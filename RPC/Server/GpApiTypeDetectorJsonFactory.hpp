#pragma once

#include "GpApiTypeDetectorFactory.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiTypeDetectorJsonFactory final: public GpApiTypeDetectorFactory
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(GpApiTypeDetectorJsonFactory)
    CLASS_DECLARE_DEFAULTS(GpApiTypeDetectorJsonFactory)

public:
                                    GpApiTypeDetectorJsonFactory    (void) noexcept;
    virtual                         ~GpApiTypeDetectorJsonFactory   (void) noexcept override final;

    virtual GpApiTypeDetector::SP   NewInstance                     (const GpApiMethodsManager& aApiManager,
                                                                     const GpBytesArray&        aData) const override final;
};

}//namespace GPlatform::API::RPC
