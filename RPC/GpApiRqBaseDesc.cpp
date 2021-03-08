#include "GpApiRqBaseDesc.hpp"

namespace GPlatform::API::RPC {

TYPE_STRUCT_IMPLEMENT(GpApiRqBaseDesc, GP_MODULE_UUID)

GpApiRqBaseDesc::GpApiRqBaseDesc (void) noexcept
{
}

GpApiRqBaseDesc::~GpApiRqBaseDesc (void) noexcept
{
}

std::string_view    GpApiRqBaseDesc::Method (void) const
{
    return method;
}

void    GpApiRqBaseDesc::SetMethod (std::string_view aMethod)
{
    method = aMethod;
}

void    GpApiRqBaseDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(method);
    PROP(sid);
    PROP(ts);
}

}//namespace GPlatform::API::RPC
