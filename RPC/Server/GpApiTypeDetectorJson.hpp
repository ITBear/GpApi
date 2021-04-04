#pragma once

#include "GpApiTypeDetector.hpp"
#include "GpApiMethodsManager.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiTypeDetectorJson final: public GpApiTypeDetector
{
public:
    CLASS_REMOVE_CTRS(GpApiTypeDetectorJson)
    CLASS_DECLARE_DEFAULTS(GpApiTypeDetectorJson)

public:
                                        GpApiTypeDetectorJson   (const GpApiMethodsManager& aApiManager,
                                                                 const GpBytesArray&        aData) noexcept;
    virtual                             ~GpApiTypeDetectorJson  (void) noexcept override final;

protected:
    virtual const GpTypeStructInfo&     DetectTypeInfo          (void) const override final;

private:
    const GpApiMethodsManager&          iApiManager;
    const GpBytesArray&                 iData;
};

}//namespace GPlatform::API::RPC
