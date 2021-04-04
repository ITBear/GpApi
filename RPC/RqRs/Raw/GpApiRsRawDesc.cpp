#include "GpApiRsRawDesc.hpp"

namespace GPlatform::API::RPC {

TYPE_STRUCT_IMPLEMENT(GpApiRsRawDesc, GP_MODULE_UUID)

GpApiRsRawDesc::GpApiRsRawDesc (void) noexcept
{
}

GpApiRsRawDesc::~GpApiRsRawDesc (void) noexcept
{
}

GpApiRsResultDesc::SP   GpApiRsRawDesc::Result (void)
{
    THROW_GPE("Disabled for Raw RS"_sv);
}

void    GpApiRsRawDesc::SetResult (GpApiRsResultDesc::SP aResult)
{
    THROW_GPE("Disabled for Raw RS"_sv);
}

void    GpApiRsRawDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    THROW_GPE("Disabled for Raw RS"_sv);
}

}//namespace GPlatform::API::RPC
