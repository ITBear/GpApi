#include "GpApiMethodFactory.hpp"

namespace GPlatform::API::RPC {

GpApiMethodFactory::GpApiMethodFactory (std::string_view aMethodName) noexcept:
iMethodName(aMethodName)
{
}

GpApiMethodFactory::~GpApiMethodFactory (void) noexcept
{
}

}//namespace GPlatform::API::RPC
