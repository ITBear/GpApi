#include "GpApiCli.hpp"

namespace GPlatform::API::RPC {

GpApiCli::GpApiCli (GpApiCliTransport::SP aTransport) noexcept:
iTransport(std::move(aTransport))
{
}

GpApiCli::~GpApiCli (void) noexcept
{
}

}//namespace GPlatform::API::RPC
