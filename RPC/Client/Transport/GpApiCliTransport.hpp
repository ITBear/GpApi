#pragma once

#include "../../RqRs/GpApiRqIfDesc.hpp"
#include "../../RqRs/GpApiRsIfDesc.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiCliTransport
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpApiCliTransport)
    CLASS_DECLARE_DEFAULTS(GpApiCliTransport)

    using SerializeRqFnT    = std::function<void(GpByteWriter& aRqWriter)>;
    using ProcessRqRsFnT    = std::function<void(std::any aRq)>;

public:
                                GpApiCliTransport       (void) noexcept;
    virtual                     ~GpApiCliTransport      (void) noexcept;

    void                        SetDefaultProcessFns    (std::optional<SerializeRqFnT>  aBeforeSerializeRqFn,
                                                         std::optional<SerializeRqFnT>  aAfterSerializeRqFn,
                                                         std::optional<ProcessRqRsFnT>  aBeforeProcessFn,
                                                         std::optional<ProcessRqRsFnT>  aAfterProcessFn);

    GpApiRsIfDesc::SP           ProcessRQ               (const GpApiRqIfDesc&       aRq,
                                                         const GpTypeStructInfo&    aRsTypeInfo);

    virtual GpApiRsIfDesc::SP   ProcessRQ               (const GpApiRqIfDesc&           aRq,
                                                         const GpTypeStructInfo&        aRsTypeInfo,
                                                         std::optional<SerializeRqFnT>  aBeforeSerializeRqFn,
                                                         std::optional<SerializeRqFnT>  aAfterSerializeRqFn,
                                                         std::optional<ProcessRqRsFnT>  aBeforeProcessFn,
                                                         std::optional<ProcessRqRsFnT>  aAfterProcessFn) = 0;

private:
    std::optional<SerializeRqFnT>   iBeforeSerializeRqFn;
    std::optional<SerializeRqFnT>   iAfterSerializeRqFn;
    std::optional<ProcessRqRsFnT>   iBeforeProcessFn;
    std::optional<ProcessRqRsFnT>   iAfterProcessF;
};

}//namespace GPlatform::API::RPC
