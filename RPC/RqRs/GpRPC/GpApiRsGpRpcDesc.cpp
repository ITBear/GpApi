#include "GpApiRsGpRpcDesc.hpp"

namespace GPlatform::API::RPC {

TYPE_STRUCT_IMPLEMENT(GpApiRsGpRpcDesc, GP_MODULE_UUID)

GpApiRsGpRpcDesc::GpApiRsGpRpcDesc (void) noexcept
{
}

GpApiRsGpRpcDesc::~GpApiRsGpRpcDesc (void) noexcept
{
}

GpApiRsResultDesc::SP   GpApiRsGpRpcDesc::Result (void)
{
    return result;
}

void    GpApiRsGpRpcDesc::SetResult (GpApiRsResultDesc::SP aResult)
{
    result = std::move(aResult);
}

void    GpApiRsGpRpcDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(result);
}

}//namespace GPlatform::API::RPC
