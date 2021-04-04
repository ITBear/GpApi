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
	GP_JSON_LIB_V		= 0
}

os_linux{
}

LIBS += -lGpCore2$$TARGET_POSTFIX$$GP_CORE_LIB_V
LIBS += -lGpJson$$TARGET_POSTFIX$$GP_JSON_LIB_V
#------------------------------ LIBS END ---------------------------------

SOURCES += \
	RPC/Client/GpApiClient.cpp \
	RPC/Client/Transport/GpApiCliTransport.cpp \
	RPC/GpApiVoidDesc.cpp \
	RPC/RqRs/GpApiRqIfDesc.cpp \
	RPC/RqRs/GpApiRsIfDesc.cpp \
	RPC/RqRs/GpApiRsResultDesc.cpp \
	RPC/RqRs/GpRPC/GpApiRqGpRpcDesc.cpp \
	RPC/RqRs/GpRPC/GpApiRsGpRpcDesc.cpp \
	RPC/RqRs/JsonRPC/GpApiRqJsonRpcDesc.cpp \
	RPC/RqRs/JsonRPC/GpApiRsJsonRpcDesc.cpp \
	RPC/RqRs/JsonRPC/GpApiRsJsonRpcResultDesc.cpp \
	RPC/RqRs/Raw/GpApiRqRawDesc.cpp \
	RPC/RqRs/Raw/GpApiRsRawDesc.cpp \
	RPC/Server/GpApiMethodFactory.cpp \
	RPC/Server/GpApiMethodsManager.cpp \
	RPC/Server/GpApiTypeDetectorJson.cpp \
	RPC/Server/GpApiTypeDetectorJsonFactory.cpp

HEADERS += \
    GpApi_global.hpp \
    GpApi.hpp \
    RPC/Client/GpApiClient.hpp \
	RPC/Client/Transport/GpApiCliTransport.hpp \
	RPC/Client/Transport/GpApiCliTransportCtx.hpp \
	RPC/Client/Transport/GpApiCliTransportFactory.hpp \
	RPC/Client/Transport/GpApiCliTransports.hpp \
    RPC/GpApiRPC.hpp \
    RPC/GpApiVoidDesc.hpp \
    RPC/RqRs/GpApiRqIfDesc.hpp \
    RPC/RqRs/GpApiRqRs.hpp \
    RPC/RqRs/GpApiRsIfDesc.hpp \
    RPC/RqRs/GpApiRsResultDesc.hpp \
    RPC/RqRs/GpRPC/GpApiGpRcpRqRs.hpp \
    RPC/RqRs/GpRPC/GpApiRqGpRpcDesc.hpp \
    RPC/RqRs/GpRPC/GpApiRsGpRpcDesc.hpp \
    RPC/RqRs/JsonRPC/GpApiJsonRcpRqRs.hpp \
    RPC/RqRs/JsonRPC/GpApiRqJsonRpcDesc.hpp \
    RPC/RqRs/JsonRPC/GpApiRsJsonRpcDesc.hpp \
    RPC/RqRs/JsonRPC/GpApiRsJsonRpcResultDesc.hpp \
    RPC/RqRs/Raw/GpApiRawRqRs.hpp \
    RPC/RqRs/Raw/GpApiRqRawDesc.hpp \
    RPC/RqRs/Raw/GpApiRsRawDesc.hpp \
    RPC/Server/GpApiMethod.hpp \
    RPC/Server/GpApiMethodFactory.hpp \
    RPC/Server/GpApiMethodsManager.hpp \
	RPC/Server/GpApiServer.hpp \
    RPC/Server/GpApiTypeDetector.hpp \
    RPC/Server/GpApiTypeDetectorFactory.hpp \
    RPC/Server/GpApiTypeDetectorJson.hpp \
	RPC/Server/GpApiTypeDetectorJsonFactory.hpp
