#pragma once

#include "GpApiResultDesc.hpp"
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

    virtual GpApiResultDesc::SP         Result          (void);
    virtual void                        SetResult       (GpApiResultDesc::SP aResult);

    virtual std::any                    Payload         (void) const;
    virtual std::any                    Payload         (void);
    virtual void                        SetPayload      (std::any aAny);
};

}//namespace GPlatform::API::RPC
