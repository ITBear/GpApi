#include "GpApiRqIfDesc.hpp"

namespace GPlatform::API::RPC {

TYPE_STRUCT_IMPLEMENT(GpApiRqIfDesc, GP_MODULE_UUID)

GpApiRqIfDesc::GpApiRqIfDesc (void) noexcept
{
}

GpApiRqIfDesc::~GpApiRqIfDesc (void) noexcept
{
}

std::string_view    GpApiRqIfDesc::Method (void) const
{
    THROW_GPE_NOT_IMPLEMENTED();
}

void    GpApiRqIfDesc::SetMethod (std::string_view /*aMethod*/)
{
    THROW_GPE_NOT_IMPLEMENTED();
}

std::any    GpApiRqIfDesc::Payload (void) const
{
    THROW_GPE_NOT_IMPLEMENTED();
}

std::any    GpApiRqIfDesc::Payload (void)
{
    THROW_GPE_NOT_IMPLEMENTED();
}

void    GpApiRqIfDesc::SetPayload (std::any /*aAny*/)
{
    THROW_GPE_NOT_IMPLEMENTED();
}

void    GpApiRqIfDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& /*aPropsOut*/)
{
}

}//namespace GPlatform::API::RPC
