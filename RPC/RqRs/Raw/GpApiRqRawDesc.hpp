#pragma once

#include "../GpApiRqIfDesc.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiRqRawDesc: public GpApiRqIfDesc
{
public:
    CLASS_DECLARE_DEFAULTS(GpApiRqRawDesc)
    TYPE_STRUCT_DECLARE("9250c47a-f80f-418b-a9e6-33788899ce96"_sv)

public:
                                GpApiRqRawDesc      (void) noexcept;
    virtual                     ~GpApiRqRawDesc     (void) noexcept override;

    virtual std::string_view    Method              (void) const override final;
    virtual void                SetMethod           (std::string_view aMethod) override final;

    virtual std::any            Payload             (void) const override final;
    virtual std::any            Payload             (void) override final;
    virtual void                SetPayload          (std::any aAny) override final;
};

}//GPlatform::API::RPC
