#pragma once

#include "../GpApi_global.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiRqIfDesc: public GpTypeStructBase
{
public:
    CLASS_DECLARE_DEFAULTS(GpApiRqIfDesc)
    TYPE_STRUCT_DECLARE("6f7f6db1-67f0-4425-97ee-6e0eecbc3e2d"_sv)

public:
                                GpApiRqIfDesc   (void) noexcept;
    virtual                     ~GpApiRqIfDesc  (void) noexcept override;

    virtual std::string_view    Method          (void) const;
    virtual void                SetMethod       (std::string_view aMethod);

    virtual std::any            Payload         (void) const;
    virtual std::any            Payload         (void);
    virtual void                SetPayload      (std::any aAny);
};

}//GPlatform::API::RPC
