#pragma once

#include "PlayFabHttp.h"
#include "StdAfx.h"
#include <list>
#include <map>

#include <AzCore/JSON/rapidjson.h>
#include <AzCore/JSON/writer.h>
#include <AzCore/JSON/document.h>
#include <rapidjson/stringbuffer.h>

#include <AzCore/RTTI/RTTI.h> // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

#ifdef GetObject // wingdi.h is extremely impollite and #defined a common function name, breaking RapidJson.  How rude.
#undef GetObject
#endif

using namespace rapidjson;

namespace PlayFabComboSdk
{
    typedef rapidjson::Writer< rapidjson::GenericStringBuffer< rapidjson::UTF8<> > > PFStringJsonWriter;
    template<typename ResType> using ProcessApiCallback = void(*)(const ResType& result, void* customData);

#ifdef WIN32
    typedef signed __int64 Int64;
    typedef signed __int32 Int32;
    typedef signed __int16 Int16;

    typedef unsigned __int64 Uint64;
    typedef unsigned __int32 Uint32;
    typedef unsigned __int16 Uint16;
#else
    typedef int64_t Int64;
    typedef int32_t Int32;
    typedef int16_t Int16;

    typedef uint64_t Uint64;
    typedef uint32_t Uint32;
    typedef uint16_t Uint16;
#endif

    template <typename BoxedType>
    class Boxed
    {
    public:
        BoxedType mValue;

        Boxed() : mValue(), mIsSet(false) {}
        Boxed(BoxedType value) : mValue(value), mIsSet(true) {}

        Boxed& operator=(BoxedType value) { mValue = value; mIsSet = true; return *this; }
        operator BoxedType() { return mValue; }

        void setNull() { mIsSet = false; }
        bool notNull() const { return mIsSet; }
        bool isNull() const { return !mIsSet; }
    private:
        bool mIsSet;
    };

    typedef Boxed<bool> OptionalBool;
    typedef Boxed<Uint16> OptionalUint16;
    typedef Boxed<Int16> OptionalInt16;
    typedef Boxed<Uint32> OptionalUint32;
    typedef Boxed<Int32> OptionalInt32;
    typedef Boxed<Uint64> OptionalUint64;
    typedef Boxed<Int64> OptionalInt64;
    typedef Boxed<float> OptionalFloat;
    typedef Boxed<double> OptionalDouble;
    typedef Boxed<time_t> OptionalTime;

    struct PlayFabBaseModel
    {
        virtual ~PlayFabBaseModel() {}
        virtual void writeJSON(PFStringJsonWriter& writer) = 0;
        virtual bool readFromValue(const rapidjson::Value& obj) = 0;

        AZStd::string toJSONString();

        static bool DecodeRequest(PlayFabRequest* request);
    };

    enum MultitypeVarTypes
    {
        MultitypeNull,
        MultitypeBool,
        MultitypeNumber,
        MultitypeString
    };

    struct MultitypeVar : public PlayFabBaseModel
    {
        AZ_TYPE_INFO(MultitypeVar,"{88487543-8a33-5e5a-b9f9-fafbcd04171a}");
    private:
        MultitypeVarTypes mType;
        AZStd::string mString;
        bool mBool;
        double mNumber;

    public:

        MultitypeVar() : mType(MultitypeNull), mString(), mBool(), mNumber() {}
        MultitypeVar(bool val) : mType(MultitypeBool), mString(), mBool(val), mNumber() {}
        MultitypeVar(Uint16 val) : mType(MultitypeNumber), mString(), mBool(), mNumber(val) {}
        MultitypeVar(Int16 val) : mType(MultitypeNumber), mString(), mBool(), mNumber(val) {}
        MultitypeVar(Uint32 val) : mType(MultitypeNumber), mString(), mBool(), mNumber(val) {}
        MultitypeVar(Int32 val) : mType(MultitypeNumber), mString(), mBool(), mNumber(val) {}
        MultitypeVar(float val) : mType(MultitypeNumber), mString(), mBool(), mNumber(val) {}
        MultitypeVar(double val) : mType(MultitypeNumber), mString(), mBool(), mNumber(val) {}
        MultitypeVar(AZStd::string val) : mType(MultitypeString), mString(val), mBool(), mNumber() {}

        MultitypeVar(const rapidjson::Value& obj)
        {
            readFromValue(obj);
        }

        void setNull() { mType = MultitypeNull; }
        bool notNull() const { return mType != MultitypeNull; }
        bool isNull() const { return mType == MultitypeNull; }
        MultitypeVarTypes getType() const { return mType; }

        MultitypeVar& operator=(bool val) { mBool = val; mType = MultitypeBool; return *this; }
        MultitypeVar& operator=(Uint16 val) { mNumber = val; mType = MultitypeNumber; return *this; }
        MultitypeVar& operator=(Int16 val) { mNumber = val; mType = MultitypeNumber; return *this; }
        MultitypeVar& operator=(Uint32 val) { mNumber = val; mType = MultitypeNumber; return *this; }
        MultitypeVar& operator=(Int32 val) { mNumber = val; mType = MultitypeNumber; return *this; }
        MultitypeVar& operator=(float val) { mNumber = val; mType = MultitypeNumber; return *this; }
        MultitypeVar& operator=(double val) { mNumber = val; mType = MultitypeNumber; return *this; }
        MultitypeVar& operator=(AZStd::string val) { mString = val; mType = MultitypeString; return *this; }

        operator bool() const { return mBool; }
        operator Uint16() const { return (Uint16)mNumber; }
        operator Int16() const { return (Int16)mNumber; }
        operator Uint32() const { return (Uint32)mNumber; }
        operator Int32() const { return (Int32)mNumber; }
        operator float() const { return (float)mNumber; }
        operator double() const { return mNumber; }
        operator AZStd::string() const { return mString; }

        ~MultitypeVar() {}
        void writeJSON(PFStringJsonWriter& writer) override;
        bool readFromValue(const rapidjson::Value& obj) override;
    };

    void writeDatetime(time_t datetime, PFStringJsonWriter& writer);
    time_t readDatetime(const rapidjson::Value& obj);

    // #THIRD_KIND_PLAYFAB_SHUTDOWN_FIXES: Changed to string literals for the value lookups. Don't use AWS::String in statics, because it results in the destructor being called after the AWS allocator has been destroyed, which results in a shutdown crash.
    struct StringCompare
    {
        bool operator () (const char *a, const char *b) const
        {
            return strcmp(a, b)<0;
        }
    };

    inline AZStd::string PlayFabBaseModel::toJSONString()
    {
        GenericStringBuffer< UTF8<> > buffer;
        PFStringJsonWriter writer(buffer);
        writeJSON(writer);
        return buffer.GetString();
    }

    inline void MultitypeVar::writeJSON(PFStringJsonWriter& writer)
    {
        switch (mType)
        {
        case MultitypeNull:
            writer.Null();
            break;
        case MultitypeBool:
            writer.Bool(mBool);
            break;
        case MultitypeNumber:
            writer.Double(mNumber);
            break;
        case MultitypeString:
            writer.String(mString.c_str());
            break;
        }
    }

    inline bool MultitypeVar::readFromValue(const rapidjson::Value& obj)
    {
        if (obj.IsNull())
        {
            mType = MultitypeNull;
        }
        else if (obj.IsBool())
        {
            mType = MultitypeBool;
            mBool = obj.GetBool();
        }
        else if (obj.IsNumber())
        {
            mType = MultitypeNumber;
            mNumber = obj.GetDouble();
        }
        else if (obj.IsString())
        {
            mType = MultitypeNumber;
            mString = obj.GetString();
        }
        else
        {
            mType = MultitypeNull;
            return false;
        }
        return true;
    }

    inline void writeDatetime(time_t datetime, PFStringJsonWriter& writer)
    {
        char buff[40];
        strftime(buff, 40, "%Y-%m-%dT%H:%M:%S.000Z", gmtime(&datetime));
        writer.String(buff);
    }

    inline time_t readDatetime(const rapidjson::Value& obj)
    {
        AZStd::string enumStr = obj.GetString();

        tm timeStruct = {};
        unsigned int milliseconds = 0; // milliseconds are truncated in a standard time_t structure
        sscanf(enumStr.c_str(), "%u-%u-%uT%u:%u%u.%uZ", &timeStruct.tm_year, &timeStruct.tm_mon, &timeStruct.tm_mday,
            &timeStruct.tm_hour, &timeStruct.tm_min, &timeStruct.tm_sec, &milliseconds);
        timeStruct.tm_year -= 1900;
        timeStruct.tm_mon -= 1;

        return mktime(&timeStruct);
    }

    inline bool PlayFabBaseModel::DecodeRequest(PlayFabRequest* request)
    {
        bool result = false;

        // Check for bad responses
        if (request->mResponseSize != 0 // Not a null response
            && request->mResponseJson->GetParseError() == kParseErrorNone) // Proper json response
        {
            // Check if the returned json indicates an error
            auto end = request->mResponseJson->MemberEnd();
            auto errorCodeJson = request->mResponseJson->FindMember("errorCode");
            auto data = request->mResponseJson->FindMember("data");

            // There should be no error code, data should exist, and be properly formatted
            result = errorCodeJson == end && data != end && data->value.IsObject();
        }

        if (!result)
            request->HandleErrorReport();

        // API will parse the result data object into the known object type (We don't know it here)
        return result;
    }
}

// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
namespace AZ
{
    
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<bool>, "{fd4f554a-8af2-53db-b527-fd69ade5494c}");
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<PlayFabComboSdk::Uint16>, "{4e8e2f32-05c8-58aa-9fd8-49483c617851}");
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<PlayFabComboSdk::Int16>, "{544ed2d9-63a1-5dfb-9418-136f68a5d7a7}");
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<PlayFabComboSdk::Uint32>, "{7db2e3d3-c2a6-5bcc-9fb1-902ae3c7fcf2}");
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<PlayFabComboSdk::Int32>, "{6b95684c-69e4-5671-b4a2-bc1cc9a29bf1}");
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<PlayFabComboSdk::Uint64>, "{89715e2c-d05c-59b1-9c5e-eacdf3dae913}");
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<PlayFabComboSdk::Int64>, "{8e09d5cb-4bfe-5d23-8da3-546a82c89e3c}");
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<float>, "{731554ff-e136-5c4d-b657-b4d816eb0943}");
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<double>, "{3be90ed2-1945-5667-9187-c990ba5ee458}");
    //AZ_TYPE_INFO_SPECIALIZE(Boxed<time_t>, "{f18905d5-33cb-5a59-b957-1a67831f2ea1}");
}
// #THIRD_KIND_END
