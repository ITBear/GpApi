#pragma once

#include "GpApiMethodsManager.hpp"
#include "GpApiTypeDetectorFactory.hpp"
#include "../../GpNetwork/HTTP/GpHttpRequestHandler.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiSrvRequestHandlerHttp: public GpHttpRequestHandler
{
public:
    CLASS_REMOVE_CTRS_EXCEPT_DEFAULT(GpApiSrvRequestHandlerHttp)
    CLASS_DECLARE_DEFAULTS(GpApiSrvRequestHandlerHttp)

protected:
                                GpApiSrvRequestHandlerHttp  (GpApiMethodsManager::SP        aApiManager,
                                                             GpTypeMapperFactory::SP        aTypeMapperFactory,
                                                             GpApiTypeDetectorFactory::SP   aTypeDetectorFactory) noexcept;

public:
    virtual                     ~GpApiSrvRequestHandlerHttp (void) noexcept override;

    virtual GpHttpResponse::SP  OnRequest                   (const GpHttpRequest& aRequest) const override final;

protected:
    virtual GpApiResultDesc::SP GenResultOK                 (void) const = 0;
    virtual GpApiResultDesc::SP GenResultEx                 (const std::exception& e) const = 0;
    virtual GpApiResultDesc::SP GenResultExUnknown          (void) const = 0;
    virtual GpApiResultDesc::SP CallAndCatch                (std::function<void()>) const = 0;

private:
    GpApiMethodsManager::SP         iApiManager;
    GpTypeMapperFactory::SP         iTypeMapperFactory;
    GpApiTypeDetectorFactory::SP    iTypeDetectorFactory;
};

}//namespace GPlatform::API::RPC
