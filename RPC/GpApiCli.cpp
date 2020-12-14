#include "GpApiCli.hpp"

namespace GPlatform::API::RPC {

GpApiCli::GpApiCli (GpApiCliTransport::SP aTransport) noexcept:
iTransport(std::move(aTransport))
{
}

GpApiCli::~GpApiCli (void) noexcept
{
}

void    GpApiCli::SetSID (std::string_view aSid)
{
    iSid = aSid;
}

}//namespace GPlatform::API::RPC
