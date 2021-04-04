#pragma once

#include "../GpApiRsIfDesc.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiRsRawDesc: public GpApiRsIfDesc
{
public:
    CLASS_DECLARE_DEFAULTS(GpApiRsRawDesc)
    TYPE_STRUCT_DECLARE("e1eb11cd-a32a-431d-b684-eedf0e5ad860"_sv)

public:
                                        GpApiRsRawDesc  (void) noexcept;
    virtual                             ~GpApiRsRawDesc (void) noexcept override;

    virtual GpApiRsResultDesc::SP       Result          (void) override final;
    virtual void                        SetResult       (GpApiRsResultDesc::SP aResult) override final;
};

}//namespace GPlatform::API::RPC

