#pragma once

#include "GpApiAddArgsDesc.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiRqDesc: public GpTypeStructBase
{
public:
    CLASS_DECLARE_DEFAULTS(GpApiRqDesc)
    TYPE_STRUCT_DECLARE("e30c3a62-e95e-496a-abe2-370ff474aeca"_sv)

public:
                            GpApiRqDesc     (void) noexcept;
    virtual                 ~GpApiRqDesc    (void) noexcept override;

public:
    std::string             method;
    std::string             sid;    //TODO make optional
    unix_ts_s_t             ts;
    GpApiAddArgsDesc::SP    args;
};

#define RQ(PREFIX, NAME, UUID) \
class PREFIX NAME##_rq final: public GpApiRqDesc \
{ \
public: \
    CLASS_DECLARE_DEFAULTS(NAME##_rq) \
    TYPE_STRUCT_DECLARE(UUID) \
 \
public: \
 \
    using DataT = NAME##_rq_data; \
 \
public: \
                    NAME##_rq   (void) noexcept; \
                    NAME##_rq   (DataT&& aData) noexcept; \
    virtual         ~NAME##_rq  (void) noexcept; \
 \
public: \
    DataT           data; \
};

#define RQ_IMPL(NAME) \
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
void    NAME##_rq::_SCollectStructProps (GpTypePropInfo::C::Vec::Val& aPropsOut) \
{ \
    PROP(data); \
}

}//GPlatform::API::RPC
