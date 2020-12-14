#pragma once

#include "../GpApi_global.hpp"

namespace GPlatform::API::RPC {

class GpApiTypeDetector
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(GpApiTypeDetector)
    CLASS_DECLARE_DEFAULTS(GpApiTypeDetector)

public:
                                    GpApiTypeDetector   (void) noexcept {}
    virtual                         ~GpApiTypeDetector  (void) noexcept {}

    virtual const GpTypeStructInfo& DetectTypeInfo      (void) const = 0;
};

}//namespace GPlatform::API::RPC

