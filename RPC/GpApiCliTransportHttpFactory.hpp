#pragma once

#include "GpApiCliTransportFactory.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiCliTransportHttpFactory final: public GpApiCliTransportFactory
{
public:
    CLASS_REMOVE_CTRS(GpApiCliTransportHttpFactory)
    CLASS_DECLARE_DEFAULTS(GpApiCliTransportHttpFactory)

public:
                                    GpApiCliTransportHttpFactory    (std::string_view           aURL,
                                                                     GpTypeMapperFactory::SP    aTypeMapperFactory);
    virtual                         ~GpApiCliTransportHttpFactory   (void) noexcept override final;

    virtual GpApiCliTransport::SP   NewInstance                     (void) const override final;

private:
    const std::string_view          iURL;
    GpTypeMapperFactory::SP         iTypeMapperFactory;
};

}//namespace GPlatform::API::RPC
