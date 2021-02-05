TEMPLATE        = lib
#CONFIG         += staticlib
VER_MAJ		    = 0
VER_MIN		    = 1
VER_PAT		    = 0
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=a38cfdc0-da92-4899-9523-002751c6b88e
QMAKE_CXXFLAGS += -DGP_TYPE_SYSTEM_STATIC_ADD_TO_MANAGER
DEFINES		   += GPAPI_LIBRARY
PACKET_NAME     = GpApi
DIR_LEVEL       = ./..

include(../../QtGlobalPro.pri)

#------------------------------ LIBS BEGIN ---------------------------------
os_windows{
	GP_CORE_LIB_V		= 2
	GP_NETWORK_LIB_V	= 0
	GP_JSON_LIB_V		= 0
}

os_linux{
}

LIBS += -lGpCore2$$TARGET_POSTFIX$$GP_CORE_LIB_V
LIBS += -lGpNetwork$$TARGET_POSTFIX$$GP_NETWORK_LIB_V
LIBS += -lGpJson$$TARGET_POSTFIX$$GP_JSON_LIB_V
#------------------------------ LIBS END ---------------------------------

SOURCES += \
	RPC/GpApiAddArgsDesc.cpp \
	RPC/GpApiCli.cpp \
	RPC/GpApiCliTransport.cpp \
	RPC/GpApiCliTransportHttp.cpp \
	RPC/GpApiCliTransportHttpCtx.cpp \
	RPC/GpApiCliTransportHttpCtxFactory.cpp \
	RPC/GpApiCliTransportHttpFactory.cpp \
	RPC/GpApiMethodFactory.cpp \
	RPC/GpApiMethodsManager.cpp \
	RPC/GpApiResultDesc.cpp \
	RPC/GpApiRqDesc.cpp \
	RPC/GpApiRsDesc.cpp \
	RPC/GpApiSrvRequestHandlerHttp.cpp \
	RPC/GpApiTypeDetectorJson.cpp \
	RPC/GpApiTypeDetectorJsonFactory.cpp \
	RPC/GpApiVoidDesc.cpp

HEADERS += \
    GpApi_global.hpp \
    GpApi.hpp \
    RPC/GpApiAddArgsDesc.hpp \
    RPC/GpApiCli.hpp \
    RPC/GpApiCliTransport.hpp \
    RPC/GpApiCliTransportCtx.hpp \
    RPC/GpApiCliTransportFactory.hpp \
    RPC/GpApiCliTransportHttp.hpp \
    RPC/GpApiCliTransportHttpCtx.hpp \
    RPC/GpApiCliTransportHttpCtxFactory.hpp \
    RPC/GpApiCliTransportHttpFactory.hpp \
    RPC/GpApiMethod.hpp \
    RPC/GpApiMethodFactory.hpp \
    RPC/GpApiMethodsManager.hpp \
    RPC/GpApiRPC.hpp \
    RPC/GpApiResultDesc.hpp \
    RPC/GpApiRqDesc.hpp \
    RPC/GpApiRsDesc.hpp \
    RPC/GpApiSrvRequestHandlerHttp.hpp \
    RPC/GpApiTypeDetector.hpp \
    RPC/GpApiTypeDetectorFactory.hpp \
    RPC/GpApiTypeDetectorJson.hpp \
    RPC/GpApiTypeDetectorJsonFactory.hpp \
    RPC/GpApiVoidDesc.hpp
