#pragma once

#include "../../RqRs/GpApiRqIfDesc.hpp"
#include "../../RqRs/GpApiRsIfDesc.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiCliTransport
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpApiCliTransport)
    CLASS_DECLARE_DEFAULTS(GpApiCliTransport)

    using ProcessRqRsFnT = std::function<void(std::any aRq)>;

public:
                                GpApiCliTransport   (void) noexcept;
    virtual                     ~GpApiCliTransport  (void) noexcept;

    virtual GpApiRsIfDesc::SP   ProcessRQ           (const GpApiRqIfDesc&           aRq,
                                                     const GpTypeStructInfo&        aRsTypeInfo,
                                                     std::optional<ProcessRqRsFnT>  aBeforeProcessFn,
                                                     std::optional<ProcessRqRsFnT>  aAfterProcessFn) = 0;
};

}//namespace GPlatform::API::RPC
