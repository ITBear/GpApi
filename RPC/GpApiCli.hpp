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

    void                                    SetSID          (std::string_view aSid);

    template<typename RQ, typename RS>
    typename RS::DataT                      ProcessRQ       (const typename RQ::DataT&  aRqData,
                                                             GpApiAddArgsDesc::SP&      aRqAddArgs,
                                                             std::string_view           aMethodName);

    template<typename RQ, typename RS>
    typename RS::DataT                      ProcessRQ       (const typename RQ::DataT&  aRqData,
                                                             std::string_view           aMethodName);

protected:
    virtual void                            CheckRsResult   (const GpApiResultDesc& aRes,
                                                             std::string_view       aMethodName) = 0;

private:
    std::string                             iSid;
    GpApiCliTransport::SP                   iTransport;
};

template<typename RQ, typename RS>
typename RS::DataT  GpApiCli::ProcessRQ
(
    const typename RQ::DataT&   aRqData,
    GpApiAddArgsDesc::SP&       aRqAddArgs,
    std::string_view            aMethodName
)
{
    RQ rq;
    rq.method   = aMethodName;
    rq.data     = aRqData;
    rq.args     = aRqAddArgs;

    if (iSid.length() > 0)
    {
        rq.sid = iSid;
    }

    //Do
    GpApiRsDesc::SP rsBase = iTransport->ProcessRQ(rq, RS::STypeInfo());

    //Check result
    CheckRsResult(rsBase->result.VC(), aMethodName);

    //Cast type
    RS rs = GpTypeManager::S().CastSP<RS>(rsBase);

    return rs->data;
}

template<typename RQ, typename RS>
typename RS::DataT  GpApiCli::ProcessRQ
(
    const typename RQ::DataT&   aRqData,
    std::string_view            aMethodName
)
{
    RQ rq;
    rq.method   = aMethodName;
    rq.data     = aRqData;

    if (iSid.length() > 0)
    {
        rq.sid = iSid;
    }

    //Do
    GpApiRsDesc::SP rsBase = iTransport->ProcessRQ(rq, RS::STypeInfo());

    //Check result
    CheckRsResult(rsBase->result.VC(), aMethodName);

    //Cast type
    RS& rs = GpTypeManager::S().Cast<RS>(rsBase.V());

    return rs.data;
}

}//namespace GPlatform::API::RPC
