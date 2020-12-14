#pragma once

#include "GpApiRqDesc.hpp"
#include "GpApiRsDesc.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiCliTransport
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(GpApiCliTransport)
    CLASS_DECLARE_DEFAULTS(GpApiCliTransport)

public:
                                GpApiCliTransport   (void) noexcept;
    virtual                     ~GpApiCliTransport  (void) noexcept;

    virtual GpApiRsDesc::SP     ProcessRQ           (const GpApiRqDesc&         aRq,
                                                     const GpTypeStructInfo&    aRsTypeInfo) = 0;
};

}//namespace GPlatform::API::RPC
