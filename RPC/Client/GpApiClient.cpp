#include "GpApiClient.hpp"

namespace GPlatform::API::RPC {

GpApiClient::GpApiClient (GpApiCliTransport::SP aTransport) noexcept:
iTransport(std::move(aTransport))
{
}

GpApiClient::~GpApiClient (void) noexcept
{
}

}//namespace GPlatform::API::RPC
