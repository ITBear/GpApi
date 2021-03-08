#pragma once

#include "GpApiMethod.hpp"
#include "GpApiCliTransport.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiCli
{
public:
    CLASS_REMOVE_CTRS(GpApiCli)
    CLASS_DECLARE_DEFAULTS(GpApiCli)

public:
                                            GpApiCli        (GpApiCliTransport::SP aTransport) noexcept;
    virtual                                 ~GpApiCli       (void) noexcept;

    GpApiCliTransport::SP                   Transport       (void) noexcept {return iTransport;}

    template<typename RQ, typename RS>
    typename RS::DataT                      ProcessRQ       (const typename RQ::DataT&  aRqData,
                                                             std::string_view           aMethodName);

protected:
    virtual void                            CheckRsResult   (GpApiResultDesc::SP    aRes,
                                                             std::string_view       aMethodName) = 0;
    virtual void                            OnProcessRQ     (GpApiRqIfDesc& aRq) = 0;

private:
    GpApiCliTransport::SP                   iTransport;
};

template<typename RQ, typename RS>
typename RS::DataT  GpApiCli::ProcessRQ
(
    const typename RQ::DataT&   aRqData,
    std::string_view            aMethodName
)
{
    RQ rq;
    rq.SetMethod(aMethodName);
    rq.SetPayload(std::make_any<typename RQ::DataTRefC>(aRqData));

    OnProcessRQ(rq);

    //Do
    GpApiRsIfDesc::SP rsBase = iTransport->ProcessRQ(rq, RS::STypeInfo());

    //Check result
    CheckRsResult(rsBase->Result(), aMethodName);

    //Cast type
    RS& rs = GpTypeManager::S().Cast<RS>(rsBase.V());

    return std::any_cast<typename RS::DataTRef>(rs.Payload());
}

}//namespace GPlatform::API::RPC
