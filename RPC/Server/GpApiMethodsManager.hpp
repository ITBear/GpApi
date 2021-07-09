#pragma once

#include "GpApiMethodFactory.hpp"

namespace GPlatform::API::RPC {

class GPAPI_API GpApiMethodsManager
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpApiMethodsManager)
    CLASS_DECLARE_DEFAULTS(GpApiMethodsManager)

    using MethodFactoriesT = GpElementsCatalog<std::string_view, GpApiMethodFactory::SP>;

public:
                                GpApiMethodsManager     (void) noexcept;
    virtual                     ~GpApiMethodsManager    (void) noexcept;

    void                        Init                    (void);

    void                        Register                (GpApiMethodFactory::SP aFactory);
    GpApiMethod::SP             Find                    (std::string_view aName) const;

    virtual GpApiRsIfDesc::SP   NewDefaultRs            (void) const = 0;

protected:
    virtual void                OnInit                  (void) = 0;
    [[noreturn]] virtual void   OnMethodNotFoundEx      (std::string_view aName) const = 0;

protected:
    MethodFactoriesT            iFactories;
};

}//namespace GPlatform::API::RPC
