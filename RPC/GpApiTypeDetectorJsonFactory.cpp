#include "GpApiTypeDetectorJsonFactory.hpp"
#include "GpApiTypeDetectorJson.hpp"

namespace GPlatform::API::RPC {

GpApiTypeDetectorJsonFactory::GpApiTypeDetectorJsonFactory (void) noexcept
{
}

GpApiTypeDetectorJsonFactory::~GpApiTypeDetectorJsonFactory (void) noexcept
{
}

GpApiTypeDetector::SP   GpApiTypeDetectorJsonFactory::NewInstance
(
    const GpApiMethodsManager&  aApiManager,
    const GpBytesArray&         aData
) const
{
    return MakeSP<GpApiTypeDetectorJson>
    (
        aApiManager,
        aData
    );
}

}//namespace GPlatform::API::RPC
