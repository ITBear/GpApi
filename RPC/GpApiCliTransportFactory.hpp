#pragma once

#include "GpApiCliTransport.hpp"

namespace GPlatform::API::RPC {

class GpApiCliTransportFactory
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(GpApiCliTransportFactory)
    CLASS_DECLARE_DEFAULTS(GpApiCliTransportFactory)

protected:
                                    GpApiCliTransportFactory    (void) noexcept {}

public:
    virtual                         ~GpApiCliTransportFactory   (void) noexcept {}

    virtual GpApiCliTransport::SP   NewInstance                 (void) const = 0;
};

}//namespace GPlatform::API::RPC
