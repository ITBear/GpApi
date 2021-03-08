#pragma once

#include "GpApiRsIfDesc.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiRsBaseDesc: public GpApiRsIfDesc
{
public:
    CLASS_DECLARE_DEFAULTS(GpApiRsBaseDesc)
    TYPE_STRUCT_DECLARE("16df1627-8643-4a94-a646-b8badd8b31c7"_sv)

public:
                                        GpApiRsBaseDesc     (void) noexcept;
    virtual                             ~GpApiRsBaseDesc    (void) noexcept override;

    virtual GpApiResultDesc::SP         Result              (void) override final;
    virtual void                        SetResult           (GpApiResultDesc::SP aResult) override final;

public:
    GpApiResultDesc::SP                 result;
};

#define RS(PREFIX, NAME, UUID) \
class PREFIX NAME##_rs final: public GpApiRsBaseDesc \
{ \
public: \
    CLASS_DECLARE_DEFAULTS(NAME##_rs) \
    TYPE_STRUCT_DECLARE(UUID) \
 \
public: \
 \
    using DataT     = NAME##_rs_data; \
    using DataTRef  = std::reference_wrapper<DataT>; \
    using DataTRefC = std::reference_wrapper<const DataT>; \
 \
public: \
                        NAME##_rs   (void) noexcept; \
    virtual             ~NAME##_rs  (void) noexcept; \
 \
    virtual std::any    Payload     (void) const override final; \
    virtual std::any    Payload     (void) override final; \
    virtual void        SetPayload  (std::any aAny) override final; \
 \
public: \
    DataT               data; \
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
std::any    NAME##_rs::Payload (void) const \
{ \
    return std::make_any<DataTRefC>(data); \
} \
 \
std::any    NAME##_rs::Payload (void) \
{ \
    return std::make_any<DataTRef>(data); \
} \
 \
void    NAME##_rs::SetPayload (std::any aAny) \
{ \
    const auto& typeInfoAny = aAny.type(); \
 \
    if (typeInfoAny == typeid(DataTRef)) \
    { \
        data = std::any_cast<DataTRef>(aAny); \
    } else if (typeInfoAny == typeid(DataTRefC)) \
    { \
        data = std::any_cast<DataTRefC>(aAny); \
    } else \
    { \
        throw std::bad_any_cast(); \
    } \
} \
 \
void    NAME##_rs::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut) \
{ \
    PROP(data); \
}

}//namespace GPlatform::API::RPC
