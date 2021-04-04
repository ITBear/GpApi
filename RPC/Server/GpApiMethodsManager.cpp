#include "GpApiMethodsManager.hpp"

namespace GPlatform::API::RPC {

GpApiMethodsManager::GpApiMethodsManager (void) noexcept
{
}

GpApiMethodsManager::~GpApiMethodsManager (void) noexcept
{
}

void    GpApiMethodsManager::Init (void)
{
    OnInit();
}

void    GpApiMethodsManager::Register (GpApiMethodFactory::SP aFactory)
{
    const auto& factory = aFactory.VC();
    iFactories.Register(factory.MethodName(), aFactory);
}

GpApiMethod::SP GpApiMethodsManager::Find (std::string_view aName) const
{
    auto res = iFactories.TryFind(aName);

    if (!res.has_value())
    {
        OnMethodNotFoundEx(aName);
    }

    return res.value().get()->NewInstance();
}

}//namespace GPlatform::API::RPC
