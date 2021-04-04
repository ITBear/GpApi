#pragma once

#include "../GpApiRsResultDesc.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiRsJsonRpcResultDesc final: public GpApiRsResultDesc
{
public:
    CLASS_DECLARE_DEFAULTS(GpApiRsJsonRpcResultDesc)
    TYPE_STRUCT_DECLARE("4297c2ba-8831-47c0-9247-ed50d4dcb3a7"_sv)

public:
                        GpApiRsJsonRpcResultDesc    (void) noexcept;
    virtual             ~GpApiRsJsonRpcResultDesc   (void) noexcept override final;

public:
    s_int_64            code    = 0;
    std::string         message;
};

}//namespace GPlatform::API::RPC
