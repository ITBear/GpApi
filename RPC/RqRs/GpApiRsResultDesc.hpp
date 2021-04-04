#pragma once

#include "../../GpApi_global.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiRsResultDesc: public GpTypeStructBase
{
public:
    CLASS_DECLARE_DEFAULTS(GpApiRsResultDesc)
    TYPE_STRUCT_DECLARE("d286edbe-3f91-4891-b179-1980ddbdd9f7"_sv)

public:
                        GpApiRsResultDesc   (void) noexcept;
    virtual             ~GpApiRsResultDesc  (void) noexcept override;
};

}//namespace GPlatform::API::RPC
