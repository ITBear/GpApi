#include "GpApiRsDesc.hpp"

namespace GPlatform::API::RPC {

TYPE_STRUCT_IMPLEMENT(GpApiRsDesc, GP_MODULE_UUID)

GpApiRsDesc::GpApiRsDesc (void) noexcept
{
}

GpApiRsDesc::~GpApiRsDesc (void) noexcept
{
}

void    GpApiRsDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(result);
}

}//namespace GPlatform::API::RPC
