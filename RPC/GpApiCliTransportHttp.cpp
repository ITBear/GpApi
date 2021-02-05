#include "GpApiCliTransportHttp.hpp"
#include <iostream>

namespace GPlatform::API::RPC {

GpApiCliTransportHttp::GpApiCliTransportHttp
(
    std::string_view    aURL,
    GpTypeMapper::SP    aTypeMapper
):
iURL(aURL),
iTypeMapper(std::move(aTypeMapper))
{
}

GpApiCliTransportHttp::GpApiCliTransportHttp
(
    std::string_view                aURL,
    GpTypeMapper::SP                aTypeMapper,
    GpApiCliTransportHttpCtx::SP    aCtx
):
GpApiCliTransport(std::move(aCtx)),
iURL(aURL),
iTypeMapper(std::move(aTypeMapper))
{
}

GpApiCliTransportHttp::~GpApiCliTransportHttp (void) noexcept
{
}

GpApiRsDesc::SP GpApiCliTransportHttp::ProcessRQ
(
    const GpApiRqDesc&      aRq,
    const GpTypeStructInfo& aRsTypeInfo
)
{
    //Ctx
    GpApiCliTransportCtx::SP ctx = Ctx();
    if (ctx.IsNotNULL())
    {
        static_cast<GpApiCliTransportHttpCtx&>(ctx.Vn()).Clear();
    }

    //RQ/RS
    GpHttpRequest::SP   httpRq;
    GpHttpResponse::SP  httpRs;
    {
        //Serialize
        GpBytesArray body = iTypeMapper->FromStruct(aRq);

        {
            std::string_view bodySW = GpRawPtrCharR(body).AsStringView();

            if (bodySW.length() > 1024)
            {
                bodySW = bodySW.substr(0, 1024);
            }
            std::cout << "[GpApiCliTransportHttp::ProcessRQ]: =========================== RQ =======================\n"
                      << bodySW << std::endl;
        }

        //Prepate HTTP RQ
        httpRq = MakeSP<GpHttpRequest>
        (
            GpHttpVersion::HTTP_1_1,
            GpHttpRequestType::POST,
            iURL,
            GpHttpHeaders(),
            std::move(body)
        );

        //Do HTTP RQ
        httpRs = iHttpClient.Do(httpRq, GpHttpClientCurl::ErorrMode::THROW_ON_NOT_200);
    }

    //Ctx
    if (ctx.IsNotNULL())
    {
        static_cast<GpApiCliTransportHttpCtx&>(ctx.Vn()).SetRqRs(httpRq, httpRs);
    }

    {
        std::string_view bodySW = GpRawPtrCharR(httpRs->body).AsStringView();

        if (bodySW.length() > 1024)
        {
            bodySW = bodySW.substr(0, 1024);
        }
        std::cout << "[GpApiCliTransportHttp::ProcessRQ]: =========================== RS =======================\n"
                  << bodySW << std::endl;
    }

    //Deserialize
    GpTypeStructBase::SP rsStruct;
    try
    {
        rsStruct = iTypeMapper->ToStruct(httpRs->body, aRsTypeInfo);
    } catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        throw;
    }

    return rsStruct.CastAs<GpApiRsDesc::SP>();
}

}//namespace GPlatform::API::RPC
