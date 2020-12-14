#pragma once

#include "../GpCore2/GpCore.hpp"

#if defined(GPAPI_LIBRARY)
    #define GPAPI_API GP_DECL_EXPORT
#else
    #define GPAPI_API GP_DECL_IMPORT
#endif
