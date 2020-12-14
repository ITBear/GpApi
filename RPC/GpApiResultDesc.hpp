#pragma once

#include "../GpApi_global.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiResultDesc: public GpTypeStructBase
{
public:
    CLASS_DECLARE_DEFAULTS(GpApiResultDesc)
    TYPE_STRUCT_DECLARE("d286edbe-3f91-4891-b179-1980ddbdd9f7"_sv)

public:
                        GpApiResultDesc     (void) noexcept;
    virtual             ~GpApiResultDesc    (void) noexcept override;
};

}//namespace GPlatform::API::RPC
