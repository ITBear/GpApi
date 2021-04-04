#include "GpApiRqRawDesc.hpp"

namespace GPlatform::API::RPC {

TYPE_STRUCT_IMPLEMENT(GpApiRqRawDesc, GP_MODULE_UUID)

GpApiRqRawDesc::GpApiRqRawDesc (void) noexcept
{
}

GpApiRqRawDesc::~GpApiRqRawDesc (void) noexcept
{
}

std::string_view    GpApiRqRawDesc::Method (void) const
{
    THROW_GPE("Disabled for Raw RQ"_sv);
}

void    GpApiRqRawDesc::SetMethod (std::string_view /*aMethod*/)
{
    THROW_GPE("Disabled for Raw RQ"_sv);
}

std::any    GpApiRqRawDesc::Payload (void) const
{
    THROW_GPE("Disabled for Raw RQ"_sv);
}

std::any    GpApiRqRawDesc::Payload (void)
{
    THROW_GPE("Disabled for Raw RQ"_sv);
}

void    GpApiRqRawDesc::SetPayload (std::any /*aAny*/)
{
    THROW_GPE("Disabled for Raw RQ"_sv);
}

void    GpApiRqRawDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& /*aPropsOut*/)
{
    //PROP()
}

}//namespace GPlatform::API::RPC
