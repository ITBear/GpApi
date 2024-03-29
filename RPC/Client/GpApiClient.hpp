#pragma once

#include "Transport/GpApiCliTransports.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiClient
{
public:
    CLASS_REMOVE_CTRS_DEFAULT_MOVE_COPY(GpApiClient)
    CLASS_DECLARE_DEFAULTS(GpApiClient)

    using TransportSerializeRqFnT   = std::function<void(GpByteWriter& aRqWriter)>;
    using TransportProcessRqRsFnT   = std::function<void(std::any aArg)>;

public:
                                            GpApiClient     (GpApiCliTransport::SP aTransport) noexcept;
    virtual                                 ~GpApiClient    (void) noexcept;

    GpApiCliTransport::SP                   Transport       (void) noexcept {return iTransport;}

    template<typename RQ, typename RS>
    typename RS::DataT                      ProcessRpcRQ    (const typename RQ::DataT&              aRqData,
                                                             std::string_view                       aMethodName);

    template<typename RQ, typename RS>
    typename RS::DataT                      ProcessRpcRQ    (const typename RQ::DataT&              aRqData,
                                                             std::string_view                       aMethodName,
                                                             std::optional<TransportSerializeRqFnT> aBeforeTransportSerializeRqFn,
                                                             std::optional<TransportSerializeRqFnT> aAfterTransportSerializeRqFn,
                                                             std::optional<TransportProcessRqRsFnT> aBeforeTransportProcessFn,
                                                             std::optional<TransportProcessRqRsFnT> aAfterTransportProcessFn);

    template<typename RQ, typename RS>
    RS                                      ProcessRawRQ    (const RQ&                              aRq);

    template<typename RQ, typename RS>
    RS                                      ProcessRawRQ    (const RQ&                              aRq,
                                                             std::optional<TransportSerializeRqFnT> aBeforeTransportSerializeRqFn,
                                                             std::optional<TransportSerializeRqFnT> aAfterTransportSerializeRqFn,
                                                             std::optional<TransportProcessRqRsFnT> aBeforeTransportProcessFn,
                                                             std::optional<TransportProcessRqRsFnT> aAfterTransportProcessFn);

protected:
    virtual void                            CheckRsResult   (const GpApiRsIfDesc&   aRsDesc,
                                                             std::string_view       aMethodName) = 0;
    virtual void                            OnBeforeRpcRQ   (GpApiRqIfDesc& aRq) = 0;

private:
    GpApiCliTransport::SP                   iTransport;
};

template<typename RQ, typename RS>
typename RS::DataT  GpApiClient::ProcessRpcRQ
(
    const typename RQ::DataT&   aRqData,
    std::string_view            aMethodName
)
{
    RQ rq;
    rq.SetMethod(aMethodName);
    rq.SetPayload(std::make_any<typename RQ::DataTRefC>(aRqData));

    OnBeforeRpcRQ(rq);

    //Do
    GpApiRsIfDesc::SP rsBase = iTransport->ProcessRQ
    (
        rq,
        RS::STypeInfo()
    );

    //Check result
    CheckRsResult(rsBase.VC(), aMethodName);

    //Cast type
    RS& rs = GpTypeManager::S().Cast<RS>(rsBase.V());

    return std::any_cast<typename RS::DataTRef>(rs.Payload());
}

template<typename RQ, typename RS>
typename RS::DataT  GpApiClient::ProcessRpcRQ
(
    const typename RQ::DataT&               aRqData,
    std::string_view                        aMethodName,
    std::optional<TransportSerializeRqFnT>  aBeforeTransportSerializeRqFn,
    std::optional<TransportSerializeRqFnT>  aAfterTransportSerializeRqFn,
    std::optional<TransportProcessRqRsFnT>  aBeforeTransportProcessFn,
    std::optional<TransportProcessRqRsFnT>  aAfterTransportProcessFn
)
{
    RQ rq;
    rq.SetMethod(aMethodName);
    rq.SetPayload(std::make_any<typename RQ::DataTRefC>(aRqData));

    OnBeforeRpcRQ(rq);

    //Do
    GpApiRsIfDesc::SP rsBase = iTransport->ProcessRQ
    (
        rq,
        RS::STypeInfo(),
        aBeforeTransportSerializeRqFn,
        aAfterTransportSerializeRqFn,
        aBeforeTransportProcessFn,
        aAfterTransportProcessFn
    );

    //Check result
    CheckRsResult(rsBase.VC(), aMethodName);

    //Cast type
    RS& rs = GpTypeManager::S().Cast<RS>(rsBase.V());

    return std::any_cast<typename RS::DataTRef>(rs.Payload());
}

template<typename RQ, typename RS>
RS  GpApiClient::ProcessRawRQ (const RQ& aRq)
{
    //Do
    GpApiRsIfDesc::SP rsBase = iTransport->ProcessRQ
    (
        aRq,
        RS::value_type::STypeInfo()
    );

    //Check result
    CheckRsResult(rsBase.VC(), ""_sv);

    //Cast type
    return GpTypeManager::S().CastSP<RS>(rsBase);
}

template<typename RQ, typename RS>
RS  GpApiClient::ProcessRawRQ
(
    const RQ&                               aRq,
    std::optional<TransportSerializeRqFnT>  aBeforeTransportSerializeRqFn,
    std::optional<TransportSerializeRqFnT>  aAfterTransportSerializeRqFn,
    std::optional<TransportProcessRqRsFnT>  aBeforeTransportProcessFn,
    std::optional<TransportProcessRqRsFnT>  aAfterTransportProcessFn
)
{
    //Do
    GpApiRsIfDesc::SP rsBase = iTransport->ProcessRQ
    (
        aRq,
        RS::value_type::STypeInfo(),
        aBeforeTransportSerializeRqFn,
        aAfterTransportSerializeRqFn,
        aBeforeTransportProcessFn,
        aAfterTransportProcessFn
    );

    //Check result
    CheckRsResult(rsBase.VC(), ""_sv);

    //Cast type
    return GpTypeManager::S().CastSP<RS>(rsBase);
}

}//namespace GPlatform::API::RPC
