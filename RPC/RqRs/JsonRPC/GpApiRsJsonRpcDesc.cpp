#include "GpApiRsJsonRpcDesc.hpp"

namespace GPlatform::API::RPC {

TYPE_STRUCT_IMPLEMENT(GpApiRsJsonRpcDesc, GP_MODULE_UUID)

GpApiRsJsonRpcDesc::GpApiRsJsonRpcDesc (void) noexcept
{
}

GpApiRsJsonRpcDesc::~GpApiRsJsonRpcDesc (void) noexcept
{
}

GpApiRsResultDesc::CSP  GpApiRsJsonRpcDesc::Result (void) const
{
    return error;
}

GpApiRsResultDesc::SP   GpApiRsJsonRpcDesc::Result (void)
{
    return error;
}

void    GpApiRsJsonRpcDesc::SetResult (GpApiRsResultDesc::SP aResult)
{
    error = GpTypeManager::S().CastSP<GpApiRsJsonRpcResultDesc::SP>(aResult);
}

void    GpApiRsJsonRpcDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(jsonrpc);
    PROP(id);
    PROP(error);
}

}//namespace GPlatform::API::RPC
