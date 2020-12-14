#pragma once

#include "../GpApi_global.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiAddArgsDesc: public GpTypeStructBase
{
public:
    CLASS_DECLARE_DEFAULTS(GpApiAddArgsDesc)
    TYPE_STRUCT_DECLARE("31a95717-3e18-447f-a170-09d29052960b"_sv)

public:
                        GpApiAddArgsDesc    (void) noexcept;
    virtual             ~GpApiAddArgsDesc   (void) noexcept override;
};

}//namespace GPlatform::API::RPC
