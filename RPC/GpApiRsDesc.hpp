#pragma once

#include "GpApiResultDesc.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiRsDesc: public GpTypeStructBase
{
public:
    CLASS_DECLARE_DEFAULTS(GpApiRsDesc)
    TYPE_STRUCT_DECLARE("16df1627-8643-4a94-a646-b8badd8b31c7"_sv)

public:
                            GpApiRsDesc     (void) noexcept;
    virtual                 ~GpApiRsDesc    (void) noexcept override;

public:
    GpApiResultDesc::SP     result;
};

#define RS(PREFIX, NAME, UUID) \
class PREFIX NAME##_rs final: public GpApiRsDesc \
{ \
public: \
    CLASS_DECLARE_DEFAULTS(NAME##_rs) \
    TYPE_STRUCT_DECLARE(UUID) \
 \
public: \
 \
    using DataT = NAME##_rs_data; \
 \
public: \
                    NAME##_rs   (void) noexcept; \
    virtual         ~NAME##_rs  (void) noexcept; \
 \
public: \
    DataT           data; \
};

#define RS_IMPL(NAME) \
TYPE_STRUCT_IMPLEMENT(NAME##_rs, GP_MODULE_UUID) \
 \
NAME##_rs::NAME##_rs (void) noexcept \
{ \
} \
 \
NAME##_rs::~NAME##_rs (void) noexcept \
{ \
} \
\
void    NAME##_rs::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut) \
{ \
    PROP(data); \
}

}//namespace GPlatform::API::RPC
