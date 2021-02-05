#pragma once

#include "../GpApi_global.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiCliTransportCtx
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(GpApiCliTransportCtx)
    CLASS_DECLARE_DEFAULTS(GpApiCliTransportCtx)

protected:
                                GpApiCliTransportCtx    (void) noexcept {}

public:
    virtual                     ~GpApiCliTransportCtx   (void) noexcept {}
};

}//namespace GPlatform::API::RPC
