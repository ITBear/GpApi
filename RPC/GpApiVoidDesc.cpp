#include "GpApiVoidDesc.hpp"

namespace GPlatform::API::RPC {

TYPE_STRUCT_IMPLEMENT(GpApiVoidDesc, GP_MODULE_UUID)

GpApiVoidDesc::GpApiVoidDesc (void) noexcept
{
}

GpApiVoidDesc::~GpApiVoidDesc (void) noexcept
{
}

void    GpApiVoidDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& /*aPropsOut*/)
{
}

}//namespace GPlatform::API::RPC
