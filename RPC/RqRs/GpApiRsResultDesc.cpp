#include "GpApiRsResultDesc.hpp"

namespace GPlatform::API::RPC {

TYPE_STRUCT_IMPLEMENT(GpApiRsResultDesc, GP_MODULE_UUID)

GpApiRsResultDesc::GpApiRsResultDesc (void) noexcept
{
}

GpApiRsResultDesc::~GpApiRsResultDesc (void) noexcept
{
}

void    GpApiRsResultDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& /*aPropsOut*/)
{
}

}//namespace GPlatform::API::RPC
