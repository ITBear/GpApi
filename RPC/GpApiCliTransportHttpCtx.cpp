#include "GpApiCliTransportHttpCtx.hpp"

namespace GPlatform::API::RPC {

GpApiCliTransportHttpCtx::GpApiCliTransportHttpCtx (void) noexcept
{
}

GpApiCliTransportHttpCtx::~GpApiCliTransportHttpCtx (void) noexcept
{
}

void    GpApiCliTransportHttpCtx::Clear (void)
{
    iRq.Clear();
    iRs.Clear();
}

void    GpApiCliTransportHttpCtx::SetRqRs
(
    GpHttpRequest::SP   aRq,
    GpHttpResponse::SP  aRs
) noexcept
{
    iRq = std::move(aRq);
    iRs = std::move(aRs);
}

}//namespace GPlatform::API::RPC
