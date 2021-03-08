#include "GpApiRsIfDesc.hpp"

namespace GPlatform::API::RPC {

TYPE_STRUCT_IMPLEMENT(GpApiRsIfDesc, GP_MODULE_UUID)

GpApiRsIfDesc::GpApiRsIfDesc (void) noexcept
{
}

GpApiRsIfDesc::~GpApiRsIfDesc (void) noexcept
{
}

GpApiResultDesc::SP GpApiRsIfDesc::Result (void)
{
    THROW_GPE_NOT_IMPLEMENTED();
}

void    GpApiRsIfDesc::SetResult (GpApiResultDesc::SP /*aResult*/)
{
    THROW_GPE_NOT_IMPLEMENTED();
}

std::any    GpApiRsIfDesc::Payload (void) const
{
    THROW_GPE_NOT_IMPLEMENTED();
}

std::any    GpApiRsIfDesc::Payload (void)
{
    THROW_GPE_NOT_IMPLEMENTED();
}

void    GpApiRsIfDesc::SetPayload (std::any /*aAny*/)
{
    THROW_GPE_NOT_IMPLEMENTED();
}

void    GpApiRsIfDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& /*aPropsOut*/)
{   
}

}//namespace GPlatform::API::RPC
