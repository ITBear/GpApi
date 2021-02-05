#pragma once

#include "GpApiRqDesc.hpp"
#include "GpApiRsDesc.hpp"
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

    virtual GpApiRsDesc::SP     ProcessRQ           (const GpApiRqDesc&         aRq,
                                                     const GpTypeStructInfo&    aRsTypeInfo) = 0;

    GpApiCliTransportCtx::SP    Ctx                 (void) noexcept {return iCtx;}

private:
    GpApiCliTransportCtx::SP    iCtx;
};

}//namespace GPlatform::API::RPC
