#pragma once

#include "GpApiCliTransportCtx.hpp"
#include "../../GpNetwork/GpNetwork.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiCliTransportHttpCtx final: public GpApiCliTransportCtx
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(GpApiCliTransportHttpCtx)
    CLASS_DECLARE_DEFAULTS(GpApiCliTransportHttpCtx)

public:
                                GpApiCliTransportHttpCtx    (void) noexcept;
    virtual                     ~GpApiCliTransportHttpCtx   (void) noexcept override final;

    void                        Clear                       (void);

    GpHttpRequest::SP           Rq                          (void) noexcept {return iRq;}
    GpHttpResponse::SP          Rs                          (void) noexcept {return iRs;}

    void                        SetRqRs                     (GpHttpRequest::SP  aRq,
                                                             GpHttpResponse::SP aRs) noexcept;

private:
    GpHttpRequest::SP           iRq;
    GpHttpResponse::SP          iRs;
};

}//namespace GPlatform::API::RPC
