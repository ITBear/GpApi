#include "GpApiCliTransport.hpp"

namespace GPlatform::API::RPC {

GpApiCliTransport::GpApiCliTransport (void) noexcept
{   
}

GpApiCliTransport::GpApiCliTransport (GpApiCliTransportCtx::SP aCtx) noexcept:
iCtx(std::move(aCtx))
{
}

GpApiCliTransport::~GpApiCliTransport (void) noexcept
{
}

}//namespace GPlatform::API::RPC
