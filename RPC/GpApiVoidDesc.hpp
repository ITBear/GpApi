#pragma once

#include "../GpApi_global.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiVoidDesc: public GpTypeStructBase
{
public:
    CLASS_DECLARE_DEFAULTS(GpApiVoidDesc)
    TYPE_STRUCT_DECLARE("f38857d3-6c29-414b-9761-4128391a2a33"_sv)

public:
                        GpApiVoidDesc   (void) noexcept;
    virtual             ~GpApiVoidDesc  (void) noexcept override;
};

}//namespace GPlatform::API::RPC
