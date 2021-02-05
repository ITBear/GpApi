#include "GpApiRqDesc.hpp"

namespace GPlatform::API::RPC {

TYPE_STRUCT_IMPLEMENT(GpApiRqDesc, GP_MODULE_UUID)

GpApiRqDesc::GpApiRqDesc (void) noexcept
{
}

GpApiRqDesc::~GpApiRqDesc (void) noexcept
{
}

void    GpApiRqDesc::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut)
{
    PROP(method);
    PROP(sid);
    PROP(ts);
    PROP(args);
}

}//namespace GPlatform::API::RPC
