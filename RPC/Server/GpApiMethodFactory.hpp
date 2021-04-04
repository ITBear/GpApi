#pragma once

#include "GpApiMethod.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiMethodFactory
{
public:
    CLASS_REMOVE_CTRS(GpApiMethodFactory)
    CLASS_DECLARE_DEFAULTS(GpApiMethodFactory)

public:
                                GpApiMethodFactory  (std::string_view aMethodName);
    virtual                     ~GpApiMethodFactory (void) noexcept;

    std::string_view            MethodName          (void) const noexcept {return iMethodName;}

    virtual GpApiMethod::SP     NewInstance         (void) const = 0;

private:
    const std::string           iMethodName;
};

}//namespace GPlatform::API::RPC
