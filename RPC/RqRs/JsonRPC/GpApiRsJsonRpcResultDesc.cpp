#include "GpApiRsJsonRpcResultDesc.hpp"

namespace GPlatform::API::RPC {

TYPE_STRUCT_IMPLEMENT(GpApiRsJsonRpcResultDesc, GP_MODULE_UUID)

GpApiRsJsonRpcResultDesc::GpApiRsJsonRpcResultDesc (void) noexcept
{
}

GpApiRsJsonRpcResultDesc::~GpApiRsJsonRpcResultDesc (void) noexcept
{
}

void    GpApiRsJsonRpcResultDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(code);
    PROP(message);
}

}//namespace GPlatform::API::RPC
