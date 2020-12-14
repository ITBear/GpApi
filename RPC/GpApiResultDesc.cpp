#include "GpApiResultDesc.hpp"

namespace GPlatform::API::RPC {

TYPE_STRUCT_IMPLEMENT(GpApiResultDesc, GP_MODULE_UUID)

GpApiResultDesc::GpApiResultDesc (void) noexcept
{
}

GpApiResultDesc::~GpApiResultDesc (void) noexcept
{
}

void    GpApiResultDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& /*aPropsOut*/)
{
}

}//namespace GPlatform::API::RPC
