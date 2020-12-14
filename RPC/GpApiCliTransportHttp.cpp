#include "GpApiCliTransportHttp.hpp"
#include <iostream>

namespace GPlatform::API::RPC {

GpApiCliTransportHttp::GpApiCliTransportHttp (std::string_view  aURL,
                                              GpTypeMapper::SP  aTypeMapper):
iURL(aURL),
iTypeMapper(std::move(aTypeMapper))
{
}

GpApiCliTransportHttp::~GpApiCliTransportHttp (void) noexcept
{
}

GpApiRsDesc::SP GpApiCliTransportHttp::ProcessRQ (const GpApiRqDesc&        aRq,
                                                  const GpTypeStructInfo&   aRsTypeInfo)
{
    //Serialize
    GpBytesArray body = iTypeMapper->FromStruct(aRq);

    {
        std::cout << "[GpApiCliTransportHttp::ProcessRQ]: =========================== RQ =======================\n"
                  << GpRawPtrCharR(body).AsStringView() << std::endl;
    }

    //Prepate HTTP RQ
    GpHttpRequest::SP   httpRq = MakeSP<GpHttpRequest>(GpHttpVersion::HTTP_1_1,
                                                       GpHttpRequestType::POST,
                                                       iURL,
                                                       GpHttpHeaders(),
                                                       std::move(body));

    //Do HTTP RQ
    GpHttpResponse::SP httpRs = iHttpClient.Do(httpRq, GpHttpClientCurl::ErorrMode::THROW_ON_NOT_200);

    {
        std::cout << "[GpApiCliTransportHttp::ProcessRQ]: =========================== RS =======================\n"
                  << GpRawPtrCharR(httpRs->body).AsStringView() << std::endl;
    }

    //Deserialize
    GpTypeStructBase::SP rsStruct = iTypeMapper->ToStruct(httpRs->body, aRsTypeInfo);
    return rsStruct.CastAs<GpApiRsDesc::SP>();
}

}//namespace GPlatform::API::RPC
