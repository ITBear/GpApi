#include "GpApiRqJsonRpcDesc.hpp"

namespace GPlatform::API::RPC {

TYPE_STRUCT_IMPLEMENT(GpApiRqJsonRpcDesc, GP_MODULE_UUID)

GpApiRqJsonRpcDesc::GpApiRqJsonRpcDesc (void) noexcept
{
}

GpApiRqJsonRpcDesc::~GpApiRqJsonRpcDesc (void) noexcept
{
}

std::string_view    GpApiRqJsonRpcDesc::Method (void) const
{
    return method;
}

void    GpApiRqJsonRpcDesc::SetMethod (std::string_view aMethod)
{
    method = aMethod;
}

void    GpApiRqJsonRpcDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(jsonrpc);
    PROP(id);
    PROP(method);
}

}//namespace GPlatform::API::RPC
