#include "GpApiCliTransportHttpFactory.hpp"
#include "GpApiCliTransportHttp.hpp"

namespace GPlatform::API::RPC {

GpApiCliTransportHttpFactory::GpApiCliTransportHttpFactory
(
    std::string_view        aURL,
    GpTypeMapperFactory::SP aTypeMapperFactory
):
iURL(aURL),
iTypeMapperFactory(std::move(aTypeMapperFactory))
{
}

GpApiCliTransportHttpFactory::GpApiCliTransportHttpFactory
(
    std::string_view                    aURL,
    GpTypeMapperFactory::SP             aTypeMapperFactory,
    GpApiCliTransportHttpCtxFactory::SP aCtxFactory
):
iURL(aURL),
iTypeMapperFactory(std::move(aTypeMapperFactory)),
iCtxFactory(std::move(aCtxFactory))
{
}

GpApiCliTransportHttpFactory::~GpApiCliTransportHttpFactory (void) noexcept
{
}

GpApiCliTransport::SP   GpApiCliTransportHttpFactory::NewInstance (void) const
{
    if (iCtxFactory.IsNotNULL())
    {
        return MakeSP<GpApiCliTransportHttp>
        (
            iURL,
            iTypeMapperFactory->NewInstance(),
            iCtxFactory.VCn().NewInstance()
        );
    } else
    {
        return MakeSP<GpApiCliTransportHttp>
        (
            iURL,
            iTypeMapperFactory->NewInstance()
        );
    }
}

}//namespace GPlatform::API::RPC
