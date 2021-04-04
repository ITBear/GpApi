#pragma once

#include "../../RqRs/GpApiRqIfDesc.hpp"
#include "../../RqRs/GpApiRsIfDesc.hpp"
#include "GpApiCliTransportCtx.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiCliTransport
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(GpApiCliTransport)
    CLASS_DECLARE_DEFAULTS(GpApiCliTransport)

public:
                                GpApiCliTransport   (void) noexcept;
                                GpApiCliTransport   (GpApiCliTransportCtx::SP aCtx) noexcept;
    virtual                     ~GpApiCliTransport  (void) noexcept;

    virtual GpApiRsIfDesc::SP   ProcessRQ           (const GpApiRqIfDesc&       aRq,
                                                     const GpTypeStructInfo&    aRsTypeInfo) = 0;

    GpApiCliTransportCtx::SP    Ctx                 (void) noexcept {return iCtx;}

private:
    GpApiCliTransportCtx::SP    iCtx;
};

}//namespace GPlatform::API::RPC
