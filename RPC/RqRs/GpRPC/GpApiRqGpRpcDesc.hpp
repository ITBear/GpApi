#pragma once

#include "../GpApiRqIfDesc.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiRqGpRpcDesc: public GpApiRqIfDesc
{
public:
    CLASS_DECLARE_DEFAULTS(GpApiRqGpRpcDesc)
    TYPE_STRUCT_DECLARE("e30c3a62-e95e-496a-abe2-370ff474aeca"_sv)

public:
                                GpApiRqGpRpcDesc    (void) noexcept;
    virtual                     ~GpApiRqGpRpcDesc   (void) noexcept override;

    virtual std::string_view    Method              (void) const override final;
    virtual void                SetMethod           (std::string_view aMethod) override final;

public:
    std::string                 method;
    std::string                 sid;    //TODO make optional
    unix_ts_s_t                 ts;
};

#define GP_API_RQ(PREFIX, NAME, UUID) \
class PREFIX NAME##_rq final: public GpApiRqGpRpcDesc \
{ \
public: \
    CLASS_DECLARE_DEFAULTS(NAME##_rq) \
    TYPE_STRUCT_DECLARE(UUID) \
 \
public: \
 \
    using DataT     = NAME##_rq_data; \
    using DataTRef  = std::reference_wrapper<DataT>; \
    using DataTRefC = std::reference_wrapper<const DataT>; \
 \
public: \
                        NAME##_rq   (void) noexcept; \
                        NAME##_rq   (DataT&& aData) noexcept; \
    virtual             ~NAME##_rq  (void) noexcept; \
 \
    virtual std::any    Payload     (void) const override final; \
    virtual std::any    Payload     (void) override final; \
    virtual void        SetPayload  (std::any aAny) override final; \
 \
public: \
    DataT               data; \
};

#define GP_API_RQ_IMPL(NAME) \
TYPE_STRUCT_IMPLEMENT(NAME##_rq, GP_MODULE_UUID) \
 \
NAME##_rq::NAME##_rq (void) noexcept \
{ \
} \
 \
NAME##_rq::NAME##_rq (DataT&& aData) noexcept: \
data(std::move(aData)) \
{ \
} \
 \
NAME##_rq::~NAME##_rq (void) noexcept \
{ \
} \
 \
std::any    NAME##_rq::Payload (void) const \
{ \
   return std::make_any<DataTRefC>(data); \
} \
 \
std::any    NAME##_rq::Payload (void) \
{ \
   return std::make_any<DataTRef>(data); \
} \
 \
void    NAME##_rq::SetPayload (std::any aAny) \
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
void    NAME##_rq::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut) \
{ \
    PROP(data); \
}

}//GPlatform::API::RPC
