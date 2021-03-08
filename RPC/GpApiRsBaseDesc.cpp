#include "GpApiRsBaseDesc.hpp"

namespace GPlatform::API::RPC {

TYPE_STRUCT_IMPLEMENT(GpApiRsBaseDesc, GP_MODULE_UUID)

GpApiRsBaseDesc::GpApiRsBaseDesc (void) noexcept
{
}

GpApiRsBaseDesc::~GpApiRsBaseDesc (void) noexcept
{
}

GpApiResultDesc::SP GpApiRsBaseDesc::Result (void)
{
    return result;
}

void    GpApiRsBaseDesc::SetResult (GpApiResultDesc::SP aResult)
{
    result = std::move(aResult);
}

void    GpApiRsBaseDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(result);
}

}//namespace GPlatform::API::RPC
