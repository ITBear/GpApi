#include "GpApiCliTransport.hpp"

namespace GPlatform::API::RPC {

GpApiCliTransport::GpApiCliTransport (void) noexcept
{
}

GpApiCliTransport::~GpApiCliTransport (void) noexcept
{
}

void    GpApiCliTransport::SetDefaultProcessFns
(
    std::optional<SerializeRqFnT>   aBeforeSerializeRqFn,
    std::optional<SerializeRqFnT>   aAfterSerializeRqFn,
    std::optional<ProcessRqRsFnT>   aBeforeProcessFn,
    std::optional<ProcessRqRsFnT>   aAfterProcessFn
)
{
    iBeforeSerializeRqFn    = aBeforeSerializeRqFn;
    iAfterSerializeRqFn     = aAfterSerializeRqFn;
    iBeforeProcessFn        = aBeforeProcessFn;
    iAfterProcessF          = aAfterProcessFn;
}

GpApiRsIfDesc::SP   GpApiCliTransport::ProcessRQ
(
    const GpApiRqIfDesc&    aRq,
    const GpTypeStructInfo& aRsTypeInfo
)
{
    return ProcessRQ
    (
        aRq,
        aRsTypeInfo,
        iBeforeSerializeRqFn,
        iAfterSerializeRqFn,
        iBeforeProcessFn,
        iAfterProcessF
    );
}

}//namespace GPlatform::API::RPC
