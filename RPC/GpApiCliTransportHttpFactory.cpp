#include "GpApiCliTransportHttpFactory.hpp"
#include "GpApiCliTransportHttp.hpp"

namespace GPlatform::API::RPC {

GpApiCliTransportHttpFactory::GpApiCliTransportHttpFactory (std::string_view        aURL,
                                                            GpTypeMapperFactory::SP aTypeMapperFactory):
iURL(aURL),
iTypeMapperFactory(std::move(aTypeMapperFactory))
{
}

GpApiCliTransportHttpFactory::~GpApiCliTransportHttpFactory (void) noexcept
{
}

GpApiCliTransport::SP   GpApiCliTransportHttpFactory::NewInstance (void) const
{
    return MakeSP<GpApiCliTransportHttp>
    (
        iURL,
        iTypeMapperFactory->NewInstance()
    );
}

}//namespace GPlatform::API::RPC
