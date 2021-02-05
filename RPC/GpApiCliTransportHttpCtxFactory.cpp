#include "GpApiCliTransportHttpCtxFactory.hpp"
#include "GpApiCliTransportHttpCtx.hpp"

namespace GPlatform::API::RPC {

GpApiCliTransportHttpCtxFactory::GpApiCliTransportHttpCtxFactory (void) noexcept
{
}

GpApiCliTransportHttpCtxFactory::~GpApiCliTransportHttpCtxFactory (void) noexcept
{
}

GpApiCliTransportHttpCtx::SP    GpApiCliTransportHttpCtxFactory::NewInstance (void) const
{
    return MakeSP<GpApiCliTransportHttpCtx>();
}

}//namespace GPlatform::API::RPC
