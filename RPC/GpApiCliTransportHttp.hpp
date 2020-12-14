#pragma once

#include "GpApiCliTransport.hpp"
#include "../../GpNetwork/GpNetwork.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiCliTransportHttp final: public GpApiCliTransport
{
public:
    CLASS_REMOVE_CTRS(GpApiCliTransportHttp)
    CLASS_DECLARE_DEFAULTS(GpApiCliTransportHttp)

public:
                                GpApiCliTransportHttp   (std::string_view   aURL,
                                                         GpTypeMapper::SP   aTypeMapper);
    virtual                     ~GpApiCliTransportHttp  (void) noexcept override final;

    virtual GpApiRsDesc::SP     ProcessRQ               (const GpApiRqDesc&         aRq,
                                                         const GpTypeStructInfo&    aRsTypeInfo) override final;

private:
    const std::string           iURL;
    GpTypeMapper::SP            iTypeMapper;
    GpHttpClientCurl            iHttpClient;
};

}//namespace GPlatform::API::RPC
