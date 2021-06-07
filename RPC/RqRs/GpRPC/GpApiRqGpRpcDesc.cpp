#include "GpApiRqGpRpcDesc.hpp"

namespace GPlatform::API::RPC {

TYPE_STRUCT_IMPLEMENT(GpApiRqGpRpcDesc, GP_MODULE_UUID)

GpApiRqGpRpcDesc::GpApiRqGpRpcDesc (void) noexcept
{
}

GpApiRqGpRpcDesc::~GpApiRqGpRpcDesc (void) noexcept
{
}

std::string_view    GpApiRqGpRpcDesc::Method (void) const
{
    return method;
}

void    GpApiRqGpRpcDesc::SetMethod (std::string_view aMethod)
{
    method = aMethod;
}

void    GpApiRqGpRpcDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(method);
    PROP(sid);
}

}//namespace GPlatform::API::RPC
