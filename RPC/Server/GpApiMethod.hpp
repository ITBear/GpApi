#pragma once

#include "../RqRs/GpApiRqIfDesc.hpp"
#include "../RqRs/GpApiRsIfDesc.hpp"

namespace GPlatform::API::RPC {

class GpApiMethod
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpApiMethod)
    CLASS_DECLARE_DEFAULTS(GpApiMethod)

public:
                                    GpApiMethod     (void) noexcept {}
    virtual                         ~GpApiMethod    (void) noexcept {}

    virtual GpApiRsIfDesc::SP       Process         (GpApiRqIfDesc& aRq) = 0;
    virtual const GpTypeStructInfo& RqTypeInfo      (void) const noexcept = 0;
    virtual const GpTypeStructInfo& RsTypeInfo      (void) const noexcept = 0;
};

#define API_METHOD(NAME) \
 \
class NAME final: public GpApiMethod \
{ \
public: \
    CLASS_REMOVE_CTRS_MOVE_COPY(NAME) \
    CLASS_DECLARE_DEFAULTS(NAME) \
 \
    using RqT   = NAME##_rq; \
    using RsT   = NAME##_rs; \
 \
    static GpApiMethodFactory::SP   SFactory    (void); \
 \
public: \
                                    NAME        (void) noexcept; \
    virtual                         ~NAME       (void) noexcept override final; \
 \
    virtual GpApiRsIfDesc::SP       Process     (GpApiRqIfDesc& aRq) override final; \
    virtual const GpTypeStructInfo& RqTypeInfo  (void) const noexcept override final; \
    virtual const GpTypeStructInfo& RsTypeInfo  (void) const noexcept override final; \
 \
protected: \
    typename RsT::DataT             Process     (RqT& aRq); \
};

#define API_METHOD_IMPL(NAME) \
 \
class NAME##_Factory final: public GpApiMethodFactory \
{ \
public: \
    CLASS_REMOVE_CTRS_MOVE_COPY(NAME##_Factory) \
    CLASS_DECLARE_DEFAULTS(NAME##_Factory) \
 \
public: \
                                NAME##_Factory  (void) noexcept:GpApiMethodFactory(#NAME) {} \
    virtual                     ~NAME##_Factory (void) noexcept override final {} \
 \
    virtual GpSP<GpApiMethod>   NewInstance     (void) const override final {return MakeSP<NAME>();} \
 \
}; \
 \
GpApiMethodFactory::SP  NAME::SFactory (void) \
{ \
    return MakeSP<NAME##_Factory>(); \
} \
 \
NAME::NAME (void) noexcept \
{ \
} \
 \
NAME::~NAME (void) noexcept \
{ \
} \
 \
GpApiRsIfDesc::SP   NAME::Process (GpApiRqIfDesc& aRq) \
{ \
    RsT::SP     rs      = MakeSP<RsT>(); \
    RsT::DataT  rsData  = Process(static_cast<RqT&>(aRq)); \
    rs.Vn().SetPayload(std::make_any<typename RsT::DataTRef>(rsData)); \
 \
    return rs; \
} \
 \
const GpTypeStructInfo& NAME::RqTypeInfo (void) const noexcept \
{ \
    return RqT::STypeInfo(); \
} \
 \
const GpTypeStructInfo& NAME::RsTypeInfo (void) const noexcept \
{ \
    return RsT::STypeInfo(); \
}

}//namespace GPlatform::API::RPC
