#include "GpApiTypeDetectorJson.hpp"
#include "../../GpJson/GpJsonToStruct.hpp"

namespace GPlatform::API::RPC {

GpApiTypeDetectorJson::GpApiTypeDetectorJson (const GpApiMethodsManager&    aApiManager,
                                              const GpBytesArray&           aData) noexcept:
iApiManager(aApiManager),
iData(aData)
{
}

GpApiTypeDetectorJson::~GpApiTypeDetectorJson (void) noexcept
{
}


const GpTypeStructInfo& GpApiTypeDetectorJson::DetectTypeInfo (void) const
{
    rapidjson::Document                         jsonDOM;
    rapidjson::Document::ConstObject            jsonObject  = GpJsonToStruct::SParseJsonDom(iData, jsonDOM);
    rapidjson::Document::ConstMemberIterator    mit         = jsonObject.FindMember("method");

    THROW_GPE_COND
    (
        mit != jsonObject.MemberEnd(),
        "Json member 'method' was not found"_sv
    );

    const auto&         mitVal      = mit->value;
    std::string_view    methodName  = {mitVal.GetString(), mitVal.GetStringLength()};

    GpApiMethod::SP method = iApiManager.Find(methodName);
    return method->RqTypeInfo();
}

}//namespace GPlatform::API::RPC
