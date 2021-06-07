#pragma once

#include "../GpApiRsIfDesc.hpp"
#include "GpApiRsJsonRpcResultDesc.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiRsJsonRpcDesc: public GpApiRsIfDesc
{
public:
    CLASS_DECLARE_DEFAULTS(GpApiRsJsonRpcDesc)
    TYPE_STRUCT_DECLARE("2b335342-83fd-48f5-8427-6787f794d156"_sv)

public:
                                        GpApiRsJsonRpcDesc  (void) noexcept;
    virtual                             ~GpApiRsJsonRpcDesc (void) noexcept override;

    virtual GpApiRsResultDesc::CSP      Result              (void) const override final;
    virtual GpApiRsResultDesc::SP       Result              (void) override final;
    virtual void                        SetResult           (GpApiRsResultDesc::SP aResult) override final;

public:
    std::string                         jsonrpc = std::string("2.0"_sv);
    s_int_64                            id      = 1;
    GpApiRsJsonRpcResultDesc::SP        error;
};

#define JSON_RPC_API_RS(PREFIX, NAME, UUID) \
class PREFIX NAME##_rs final: public GpApiRsJsonRpcDesc \
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
    DataT               result; \
};

#define JSON_RPC_API_RS_IMPL(NAME) \
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
    return std::make_any<DataTRefC>(result); \
} \
 \
std::any    NAME##_rs::Payload (void) \
{ \
    return std::make_any<DataTRef>(result); \
} \
 \
void    NAME##_rs::SetPayload (std::any aAny) \
{ \
    const auto& typeInfoAny = aAny.type(); \
 \
    if (typeInfoAny == typeid(DataTRef)) \
    { \
        result = std::any_cast<DataTRef>(aAny); \
    } else if (typeInfoAny == typeid(DataTRefC)) \
    { \
        result = std::any_cast<DataTRefC>(aAny); \
    } else \
    { \
        throw std::bad_any_cast(); \
    } \
} \
 \
void    NAME##_rs::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut) \
{ \
    PROP(result); \
}

}//namespace GPlatform::API::RPC
