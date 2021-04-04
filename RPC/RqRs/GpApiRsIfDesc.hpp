#pragma once

#include "GpApiRsResultDesc.hpp"
#include <any>

namespace GPlatform::API::RPC {

class GPAPI_API GpApiRsIfDesc: public GpTypeStructBase
{
public:
    CLASS_DECLARE_DEFAULTS(GpApiRsIfDesc)
    TYPE_STRUCT_DECLARE("d8485e07-ef56-4315-aa0e-763ce6ff5895"_sv)

public:
                                        GpApiRsIfDesc   (void) noexcept;
    virtual                             ~GpApiRsIfDesc  (void) noexcept override;

    virtual GpApiRsResultDesc::CSP      Result          (void) const;
    virtual GpApiRsResultDesc::SP       Result          (void);
    virtual void                        SetResult       (GpApiRsResultDesc::SP aResult);

    virtual std::any                    Payload         (void) const;
    virtual std::any                    Payload         (void);
    virtual void                        SetPayload      (std::any aAny);
};

}//namespace GPlatform::API::RPC
