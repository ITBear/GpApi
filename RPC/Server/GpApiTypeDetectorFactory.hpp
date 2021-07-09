#pragma once

#include "GpApiTypeDetector.hpp"
#include "GpApiMethodsManager.hpp"

namespace GPlatform::API::RPC {

class GpApiTypeDetectorFactory
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpApiTypeDetectorFactory)
    CLASS_DECLARE_DEFAULTS(GpApiTypeDetectorFactory)

protected:
                                    GpApiTypeDetectorFactory    (void) noexcept {}

public:
    virtual                         ~GpApiTypeDetectorFactory   (void) noexcept {}

    virtual GpApiTypeDetector::SP   NewInstance                 (const GpApiMethodsManager& aApiManager,
                                                                 const GpBytesArray&        aData) const = 0;
};

}//namespace GPlatform::API::RPC
