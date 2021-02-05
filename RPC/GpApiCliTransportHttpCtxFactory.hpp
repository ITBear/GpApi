#pragma once

#include "../GpApi_global.hpp"

namespace GPlatform::API::RPC {

class GpApiCliTransportHttpCtx;

class GPAPI_API GpApiCliTransportHttpCtxFactory
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(GpApiCliTransportHttpCtxFactory)
    CLASS_DECLARE_DEFAULTS(GpApiCliTransportHttpCtxFactory)

public:
                                            GpApiCliTransportHttpCtxFactory     (void) noexcept;
    virtual                                 ~GpApiCliTransportHttpCtxFactory    (void) noexcept;

    virtual GpSP<GpApiCliTransportHttpCtx>  NewInstance                         (void) const;
};

}//namespace GPlatform::API::RPC
