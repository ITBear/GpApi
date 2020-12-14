#include "GpApiSrvRequestHandlerHttp.hpp"
#include <iostream>

namespace GPlatform::API::RPC {

GpApiSrvRequestHandlerHttp::GpApiSrvRequestHandlerHttp (GpApiMethodsManager::SP         aApiManager,
                                                        GpTypeMapperFactory::SP         aTypeMapperFactory,
                                                        GpApiTypeDetectorFactory::SP    aTypeDetectorFactory) noexcept:
iApiManager(std::move(aApiManager)),
iTypeMapperFactory(std::move(aTypeMapperFactory)),
iTypeDetectorFactory(std::move(aTypeDetectorFactory))
{
}

GpApiSrvRequestHandlerHttp::~GpApiSrvRequestHandlerHttp (void) noexcept
{
}

GpHttpResponse::SP  GpApiSrvRequestHandlerHttp::OnRequest (const GpHttpRequest& aRequest) const
{
    {
        std::cout << "[GpApiSrvRequestHandlerHttp::OnRequest]: --------------------------- RQ ---------------------------\n"_sv;
        std::cout << GpRawPtrCharR(aRequest.body).AsStringView() << "\n";
        std::cout.flush();
    }

    GpApiRqDesc::SP rq;
    GpApiRsDesc::SP rs;

    auto typeMapper = iTypeMapperFactory->NewInstance();

    try
    {
        //Detect type
        auto                    typeDetector    = iTypeDetectorFactory->NewInstance(iApiManager.VC(), aRequest.body);
        const GpTypeStructInfo& rqTypeInfo      = typeDetector->DetectTypeInfo();

        //Deserialize RQ data
        rq = typeMapper->ToStruct(aRequest.body, rqTypeInfo).CastAs<GpApiRqDesc::SP>();

        //Find method and call
        GpApiMethod::SP method = iApiManager->Find(rq->method);

        auto result = CallAndCatch([&](){rs = method->Process(rq.Vn());});

        if (rs.IsNULL())
        {
            rs = method->RsTypeInfo().NewInstance().CastAs<GpApiRsDesc::SP>();
        }

        rs->result = result;
    } catch (const std::exception& e)
    {
        if (rs.IsNULL())
        {
            rs = MakeSP<GpApiRsDesc>();
        }

        rs->result = GenResultEx(e);
    } catch (...)
    {
        if (rs.IsNULL())
        {
            rs = MakeSP<GpApiRsDesc>();
        }

        rs->result = GenResultExUnknown();
    }

    //Struct to Json
    GpBytesArray rsBody = typeMapper->FromStruct(rs.VC());

    {
        std::cout << "[GpApiSrvRequestHandlerHttp::OnRequest]: --------------------------- RS ---------------------------\n"_sv;
        std::cout << GpRawPtrCharR(rsBody).AsStringView() << "\n";
        std::cout.flush();
    }

    GpHttpHeaders headers;
    headers
        .SetContentType(GpHttpContentType::APPLICATION_JSON, GpHttpCharset::UTF_8)
        .SetConnection(GpHttpConnectionFlag::KEEP_ALIVE)
        .SetCacheControl(GpHttpCacheControl::NO_STORE);

    GpHttpResponse::SP httpRs = MakeSP<GpHttpResponse>(GpHttpResponseCode::OK_200,
                                                       std::move(headers),
                                                       std::move(rsBody));

    return httpRs;
}

}//namespace GPlatform::API::RPC
