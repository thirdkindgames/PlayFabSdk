#pragma once

#include <PlayFabComboSdk/PlayFabBaseModel.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <AzCore/RTTI/RTTI.h> // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

using namespace rapidjson;

namespace PlayFabComboSdk
{
    namespace ClientModels
    {
        struct AcceptTradeRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::AcceptTradeRequest,"{06b5a3f9-310f-5058-bd26-98d384e4a2c1}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string OfferingPlayerId;
            AZStd::string TradeId;
            AZStd::vector<AZStd::string> AcceptedInventoryInstanceIds; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            AcceptTradeRequest() :
                PlayFabBaseModel(),
                OfferingPlayerId(),
                TradeId(),
                AcceptedInventoryInstanceIds()
            {}

            AcceptTradeRequest(const AcceptTradeRequest& src) :
                PlayFabBaseModel(),
                OfferingPlayerId(src.OfferingPlayerId),
                TradeId(src.TradeId),
                AcceptedInventoryInstanceIds(src.AcceptedInventoryInstanceIds)
            {}

            AcceptTradeRequest(const rapidjson::Value& obj) : AcceptTradeRequest()
            {
                readFromValue(obj);
            }

            ~AcceptTradeRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("OfferingPlayerId");
                writer.String(OfferingPlayerId.c_str());
                writer.String("TradeId");
                writer.String(TradeId.c_str());
                if (!AcceptedInventoryInstanceIds.empty()) {
                    writer.String("AcceptedInventoryInstanceIds");
                    writer.StartArray();
                    for (auto iter = AcceptedInventoryInstanceIds.begin(); iter != AcceptedInventoryInstanceIds.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator OfferingPlayerId_member = obj.FindMember("OfferingPlayerId");
                if (OfferingPlayerId_member != obj.MemberEnd() && !OfferingPlayerId_member->value.IsNull()) OfferingPlayerId = OfferingPlayerId_member->value.GetString();
                const Value::ConstMemberIterator TradeId_member = obj.FindMember("TradeId");
                if (TradeId_member != obj.MemberEnd() && !TradeId_member->value.IsNull()) TradeId = TradeId_member->value.GetString();
                const Value::ConstMemberIterator AcceptedInventoryInstanceIds_member = obj.FindMember("AcceptedInventoryInstanceIds");
                if (AcceptedInventoryInstanceIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = AcceptedInventoryInstanceIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        AcceptedInventoryInstanceIds.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        enum TradeStatus
        {
            TradeStatusInvalid,
            TradeStatusOpening,
            TradeStatusOpen,
            TradeStatusAccepting,
            TradeStatusAccepted,
            TradeStatusFilled,
            TradeStatusCancelled
        };

        inline void writeTradeStatusEnumJSON(TradeStatus enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case TradeStatusInvalid: writer.String("Invalid"); break;
            case TradeStatusOpening: writer.String("Opening"); break;
            case TradeStatusOpen: writer.String("Open"); break;
            case TradeStatusAccepting: writer.String("Accepting"); break;
            case TradeStatusAccepted: writer.String("Accepted"); break;
            case TradeStatusFilled: writer.String("Filled"); break;
            case TradeStatusCancelled: writer.String("Cancelled"); break;

            }
        }

        inline TradeStatus readTradeStatusFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<TradeStatus>(obj.GetInt());

            static std::map<const char *, TradeStatus, PlayFabComboSdk::StringCompare> _TradeStatusMap;
            if (_TradeStatusMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _TradeStatusMap["Invalid"] = TradeStatusInvalid;
                _TradeStatusMap["Opening"] = TradeStatusOpening;
                _TradeStatusMap["Open"] = TradeStatusOpen;
                _TradeStatusMap["Accepting"] = TradeStatusAccepting;
                _TradeStatusMap["Accepted"] = TradeStatusAccepted;
                _TradeStatusMap["Filled"] = TradeStatusFilled;
                _TradeStatusMap["Cancelled"] = TradeStatusCancelled;

            }

            auto output = _TradeStatusMap.find(obj.GetString());
            if (output != _TradeStatusMap.end())
                return output->second;

            return TradeStatusInvalid; // Basically critical fail
        }

        struct TradeInfo : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::TradeInfo,"{35b61787-4200-5965-9cfa-5b89d0ac792f}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            Boxed<TradeStatus> Status;
            AZStd::string TradeId;
            AZStd::string OfferingPlayerId;
            AZStd::vector<AZStd::string> OfferedInventoryInstanceIds; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<AZStd::string> OfferedCatalogItemIds; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<AZStd::string> RequestedCatalogItemIds; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<AZStd::string> AllowedPlayerIds; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string AcceptedPlayerId;
            AZStd::vector<AZStd::string> AcceptedInventoryInstanceIds; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            OptionalTime OpenedAt;
            OptionalTime FilledAt;
            OptionalTime CancelledAt;
            OptionalTime InvalidatedAt;

            TradeInfo() :
                PlayFabBaseModel(),
                Status(),
                TradeId(),
                OfferingPlayerId(),
                OfferedInventoryInstanceIds(),
                OfferedCatalogItemIds(),
                RequestedCatalogItemIds(),
                AllowedPlayerIds(),
                AcceptedPlayerId(),
                AcceptedInventoryInstanceIds(),
                OpenedAt(),
                FilledAt(),
                CancelledAt(),
                InvalidatedAt()
            {}

            TradeInfo(const TradeInfo& src) :
                PlayFabBaseModel(),
                Status(src.Status),
                TradeId(src.TradeId),
                OfferingPlayerId(src.OfferingPlayerId),
                OfferedInventoryInstanceIds(src.OfferedInventoryInstanceIds),
                OfferedCatalogItemIds(src.OfferedCatalogItemIds),
                RequestedCatalogItemIds(src.RequestedCatalogItemIds),
                AllowedPlayerIds(src.AllowedPlayerIds),
                AcceptedPlayerId(src.AcceptedPlayerId),
                AcceptedInventoryInstanceIds(src.AcceptedInventoryInstanceIds),
                OpenedAt(src.OpenedAt),
                FilledAt(src.FilledAt),
                CancelledAt(src.CancelledAt),
                InvalidatedAt(src.InvalidatedAt)
            {}

            TradeInfo(const rapidjson::Value& obj) : TradeInfo()
            {
                readFromValue(obj);
            }

            ~TradeInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Status.notNull()) {
                    writer.String("Status");
                    writeTradeStatusEnumJSON(Status, writer);
                }
                if (TradeId.length() > 0) {
                    writer.String("TradeId");
                    writer.String(TradeId.c_str());
                }
                if (OfferingPlayerId.length() > 0) {
                    writer.String("OfferingPlayerId");
                    writer.String(OfferingPlayerId.c_str());
                }
                if (!OfferedInventoryInstanceIds.empty()) {
                    writer.String("OfferedInventoryInstanceIds");
                    writer.StartArray();
                    for (auto iter = OfferedInventoryInstanceIds.begin(); iter != OfferedInventoryInstanceIds.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!OfferedCatalogItemIds.empty()) {
                    writer.String("OfferedCatalogItemIds");
                    writer.StartArray();
                    for (auto iter = OfferedCatalogItemIds.begin(); iter != OfferedCatalogItemIds.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!RequestedCatalogItemIds.empty()) {
                    writer.String("RequestedCatalogItemIds");
                    writer.StartArray();
                    for (auto iter = RequestedCatalogItemIds.begin(); iter != RequestedCatalogItemIds.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!AllowedPlayerIds.empty()) {
                    writer.String("AllowedPlayerIds");
                    writer.StartArray();
                    for (auto iter = AllowedPlayerIds.begin(); iter != AllowedPlayerIds.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (AcceptedPlayerId.length() > 0) {
                    writer.String("AcceptedPlayerId");
                    writer.String(AcceptedPlayerId.c_str());
                }
                if (!AcceptedInventoryInstanceIds.empty()) {
                    writer.String("AcceptedInventoryInstanceIds");
                    writer.StartArray();
                    for (auto iter = AcceptedInventoryInstanceIds.begin(); iter != AcceptedInventoryInstanceIds.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (OpenedAt.notNull()) {
                    writer.String("OpenedAt");
                    writeDatetime(OpenedAt, writer);
                }
                if (FilledAt.notNull()) {
                    writer.String("FilledAt");
                    writeDatetime(FilledAt, writer);
                }
                if (CancelledAt.notNull()) {
                    writer.String("CancelledAt");
                    writeDatetime(CancelledAt, writer);
                }
                if (InvalidatedAt.notNull()) {
                    writer.String("InvalidatedAt");
                    writeDatetime(InvalidatedAt, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
                if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readTradeStatusFromValue(Status_member->value);
                const Value::ConstMemberIterator TradeId_member = obj.FindMember("TradeId");
                if (TradeId_member != obj.MemberEnd() && !TradeId_member->value.IsNull()) TradeId = TradeId_member->value.GetString();
                const Value::ConstMemberIterator OfferingPlayerId_member = obj.FindMember("OfferingPlayerId");
                if (OfferingPlayerId_member != obj.MemberEnd() && !OfferingPlayerId_member->value.IsNull()) OfferingPlayerId = OfferingPlayerId_member->value.GetString();
                const Value::ConstMemberIterator OfferedInventoryInstanceIds_member = obj.FindMember("OfferedInventoryInstanceIds");
                if (OfferedInventoryInstanceIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = OfferedInventoryInstanceIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        OfferedInventoryInstanceIds.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator OfferedCatalogItemIds_member = obj.FindMember("OfferedCatalogItemIds");
                if (OfferedCatalogItemIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = OfferedCatalogItemIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        OfferedCatalogItemIds.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator RequestedCatalogItemIds_member = obj.FindMember("RequestedCatalogItemIds");
                if (RequestedCatalogItemIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = RequestedCatalogItemIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        RequestedCatalogItemIds.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator AllowedPlayerIds_member = obj.FindMember("AllowedPlayerIds");
                if (AllowedPlayerIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = AllowedPlayerIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        AllowedPlayerIds.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator AcceptedPlayerId_member = obj.FindMember("AcceptedPlayerId");
                if (AcceptedPlayerId_member != obj.MemberEnd() && !AcceptedPlayerId_member->value.IsNull()) AcceptedPlayerId = AcceptedPlayerId_member->value.GetString();
                const Value::ConstMemberIterator AcceptedInventoryInstanceIds_member = obj.FindMember("AcceptedInventoryInstanceIds");
                if (AcceptedInventoryInstanceIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = AcceptedInventoryInstanceIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        AcceptedInventoryInstanceIds.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator OpenedAt_member = obj.FindMember("OpenedAt");
                if (OpenedAt_member != obj.MemberEnd() && !OpenedAt_member->value.IsNull()) OpenedAt = readDatetime(OpenedAt_member->value);
                const Value::ConstMemberIterator FilledAt_member = obj.FindMember("FilledAt");
                if (FilledAt_member != obj.MemberEnd() && !FilledAt_member->value.IsNull()) FilledAt = readDatetime(FilledAt_member->value);
                const Value::ConstMemberIterator CancelledAt_member = obj.FindMember("CancelledAt");
                if (CancelledAt_member != obj.MemberEnd() && !CancelledAt_member->value.IsNull()) CancelledAt = readDatetime(CancelledAt_member->value);
                const Value::ConstMemberIterator InvalidatedAt_member = obj.FindMember("InvalidatedAt");
                if (InvalidatedAt_member != obj.MemberEnd() && !InvalidatedAt_member->value.IsNull()) InvalidatedAt = readDatetime(InvalidatedAt_member->value);

                return true;
            }
        };

        struct AcceptTradeResponse : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::AcceptTradeResponse,"{e6ebdf1c-5c14-522d-b270-5b68cf33a6f4}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            TradeInfo* Trade;

            AcceptTradeResponse() :
                PlayFabBaseModel(),
                Trade(nullptr)
            {}

            AcceptTradeResponse(const AcceptTradeResponse& src) :
                PlayFabBaseModel(),
                Trade(src.Trade ? new TradeInfo(*src.Trade) : nullptr)
            {}

            AcceptTradeResponse(const rapidjson::Value& obj) : AcceptTradeResponse()
            {
                readFromValue(obj);
            }

            ~AcceptTradeResponse()
            {
                if (Trade != nullptr) delete Trade;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Trade != nullptr) {
                    writer.String("Trade");
                    Trade->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Trade_member = obj.FindMember("Trade");
                if (Trade_member != obj.MemberEnd() && !Trade_member->value.IsNull()) Trade = new TradeInfo(Trade_member->value);

                return true;
            }
        };

        struct AdCampaignAttributionModel : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::AdCampaignAttributionModel,"{c011e1c7-58c3-5990-942a-001a00e478ed}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string Platform;
            AZStd::string CampaignId;
            time_t AttributedAt;

            AdCampaignAttributionModel() :
                PlayFabBaseModel(),
                Platform(),
                CampaignId(),
                AttributedAt(0)
            {}

            AdCampaignAttributionModel(const AdCampaignAttributionModel& src) :
                PlayFabBaseModel(),
                Platform(src.Platform),
                CampaignId(src.CampaignId),
                AttributedAt(src.AttributedAt)
            {}

            AdCampaignAttributionModel(const rapidjson::Value& obj) : AdCampaignAttributionModel()
            {
                readFromValue(obj);
            }

            ~AdCampaignAttributionModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Platform.length() > 0) {
                    writer.String("Platform");
                    writer.String(Platform.c_str());
                }
                if (CampaignId.length() > 0) {
                    writer.String("CampaignId");
                    writer.String(CampaignId.c_str());
                }
                writer.String("AttributedAt");
                writeDatetime(AttributedAt, writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
                if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = Platform_member->value.GetString();
                const Value::ConstMemberIterator CampaignId_member = obj.FindMember("CampaignId");
                if (CampaignId_member != obj.MemberEnd() && !CampaignId_member->value.IsNull()) CampaignId = CampaignId_member->value.GetString();
                const Value::ConstMemberIterator AttributedAt_member = obj.FindMember("AttributedAt");
                if (AttributedAt_member != obj.MemberEnd() && !AttributedAt_member->value.IsNull()) AttributedAt = readDatetime(AttributedAt_member->value);

                return true;
            }
        };

        struct AddFriendRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::AddFriendRequest,"{c0d05831-19f3-58fd-ba3f-dea1d18d6bd8}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string FriendPlayFabId;
            AZStd::string FriendUsername;
            AZStd::string FriendEmail;
            AZStd::string FriendTitleDisplayName;

            AddFriendRequest() :
                PlayFabBaseModel(),
                FriendPlayFabId(),
                FriendUsername(),
                FriendEmail(),
                FriendTitleDisplayName()
            {}

            AddFriendRequest(const AddFriendRequest& src) :
                PlayFabBaseModel(),
                FriendPlayFabId(src.FriendPlayFabId),
                FriendUsername(src.FriendUsername),
                FriendEmail(src.FriendEmail),
                FriendTitleDisplayName(src.FriendTitleDisplayName)
            {}

            AddFriendRequest(const rapidjson::Value& obj) : AddFriendRequest()
            {
                readFromValue(obj);
            }

            ~AddFriendRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (FriendPlayFabId.length() > 0) {
                    writer.String("FriendPlayFabId");
                    writer.String(FriendPlayFabId.c_str());
                }
                if (FriendUsername.length() > 0) {
                    writer.String("FriendUsername");
                    writer.String(FriendUsername.c_str());
                }
                if (FriendEmail.length() > 0) {
                    writer.String("FriendEmail");
                    writer.String(FriendEmail.c_str());
                }
                if (FriendTitleDisplayName.length() > 0) {
                    writer.String("FriendTitleDisplayName");
                    writer.String(FriendTitleDisplayName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
                if (FriendPlayFabId_member != obj.MemberEnd() && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();
                const Value::ConstMemberIterator FriendUsername_member = obj.FindMember("FriendUsername");
                if (FriendUsername_member != obj.MemberEnd() && !FriendUsername_member->value.IsNull()) FriendUsername = FriendUsername_member->value.GetString();
                const Value::ConstMemberIterator FriendEmail_member = obj.FindMember("FriendEmail");
                if (FriendEmail_member != obj.MemberEnd() && !FriendEmail_member->value.IsNull()) FriendEmail = FriendEmail_member->value.GetString();
                const Value::ConstMemberIterator FriendTitleDisplayName_member = obj.FindMember("FriendTitleDisplayName");
                if (FriendTitleDisplayName_member != obj.MemberEnd() && !FriendTitleDisplayName_member->value.IsNull()) FriendTitleDisplayName = FriendTitleDisplayName_member->value.GetString();

                return true;
            }
        };

        struct AddFriendResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::AddFriendResult,"{d803ad7a-9f1c-56f2-81b4-1ab1bafcefdc}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            bool Created;

            AddFriendResult() :
                PlayFabBaseModel(),
                Created(false)
            {}

            AddFriendResult(const AddFriendResult& src) :
                PlayFabBaseModel(),
                Created(src.Created)
            {}

            AddFriendResult(const rapidjson::Value& obj) : AddFriendResult()
            {
                readFromValue(obj);
            }

            ~AddFriendResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Created");
                writer.Bool(Created);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
                if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = Created_member->value.GetBool();

                return true;
            }
        };

        struct GenericServiceId : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GenericServiceId,"{c4df560b-9467-5a28-904e-4f8475bd0094}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string ServiceName;
            AZStd::string UserId;

            GenericServiceId() :
                PlayFabBaseModel(),
                ServiceName(),
                UserId()
            {}

            GenericServiceId(const GenericServiceId& src) :
                PlayFabBaseModel(),
                ServiceName(src.ServiceName),
                UserId(src.UserId)
            {}

            GenericServiceId(const rapidjson::Value& obj) : GenericServiceId()
            {
                readFromValue(obj);
            }

            ~GenericServiceId()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ServiceName");
                writer.String(ServiceName.c_str());
                writer.String("UserId");
                writer.String(UserId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ServiceName_member = obj.FindMember("ServiceName");
                if (ServiceName_member != obj.MemberEnd() && !ServiceName_member->value.IsNull()) ServiceName = ServiceName_member->value.GetString();
                const Value::ConstMemberIterator UserId_member = obj.FindMember("UserId");
                if (UserId_member != obj.MemberEnd() && !UserId_member->value.IsNull()) UserId = UserId_member->value.GetString();

                return true;
            }
        };

        struct AddGenericIDRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::AddGenericIDRequest,"{473aaa30-e39f-5739-b168-239e70757c1d}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            GenericServiceId GenericId;

            AddGenericIDRequest() :
                PlayFabBaseModel(),
                GenericId()
            {}

            AddGenericIDRequest(const AddGenericIDRequest& src) :
                PlayFabBaseModel(),
                GenericId(src.GenericId)
            {}

            AddGenericIDRequest(const rapidjson::Value& obj) : AddGenericIDRequest()
            {
                readFromValue(obj);
            }

            ~AddGenericIDRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("GenericId");
                GenericId.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GenericId_member = obj.FindMember("GenericId");
                if (GenericId_member != obj.MemberEnd() && !GenericId_member->value.IsNull()) GenericId = GenericServiceId(GenericId_member->value);

                return true;
            }
        };

        struct AddGenericIDResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::AddGenericIDResult,"{79a28670-9965-5480-b165-a9a3e32a387e}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            AddGenericIDResult() :
                PlayFabBaseModel()
            {}

            AddGenericIDResult(const AddGenericIDResult& src) :
                PlayFabBaseModel()
            {}

            AddGenericIDResult(const rapidjson::Value& obj) : AddGenericIDResult()
            {
                readFromValue(obj);
            }

            ~AddGenericIDResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct AddSharedGroupMembersRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::AddSharedGroupMembersRequest,"{af437d90-2ba4-59fc-9f1f-ba7a18b2e4d9}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string SharedGroupId;
            AZStd::vector<AZStd::string> PlayFabIds; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            AddSharedGroupMembersRequest() :
                PlayFabBaseModel(),
                SharedGroupId(),
                PlayFabIds()
            {}

            AddSharedGroupMembersRequest(const AddSharedGroupMembersRequest& src) :
                PlayFabBaseModel(),
                SharedGroupId(src.SharedGroupId),
                PlayFabIds(src.PlayFabIds)
            {}

            AddSharedGroupMembersRequest(const rapidjson::Value& obj) : AddSharedGroupMembersRequest()
            {
                readFromValue(obj);
            }

            ~AddSharedGroupMembersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("SharedGroupId");
                writer.String(SharedGroupId.c_str());
                writer.String("PlayFabIds");
                writer.StartArray();
                for (auto iter = PlayFabIds.begin(); iter != PlayFabIds.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
                if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();
                const Value::ConstMemberIterator PlayFabIds_member = obj.FindMember("PlayFabIds");
                if (PlayFabIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = PlayFabIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        PlayFabIds.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct AddSharedGroupMembersResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::AddSharedGroupMembersResult,"{081eb015-a843-5790-ba2a-a7388584633e}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            AddSharedGroupMembersResult() :
                PlayFabBaseModel()
            {}

            AddSharedGroupMembersResult(const AddSharedGroupMembersResult& src) :
                PlayFabBaseModel()
            {}

            AddSharedGroupMembersResult(const rapidjson::Value& obj) : AddSharedGroupMembersResult()
            {
                readFromValue(obj);
            }

            ~AddSharedGroupMembersResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct AddUsernamePasswordRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::AddUsernamePasswordRequest,"{4f036def-709a-50e4-9af1-b8511a7447f7}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string Username;
            AZStd::string Email;
            AZStd::string Password;

            AddUsernamePasswordRequest() :
                PlayFabBaseModel(),
                Username(),
                Email(),
                Password()
            {}

            AddUsernamePasswordRequest(const AddUsernamePasswordRequest& src) :
                PlayFabBaseModel(),
                Username(src.Username),
                Email(src.Email),
                Password(src.Password)
            {}

            AddUsernamePasswordRequest(const rapidjson::Value& obj) : AddUsernamePasswordRequest()
            {
                readFromValue(obj);
            }

            ~AddUsernamePasswordRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Username");
                writer.String(Username.c_str());
                writer.String("Email");
                writer.String(Email.c_str());
                writer.String("Password");
                writer.String(Password.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
                const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
                if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
                const Value::ConstMemberIterator Password_member = obj.FindMember("Password");
                if (Password_member != obj.MemberEnd() && !Password_member->value.IsNull()) Password = Password_member->value.GetString();

                return true;
            }
        };

        struct AddUsernamePasswordResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::AddUsernamePasswordResult,"{4140b971-1dda-53c0-9f5f-4bc52ea9ba49}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string Username;

            AddUsernamePasswordResult() :
                PlayFabBaseModel(),
                Username()
            {}

            AddUsernamePasswordResult(const AddUsernamePasswordResult& src) :
                PlayFabBaseModel(),
                Username(src.Username)
            {}

            AddUsernamePasswordResult(const rapidjson::Value& obj) : AddUsernamePasswordResult()
            {
                readFromValue(obj);
            }

            ~AddUsernamePasswordResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Username.length() > 0) {
                    writer.String("Username");
                    writer.String(Username.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();

                return true;
            }
        };

        struct AddUserVirtualCurrencyRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::AddUserVirtualCurrencyRequest,"{d2ec4fd0-b01e-5d17-a347-568a8b414cb3}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string VirtualCurrency;
            Int32 Amount;

            AddUserVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                VirtualCurrency(),
                Amount(0)
            {}

            AddUserVirtualCurrencyRequest(const AddUserVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                VirtualCurrency(src.VirtualCurrency),
                Amount(src.Amount)
            {}

            AddUserVirtualCurrencyRequest(const rapidjson::Value& obj) : AddUserVirtualCurrencyRequest()
            {
                readFromValue(obj);
            }

            ~AddUserVirtualCurrencyRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("VirtualCurrency");
                writer.String(VirtualCurrency.c_str());
                writer.String("Amount");
                writer.Int(Amount);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
                const Value::ConstMemberIterator Amount_member = obj.FindMember("Amount");
                if (Amount_member != obj.MemberEnd() && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();

                return true;
            }
        };

        struct AndroidDevicePushNotificationRegistrationRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::AndroidDevicePushNotificationRegistrationRequest,"{3eaeef24-6074-5665-a6ec-d2e368aed8bc}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string DeviceToken;
            OptionalBool SendPushNotificationConfirmation;
            AZStd::string ConfirmationMessage;

            AndroidDevicePushNotificationRegistrationRequest() :
                PlayFabBaseModel(),
                DeviceToken(),
                SendPushNotificationConfirmation(),
                ConfirmationMessage()
            {}

            AndroidDevicePushNotificationRegistrationRequest(const AndroidDevicePushNotificationRegistrationRequest& src) :
                PlayFabBaseModel(),
                DeviceToken(src.DeviceToken),
                SendPushNotificationConfirmation(src.SendPushNotificationConfirmation),
                ConfirmationMessage(src.ConfirmationMessage)
            {}

            AndroidDevicePushNotificationRegistrationRequest(const rapidjson::Value& obj) : AndroidDevicePushNotificationRegistrationRequest()
            {
                readFromValue(obj);
            }

            ~AndroidDevicePushNotificationRegistrationRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("DeviceToken");
                writer.String(DeviceToken.c_str());
                if (SendPushNotificationConfirmation.notNull()) {
                    writer.String("SendPushNotificationConfirmation");
                    writer.Bool(SendPushNotificationConfirmation);
                }
                if (ConfirmationMessage.length() > 0) {
                    writer.String("ConfirmationMessage");
                    writer.String(ConfirmationMessage.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DeviceToken_member = obj.FindMember("DeviceToken");
                if (DeviceToken_member != obj.MemberEnd() && !DeviceToken_member->value.IsNull()) DeviceToken = DeviceToken_member->value.GetString();
                const Value::ConstMemberIterator SendPushNotificationConfirmation_member = obj.FindMember("SendPushNotificationConfirmation");
                if (SendPushNotificationConfirmation_member != obj.MemberEnd() && !SendPushNotificationConfirmation_member->value.IsNull()) SendPushNotificationConfirmation = SendPushNotificationConfirmation_member->value.GetBool();
                const Value::ConstMemberIterator ConfirmationMessage_member = obj.FindMember("ConfirmationMessage");
                if (ConfirmationMessage_member != obj.MemberEnd() && !ConfirmationMessage_member->value.IsNull()) ConfirmationMessage = ConfirmationMessage_member->value.GetString();

                return true;
            }
        };

        struct AndroidDevicePushNotificationRegistrationResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::AndroidDevicePushNotificationRegistrationResult,"{a7f278b3-3b4e-5c4d-bded-a1b162c8a06e}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            AndroidDevicePushNotificationRegistrationResult() :
                PlayFabBaseModel()
            {}

            AndroidDevicePushNotificationRegistrationResult(const AndroidDevicePushNotificationRegistrationResult& src) :
                PlayFabBaseModel()
            {}

            AndroidDevicePushNotificationRegistrationResult(const rapidjson::Value& obj) : AndroidDevicePushNotificationRegistrationResult()
            {
                readFromValue(obj);
            }

            ~AndroidDevicePushNotificationRegistrationResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct AttributeInstallRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::AttributeInstallRequest,"{4c15475d-88b6-50f0-b5b1-783275a06e64}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string Idfa;
            AZStd::string Adid;

            AttributeInstallRequest() :
                PlayFabBaseModel(),
                Idfa(),
                Adid()
            {}

            AttributeInstallRequest(const AttributeInstallRequest& src) :
                PlayFabBaseModel(),
                Idfa(src.Idfa),
                Adid(src.Adid)
            {}

            AttributeInstallRequest(const rapidjson::Value& obj) : AttributeInstallRequest()
            {
                readFromValue(obj);
            }

            ~AttributeInstallRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Idfa.length() > 0) {
                    writer.String("Idfa");
                    writer.String(Idfa.c_str());
                }
                if (Adid.length() > 0) {
                    writer.String("Adid");
                    writer.String(Adid.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Idfa_member = obj.FindMember("Idfa");
                if (Idfa_member != obj.MemberEnd() && !Idfa_member->value.IsNull()) Idfa = Idfa_member->value.GetString();
                const Value::ConstMemberIterator Adid_member = obj.FindMember("Adid");
                if (Adid_member != obj.MemberEnd() && !Adid_member->value.IsNull()) Adid = Adid_member->value.GetString();

                return true;
            }
        };

        struct AttributeInstallResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::AttributeInstallResult,"{edc97227-e67e-53a6-b743-a94ccefa38fd}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            AttributeInstallResult() :
                PlayFabBaseModel()
            {}

            AttributeInstallResult(const AttributeInstallResult& src) :
                PlayFabBaseModel()
            {}

            AttributeInstallResult(const rapidjson::Value& obj) : AttributeInstallResult()
            {
                readFromValue(obj);
            }

            ~AttributeInstallResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct CancelTradeRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::CancelTradeRequest,"{a6a18f26-3e9d-5993-b457-9462dab62f31}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string TradeId;

            CancelTradeRequest() :
                PlayFabBaseModel(),
                TradeId()
            {}

            CancelTradeRequest(const CancelTradeRequest& src) :
                PlayFabBaseModel(),
                TradeId(src.TradeId)
            {}

            CancelTradeRequest(const rapidjson::Value& obj) : CancelTradeRequest()
            {
                readFromValue(obj);
            }

            ~CancelTradeRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("TradeId");
                writer.String(TradeId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TradeId_member = obj.FindMember("TradeId");
                if (TradeId_member != obj.MemberEnd() && !TradeId_member->value.IsNull()) TradeId = TradeId_member->value.GetString();

                return true;
            }
        };

        struct CancelTradeResponse : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::CancelTradeResponse,"{25b8316a-c9de-51ad-98f1-2b9718841621}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            TradeInfo* Trade;

            CancelTradeResponse() :
                PlayFabBaseModel(),
                Trade(nullptr)
            {}

            CancelTradeResponse(const CancelTradeResponse& src) :
                PlayFabBaseModel(),
                Trade(src.Trade ? new TradeInfo(*src.Trade) : nullptr)
            {}

            CancelTradeResponse(const rapidjson::Value& obj) : CancelTradeResponse()
            {
                readFromValue(obj);
            }

            ~CancelTradeResponse()
            {
                if (Trade != nullptr) delete Trade;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Trade != nullptr) {
                    writer.String("Trade");
                    Trade->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Trade_member = obj.FindMember("Trade");
                if (Trade_member != obj.MemberEnd() && !Trade_member->value.IsNull()) Trade = new TradeInfo(Trade_member->value);

                return true;
            }
        };

        struct CartItem : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::CartItem,"{a6883b34-cc5b-5ab7-9e2d-c5ff5000ea54}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string ItemId;
            AZStd::string ItemClass;
            AZStd::string ItemInstanceId;
            AZStd::string DisplayName;
            AZStd::string Description;
            AZStd::unordered_map<AZStd::string, Uint32> VirtualCurrencyPrices;
            AZStd::unordered_map<AZStd::string, Uint32> RealCurrencyPrices;
            AZStd::unordered_map<AZStd::string, Uint32> VCAmount;

            CartItem() :
                PlayFabBaseModel(),
                ItemId(),
                ItemClass(),
                ItemInstanceId(),
                DisplayName(),
                Description(),
                VirtualCurrencyPrices(),
                RealCurrencyPrices(),
                VCAmount()
            {}

            CartItem(const CartItem& src) :
                PlayFabBaseModel(),
                ItemId(src.ItemId),
                ItemClass(src.ItemClass),
                ItemInstanceId(src.ItemInstanceId),
                DisplayName(src.DisplayName),
                Description(src.Description),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices),
                RealCurrencyPrices(src.RealCurrencyPrices),
                VCAmount(src.VCAmount)
            {}

            CartItem(const rapidjson::Value& obj) : CartItem()
            {
                readFromValue(obj);
            }

            ~CartItem()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (ItemId.length() > 0) {
                    writer.String("ItemId");
                    writer.String(ItemId.c_str());
                }
                if (ItemClass.length() > 0) {
                    writer.String("ItemClass");
                    writer.String(ItemClass.c_str());
                }
                if (ItemInstanceId.length() > 0) {
                    writer.String("ItemInstanceId");
                    writer.String(ItemInstanceId.c_str());
                }
                if (DisplayName.length() > 0) {
                    writer.String("DisplayName");
                    writer.String(DisplayName.c_str());
                }
                if (Description.length() > 0) {
                    writer.String("Description");
                    writer.String(Description.c_str());
                }
                if (!VirtualCurrencyPrices.empty()) {
                    writer.String("VirtualCurrencyPrices");
                    writer.StartObject();
                    for (auto iter = VirtualCurrencyPrices.begin(); iter != VirtualCurrencyPrices.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                if (!RealCurrencyPrices.empty()) {
                    writer.String("RealCurrencyPrices");
                    writer.StartObject();
                    for (auto iter = RealCurrencyPrices.begin(); iter != RealCurrencyPrices.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                if (!VCAmount.empty()) {
                    writer.String("VCAmount");
                    writer.StartObject();
                    for (auto iter = VCAmount.begin(); iter != VCAmount.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
                const Value::ConstMemberIterator ItemClass_member = obj.FindMember("ItemClass");
                if (ItemClass_member != obj.MemberEnd() && !ItemClass_member->value.IsNull()) ItemClass = ItemClass_member->value.GetString();
                const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
                if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator Description_member = obj.FindMember("Description");
                if (Description_member != obj.MemberEnd() && !Description_member->value.IsNull()) Description = Description_member->value.GetString();
                const Value::ConstMemberIterator VirtualCurrencyPrices_member = obj.FindMember("VirtualCurrencyPrices");
                if (VirtualCurrencyPrices_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrencyPrices_member->value.MemberBegin(); iter != VirtualCurrencyPrices_member->value.MemberEnd(); ++iter) {
                        VirtualCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
                    }
                }
                const Value::ConstMemberIterator RealCurrencyPrices_member = obj.FindMember("RealCurrencyPrices");
                if (RealCurrencyPrices_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = RealCurrencyPrices_member->value.MemberBegin(); iter != RealCurrencyPrices_member->value.MemberEnd(); ++iter) {
                        RealCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
                    }
                }
                const Value::ConstMemberIterator VCAmount_member = obj.FindMember("VCAmount");
                if (VCAmount_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VCAmount_member->value.MemberBegin(); iter != VCAmount_member->value.MemberEnd(); ++iter) {
                        VCAmount[iter->name.GetString()] = iter->value.GetUint();
                    }
                }

                return true;
            }
        };

        struct CatalogItemConsumableInfo : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::CatalogItemConsumableInfo,"{5b6ed8d2-a0d9-57bc-ae2e-e2c7119d461c}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            OptionalUint32 UsageCount;
            OptionalUint32 UsagePeriod;
            AZStd::string UsagePeriodGroup;

            CatalogItemConsumableInfo() :
                PlayFabBaseModel(),
                UsageCount(),
                UsagePeriod(),
                UsagePeriodGroup()
            {}

            CatalogItemConsumableInfo(const CatalogItemConsumableInfo& src) :
                PlayFabBaseModel(),
                UsageCount(src.UsageCount),
                UsagePeriod(src.UsagePeriod),
                UsagePeriodGroup(src.UsagePeriodGroup)
            {}

            CatalogItemConsumableInfo(const rapidjson::Value& obj) : CatalogItemConsumableInfo()
            {
                readFromValue(obj);
            }

            ~CatalogItemConsumableInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (UsageCount.notNull()) {
                    writer.String("UsageCount");
                    writer.Uint(UsageCount);
                }
                if (UsagePeriod.notNull()) {
                    writer.String("UsagePeriod");
                    writer.Uint(UsagePeriod);
                }
                if (UsagePeriodGroup.length() > 0) {
                    writer.String("UsagePeriodGroup");
                    writer.String(UsagePeriodGroup.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator UsageCount_member = obj.FindMember("UsageCount");
                if (UsageCount_member != obj.MemberEnd() && !UsageCount_member->value.IsNull()) UsageCount = UsageCount_member->value.GetUint();
                const Value::ConstMemberIterator UsagePeriod_member = obj.FindMember("UsagePeriod");
                if (UsagePeriod_member != obj.MemberEnd() && !UsagePeriod_member->value.IsNull()) UsagePeriod = UsagePeriod_member->value.GetUint();
                const Value::ConstMemberIterator UsagePeriodGroup_member = obj.FindMember("UsagePeriodGroup");
                if (UsagePeriodGroup_member != obj.MemberEnd() && !UsagePeriodGroup_member->value.IsNull()) UsagePeriodGroup = UsagePeriodGroup_member->value.GetString();

                return true;
            }
        };

        struct CatalogItemContainerInfo : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::CatalogItemContainerInfo,"{acf009ed-cd2b-5912-b789-08d864d5d272}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string KeyItemId;
            AZStd::vector<AZStd::string> ItemContents; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<AZStd::string> ResultTableContents; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::unordered_map<AZStd::string, Uint32> VirtualCurrencyContents;

            CatalogItemContainerInfo() :
                PlayFabBaseModel(),
                KeyItemId(),
                ItemContents(),
                ResultTableContents(),
                VirtualCurrencyContents()
            {}

            CatalogItemContainerInfo(const CatalogItemContainerInfo& src) :
                PlayFabBaseModel(),
                KeyItemId(src.KeyItemId),
                ItemContents(src.ItemContents),
                ResultTableContents(src.ResultTableContents),
                VirtualCurrencyContents(src.VirtualCurrencyContents)
            {}

            CatalogItemContainerInfo(const rapidjson::Value& obj) : CatalogItemContainerInfo()
            {
                readFromValue(obj);
            }

            ~CatalogItemContainerInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (KeyItemId.length() > 0) {
                    writer.String("KeyItemId");
                    writer.String(KeyItemId.c_str());
                }
                if (!ItemContents.empty()) {
                    writer.String("ItemContents");
                    writer.StartArray();
                    for (auto iter = ItemContents.begin(); iter != ItemContents.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!ResultTableContents.empty()) {
                    writer.String("ResultTableContents");
                    writer.StartArray();
                    for (auto iter = ResultTableContents.begin(); iter != ResultTableContents.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!VirtualCurrencyContents.empty()) {
                    writer.String("VirtualCurrencyContents");
                    writer.StartObject();
                    for (auto iter = VirtualCurrencyContents.begin(); iter != VirtualCurrencyContents.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator KeyItemId_member = obj.FindMember("KeyItemId");
                if (KeyItemId_member != obj.MemberEnd() && !KeyItemId_member->value.IsNull()) KeyItemId = KeyItemId_member->value.GetString();
                const Value::ConstMemberIterator ItemContents_member = obj.FindMember("ItemContents");
                if (ItemContents_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = ItemContents_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        ItemContents.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator ResultTableContents_member = obj.FindMember("ResultTableContents");
                if (ResultTableContents_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = ResultTableContents_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        ResultTableContents.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator VirtualCurrencyContents_member = obj.FindMember("VirtualCurrencyContents");
                if (VirtualCurrencyContents_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrencyContents_member->value.MemberBegin(); iter != VirtualCurrencyContents_member->value.MemberEnd(); ++iter) {
                        VirtualCurrencyContents[iter->name.GetString()] = iter->value.GetUint();
                    }
                }

                return true;
            }
        };

        struct CatalogItemBundleInfo : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::CatalogItemBundleInfo,"{fd94aa50-cb8d-5f2c-b76b-e2e6bc50bdab}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<AZStd::string> BundledItems; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<AZStd::string> BundledResultTables; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::unordered_map<AZStd::string, Uint32> BundledVirtualCurrencies;

            CatalogItemBundleInfo() :
                PlayFabBaseModel(),
                BundledItems(),
                BundledResultTables(),
                BundledVirtualCurrencies()
            {}

            CatalogItemBundleInfo(const CatalogItemBundleInfo& src) :
                PlayFabBaseModel(),
                BundledItems(src.BundledItems),
                BundledResultTables(src.BundledResultTables),
                BundledVirtualCurrencies(src.BundledVirtualCurrencies)
            {}

            CatalogItemBundleInfo(const rapidjson::Value& obj) : CatalogItemBundleInfo()
            {
                readFromValue(obj);
            }

            ~CatalogItemBundleInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!BundledItems.empty()) {
                    writer.String("BundledItems");
                    writer.StartArray();
                    for (auto iter = BundledItems.begin(); iter != BundledItems.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!BundledResultTables.empty()) {
                    writer.String("BundledResultTables");
                    writer.StartArray();
                    for (auto iter = BundledResultTables.begin(); iter != BundledResultTables.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!BundledVirtualCurrencies.empty()) {
                    writer.String("BundledVirtualCurrencies");
                    writer.StartObject();
                    for (auto iter = BundledVirtualCurrencies.begin(); iter != BundledVirtualCurrencies.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BundledItems_member = obj.FindMember("BundledItems");
                if (BundledItems_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = BundledItems_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        BundledItems.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator BundledResultTables_member = obj.FindMember("BundledResultTables");
                if (BundledResultTables_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = BundledResultTables_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        BundledResultTables.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator BundledVirtualCurrencies_member = obj.FindMember("BundledVirtualCurrencies");
                if (BundledVirtualCurrencies_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = BundledVirtualCurrencies_member->value.MemberBegin(); iter != BundledVirtualCurrencies_member->value.MemberEnd(); ++iter) {
                        BundledVirtualCurrencies[iter->name.GetString()] = iter->value.GetUint();
                    }
                }

                return true;
            }
        };

        struct CatalogItem : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::CatalogItem,"{b956cf4f-31c8-5115-86ce-30ad567ee684}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string ItemId;
            AZStd::string ItemClass;
            AZStd::string CatalogVersion;
            AZStd::string DisplayName;
            AZStd::string Description;
            AZStd::unordered_map<AZStd::string, Uint32> VirtualCurrencyPrices;
            AZStd::unordered_map<AZStd::string, Uint32> RealCurrencyPrices;
            AZStd::vector<AZStd::string> Tags; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string CustomData;
            CatalogItemConsumableInfo* Consumable;
            CatalogItemContainerInfo* Container;
            CatalogItemBundleInfo* Bundle;
            bool CanBecomeCharacter;
            bool IsStackable;
            bool IsTradable;
            AZStd::string ItemImageUrl;
            bool IsLimitedEdition;
            Int32 InitialLimitedEditionCount;

            CatalogItem() :
                PlayFabBaseModel(),
                ItemId(),
                ItemClass(),
                CatalogVersion(),
                DisplayName(),
                Description(),
                VirtualCurrencyPrices(),
                RealCurrencyPrices(),
                Tags(),
                CustomData(),
                Consumable(nullptr),
                Container(nullptr),
                Bundle(nullptr),
                CanBecomeCharacter(false),
                IsStackable(false),
                IsTradable(false),
                ItemImageUrl(),
                IsLimitedEdition(false),
                InitialLimitedEditionCount(0)
            {}

            CatalogItem(const CatalogItem& src) :
                PlayFabBaseModel(),
                ItemId(src.ItemId),
                ItemClass(src.ItemClass),
                CatalogVersion(src.CatalogVersion),
                DisplayName(src.DisplayName),
                Description(src.Description),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices),
                RealCurrencyPrices(src.RealCurrencyPrices),
                Tags(src.Tags),
                CustomData(src.CustomData),
                Consumable(src.Consumable ? new CatalogItemConsumableInfo(*src.Consumable) : nullptr),
                Container(src.Container ? new CatalogItemContainerInfo(*src.Container) : nullptr),
                Bundle(src.Bundle ? new CatalogItemBundleInfo(*src.Bundle) : nullptr),
                CanBecomeCharacter(src.CanBecomeCharacter),
                IsStackable(src.IsStackable),
                IsTradable(src.IsTradable),
                ItemImageUrl(src.ItemImageUrl),
                IsLimitedEdition(src.IsLimitedEdition),
                InitialLimitedEditionCount(src.InitialLimitedEditionCount)
            {}

            CatalogItem(const rapidjson::Value& obj) : CatalogItem()
            {
                readFromValue(obj);
            }

            ~CatalogItem()
            {
                if (Consumable != nullptr) delete Consumable;
                if (Container != nullptr) delete Container;
                if (Bundle != nullptr) delete Bundle;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ItemId");
                writer.String(ItemId.c_str());
                if (ItemClass.length() > 0) {
                    writer.String("ItemClass");
                    writer.String(ItemClass.c_str());
                }
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                if (DisplayName.length() > 0) {
                    writer.String("DisplayName");
                    writer.String(DisplayName.c_str());
                }
                if (Description.length() > 0) {
                    writer.String("Description");
                    writer.String(Description.c_str());
                }
                if (!VirtualCurrencyPrices.empty()) {
                    writer.String("VirtualCurrencyPrices");
                    writer.StartObject();
                    for (auto iter = VirtualCurrencyPrices.begin(); iter != VirtualCurrencyPrices.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                if (!RealCurrencyPrices.empty()) {
                    writer.String("RealCurrencyPrices");
                    writer.StartObject();
                    for (auto iter = RealCurrencyPrices.begin(); iter != RealCurrencyPrices.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                if (!Tags.empty()) {
                    writer.String("Tags");
                    writer.StartArray();
                    for (auto iter = Tags.begin(); iter != Tags.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (CustomData.length() > 0) {
                    writer.String("CustomData");
                    writer.String(CustomData.c_str());
                }
                if (Consumable != nullptr) {
                    writer.String("Consumable");
                    Consumable->writeJSON(writer);
                }
                if (Container != nullptr) {
                    writer.String("Container");
                    Container->writeJSON(writer);
                }
                if (Bundle != nullptr) {
                    writer.String("Bundle");
                    Bundle->writeJSON(writer);
                }
                writer.String("CanBecomeCharacter");
                writer.Bool(CanBecomeCharacter);
                writer.String("IsStackable");
                writer.Bool(IsStackable);
                writer.String("IsTradable");
                writer.Bool(IsTradable);
                if (ItemImageUrl.length() > 0) {
                    writer.String("ItemImageUrl");
                    writer.String(ItemImageUrl.c_str());
                }
                writer.String("IsLimitedEdition");
                writer.Bool(IsLimitedEdition);
                writer.String("InitialLimitedEditionCount");
                writer.Int(InitialLimitedEditionCount);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
                const Value::ConstMemberIterator ItemClass_member = obj.FindMember("ItemClass");
                if (ItemClass_member != obj.MemberEnd() && !ItemClass_member->value.IsNull()) ItemClass = ItemClass_member->value.GetString();
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator Description_member = obj.FindMember("Description");
                if (Description_member != obj.MemberEnd() && !Description_member->value.IsNull()) Description = Description_member->value.GetString();
                const Value::ConstMemberIterator VirtualCurrencyPrices_member = obj.FindMember("VirtualCurrencyPrices");
                if (VirtualCurrencyPrices_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrencyPrices_member->value.MemberBegin(); iter != VirtualCurrencyPrices_member->value.MemberEnd(); ++iter) {
                        VirtualCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
                    }
                }
                const Value::ConstMemberIterator RealCurrencyPrices_member = obj.FindMember("RealCurrencyPrices");
                if (RealCurrencyPrices_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = RealCurrencyPrices_member->value.MemberBegin(); iter != RealCurrencyPrices_member->value.MemberEnd(); ++iter) {
                        RealCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
                    }
                }
                const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
                if (Tags_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Tags_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Tags.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator CustomData_member = obj.FindMember("CustomData");
                if (CustomData_member != obj.MemberEnd() && !CustomData_member->value.IsNull()) CustomData = CustomData_member->value.GetString();
                const Value::ConstMemberIterator Consumable_member = obj.FindMember("Consumable");
                if (Consumable_member != obj.MemberEnd() && !Consumable_member->value.IsNull()) Consumable = new CatalogItemConsumableInfo(Consumable_member->value);
                const Value::ConstMemberIterator Container_member = obj.FindMember("Container");
                if (Container_member != obj.MemberEnd() && !Container_member->value.IsNull()) Container = new CatalogItemContainerInfo(Container_member->value);
                const Value::ConstMemberIterator Bundle_member = obj.FindMember("Bundle");
                if (Bundle_member != obj.MemberEnd() && !Bundle_member->value.IsNull()) Bundle = new CatalogItemBundleInfo(Bundle_member->value);
                const Value::ConstMemberIterator CanBecomeCharacter_member = obj.FindMember("CanBecomeCharacter");
                if (CanBecomeCharacter_member != obj.MemberEnd() && !CanBecomeCharacter_member->value.IsNull()) CanBecomeCharacter = CanBecomeCharacter_member->value.GetBool();
                const Value::ConstMemberIterator IsStackable_member = obj.FindMember("IsStackable");
                if (IsStackable_member != obj.MemberEnd() && !IsStackable_member->value.IsNull()) IsStackable = IsStackable_member->value.GetBool();
                const Value::ConstMemberIterator IsTradable_member = obj.FindMember("IsTradable");
                if (IsTradable_member != obj.MemberEnd() && !IsTradable_member->value.IsNull()) IsTradable = IsTradable_member->value.GetBool();
                const Value::ConstMemberIterator ItemImageUrl_member = obj.FindMember("ItemImageUrl");
                if (ItemImageUrl_member != obj.MemberEnd() && !ItemImageUrl_member->value.IsNull()) ItemImageUrl = ItemImageUrl_member->value.GetString();
                const Value::ConstMemberIterator IsLimitedEdition_member = obj.FindMember("IsLimitedEdition");
                if (IsLimitedEdition_member != obj.MemberEnd() && !IsLimitedEdition_member->value.IsNull()) IsLimitedEdition = IsLimitedEdition_member->value.GetBool();
                const Value::ConstMemberIterator InitialLimitedEditionCount_member = obj.FindMember("InitialLimitedEditionCount");
                if (InitialLimitedEditionCount_member != obj.MemberEnd() && !InitialLimitedEditionCount_member->value.IsNull()) InitialLimitedEditionCount = InitialLimitedEditionCount_member->value.GetInt();

                return true;
            }
        };

        struct ItemInstance : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ItemInstance,"{c02ac0c2-cee5-5342-aedc-8fb5736884a2}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string ItemId;
            AZStd::string ItemInstanceId;
            AZStd::string ItemClass;
            OptionalTime PurchaseDate;
            OptionalTime Expiration;
            OptionalInt32 RemainingUses;
            OptionalInt32 UsesIncrementedBy;
            AZStd::string Annotation;
            AZStd::string CatalogVersion;
            AZStd::string BundleParent;
            AZStd::string DisplayName;
            AZStd::string UnitCurrency;
            Uint32 UnitPrice;
            AZStd::vector<AZStd::string> BundleContents; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::unordered_map<AZStd::string, AZStd::string> CustomData;

            ItemInstance() :
                PlayFabBaseModel(),
                ItemId(),
                ItemInstanceId(),
                ItemClass(),
                PurchaseDate(),
                Expiration(),
                RemainingUses(),
                UsesIncrementedBy(),
                Annotation(),
                CatalogVersion(),
                BundleParent(),
                DisplayName(),
                UnitCurrency(),
                UnitPrice(0),
                BundleContents(),
                CustomData()
            {}

            ItemInstance(const ItemInstance& src) :
                PlayFabBaseModel(),
                ItemId(src.ItemId),
                ItemInstanceId(src.ItemInstanceId),
                ItemClass(src.ItemClass),
                PurchaseDate(src.PurchaseDate),
                Expiration(src.Expiration),
                RemainingUses(src.RemainingUses),
                UsesIncrementedBy(src.UsesIncrementedBy),
                Annotation(src.Annotation),
                CatalogVersion(src.CatalogVersion),
                BundleParent(src.BundleParent),
                DisplayName(src.DisplayName),
                UnitCurrency(src.UnitCurrency),
                UnitPrice(src.UnitPrice),
                BundleContents(src.BundleContents),
                CustomData(src.CustomData)
            {}

            ItemInstance(const rapidjson::Value& obj) : ItemInstance()
            {
                readFromValue(obj);
            }

            ~ItemInstance()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (ItemId.length() > 0) {
                    writer.String("ItemId");
                    writer.String(ItemId.c_str());
                }
                if (ItemInstanceId.length() > 0) {
                    writer.String("ItemInstanceId");
                    writer.String(ItemInstanceId.c_str());
                }
                if (ItemClass.length() > 0) {
                    writer.String("ItemClass");
                    writer.String(ItemClass.c_str());
                }
                if (PurchaseDate.notNull()) {
                    writer.String("PurchaseDate");
                    writeDatetime(PurchaseDate, writer);
                }
                if (Expiration.notNull()) {
                    writer.String("Expiration");
                    writeDatetime(Expiration, writer);
                }
                if (RemainingUses.notNull()) {
                    writer.String("RemainingUses");
                    writer.Int(RemainingUses);
                }
                if (UsesIncrementedBy.notNull()) {
                    writer.String("UsesIncrementedBy");
                    writer.Int(UsesIncrementedBy);
                }
                if (Annotation.length() > 0) {
                    writer.String("Annotation");
                    writer.String(Annotation.c_str());
                }
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                if (BundleParent.length() > 0) {
                    writer.String("BundleParent");
                    writer.String(BundleParent.c_str());
                }
                if (DisplayName.length() > 0) {
                    writer.String("DisplayName");
                    writer.String(DisplayName.c_str());
                }
                if (UnitCurrency.length() > 0) {
                    writer.String("UnitCurrency");
                    writer.String(UnitCurrency.c_str());
                }
                writer.String("UnitPrice");
                writer.Uint(UnitPrice);
                if (!BundleContents.empty()) {
                    writer.String("BundleContents");
                    writer.StartArray();
                    for (auto iter = BundleContents.begin(); iter != BundleContents.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!CustomData.empty()) {
                    writer.String("CustomData");
                    writer.StartObject();
                    for (auto iter = CustomData.begin(); iter != CustomData.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
                const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
                if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator ItemClass_member = obj.FindMember("ItemClass");
                if (ItemClass_member != obj.MemberEnd() && !ItemClass_member->value.IsNull()) ItemClass = ItemClass_member->value.GetString();
                const Value::ConstMemberIterator PurchaseDate_member = obj.FindMember("PurchaseDate");
                if (PurchaseDate_member != obj.MemberEnd() && !PurchaseDate_member->value.IsNull()) PurchaseDate = readDatetime(PurchaseDate_member->value);
                const Value::ConstMemberIterator Expiration_member = obj.FindMember("Expiration");
                if (Expiration_member != obj.MemberEnd() && !Expiration_member->value.IsNull()) Expiration = readDatetime(Expiration_member->value);
                const Value::ConstMemberIterator RemainingUses_member = obj.FindMember("RemainingUses");
                if (RemainingUses_member != obj.MemberEnd() && !RemainingUses_member->value.IsNull()) RemainingUses = RemainingUses_member->value.GetInt();
                const Value::ConstMemberIterator UsesIncrementedBy_member = obj.FindMember("UsesIncrementedBy");
                if (UsesIncrementedBy_member != obj.MemberEnd() && !UsesIncrementedBy_member->value.IsNull()) UsesIncrementedBy = UsesIncrementedBy_member->value.GetInt();
                const Value::ConstMemberIterator Annotation_member = obj.FindMember("Annotation");
                if (Annotation_member != obj.MemberEnd() && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator BundleParent_member = obj.FindMember("BundleParent");
                if (BundleParent_member != obj.MemberEnd() && !BundleParent_member->value.IsNull()) BundleParent = BundleParent_member->value.GetString();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator UnitCurrency_member = obj.FindMember("UnitCurrency");
                if (UnitCurrency_member != obj.MemberEnd() && !UnitCurrency_member->value.IsNull()) UnitCurrency = UnitCurrency_member->value.GetString();
                const Value::ConstMemberIterator UnitPrice_member = obj.FindMember("UnitPrice");
                if (UnitPrice_member != obj.MemberEnd() && !UnitPrice_member->value.IsNull()) UnitPrice = UnitPrice_member->value.GetUint();
                const Value::ConstMemberIterator BundleContents_member = obj.FindMember("BundleContents");
                if (BundleContents_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = BundleContents_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        BundleContents.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator CustomData_member = obj.FindMember("CustomData");
                if (CustomData_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = CustomData_member->value.MemberBegin(); iter != CustomData_member->value.MemberEnd(); ++iter) {
                        CustomData[iter->name.GetString()] = iter->value.GetString();
                    }
                }

                return true;
            }
        };

        struct CharacterInventory : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::CharacterInventory,"{edc9b8fe-b0a0-54a0-a65c-11c5180a61e7}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string CharacterId;
            AZStd::vector<ItemInstance> Inventory; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            CharacterInventory() :
                PlayFabBaseModel(),
                CharacterId(),
                Inventory()
            {}

            CharacterInventory(const CharacterInventory& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                Inventory(src.Inventory)
            {}

            CharacterInventory(const rapidjson::Value& obj) : CharacterInventory()
            {
                readFromValue(obj);
            }

            ~CharacterInventory()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                if (!Inventory.empty()) {
                    writer.String("Inventory");
                    writer.StartArray();
                    for (auto iter = Inventory.begin(); iter != Inventory.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator Inventory_member = obj.FindMember("Inventory");
                if (Inventory_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Inventory_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Inventory.push_back(ItemInstance(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct CharacterLeaderboardEntry : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::CharacterLeaderboardEntry,"{d3c942af-79eb-5708-b616-ccb0672d2393}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string PlayFabId;
            AZStd::string CharacterId;
            AZStd::string CharacterName;
            AZStd::string DisplayName;
            AZStd::string CharacterType;
            Int32 StatValue;
            Int32 Position;

            CharacterLeaderboardEntry() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                CharacterName(),
                DisplayName(),
                CharacterType(),
                StatValue(0),
                Position(0)
            {}

            CharacterLeaderboardEntry(const CharacterLeaderboardEntry& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                CharacterName(src.CharacterName),
                DisplayName(src.DisplayName),
                CharacterType(src.CharacterType),
                StatValue(src.StatValue),
                Position(src.Position)
            {}

            CharacterLeaderboardEntry(const rapidjson::Value& obj) : CharacterLeaderboardEntry()
            {
                readFromValue(obj);
            }

            ~CharacterLeaderboardEntry()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                if (CharacterName.length() > 0) {
                    writer.String("CharacterName");
                    writer.String(CharacterName.c_str());
                }
                if (DisplayName.length() > 0) {
                    writer.String("DisplayName");
                    writer.String(DisplayName.c_str());
                }
                if (CharacterType.length() > 0) {
                    writer.String("CharacterType");
                    writer.String(CharacterType.c_str());
                }
                writer.String("StatValue");
                writer.Int(StatValue);
                writer.String("Position");
                writer.Int(Position);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator CharacterName_member = obj.FindMember("CharacterName");
                if (CharacterName_member != obj.MemberEnd() && !CharacterName_member->value.IsNull()) CharacterName = CharacterName_member->value.GetString();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
                if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();
                const Value::ConstMemberIterator StatValue_member = obj.FindMember("StatValue");
                if (StatValue_member != obj.MemberEnd() && !StatValue_member->value.IsNull()) StatValue = StatValue_member->value.GetInt();
                const Value::ConstMemberIterator Position_member = obj.FindMember("Position");
                if (Position_member != obj.MemberEnd() && !Position_member->value.IsNull()) Position = Position_member->value.GetInt();

                return true;
            }
        };

        struct CharacterResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::CharacterResult,"{f997036d-3b1b-594b-9451-0c496066e375}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string CharacterId;
            AZStd::string CharacterName;
            AZStd::string CharacterType;

            CharacterResult() :
                PlayFabBaseModel(),
                CharacterId(),
                CharacterName(),
                CharacterType()
            {}

            CharacterResult(const CharacterResult& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CharacterName(src.CharacterName),
                CharacterType(src.CharacterType)
            {}

            CharacterResult(const rapidjson::Value& obj) : CharacterResult()
            {
                readFromValue(obj);
            }

            ~CharacterResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                if (CharacterName.length() > 0) {
                    writer.String("CharacterName");
                    writer.String(CharacterName.c_str());
                }
                if (CharacterType.length() > 0) {
                    writer.String("CharacterType");
                    writer.String(CharacterType.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator CharacterName_member = obj.FindMember("CharacterName");
                if (CharacterName_member != obj.MemberEnd() && !CharacterName_member->value.IsNull()) CharacterName = CharacterName_member->value.GetString();
                const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
                if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();

                return true;
            }
        };

        enum CloudScriptRevisionOption
        {
            CloudScriptRevisionOptionLive,
            CloudScriptRevisionOptionLatest,
            CloudScriptRevisionOptionSpecific
        };

        inline void writeCloudScriptRevisionOptionEnumJSON(CloudScriptRevisionOption enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case CloudScriptRevisionOptionLive: writer.String("Live"); break;
            case CloudScriptRevisionOptionLatest: writer.String("Latest"); break;
            case CloudScriptRevisionOptionSpecific: writer.String("Specific"); break;

            }
        }

        inline CloudScriptRevisionOption readCloudScriptRevisionOptionFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<CloudScriptRevisionOption>(obj.GetInt());

            static std::map<const char *, CloudScriptRevisionOption, PlayFabComboSdk::StringCompare> _CloudScriptRevisionOptionMap;
            if (_CloudScriptRevisionOptionMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _CloudScriptRevisionOptionMap["Live"] = CloudScriptRevisionOptionLive;
                _CloudScriptRevisionOptionMap["Latest"] = CloudScriptRevisionOptionLatest;
                _CloudScriptRevisionOptionMap["Specific"] = CloudScriptRevisionOptionSpecific;

            }

            auto output = _CloudScriptRevisionOptionMap.find(obj.GetString());
            if (output != _CloudScriptRevisionOptionMap.end())
                return output->second;

            return CloudScriptRevisionOptionLive; // Basically critical fail
        }

        struct Container_Dictionary_String_String : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::Container_Dictionary_String_String,"{76c565bf-b938-57dc-acfe-8d8f028ec8fe}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::unordered_map<AZStd::string, AZStd::string> Data;

            Container_Dictionary_String_String() :
                PlayFabBaseModel(),
                Data()
            {}

            Container_Dictionary_String_String(const Container_Dictionary_String_String& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            Container_Dictionary_String_String(const rapidjson::Value& obj) : Container_Dictionary_String_String()
            {
                readFromValue(obj);
            }

            ~Container_Dictionary_String_String()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartObject();
                    for (auto iter = Data.begin(); iter != Data.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
                        Data[iter->name.GetString()] = iter->value.GetString();
                    }
                }

                return true;
            }
        };

        struct CollectionFilter : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::CollectionFilter,"{54f574b0-d059-5e15-84d6-fb7e5d7c1136}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<Container_Dictionary_String_String> Includes; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<Container_Dictionary_String_String> Excludes; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            CollectionFilter() :
                PlayFabBaseModel(),
                Includes(),
                Excludes()
            {}

            CollectionFilter(const CollectionFilter& src) :
                PlayFabBaseModel(),
                Includes(src.Includes),
                Excludes(src.Excludes)
            {}

            CollectionFilter(const rapidjson::Value& obj) : CollectionFilter()
            {
                readFromValue(obj);
            }

            ~CollectionFilter()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Includes.empty()) {
                    writer.String("Includes");
                    writer.StartArray();
                    for (auto iter = Includes.begin(); iter != Includes.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!Excludes.empty()) {
                    writer.String("Excludes");
                    writer.StartArray();
                    for (auto iter = Excludes.begin(); iter != Excludes.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Includes_member = obj.FindMember("Includes");
                if (Includes_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Includes_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Includes.push_back(Container_Dictionary_String_String(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator Excludes_member = obj.FindMember("Excludes");
                if (Excludes_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Excludes_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Excludes.push_back(Container_Dictionary_String_String(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct ConfirmPurchaseRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ConfirmPurchaseRequest,"{f2e51baf-b0f3-5521-83d1-7ee41ae087db}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string OrderId;

            ConfirmPurchaseRequest() :
                PlayFabBaseModel(),
                OrderId()
            {}

            ConfirmPurchaseRequest(const ConfirmPurchaseRequest& src) :
                PlayFabBaseModel(),
                OrderId(src.OrderId)
            {}

            ConfirmPurchaseRequest(const rapidjson::Value& obj) : ConfirmPurchaseRequest()
            {
                readFromValue(obj);
            }

            ~ConfirmPurchaseRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("OrderId");
                writer.String(OrderId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator OrderId_member = obj.FindMember("OrderId");
                if (OrderId_member != obj.MemberEnd() && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();

                return true;
            }
        };

        struct ConfirmPurchaseResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ConfirmPurchaseResult,"{ea43f138-aaf7-5225-8780-78f60e0fe638}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string OrderId;
            time_t PurchaseDate;
            AZStd::vector<ItemInstance> Items; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            ConfirmPurchaseResult() :
                PlayFabBaseModel(),
                OrderId(),
                PurchaseDate(0),
                Items()
            {}

            ConfirmPurchaseResult(const ConfirmPurchaseResult& src) :
                PlayFabBaseModel(),
                OrderId(src.OrderId),
                PurchaseDate(src.PurchaseDate),
                Items(src.Items)
            {}

            ConfirmPurchaseResult(const rapidjson::Value& obj) : ConfirmPurchaseResult()
            {
                readFromValue(obj);
            }

            ~ConfirmPurchaseResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (OrderId.length() > 0) {
                    writer.String("OrderId");
                    writer.String(OrderId.c_str());
                }
                writer.String("PurchaseDate");
                writeDatetime(PurchaseDate, writer);
                if (!Items.empty()) {
                    writer.String("Items");
                    writer.StartArray();
                    for (auto iter = Items.begin(); iter != Items.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator OrderId_member = obj.FindMember("OrderId");
                if (OrderId_member != obj.MemberEnd() && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();
                const Value::ConstMemberIterator PurchaseDate_member = obj.FindMember("PurchaseDate");
                if (PurchaseDate_member != obj.MemberEnd() && !PurchaseDate_member->value.IsNull()) PurchaseDate = readDatetime(PurchaseDate_member->value);
                const Value::ConstMemberIterator Items_member = obj.FindMember("Items");
                if (Items_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Items_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Items.push_back(ItemInstance(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct ConsumeItemRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ConsumeItemRequest,"{fb0fb160-695f-5cf3-a8a0-e49361a4d248}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string ItemInstanceId;
            Int32 ConsumeCount;
            AZStd::string CharacterId;

            ConsumeItemRequest() :
                PlayFabBaseModel(),
                ItemInstanceId(),
                ConsumeCount(0),
                CharacterId()
            {}

            ConsumeItemRequest(const ConsumeItemRequest& src) :
                PlayFabBaseModel(),
                ItemInstanceId(src.ItemInstanceId),
                ConsumeCount(src.ConsumeCount),
                CharacterId(src.CharacterId)
            {}

            ConsumeItemRequest(const rapidjson::Value& obj) : ConsumeItemRequest()
            {
                readFromValue(obj);
            }

            ~ConsumeItemRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ItemInstanceId");
                writer.String(ItemInstanceId.c_str());
                writer.String("ConsumeCount");
                writer.Int(ConsumeCount);
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
                if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator ConsumeCount_member = obj.FindMember("ConsumeCount");
                if (ConsumeCount_member != obj.MemberEnd() && !ConsumeCount_member->value.IsNull()) ConsumeCount = ConsumeCount_member->value.GetInt();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

                return true;
            }
        };

        struct ConsumeItemResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ConsumeItemResult,"{bd16e06f-0ed6-5936-841a-d3a1edfd97fd}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string ItemInstanceId;
            Int32 RemainingUses;

            ConsumeItemResult() :
                PlayFabBaseModel(),
                ItemInstanceId(),
                RemainingUses(0)
            {}

            ConsumeItemResult(const ConsumeItemResult& src) :
                PlayFabBaseModel(),
                ItemInstanceId(src.ItemInstanceId),
                RemainingUses(src.RemainingUses)
            {}

            ConsumeItemResult(const rapidjson::Value& obj) : ConsumeItemResult()
            {
                readFromValue(obj);
            }

            ~ConsumeItemResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (ItemInstanceId.length() > 0) {
                    writer.String("ItemInstanceId");
                    writer.String(ItemInstanceId.c_str());
                }
                writer.String("RemainingUses");
                writer.Int(RemainingUses);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
                if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator RemainingUses_member = obj.FindMember("RemainingUses");
                if (RemainingUses_member != obj.MemberEnd() && !RemainingUses_member->value.IsNull()) RemainingUses = RemainingUses_member->value.GetInt();

                return true;
            }
        };

        enum ContinentCode
        {
            ContinentCodeAF,
            ContinentCodeAN,
            ContinentCodeAS,
            ContinentCodeEU,
            ContinentCodeNA,
            ContinentCodeOC,
            ContinentCodeSA
        };

        inline void writeContinentCodeEnumJSON(ContinentCode enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case ContinentCodeAF: writer.String("AF"); break;
            case ContinentCodeAN: writer.String("AN"); break;
            case ContinentCodeAS: writer.String("AS"); break;
            case ContinentCodeEU: writer.String("EU"); break;
            case ContinentCodeNA: writer.String("NA"); break;
            case ContinentCodeOC: writer.String("OC"); break;
            case ContinentCodeSA: writer.String("SA"); break;

            }
        }

        inline ContinentCode readContinentCodeFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<ContinentCode>(obj.GetInt());

            static std::map<const char *, ContinentCode, PlayFabComboSdk::StringCompare> _ContinentCodeMap;
            if (_ContinentCodeMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _ContinentCodeMap["AF"] = ContinentCodeAF;
                _ContinentCodeMap["AN"] = ContinentCodeAN;
                _ContinentCodeMap["AS"] = ContinentCodeAS;
                _ContinentCodeMap["EU"] = ContinentCodeEU;
                _ContinentCodeMap["NA"] = ContinentCodeNA;
                _ContinentCodeMap["OC"] = ContinentCodeOC;
                _ContinentCodeMap["SA"] = ContinentCodeSA;

            }

            auto output = _ContinentCodeMap.find(obj.GetString());
            if (output != _ContinentCodeMap.end())
                return output->second;

            return ContinentCodeAF; // Basically critical fail
        }

        enum CountryCode
        {
            CountryCodeAF,
            CountryCodeAX,
            CountryCodeAL,
            CountryCodeDZ,
            CountryCodeAS,
            CountryCodeAD,
            CountryCodeAO,
            CountryCodeAI,
            CountryCodeAQ,
            CountryCodeAG,
            CountryCodeAR,
            CountryCodeAM,
            CountryCodeAW,
            CountryCodeAU,
            CountryCodeAT,
            CountryCodeAZ,
            CountryCodeBS,
            CountryCodeBH,
            CountryCodeBD,
            CountryCodeBB,
            CountryCodeBY,
            CountryCodeBE,
            CountryCodeBZ,
            CountryCodeBJ,
            CountryCodeBM,
            CountryCodeBT,
            CountryCodeBO,
            CountryCodeBQ,
            CountryCodeBA,
            CountryCodeBW,
            CountryCodeBV,
            CountryCodeBR,
            CountryCodeIO,
            CountryCodeBN,
            CountryCodeBG,
            CountryCodeBF,
            CountryCodeBI,
            CountryCodeKH,
            CountryCodeCM,
            CountryCodeCA,
            CountryCodeCV,
            CountryCodeKY,
            CountryCodeCF,
            CountryCodeTD,
            CountryCodeCL,
            CountryCodeCN,
            CountryCodeCX,
            CountryCodeCC,
            CountryCodeCO,
            CountryCodeKM,
            CountryCodeCG,
            CountryCodeCD,
            CountryCodeCK,
            CountryCodeCR,
            CountryCodeCI,
            CountryCodeHR,
            CountryCodeCU,
            CountryCodeCW,
            CountryCodeCY,
            CountryCodeCZ,
            CountryCodeDK,
            CountryCodeDJ,
            CountryCodeDM,
            CountryCodeDO,
            CountryCodeEC,
            CountryCodeEG,
            CountryCodeSV,
            CountryCodeGQ,
            CountryCodeER,
            CountryCodeEE,
            CountryCodeET,
            CountryCodeFK,
            CountryCodeFO,
            CountryCodeFJ,
            CountryCodeFI,
            CountryCodeFR,
            CountryCodeGF,
            CountryCodePF,
            CountryCodeTF,
            CountryCodeGA,
            CountryCodeGM,
            CountryCodeGE,
            CountryCodeDE,
            CountryCodeGH,
            CountryCodeGI,
            CountryCodeGR,
            CountryCodeGL,
            CountryCodeGD,
            CountryCodeGP,
            CountryCodeGU,
            CountryCodeGT,
            CountryCodeGG,
            CountryCodeGN,
            CountryCodeGW,
            CountryCodeGY,
            CountryCodeHT,
            CountryCodeHM,
            CountryCodeVA,
            CountryCodeHN,
            CountryCodeHK,
            CountryCodeHU,
            CountryCodeIS,
            CountryCodeIN,
            CountryCodeID,
            CountryCodeIR,
            CountryCodeIQ,
            CountryCodeIE,
            CountryCodeIM,
            CountryCodeIL,
            CountryCodeIT,
            CountryCodeJM,
            CountryCodeJP,
            CountryCodeJE,
            CountryCodeJO,
            CountryCodeKZ,
            CountryCodeKE,
            CountryCodeKI,
            CountryCodeKP,
            CountryCodeKR,
            CountryCodeKW,
            CountryCodeKG,
            CountryCodeLA,
            CountryCodeLV,
            CountryCodeLB,
            CountryCodeLS,
            CountryCodeLR,
            CountryCodeLY,
            CountryCodeLI,
            CountryCodeLT,
            CountryCodeLU,
            CountryCodeMO,
            CountryCodeMK,
            CountryCodeMG,
            CountryCodeMW,
            CountryCodeMY,
            CountryCodeMV,
            CountryCodeML,
            CountryCodeMT,
            CountryCodeMH,
            CountryCodeMQ,
            CountryCodeMR,
            CountryCodeMU,
            CountryCodeYT,
            CountryCodeMX,
            CountryCodeFM,
            CountryCodeMD,
            CountryCodeMC,
            CountryCodeMN,
            CountryCodeME,
            CountryCodeMS,
            CountryCodeMA,
            CountryCodeMZ,
            CountryCodeMM,
            CountryCodeNA,
            CountryCodeNR,
            CountryCodeNP,
            CountryCodeNL,
            CountryCodeNC,
            CountryCodeNZ,
            CountryCodeNI,
            CountryCodeNE,
            CountryCodeNG,
            CountryCodeNU,
            CountryCodeNF,
            CountryCodeMP,
            CountryCodeNO,
            CountryCodeOM,
            CountryCodePK,
            CountryCodePW,
            CountryCodePS,
            CountryCodePA,
            CountryCodePG,
            CountryCodePY,
            CountryCodePE,
            CountryCodePH,
            CountryCodePN,
            CountryCodePL,
            CountryCodePT,
            CountryCodePR,
            CountryCodeQA,
            CountryCodeRE,
            CountryCodeRO,
            CountryCodeRU,
            CountryCodeRW,
            CountryCodeBL,
            CountryCodeSH,
            CountryCodeKN,
            CountryCodeLC,
            CountryCodeMF,
            CountryCodePM,
            CountryCodeVC,
            CountryCodeWS,
            CountryCodeSM,
            CountryCodeST,
            CountryCodeSA,
            CountryCodeSN,
            CountryCodeRS,
            CountryCodeSC,
            CountryCodeSL,
            CountryCodeSG,
            CountryCodeSX,
            CountryCodeSK,
            CountryCodeSI,
            CountryCodeSB,
            CountryCodeSO,
            CountryCodeZA,
            CountryCodeGS,
            CountryCodeSS,
            CountryCodeES,
            CountryCodeLK,
            CountryCodeSD,
            CountryCodeSR,
            CountryCodeSJ,
            CountryCodeSZ,
            CountryCodeSE,
            CountryCodeCH,
            CountryCodeSY,
            CountryCodeTW,
            CountryCodeTJ,
            CountryCodeTZ,
            CountryCodeTH,
            CountryCodeTL,
            CountryCodeTG,
            CountryCodeTK,
            CountryCodeTO,
            CountryCodeTT,
            CountryCodeTN,
            CountryCodeTR,
            CountryCodeTM,
            CountryCodeTC,
            CountryCodeTV,
            CountryCodeUG,
            CountryCodeUA,
            CountryCodeAE,
            CountryCodeGB,
            CountryCodeUS,
            CountryCodeUM,
            CountryCodeUY,
            CountryCodeUZ,
            CountryCodeVU,
            CountryCodeVE,
            CountryCodeVN,
            CountryCodeVG,
            CountryCodeVI,
            CountryCodeWF,
            CountryCodeEH,
            CountryCodeYE,
            CountryCodeZM,
            CountryCodeZW
        };

        inline void writeCountryCodeEnumJSON(CountryCode enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case CountryCodeAF: writer.String("AF"); break;
            case CountryCodeAX: writer.String("AX"); break;
            case CountryCodeAL: writer.String("AL"); break;
            case CountryCodeDZ: writer.String("DZ"); break;
            case CountryCodeAS: writer.String("AS"); break;
            case CountryCodeAD: writer.String("AD"); break;
            case CountryCodeAO: writer.String("AO"); break;
            case CountryCodeAI: writer.String("AI"); break;
            case CountryCodeAQ: writer.String("AQ"); break;
            case CountryCodeAG: writer.String("AG"); break;
            case CountryCodeAR: writer.String("AR"); break;
            case CountryCodeAM: writer.String("AM"); break;
            case CountryCodeAW: writer.String("AW"); break;
            case CountryCodeAU: writer.String("AU"); break;
            case CountryCodeAT: writer.String("AT"); break;
            case CountryCodeAZ: writer.String("AZ"); break;
            case CountryCodeBS: writer.String("BS"); break;
            case CountryCodeBH: writer.String("BH"); break;
            case CountryCodeBD: writer.String("BD"); break;
            case CountryCodeBB: writer.String("BB"); break;
            case CountryCodeBY: writer.String("BY"); break;
            case CountryCodeBE: writer.String("BE"); break;
            case CountryCodeBZ: writer.String("BZ"); break;
            case CountryCodeBJ: writer.String("BJ"); break;
            case CountryCodeBM: writer.String("BM"); break;
            case CountryCodeBT: writer.String("BT"); break;
            case CountryCodeBO: writer.String("BO"); break;
            case CountryCodeBQ: writer.String("BQ"); break;
            case CountryCodeBA: writer.String("BA"); break;
            case CountryCodeBW: writer.String("BW"); break;
            case CountryCodeBV: writer.String("BV"); break;
            case CountryCodeBR: writer.String("BR"); break;
            case CountryCodeIO: writer.String("IO"); break;
            case CountryCodeBN: writer.String("BN"); break;
            case CountryCodeBG: writer.String("BG"); break;
            case CountryCodeBF: writer.String("BF"); break;
            case CountryCodeBI: writer.String("BI"); break;
            case CountryCodeKH: writer.String("KH"); break;
            case CountryCodeCM: writer.String("CM"); break;
            case CountryCodeCA: writer.String("CA"); break;
            case CountryCodeCV: writer.String("CV"); break;
            case CountryCodeKY: writer.String("KY"); break;
            case CountryCodeCF: writer.String("CF"); break;
            case CountryCodeTD: writer.String("TD"); break;
            case CountryCodeCL: writer.String("CL"); break;
            case CountryCodeCN: writer.String("CN"); break;
            case CountryCodeCX: writer.String("CX"); break;
            case CountryCodeCC: writer.String("CC"); break;
            case CountryCodeCO: writer.String("CO"); break;
            case CountryCodeKM: writer.String("KM"); break;
            case CountryCodeCG: writer.String("CG"); break;
            case CountryCodeCD: writer.String("CD"); break;
            case CountryCodeCK: writer.String("CK"); break;
            case CountryCodeCR: writer.String("CR"); break;
            case CountryCodeCI: writer.String("CI"); break;
            case CountryCodeHR: writer.String("HR"); break;
            case CountryCodeCU: writer.String("CU"); break;
            case CountryCodeCW: writer.String("CW"); break;
            case CountryCodeCY: writer.String("CY"); break;
            case CountryCodeCZ: writer.String("CZ"); break;
            case CountryCodeDK: writer.String("DK"); break;
            case CountryCodeDJ: writer.String("DJ"); break;
            case CountryCodeDM: writer.String("DM"); break;
            case CountryCodeDO: writer.String("DO"); break;
            case CountryCodeEC: writer.String("EC"); break;
            case CountryCodeEG: writer.String("EG"); break;
            case CountryCodeSV: writer.String("SV"); break;
            case CountryCodeGQ: writer.String("GQ"); break;
            case CountryCodeER: writer.String("ER"); break;
            case CountryCodeEE: writer.String("EE"); break;
            case CountryCodeET: writer.String("ET"); break;
            case CountryCodeFK: writer.String("FK"); break;
            case CountryCodeFO: writer.String("FO"); break;
            case CountryCodeFJ: writer.String("FJ"); break;
            case CountryCodeFI: writer.String("FI"); break;
            case CountryCodeFR: writer.String("FR"); break;
            case CountryCodeGF: writer.String("GF"); break;
            case CountryCodePF: writer.String("PF"); break;
            case CountryCodeTF: writer.String("TF"); break;
            case CountryCodeGA: writer.String("GA"); break;
            case CountryCodeGM: writer.String("GM"); break;
            case CountryCodeGE: writer.String("GE"); break;
            case CountryCodeDE: writer.String("DE"); break;
            case CountryCodeGH: writer.String("GH"); break;
            case CountryCodeGI: writer.String("GI"); break;
            case CountryCodeGR: writer.String("GR"); break;
            case CountryCodeGL: writer.String("GL"); break;
            case CountryCodeGD: writer.String("GD"); break;
            case CountryCodeGP: writer.String("GP"); break;
            case CountryCodeGU: writer.String("GU"); break;
            case CountryCodeGT: writer.String("GT"); break;
            case CountryCodeGG: writer.String("GG"); break;
            case CountryCodeGN: writer.String("GN"); break;
            case CountryCodeGW: writer.String("GW"); break;
            case CountryCodeGY: writer.String("GY"); break;
            case CountryCodeHT: writer.String("HT"); break;
            case CountryCodeHM: writer.String("HM"); break;
            case CountryCodeVA: writer.String("VA"); break;
            case CountryCodeHN: writer.String("HN"); break;
            case CountryCodeHK: writer.String("HK"); break;
            case CountryCodeHU: writer.String("HU"); break;
            case CountryCodeIS: writer.String("IS"); break;
            case CountryCodeIN: writer.String("IN"); break;
            case CountryCodeID: writer.String("ID"); break;
            case CountryCodeIR: writer.String("IR"); break;
            case CountryCodeIQ: writer.String("IQ"); break;
            case CountryCodeIE: writer.String("IE"); break;
            case CountryCodeIM: writer.String("IM"); break;
            case CountryCodeIL: writer.String("IL"); break;
            case CountryCodeIT: writer.String("IT"); break;
            case CountryCodeJM: writer.String("JM"); break;
            case CountryCodeJP: writer.String("JP"); break;
            case CountryCodeJE: writer.String("JE"); break;
            case CountryCodeJO: writer.String("JO"); break;
            case CountryCodeKZ: writer.String("KZ"); break;
            case CountryCodeKE: writer.String("KE"); break;
            case CountryCodeKI: writer.String("KI"); break;
            case CountryCodeKP: writer.String("KP"); break;
            case CountryCodeKR: writer.String("KR"); break;
            case CountryCodeKW: writer.String("KW"); break;
            case CountryCodeKG: writer.String("KG"); break;
            case CountryCodeLA: writer.String("LA"); break;
            case CountryCodeLV: writer.String("LV"); break;
            case CountryCodeLB: writer.String("LB"); break;
            case CountryCodeLS: writer.String("LS"); break;
            case CountryCodeLR: writer.String("LR"); break;
            case CountryCodeLY: writer.String("LY"); break;
            case CountryCodeLI: writer.String("LI"); break;
            case CountryCodeLT: writer.String("LT"); break;
            case CountryCodeLU: writer.String("LU"); break;
            case CountryCodeMO: writer.String("MO"); break;
            case CountryCodeMK: writer.String("MK"); break;
            case CountryCodeMG: writer.String("MG"); break;
            case CountryCodeMW: writer.String("MW"); break;
            case CountryCodeMY: writer.String("MY"); break;
            case CountryCodeMV: writer.String("MV"); break;
            case CountryCodeML: writer.String("ML"); break;
            case CountryCodeMT: writer.String("MT"); break;
            case CountryCodeMH: writer.String("MH"); break;
            case CountryCodeMQ: writer.String("MQ"); break;
            case CountryCodeMR: writer.String("MR"); break;
            case CountryCodeMU: writer.String("MU"); break;
            case CountryCodeYT: writer.String("YT"); break;
            case CountryCodeMX: writer.String("MX"); break;
            case CountryCodeFM: writer.String("FM"); break;
            case CountryCodeMD: writer.String("MD"); break;
            case CountryCodeMC: writer.String("MC"); break;
            case CountryCodeMN: writer.String("MN"); break;
            case CountryCodeME: writer.String("ME"); break;
            case CountryCodeMS: writer.String("MS"); break;
            case CountryCodeMA: writer.String("MA"); break;
            case CountryCodeMZ: writer.String("MZ"); break;
            case CountryCodeMM: writer.String("MM"); break;
            case CountryCodeNA: writer.String("NA"); break;
            case CountryCodeNR: writer.String("NR"); break;
            case CountryCodeNP: writer.String("NP"); break;
            case CountryCodeNL: writer.String("NL"); break;
            case CountryCodeNC: writer.String("NC"); break;
            case CountryCodeNZ: writer.String("NZ"); break;
            case CountryCodeNI: writer.String("NI"); break;
            case CountryCodeNE: writer.String("NE"); break;
            case CountryCodeNG: writer.String("NG"); break;
            case CountryCodeNU: writer.String("NU"); break;
            case CountryCodeNF: writer.String("NF"); break;
            case CountryCodeMP: writer.String("MP"); break;
            case CountryCodeNO: writer.String("NO"); break;
            case CountryCodeOM: writer.String("OM"); break;
            case CountryCodePK: writer.String("PK"); break;
            case CountryCodePW: writer.String("PW"); break;
            case CountryCodePS: writer.String("PS"); break;
            case CountryCodePA: writer.String("PA"); break;
            case CountryCodePG: writer.String("PG"); break;
            case CountryCodePY: writer.String("PY"); break;
            case CountryCodePE: writer.String("PE"); break;
            case CountryCodePH: writer.String("PH"); break;
            case CountryCodePN: writer.String("PN"); break;
            case CountryCodePL: writer.String("PL"); break;
            case CountryCodePT: writer.String("PT"); break;
            case CountryCodePR: writer.String("PR"); break;
            case CountryCodeQA: writer.String("QA"); break;
            case CountryCodeRE: writer.String("RE"); break;
            case CountryCodeRO: writer.String("RO"); break;
            case CountryCodeRU: writer.String("RU"); break;
            case CountryCodeRW: writer.String("RW"); break;
            case CountryCodeBL: writer.String("BL"); break;
            case CountryCodeSH: writer.String("SH"); break;
            case CountryCodeKN: writer.String("KN"); break;
            case CountryCodeLC: writer.String("LC"); break;
            case CountryCodeMF: writer.String("MF"); break;
            case CountryCodePM: writer.String("PM"); break;
            case CountryCodeVC: writer.String("VC"); break;
            case CountryCodeWS: writer.String("WS"); break;
            case CountryCodeSM: writer.String("SM"); break;
            case CountryCodeST: writer.String("ST"); break;
            case CountryCodeSA: writer.String("SA"); break;
            case CountryCodeSN: writer.String("SN"); break;
            case CountryCodeRS: writer.String("RS"); break;
            case CountryCodeSC: writer.String("SC"); break;
            case CountryCodeSL: writer.String("SL"); break;
            case CountryCodeSG: writer.String("SG"); break;
            case CountryCodeSX: writer.String("SX"); break;
            case CountryCodeSK: writer.String("SK"); break;
            case CountryCodeSI: writer.String("SI"); break;
            case CountryCodeSB: writer.String("SB"); break;
            case CountryCodeSO: writer.String("SO"); break;
            case CountryCodeZA: writer.String("ZA"); break;
            case CountryCodeGS: writer.String("GS"); break;
            case CountryCodeSS: writer.String("SS"); break;
            case CountryCodeES: writer.String("ES"); break;
            case CountryCodeLK: writer.String("LK"); break;
            case CountryCodeSD: writer.String("SD"); break;
            case CountryCodeSR: writer.String("SR"); break;
            case CountryCodeSJ: writer.String("SJ"); break;
            case CountryCodeSZ: writer.String("SZ"); break;
            case CountryCodeSE: writer.String("SE"); break;
            case CountryCodeCH: writer.String("CH"); break;
            case CountryCodeSY: writer.String("SY"); break;
            case CountryCodeTW: writer.String("TW"); break;
            case CountryCodeTJ: writer.String("TJ"); break;
            case CountryCodeTZ: writer.String("TZ"); break;
            case CountryCodeTH: writer.String("TH"); break;
            case CountryCodeTL: writer.String("TL"); break;
            case CountryCodeTG: writer.String("TG"); break;
            case CountryCodeTK: writer.String("TK"); break;
            case CountryCodeTO: writer.String("TO"); break;
            case CountryCodeTT: writer.String("TT"); break;
            case CountryCodeTN: writer.String("TN"); break;
            case CountryCodeTR: writer.String("TR"); break;
            case CountryCodeTM: writer.String("TM"); break;
            case CountryCodeTC: writer.String("TC"); break;
            case CountryCodeTV: writer.String("TV"); break;
            case CountryCodeUG: writer.String("UG"); break;
            case CountryCodeUA: writer.String("UA"); break;
            case CountryCodeAE: writer.String("AE"); break;
            case CountryCodeGB: writer.String("GB"); break;
            case CountryCodeUS: writer.String("US"); break;
            case CountryCodeUM: writer.String("UM"); break;
            case CountryCodeUY: writer.String("UY"); break;
            case CountryCodeUZ: writer.String("UZ"); break;
            case CountryCodeVU: writer.String("VU"); break;
            case CountryCodeVE: writer.String("VE"); break;
            case CountryCodeVN: writer.String("VN"); break;
            case CountryCodeVG: writer.String("VG"); break;
            case CountryCodeVI: writer.String("VI"); break;
            case CountryCodeWF: writer.String("WF"); break;
            case CountryCodeEH: writer.String("EH"); break;
            case CountryCodeYE: writer.String("YE"); break;
            case CountryCodeZM: writer.String("ZM"); break;
            case CountryCodeZW: writer.String("ZW"); break;

            }
        }

        inline CountryCode readCountryCodeFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<CountryCode>(obj.GetInt());

            static std::map<const char *, CountryCode, PlayFabComboSdk::StringCompare> _CountryCodeMap;
            if (_CountryCodeMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _CountryCodeMap["AF"] = CountryCodeAF;
                _CountryCodeMap["AX"] = CountryCodeAX;
                _CountryCodeMap["AL"] = CountryCodeAL;
                _CountryCodeMap["DZ"] = CountryCodeDZ;
                _CountryCodeMap["AS"] = CountryCodeAS;
                _CountryCodeMap["AD"] = CountryCodeAD;
                _CountryCodeMap["AO"] = CountryCodeAO;
                _CountryCodeMap["AI"] = CountryCodeAI;
                _CountryCodeMap["AQ"] = CountryCodeAQ;
                _CountryCodeMap["AG"] = CountryCodeAG;
                _CountryCodeMap["AR"] = CountryCodeAR;
                _CountryCodeMap["AM"] = CountryCodeAM;
                _CountryCodeMap["AW"] = CountryCodeAW;
                _CountryCodeMap["AU"] = CountryCodeAU;
                _CountryCodeMap["AT"] = CountryCodeAT;
                _CountryCodeMap["AZ"] = CountryCodeAZ;
                _CountryCodeMap["BS"] = CountryCodeBS;
                _CountryCodeMap["BH"] = CountryCodeBH;
                _CountryCodeMap["BD"] = CountryCodeBD;
                _CountryCodeMap["BB"] = CountryCodeBB;
                _CountryCodeMap["BY"] = CountryCodeBY;
                _CountryCodeMap["BE"] = CountryCodeBE;
                _CountryCodeMap["BZ"] = CountryCodeBZ;
                _CountryCodeMap["BJ"] = CountryCodeBJ;
                _CountryCodeMap["BM"] = CountryCodeBM;
                _CountryCodeMap["BT"] = CountryCodeBT;
                _CountryCodeMap["BO"] = CountryCodeBO;
                _CountryCodeMap["BQ"] = CountryCodeBQ;
                _CountryCodeMap["BA"] = CountryCodeBA;
                _CountryCodeMap["BW"] = CountryCodeBW;
                _CountryCodeMap["BV"] = CountryCodeBV;
                _CountryCodeMap["BR"] = CountryCodeBR;
                _CountryCodeMap["IO"] = CountryCodeIO;
                _CountryCodeMap["BN"] = CountryCodeBN;
                _CountryCodeMap["BG"] = CountryCodeBG;
                _CountryCodeMap["BF"] = CountryCodeBF;
                _CountryCodeMap["BI"] = CountryCodeBI;
                _CountryCodeMap["KH"] = CountryCodeKH;
                _CountryCodeMap["CM"] = CountryCodeCM;
                _CountryCodeMap["CA"] = CountryCodeCA;
                _CountryCodeMap["CV"] = CountryCodeCV;
                _CountryCodeMap["KY"] = CountryCodeKY;
                _CountryCodeMap["CF"] = CountryCodeCF;
                _CountryCodeMap["TD"] = CountryCodeTD;
                _CountryCodeMap["CL"] = CountryCodeCL;
                _CountryCodeMap["CN"] = CountryCodeCN;
                _CountryCodeMap["CX"] = CountryCodeCX;
                _CountryCodeMap["CC"] = CountryCodeCC;
                _CountryCodeMap["CO"] = CountryCodeCO;
                _CountryCodeMap["KM"] = CountryCodeKM;
                _CountryCodeMap["CG"] = CountryCodeCG;
                _CountryCodeMap["CD"] = CountryCodeCD;
                _CountryCodeMap["CK"] = CountryCodeCK;
                _CountryCodeMap["CR"] = CountryCodeCR;
                _CountryCodeMap["CI"] = CountryCodeCI;
                _CountryCodeMap["HR"] = CountryCodeHR;
                _CountryCodeMap["CU"] = CountryCodeCU;
                _CountryCodeMap["CW"] = CountryCodeCW;
                _CountryCodeMap["CY"] = CountryCodeCY;
                _CountryCodeMap["CZ"] = CountryCodeCZ;
                _CountryCodeMap["DK"] = CountryCodeDK;
                _CountryCodeMap["DJ"] = CountryCodeDJ;
                _CountryCodeMap["DM"] = CountryCodeDM;
                _CountryCodeMap["DO"] = CountryCodeDO;
                _CountryCodeMap["EC"] = CountryCodeEC;
                _CountryCodeMap["EG"] = CountryCodeEG;
                _CountryCodeMap["SV"] = CountryCodeSV;
                _CountryCodeMap["GQ"] = CountryCodeGQ;
                _CountryCodeMap["ER"] = CountryCodeER;
                _CountryCodeMap["EE"] = CountryCodeEE;
                _CountryCodeMap["ET"] = CountryCodeET;
                _CountryCodeMap["FK"] = CountryCodeFK;
                _CountryCodeMap["FO"] = CountryCodeFO;
                _CountryCodeMap["FJ"] = CountryCodeFJ;
                _CountryCodeMap["FI"] = CountryCodeFI;
                _CountryCodeMap["FR"] = CountryCodeFR;
                _CountryCodeMap["GF"] = CountryCodeGF;
                _CountryCodeMap["PF"] = CountryCodePF;
                _CountryCodeMap["TF"] = CountryCodeTF;
                _CountryCodeMap["GA"] = CountryCodeGA;
                _CountryCodeMap["GM"] = CountryCodeGM;
                _CountryCodeMap["GE"] = CountryCodeGE;
                _CountryCodeMap["DE"] = CountryCodeDE;
                _CountryCodeMap["GH"] = CountryCodeGH;
                _CountryCodeMap["GI"] = CountryCodeGI;
                _CountryCodeMap["GR"] = CountryCodeGR;
                _CountryCodeMap["GL"] = CountryCodeGL;
                _CountryCodeMap["GD"] = CountryCodeGD;
                _CountryCodeMap["GP"] = CountryCodeGP;
                _CountryCodeMap["GU"] = CountryCodeGU;
                _CountryCodeMap["GT"] = CountryCodeGT;
                _CountryCodeMap["GG"] = CountryCodeGG;
                _CountryCodeMap["GN"] = CountryCodeGN;
                _CountryCodeMap["GW"] = CountryCodeGW;
                _CountryCodeMap["GY"] = CountryCodeGY;
                _CountryCodeMap["HT"] = CountryCodeHT;
                _CountryCodeMap["HM"] = CountryCodeHM;
                _CountryCodeMap["VA"] = CountryCodeVA;
                _CountryCodeMap["HN"] = CountryCodeHN;
                _CountryCodeMap["HK"] = CountryCodeHK;
                _CountryCodeMap["HU"] = CountryCodeHU;
                _CountryCodeMap["IS"] = CountryCodeIS;
                _CountryCodeMap["IN"] = CountryCodeIN;
                _CountryCodeMap["ID"] = CountryCodeID;
                _CountryCodeMap["IR"] = CountryCodeIR;
                _CountryCodeMap["IQ"] = CountryCodeIQ;
                _CountryCodeMap["IE"] = CountryCodeIE;
                _CountryCodeMap["IM"] = CountryCodeIM;
                _CountryCodeMap["IL"] = CountryCodeIL;
                _CountryCodeMap["IT"] = CountryCodeIT;
                _CountryCodeMap["JM"] = CountryCodeJM;
                _CountryCodeMap["JP"] = CountryCodeJP;
                _CountryCodeMap["JE"] = CountryCodeJE;
                _CountryCodeMap["JO"] = CountryCodeJO;
                _CountryCodeMap["KZ"] = CountryCodeKZ;
                _CountryCodeMap["KE"] = CountryCodeKE;
                _CountryCodeMap["KI"] = CountryCodeKI;
                _CountryCodeMap["KP"] = CountryCodeKP;
                _CountryCodeMap["KR"] = CountryCodeKR;
                _CountryCodeMap["KW"] = CountryCodeKW;
                _CountryCodeMap["KG"] = CountryCodeKG;
                _CountryCodeMap["LA"] = CountryCodeLA;
                _CountryCodeMap["LV"] = CountryCodeLV;
                _CountryCodeMap["LB"] = CountryCodeLB;
                _CountryCodeMap["LS"] = CountryCodeLS;
                _CountryCodeMap["LR"] = CountryCodeLR;
                _CountryCodeMap["LY"] = CountryCodeLY;
                _CountryCodeMap["LI"] = CountryCodeLI;
                _CountryCodeMap["LT"] = CountryCodeLT;
                _CountryCodeMap["LU"] = CountryCodeLU;
                _CountryCodeMap["MO"] = CountryCodeMO;
                _CountryCodeMap["MK"] = CountryCodeMK;
                _CountryCodeMap["MG"] = CountryCodeMG;
                _CountryCodeMap["MW"] = CountryCodeMW;
                _CountryCodeMap["MY"] = CountryCodeMY;
                _CountryCodeMap["MV"] = CountryCodeMV;
                _CountryCodeMap["ML"] = CountryCodeML;
                _CountryCodeMap["MT"] = CountryCodeMT;
                _CountryCodeMap["MH"] = CountryCodeMH;
                _CountryCodeMap["MQ"] = CountryCodeMQ;
                _CountryCodeMap["MR"] = CountryCodeMR;
                _CountryCodeMap["MU"] = CountryCodeMU;
                _CountryCodeMap["YT"] = CountryCodeYT;
                _CountryCodeMap["MX"] = CountryCodeMX;
                _CountryCodeMap["FM"] = CountryCodeFM;
                _CountryCodeMap["MD"] = CountryCodeMD;
                _CountryCodeMap["MC"] = CountryCodeMC;
                _CountryCodeMap["MN"] = CountryCodeMN;
                _CountryCodeMap["ME"] = CountryCodeME;
                _CountryCodeMap["MS"] = CountryCodeMS;
                _CountryCodeMap["MA"] = CountryCodeMA;
                _CountryCodeMap["MZ"] = CountryCodeMZ;
                _CountryCodeMap["MM"] = CountryCodeMM;
                _CountryCodeMap["NA"] = CountryCodeNA;
                _CountryCodeMap["NR"] = CountryCodeNR;
                _CountryCodeMap["NP"] = CountryCodeNP;
                _CountryCodeMap["NL"] = CountryCodeNL;
                _CountryCodeMap["NC"] = CountryCodeNC;
                _CountryCodeMap["NZ"] = CountryCodeNZ;
                _CountryCodeMap["NI"] = CountryCodeNI;
                _CountryCodeMap["NE"] = CountryCodeNE;
                _CountryCodeMap["NG"] = CountryCodeNG;
                _CountryCodeMap["NU"] = CountryCodeNU;
                _CountryCodeMap["NF"] = CountryCodeNF;
                _CountryCodeMap["MP"] = CountryCodeMP;
                _CountryCodeMap["NO"] = CountryCodeNO;
                _CountryCodeMap["OM"] = CountryCodeOM;
                _CountryCodeMap["PK"] = CountryCodePK;
                _CountryCodeMap["PW"] = CountryCodePW;
                _CountryCodeMap["PS"] = CountryCodePS;
                _CountryCodeMap["PA"] = CountryCodePA;
                _CountryCodeMap["PG"] = CountryCodePG;
                _CountryCodeMap["PY"] = CountryCodePY;
                _CountryCodeMap["PE"] = CountryCodePE;
                _CountryCodeMap["PH"] = CountryCodePH;
                _CountryCodeMap["PN"] = CountryCodePN;
                _CountryCodeMap["PL"] = CountryCodePL;
                _CountryCodeMap["PT"] = CountryCodePT;
                _CountryCodeMap["PR"] = CountryCodePR;
                _CountryCodeMap["QA"] = CountryCodeQA;
                _CountryCodeMap["RE"] = CountryCodeRE;
                _CountryCodeMap["RO"] = CountryCodeRO;
                _CountryCodeMap["RU"] = CountryCodeRU;
                _CountryCodeMap["RW"] = CountryCodeRW;
                _CountryCodeMap["BL"] = CountryCodeBL;
                _CountryCodeMap["SH"] = CountryCodeSH;
                _CountryCodeMap["KN"] = CountryCodeKN;
                _CountryCodeMap["LC"] = CountryCodeLC;
                _CountryCodeMap["MF"] = CountryCodeMF;
                _CountryCodeMap["PM"] = CountryCodePM;
                _CountryCodeMap["VC"] = CountryCodeVC;
                _CountryCodeMap["WS"] = CountryCodeWS;
                _CountryCodeMap["SM"] = CountryCodeSM;
                _CountryCodeMap["ST"] = CountryCodeST;
                _CountryCodeMap["SA"] = CountryCodeSA;
                _CountryCodeMap["SN"] = CountryCodeSN;
                _CountryCodeMap["RS"] = CountryCodeRS;
                _CountryCodeMap["SC"] = CountryCodeSC;
                _CountryCodeMap["SL"] = CountryCodeSL;
                _CountryCodeMap["SG"] = CountryCodeSG;
                _CountryCodeMap["SX"] = CountryCodeSX;
                _CountryCodeMap["SK"] = CountryCodeSK;
                _CountryCodeMap["SI"] = CountryCodeSI;
                _CountryCodeMap["SB"] = CountryCodeSB;
                _CountryCodeMap["SO"] = CountryCodeSO;
                _CountryCodeMap["ZA"] = CountryCodeZA;
                _CountryCodeMap["GS"] = CountryCodeGS;
                _CountryCodeMap["SS"] = CountryCodeSS;
                _CountryCodeMap["ES"] = CountryCodeES;
                _CountryCodeMap["LK"] = CountryCodeLK;
                _CountryCodeMap["SD"] = CountryCodeSD;
                _CountryCodeMap["SR"] = CountryCodeSR;
                _CountryCodeMap["SJ"] = CountryCodeSJ;
                _CountryCodeMap["SZ"] = CountryCodeSZ;
                _CountryCodeMap["SE"] = CountryCodeSE;
                _CountryCodeMap["CH"] = CountryCodeCH;
                _CountryCodeMap["SY"] = CountryCodeSY;
                _CountryCodeMap["TW"] = CountryCodeTW;
                _CountryCodeMap["TJ"] = CountryCodeTJ;
                _CountryCodeMap["TZ"] = CountryCodeTZ;
                _CountryCodeMap["TH"] = CountryCodeTH;
                _CountryCodeMap["TL"] = CountryCodeTL;
                _CountryCodeMap["TG"] = CountryCodeTG;
                _CountryCodeMap["TK"] = CountryCodeTK;
                _CountryCodeMap["TO"] = CountryCodeTO;
                _CountryCodeMap["TT"] = CountryCodeTT;
                _CountryCodeMap["TN"] = CountryCodeTN;
                _CountryCodeMap["TR"] = CountryCodeTR;
                _CountryCodeMap["TM"] = CountryCodeTM;
                _CountryCodeMap["TC"] = CountryCodeTC;
                _CountryCodeMap["TV"] = CountryCodeTV;
                _CountryCodeMap["UG"] = CountryCodeUG;
                _CountryCodeMap["UA"] = CountryCodeUA;
                _CountryCodeMap["AE"] = CountryCodeAE;
                _CountryCodeMap["GB"] = CountryCodeGB;
                _CountryCodeMap["US"] = CountryCodeUS;
                _CountryCodeMap["UM"] = CountryCodeUM;
                _CountryCodeMap["UY"] = CountryCodeUY;
                _CountryCodeMap["UZ"] = CountryCodeUZ;
                _CountryCodeMap["VU"] = CountryCodeVU;
                _CountryCodeMap["VE"] = CountryCodeVE;
                _CountryCodeMap["VN"] = CountryCodeVN;
                _CountryCodeMap["VG"] = CountryCodeVG;
                _CountryCodeMap["VI"] = CountryCodeVI;
                _CountryCodeMap["WF"] = CountryCodeWF;
                _CountryCodeMap["EH"] = CountryCodeEH;
                _CountryCodeMap["YE"] = CountryCodeYE;
                _CountryCodeMap["ZM"] = CountryCodeZM;
                _CountryCodeMap["ZW"] = CountryCodeZW;

            }

            auto output = _CountryCodeMap.find(obj.GetString());
            if (output != _CountryCodeMap.end())
                return output->second;

            return CountryCodeAF; // Basically critical fail
        }

        struct CreateSharedGroupRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::CreateSharedGroupRequest,"{b63de806-fc0f-5583-b702-b7f7f4814ab2}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string SharedGroupId;

            CreateSharedGroupRequest() :
                PlayFabBaseModel(),
                SharedGroupId()
            {}

            CreateSharedGroupRequest(const CreateSharedGroupRequest& src) :
                PlayFabBaseModel(),
                SharedGroupId(src.SharedGroupId)
            {}

            CreateSharedGroupRequest(const rapidjson::Value& obj) : CreateSharedGroupRequest()
            {
                readFromValue(obj);
            }

            ~CreateSharedGroupRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (SharedGroupId.length() > 0) {
                    writer.String("SharedGroupId");
                    writer.String(SharedGroupId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
                if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();

                return true;
            }
        };

        struct CreateSharedGroupResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::CreateSharedGroupResult,"{529277af-eedf-535a-bdf8-ac2492a31c61}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string SharedGroupId;

            CreateSharedGroupResult() :
                PlayFabBaseModel(),
                SharedGroupId()
            {}

            CreateSharedGroupResult(const CreateSharedGroupResult& src) :
                PlayFabBaseModel(),
                SharedGroupId(src.SharedGroupId)
            {}

            CreateSharedGroupResult(const rapidjson::Value& obj) : CreateSharedGroupResult()
            {
                readFromValue(obj);
            }

            ~CreateSharedGroupResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (SharedGroupId.length() > 0) {
                    writer.String("SharedGroupId");
                    writer.String(SharedGroupId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
                if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();

                return true;
            }
        };

        enum Currency
        {
            CurrencyAED,
            CurrencyAFN,
            CurrencyALL,
            CurrencyAMD,
            CurrencyANG,
            CurrencyAOA,
            CurrencyARS,
            CurrencyAUD,
            CurrencyAWG,
            CurrencyAZN,
            CurrencyBAM,
            CurrencyBBD,
            CurrencyBDT,
            CurrencyBGN,
            CurrencyBHD,
            CurrencyBIF,
            CurrencyBMD,
            CurrencyBND,
            CurrencyBOB,
            CurrencyBRL,
            CurrencyBSD,
            CurrencyBTN,
            CurrencyBWP,
            CurrencyBYR,
            CurrencyBZD,
            CurrencyCAD,
            CurrencyCDF,
            CurrencyCHF,
            CurrencyCLP,
            CurrencyCNY,
            CurrencyCOP,
            CurrencyCRC,
            CurrencyCUC,
            CurrencyCUP,
            CurrencyCVE,
            CurrencyCZK,
            CurrencyDJF,
            CurrencyDKK,
            CurrencyDOP,
            CurrencyDZD,
            CurrencyEGP,
            CurrencyERN,
            CurrencyETB,
            CurrencyEUR,
            CurrencyFJD,
            CurrencyFKP,
            CurrencyGBP,
            CurrencyGEL,
            CurrencyGGP,
            CurrencyGHS,
            CurrencyGIP,
            CurrencyGMD,
            CurrencyGNF,
            CurrencyGTQ,
            CurrencyGYD,
            CurrencyHKD,
            CurrencyHNL,
            CurrencyHRK,
            CurrencyHTG,
            CurrencyHUF,
            CurrencyIDR,
            CurrencyILS,
            CurrencyIMP,
            CurrencyINR,
            CurrencyIQD,
            CurrencyIRR,
            CurrencyISK,
            CurrencyJEP,
            CurrencyJMD,
            CurrencyJOD,
            CurrencyJPY,
            CurrencyKES,
            CurrencyKGS,
            CurrencyKHR,
            CurrencyKMF,
            CurrencyKPW,
            CurrencyKRW,
            CurrencyKWD,
            CurrencyKYD,
            CurrencyKZT,
            CurrencyLAK,
            CurrencyLBP,
            CurrencyLKR,
            CurrencyLRD,
            CurrencyLSL,
            CurrencyLYD,
            CurrencyMAD,
            CurrencyMDL,
            CurrencyMGA,
            CurrencyMKD,
            CurrencyMMK,
            CurrencyMNT,
            CurrencyMOP,
            CurrencyMRO,
            CurrencyMUR,
            CurrencyMVR,
            CurrencyMWK,
            CurrencyMXN,
            CurrencyMYR,
            CurrencyMZN,
            CurrencyNAD,
            CurrencyNGN,
            CurrencyNIO,
            CurrencyNOK,
            CurrencyNPR,
            CurrencyNZD,
            CurrencyOMR,
            CurrencyPAB,
            CurrencyPEN,
            CurrencyPGK,
            CurrencyPHP,
            CurrencyPKR,
            CurrencyPLN,
            CurrencyPYG,
            CurrencyQAR,
            CurrencyRON,
            CurrencyRSD,
            CurrencyRUB,
            CurrencyRWF,
            CurrencySAR,
            CurrencySBD,
            CurrencySCR,
            CurrencySDG,
            CurrencySEK,
            CurrencySGD,
            CurrencySHP,
            CurrencySLL,
            CurrencySOS,
            CurrencySPL,
            CurrencySRD,
            CurrencySTD,
            CurrencySVC,
            CurrencySYP,
            CurrencySZL,
            CurrencyTHB,
            CurrencyTJS,
            CurrencyTMT,
            CurrencyTND,
            CurrencyTOP,
            CurrencyTRY,
            CurrencyTTD,
            CurrencyTVD,
            CurrencyTWD,
            CurrencyTZS,
            CurrencyUAH,
            CurrencyUGX,
            CurrencyUSD,
            CurrencyUYU,
            CurrencyUZS,
            CurrencyVEF,
            CurrencyVND,
            CurrencyVUV,
            CurrencyWST,
            CurrencyXAF,
            CurrencyXCD,
            CurrencyXDR,
            CurrencyXOF,
            CurrencyXPF,
            CurrencyYER,
            CurrencyZAR,
            CurrencyZMW,
            CurrencyZWD
        };

        inline void writeCurrencyEnumJSON(Currency enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case CurrencyAED: writer.String("AED"); break;
            case CurrencyAFN: writer.String("AFN"); break;
            case CurrencyALL: writer.String("ALL"); break;
            case CurrencyAMD: writer.String("AMD"); break;
            case CurrencyANG: writer.String("ANG"); break;
            case CurrencyAOA: writer.String("AOA"); break;
            case CurrencyARS: writer.String("ARS"); break;
            case CurrencyAUD: writer.String("AUD"); break;
            case CurrencyAWG: writer.String("AWG"); break;
            case CurrencyAZN: writer.String("AZN"); break;
            case CurrencyBAM: writer.String("BAM"); break;
            case CurrencyBBD: writer.String("BBD"); break;
            case CurrencyBDT: writer.String("BDT"); break;
            case CurrencyBGN: writer.String("BGN"); break;
            case CurrencyBHD: writer.String("BHD"); break;
            case CurrencyBIF: writer.String("BIF"); break;
            case CurrencyBMD: writer.String("BMD"); break;
            case CurrencyBND: writer.String("BND"); break;
            case CurrencyBOB: writer.String("BOB"); break;
            case CurrencyBRL: writer.String("BRL"); break;
            case CurrencyBSD: writer.String("BSD"); break;
            case CurrencyBTN: writer.String("BTN"); break;
            case CurrencyBWP: writer.String("BWP"); break;
            case CurrencyBYR: writer.String("BYR"); break;
            case CurrencyBZD: writer.String("BZD"); break;
            case CurrencyCAD: writer.String("CAD"); break;
            case CurrencyCDF: writer.String("CDF"); break;
            case CurrencyCHF: writer.String("CHF"); break;
            case CurrencyCLP: writer.String("CLP"); break;
            case CurrencyCNY: writer.String("CNY"); break;
            case CurrencyCOP: writer.String("COP"); break;
            case CurrencyCRC: writer.String("CRC"); break;
            case CurrencyCUC: writer.String("CUC"); break;
            case CurrencyCUP: writer.String("CUP"); break;
            case CurrencyCVE: writer.String("CVE"); break;
            case CurrencyCZK: writer.String("CZK"); break;
            case CurrencyDJF: writer.String("DJF"); break;
            case CurrencyDKK: writer.String("DKK"); break;
            case CurrencyDOP: writer.String("DOP"); break;
            case CurrencyDZD: writer.String("DZD"); break;
            case CurrencyEGP: writer.String("EGP"); break;
            case CurrencyERN: writer.String("ERN"); break;
            case CurrencyETB: writer.String("ETB"); break;
            case CurrencyEUR: writer.String("EUR"); break;
            case CurrencyFJD: writer.String("FJD"); break;
            case CurrencyFKP: writer.String("FKP"); break;
            case CurrencyGBP: writer.String("GBP"); break;
            case CurrencyGEL: writer.String("GEL"); break;
            case CurrencyGGP: writer.String("GGP"); break;
            case CurrencyGHS: writer.String("GHS"); break;
            case CurrencyGIP: writer.String("GIP"); break;
            case CurrencyGMD: writer.String("GMD"); break;
            case CurrencyGNF: writer.String("GNF"); break;
            case CurrencyGTQ: writer.String("GTQ"); break;
            case CurrencyGYD: writer.String("GYD"); break;
            case CurrencyHKD: writer.String("HKD"); break;
            case CurrencyHNL: writer.String("HNL"); break;
            case CurrencyHRK: writer.String("HRK"); break;
            case CurrencyHTG: writer.String("HTG"); break;
            case CurrencyHUF: writer.String("HUF"); break;
            case CurrencyIDR: writer.String("IDR"); break;
            case CurrencyILS: writer.String("ILS"); break;
            case CurrencyIMP: writer.String("IMP"); break;
            case CurrencyINR: writer.String("INR"); break;
            case CurrencyIQD: writer.String("IQD"); break;
            case CurrencyIRR: writer.String("IRR"); break;
            case CurrencyISK: writer.String("ISK"); break;
            case CurrencyJEP: writer.String("JEP"); break;
            case CurrencyJMD: writer.String("JMD"); break;
            case CurrencyJOD: writer.String("JOD"); break;
            case CurrencyJPY: writer.String("JPY"); break;
            case CurrencyKES: writer.String("KES"); break;
            case CurrencyKGS: writer.String("KGS"); break;
            case CurrencyKHR: writer.String("KHR"); break;
            case CurrencyKMF: writer.String("KMF"); break;
            case CurrencyKPW: writer.String("KPW"); break;
            case CurrencyKRW: writer.String("KRW"); break;
            case CurrencyKWD: writer.String("KWD"); break;
            case CurrencyKYD: writer.String("KYD"); break;
            case CurrencyKZT: writer.String("KZT"); break;
            case CurrencyLAK: writer.String("LAK"); break;
            case CurrencyLBP: writer.String("LBP"); break;
            case CurrencyLKR: writer.String("LKR"); break;
            case CurrencyLRD: writer.String("LRD"); break;
            case CurrencyLSL: writer.String("LSL"); break;
            case CurrencyLYD: writer.String("LYD"); break;
            case CurrencyMAD: writer.String("MAD"); break;
            case CurrencyMDL: writer.String("MDL"); break;
            case CurrencyMGA: writer.String("MGA"); break;
            case CurrencyMKD: writer.String("MKD"); break;
            case CurrencyMMK: writer.String("MMK"); break;
            case CurrencyMNT: writer.String("MNT"); break;
            case CurrencyMOP: writer.String("MOP"); break;
            case CurrencyMRO: writer.String("MRO"); break;
            case CurrencyMUR: writer.String("MUR"); break;
            case CurrencyMVR: writer.String("MVR"); break;
            case CurrencyMWK: writer.String("MWK"); break;
            case CurrencyMXN: writer.String("MXN"); break;
            case CurrencyMYR: writer.String("MYR"); break;
            case CurrencyMZN: writer.String("MZN"); break;
            case CurrencyNAD: writer.String("NAD"); break;
            case CurrencyNGN: writer.String("NGN"); break;
            case CurrencyNIO: writer.String("NIO"); break;
            case CurrencyNOK: writer.String("NOK"); break;
            case CurrencyNPR: writer.String("NPR"); break;
            case CurrencyNZD: writer.String("NZD"); break;
            case CurrencyOMR: writer.String("OMR"); break;
            case CurrencyPAB: writer.String("PAB"); break;
            case CurrencyPEN: writer.String("PEN"); break;
            case CurrencyPGK: writer.String("PGK"); break;
            case CurrencyPHP: writer.String("PHP"); break;
            case CurrencyPKR: writer.String("PKR"); break;
            case CurrencyPLN: writer.String("PLN"); break;
            case CurrencyPYG: writer.String("PYG"); break;
            case CurrencyQAR: writer.String("QAR"); break;
            case CurrencyRON: writer.String("RON"); break;
            case CurrencyRSD: writer.String("RSD"); break;
            case CurrencyRUB: writer.String("RUB"); break;
            case CurrencyRWF: writer.String("RWF"); break;
            case CurrencySAR: writer.String("SAR"); break;
            case CurrencySBD: writer.String("SBD"); break;
            case CurrencySCR: writer.String("SCR"); break;
            case CurrencySDG: writer.String("SDG"); break;
            case CurrencySEK: writer.String("SEK"); break;
            case CurrencySGD: writer.String("SGD"); break;
            case CurrencySHP: writer.String("SHP"); break;
            case CurrencySLL: writer.String("SLL"); break;
            case CurrencySOS: writer.String("SOS"); break;
            case CurrencySPL: writer.String("SPL"); break;
            case CurrencySRD: writer.String("SRD"); break;
            case CurrencySTD: writer.String("STD"); break;
            case CurrencySVC: writer.String("SVC"); break;
            case CurrencySYP: writer.String("SYP"); break;
            case CurrencySZL: writer.String("SZL"); break;
            case CurrencyTHB: writer.String("THB"); break;
            case CurrencyTJS: writer.String("TJS"); break;
            case CurrencyTMT: writer.String("TMT"); break;
            case CurrencyTND: writer.String("TND"); break;
            case CurrencyTOP: writer.String("TOP"); break;
            case CurrencyTRY: writer.String("TRY"); break;
            case CurrencyTTD: writer.String("TTD"); break;
            case CurrencyTVD: writer.String("TVD"); break;
            case CurrencyTWD: writer.String("TWD"); break;
            case CurrencyTZS: writer.String("TZS"); break;
            case CurrencyUAH: writer.String("UAH"); break;
            case CurrencyUGX: writer.String("UGX"); break;
            case CurrencyUSD: writer.String("USD"); break;
            case CurrencyUYU: writer.String("UYU"); break;
            case CurrencyUZS: writer.String("UZS"); break;
            case CurrencyVEF: writer.String("VEF"); break;
            case CurrencyVND: writer.String("VND"); break;
            case CurrencyVUV: writer.String("VUV"); break;
            case CurrencyWST: writer.String("WST"); break;
            case CurrencyXAF: writer.String("XAF"); break;
            case CurrencyXCD: writer.String("XCD"); break;
            case CurrencyXDR: writer.String("XDR"); break;
            case CurrencyXOF: writer.String("XOF"); break;
            case CurrencyXPF: writer.String("XPF"); break;
            case CurrencyYER: writer.String("YER"); break;
            case CurrencyZAR: writer.String("ZAR"); break;
            case CurrencyZMW: writer.String("ZMW"); break;
            case CurrencyZWD: writer.String("ZWD"); break;

            }
        }

        inline Currency readCurrencyFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<Currency>(obj.GetInt());

            static std::map<const char *, Currency, PlayFabComboSdk::StringCompare> _CurrencyMap;
            if (_CurrencyMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _CurrencyMap["AED"] = CurrencyAED;
                _CurrencyMap["AFN"] = CurrencyAFN;
                _CurrencyMap["ALL"] = CurrencyALL;
                _CurrencyMap["AMD"] = CurrencyAMD;
                _CurrencyMap["ANG"] = CurrencyANG;
                _CurrencyMap["AOA"] = CurrencyAOA;
                _CurrencyMap["ARS"] = CurrencyARS;
                _CurrencyMap["AUD"] = CurrencyAUD;
                _CurrencyMap["AWG"] = CurrencyAWG;
                _CurrencyMap["AZN"] = CurrencyAZN;
                _CurrencyMap["BAM"] = CurrencyBAM;
                _CurrencyMap["BBD"] = CurrencyBBD;
                _CurrencyMap["BDT"] = CurrencyBDT;
                _CurrencyMap["BGN"] = CurrencyBGN;
                _CurrencyMap["BHD"] = CurrencyBHD;
                _CurrencyMap["BIF"] = CurrencyBIF;
                _CurrencyMap["BMD"] = CurrencyBMD;
                _CurrencyMap["BND"] = CurrencyBND;
                _CurrencyMap["BOB"] = CurrencyBOB;
                _CurrencyMap["BRL"] = CurrencyBRL;
                _CurrencyMap["BSD"] = CurrencyBSD;
                _CurrencyMap["BTN"] = CurrencyBTN;
                _CurrencyMap["BWP"] = CurrencyBWP;
                _CurrencyMap["BYR"] = CurrencyBYR;
                _CurrencyMap["BZD"] = CurrencyBZD;
                _CurrencyMap["CAD"] = CurrencyCAD;
                _CurrencyMap["CDF"] = CurrencyCDF;
                _CurrencyMap["CHF"] = CurrencyCHF;
                _CurrencyMap["CLP"] = CurrencyCLP;
                _CurrencyMap["CNY"] = CurrencyCNY;
                _CurrencyMap["COP"] = CurrencyCOP;
                _CurrencyMap["CRC"] = CurrencyCRC;
                _CurrencyMap["CUC"] = CurrencyCUC;
                _CurrencyMap["CUP"] = CurrencyCUP;
                _CurrencyMap["CVE"] = CurrencyCVE;
                _CurrencyMap["CZK"] = CurrencyCZK;
                _CurrencyMap["DJF"] = CurrencyDJF;
                _CurrencyMap["DKK"] = CurrencyDKK;
                _CurrencyMap["DOP"] = CurrencyDOP;
                _CurrencyMap["DZD"] = CurrencyDZD;
                _CurrencyMap["EGP"] = CurrencyEGP;
                _CurrencyMap["ERN"] = CurrencyERN;
                _CurrencyMap["ETB"] = CurrencyETB;
                _CurrencyMap["EUR"] = CurrencyEUR;
                _CurrencyMap["FJD"] = CurrencyFJD;
                _CurrencyMap["FKP"] = CurrencyFKP;
                _CurrencyMap["GBP"] = CurrencyGBP;
                _CurrencyMap["GEL"] = CurrencyGEL;
                _CurrencyMap["GGP"] = CurrencyGGP;
                _CurrencyMap["GHS"] = CurrencyGHS;
                _CurrencyMap["GIP"] = CurrencyGIP;
                _CurrencyMap["GMD"] = CurrencyGMD;
                _CurrencyMap["GNF"] = CurrencyGNF;
                _CurrencyMap["GTQ"] = CurrencyGTQ;
                _CurrencyMap["GYD"] = CurrencyGYD;
                _CurrencyMap["HKD"] = CurrencyHKD;
                _CurrencyMap["HNL"] = CurrencyHNL;
                _CurrencyMap["HRK"] = CurrencyHRK;
                _CurrencyMap["HTG"] = CurrencyHTG;
                _CurrencyMap["HUF"] = CurrencyHUF;
                _CurrencyMap["IDR"] = CurrencyIDR;
                _CurrencyMap["ILS"] = CurrencyILS;
                _CurrencyMap["IMP"] = CurrencyIMP;
                _CurrencyMap["INR"] = CurrencyINR;
                _CurrencyMap["IQD"] = CurrencyIQD;
                _CurrencyMap["IRR"] = CurrencyIRR;
                _CurrencyMap["ISK"] = CurrencyISK;
                _CurrencyMap["JEP"] = CurrencyJEP;
                _CurrencyMap["JMD"] = CurrencyJMD;
                _CurrencyMap["JOD"] = CurrencyJOD;
                _CurrencyMap["JPY"] = CurrencyJPY;
                _CurrencyMap["KES"] = CurrencyKES;
                _CurrencyMap["KGS"] = CurrencyKGS;
                _CurrencyMap["KHR"] = CurrencyKHR;
                _CurrencyMap["KMF"] = CurrencyKMF;
                _CurrencyMap["KPW"] = CurrencyKPW;
                _CurrencyMap["KRW"] = CurrencyKRW;
                _CurrencyMap["KWD"] = CurrencyKWD;
                _CurrencyMap["KYD"] = CurrencyKYD;
                _CurrencyMap["KZT"] = CurrencyKZT;
                _CurrencyMap["LAK"] = CurrencyLAK;
                _CurrencyMap["LBP"] = CurrencyLBP;
                _CurrencyMap["LKR"] = CurrencyLKR;
                _CurrencyMap["LRD"] = CurrencyLRD;
                _CurrencyMap["LSL"] = CurrencyLSL;
                _CurrencyMap["LYD"] = CurrencyLYD;
                _CurrencyMap["MAD"] = CurrencyMAD;
                _CurrencyMap["MDL"] = CurrencyMDL;
                _CurrencyMap["MGA"] = CurrencyMGA;
                _CurrencyMap["MKD"] = CurrencyMKD;
                _CurrencyMap["MMK"] = CurrencyMMK;
                _CurrencyMap["MNT"] = CurrencyMNT;
                _CurrencyMap["MOP"] = CurrencyMOP;
                _CurrencyMap["MRO"] = CurrencyMRO;
                _CurrencyMap["MUR"] = CurrencyMUR;
                _CurrencyMap["MVR"] = CurrencyMVR;
                _CurrencyMap["MWK"] = CurrencyMWK;
                _CurrencyMap["MXN"] = CurrencyMXN;
                _CurrencyMap["MYR"] = CurrencyMYR;
                _CurrencyMap["MZN"] = CurrencyMZN;
                _CurrencyMap["NAD"] = CurrencyNAD;
                _CurrencyMap["NGN"] = CurrencyNGN;
                _CurrencyMap["NIO"] = CurrencyNIO;
                _CurrencyMap["NOK"] = CurrencyNOK;
                _CurrencyMap["NPR"] = CurrencyNPR;
                _CurrencyMap["NZD"] = CurrencyNZD;
                _CurrencyMap["OMR"] = CurrencyOMR;
                _CurrencyMap["PAB"] = CurrencyPAB;
                _CurrencyMap["PEN"] = CurrencyPEN;
                _CurrencyMap["PGK"] = CurrencyPGK;
                _CurrencyMap["PHP"] = CurrencyPHP;
                _CurrencyMap["PKR"] = CurrencyPKR;
                _CurrencyMap["PLN"] = CurrencyPLN;
                _CurrencyMap["PYG"] = CurrencyPYG;
                _CurrencyMap["QAR"] = CurrencyQAR;
                _CurrencyMap["RON"] = CurrencyRON;
                _CurrencyMap["RSD"] = CurrencyRSD;
                _CurrencyMap["RUB"] = CurrencyRUB;
                _CurrencyMap["RWF"] = CurrencyRWF;
                _CurrencyMap["SAR"] = CurrencySAR;
                _CurrencyMap["SBD"] = CurrencySBD;
                _CurrencyMap["SCR"] = CurrencySCR;
                _CurrencyMap["SDG"] = CurrencySDG;
                _CurrencyMap["SEK"] = CurrencySEK;
                _CurrencyMap["SGD"] = CurrencySGD;
                _CurrencyMap["SHP"] = CurrencySHP;
                _CurrencyMap["SLL"] = CurrencySLL;
                _CurrencyMap["SOS"] = CurrencySOS;
                _CurrencyMap["SPL"] = CurrencySPL;
                _CurrencyMap["SRD"] = CurrencySRD;
                _CurrencyMap["STD"] = CurrencySTD;
                _CurrencyMap["SVC"] = CurrencySVC;
                _CurrencyMap["SYP"] = CurrencySYP;
                _CurrencyMap["SZL"] = CurrencySZL;
                _CurrencyMap["THB"] = CurrencyTHB;
                _CurrencyMap["TJS"] = CurrencyTJS;
                _CurrencyMap["TMT"] = CurrencyTMT;
                _CurrencyMap["TND"] = CurrencyTND;
                _CurrencyMap["TOP"] = CurrencyTOP;
                _CurrencyMap["TRY"] = CurrencyTRY;
                _CurrencyMap["TTD"] = CurrencyTTD;
                _CurrencyMap["TVD"] = CurrencyTVD;
                _CurrencyMap["TWD"] = CurrencyTWD;
                _CurrencyMap["TZS"] = CurrencyTZS;
                _CurrencyMap["UAH"] = CurrencyUAH;
                _CurrencyMap["UGX"] = CurrencyUGX;
                _CurrencyMap["USD"] = CurrencyUSD;
                _CurrencyMap["UYU"] = CurrencyUYU;
                _CurrencyMap["UZS"] = CurrencyUZS;
                _CurrencyMap["VEF"] = CurrencyVEF;
                _CurrencyMap["VND"] = CurrencyVND;
                _CurrencyMap["VUV"] = CurrencyVUV;
                _CurrencyMap["WST"] = CurrencyWST;
                _CurrencyMap["XAF"] = CurrencyXAF;
                _CurrencyMap["XCD"] = CurrencyXCD;
                _CurrencyMap["XDR"] = CurrencyXDR;
                _CurrencyMap["XOF"] = CurrencyXOF;
                _CurrencyMap["XPF"] = CurrencyXPF;
                _CurrencyMap["YER"] = CurrencyYER;
                _CurrencyMap["ZAR"] = CurrencyZAR;
                _CurrencyMap["ZMW"] = CurrencyZMW;
                _CurrencyMap["ZWD"] = CurrencyZWD;

            }

            auto output = _CurrencyMap.find(obj.GetString());
            if (output != _CurrencyMap.end())
                return output->second;

            return CurrencyAED; // Basically critical fail
        }

        enum Region
        {
            RegionUSCentral,
            RegionUSEast,
            RegionEUWest,
            RegionSingapore,
            RegionJapan,
            RegionBrazil,
            RegionAustralia
        };

        inline void writeRegionEnumJSON(Region enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case RegionUSCentral: writer.String("USCentral"); break;
            case RegionUSEast: writer.String("USEast"); break;
            case RegionEUWest: writer.String("EUWest"); break;
            case RegionSingapore: writer.String("Singapore"); break;
            case RegionJapan: writer.String("Japan"); break;
            case RegionBrazil: writer.String("Brazil"); break;
            case RegionAustralia: writer.String("Australia"); break;

            }
        }

        inline Region readRegionFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<Region>(obj.GetInt());

            static std::map<const char *, Region, PlayFabComboSdk::StringCompare> _RegionMap;
            if (_RegionMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _RegionMap["USCentral"] = RegionUSCentral;
                _RegionMap["USEast"] = RegionUSEast;
                _RegionMap["EUWest"] = RegionEUWest;
                _RegionMap["Singapore"] = RegionSingapore;
                _RegionMap["Japan"] = RegionJapan;
                _RegionMap["Brazil"] = RegionBrazil;
                _RegionMap["Australia"] = RegionAustralia;

            }

            auto output = _RegionMap.find(obj.GetString());
            if (output != _RegionMap.end())
                return output->second;

            return RegionUSCentral; // Basically critical fail
        }

        struct CurrentGamesRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::CurrentGamesRequest,"{efdacd69-8fbb-586c-a8a1-febca38c2efb}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            Boxed<Region> pfRegion;
            AZStd::string BuildVersion;
            AZStd::string GameMode;
            AZStd::string StatisticName;
            CollectionFilter* TagFilter;

            CurrentGamesRequest() :
                PlayFabBaseModel(),
                pfRegion(),
                BuildVersion(),
                GameMode(),
                StatisticName(),
                TagFilter(nullptr)
            {}

            CurrentGamesRequest(const CurrentGamesRequest& src) :
                PlayFabBaseModel(),
                pfRegion(src.pfRegion),
                BuildVersion(src.BuildVersion),
                GameMode(src.GameMode),
                StatisticName(src.StatisticName),
                TagFilter(src.TagFilter ? new CollectionFilter(*src.TagFilter) : nullptr)
            {}

            CurrentGamesRequest(const rapidjson::Value& obj) : CurrentGamesRequest()
            {
                readFromValue(obj);
            }

            ~CurrentGamesRequest()
            {
                if (TagFilter != nullptr) delete TagFilter;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (pfRegion.notNull()) {
                    writer.String("Region");
                    writeRegionEnumJSON(pfRegion, writer);
                }
                if (BuildVersion.length() > 0) {
                    writer.String("BuildVersion");
                    writer.String(BuildVersion.c_str());
                }
                if (GameMode.length() > 0) {
                    writer.String("GameMode");
                    writer.String(GameMode.c_str());
                }
                if (StatisticName.length() > 0) {
                    writer.String("StatisticName");
                    writer.String(StatisticName.c_str());
                }
                if (TagFilter != nullptr) {
                    writer.String("TagFilter");
                    TagFilter->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
                if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);
                const Value::ConstMemberIterator BuildVersion_member = obj.FindMember("BuildVersion");
                if (BuildVersion_member != obj.MemberEnd() && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
                const Value::ConstMemberIterator GameMode_member = obj.FindMember("GameMode");
                if (GameMode_member != obj.MemberEnd() && !GameMode_member->value.IsNull()) GameMode = GameMode_member->value.GetString();
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator TagFilter_member = obj.FindMember("TagFilter");
                if (TagFilter_member != obj.MemberEnd() && !TagFilter_member->value.IsNull()) TagFilter = new CollectionFilter(TagFilter_member->value);

                return true;
            }
        };

        enum GameInstanceState
        {
            GameInstanceStateOpen,
            GameInstanceStateClosed
        };

        inline void writeGameInstanceStateEnumJSON(GameInstanceState enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case GameInstanceStateOpen: writer.String("Open"); break;
            case GameInstanceStateClosed: writer.String("Closed"); break;

            }
        }

        inline GameInstanceState readGameInstanceStateFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<GameInstanceState>(obj.GetInt());

            static std::map<const char *, GameInstanceState, PlayFabComboSdk::StringCompare> _GameInstanceStateMap;
            if (_GameInstanceStateMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _GameInstanceStateMap["Open"] = GameInstanceStateOpen;
                _GameInstanceStateMap["Closed"] = GameInstanceStateClosed;

            }

            auto output = _GameInstanceStateMap.find(obj.GetString());
            if (output != _GameInstanceStateMap.end())
                return output->second;

            return GameInstanceStateOpen; // Basically critical fail
        }

        struct GameInfo : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GameInfo,"{5eed111e-eb0d-50be-86e3-370c2a24e9cc}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            Boxed<Region> pfRegion;
            AZStd::string LobbyID;
            AZStd::string BuildVersion;
            AZStd::string GameMode;
            AZStd::string StatisticName;
            OptionalInt32 MaxPlayers;
            AZStd::vector<AZStd::string> PlayerUserIds; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            Uint32 RunTime;
            Boxed<GameInstanceState> GameServerState;
            AZStd::string GameServerData;
            AZStd::unordered_map<AZStd::string, AZStd::string> Tags;
            OptionalTime LastHeartbeat;
            AZStd::string ServerHostname;
            OptionalInt32 ServerPort;

            GameInfo() :
                PlayFabBaseModel(),
                pfRegion(),
                LobbyID(),
                BuildVersion(),
                GameMode(),
                StatisticName(),
                MaxPlayers(),
                PlayerUserIds(),
                RunTime(0),
                GameServerState(),
                GameServerData(),
                Tags(),
                LastHeartbeat(),
                ServerHostname(),
                ServerPort()
            {}

            GameInfo(const GameInfo& src) :
                PlayFabBaseModel(),
                pfRegion(src.pfRegion),
                LobbyID(src.LobbyID),
                BuildVersion(src.BuildVersion),
                GameMode(src.GameMode),
                StatisticName(src.StatisticName),
                MaxPlayers(src.MaxPlayers),
                PlayerUserIds(src.PlayerUserIds),
                RunTime(src.RunTime),
                GameServerState(src.GameServerState),
                GameServerData(src.GameServerData),
                Tags(src.Tags),
                LastHeartbeat(src.LastHeartbeat),
                ServerHostname(src.ServerHostname),
                ServerPort(src.ServerPort)
            {}

            GameInfo(const rapidjson::Value& obj) : GameInfo()
            {
                readFromValue(obj);
            }

            ~GameInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (pfRegion.notNull()) {
                    writer.String("Region");
                    writeRegionEnumJSON(pfRegion, writer);
                }
                if (LobbyID.length() > 0) {
                    writer.String("LobbyID");
                    writer.String(LobbyID.c_str());
                }
                if (BuildVersion.length() > 0) {
                    writer.String("BuildVersion");
                    writer.String(BuildVersion.c_str());
                }
                if (GameMode.length() > 0) {
                    writer.String("GameMode");
                    writer.String(GameMode.c_str());
                }
                if (StatisticName.length() > 0) {
                    writer.String("StatisticName");
                    writer.String(StatisticName.c_str());
                }
                if (MaxPlayers.notNull()) {
                    writer.String("MaxPlayers");
                    writer.Int(MaxPlayers);
                }
                if (!PlayerUserIds.empty()) {
                    writer.String("PlayerUserIds");
                    writer.StartArray();
                    for (auto iter = PlayerUserIds.begin(); iter != PlayerUserIds.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                writer.String("RunTime");
                writer.Uint(RunTime);
                if (GameServerState.notNull()) {
                    writer.String("GameServerState");
                    writeGameInstanceStateEnumJSON(GameServerState, writer);
                }
                if (GameServerData.length() > 0) {
                    writer.String("GameServerData");
                    writer.String(GameServerData.c_str());
                }
                if (!Tags.empty()) {
                    writer.String("Tags");
                    writer.StartObject();
                    for (auto iter = Tags.begin(); iter != Tags.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                if (LastHeartbeat.notNull()) {
                    writer.String("LastHeartbeat");
                    writeDatetime(LastHeartbeat, writer);
                }
                if (ServerHostname.length() > 0) {
                    writer.String("ServerHostname");
                    writer.String(ServerHostname.c_str());
                }
                if (ServerPort.notNull()) {
                    writer.String("ServerPort");
                    writer.Int(ServerPort);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
                if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);
                const Value::ConstMemberIterator LobbyID_member = obj.FindMember("LobbyID");
                if (LobbyID_member != obj.MemberEnd() && !LobbyID_member->value.IsNull()) LobbyID = LobbyID_member->value.GetString();
                const Value::ConstMemberIterator BuildVersion_member = obj.FindMember("BuildVersion");
                if (BuildVersion_member != obj.MemberEnd() && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
                const Value::ConstMemberIterator GameMode_member = obj.FindMember("GameMode");
                if (GameMode_member != obj.MemberEnd() && !GameMode_member->value.IsNull()) GameMode = GameMode_member->value.GetString();
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator MaxPlayers_member = obj.FindMember("MaxPlayers");
                if (MaxPlayers_member != obj.MemberEnd() && !MaxPlayers_member->value.IsNull()) MaxPlayers = MaxPlayers_member->value.GetInt();
                const Value::ConstMemberIterator PlayerUserIds_member = obj.FindMember("PlayerUserIds");
                if (PlayerUserIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = PlayerUserIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        PlayerUserIds.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator RunTime_member = obj.FindMember("RunTime");
                if (RunTime_member != obj.MemberEnd() && !RunTime_member->value.IsNull()) RunTime = RunTime_member->value.GetUint();
                const Value::ConstMemberIterator GameServerState_member = obj.FindMember("GameServerState");
                if (GameServerState_member != obj.MemberEnd() && !GameServerState_member->value.IsNull()) GameServerState = readGameInstanceStateFromValue(GameServerState_member->value);
                const Value::ConstMemberIterator GameServerData_member = obj.FindMember("GameServerData");
                if (GameServerData_member != obj.MemberEnd() && !GameServerData_member->value.IsNull()) GameServerData = GameServerData_member->value.GetString();
                const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
                if (Tags_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Tags_member->value.MemberBegin(); iter != Tags_member->value.MemberEnd(); ++iter) {
                        Tags[iter->name.GetString()] = iter->value.GetString();
                    }
                }
                const Value::ConstMemberIterator LastHeartbeat_member = obj.FindMember("LastHeartbeat");
                if (LastHeartbeat_member != obj.MemberEnd() && !LastHeartbeat_member->value.IsNull()) LastHeartbeat = readDatetime(LastHeartbeat_member->value);
                const Value::ConstMemberIterator ServerHostname_member = obj.FindMember("ServerHostname");
                if (ServerHostname_member != obj.MemberEnd() && !ServerHostname_member->value.IsNull()) ServerHostname = ServerHostname_member->value.GetString();
                const Value::ConstMemberIterator ServerPort_member = obj.FindMember("ServerPort");
                if (ServerPort_member != obj.MemberEnd() && !ServerPort_member->value.IsNull()) ServerPort = ServerPort_member->value.GetInt();

                return true;
            }
        };

        struct CurrentGamesResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::CurrentGamesResult,"{82e07dfc-41fe-56af-848c-43b91d026716}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<GameInfo> Games; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            Int32 PlayerCount;
            Int32 GameCount;

            CurrentGamesResult() :
                PlayFabBaseModel(),
                Games(),
                PlayerCount(0),
                GameCount(0)
            {}

            CurrentGamesResult(const CurrentGamesResult& src) :
                PlayFabBaseModel(),
                Games(src.Games),
                PlayerCount(src.PlayerCount),
                GameCount(src.GameCount)
            {}

            CurrentGamesResult(const rapidjson::Value& obj) : CurrentGamesResult()
            {
                readFromValue(obj);
            }

            ~CurrentGamesResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Games.empty()) {
                    writer.String("Games");
                    writer.StartArray();
                    for (auto iter = Games.begin(); iter != Games.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.String("PlayerCount");
                writer.Int(PlayerCount);
                writer.String("GameCount");
                writer.Int(GameCount);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Games_member = obj.FindMember("Games");
                if (Games_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Games_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Games.push_back(GameInfo(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator PlayerCount_member = obj.FindMember("PlayerCount");
                if (PlayerCount_member != obj.MemberEnd() && !PlayerCount_member->value.IsNull()) PlayerCount = PlayerCount_member->value.GetInt();
                const Value::ConstMemberIterator GameCount_member = obj.FindMember("GameCount");
                if (GameCount_member != obj.MemberEnd() && !GameCount_member->value.IsNull()) GameCount = GameCount_member->value.GetInt();

                return true;
            }
        };

        struct EmptyResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::EmptyResult,"{3c3ee503-e4ba-5a4d-80f2-bfd1b7852c4f}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            EmptyResult() :
                PlayFabBaseModel()
            {}

            EmptyResult(const EmptyResult& src) :
                PlayFabBaseModel()
            {}

            EmptyResult(const rapidjson::Value& obj) : EmptyResult()
            {
                readFromValue(obj);
            }

            ~EmptyResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct ExecuteCloudScriptRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ExecuteCloudScriptRequest,"{ea9383d5-aa8f-57a6-a12f-9542446555ba}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string FunctionName;
            MultitypeVar FunctionParameter;
            Boxed<CloudScriptRevisionOption> RevisionSelection;
            OptionalInt32 SpecificRevision;
            OptionalBool GeneratePlayStreamEvent;

            ExecuteCloudScriptRequest() :
                PlayFabBaseModel(),
                FunctionName(),
                FunctionParameter(),
                RevisionSelection(),
                SpecificRevision(),
                GeneratePlayStreamEvent()
            {}

            ExecuteCloudScriptRequest(const ExecuteCloudScriptRequest& src) :
                PlayFabBaseModel(),
                FunctionName(src.FunctionName),
                FunctionParameter(src.FunctionParameter),
                RevisionSelection(src.RevisionSelection),
                SpecificRevision(src.SpecificRevision),
                GeneratePlayStreamEvent(src.GeneratePlayStreamEvent)
            {}

            ExecuteCloudScriptRequest(const rapidjson::Value& obj) : ExecuteCloudScriptRequest()
            {
                readFromValue(obj);
            }

            ~ExecuteCloudScriptRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("FunctionName");
                writer.String(FunctionName.c_str());
                if (FunctionParameter.notNull()) {
                    writer.String("FunctionParameter");
                    FunctionParameter.writeJSON(writer);
                }
                if (RevisionSelection.notNull()) {
                    writer.String("RevisionSelection");
                    writeCloudScriptRevisionOptionEnumJSON(RevisionSelection, writer);
                }
                if (SpecificRevision.notNull()) {
                    writer.String("SpecificRevision");
                    writer.Int(SpecificRevision);
                }
                if (GeneratePlayStreamEvent.notNull()) {
                    writer.String("GeneratePlayStreamEvent");
                    writer.Bool(GeneratePlayStreamEvent);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FunctionName_member = obj.FindMember("FunctionName");
                if (FunctionName_member != obj.MemberEnd() && !FunctionName_member->value.IsNull()) FunctionName = FunctionName_member->value.GetString();
                const Value::ConstMemberIterator FunctionParameter_member = obj.FindMember("FunctionParameter");
                if (FunctionParameter_member != obj.MemberEnd() && !FunctionParameter_member->value.IsNull()) FunctionParameter = MultitypeVar(FunctionParameter_member->value);
                const Value::ConstMemberIterator RevisionSelection_member = obj.FindMember("RevisionSelection");
                if (RevisionSelection_member != obj.MemberEnd() && !RevisionSelection_member->value.IsNull()) RevisionSelection = readCloudScriptRevisionOptionFromValue(RevisionSelection_member->value);
                const Value::ConstMemberIterator SpecificRevision_member = obj.FindMember("SpecificRevision");
                if (SpecificRevision_member != obj.MemberEnd() && !SpecificRevision_member->value.IsNull()) SpecificRevision = SpecificRevision_member->value.GetInt();
                const Value::ConstMemberIterator GeneratePlayStreamEvent_member = obj.FindMember("GeneratePlayStreamEvent");
                if (GeneratePlayStreamEvent_member != obj.MemberEnd() && !GeneratePlayStreamEvent_member->value.IsNull()) GeneratePlayStreamEvent = GeneratePlayStreamEvent_member->value.GetBool();

                return true;
            }
        };

        struct LogStatement : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LogStatement,"{8a7b1ec5-001d-5b0f-8229-572558c03fe3}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string Level;
            AZStd::string Message;
            MultitypeVar Data;

            LogStatement() :
                PlayFabBaseModel(),
                Level(),
                Message(),
                Data()
            {}

            LogStatement(const LogStatement& src) :
                PlayFabBaseModel(),
                Level(src.Level),
                Message(src.Message),
                Data(src.Data)
            {}

            LogStatement(const rapidjson::Value& obj) : LogStatement()
            {
                readFromValue(obj);
            }

            ~LogStatement()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Level.length() > 0) {
                    writer.String("Level");
                    writer.String(Level.c_str());
                }
                if (Message.length() > 0) {
                    writer.String("Message");
                    writer.String(Message.c_str());
                }
                if (Data.notNull()) {
                    writer.String("Data");
                    Data.writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Level_member = obj.FindMember("Level");
                if (Level_member != obj.MemberEnd() && !Level_member->value.IsNull()) Level = Level_member->value.GetString();
                const Value::ConstMemberIterator Message_member = obj.FindMember("Message");
                if (Message_member != obj.MemberEnd() && !Message_member->value.IsNull()) Message = Message_member->value.GetString();
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd() && !Data_member->value.IsNull()) Data = MultitypeVar(Data_member->value);

                return true;
            }
        };

        struct ScriptExecutionError : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ScriptExecutionError,"{6bf1c0f3-2c3a-5d5d-b3a2-c73985670703}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string Error;
            AZStd::string Message;
            AZStd::string StackTrace;

            ScriptExecutionError() :
                PlayFabBaseModel(),
                Error(),
                Message(),
                StackTrace()
            {}

            ScriptExecutionError(const ScriptExecutionError& src) :
                PlayFabBaseModel(),
                Error(src.Error),
                Message(src.Message),
                StackTrace(src.StackTrace)
            {}

            ScriptExecutionError(const rapidjson::Value& obj) : ScriptExecutionError()
            {
                readFromValue(obj);
            }

            ~ScriptExecutionError()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Error.length() > 0) {
                    writer.String("Error");
                    writer.String(Error.c_str());
                }
                if (Message.length() > 0) {
                    writer.String("Message");
                    writer.String(Message.c_str());
                }
                if (StackTrace.length() > 0) {
                    writer.String("StackTrace");
                    writer.String(StackTrace.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Error_member = obj.FindMember("Error");
                if (Error_member != obj.MemberEnd() && !Error_member->value.IsNull()) Error = Error_member->value.GetString();
                const Value::ConstMemberIterator Message_member = obj.FindMember("Message");
                if (Message_member != obj.MemberEnd() && !Message_member->value.IsNull()) Message = Message_member->value.GetString();
                const Value::ConstMemberIterator StackTrace_member = obj.FindMember("StackTrace");
                if (StackTrace_member != obj.MemberEnd() && !StackTrace_member->value.IsNull()) StackTrace = StackTrace_member->value.GetString();

                return true;
            }
        };

        struct ExecuteCloudScriptResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ExecuteCloudScriptResult,"{37bbcd58-777b-52b3-9923-cc10fcf9eb4f}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string FunctionName;
            Int32 Revision;
            MultitypeVar FunctionResult;
            OptionalBool FunctionResultTooLarge;
            AZStd::vector<LogStatement> Logs; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            OptionalBool LogsTooLarge;
            double ExecutionTimeSeconds;
            double ProcessorTimeSeconds;
            Uint32 MemoryConsumedBytes;
            Int32 APIRequestsIssued;
            Int32 HttpRequestsIssued;
            ScriptExecutionError* Error;

            ExecuteCloudScriptResult() :
                PlayFabBaseModel(),
                FunctionName(),
                Revision(0),
                FunctionResult(),
                FunctionResultTooLarge(),
                Logs(),
                LogsTooLarge(),
                ExecutionTimeSeconds(0),
                ProcessorTimeSeconds(0),
                MemoryConsumedBytes(0),
                APIRequestsIssued(0),
                HttpRequestsIssued(0),
                Error(nullptr)
            {}

            ExecuteCloudScriptResult(const ExecuteCloudScriptResult& src) :
                PlayFabBaseModel(),
                FunctionName(src.FunctionName),
                Revision(src.Revision),
                FunctionResult(src.FunctionResult),
                FunctionResultTooLarge(src.FunctionResultTooLarge),
                Logs(src.Logs),
                LogsTooLarge(src.LogsTooLarge),
                ExecutionTimeSeconds(src.ExecutionTimeSeconds),
                ProcessorTimeSeconds(src.ProcessorTimeSeconds),
                MemoryConsumedBytes(src.MemoryConsumedBytes),
                APIRequestsIssued(src.APIRequestsIssued),
                HttpRequestsIssued(src.HttpRequestsIssued),
                Error(src.Error ? new ScriptExecutionError(*src.Error) : nullptr)
            {}

            ExecuteCloudScriptResult(const rapidjson::Value& obj) : ExecuteCloudScriptResult()
            {
                readFromValue(obj);
            }

            ~ExecuteCloudScriptResult()
            {
                if (Error != nullptr) delete Error;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (FunctionName.length() > 0) {
                    writer.String("FunctionName");
                    writer.String(FunctionName.c_str());
                }
                writer.String("Revision");
                writer.Int(Revision);
                if (FunctionResult.notNull()) {
                    writer.String("FunctionResult");
                    FunctionResult.writeJSON(writer);
                }
                if (FunctionResultTooLarge.notNull()) {
                    writer.String("FunctionResultTooLarge");
                    writer.Bool(FunctionResultTooLarge);
                }
                if (!Logs.empty()) {
                    writer.String("Logs");
                    writer.StartArray();
                    for (auto iter = Logs.begin(); iter != Logs.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (LogsTooLarge.notNull()) {
                    writer.String("LogsTooLarge");
                    writer.Bool(LogsTooLarge);
                }
                writer.String("ExecutionTimeSeconds");
                writer.Double(ExecutionTimeSeconds);
                writer.String("ProcessorTimeSeconds");
                writer.Double(ProcessorTimeSeconds);
                writer.String("MemoryConsumedBytes");
                writer.Uint(MemoryConsumedBytes);
                writer.String("APIRequestsIssued");
                writer.Int(APIRequestsIssued);
                writer.String("HttpRequestsIssued");
                writer.Int(HttpRequestsIssued);
                if (Error != nullptr) {
                    writer.String("Error");
                    Error->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FunctionName_member = obj.FindMember("FunctionName");
                if (FunctionName_member != obj.MemberEnd() && !FunctionName_member->value.IsNull()) FunctionName = FunctionName_member->value.GetString();
                const Value::ConstMemberIterator Revision_member = obj.FindMember("Revision");
                if (Revision_member != obj.MemberEnd() && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();
                const Value::ConstMemberIterator FunctionResult_member = obj.FindMember("FunctionResult");
                if (FunctionResult_member != obj.MemberEnd() && !FunctionResult_member->value.IsNull()) FunctionResult = MultitypeVar(FunctionResult_member->value);
                const Value::ConstMemberIterator FunctionResultTooLarge_member = obj.FindMember("FunctionResultTooLarge");
                if (FunctionResultTooLarge_member != obj.MemberEnd() && !FunctionResultTooLarge_member->value.IsNull()) FunctionResultTooLarge = FunctionResultTooLarge_member->value.GetBool();
                const Value::ConstMemberIterator Logs_member = obj.FindMember("Logs");
                if (Logs_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Logs_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Logs.push_back(LogStatement(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator LogsTooLarge_member = obj.FindMember("LogsTooLarge");
                if (LogsTooLarge_member != obj.MemberEnd() && !LogsTooLarge_member->value.IsNull()) LogsTooLarge = LogsTooLarge_member->value.GetBool();
                const Value::ConstMemberIterator ExecutionTimeSeconds_member = obj.FindMember("ExecutionTimeSeconds");
                if (ExecutionTimeSeconds_member != obj.MemberEnd() && !ExecutionTimeSeconds_member->value.IsNull()) ExecutionTimeSeconds = ExecutionTimeSeconds_member->value.GetDouble();
                const Value::ConstMemberIterator ProcessorTimeSeconds_member = obj.FindMember("ProcessorTimeSeconds");
                if (ProcessorTimeSeconds_member != obj.MemberEnd() && !ProcessorTimeSeconds_member->value.IsNull()) ProcessorTimeSeconds = ProcessorTimeSeconds_member->value.GetDouble();
                const Value::ConstMemberIterator MemoryConsumedBytes_member = obj.FindMember("MemoryConsumedBytes");
                if (MemoryConsumedBytes_member != obj.MemberEnd() && !MemoryConsumedBytes_member->value.IsNull()) MemoryConsumedBytes = MemoryConsumedBytes_member->value.GetUint();
                const Value::ConstMemberIterator APIRequestsIssued_member = obj.FindMember("APIRequestsIssued");
                if (APIRequestsIssued_member != obj.MemberEnd() && !APIRequestsIssued_member->value.IsNull()) APIRequestsIssued = APIRequestsIssued_member->value.GetInt();
                const Value::ConstMemberIterator HttpRequestsIssued_member = obj.FindMember("HttpRequestsIssued");
                if (HttpRequestsIssued_member != obj.MemberEnd() && !HttpRequestsIssued_member->value.IsNull()) HttpRequestsIssued = HttpRequestsIssued_member->value.GetInt();
                const Value::ConstMemberIterator Error_member = obj.FindMember("Error");
                if (Error_member != obj.MemberEnd() && !Error_member->value.IsNull()) Error = new ScriptExecutionError(Error_member->value);

                return true;
            }
        };

        struct FacebookPlayFabIdPair : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::FacebookPlayFabIdPair,"{d7f09d4a-8239-5b37-83b5-07e65d54c18d}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string FacebookId;
            AZStd::string PlayFabId;

            FacebookPlayFabIdPair() :
                PlayFabBaseModel(),
                FacebookId(),
                PlayFabId()
            {}

            FacebookPlayFabIdPair(const FacebookPlayFabIdPair& src) :
                PlayFabBaseModel(),
                FacebookId(src.FacebookId),
                PlayFabId(src.PlayFabId)
            {}

            FacebookPlayFabIdPair(const rapidjson::Value& obj) : FacebookPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~FacebookPlayFabIdPair()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (FacebookId.length() > 0) {
                    writer.String("FacebookId");
                    writer.String(FacebookId.c_str());
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FacebookId_member = obj.FindMember("FacebookId");
                if (FacebookId_member != obj.MemberEnd() && !FacebookId_member->value.IsNull()) FacebookId = FacebookId_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct UserFacebookInfo : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UserFacebookInfo,"{035647f2-975a-5bdc-98e5-e8d2ad86f8fd}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string FacebookId;
            AZStd::string FullName;

            UserFacebookInfo() :
                PlayFabBaseModel(),
                FacebookId(),
                FullName()
            {}

            UserFacebookInfo(const UserFacebookInfo& src) :
                PlayFabBaseModel(),
                FacebookId(src.FacebookId),
                FullName(src.FullName)
            {}

            UserFacebookInfo(const rapidjson::Value& obj) : UserFacebookInfo()
            {
                readFromValue(obj);
            }

            ~UserFacebookInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (FacebookId.length() > 0) {
                    writer.String("FacebookId");
                    writer.String(FacebookId.c_str());
                }
                if (FullName.length() > 0) {
                    writer.String("FullName");
                    writer.String(FullName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FacebookId_member = obj.FindMember("FacebookId");
                if (FacebookId_member != obj.MemberEnd() && !FacebookId_member->value.IsNull()) FacebookId = FacebookId_member->value.GetString();
                const Value::ConstMemberIterator FullName_member = obj.FindMember("FullName");
                if (FullName_member != obj.MemberEnd() && !FullName_member->value.IsNull()) FullName = FullName_member->value.GetString();

                return true;
            }
        };

        enum TitleActivationStatus
        {
            TitleActivationStatusNone,
            TitleActivationStatusActivatedTitleKey,
            TitleActivationStatusPendingSteam,
            TitleActivationStatusActivatedSteam,
            TitleActivationStatusRevokedSteam
        };

        inline void writeTitleActivationStatusEnumJSON(TitleActivationStatus enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case TitleActivationStatusNone: writer.String("None"); break;
            case TitleActivationStatusActivatedTitleKey: writer.String("ActivatedTitleKey"); break;
            case TitleActivationStatusPendingSteam: writer.String("PendingSteam"); break;
            case TitleActivationStatusActivatedSteam: writer.String("ActivatedSteam"); break;
            case TitleActivationStatusRevokedSteam: writer.String("RevokedSteam"); break;

            }
        }

        inline TitleActivationStatus readTitleActivationStatusFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<TitleActivationStatus>(obj.GetInt());

            static std::map<const char *, TitleActivationStatus, PlayFabComboSdk::StringCompare> _TitleActivationStatusMap;
            if (_TitleActivationStatusMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _TitleActivationStatusMap["None"] = TitleActivationStatusNone;
                _TitleActivationStatusMap["ActivatedTitleKey"] = TitleActivationStatusActivatedTitleKey;
                _TitleActivationStatusMap["PendingSteam"] = TitleActivationStatusPendingSteam;
                _TitleActivationStatusMap["ActivatedSteam"] = TitleActivationStatusActivatedSteam;
                _TitleActivationStatusMap["RevokedSteam"] = TitleActivationStatusRevokedSteam;

            }

            auto output = _TitleActivationStatusMap.find(obj.GetString());
            if (output != _TitleActivationStatusMap.end())
                return output->second;

            return TitleActivationStatusNone; // Basically critical fail
        }

        struct UserSteamInfo : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UserSteamInfo,"{24079cdf-8f0c-56b5-a741-35c38843ce21}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string SteamId;
            AZStd::string SteamCountry;
            Boxed<Currency> SteamCurrency;
            Boxed<TitleActivationStatus> SteamActivationStatus;

            UserSteamInfo() :
                PlayFabBaseModel(),
                SteamId(),
                SteamCountry(),
                SteamCurrency(),
                SteamActivationStatus()
            {}

            UserSteamInfo(const UserSteamInfo& src) :
                PlayFabBaseModel(),
                SteamId(src.SteamId),
                SteamCountry(src.SteamCountry),
                SteamCurrency(src.SteamCurrency),
                SteamActivationStatus(src.SteamActivationStatus)
            {}

            UserSteamInfo(const rapidjson::Value& obj) : UserSteamInfo()
            {
                readFromValue(obj);
            }

            ~UserSteamInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (SteamId.length() > 0) {
                    writer.String("SteamId");
                    writer.String(SteamId.c_str());
                }
                if (SteamCountry.length() > 0) {
                    writer.String("SteamCountry");
                    writer.String(SteamCountry.c_str());
                }
                if (SteamCurrency.notNull()) {
                    writer.String("SteamCurrency");
                    writeCurrencyEnumJSON(SteamCurrency, writer);
                }
                if (SteamActivationStatus.notNull()) {
                    writer.String("SteamActivationStatus");
                    writeTitleActivationStatusEnumJSON(SteamActivationStatus, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SteamId_member = obj.FindMember("SteamId");
                if (SteamId_member != obj.MemberEnd() && !SteamId_member->value.IsNull()) SteamId = SteamId_member->value.GetString();
                const Value::ConstMemberIterator SteamCountry_member = obj.FindMember("SteamCountry");
                if (SteamCountry_member != obj.MemberEnd() && !SteamCountry_member->value.IsNull()) SteamCountry = SteamCountry_member->value.GetString();
                const Value::ConstMemberIterator SteamCurrency_member = obj.FindMember("SteamCurrency");
                if (SteamCurrency_member != obj.MemberEnd() && !SteamCurrency_member->value.IsNull()) SteamCurrency = readCurrencyFromValue(SteamCurrency_member->value);
                const Value::ConstMemberIterator SteamActivationStatus_member = obj.FindMember("SteamActivationStatus");
                if (SteamActivationStatus_member != obj.MemberEnd() && !SteamActivationStatus_member->value.IsNull()) SteamActivationStatus = readTitleActivationStatusFromValue(SteamActivationStatus_member->value);

                return true;
            }
        };

        struct UserGameCenterInfo : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UserGameCenterInfo,"{b64357bd-d71a-5848-ad61-3e5f9945de45}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string GameCenterId;

            UserGameCenterInfo() :
                PlayFabBaseModel(),
                GameCenterId()
            {}

            UserGameCenterInfo(const UserGameCenterInfo& src) :
                PlayFabBaseModel(),
                GameCenterId(src.GameCenterId)
            {}

            UserGameCenterInfo(const rapidjson::Value& obj) : UserGameCenterInfo()
            {
                readFromValue(obj);
            }

            ~UserGameCenterInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (GameCenterId.length() > 0) {
                    writer.String("GameCenterId");
                    writer.String(GameCenterId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GameCenterId_member = obj.FindMember("GameCenterId");
                if (GameCenterId_member != obj.MemberEnd() && !GameCenterId_member->value.IsNull()) GameCenterId = GameCenterId_member->value.GetString();

                return true;
            }
        };

        enum LoginIdentityProvider
        {
            LoginIdentityProviderUnknown,
            LoginIdentityProviderPlayFab,
            LoginIdentityProviderCustom,
            LoginIdentityProviderGameCenter,
            LoginIdentityProviderGooglePlay,
            LoginIdentityProviderSteam,
            LoginIdentityProviderXBoxLive,
            LoginIdentityProviderPSN,
            LoginIdentityProviderKongregate,
            LoginIdentityProviderFacebook,
            LoginIdentityProviderIOSDevice,
            LoginIdentityProviderAndroidDevice,
            LoginIdentityProviderTwitch,
            LoginIdentityProviderWindowsHello
        };

        inline void writeLoginIdentityProviderEnumJSON(LoginIdentityProvider enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case LoginIdentityProviderUnknown: writer.String("Unknown"); break;
            case LoginIdentityProviderPlayFab: writer.String("PlayFab"); break;
            case LoginIdentityProviderCustom: writer.String("Custom"); break;
            case LoginIdentityProviderGameCenter: writer.String("GameCenter"); break;
            case LoginIdentityProviderGooglePlay: writer.String("GooglePlay"); break;
            case LoginIdentityProviderSteam: writer.String("Steam"); break;
            case LoginIdentityProviderXBoxLive: writer.String("XBoxLive"); break;
            case LoginIdentityProviderPSN: writer.String("PSN"); break;
            case LoginIdentityProviderKongregate: writer.String("Kongregate"); break;
            case LoginIdentityProviderFacebook: writer.String("Facebook"); break;
            case LoginIdentityProviderIOSDevice: writer.String("IOSDevice"); break;
            case LoginIdentityProviderAndroidDevice: writer.String("AndroidDevice"); break;
            case LoginIdentityProviderTwitch: writer.String("Twitch"); break;
            case LoginIdentityProviderWindowsHello: writer.String("WindowsHello"); break;

            }
        }

        inline LoginIdentityProvider readLoginIdentityProviderFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<LoginIdentityProvider>(obj.GetInt());

            static std::map<const char *, LoginIdentityProvider, PlayFabComboSdk::StringCompare> _LoginIdentityProviderMap;
            if (_LoginIdentityProviderMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _LoginIdentityProviderMap["Unknown"] = LoginIdentityProviderUnknown;
                _LoginIdentityProviderMap["PlayFab"] = LoginIdentityProviderPlayFab;
                _LoginIdentityProviderMap["Custom"] = LoginIdentityProviderCustom;
                _LoginIdentityProviderMap["GameCenter"] = LoginIdentityProviderGameCenter;
                _LoginIdentityProviderMap["GooglePlay"] = LoginIdentityProviderGooglePlay;
                _LoginIdentityProviderMap["Steam"] = LoginIdentityProviderSteam;
                _LoginIdentityProviderMap["XBoxLive"] = LoginIdentityProviderXBoxLive;
                _LoginIdentityProviderMap["PSN"] = LoginIdentityProviderPSN;
                _LoginIdentityProviderMap["Kongregate"] = LoginIdentityProviderKongregate;
                _LoginIdentityProviderMap["Facebook"] = LoginIdentityProviderFacebook;
                _LoginIdentityProviderMap["IOSDevice"] = LoginIdentityProviderIOSDevice;
                _LoginIdentityProviderMap["AndroidDevice"] = LoginIdentityProviderAndroidDevice;
                _LoginIdentityProviderMap["Twitch"] = LoginIdentityProviderTwitch;
                _LoginIdentityProviderMap["WindowsHello"] = LoginIdentityProviderWindowsHello;

            }

            auto output = _LoginIdentityProviderMap.find(obj.GetString());
            if (output != _LoginIdentityProviderMap.end())
                return output->second;

            return LoginIdentityProviderUnknown; // Basically critical fail
        }

        struct LocationModel : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LocationModel,"{68699f65-7c02-5c39-b801-2be1830fda61}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            Boxed<ContinentCode> pfContinentCode;
            Boxed<CountryCode> pfCountryCode;
            AZStd::string City;
            OptionalDouble Latitude;
            OptionalDouble Longitude;

            LocationModel() :
                PlayFabBaseModel(),
                pfContinentCode(),
                pfCountryCode(),
                City(),
                Latitude(),
                Longitude()
            {}

            LocationModel(const LocationModel& src) :
                PlayFabBaseModel(),
                pfContinentCode(src.pfContinentCode),
                pfCountryCode(src.pfCountryCode),
                City(src.City),
                Latitude(src.Latitude),
                Longitude(src.Longitude)
            {}

            LocationModel(const rapidjson::Value& obj) : LocationModel()
            {
                readFromValue(obj);
            }

            ~LocationModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (pfContinentCode.notNull()) {
                    writer.String("ContinentCode");
                    writeContinentCodeEnumJSON(pfContinentCode, writer);
                }
                if (pfCountryCode.notNull()) {
                    writer.String("CountryCode");
                    writeCountryCodeEnumJSON(pfCountryCode, writer);
                }
                if (City.length() > 0) {
                    writer.String("City");
                    writer.String(City.c_str());
                }
                if (Latitude.notNull()) {
                    writer.String("Latitude");
                    writer.Double(Latitude);
                }
                if (Longitude.notNull()) {
                    writer.String("Longitude");
                    writer.Double(Longitude);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ContinentCode_member = obj.FindMember("ContinentCode");
                if (ContinentCode_member != obj.MemberEnd() && !ContinentCode_member->value.IsNull()) pfContinentCode = readContinentCodeFromValue(ContinentCode_member->value);
                const Value::ConstMemberIterator CountryCode_member = obj.FindMember("CountryCode");
                if (CountryCode_member != obj.MemberEnd() && !CountryCode_member->value.IsNull()) pfCountryCode = readCountryCodeFromValue(CountryCode_member->value);
                const Value::ConstMemberIterator City_member = obj.FindMember("City");
                if (City_member != obj.MemberEnd() && !City_member->value.IsNull()) City = City_member->value.GetString();
                const Value::ConstMemberIterator Latitude_member = obj.FindMember("Latitude");
                if (Latitude_member != obj.MemberEnd() && !Latitude_member->value.IsNull()) Latitude = Latitude_member->value.GetDouble();
                const Value::ConstMemberIterator Longitude_member = obj.FindMember("Longitude");
                if (Longitude_member != obj.MemberEnd() && !Longitude_member->value.IsNull()) Longitude = Longitude_member->value.GetDouble();

                return true;
            }
        };

        struct TagModel : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::TagModel,"{6c76f702-10f4-52a0-9ebc-92ab3ed01364}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string TagValue;

            TagModel() :
                PlayFabBaseModel(),
                TagValue()
            {}

            TagModel(const TagModel& src) :
                PlayFabBaseModel(),
                TagValue(src.TagValue)
            {}

            TagModel(const rapidjson::Value& obj) : TagModel()
            {
                readFromValue(obj);
            }

            ~TagModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (TagValue.length() > 0) {
                    writer.String("TagValue");
                    writer.String(TagValue.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TagValue_member = obj.FindMember("TagValue");
                if (TagValue_member != obj.MemberEnd() && !TagValue_member->value.IsNull()) TagValue = TagValue_member->value.GetString();

                return true;
            }
        };

        enum PushNotificationPlatform
        {
            PushNotificationPlatformApplePushNotificationService,
            PushNotificationPlatformGoogleCloudMessaging
        };

        inline void writePushNotificationPlatformEnumJSON(PushNotificationPlatform enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case PushNotificationPlatformApplePushNotificationService: writer.String("ApplePushNotificationService"); break;
            case PushNotificationPlatformGoogleCloudMessaging: writer.String("GoogleCloudMessaging"); break;

            }
        }

        inline PushNotificationPlatform readPushNotificationPlatformFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<PushNotificationPlatform>(obj.GetInt());

            static std::map<const char *, PushNotificationPlatform, PlayFabComboSdk::StringCompare> _PushNotificationPlatformMap;
            if (_PushNotificationPlatformMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _PushNotificationPlatformMap["ApplePushNotificationService"] = PushNotificationPlatformApplePushNotificationService;
                _PushNotificationPlatformMap["GoogleCloudMessaging"] = PushNotificationPlatformGoogleCloudMessaging;

            }

            auto output = _PushNotificationPlatformMap.find(obj.GetString());
            if (output != _PushNotificationPlatformMap.end())
                return output->second;

            return PushNotificationPlatformApplePushNotificationService; // Basically critical fail
        }

        struct PushNotificationRegistrationModel : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::PushNotificationRegistrationModel,"{5878b618-e40e-5be4-a6a6-39e21a5d6aa7}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            Boxed<PushNotificationPlatform> Platform;
            AZStd::string NotificationEndpointARN;

            PushNotificationRegistrationModel() :
                PlayFabBaseModel(),
                Platform(),
                NotificationEndpointARN()
            {}

            PushNotificationRegistrationModel(const PushNotificationRegistrationModel& src) :
                PlayFabBaseModel(),
                Platform(src.Platform),
                NotificationEndpointARN(src.NotificationEndpointARN)
            {}

            PushNotificationRegistrationModel(const rapidjson::Value& obj) : PushNotificationRegistrationModel()
            {
                readFromValue(obj);
            }

            ~PushNotificationRegistrationModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Platform.notNull()) {
                    writer.String("Platform");
                    writePushNotificationPlatformEnumJSON(Platform, writer);
                }
                if (NotificationEndpointARN.length() > 0) {
                    writer.String("NotificationEndpointARN");
                    writer.String(NotificationEndpointARN.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
                if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = readPushNotificationPlatformFromValue(Platform_member->value);
                const Value::ConstMemberIterator NotificationEndpointARN_member = obj.FindMember("NotificationEndpointARN");
                if (NotificationEndpointARN_member != obj.MemberEnd() && !NotificationEndpointARN_member->value.IsNull()) NotificationEndpointARN = NotificationEndpointARN_member->value.GetString();

                return true;
            }
        };

        struct LinkedPlatformAccountModel : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LinkedPlatformAccountModel,"{54238568-b5f2-5f8b-9670-3d9663351ec2}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            Boxed<LoginIdentityProvider> Platform;
            AZStd::string PlatformUserId;
            AZStd::string Username;
            AZStd::string Email;

            LinkedPlatformAccountModel() :
                PlayFabBaseModel(),
                Platform(),
                PlatformUserId(),
                Username(),
                Email()
            {}

            LinkedPlatformAccountModel(const LinkedPlatformAccountModel& src) :
                PlayFabBaseModel(),
                Platform(src.Platform),
                PlatformUserId(src.PlatformUserId),
                Username(src.Username),
                Email(src.Email)
            {}

            LinkedPlatformAccountModel(const rapidjson::Value& obj) : LinkedPlatformAccountModel()
            {
                readFromValue(obj);
            }

            ~LinkedPlatformAccountModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Platform.notNull()) {
                    writer.String("Platform");
                    writeLoginIdentityProviderEnumJSON(Platform, writer);
                }
                if (PlatformUserId.length() > 0) {
                    writer.String("PlatformUserId");
                    writer.String(PlatformUserId.c_str());
                }
                if (Username.length() > 0) {
                    writer.String("Username");
                    writer.String(Username.c_str());
                }
                if (Email.length() > 0) {
                    writer.String("Email");
                    writer.String(Email.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
                if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = readLoginIdentityProviderFromValue(Platform_member->value);
                const Value::ConstMemberIterator PlatformUserId_member = obj.FindMember("PlatformUserId");
                if (PlatformUserId_member != obj.MemberEnd() && !PlatformUserId_member->value.IsNull()) PlatformUserId = PlatformUserId_member->value.GetString();
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
                const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
                if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();

                return true;
            }
        };

        struct ValueToDateModel : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ValueToDateModel,"{df64b8f3-3b14-5877-9071-d3cd9e8d741d}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string Currency;
            Uint32 TotalValue;
            AZStd::string TotalValueAsDecimal;

            ValueToDateModel() :
                PlayFabBaseModel(),
                Currency(),
                TotalValue(0),
                TotalValueAsDecimal()
            {}

            ValueToDateModel(const ValueToDateModel& src) :
                PlayFabBaseModel(),
                Currency(src.Currency),
                TotalValue(src.TotalValue),
                TotalValueAsDecimal(src.TotalValueAsDecimal)
            {}

            ValueToDateModel(const rapidjson::Value& obj) : ValueToDateModel()
            {
                readFromValue(obj);
            }

            ~ValueToDateModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Currency.length() > 0) {
                    writer.String("Currency");
                    writer.String(Currency.c_str());
                }
                writer.String("TotalValue");
                writer.Uint(TotalValue);
                if (TotalValueAsDecimal.length() > 0) {
                    writer.String("TotalValueAsDecimal");
                    writer.String(TotalValueAsDecimal.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Currency_member = obj.FindMember("Currency");
                if (Currency_member != obj.MemberEnd() && !Currency_member->value.IsNull()) Currency = Currency_member->value.GetString();
                const Value::ConstMemberIterator TotalValue_member = obj.FindMember("TotalValue");
                if (TotalValue_member != obj.MemberEnd() && !TotalValue_member->value.IsNull()) TotalValue = TotalValue_member->value.GetUint();
                const Value::ConstMemberIterator TotalValueAsDecimal_member = obj.FindMember("TotalValueAsDecimal");
                if (TotalValueAsDecimal_member != obj.MemberEnd() && !TotalValueAsDecimal_member->value.IsNull()) TotalValueAsDecimal = TotalValueAsDecimal_member->value.GetString();

                return true;
            }
        };

        struct VirtualCurrencyBalanceModel : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::VirtualCurrencyBalanceModel,"{267c1c82-5807-5217-894a-53db106971bf}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string Currency;
            Int32 TotalValue;

            VirtualCurrencyBalanceModel() :
                PlayFabBaseModel(),
                Currency(),
                TotalValue(0)
            {}

            VirtualCurrencyBalanceModel(const VirtualCurrencyBalanceModel& src) :
                PlayFabBaseModel(),
                Currency(src.Currency),
                TotalValue(src.TotalValue)
            {}

            VirtualCurrencyBalanceModel(const rapidjson::Value& obj) : VirtualCurrencyBalanceModel()
            {
                readFromValue(obj);
            }

            ~VirtualCurrencyBalanceModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Currency.length() > 0) {
                    writer.String("Currency");
                    writer.String(Currency.c_str());
                }
                writer.String("TotalValue");
                writer.Int(TotalValue);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Currency_member = obj.FindMember("Currency");
                if (Currency_member != obj.MemberEnd() && !Currency_member->value.IsNull()) Currency = Currency_member->value.GetString();
                const Value::ConstMemberIterator TotalValue_member = obj.FindMember("TotalValue");
                if (TotalValue_member != obj.MemberEnd() && !TotalValue_member->value.IsNull()) TotalValue = TotalValue_member->value.GetInt();

                return true;
            }
        };

        struct StatisticModel : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::StatisticModel,"{fcc9f82b-70ba-5210-a84e-d5d3bbcbe466}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string Name;
            Int32 Version;
            Int32 Value;

            StatisticModel() :
                PlayFabBaseModel(),
                Name(),
                Version(0),
                Value(0)
            {}

            StatisticModel(const StatisticModel& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Version(src.Version),
                Value(src.Value)
            {}

            StatisticModel(const rapidjson::Value& obj) : StatisticModel()
            {
                readFromValue(obj);
            }

            ~StatisticModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Name.length() > 0) {
                    writer.String("Name");
                    writer.String(Name.c_str());
                }
                writer.String("Version");
                writer.Int(Version);
                writer.String("Value");
                writer.Int(Value);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
                if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetInt();

                return true;
            }
        };

        struct PlayerProfileModel : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::PlayerProfileModel,"{4f45f135-f958-5216-9702-015352cfb302}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string PublisherId;
            AZStd::string TitleId;
            AZStd::string PlayerId;
            OptionalTime Created;
            Boxed<LoginIdentityProvider> Origination;
            OptionalTime LastLogin;
            OptionalTime BannedUntil;
            AZStd::vector<LocationModel> Locations; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string DisplayName;
            AZStd::string AvatarUrl;
            AZStd::vector<TagModel> Tags; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<PushNotificationRegistrationModel> PushNotificationRegistrations; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<LinkedPlatformAccountModel> LinkedAccounts; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<AdCampaignAttributionModel> AdCampaignAttributions; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            OptionalUint32 TotalValueToDateInUSD;
            AZStd::vector<ValueToDateModel> ValuesToDate; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<VirtualCurrencyBalanceModel> VirtualCurrencyBalances; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<StatisticModel> Statistics; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            PlayerProfileModel() :
                PlayFabBaseModel(),
                PublisherId(),
                TitleId(),
                PlayerId(),
                Created(),
                Origination(),
                LastLogin(),
                BannedUntil(),
                Locations(),
                DisplayName(),
                AvatarUrl(),
                Tags(),
                PushNotificationRegistrations(),
                LinkedAccounts(),
                AdCampaignAttributions(),
                TotalValueToDateInUSD(),
                ValuesToDate(),
                VirtualCurrencyBalances(),
                Statistics()
            {}

            PlayerProfileModel(const PlayerProfileModel& src) :
                PlayFabBaseModel(),
                PublisherId(src.PublisherId),
                TitleId(src.TitleId),
                PlayerId(src.PlayerId),
                Created(src.Created),
                Origination(src.Origination),
                LastLogin(src.LastLogin),
                BannedUntil(src.BannedUntil),
                Locations(src.Locations),
                DisplayName(src.DisplayName),
                AvatarUrl(src.AvatarUrl),
                Tags(src.Tags),
                PushNotificationRegistrations(src.PushNotificationRegistrations),
                LinkedAccounts(src.LinkedAccounts),
                AdCampaignAttributions(src.AdCampaignAttributions),
                TotalValueToDateInUSD(src.TotalValueToDateInUSD),
                ValuesToDate(src.ValuesToDate),
                VirtualCurrencyBalances(src.VirtualCurrencyBalances),
                Statistics(src.Statistics)
            {}

            PlayerProfileModel(const rapidjson::Value& obj) : PlayerProfileModel()
            {
                readFromValue(obj);
            }

            ~PlayerProfileModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PublisherId.length() > 0) {
                    writer.String("PublisherId");
                    writer.String(PublisherId.c_str());
                }
                if (TitleId.length() > 0) {
                    writer.String("TitleId");
                    writer.String(TitleId.c_str());
                }
                if (PlayerId.length() > 0) {
                    writer.String("PlayerId");
                    writer.String(PlayerId.c_str());
                }
                if (Created.notNull()) {
                    writer.String("Created");
                    writeDatetime(Created, writer);
                }
                if (Origination.notNull()) {
                    writer.String("Origination");
                    writeLoginIdentityProviderEnumJSON(Origination, writer);
                }
                if (LastLogin.notNull()) {
                    writer.String("LastLogin");
                    writeDatetime(LastLogin, writer);
                }
                if (BannedUntil.notNull()) {
                    writer.String("BannedUntil");
                    writeDatetime(BannedUntil, writer);
                }
                if (!Locations.empty()) {
                    writer.String("Locations");
                    writer.StartArray();
                    for (auto iter = Locations.begin(); iter != Locations.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (DisplayName.length() > 0) {
                    writer.String("DisplayName");
                    writer.String(DisplayName.c_str());
                }
                if (AvatarUrl.length() > 0) {
                    writer.String("AvatarUrl");
                    writer.String(AvatarUrl.c_str());
                }
                if (!Tags.empty()) {
                    writer.String("Tags");
                    writer.StartArray();
                    for (auto iter = Tags.begin(); iter != Tags.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!PushNotificationRegistrations.empty()) {
                    writer.String("PushNotificationRegistrations");
                    writer.StartArray();
                    for (auto iter = PushNotificationRegistrations.begin(); iter != PushNotificationRegistrations.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!LinkedAccounts.empty()) {
                    writer.String("LinkedAccounts");
                    writer.StartArray();
                    for (auto iter = LinkedAccounts.begin(); iter != LinkedAccounts.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!AdCampaignAttributions.empty()) {
                    writer.String("AdCampaignAttributions");
                    writer.StartArray();
                    for (auto iter = AdCampaignAttributions.begin(); iter != AdCampaignAttributions.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (TotalValueToDateInUSD.notNull()) {
                    writer.String("TotalValueToDateInUSD");
                    writer.Uint(TotalValueToDateInUSD);
                }
                if (!ValuesToDate.empty()) {
                    writer.String("ValuesToDate");
                    writer.StartArray();
                    for (auto iter = ValuesToDate.begin(); iter != ValuesToDate.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!VirtualCurrencyBalances.empty()) {
                    writer.String("VirtualCurrencyBalances");
                    writer.StartArray();
                    for (auto iter = VirtualCurrencyBalances.begin(); iter != VirtualCurrencyBalances.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!Statistics.empty()) {
                    writer.String("Statistics");
                    writer.StartArray();
                    for (auto iter = Statistics.begin(); iter != Statistics.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PublisherId_member = obj.FindMember("PublisherId");
                if (PublisherId_member != obj.MemberEnd() && !PublisherId_member->value.IsNull()) PublisherId = PublisherId_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator PlayerId_member = obj.FindMember("PlayerId");
                if (PlayerId_member != obj.MemberEnd() && !PlayerId_member->value.IsNull()) PlayerId = PlayerId_member->value.GetString();
                const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
                if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
                const Value::ConstMemberIterator Origination_member = obj.FindMember("Origination");
                if (Origination_member != obj.MemberEnd() && !Origination_member->value.IsNull()) Origination = readLoginIdentityProviderFromValue(Origination_member->value);
                const Value::ConstMemberIterator LastLogin_member = obj.FindMember("LastLogin");
                if (LastLogin_member != obj.MemberEnd() && !LastLogin_member->value.IsNull()) LastLogin = readDatetime(LastLogin_member->value);
                const Value::ConstMemberIterator BannedUntil_member = obj.FindMember("BannedUntil");
                if (BannedUntil_member != obj.MemberEnd() && !BannedUntil_member->value.IsNull()) BannedUntil = readDatetime(BannedUntil_member->value);
                const Value::ConstMemberIterator Locations_member = obj.FindMember("Locations");
                if (Locations_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Locations_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Locations.push_back(LocationModel(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator AvatarUrl_member = obj.FindMember("AvatarUrl");
                if (AvatarUrl_member != obj.MemberEnd() && !AvatarUrl_member->value.IsNull()) AvatarUrl = AvatarUrl_member->value.GetString();
                const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
                if (Tags_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Tags_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Tags.push_back(TagModel(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator PushNotificationRegistrations_member = obj.FindMember("PushNotificationRegistrations");
                if (PushNotificationRegistrations_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = PushNotificationRegistrations_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        PushNotificationRegistrations.push_back(PushNotificationRegistrationModel(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator LinkedAccounts_member = obj.FindMember("LinkedAccounts");
                if (LinkedAccounts_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = LinkedAccounts_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        LinkedAccounts.push_back(LinkedPlatformAccountModel(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator AdCampaignAttributions_member = obj.FindMember("AdCampaignAttributions");
                if (AdCampaignAttributions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = AdCampaignAttributions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        AdCampaignAttributions.push_back(AdCampaignAttributionModel(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator TotalValueToDateInUSD_member = obj.FindMember("TotalValueToDateInUSD");
                if (TotalValueToDateInUSD_member != obj.MemberEnd() && !TotalValueToDateInUSD_member->value.IsNull()) TotalValueToDateInUSD = TotalValueToDateInUSD_member->value.GetUint();
                const Value::ConstMemberIterator ValuesToDate_member = obj.FindMember("ValuesToDate");
                if (ValuesToDate_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = ValuesToDate_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        ValuesToDate.push_back(ValueToDateModel(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator VirtualCurrencyBalances_member = obj.FindMember("VirtualCurrencyBalances");
                if (VirtualCurrencyBalances_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = VirtualCurrencyBalances_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        VirtualCurrencyBalances.push_back(VirtualCurrencyBalanceModel(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator Statistics_member = obj.FindMember("Statistics");
                if (Statistics_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Statistics_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Statistics.push_back(StatisticModel(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct FriendInfo : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::FriendInfo,"{4e0e5c51-347f-572e-b67e-04c94a028834}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string FriendPlayFabId;
            AZStd::string Username;
            AZStd::string TitleDisplayName;
            AZStd::vector<AZStd::string> Tags; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string CurrentMatchmakerLobbyId;
            UserFacebookInfo* FacebookInfo;
            UserSteamInfo* SteamInfo;
            UserGameCenterInfo* GameCenterInfo;
            PlayerProfileModel* Profile;

            FriendInfo() :
                PlayFabBaseModel(),
                FriendPlayFabId(),
                Username(),
                TitleDisplayName(),
                Tags(),
                CurrentMatchmakerLobbyId(),
                FacebookInfo(nullptr),
                SteamInfo(nullptr),
                GameCenterInfo(nullptr),
                Profile(nullptr)
            {}

            FriendInfo(const FriendInfo& src) :
                PlayFabBaseModel(),
                FriendPlayFabId(src.FriendPlayFabId),
                Username(src.Username),
                TitleDisplayName(src.TitleDisplayName),
                Tags(src.Tags),
                CurrentMatchmakerLobbyId(src.CurrentMatchmakerLobbyId),
                FacebookInfo(src.FacebookInfo ? new UserFacebookInfo(*src.FacebookInfo) : nullptr),
                SteamInfo(src.SteamInfo ? new UserSteamInfo(*src.SteamInfo) : nullptr),
                GameCenterInfo(src.GameCenterInfo ? new UserGameCenterInfo(*src.GameCenterInfo) : nullptr),
                Profile(src.Profile ? new PlayerProfileModel(*src.Profile) : nullptr)
            {}

            FriendInfo(const rapidjson::Value& obj) : FriendInfo()
            {
                readFromValue(obj);
            }

            ~FriendInfo()
            {
                if (FacebookInfo != nullptr) delete FacebookInfo;
                if (SteamInfo != nullptr) delete SteamInfo;
                if (GameCenterInfo != nullptr) delete GameCenterInfo;
                if (Profile != nullptr) delete Profile;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (FriendPlayFabId.length() > 0) {
                    writer.String("FriendPlayFabId");
                    writer.String(FriendPlayFabId.c_str());
                }
                if (Username.length() > 0) {
                    writer.String("Username");
                    writer.String(Username.c_str());
                }
                if (TitleDisplayName.length() > 0) {
                    writer.String("TitleDisplayName");
                    writer.String(TitleDisplayName.c_str());
                }
                if (!Tags.empty()) {
                    writer.String("Tags");
                    writer.StartArray();
                    for (auto iter = Tags.begin(); iter != Tags.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (CurrentMatchmakerLobbyId.length() > 0) {
                    writer.String("CurrentMatchmakerLobbyId");
                    writer.String(CurrentMatchmakerLobbyId.c_str());
                }
                if (FacebookInfo != nullptr) {
                    writer.String("FacebookInfo");
                    FacebookInfo->writeJSON(writer);
                }
                if (SteamInfo != nullptr) {
                    writer.String("SteamInfo");
                    SteamInfo->writeJSON(writer);
                }
                if (GameCenterInfo != nullptr) {
                    writer.String("GameCenterInfo");
                    GameCenterInfo->writeJSON(writer);
                }
                if (Profile != nullptr) {
                    writer.String("Profile");
                    Profile->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
                if (FriendPlayFabId_member != obj.MemberEnd() && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
                const Value::ConstMemberIterator TitleDisplayName_member = obj.FindMember("TitleDisplayName");
                if (TitleDisplayName_member != obj.MemberEnd() && !TitleDisplayName_member->value.IsNull()) TitleDisplayName = TitleDisplayName_member->value.GetString();
                const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
                if (Tags_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Tags_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Tags.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator CurrentMatchmakerLobbyId_member = obj.FindMember("CurrentMatchmakerLobbyId");
                if (CurrentMatchmakerLobbyId_member != obj.MemberEnd() && !CurrentMatchmakerLobbyId_member->value.IsNull()) CurrentMatchmakerLobbyId = CurrentMatchmakerLobbyId_member->value.GetString();
                const Value::ConstMemberIterator FacebookInfo_member = obj.FindMember("FacebookInfo");
                if (FacebookInfo_member != obj.MemberEnd() && !FacebookInfo_member->value.IsNull()) FacebookInfo = new UserFacebookInfo(FacebookInfo_member->value);
                const Value::ConstMemberIterator SteamInfo_member = obj.FindMember("SteamInfo");
                if (SteamInfo_member != obj.MemberEnd() && !SteamInfo_member->value.IsNull()) SteamInfo = new UserSteamInfo(SteamInfo_member->value);
                const Value::ConstMemberIterator GameCenterInfo_member = obj.FindMember("GameCenterInfo");
                if (GameCenterInfo_member != obj.MemberEnd() && !GameCenterInfo_member->value.IsNull()) GameCenterInfo = new UserGameCenterInfo(GameCenterInfo_member->value);
                const Value::ConstMemberIterator Profile_member = obj.FindMember("Profile");
                if (Profile_member != obj.MemberEnd() && !Profile_member->value.IsNull()) Profile = new PlayerProfileModel(Profile_member->value);

                return true;
            }
        };

        struct GameCenterPlayFabIdPair : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GameCenterPlayFabIdPair,"{d8c46e10-3ee4-59cc-b4be-3ae27141c5c6}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string GameCenterId;
            AZStd::string PlayFabId;

            GameCenterPlayFabIdPair() :
                PlayFabBaseModel(),
                GameCenterId(),
                PlayFabId()
            {}

            GameCenterPlayFabIdPair(const GameCenterPlayFabIdPair& src) :
                PlayFabBaseModel(),
                GameCenterId(src.GameCenterId),
                PlayFabId(src.PlayFabId)
            {}

            GameCenterPlayFabIdPair(const rapidjson::Value& obj) : GameCenterPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~GameCenterPlayFabIdPair()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (GameCenterId.length() > 0) {
                    writer.String("GameCenterId");
                    writer.String(GameCenterId.c_str());
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GameCenterId_member = obj.FindMember("GameCenterId");
                if (GameCenterId_member != obj.MemberEnd() && !GameCenterId_member->value.IsNull()) GameCenterId = GameCenterId_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct GameServerRegionsRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GameServerRegionsRequest,"{81e4e74a-b328-5b7c-a4b3-845ed6e8c7eb}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string BuildVersion;
            AZStd::string TitleId;

            GameServerRegionsRequest() :
                PlayFabBaseModel(),
                BuildVersion(),
                TitleId()
            {}

            GameServerRegionsRequest(const GameServerRegionsRequest& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion),
                TitleId(src.TitleId)
            {}

            GameServerRegionsRequest(const rapidjson::Value& obj) : GameServerRegionsRequest()
            {
                readFromValue(obj);
            }

            ~GameServerRegionsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("BuildVersion");
                writer.String(BuildVersion.c_str());
                if (TitleId.length() > 0) {
                    writer.String("TitleId");
                    writer.String(TitleId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildVersion_member = obj.FindMember("BuildVersion");
                if (BuildVersion_member != obj.MemberEnd() && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

                return true;
            }
        };

        struct RegionInfo : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::RegionInfo,"{421b5a6f-b744-5a71-8dbc-43c6082dc029}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            Boxed<Region> pfRegion;
            AZStd::string Name;
            bool Available;
            AZStd::string PingUrl;

            RegionInfo() :
                PlayFabBaseModel(),
                pfRegion(),
                Name(),
                Available(false),
                PingUrl()
            {}

            RegionInfo(const RegionInfo& src) :
                PlayFabBaseModel(),
                pfRegion(src.pfRegion),
                Name(src.Name),
                Available(src.Available),
                PingUrl(src.PingUrl)
            {}

            RegionInfo(const rapidjson::Value& obj) : RegionInfo()
            {
                readFromValue(obj);
            }

            ~RegionInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (pfRegion.notNull()) {
                    writer.String("Region");
                    writeRegionEnumJSON(pfRegion, writer);
                }
                if (Name.length() > 0) {
                    writer.String("Name");
                    writer.String(Name.c_str());
                }
                writer.String("Available");
                writer.Bool(Available);
                if (PingUrl.length() > 0) {
                    writer.String("PingUrl");
                    writer.String(PingUrl.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
                if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
                const Value::ConstMemberIterator Available_member = obj.FindMember("Available");
                if (Available_member != obj.MemberEnd() && !Available_member->value.IsNull()) Available = Available_member->value.GetBool();
                const Value::ConstMemberIterator PingUrl_member = obj.FindMember("PingUrl");
                if (PingUrl_member != obj.MemberEnd() && !PingUrl_member->value.IsNull()) PingUrl = PingUrl_member->value.GetString();

                return true;
            }
        };

        struct GameServerRegionsResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GameServerRegionsResult,"{b4ea2e3e-6377-5bed-98d7-b786010336b1}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<RegionInfo> Regions; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GameServerRegionsResult() :
                PlayFabBaseModel(),
                Regions()
            {}

            GameServerRegionsResult(const GameServerRegionsResult& src) :
                PlayFabBaseModel(),
                Regions(src.Regions)
            {}

            GameServerRegionsResult(const rapidjson::Value& obj) : GameServerRegionsResult()
            {
                readFromValue(obj);
            }

            ~GameServerRegionsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Regions.empty()) {
                    writer.String("Regions");
                    writer.StartArray();
                    for (auto iter = Regions.begin(); iter != Regions.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Regions_member = obj.FindMember("Regions");
                if (Regions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Regions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Regions.push_back(RegionInfo(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GenericPlayFabIdPair : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GenericPlayFabIdPair,"{046c07ad-b3a7-5475-b8e3-63ca7fdcb90e}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            GenericServiceId* GenericId;
            AZStd::string PlayFabId;

            GenericPlayFabIdPair() :
                PlayFabBaseModel(),
                GenericId(nullptr),
                PlayFabId()
            {}

            GenericPlayFabIdPair(const GenericPlayFabIdPair& src) :
                PlayFabBaseModel(),
                GenericId(src.GenericId ? new GenericServiceId(*src.GenericId) : nullptr),
                PlayFabId(src.PlayFabId)
            {}

            GenericPlayFabIdPair(const rapidjson::Value& obj) : GenericPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~GenericPlayFabIdPair()
            {
                if (GenericId != nullptr) delete GenericId;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (GenericId != nullptr) {
                    writer.String("GenericId");
                    GenericId->writeJSON(writer);
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GenericId_member = obj.FindMember("GenericId");
                if (GenericId_member != obj.MemberEnd() && !GenericId_member->value.IsNull()) GenericId = new GenericServiceId(GenericId_member->value);
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct GetAccountInfoRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetAccountInfoRequest,"{c7c4f5d4-6bd6-5840-abcb-d754041b8093}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string PlayFabId;
            AZStd::string Username;
            AZStd::string Email;
            AZStd::string TitleDisplayName;

            GetAccountInfoRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                Username(),
                Email(),
                TitleDisplayName()
            {}

            GetAccountInfoRequest(const GetAccountInfoRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Username(src.Username),
                Email(src.Email),
                TitleDisplayName(src.TitleDisplayName)
            {}

            GetAccountInfoRequest(const rapidjson::Value& obj) : GetAccountInfoRequest()
            {
                readFromValue(obj);
            }

            ~GetAccountInfoRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                if (Username.length() > 0) {
                    writer.String("Username");
                    writer.String(Username.c_str());
                }
                if (Email.length() > 0) {
                    writer.String("Email");
                    writer.String(Email.c_str());
                }
                if (TitleDisplayName.length() > 0) {
                    writer.String("TitleDisplayName");
                    writer.String(TitleDisplayName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
                const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
                if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
                const Value::ConstMemberIterator TitleDisplayName_member = obj.FindMember("TitleDisplayName");
                if (TitleDisplayName_member != obj.MemberEnd() && !TitleDisplayName_member->value.IsNull()) TitleDisplayName = TitleDisplayName_member->value.GetString();

                return true;
            }
        };

        enum UserOrigination
        {
            UserOriginationOrganic,
            UserOriginationSteam,
            UserOriginationGoogle,
            UserOriginationAmazon,
            UserOriginationFacebook,
            UserOriginationKongregate,
            UserOriginationGamersFirst,
            UserOriginationUnknown,
            UserOriginationIOS,
            UserOriginationLoadTest,
            UserOriginationAndroid,
            UserOriginationPSN,
            UserOriginationGameCenter,
            UserOriginationCustomId,
            UserOriginationXboxLive,
            UserOriginationParse,
            UserOriginationTwitch,
            UserOriginationWindowsHello
        };

        inline void writeUserOriginationEnumJSON(UserOrigination enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case UserOriginationOrganic: writer.String("Organic"); break;
            case UserOriginationSteam: writer.String("Steam"); break;
            case UserOriginationGoogle: writer.String("Google"); break;
            case UserOriginationAmazon: writer.String("Amazon"); break;
            case UserOriginationFacebook: writer.String("Facebook"); break;
            case UserOriginationKongregate: writer.String("Kongregate"); break;
            case UserOriginationGamersFirst: writer.String("GamersFirst"); break;
            case UserOriginationUnknown: writer.String("Unknown"); break;
            case UserOriginationIOS: writer.String("IOS"); break;
            case UserOriginationLoadTest: writer.String("LoadTest"); break;
            case UserOriginationAndroid: writer.String("Android"); break;
            case UserOriginationPSN: writer.String("PSN"); break;
            case UserOriginationGameCenter: writer.String("GameCenter"); break;
            case UserOriginationCustomId: writer.String("CustomId"); break;
            case UserOriginationXboxLive: writer.String("XboxLive"); break;
            case UserOriginationParse: writer.String("Parse"); break;
            case UserOriginationTwitch: writer.String("Twitch"); break;
            case UserOriginationWindowsHello: writer.String("WindowsHello"); break;

            }
        }

        inline UserOrigination readUserOriginationFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<UserOrigination>(obj.GetInt());

            static std::map<const char *, UserOrigination, PlayFabComboSdk::StringCompare> _UserOriginationMap;
            if (_UserOriginationMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _UserOriginationMap["Organic"] = UserOriginationOrganic;
                _UserOriginationMap["Steam"] = UserOriginationSteam;
                _UserOriginationMap["Google"] = UserOriginationGoogle;
                _UserOriginationMap["Amazon"] = UserOriginationAmazon;
                _UserOriginationMap["Facebook"] = UserOriginationFacebook;
                _UserOriginationMap["Kongregate"] = UserOriginationKongregate;
                _UserOriginationMap["GamersFirst"] = UserOriginationGamersFirst;
                _UserOriginationMap["Unknown"] = UserOriginationUnknown;
                _UserOriginationMap["IOS"] = UserOriginationIOS;
                _UserOriginationMap["LoadTest"] = UserOriginationLoadTest;
                _UserOriginationMap["Android"] = UserOriginationAndroid;
                _UserOriginationMap["PSN"] = UserOriginationPSN;
                _UserOriginationMap["GameCenter"] = UserOriginationGameCenter;
                _UserOriginationMap["CustomId"] = UserOriginationCustomId;
                _UserOriginationMap["XboxLive"] = UserOriginationXboxLive;
                _UserOriginationMap["Parse"] = UserOriginationParse;
                _UserOriginationMap["Twitch"] = UserOriginationTwitch;
                _UserOriginationMap["WindowsHello"] = UserOriginationWindowsHello;

            }

            auto output = _UserOriginationMap.find(obj.GetString());
            if (output != _UserOriginationMap.end())
                return output->second;

            return UserOriginationOrganic; // Basically critical fail
        }

        struct UserTitleInfo : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UserTitleInfo,"{24adf0e4-5cbb-5eb9-b386-0ff586308c96}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string DisplayName;
            Boxed<UserOrigination> Origination;
            time_t Created;
            OptionalTime LastLogin;
            OptionalTime FirstLogin;
            OptionalBool isBanned;
            AZStd::string AvatarUrl;

            UserTitleInfo() :
                PlayFabBaseModel(),
                DisplayName(),
                Origination(),
                Created(0),
                LastLogin(),
                FirstLogin(),
                isBanned(),
                AvatarUrl()
            {}

            UserTitleInfo(const UserTitleInfo& src) :
                PlayFabBaseModel(),
                DisplayName(src.DisplayName),
                Origination(src.Origination),
                Created(src.Created),
                LastLogin(src.LastLogin),
                FirstLogin(src.FirstLogin),
                isBanned(src.isBanned),
                AvatarUrl(src.AvatarUrl)
            {}

            UserTitleInfo(const rapidjson::Value& obj) : UserTitleInfo()
            {
                readFromValue(obj);
            }

            ~UserTitleInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (DisplayName.length() > 0) {
                    writer.String("DisplayName");
                    writer.String(DisplayName.c_str());
                }
                if (Origination.notNull()) {
                    writer.String("Origination");
                    writeUserOriginationEnumJSON(Origination, writer);
                }
                writer.String("Created");
                writeDatetime(Created, writer);
                if (LastLogin.notNull()) {
                    writer.String("LastLogin");
                    writeDatetime(LastLogin, writer);
                }
                if (FirstLogin.notNull()) {
                    writer.String("FirstLogin");
                    writeDatetime(FirstLogin, writer);
                }
                if (isBanned.notNull()) {
                    writer.String("isBanned");
                    writer.Bool(isBanned);
                }
                if (AvatarUrl.length() > 0) {
                    writer.String("AvatarUrl");
                    writer.String(AvatarUrl.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator Origination_member = obj.FindMember("Origination");
                if (Origination_member != obj.MemberEnd() && !Origination_member->value.IsNull()) Origination = readUserOriginationFromValue(Origination_member->value);
                const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
                if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
                const Value::ConstMemberIterator LastLogin_member = obj.FindMember("LastLogin");
                if (LastLogin_member != obj.MemberEnd() && !LastLogin_member->value.IsNull()) LastLogin = readDatetime(LastLogin_member->value);
                const Value::ConstMemberIterator FirstLogin_member = obj.FindMember("FirstLogin");
                if (FirstLogin_member != obj.MemberEnd() && !FirstLogin_member->value.IsNull()) FirstLogin = readDatetime(FirstLogin_member->value);
                const Value::ConstMemberIterator isBanned_member = obj.FindMember("isBanned");
                if (isBanned_member != obj.MemberEnd() && !isBanned_member->value.IsNull()) isBanned = isBanned_member->value.GetBool();
                const Value::ConstMemberIterator AvatarUrl_member = obj.FindMember("AvatarUrl");
                if (AvatarUrl_member != obj.MemberEnd() && !AvatarUrl_member->value.IsNull()) AvatarUrl = AvatarUrl_member->value.GetString();

                return true;
            }
        };

        struct UserPrivateAccountInfo : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UserPrivateAccountInfo,"{f3620e59-121f-5a3d-a64e-51d468de6c0e}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string Email;

            UserPrivateAccountInfo() :
                PlayFabBaseModel(),
                Email()
            {}

            UserPrivateAccountInfo(const UserPrivateAccountInfo& src) :
                PlayFabBaseModel(),
                Email(src.Email)
            {}

            UserPrivateAccountInfo(const rapidjson::Value& obj) : UserPrivateAccountInfo()
            {
                readFromValue(obj);
            }

            ~UserPrivateAccountInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Email.length() > 0) {
                    writer.String("Email");
                    writer.String(Email.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
                if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();

                return true;
            }
        };

        struct UserIosDeviceInfo : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UserIosDeviceInfo,"{1f2ef4f6-51b4-5f7f-9361-fe28f0d6938c}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string IosDeviceId;

            UserIosDeviceInfo() :
                PlayFabBaseModel(),
                IosDeviceId()
            {}

            UserIosDeviceInfo(const UserIosDeviceInfo& src) :
                PlayFabBaseModel(),
                IosDeviceId(src.IosDeviceId)
            {}

            UserIosDeviceInfo(const rapidjson::Value& obj) : UserIosDeviceInfo()
            {
                readFromValue(obj);
            }

            ~UserIosDeviceInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (IosDeviceId.length() > 0) {
                    writer.String("IosDeviceId");
                    writer.String(IosDeviceId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator IosDeviceId_member = obj.FindMember("IosDeviceId");
                if (IosDeviceId_member != obj.MemberEnd() && !IosDeviceId_member->value.IsNull()) IosDeviceId = IosDeviceId_member->value.GetString();

                return true;
            }
        };

        struct UserAndroidDeviceInfo : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UserAndroidDeviceInfo,"{b7e456da-f8a8-5aac-9a11-c9b681edf9e0}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string AndroidDeviceId;

            UserAndroidDeviceInfo() :
                PlayFabBaseModel(),
                AndroidDeviceId()
            {}

            UserAndroidDeviceInfo(const UserAndroidDeviceInfo& src) :
                PlayFabBaseModel(),
                AndroidDeviceId(src.AndroidDeviceId)
            {}

            UserAndroidDeviceInfo(const rapidjson::Value& obj) : UserAndroidDeviceInfo()
            {
                readFromValue(obj);
            }

            ~UserAndroidDeviceInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (AndroidDeviceId.length() > 0) {
                    writer.String("AndroidDeviceId");
                    writer.String(AndroidDeviceId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AndroidDeviceId_member = obj.FindMember("AndroidDeviceId");
                if (AndroidDeviceId_member != obj.MemberEnd() && !AndroidDeviceId_member->value.IsNull()) AndroidDeviceId = AndroidDeviceId_member->value.GetString();

                return true;
            }
        };

        struct UserKongregateInfo : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UserKongregateInfo,"{9032b7fe-712b-5e7b-a9a2-0a99d347e7a3}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string KongregateId;
            AZStd::string KongregateName;

            UserKongregateInfo() :
                PlayFabBaseModel(),
                KongregateId(),
                KongregateName()
            {}

            UserKongregateInfo(const UserKongregateInfo& src) :
                PlayFabBaseModel(),
                KongregateId(src.KongregateId),
                KongregateName(src.KongregateName)
            {}

            UserKongregateInfo(const rapidjson::Value& obj) : UserKongregateInfo()
            {
                readFromValue(obj);
            }

            ~UserKongregateInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (KongregateId.length() > 0) {
                    writer.String("KongregateId");
                    writer.String(KongregateId.c_str());
                }
                if (KongregateName.length() > 0) {
                    writer.String("KongregateName");
                    writer.String(KongregateName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator KongregateId_member = obj.FindMember("KongregateId");
                if (KongregateId_member != obj.MemberEnd() && !KongregateId_member->value.IsNull()) KongregateId = KongregateId_member->value.GetString();
                const Value::ConstMemberIterator KongregateName_member = obj.FindMember("KongregateName");
                if (KongregateName_member != obj.MemberEnd() && !KongregateName_member->value.IsNull()) KongregateName = KongregateName_member->value.GetString();

                return true;
            }
        };

        struct UserTwitchInfo : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UserTwitchInfo,"{ee378687-dd3d-57cf-8775-0d509495bed3}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string TwitchId;
            AZStd::string TwitchUserName;

            UserTwitchInfo() :
                PlayFabBaseModel(),
                TwitchId(),
                TwitchUserName()
            {}

            UserTwitchInfo(const UserTwitchInfo& src) :
                PlayFabBaseModel(),
                TwitchId(src.TwitchId),
                TwitchUserName(src.TwitchUserName)
            {}

            UserTwitchInfo(const rapidjson::Value& obj) : UserTwitchInfo()
            {
                readFromValue(obj);
            }

            ~UserTwitchInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (TwitchId.length() > 0) {
                    writer.String("TwitchId");
                    writer.String(TwitchId.c_str());
                }
                if (TwitchUserName.length() > 0) {
                    writer.String("TwitchUserName");
                    writer.String(TwitchUserName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TwitchId_member = obj.FindMember("TwitchId");
                if (TwitchId_member != obj.MemberEnd() && !TwitchId_member->value.IsNull()) TwitchId = TwitchId_member->value.GetString();
                const Value::ConstMemberIterator TwitchUserName_member = obj.FindMember("TwitchUserName");
                if (TwitchUserName_member != obj.MemberEnd() && !TwitchUserName_member->value.IsNull()) TwitchUserName = TwitchUserName_member->value.GetString();

                return true;
            }
        };

        struct UserPsnInfo : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UserPsnInfo,"{4d4e8022-6cb9-53fb-9d31-25ee94a2b489}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string PsnAccountId;
            AZStd::string PsnOnlineId;

            UserPsnInfo() :
                PlayFabBaseModel(),
                PsnAccountId(),
                PsnOnlineId()
            {}

            UserPsnInfo(const UserPsnInfo& src) :
                PlayFabBaseModel(),
                PsnAccountId(src.PsnAccountId),
                PsnOnlineId(src.PsnOnlineId)
            {}

            UserPsnInfo(const rapidjson::Value& obj) : UserPsnInfo()
            {
                readFromValue(obj);
            }

            ~UserPsnInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PsnAccountId.length() > 0) {
                    writer.String("PsnAccountId");
                    writer.String(PsnAccountId.c_str());
                }
                if (PsnOnlineId.length() > 0) {
                    writer.String("PsnOnlineId");
                    writer.String(PsnOnlineId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PsnAccountId_member = obj.FindMember("PsnAccountId");
                if (PsnAccountId_member != obj.MemberEnd() && !PsnAccountId_member->value.IsNull()) PsnAccountId = PsnAccountId_member->value.GetString();
                const Value::ConstMemberIterator PsnOnlineId_member = obj.FindMember("PsnOnlineId");
                if (PsnOnlineId_member != obj.MemberEnd() && !PsnOnlineId_member->value.IsNull()) PsnOnlineId = PsnOnlineId_member->value.GetString();

                return true;
            }
        };

        struct UserGoogleInfo : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UserGoogleInfo,"{3ecbacde-8cba-579c-a055-7c4228c42c1e}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string GoogleId;
            AZStd::string GoogleEmail;
            AZStd::string GoogleLocale;
            AZStd::string GoogleGender;

            UserGoogleInfo() :
                PlayFabBaseModel(),
                GoogleId(),
                GoogleEmail(),
                GoogleLocale(),
                GoogleGender()
            {}

            UserGoogleInfo(const UserGoogleInfo& src) :
                PlayFabBaseModel(),
                GoogleId(src.GoogleId),
                GoogleEmail(src.GoogleEmail),
                GoogleLocale(src.GoogleLocale),
                GoogleGender(src.GoogleGender)
            {}

            UserGoogleInfo(const rapidjson::Value& obj) : UserGoogleInfo()
            {
                readFromValue(obj);
            }

            ~UserGoogleInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (GoogleId.length() > 0) {
                    writer.String("GoogleId");
                    writer.String(GoogleId.c_str());
                }
                if (GoogleEmail.length() > 0) {
                    writer.String("GoogleEmail");
                    writer.String(GoogleEmail.c_str());
                }
                if (GoogleLocale.length() > 0) {
                    writer.String("GoogleLocale");
                    writer.String(GoogleLocale.c_str());
                }
                if (GoogleGender.length() > 0) {
                    writer.String("GoogleGender");
                    writer.String(GoogleGender.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GoogleId_member = obj.FindMember("GoogleId");
                if (GoogleId_member != obj.MemberEnd() && !GoogleId_member->value.IsNull()) GoogleId = GoogleId_member->value.GetString();
                const Value::ConstMemberIterator GoogleEmail_member = obj.FindMember("GoogleEmail");
                if (GoogleEmail_member != obj.MemberEnd() && !GoogleEmail_member->value.IsNull()) GoogleEmail = GoogleEmail_member->value.GetString();
                const Value::ConstMemberIterator GoogleLocale_member = obj.FindMember("GoogleLocale");
                if (GoogleLocale_member != obj.MemberEnd() && !GoogleLocale_member->value.IsNull()) GoogleLocale = GoogleLocale_member->value.GetString();
                const Value::ConstMemberIterator GoogleGender_member = obj.FindMember("GoogleGender");
                if (GoogleGender_member != obj.MemberEnd() && !GoogleGender_member->value.IsNull()) GoogleGender = GoogleGender_member->value.GetString();

                return true;
            }
        };

        struct UserXboxInfo : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UserXboxInfo,"{8b57a455-1848-5f48-b4a3-a6097585a2dd}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string XboxUserId;

            UserXboxInfo() :
                PlayFabBaseModel(),
                XboxUserId()
            {}

            UserXboxInfo(const UserXboxInfo& src) :
                PlayFabBaseModel(),
                XboxUserId(src.XboxUserId)
            {}

            UserXboxInfo(const rapidjson::Value& obj) : UserXboxInfo()
            {
                readFromValue(obj);
            }

            ~UserXboxInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (XboxUserId.length() > 0) {
                    writer.String("XboxUserId");
                    writer.String(XboxUserId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator XboxUserId_member = obj.FindMember("XboxUserId");
                if (XboxUserId_member != obj.MemberEnd() && !XboxUserId_member->value.IsNull()) XboxUserId = XboxUserId_member->value.GetString();

                return true;
            }
        };

        struct UserCustomIdInfo : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UserCustomIdInfo,"{49ffc3fa-b792-523a-b650-0ee610782130}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string CustomId;

            UserCustomIdInfo() :
                PlayFabBaseModel(),
                CustomId()
            {}

            UserCustomIdInfo(const UserCustomIdInfo& src) :
                PlayFabBaseModel(),
                CustomId(src.CustomId)
            {}

            UserCustomIdInfo(const rapidjson::Value& obj) : UserCustomIdInfo()
            {
                readFromValue(obj);
            }

            ~UserCustomIdInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CustomId.length() > 0) {
                    writer.String("CustomId");
                    writer.String(CustomId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CustomId_member = obj.FindMember("CustomId");
                if (CustomId_member != obj.MemberEnd() && !CustomId_member->value.IsNull()) CustomId = CustomId_member->value.GetString();

                return true;
            }
        };

        struct UserAccountInfo : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UserAccountInfo,"{7700f497-2c68-551f-96d1-127cbf5ee08c}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string PlayFabId;
            time_t Created;
            AZStd::string Username;
            UserTitleInfo* TitleInfo;
            UserPrivateAccountInfo* PrivateInfo;
            UserFacebookInfo* FacebookInfo;
            UserSteamInfo* SteamInfo;
            UserGameCenterInfo* GameCenterInfo;
            UserIosDeviceInfo* IosDeviceInfo;
            UserAndroidDeviceInfo* AndroidDeviceInfo;
            UserKongregateInfo* KongregateInfo;
            UserTwitchInfo* TwitchInfo;
            UserPsnInfo* PsnInfo;
            UserGoogleInfo* GoogleInfo;
            UserXboxInfo* XboxInfo;
            UserCustomIdInfo* CustomIdInfo;

            UserAccountInfo() :
                PlayFabBaseModel(),
                PlayFabId(),
                Created(0),
                Username(),
                TitleInfo(nullptr),
                PrivateInfo(nullptr),
                FacebookInfo(nullptr),
                SteamInfo(nullptr),
                GameCenterInfo(nullptr),
                IosDeviceInfo(nullptr),
                AndroidDeviceInfo(nullptr),
                KongregateInfo(nullptr),
                TwitchInfo(nullptr),
                PsnInfo(nullptr),
                GoogleInfo(nullptr),
                XboxInfo(nullptr),
                CustomIdInfo(nullptr)
            {}

            UserAccountInfo(const UserAccountInfo& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Created(src.Created),
                Username(src.Username),
                TitleInfo(src.TitleInfo ? new UserTitleInfo(*src.TitleInfo) : nullptr),
                PrivateInfo(src.PrivateInfo ? new UserPrivateAccountInfo(*src.PrivateInfo) : nullptr),
                FacebookInfo(src.FacebookInfo ? new UserFacebookInfo(*src.FacebookInfo) : nullptr),
                SteamInfo(src.SteamInfo ? new UserSteamInfo(*src.SteamInfo) : nullptr),
                GameCenterInfo(src.GameCenterInfo ? new UserGameCenterInfo(*src.GameCenterInfo) : nullptr),
                IosDeviceInfo(src.IosDeviceInfo ? new UserIosDeviceInfo(*src.IosDeviceInfo) : nullptr),
                AndroidDeviceInfo(src.AndroidDeviceInfo ? new UserAndroidDeviceInfo(*src.AndroidDeviceInfo) : nullptr),
                KongregateInfo(src.KongregateInfo ? new UserKongregateInfo(*src.KongregateInfo) : nullptr),
                TwitchInfo(src.TwitchInfo ? new UserTwitchInfo(*src.TwitchInfo) : nullptr),
                PsnInfo(src.PsnInfo ? new UserPsnInfo(*src.PsnInfo) : nullptr),
                GoogleInfo(src.GoogleInfo ? new UserGoogleInfo(*src.GoogleInfo) : nullptr),
                XboxInfo(src.XboxInfo ? new UserXboxInfo(*src.XboxInfo) : nullptr),
                CustomIdInfo(src.CustomIdInfo ? new UserCustomIdInfo(*src.CustomIdInfo) : nullptr)
            {}

            UserAccountInfo(const rapidjson::Value& obj) : UserAccountInfo()
            {
                readFromValue(obj);
            }

            ~UserAccountInfo()
            {
                if (TitleInfo != nullptr) delete TitleInfo;
                if (PrivateInfo != nullptr) delete PrivateInfo;
                if (FacebookInfo != nullptr) delete FacebookInfo;
                if (SteamInfo != nullptr) delete SteamInfo;
                if (GameCenterInfo != nullptr) delete GameCenterInfo;
                if (IosDeviceInfo != nullptr) delete IosDeviceInfo;
                if (AndroidDeviceInfo != nullptr) delete AndroidDeviceInfo;
                if (KongregateInfo != nullptr) delete KongregateInfo;
                if (TwitchInfo != nullptr) delete TwitchInfo;
                if (PsnInfo != nullptr) delete PsnInfo;
                if (GoogleInfo != nullptr) delete GoogleInfo;
                if (XboxInfo != nullptr) delete XboxInfo;
                if (CustomIdInfo != nullptr) delete CustomIdInfo;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.String("Created");
                writeDatetime(Created, writer);
                if (Username.length() > 0) {
                    writer.String("Username");
                    writer.String(Username.c_str());
                }
                if (TitleInfo != nullptr) {
                    writer.String("TitleInfo");
                    TitleInfo->writeJSON(writer);
                }
                if (PrivateInfo != nullptr) {
                    writer.String("PrivateInfo");
                    PrivateInfo->writeJSON(writer);
                }
                if (FacebookInfo != nullptr) {
                    writer.String("FacebookInfo");
                    FacebookInfo->writeJSON(writer);
                }
                if (SteamInfo != nullptr) {
                    writer.String("SteamInfo");
                    SteamInfo->writeJSON(writer);
                }
                if (GameCenterInfo != nullptr) {
                    writer.String("GameCenterInfo");
                    GameCenterInfo->writeJSON(writer);
                }
                if (IosDeviceInfo != nullptr) {
                    writer.String("IosDeviceInfo");
                    IosDeviceInfo->writeJSON(writer);
                }
                if (AndroidDeviceInfo != nullptr) {
                    writer.String("AndroidDeviceInfo");
                    AndroidDeviceInfo->writeJSON(writer);
                }
                if (KongregateInfo != nullptr) {
                    writer.String("KongregateInfo");
                    KongregateInfo->writeJSON(writer);
                }
                if (TwitchInfo != nullptr) {
                    writer.String("TwitchInfo");
                    TwitchInfo->writeJSON(writer);
                }
                if (PsnInfo != nullptr) {
                    writer.String("PsnInfo");
                    PsnInfo->writeJSON(writer);
                }
                if (GoogleInfo != nullptr) {
                    writer.String("GoogleInfo");
                    GoogleInfo->writeJSON(writer);
                }
                if (XboxInfo != nullptr) {
                    writer.String("XboxInfo");
                    XboxInfo->writeJSON(writer);
                }
                if (CustomIdInfo != nullptr) {
                    writer.String("CustomIdInfo");
                    CustomIdInfo->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
                if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
                const Value::ConstMemberIterator TitleInfo_member = obj.FindMember("TitleInfo");
                if (TitleInfo_member != obj.MemberEnd() && !TitleInfo_member->value.IsNull()) TitleInfo = new UserTitleInfo(TitleInfo_member->value);
                const Value::ConstMemberIterator PrivateInfo_member = obj.FindMember("PrivateInfo");
                if (PrivateInfo_member != obj.MemberEnd() && !PrivateInfo_member->value.IsNull()) PrivateInfo = new UserPrivateAccountInfo(PrivateInfo_member->value);
                const Value::ConstMemberIterator FacebookInfo_member = obj.FindMember("FacebookInfo");
                if (FacebookInfo_member != obj.MemberEnd() && !FacebookInfo_member->value.IsNull()) FacebookInfo = new UserFacebookInfo(FacebookInfo_member->value);
                const Value::ConstMemberIterator SteamInfo_member = obj.FindMember("SteamInfo");
                if (SteamInfo_member != obj.MemberEnd() && !SteamInfo_member->value.IsNull()) SteamInfo = new UserSteamInfo(SteamInfo_member->value);
                const Value::ConstMemberIterator GameCenterInfo_member = obj.FindMember("GameCenterInfo");
                if (GameCenterInfo_member != obj.MemberEnd() && !GameCenterInfo_member->value.IsNull()) GameCenterInfo = new UserGameCenterInfo(GameCenterInfo_member->value);
                const Value::ConstMemberIterator IosDeviceInfo_member = obj.FindMember("IosDeviceInfo");
                if (IosDeviceInfo_member != obj.MemberEnd() && !IosDeviceInfo_member->value.IsNull()) IosDeviceInfo = new UserIosDeviceInfo(IosDeviceInfo_member->value);
                const Value::ConstMemberIterator AndroidDeviceInfo_member = obj.FindMember("AndroidDeviceInfo");
                if (AndroidDeviceInfo_member != obj.MemberEnd() && !AndroidDeviceInfo_member->value.IsNull()) AndroidDeviceInfo = new UserAndroidDeviceInfo(AndroidDeviceInfo_member->value);
                const Value::ConstMemberIterator KongregateInfo_member = obj.FindMember("KongregateInfo");
                if (KongregateInfo_member != obj.MemberEnd() && !KongregateInfo_member->value.IsNull()) KongregateInfo = new UserKongregateInfo(KongregateInfo_member->value);
                const Value::ConstMemberIterator TwitchInfo_member = obj.FindMember("TwitchInfo");
                if (TwitchInfo_member != obj.MemberEnd() && !TwitchInfo_member->value.IsNull()) TwitchInfo = new UserTwitchInfo(TwitchInfo_member->value);
                const Value::ConstMemberIterator PsnInfo_member = obj.FindMember("PsnInfo");
                if (PsnInfo_member != obj.MemberEnd() && !PsnInfo_member->value.IsNull()) PsnInfo = new UserPsnInfo(PsnInfo_member->value);
                const Value::ConstMemberIterator GoogleInfo_member = obj.FindMember("GoogleInfo");
                if (GoogleInfo_member != obj.MemberEnd() && !GoogleInfo_member->value.IsNull()) GoogleInfo = new UserGoogleInfo(GoogleInfo_member->value);
                const Value::ConstMemberIterator XboxInfo_member = obj.FindMember("XboxInfo");
                if (XboxInfo_member != obj.MemberEnd() && !XboxInfo_member->value.IsNull()) XboxInfo = new UserXboxInfo(XboxInfo_member->value);
                const Value::ConstMemberIterator CustomIdInfo_member = obj.FindMember("CustomIdInfo");
                if (CustomIdInfo_member != obj.MemberEnd() && !CustomIdInfo_member->value.IsNull()) CustomIdInfo = new UserCustomIdInfo(CustomIdInfo_member->value);

                return true;
            }
        };

        struct GetAccountInfoResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetAccountInfoResult,"{c67a9305-ab84-57d6-8d4a-3581032c0c73}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            UserAccountInfo* AccountInfo;

            GetAccountInfoResult() :
                PlayFabBaseModel(),
                AccountInfo(nullptr)
            {}

            GetAccountInfoResult(const GetAccountInfoResult& src) :
                PlayFabBaseModel(),
                AccountInfo(src.AccountInfo ? new UserAccountInfo(*src.AccountInfo) : nullptr)
            {}

            GetAccountInfoResult(const rapidjson::Value& obj) : GetAccountInfoResult()
            {
                readFromValue(obj);
            }

            ~GetAccountInfoResult()
            {
                if (AccountInfo != nullptr) delete AccountInfo;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (AccountInfo != nullptr) {
                    writer.String("AccountInfo");
                    AccountInfo->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AccountInfo_member = obj.FindMember("AccountInfo");
                if (AccountInfo_member != obj.MemberEnd() && !AccountInfo_member->value.IsNull()) AccountInfo = new UserAccountInfo(AccountInfo_member->value);

                return true;
            }
        };

        struct GetCatalogItemsRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetCatalogItemsRequest,"{0f9fc6d3-10e8-5eee-af68-a187de458a43}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string CatalogVersion;

            GetCatalogItemsRequest() :
                PlayFabBaseModel(),
                CatalogVersion()
            {}

            GetCatalogItemsRequest(const GetCatalogItemsRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion)
            {}

            GetCatalogItemsRequest(const rapidjson::Value& obj) : GetCatalogItemsRequest()
            {
                readFromValue(obj);
            }

            ~GetCatalogItemsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();

                return true;
            }
        };

        struct GetCatalogItemsResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetCatalogItemsResult,"{f18554e6-db4d-571d-966c-6879320a4e68}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<CatalogItem> Catalog; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetCatalogItemsResult() :
                PlayFabBaseModel(),
                Catalog()
            {}

            GetCatalogItemsResult(const GetCatalogItemsResult& src) :
                PlayFabBaseModel(),
                Catalog(src.Catalog)
            {}

            GetCatalogItemsResult(const rapidjson::Value& obj) : GetCatalogItemsResult()
            {
                readFromValue(obj);
            }

            ~GetCatalogItemsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Catalog.empty()) {
                    writer.String("Catalog");
                    writer.StartArray();
                    for (auto iter = Catalog.begin(); iter != Catalog.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Catalog_member = obj.FindMember("Catalog");
                if (Catalog_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Catalog_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Catalog.push_back(CatalogItem(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetCharacterDataRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetCharacterDataRequest,"{5498b15f-980c-5fb3-aed8-f1d50dabe346}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string PlayFabId;
            AZStd::string CharacterId;
            AZStd::vector<AZStd::string> Keys; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            OptionalUint32 IfChangedFromDataVersion;

            GetCharacterDataRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                Keys(),
                IfChangedFromDataVersion()
            {}

            GetCharacterDataRequest(const GetCharacterDataRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                Keys(src.Keys),
                IfChangedFromDataVersion(src.IfChangedFromDataVersion)
            {}

            GetCharacterDataRequest(const rapidjson::Value& obj) : GetCharacterDataRequest()
            {
                readFromValue(obj);
            }

            ~GetCharacterDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.String("CharacterId");
                writer.String(CharacterId.c_str());
                if (!Keys.empty()) {
                    writer.String("Keys");
                    writer.StartArray();
                    for (auto iter = Keys.begin(); iter != Keys.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (IfChangedFromDataVersion.notNull()) {
                    writer.String("IfChangedFromDataVersion");
                    writer.Uint(IfChangedFromDataVersion);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
                if (Keys_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Keys_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Keys.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator IfChangedFromDataVersion_member = obj.FindMember("IfChangedFromDataVersion");
                if (IfChangedFromDataVersion_member != obj.MemberEnd() && !IfChangedFromDataVersion_member->value.IsNull()) IfChangedFromDataVersion = IfChangedFromDataVersion_member->value.GetUint();

                return true;
            }
        };

        enum UserDataPermission
        {
            UserDataPermissionPrivate,
            UserDataPermissionPublic
        };

        inline void writeUserDataPermissionEnumJSON(UserDataPermission enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case UserDataPermissionPrivate: writer.String("Private"); break;
            case UserDataPermissionPublic: writer.String("Public"); break;

            }
        }

        inline UserDataPermission readUserDataPermissionFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<UserDataPermission>(obj.GetInt());

            static std::map<const char *, UserDataPermission, PlayFabComboSdk::StringCompare> _UserDataPermissionMap;
            if (_UserDataPermissionMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _UserDataPermissionMap["Private"] = UserDataPermissionPrivate;
                _UserDataPermissionMap["Public"] = UserDataPermissionPublic;

            }

            auto output = _UserDataPermissionMap.find(obj.GetString());
            if (output != _UserDataPermissionMap.end())
                return output->second;

            return UserDataPermissionPrivate; // Basically critical fail
        }

        struct UserDataRecord : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UserDataRecord,"{ae30f93d-bdfa-56b7-abc0-9a4ed87d67bb}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string Value;
            time_t LastUpdated;
            Boxed<UserDataPermission> Permission;

            UserDataRecord() :
                PlayFabBaseModel(),
                Value(),
                LastUpdated(0),
                Permission()
            {}

            UserDataRecord(const UserDataRecord& src) :
                PlayFabBaseModel(),
                Value(src.Value),
                LastUpdated(src.LastUpdated),
                Permission(src.Permission)
            {}

            UserDataRecord(const rapidjson::Value& obj) : UserDataRecord()
            {
                readFromValue(obj);
            }

            ~UserDataRecord()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Value.length() > 0) {
                    writer.String("Value");
                    writer.String(Value.c_str());
                }
                writer.String("LastUpdated");
                writeDatetime(LastUpdated, writer);
                if (Permission.notNull()) {
                    writer.String("Permission");
                    writeUserDataPermissionEnumJSON(Permission, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
                if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetString();
                const Value::ConstMemberIterator LastUpdated_member = obj.FindMember("LastUpdated");
                if (LastUpdated_member != obj.MemberEnd() && !LastUpdated_member->value.IsNull()) LastUpdated = readDatetime(LastUpdated_member->value);
                const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
                if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

                return true;
            }
        };

        struct GetCharacterDataResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetCharacterDataResult,"{8af363c8-e91f-5727-a993-5b282b1fb750}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string CharacterId;
            AZStd::unordered_map<AZStd::string, UserDataRecord> Data;
            Uint32 DataVersion;

            GetCharacterDataResult() :
                PlayFabBaseModel(),
                CharacterId(),
                Data(),
                DataVersion(0)
            {}

            GetCharacterDataResult(const GetCharacterDataResult& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                Data(src.Data),
                DataVersion(src.DataVersion)
            {}

            GetCharacterDataResult(const rapidjson::Value& obj) : GetCharacterDataResult()
            {
                readFromValue(obj);
            }

            ~GetCharacterDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartObject();
                    for (auto iter = Data.begin(); iter != Data.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.String("DataVersion");
                writer.Uint(DataVersion);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
                        Data[iter->name.GetString()] = UserDataRecord(iter->value);
                    }
                }
                const Value::ConstMemberIterator DataVersion_member = obj.FindMember("DataVersion");
                if (DataVersion_member != obj.MemberEnd() && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();

                return true;
            }
        };

        struct GetCharacterInventoryRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetCharacterInventoryRequest,"{03a1e4a1-d944-5ae3-91d8-9f7a821427ad}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string CharacterId;
            AZStd::string CatalogVersion;

            GetCharacterInventoryRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                CatalogVersion()
            {}

            GetCharacterInventoryRequest(const GetCharacterInventoryRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CatalogVersion(src.CatalogVersion)
            {}

            GetCharacterInventoryRequest(const rapidjson::Value& obj) : GetCharacterInventoryRequest()
            {
                readFromValue(obj);
            }

            ~GetCharacterInventoryRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("CharacterId");
                writer.String(CharacterId.c_str());
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();

                return true;
            }
        };

        struct VirtualCurrencyRechargeTime : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::VirtualCurrencyRechargeTime,"{87de88e0-afd2-550b-abe0-cd9365534527}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            Int32 SecondsToRecharge;
            time_t RechargeTime;
            Int32 RechargeMax;

            VirtualCurrencyRechargeTime() :
                PlayFabBaseModel(),
                SecondsToRecharge(0),
                RechargeTime(0),
                RechargeMax(0)
            {}

            VirtualCurrencyRechargeTime(const VirtualCurrencyRechargeTime& src) :
                PlayFabBaseModel(),
                SecondsToRecharge(src.SecondsToRecharge),
                RechargeTime(src.RechargeTime),
                RechargeMax(src.RechargeMax)
            {}

            VirtualCurrencyRechargeTime(const rapidjson::Value& obj) : VirtualCurrencyRechargeTime()
            {
                readFromValue(obj);
            }

            ~VirtualCurrencyRechargeTime()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("SecondsToRecharge");
                writer.Int(SecondsToRecharge);
                writer.String("RechargeTime");
                writeDatetime(RechargeTime, writer);
                writer.String("RechargeMax");
                writer.Int(RechargeMax);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SecondsToRecharge_member = obj.FindMember("SecondsToRecharge");
                if (SecondsToRecharge_member != obj.MemberEnd() && !SecondsToRecharge_member->value.IsNull()) SecondsToRecharge = SecondsToRecharge_member->value.GetInt();
                const Value::ConstMemberIterator RechargeTime_member = obj.FindMember("RechargeTime");
                if (RechargeTime_member != obj.MemberEnd() && !RechargeTime_member->value.IsNull()) RechargeTime = readDatetime(RechargeTime_member->value);
                const Value::ConstMemberIterator RechargeMax_member = obj.FindMember("RechargeMax");
                if (RechargeMax_member != obj.MemberEnd() && !RechargeMax_member->value.IsNull()) RechargeMax = RechargeMax_member->value.GetInt();

                return true;
            }
        };

        struct GetCharacterInventoryResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetCharacterInventoryResult,"{5b115f56-8347-5da4-b0bd-fbe5f9112cd3}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string CharacterId;
            AZStd::vector<ItemInstance> Inventory; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::unordered_map<AZStd::string, Int32> VirtualCurrency;
            AZStd::unordered_map<AZStd::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            GetCharacterInventoryResult() :
                PlayFabBaseModel(),
                CharacterId(),
                Inventory(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            GetCharacterInventoryResult(const GetCharacterInventoryResult& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                Inventory(src.Inventory),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes)
            {}

            GetCharacterInventoryResult(const rapidjson::Value& obj) : GetCharacterInventoryResult()
            {
                readFromValue(obj);
            }

            ~GetCharacterInventoryResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                if (!Inventory.empty()) {
                    writer.String("Inventory");
                    writer.StartArray();
                    for (auto iter = Inventory.begin(); iter != Inventory.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!VirtualCurrency.empty()) {
                    writer.String("VirtualCurrency");
                    writer.StartObject();
                    for (auto iter = VirtualCurrency.begin(); iter != VirtualCurrency.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.Int(iter->second);
                    }
                    writer.EndObject();
                }
                if (!VirtualCurrencyRechargeTimes.empty()) {
                    writer.String("VirtualCurrencyRechargeTimes");
                    writer.StartObject();
                    for (auto iter = VirtualCurrencyRechargeTimes.begin(); iter != VirtualCurrencyRechargeTimes.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator Inventory_member = obj.FindMember("Inventory");
                if (Inventory_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Inventory_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Inventory.push_back(ItemInstance(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrency_member->value.MemberBegin(); iter != VirtualCurrency_member->value.MemberEnd(); ++iter) {
                        VirtualCurrency[iter->name.GetString()] = iter->value.GetInt();
                    }
                }
                const Value::ConstMemberIterator VirtualCurrencyRechargeTimes_member = obj.FindMember("VirtualCurrencyRechargeTimes");
                if (VirtualCurrencyRechargeTimes_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrencyRechargeTimes_member->value.MemberBegin(); iter != VirtualCurrencyRechargeTimes_member->value.MemberEnd(); ++iter) {
                        VirtualCurrencyRechargeTimes[iter->name.GetString()] = VirtualCurrencyRechargeTime(iter->value);
                    }
                }

                return true;
            }
        };

        struct GetCharacterLeaderboardRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetCharacterLeaderboardRequest,"{f6a7a81c-47f3-507f-b509-61bb1302dda3}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string CharacterType;
            AZStd::string StatisticName;
            Int32 StartPosition;
            OptionalInt32 MaxResultsCount;

            GetCharacterLeaderboardRequest() :
                PlayFabBaseModel(),
                CharacterType(),
                StatisticName(),
                StartPosition(0),
                MaxResultsCount()
            {}

            GetCharacterLeaderboardRequest(const GetCharacterLeaderboardRequest& src) :
                PlayFabBaseModel(),
                CharacterType(src.CharacterType),
                StatisticName(src.StatisticName),
                StartPosition(src.StartPosition),
                MaxResultsCount(src.MaxResultsCount)
            {}

            GetCharacterLeaderboardRequest(const rapidjson::Value& obj) : GetCharacterLeaderboardRequest()
            {
                readFromValue(obj);
            }

            ~GetCharacterLeaderboardRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CharacterType.length() > 0) {
                    writer.String("CharacterType");
                    writer.String(CharacterType.c_str());
                }
                writer.String("StatisticName");
                writer.String(StatisticName.c_str());
                writer.String("StartPosition");
                writer.Int(StartPosition);
                if (MaxResultsCount.notNull()) {
                    writer.String("MaxResultsCount");
                    writer.Int(MaxResultsCount);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
                if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator StartPosition_member = obj.FindMember("StartPosition");
                if (StartPosition_member != obj.MemberEnd() && !StartPosition_member->value.IsNull()) StartPosition = StartPosition_member->value.GetInt();
                const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
                if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();

                return true;
            }
        };

        struct GetCharacterLeaderboardResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetCharacterLeaderboardResult,"{f7b874ba-0cf8-5b20-b541-03097f792abc}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<CharacterLeaderboardEntry> Leaderboard; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetCharacterLeaderboardResult() :
                PlayFabBaseModel(),
                Leaderboard()
            {}

            GetCharacterLeaderboardResult(const GetCharacterLeaderboardResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard)
            {}

            GetCharacterLeaderboardResult(const rapidjson::Value& obj) : GetCharacterLeaderboardResult()
            {
                readFromValue(obj);
            }

            ~GetCharacterLeaderboardResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Leaderboard.empty()) {
                    writer.String("Leaderboard");
                    writer.StartArray();
                    for (auto iter = Leaderboard.begin(); iter != Leaderboard.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Leaderboard_member = obj.FindMember("Leaderboard");
                if (Leaderboard_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Leaderboard_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Leaderboard.push_back(CharacterLeaderboardEntry(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetCharacterStatisticsRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetCharacterStatisticsRequest,"{966f2824-4a5c-57da-acf4-f787532aa048}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string CharacterId;

            GetCharacterStatisticsRequest() :
                PlayFabBaseModel(),
                CharacterId()
            {}

            GetCharacterStatisticsRequest(const GetCharacterStatisticsRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId)
            {}

            GetCharacterStatisticsRequest(const rapidjson::Value& obj) : GetCharacterStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~GetCharacterStatisticsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("CharacterId");
                writer.String(CharacterId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

                return true;
            }
        };

        struct GetCharacterStatisticsResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetCharacterStatisticsResult,"{3b5eac8f-2b0b-5df5-afa5-d75868e5f2fc}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::unordered_map<AZStd::string, Int32> CharacterStatistics;

            GetCharacterStatisticsResult() :
                PlayFabBaseModel(),
                CharacterStatistics()
            {}

            GetCharacterStatisticsResult(const GetCharacterStatisticsResult& src) :
                PlayFabBaseModel(),
                CharacterStatistics(src.CharacterStatistics)
            {}

            GetCharacterStatisticsResult(const rapidjson::Value& obj) : GetCharacterStatisticsResult()
            {
                readFromValue(obj);
            }

            ~GetCharacterStatisticsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!CharacterStatistics.empty()) {
                    writer.String("CharacterStatistics");
                    writer.StartObject();
                    for (auto iter = CharacterStatistics.begin(); iter != CharacterStatistics.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.Int(iter->second);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterStatistics_member = obj.FindMember("CharacterStatistics");
                if (CharacterStatistics_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = CharacterStatistics_member->value.MemberBegin(); iter != CharacterStatistics_member->value.MemberEnd(); ++iter) {
                        CharacterStatistics[iter->name.GetString()] = iter->value.GetInt();
                    }
                }

                return true;
            }
        };

        struct GetContentDownloadUrlRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetContentDownloadUrlRequest,"{a18e7d68-a277-5990-beee-19aec3961410}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string Key;
            AZStd::string HttpMethod;
            OptionalBool ThruCDN;

            GetContentDownloadUrlRequest() :
                PlayFabBaseModel(),
                Key(),
                HttpMethod(),
                ThruCDN()
            {}

            GetContentDownloadUrlRequest(const GetContentDownloadUrlRequest& src) :
                PlayFabBaseModel(),
                Key(src.Key),
                HttpMethod(src.HttpMethod),
                ThruCDN(src.ThruCDN)
            {}

            GetContentDownloadUrlRequest(const rapidjson::Value& obj) : GetContentDownloadUrlRequest()
            {
                readFromValue(obj);
            }

            ~GetContentDownloadUrlRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Key");
                writer.String(Key.c_str());
                if (HttpMethod.length() > 0) {
                    writer.String("HttpMethod");
                    writer.String(HttpMethod.c_str());
                }
                if (ThruCDN.notNull()) {
                    writer.String("ThruCDN");
                    writer.Bool(ThruCDN);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
                if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
                const Value::ConstMemberIterator HttpMethod_member = obj.FindMember("HttpMethod");
                if (HttpMethod_member != obj.MemberEnd() && !HttpMethod_member->value.IsNull()) HttpMethod = HttpMethod_member->value.GetString();
                const Value::ConstMemberIterator ThruCDN_member = obj.FindMember("ThruCDN");
                if (ThruCDN_member != obj.MemberEnd() && !ThruCDN_member->value.IsNull()) ThruCDN = ThruCDN_member->value.GetBool();

                return true;
            }
        };

        struct GetContentDownloadUrlResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetContentDownloadUrlResult,"{285f0f28-41c7-5fed-aa55-6fe27f3e4356}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string URL;

            GetContentDownloadUrlResult() :
                PlayFabBaseModel(),
                URL()
            {}

            GetContentDownloadUrlResult(const GetContentDownloadUrlResult& src) :
                PlayFabBaseModel(),
                URL(src.URL)
            {}

            GetContentDownloadUrlResult(const rapidjson::Value& obj) : GetContentDownloadUrlResult()
            {
                readFromValue(obj);
            }

            ~GetContentDownloadUrlResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (URL.length() > 0) {
                    writer.String("URL");
                    writer.String(URL.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator URL_member = obj.FindMember("URL");
                if (URL_member != obj.MemberEnd() && !URL_member->value.IsNull()) URL = URL_member->value.GetString();

                return true;
            }
        };

        struct PlayerProfileViewConstraints : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::PlayerProfileViewConstraints,"{7ab0bd24-0fb0-5b61-85e5-3a30f745f6fe}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            bool ShowDisplayName;
            bool ShowCreated;
            bool ShowOrigination;
            bool ShowLastLogin;
            bool ShowBannedUntil;
            bool ShowStatistics;
            bool ShowCampaignAttributions;
            bool ShowPushNotificationRegistrations;
            bool ShowLinkedAccounts;
            bool ShowTotalValueToDateInUsd;
            bool ShowValuesToDate;
            bool ShowTags;
            bool ShowLocations;
            bool ShowAvatarUrl;

            PlayerProfileViewConstraints() :
                PlayFabBaseModel(),
                ShowDisplayName(false),
                ShowCreated(false),
                ShowOrigination(false),
                ShowLastLogin(false),
                ShowBannedUntil(false),
                ShowStatistics(false),
                ShowCampaignAttributions(false),
                ShowPushNotificationRegistrations(false),
                ShowLinkedAccounts(false),
                ShowTotalValueToDateInUsd(false),
                ShowValuesToDate(false),
                ShowTags(false),
                ShowLocations(false),
                ShowAvatarUrl(false)
            {}

            PlayerProfileViewConstraints(const PlayerProfileViewConstraints& src) :
                PlayFabBaseModel(),
                ShowDisplayName(src.ShowDisplayName),
                ShowCreated(src.ShowCreated),
                ShowOrigination(src.ShowOrigination),
                ShowLastLogin(src.ShowLastLogin),
                ShowBannedUntil(src.ShowBannedUntil),
                ShowStatistics(src.ShowStatistics),
                ShowCampaignAttributions(src.ShowCampaignAttributions),
                ShowPushNotificationRegistrations(src.ShowPushNotificationRegistrations),
                ShowLinkedAccounts(src.ShowLinkedAccounts),
                ShowTotalValueToDateInUsd(src.ShowTotalValueToDateInUsd),
                ShowValuesToDate(src.ShowValuesToDate),
                ShowTags(src.ShowTags),
                ShowLocations(src.ShowLocations),
                ShowAvatarUrl(src.ShowAvatarUrl)
            {}

            PlayerProfileViewConstraints(const rapidjson::Value& obj) : PlayerProfileViewConstraints()
            {
                readFromValue(obj);
            }

            ~PlayerProfileViewConstraints()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ShowDisplayName");
                writer.Bool(ShowDisplayName);
                writer.String("ShowCreated");
                writer.Bool(ShowCreated);
                writer.String("ShowOrigination");
                writer.Bool(ShowOrigination);
                writer.String("ShowLastLogin");
                writer.Bool(ShowLastLogin);
                writer.String("ShowBannedUntil");
                writer.Bool(ShowBannedUntil);
                writer.String("ShowStatistics");
                writer.Bool(ShowStatistics);
                writer.String("ShowCampaignAttributions");
                writer.Bool(ShowCampaignAttributions);
                writer.String("ShowPushNotificationRegistrations");
                writer.Bool(ShowPushNotificationRegistrations);
                writer.String("ShowLinkedAccounts");
                writer.Bool(ShowLinkedAccounts);
                writer.String("ShowTotalValueToDateInUsd");
                writer.Bool(ShowTotalValueToDateInUsd);
                writer.String("ShowValuesToDate");
                writer.Bool(ShowValuesToDate);
                writer.String("ShowTags");
                writer.Bool(ShowTags);
                writer.String("ShowLocations");
                writer.Bool(ShowLocations);
                writer.String("ShowAvatarUrl");
                writer.Bool(ShowAvatarUrl);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ShowDisplayName_member = obj.FindMember("ShowDisplayName");
                if (ShowDisplayName_member != obj.MemberEnd() && !ShowDisplayName_member->value.IsNull()) ShowDisplayName = ShowDisplayName_member->value.GetBool();
                const Value::ConstMemberIterator ShowCreated_member = obj.FindMember("ShowCreated");
                if (ShowCreated_member != obj.MemberEnd() && !ShowCreated_member->value.IsNull()) ShowCreated = ShowCreated_member->value.GetBool();
                const Value::ConstMemberIterator ShowOrigination_member = obj.FindMember("ShowOrigination");
                if (ShowOrigination_member != obj.MemberEnd() && !ShowOrigination_member->value.IsNull()) ShowOrigination = ShowOrigination_member->value.GetBool();
                const Value::ConstMemberIterator ShowLastLogin_member = obj.FindMember("ShowLastLogin");
                if (ShowLastLogin_member != obj.MemberEnd() && !ShowLastLogin_member->value.IsNull()) ShowLastLogin = ShowLastLogin_member->value.GetBool();
                const Value::ConstMemberIterator ShowBannedUntil_member = obj.FindMember("ShowBannedUntil");
                if (ShowBannedUntil_member != obj.MemberEnd() && !ShowBannedUntil_member->value.IsNull()) ShowBannedUntil = ShowBannedUntil_member->value.GetBool();
                const Value::ConstMemberIterator ShowStatistics_member = obj.FindMember("ShowStatistics");
                if (ShowStatistics_member != obj.MemberEnd() && !ShowStatistics_member->value.IsNull()) ShowStatistics = ShowStatistics_member->value.GetBool();
                const Value::ConstMemberIterator ShowCampaignAttributions_member = obj.FindMember("ShowCampaignAttributions");
                if (ShowCampaignAttributions_member != obj.MemberEnd() && !ShowCampaignAttributions_member->value.IsNull()) ShowCampaignAttributions = ShowCampaignAttributions_member->value.GetBool();
                const Value::ConstMemberIterator ShowPushNotificationRegistrations_member = obj.FindMember("ShowPushNotificationRegistrations");
                if (ShowPushNotificationRegistrations_member != obj.MemberEnd() && !ShowPushNotificationRegistrations_member->value.IsNull()) ShowPushNotificationRegistrations = ShowPushNotificationRegistrations_member->value.GetBool();
                const Value::ConstMemberIterator ShowLinkedAccounts_member = obj.FindMember("ShowLinkedAccounts");
                if (ShowLinkedAccounts_member != obj.MemberEnd() && !ShowLinkedAccounts_member->value.IsNull()) ShowLinkedAccounts = ShowLinkedAccounts_member->value.GetBool();
                const Value::ConstMemberIterator ShowTotalValueToDateInUsd_member = obj.FindMember("ShowTotalValueToDateInUsd");
                if (ShowTotalValueToDateInUsd_member != obj.MemberEnd() && !ShowTotalValueToDateInUsd_member->value.IsNull()) ShowTotalValueToDateInUsd = ShowTotalValueToDateInUsd_member->value.GetBool();
                const Value::ConstMemberIterator ShowValuesToDate_member = obj.FindMember("ShowValuesToDate");
                if (ShowValuesToDate_member != obj.MemberEnd() && !ShowValuesToDate_member->value.IsNull()) ShowValuesToDate = ShowValuesToDate_member->value.GetBool();
                const Value::ConstMemberIterator ShowTags_member = obj.FindMember("ShowTags");
                if (ShowTags_member != obj.MemberEnd() && !ShowTags_member->value.IsNull()) ShowTags = ShowTags_member->value.GetBool();
                const Value::ConstMemberIterator ShowLocations_member = obj.FindMember("ShowLocations");
                if (ShowLocations_member != obj.MemberEnd() && !ShowLocations_member->value.IsNull()) ShowLocations = ShowLocations_member->value.GetBool();
                const Value::ConstMemberIterator ShowAvatarUrl_member = obj.FindMember("ShowAvatarUrl");
                if (ShowAvatarUrl_member != obj.MemberEnd() && !ShowAvatarUrl_member->value.IsNull()) ShowAvatarUrl = ShowAvatarUrl_member->value.GetBool();

                return true;
            }
        };

        struct GetFriendLeaderboardAroundPlayerRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetFriendLeaderboardAroundPlayerRequest,"{36713efd-d029-5630-98f3-592e1b9ea41d}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string StatisticName;
            OptionalInt32 MaxResultsCount;
            AZStd::string PlayFabId;
            OptionalBool IncludeSteamFriends;
            OptionalBool IncludeFacebookFriends;
            OptionalInt32 Version;
            PlayerProfileViewConstraints* ProfileConstraints;

            GetFriendLeaderboardAroundPlayerRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                MaxResultsCount(),
                PlayFabId(),
                IncludeSteamFriends(),
                IncludeFacebookFriends(),
                Version(),
                ProfileConstraints(nullptr)
            {}

            GetFriendLeaderboardAroundPlayerRequest(const GetFriendLeaderboardAroundPlayerRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                MaxResultsCount(src.MaxResultsCount),
                PlayFabId(src.PlayFabId),
                IncludeSteamFriends(src.IncludeSteamFriends),
                IncludeFacebookFriends(src.IncludeFacebookFriends),
                Version(src.Version),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : nullptr)
            {}

            GetFriendLeaderboardAroundPlayerRequest(const rapidjson::Value& obj) : GetFriendLeaderboardAroundPlayerRequest()
            {
                readFromValue(obj);
            }

            ~GetFriendLeaderboardAroundPlayerRequest()
            {
                if (ProfileConstraints != nullptr) delete ProfileConstraints;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("StatisticName");
                writer.String(StatisticName.c_str());
                if (MaxResultsCount.notNull()) {
                    writer.String("MaxResultsCount");
                    writer.Int(MaxResultsCount);
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                if (IncludeSteamFriends.notNull()) {
                    writer.String("IncludeSteamFriends");
                    writer.Bool(IncludeSteamFriends);
                }
                if (IncludeFacebookFriends.notNull()) {
                    writer.String("IncludeFacebookFriends");
                    writer.Bool(IncludeFacebookFriends);
                }
                if (Version.notNull()) {
                    writer.String("Version");
                    writer.Int(Version);
                }
                if (ProfileConstraints != nullptr) {
                    writer.String("ProfileConstraints");
                    ProfileConstraints->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
                if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator IncludeSteamFriends_member = obj.FindMember("IncludeSteamFriends");
                if (IncludeSteamFriends_member != obj.MemberEnd() && !IncludeSteamFriends_member->value.IsNull()) IncludeSteamFriends = IncludeSteamFriends_member->value.GetBool();
                const Value::ConstMemberIterator IncludeFacebookFriends_member = obj.FindMember("IncludeFacebookFriends");
                if (IncludeFacebookFriends_member != obj.MemberEnd() && !IncludeFacebookFriends_member->value.IsNull()) IncludeFacebookFriends = IncludeFacebookFriends_member->value.GetBool();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
                if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);

                return true;
            }
        };

        struct PlayerLeaderboardEntry : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::PlayerLeaderboardEntry,"{70467536-eab2-5c26-b4dd-e294a3d1557f}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string PlayFabId;
            AZStd::string DisplayName;
            Int32 StatValue;
            Int32 Position;
            PlayerProfileModel* Profile;

            PlayerLeaderboardEntry() :
                PlayFabBaseModel(),
                PlayFabId(),
                DisplayName(),
                StatValue(0),
                Position(0),
                Profile(nullptr)
            {}

            PlayerLeaderboardEntry(const PlayerLeaderboardEntry& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                DisplayName(src.DisplayName),
                StatValue(src.StatValue),
                Position(src.Position),
                Profile(src.Profile ? new PlayerProfileModel(*src.Profile) : nullptr)
            {}

            PlayerLeaderboardEntry(const rapidjson::Value& obj) : PlayerLeaderboardEntry()
            {
                readFromValue(obj);
            }

            ~PlayerLeaderboardEntry()
            {
                if (Profile != nullptr) delete Profile;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                if (DisplayName.length() > 0) {
                    writer.String("DisplayName");
                    writer.String(DisplayName.c_str());
                }
                writer.String("StatValue");
                writer.Int(StatValue);
                writer.String("Position");
                writer.Int(Position);
                if (Profile != nullptr) {
                    writer.String("Profile");
                    Profile->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator StatValue_member = obj.FindMember("StatValue");
                if (StatValue_member != obj.MemberEnd() && !StatValue_member->value.IsNull()) StatValue = StatValue_member->value.GetInt();
                const Value::ConstMemberIterator Position_member = obj.FindMember("Position");
                if (Position_member != obj.MemberEnd() && !Position_member->value.IsNull()) Position = Position_member->value.GetInt();
                const Value::ConstMemberIterator Profile_member = obj.FindMember("Profile");
                if (Profile_member != obj.MemberEnd() && !Profile_member->value.IsNull()) Profile = new PlayerProfileModel(Profile_member->value);

                return true;
            }
        };

        struct GetFriendLeaderboardAroundPlayerResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetFriendLeaderboardAroundPlayerResult,"{b55e0066-6133-59a7-b840-b4f4556a3c37}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<PlayerLeaderboardEntry> Leaderboard; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            Int32 Version;
            OptionalTime NextReset;

            GetFriendLeaderboardAroundPlayerResult() :
                PlayFabBaseModel(),
                Leaderboard(),
                Version(0),
                NextReset()
            {}

            GetFriendLeaderboardAroundPlayerResult(const GetFriendLeaderboardAroundPlayerResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard),
                Version(src.Version),
                NextReset(src.NextReset)
            {}

            GetFriendLeaderboardAroundPlayerResult(const rapidjson::Value& obj) : GetFriendLeaderboardAroundPlayerResult()
            {
                readFromValue(obj);
            }

            ~GetFriendLeaderboardAroundPlayerResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Leaderboard.empty()) {
                    writer.String("Leaderboard");
                    writer.StartArray();
                    for (auto iter = Leaderboard.begin(); iter != Leaderboard.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.String("Version");
                writer.Int(Version);
                if (NextReset.notNull()) {
                    writer.String("NextReset");
                    writeDatetime(NextReset, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Leaderboard_member = obj.FindMember("Leaderboard");
                if (Leaderboard_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Leaderboard_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Leaderboard.push_back(PlayerLeaderboardEntry(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator NextReset_member = obj.FindMember("NextReset");
                if (NextReset_member != obj.MemberEnd() && !NextReset_member->value.IsNull()) NextReset = readDatetime(NextReset_member->value);

                return true;
            }
        };

        struct GetFriendLeaderboardRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetFriendLeaderboardRequest,"{d6eabfa2-a295-5848-8b6f-86e0e1de5070}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string StatisticName;
            Int32 StartPosition;
            OptionalInt32 MaxResultsCount;
            OptionalBool IncludeSteamFriends;
            OptionalBool IncludeFacebookFriends;
            OptionalInt32 Version;
            PlayerProfileViewConstraints* ProfileConstraints;

            GetFriendLeaderboardRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                StartPosition(0),
                MaxResultsCount(),
                IncludeSteamFriends(),
                IncludeFacebookFriends(),
                Version(),
                ProfileConstraints(nullptr)
            {}

            GetFriendLeaderboardRequest(const GetFriendLeaderboardRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                StartPosition(src.StartPosition),
                MaxResultsCount(src.MaxResultsCount),
                IncludeSteamFriends(src.IncludeSteamFriends),
                IncludeFacebookFriends(src.IncludeFacebookFriends),
                Version(src.Version),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : nullptr)
            {}

            GetFriendLeaderboardRequest(const rapidjson::Value& obj) : GetFriendLeaderboardRequest()
            {
                readFromValue(obj);
            }

            ~GetFriendLeaderboardRequest()
            {
                if (ProfileConstraints != nullptr) delete ProfileConstraints;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("StatisticName");
                writer.String(StatisticName.c_str());
                writer.String("StartPosition");
                writer.Int(StartPosition);
                if (MaxResultsCount.notNull()) {
                    writer.String("MaxResultsCount");
                    writer.Int(MaxResultsCount);
                }
                if (IncludeSteamFriends.notNull()) {
                    writer.String("IncludeSteamFriends");
                    writer.Bool(IncludeSteamFriends);
                }
                if (IncludeFacebookFriends.notNull()) {
                    writer.String("IncludeFacebookFriends");
                    writer.Bool(IncludeFacebookFriends);
                }
                if (Version.notNull()) {
                    writer.String("Version");
                    writer.Int(Version);
                }
                if (ProfileConstraints != nullptr) {
                    writer.String("ProfileConstraints");
                    ProfileConstraints->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator StartPosition_member = obj.FindMember("StartPosition");
                if (StartPosition_member != obj.MemberEnd() && !StartPosition_member->value.IsNull()) StartPosition = StartPosition_member->value.GetInt();
                const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
                if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();
                const Value::ConstMemberIterator IncludeSteamFriends_member = obj.FindMember("IncludeSteamFriends");
                if (IncludeSteamFriends_member != obj.MemberEnd() && !IncludeSteamFriends_member->value.IsNull()) IncludeSteamFriends = IncludeSteamFriends_member->value.GetBool();
                const Value::ConstMemberIterator IncludeFacebookFriends_member = obj.FindMember("IncludeFacebookFriends");
                if (IncludeFacebookFriends_member != obj.MemberEnd() && !IncludeFacebookFriends_member->value.IsNull()) IncludeFacebookFriends = IncludeFacebookFriends_member->value.GetBool();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
                if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);

                return true;
            }
        };

        struct GetFriendsListRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetFriendsListRequest,"{8a2e1afa-d7ed-5939-a22e-b1ff3b81cd81}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            OptionalBool IncludeSteamFriends;
            OptionalBool IncludeFacebookFriends;
            PlayerProfileViewConstraints* ProfileConstraints;

            GetFriendsListRequest() :
                PlayFabBaseModel(),
                IncludeSteamFriends(),
                IncludeFacebookFriends(),
                ProfileConstraints(nullptr)
            {}

            GetFriendsListRequest(const GetFriendsListRequest& src) :
                PlayFabBaseModel(),
                IncludeSteamFriends(src.IncludeSteamFriends),
                IncludeFacebookFriends(src.IncludeFacebookFriends),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : nullptr)
            {}

            GetFriendsListRequest(const rapidjson::Value& obj) : GetFriendsListRequest()
            {
                readFromValue(obj);
            }

            ~GetFriendsListRequest()
            {
                if (ProfileConstraints != nullptr) delete ProfileConstraints;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (IncludeSteamFriends.notNull()) {
                    writer.String("IncludeSteamFriends");
                    writer.Bool(IncludeSteamFriends);
                }
                if (IncludeFacebookFriends.notNull()) {
                    writer.String("IncludeFacebookFriends");
                    writer.Bool(IncludeFacebookFriends);
                }
                if (ProfileConstraints != nullptr) {
                    writer.String("ProfileConstraints");
                    ProfileConstraints->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator IncludeSteamFriends_member = obj.FindMember("IncludeSteamFriends");
                if (IncludeSteamFriends_member != obj.MemberEnd() && !IncludeSteamFriends_member->value.IsNull()) IncludeSteamFriends = IncludeSteamFriends_member->value.GetBool();
                const Value::ConstMemberIterator IncludeFacebookFriends_member = obj.FindMember("IncludeFacebookFriends");
                if (IncludeFacebookFriends_member != obj.MemberEnd() && !IncludeFacebookFriends_member->value.IsNull()) IncludeFacebookFriends = IncludeFacebookFriends_member->value.GetBool();
                const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
                if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);

                return true;
            }
        };

        struct GetFriendsListResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetFriendsListResult,"{75b166df-ecda-525d-a92f-664cb608037a}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<FriendInfo> Friends; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetFriendsListResult() :
                PlayFabBaseModel(),
                Friends()
            {}

            GetFriendsListResult(const GetFriendsListResult& src) :
                PlayFabBaseModel(),
                Friends(src.Friends)
            {}

            GetFriendsListResult(const rapidjson::Value& obj) : GetFriendsListResult()
            {
                readFromValue(obj);
            }

            ~GetFriendsListResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Friends.empty()) {
                    writer.String("Friends");
                    writer.StartArray();
                    for (auto iter = Friends.begin(); iter != Friends.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Friends_member = obj.FindMember("Friends");
                if (Friends_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Friends_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Friends.push_back(FriendInfo(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetLeaderboardAroundCharacterRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetLeaderboardAroundCharacterRequest,"{70664254-a92d-5d6f-9965-db681416ee7e}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string StatisticName;
            AZStd::string CharacterId;
            AZStd::string CharacterType;
            OptionalInt32 MaxResultsCount;

            GetLeaderboardAroundCharacterRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                CharacterId(),
                CharacterType(),
                MaxResultsCount()
            {}

            GetLeaderboardAroundCharacterRequest(const GetLeaderboardAroundCharacterRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                CharacterId(src.CharacterId),
                CharacterType(src.CharacterType),
                MaxResultsCount(src.MaxResultsCount)
            {}

            GetLeaderboardAroundCharacterRequest(const rapidjson::Value& obj) : GetLeaderboardAroundCharacterRequest()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardAroundCharacterRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("StatisticName");
                writer.String(StatisticName.c_str());
                writer.String("CharacterId");
                writer.String(CharacterId.c_str());
                if (CharacterType.length() > 0) {
                    writer.String("CharacterType");
                    writer.String(CharacterType.c_str());
                }
                if (MaxResultsCount.notNull()) {
                    writer.String("MaxResultsCount");
                    writer.Int(MaxResultsCount);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
                if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();
                const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
                if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();

                return true;
            }
        };

        struct GetLeaderboardAroundCharacterResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetLeaderboardAroundCharacterResult,"{4e21a2c4-80ed-584a-959b-4d80e328f118}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<CharacterLeaderboardEntry> Leaderboard; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetLeaderboardAroundCharacterResult() :
                PlayFabBaseModel(),
                Leaderboard()
            {}

            GetLeaderboardAroundCharacterResult(const GetLeaderboardAroundCharacterResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard)
            {}

            GetLeaderboardAroundCharacterResult(const rapidjson::Value& obj) : GetLeaderboardAroundCharacterResult()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardAroundCharacterResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Leaderboard.empty()) {
                    writer.String("Leaderboard");
                    writer.StartArray();
                    for (auto iter = Leaderboard.begin(); iter != Leaderboard.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Leaderboard_member = obj.FindMember("Leaderboard");
                if (Leaderboard_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Leaderboard_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Leaderboard.push_back(CharacterLeaderboardEntry(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetLeaderboardAroundPlayerRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetLeaderboardAroundPlayerRequest,"{38ccace5-2eeb-5c20-8351-5ce82e032f64}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string PlayFabId;
            AZStd::string StatisticName;
            OptionalInt32 MaxResultsCount;
            OptionalInt32 Version;
            PlayerProfileViewConstraints* ProfileConstraints;

            GetLeaderboardAroundPlayerRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                StatisticName(),
                MaxResultsCount(),
                Version(),
                ProfileConstraints(nullptr)
            {}

            GetLeaderboardAroundPlayerRequest(const GetLeaderboardAroundPlayerRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                StatisticName(src.StatisticName),
                MaxResultsCount(src.MaxResultsCount),
                Version(src.Version),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : nullptr)
            {}

            GetLeaderboardAroundPlayerRequest(const rapidjson::Value& obj) : GetLeaderboardAroundPlayerRequest()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardAroundPlayerRequest()
            {
                if (ProfileConstraints != nullptr) delete ProfileConstraints;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.String("StatisticName");
                writer.String(StatisticName.c_str());
                if (MaxResultsCount.notNull()) {
                    writer.String("MaxResultsCount");
                    writer.Int(MaxResultsCount);
                }
                if (Version.notNull()) {
                    writer.String("Version");
                    writer.Int(Version);
                }
                if (ProfileConstraints != nullptr) {
                    writer.String("ProfileConstraints");
                    ProfileConstraints->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
                if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
                if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);

                return true;
            }
        };

        struct GetLeaderboardAroundPlayerResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetLeaderboardAroundPlayerResult,"{8a41f7ba-576f-5d76-ab2d-817626d24c59}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<PlayerLeaderboardEntry> Leaderboard; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            Int32 Version;
            OptionalTime NextReset;

            GetLeaderboardAroundPlayerResult() :
                PlayFabBaseModel(),
                Leaderboard(),
                Version(0),
                NextReset()
            {}

            GetLeaderboardAroundPlayerResult(const GetLeaderboardAroundPlayerResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard),
                Version(src.Version),
                NextReset(src.NextReset)
            {}

            GetLeaderboardAroundPlayerResult(const rapidjson::Value& obj) : GetLeaderboardAroundPlayerResult()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardAroundPlayerResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Leaderboard.empty()) {
                    writer.String("Leaderboard");
                    writer.StartArray();
                    for (auto iter = Leaderboard.begin(); iter != Leaderboard.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.String("Version");
                writer.Int(Version);
                if (NextReset.notNull()) {
                    writer.String("NextReset");
                    writeDatetime(NextReset, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Leaderboard_member = obj.FindMember("Leaderboard");
                if (Leaderboard_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Leaderboard_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Leaderboard.push_back(PlayerLeaderboardEntry(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator NextReset_member = obj.FindMember("NextReset");
                if (NextReset_member != obj.MemberEnd() && !NextReset_member->value.IsNull()) NextReset = readDatetime(NextReset_member->value);

                return true;
            }
        };

        struct GetLeaderboardForUsersCharactersRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetLeaderboardForUsersCharactersRequest,"{4416f662-2a24-5932-bef4-4716c2c8f0e2}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string StatisticName;
            Int32 MaxResultsCount;

            GetLeaderboardForUsersCharactersRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                MaxResultsCount(0)
            {}

            GetLeaderboardForUsersCharactersRequest(const GetLeaderboardForUsersCharactersRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                MaxResultsCount(src.MaxResultsCount)
            {}

            GetLeaderboardForUsersCharactersRequest(const rapidjson::Value& obj) : GetLeaderboardForUsersCharactersRequest()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardForUsersCharactersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("StatisticName");
                writer.String(StatisticName.c_str());
                writer.String("MaxResultsCount");
                writer.Int(MaxResultsCount);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
                if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();

                return true;
            }
        };

        struct GetLeaderboardForUsersCharactersResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetLeaderboardForUsersCharactersResult,"{db497e09-3a94-5a7e-b894-3acb986e8b42}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<CharacterLeaderboardEntry> Leaderboard; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetLeaderboardForUsersCharactersResult() :
                PlayFabBaseModel(),
                Leaderboard()
            {}

            GetLeaderboardForUsersCharactersResult(const GetLeaderboardForUsersCharactersResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard)
            {}

            GetLeaderboardForUsersCharactersResult(const rapidjson::Value& obj) : GetLeaderboardForUsersCharactersResult()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardForUsersCharactersResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Leaderboard.empty()) {
                    writer.String("Leaderboard");
                    writer.StartArray();
                    for (auto iter = Leaderboard.begin(); iter != Leaderboard.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Leaderboard_member = obj.FindMember("Leaderboard");
                if (Leaderboard_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Leaderboard_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Leaderboard.push_back(CharacterLeaderboardEntry(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetLeaderboardRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetLeaderboardRequest,"{7f1a9a0b-500a-5fc7-b631-44ce486fa5bf}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string StatisticName;
            Int32 StartPosition;
            OptionalInt32 MaxResultsCount;
            OptionalInt32 Version;
            PlayerProfileViewConstraints* ProfileConstraints;

            GetLeaderboardRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                StartPosition(0),
                MaxResultsCount(),
                Version(),
                ProfileConstraints(nullptr)
            {}

            GetLeaderboardRequest(const GetLeaderboardRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                StartPosition(src.StartPosition),
                MaxResultsCount(src.MaxResultsCount),
                Version(src.Version),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : nullptr)
            {}

            GetLeaderboardRequest(const rapidjson::Value& obj) : GetLeaderboardRequest()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardRequest()
            {
                if (ProfileConstraints != nullptr) delete ProfileConstraints;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("StatisticName");
                writer.String(StatisticName.c_str());
                writer.String("StartPosition");
                writer.Int(StartPosition);
                if (MaxResultsCount.notNull()) {
                    writer.String("MaxResultsCount");
                    writer.Int(MaxResultsCount);
                }
                if (Version.notNull()) {
                    writer.String("Version");
                    writer.Int(Version);
                }
                if (ProfileConstraints != nullptr) {
                    writer.String("ProfileConstraints");
                    ProfileConstraints->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator StartPosition_member = obj.FindMember("StartPosition");
                if (StartPosition_member != obj.MemberEnd() && !StartPosition_member->value.IsNull()) StartPosition = StartPosition_member->value.GetInt();
                const Value::ConstMemberIterator MaxResultsCount_member = obj.FindMember("MaxResultsCount");
                if (MaxResultsCount_member != obj.MemberEnd() && !MaxResultsCount_member->value.IsNull()) MaxResultsCount = MaxResultsCount_member->value.GetInt();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
                if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);

                return true;
            }
        };

        struct GetLeaderboardResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetLeaderboardResult,"{2998946d-2791-5897-9f0e-848377027e1e}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<PlayerLeaderboardEntry> Leaderboard; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            Int32 Version;
            OptionalTime NextReset;

            GetLeaderboardResult() :
                PlayFabBaseModel(),
                Leaderboard(),
                Version(0),
                NextReset()
            {}

            GetLeaderboardResult(const GetLeaderboardResult& src) :
                PlayFabBaseModel(),
                Leaderboard(src.Leaderboard),
                Version(src.Version),
                NextReset(src.NextReset)
            {}

            GetLeaderboardResult(const rapidjson::Value& obj) : GetLeaderboardResult()
            {
                readFromValue(obj);
            }

            ~GetLeaderboardResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Leaderboard.empty()) {
                    writer.String("Leaderboard");
                    writer.StartArray();
                    for (auto iter = Leaderboard.begin(); iter != Leaderboard.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.String("Version");
                writer.Int(Version);
                if (NextReset.notNull()) {
                    writer.String("NextReset");
                    writeDatetime(NextReset, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Leaderboard_member = obj.FindMember("Leaderboard");
                if (Leaderboard_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Leaderboard_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Leaderboard.push_back(PlayerLeaderboardEntry(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator NextReset_member = obj.FindMember("NextReset");
                if (NextReset_member != obj.MemberEnd() && !NextReset_member->value.IsNull()) NextReset = readDatetime(NextReset_member->value);

                return true;
            }
        };

        struct GetPhotonAuthenticationTokenRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPhotonAuthenticationTokenRequest,"{6b8f93b4-675c-5404-b892-fd20f027446c}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string PhotonApplicationId;

            GetPhotonAuthenticationTokenRequest() :
                PlayFabBaseModel(),
                PhotonApplicationId()
            {}

            GetPhotonAuthenticationTokenRequest(const GetPhotonAuthenticationTokenRequest& src) :
                PlayFabBaseModel(),
                PhotonApplicationId(src.PhotonApplicationId)
            {}

            GetPhotonAuthenticationTokenRequest(const rapidjson::Value& obj) : GetPhotonAuthenticationTokenRequest()
            {
                readFromValue(obj);
            }

            ~GetPhotonAuthenticationTokenRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PhotonApplicationId");
                writer.String(PhotonApplicationId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PhotonApplicationId_member = obj.FindMember("PhotonApplicationId");
                if (PhotonApplicationId_member != obj.MemberEnd() && !PhotonApplicationId_member->value.IsNull()) PhotonApplicationId = PhotonApplicationId_member->value.GetString();

                return true;
            }
        };

        struct GetPhotonAuthenticationTokenResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPhotonAuthenticationTokenResult,"{9ed92649-d81a-5825-b7c1-70c6170cd843}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string PhotonCustomAuthenticationToken;

            GetPhotonAuthenticationTokenResult() :
                PlayFabBaseModel(),
                PhotonCustomAuthenticationToken()
            {}

            GetPhotonAuthenticationTokenResult(const GetPhotonAuthenticationTokenResult& src) :
                PlayFabBaseModel(),
                PhotonCustomAuthenticationToken(src.PhotonCustomAuthenticationToken)
            {}

            GetPhotonAuthenticationTokenResult(const rapidjson::Value& obj) : GetPhotonAuthenticationTokenResult()
            {
                readFromValue(obj);
            }

            ~GetPhotonAuthenticationTokenResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PhotonCustomAuthenticationToken.length() > 0) {
                    writer.String("PhotonCustomAuthenticationToken");
                    writer.String(PhotonCustomAuthenticationToken.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PhotonCustomAuthenticationToken_member = obj.FindMember("PhotonCustomAuthenticationToken");
                if (PhotonCustomAuthenticationToken_member != obj.MemberEnd() && !PhotonCustomAuthenticationToken_member->value.IsNull()) PhotonCustomAuthenticationToken = PhotonCustomAuthenticationToken_member->value.GetString();

                return true;
            }
        };

        struct GetPlayerCombinedInfoRequestParams : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayerCombinedInfoRequestParams,"{2feec8a3-bb59-53d3-aef0-6a759ecdc5f1}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            bool GetUserAccountInfo;
            bool GetUserInventory;
            bool GetUserVirtualCurrency;
            bool GetUserData;
            AZStd::vector<AZStd::string> UserDataKeys; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            bool GetUserReadOnlyData;
            AZStd::vector<AZStd::string> UserReadOnlyDataKeys; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            bool GetCharacterInventories;
            bool GetCharacterList;
            bool GetTitleData;
            AZStd::vector<AZStd::string> TitleDataKeys; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            bool GetPlayerStatistics;
            AZStd::vector<AZStd::string> PlayerStatisticNames; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            bool GetPlayerProfile;
            PlayerProfileViewConstraints* ProfileConstraints;

            GetPlayerCombinedInfoRequestParams() :
                PlayFabBaseModel(),
                GetUserAccountInfo(false),
                GetUserInventory(false),
                GetUserVirtualCurrency(false),
                GetUserData(false),
                UserDataKeys(),
                GetUserReadOnlyData(false),
                UserReadOnlyDataKeys(),
                GetCharacterInventories(false),
                GetCharacterList(false),
                GetTitleData(false),
                TitleDataKeys(),
                GetPlayerStatistics(false),
                PlayerStatisticNames(),
                GetPlayerProfile(false),
                ProfileConstraints(nullptr)
            {}

            GetPlayerCombinedInfoRequestParams(const GetPlayerCombinedInfoRequestParams& src) :
                PlayFabBaseModel(),
                GetUserAccountInfo(src.GetUserAccountInfo),
                GetUserInventory(src.GetUserInventory),
                GetUserVirtualCurrency(src.GetUserVirtualCurrency),
                GetUserData(src.GetUserData),
                UserDataKeys(src.UserDataKeys),
                GetUserReadOnlyData(src.GetUserReadOnlyData),
                UserReadOnlyDataKeys(src.UserReadOnlyDataKeys),
                GetCharacterInventories(src.GetCharacterInventories),
                GetCharacterList(src.GetCharacterList),
                GetTitleData(src.GetTitleData),
                TitleDataKeys(src.TitleDataKeys),
                GetPlayerStatistics(src.GetPlayerStatistics),
                PlayerStatisticNames(src.PlayerStatisticNames),
                GetPlayerProfile(src.GetPlayerProfile),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : nullptr)
            {}

            GetPlayerCombinedInfoRequestParams(const rapidjson::Value& obj) : GetPlayerCombinedInfoRequestParams()
            {
                readFromValue(obj);
            }

            ~GetPlayerCombinedInfoRequestParams()
            {
                if (ProfileConstraints != nullptr) delete ProfileConstraints;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("GetUserAccountInfo");
                writer.Bool(GetUserAccountInfo);
                writer.String("GetUserInventory");
                writer.Bool(GetUserInventory);
                writer.String("GetUserVirtualCurrency");
                writer.Bool(GetUserVirtualCurrency);
                writer.String("GetUserData");
                writer.Bool(GetUserData);
                if (!UserDataKeys.empty()) {
                    writer.String("UserDataKeys");
                    writer.StartArray();
                    for (auto iter = UserDataKeys.begin(); iter != UserDataKeys.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                writer.String("GetUserReadOnlyData");
                writer.Bool(GetUserReadOnlyData);
                if (!UserReadOnlyDataKeys.empty()) {
                    writer.String("UserReadOnlyDataKeys");
                    writer.StartArray();
                    for (auto iter = UserReadOnlyDataKeys.begin(); iter != UserReadOnlyDataKeys.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                writer.String("GetCharacterInventories");
                writer.Bool(GetCharacterInventories);
                writer.String("GetCharacterList");
                writer.Bool(GetCharacterList);
                writer.String("GetTitleData");
                writer.Bool(GetTitleData);
                if (!TitleDataKeys.empty()) {
                    writer.String("TitleDataKeys");
                    writer.StartArray();
                    for (auto iter = TitleDataKeys.begin(); iter != TitleDataKeys.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                writer.String("GetPlayerStatistics");
                writer.Bool(GetPlayerStatistics);
                if (!PlayerStatisticNames.empty()) {
                    writer.String("PlayerStatisticNames");
                    writer.StartArray();
                    for (auto iter = PlayerStatisticNames.begin(); iter != PlayerStatisticNames.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                writer.String("GetPlayerProfile");
                writer.Bool(GetPlayerProfile);
                if (ProfileConstraints != nullptr) {
                    writer.String("ProfileConstraints");
                    ProfileConstraints->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GetUserAccountInfo_member = obj.FindMember("GetUserAccountInfo");
                if (GetUserAccountInfo_member != obj.MemberEnd() && !GetUserAccountInfo_member->value.IsNull()) GetUserAccountInfo = GetUserAccountInfo_member->value.GetBool();
                const Value::ConstMemberIterator GetUserInventory_member = obj.FindMember("GetUserInventory");
                if (GetUserInventory_member != obj.MemberEnd() && !GetUserInventory_member->value.IsNull()) GetUserInventory = GetUserInventory_member->value.GetBool();
                const Value::ConstMemberIterator GetUserVirtualCurrency_member = obj.FindMember("GetUserVirtualCurrency");
                if (GetUserVirtualCurrency_member != obj.MemberEnd() && !GetUserVirtualCurrency_member->value.IsNull()) GetUserVirtualCurrency = GetUserVirtualCurrency_member->value.GetBool();
                const Value::ConstMemberIterator GetUserData_member = obj.FindMember("GetUserData");
                if (GetUserData_member != obj.MemberEnd() && !GetUserData_member->value.IsNull()) GetUserData = GetUserData_member->value.GetBool();
                const Value::ConstMemberIterator UserDataKeys_member = obj.FindMember("UserDataKeys");
                if (UserDataKeys_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = UserDataKeys_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        UserDataKeys.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator GetUserReadOnlyData_member = obj.FindMember("GetUserReadOnlyData");
                if (GetUserReadOnlyData_member != obj.MemberEnd() && !GetUserReadOnlyData_member->value.IsNull()) GetUserReadOnlyData = GetUserReadOnlyData_member->value.GetBool();
                const Value::ConstMemberIterator UserReadOnlyDataKeys_member = obj.FindMember("UserReadOnlyDataKeys");
                if (UserReadOnlyDataKeys_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = UserReadOnlyDataKeys_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        UserReadOnlyDataKeys.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator GetCharacterInventories_member = obj.FindMember("GetCharacterInventories");
                if (GetCharacterInventories_member != obj.MemberEnd() && !GetCharacterInventories_member->value.IsNull()) GetCharacterInventories = GetCharacterInventories_member->value.GetBool();
                const Value::ConstMemberIterator GetCharacterList_member = obj.FindMember("GetCharacterList");
                if (GetCharacterList_member != obj.MemberEnd() && !GetCharacterList_member->value.IsNull()) GetCharacterList = GetCharacterList_member->value.GetBool();
                const Value::ConstMemberIterator GetTitleData_member = obj.FindMember("GetTitleData");
                if (GetTitleData_member != obj.MemberEnd() && !GetTitleData_member->value.IsNull()) GetTitleData = GetTitleData_member->value.GetBool();
                const Value::ConstMemberIterator TitleDataKeys_member = obj.FindMember("TitleDataKeys");
                if (TitleDataKeys_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = TitleDataKeys_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        TitleDataKeys.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator GetPlayerStatistics_member = obj.FindMember("GetPlayerStatistics");
                if (GetPlayerStatistics_member != obj.MemberEnd() && !GetPlayerStatistics_member->value.IsNull()) GetPlayerStatistics = GetPlayerStatistics_member->value.GetBool();
                const Value::ConstMemberIterator PlayerStatisticNames_member = obj.FindMember("PlayerStatisticNames");
                if (PlayerStatisticNames_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = PlayerStatisticNames_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        PlayerStatisticNames.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator GetPlayerProfile_member = obj.FindMember("GetPlayerProfile");
                if (GetPlayerProfile_member != obj.MemberEnd() && !GetPlayerProfile_member->value.IsNull()) GetPlayerProfile = GetPlayerProfile_member->value.GetBool();
                const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
                if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);

                return true;
            }
        };

        struct GetPlayerCombinedInfoRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayerCombinedInfoRequest,"{e7ffb7f2-bff5-5c8f-b71e-6041abbf8ae9}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string PlayFabId;
            GetPlayerCombinedInfoRequestParams InfoRequestParameters;

            GetPlayerCombinedInfoRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                InfoRequestParameters()
            {}

            GetPlayerCombinedInfoRequest(const GetPlayerCombinedInfoRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                InfoRequestParameters(src.InfoRequestParameters)
            {}

            GetPlayerCombinedInfoRequest(const rapidjson::Value& obj) : GetPlayerCombinedInfoRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerCombinedInfoRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.String("InfoRequestParameters");
                InfoRequestParameters.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);

                return true;
            }
        };

        struct StatisticValue : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::StatisticValue,"{5bafceef-3bfe-55f1-b47e-6333c769cf1a}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string StatisticName;
            Int32 Value;
            Uint32 Version;

            StatisticValue() :
                PlayFabBaseModel(),
                StatisticName(),
                Value(0),
                Version(0)
            {}

            StatisticValue(const StatisticValue& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Value(src.Value),
                Version(src.Version)
            {}

            StatisticValue(const rapidjson::Value& obj) : StatisticValue()
            {
                readFromValue(obj);
            }

            ~StatisticValue()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (StatisticName.length() > 0) {
                    writer.String("StatisticName");
                    writer.String(StatisticName.c_str());
                }
                writer.String("Value");
                writer.Int(Value);
                writer.String("Version");
                writer.Uint(Version);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
                if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetInt();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetUint();

                return true;
            }
        };

        struct GetPlayerCombinedInfoResultPayload : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayerCombinedInfoResultPayload,"{493e62c4-ebff-58e9-9fba-751b7a5d1d06}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            UserAccountInfo* AccountInfo;
            AZStd::vector<ItemInstance> UserInventory; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::unordered_map<AZStd::string, Int32> UserVirtualCurrency;
            AZStd::unordered_map<AZStd::string, VirtualCurrencyRechargeTime> UserVirtualCurrencyRechargeTimes;
            AZStd::unordered_map<AZStd::string, UserDataRecord> UserData;
            Uint32 UserDataVersion;
            AZStd::unordered_map<AZStd::string, UserDataRecord> UserReadOnlyData;
            Uint32 UserReadOnlyDataVersion;
            AZStd::vector<CharacterResult> CharacterList; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<CharacterInventory> CharacterInventories; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::unordered_map<AZStd::string, AZStd::string> TitleData;
            AZStd::vector<StatisticValue> PlayerStatistics; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            PlayerProfileModel* PlayerProfile;

            GetPlayerCombinedInfoResultPayload() :
                PlayFabBaseModel(),
                AccountInfo(nullptr),
                UserInventory(),
                UserVirtualCurrency(),
                UserVirtualCurrencyRechargeTimes(),
                UserData(),
                UserDataVersion(0),
                UserReadOnlyData(),
                UserReadOnlyDataVersion(0),
                CharacterList(),
                CharacterInventories(),
                TitleData(),
                PlayerStatistics(),
                PlayerProfile(nullptr)
            {}

            GetPlayerCombinedInfoResultPayload(const GetPlayerCombinedInfoResultPayload& src) :
                PlayFabBaseModel(),
                AccountInfo(src.AccountInfo ? new UserAccountInfo(*src.AccountInfo) : nullptr),
                UserInventory(src.UserInventory),
                UserVirtualCurrency(src.UserVirtualCurrency),
                UserVirtualCurrencyRechargeTimes(src.UserVirtualCurrencyRechargeTimes),
                UserData(src.UserData),
                UserDataVersion(src.UserDataVersion),
                UserReadOnlyData(src.UserReadOnlyData),
                UserReadOnlyDataVersion(src.UserReadOnlyDataVersion),
                CharacterList(src.CharacterList),
                CharacterInventories(src.CharacterInventories),
                TitleData(src.TitleData),
                PlayerStatistics(src.PlayerStatistics),
                PlayerProfile(src.PlayerProfile ? new PlayerProfileModel(*src.PlayerProfile) : nullptr)
            {}

            GetPlayerCombinedInfoResultPayload(const rapidjson::Value& obj) : GetPlayerCombinedInfoResultPayload()
            {
                readFromValue(obj);
            }

            ~GetPlayerCombinedInfoResultPayload()
            {
                if (AccountInfo != nullptr) delete AccountInfo;
                if (PlayerProfile != nullptr) delete PlayerProfile;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (AccountInfo != nullptr) {
                    writer.String("AccountInfo");
                    AccountInfo->writeJSON(writer);
                }
                if (!UserInventory.empty()) {
                    writer.String("UserInventory");
                    writer.StartArray();
                    for (auto iter = UserInventory.begin(); iter != UserInventory.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!UserVirtualCurrency.empty()) {
                    writer.String("UserVirtualCurrency");
                    writer.StartObject();
                    for (auto iter = UserVirtualCurrency.begin(); iter != UserVirtualCurrency.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.Int(iter->second);
                    }
                    writer.EndObject();
                }
                if (!UserVirtualCurrencyRechargeTimes.empty()) {
                    writer.String("UserVirtualCurrencyRechargeTimes");
                    writer.StartObject();
                    for (auto iter = UserVirtualCurrencyRechargeTimes.begin(); iter != UserVirtualCurrencyRechargeTimes.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                if (!UserData.empty()) {
                    writer.String("UserData");
                    writer.StartObject();
                    for (auto iter = UserData.begin(); iter != UserData.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.String("UserDataVersion");
                writer.Uint(UserDataVersion);
                if (!UserReadOnlyData.empty()) {
                    writer.String("UserReadOnlyData");
                    writer.StartObject();
                    for (auto iter = UserReadOnlyData.begin(); iter != UserReadOnlyData.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.String("UserReadOnlyDataVersion");
                writer.Uint(UserReadOnlyDataVersion);
                if (!CharacterList.empty()) {
                    writer.String("CharacterList");
                    writer.StartArray();
                    for (auto iter = CharacterList.begin(); iter != CharacterList.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!CharacterInventories.empty()) {
                    writer.String("CharacterInventories");
                    writer.StartArray();
                    for (auto iter = CharacterInventories.begin(); iter != CharacterInventories.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!TitleData.empty()) {
                    writer.String("TitleData");
                    writer.StartObject();
                    for (auto iter = TitleData.begin(); iter != TitleData.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                if (!PlayerStatistics.empty()) {
                    writer.String("PlayerStatistics");
                    writer.StartArray();
                    for (auto iter = PlayerStatistics.begin(); iter != PlayerStatistics.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (PlayerProfile != nullptr) {
                    writer.String("PlayerProfile");
                    PlayerProfile->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AccountInfo_member = obj.FindMember("AccountInfo");
                if (AccountInfo_member != obj.MemberEnd() && !AccountInfo_member->value.IsNull()) AccountInfo = new UserAccountInfo(AccountInfo_member->value);
                const Value::ConstMemberIterator UserInventory_member = obj.FindMember("UserInventory");
                if (UserInventory_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = UserInventory_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        UserInventory.push_back(ItemInstance(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator UserVirtualCurrency_member = obj.FindMember("UserVirtualCurrency");
                if (UserVirtualCurrency_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = UserVirtualCurrency_member->value.MemberBegin(); iter != UserVirtualCurrency_member->value.MemberEnd(); ++iter) {
                        UserVirtualCurrency[iter->name.GetString()] = iter->value.GetInt();
                    }
                }
                const Value::ConstMemberIterator UserVirtualCurrencyRechargeTimes_member = obj.FindMember("UserVirtualCurrencyRechargeTimes");
                if (UserVirtualCurrencyRechargeTimes_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = UserVirtualCurrencyRechargeTimes_member->value.MemberBegin(); iter != UserVirtualCurrencyRechargeTimes_member->value.MemberEnd(); ++iter) {
                        UserVirtualCurrencyRechargeTimes[iter->name.GetString()] = VirtualCurrencyRechargeTime(iter->value);
                    }
                }
                const Value::ConstMemberIterator UserData_member = obj.FindMember("UserData");
                if (UserData_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = UserData_member->value.MemberBegin(); iter != UserData_member->value.MemberEnd(); ++iter) {
                        UserData[iter->name.GetString()] = UserDataRecord(iter->value);
                    }
                }
                const Value::ConstMemberIterator UserDataVersion_member = obj.FindMember("UserDataVersion");
                if (UserDataVersion_member != obj.MemberEnd() && !UserDataVersion_member->value.IsNull()) UserDataVersion = UserDataVersion_member->value.GetUint();
                const Value::ConstMemberIterator UserReadOnlyData_member = obj.FindMember("UserReadOnlyData");
                if (UserReadOnlyData_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = UserReadOnlyData_member->value.MemberBegin(); iter != UserReadOnlyData_member->value.MemberEnd(); ++iter) {
                        UserReadOnlyData[iter->name.GetString()] = UserDataRecord(iter->value);
                    }
                }
                const Value::ConstMemberIterator UserReadOnlyDataVersion_member = obj.FindMember("UserReadOnlyDataVersion");
                if (UserReadOnlyDataVersion_member != obj.MemberEnd() && !UserReadOnlyDataVersion_member->value.IsNull()) UserReadOnlyDataVersion = UserReadOnlyDataVersion_member->value.GetUint();
                const Value::ConstMemberIterator CharacterList_member = obj.FindMember("CharacterList");
                if (CharacterList_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = CharacterList_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        CharacterList.push_back(CharacterResult(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator CharacterInventories_member = obj.FindMember("CharacterInventories");
                if (CharacterInventories_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = CharacterInventories_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        CharacterInventories.push_back(CharacterInventory(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator TitleData_member = obj.FindMember("TitleData");
                if (TitleData_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = TitleData_member->value.MemberBegin(); iter != TitleData_member->value.MemberEnd(); ++iter) {
                        TitleData[iter->name.GetString()] = iter->value.GetString();
                    }
                }
                const Value::ConstMemberIterator PlayerStatistics_member = obj.FindMember("PlayerStatistics");
                if (PlayerStatistics_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = PlayerStatistics_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        PlayerStatistics.push_back(StatisticValue(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator PlayerProfile_member = obj.FindMember("PlayerProfile");
                if (PlayerProfile_member != obj.MemberEnd() && !PlayerProfile_member->value.IsNull()) PlayerProfile = new PlayerProfileModel(PlayerProfile_member->value);

                return true;
            }
        };

        struct GetPlayerCombinedInfoResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayerCombinedInfoResult,"{a7bdce5d-292c-5b38-9fc4-d2af81cf07a9}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string PlayFabId;
            GetPlayerCombinedInfoResultPayload* InfoResultPayload;

            GetPlayerCombinedInfoResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                InfoResultPayload(nullptr)
            {}

            GetPlayerCombinedInfoResult(const GetPlayerCombinedInfoResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                InfoResultPayload(src.InfoResultPayload ? new GetPlayerCombinedInfoResultPayload(*src.InfoResultPayload) : nullptr)
            {}

            GetPlayerCombinedInfoResult(const rapidjson::Value& obj) : GetPlayerCombinedInfoResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerCombinedInfoResult()
            {
                if (InfoResultPayload != nullptr) delete InfoResultPayload;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                if (InfoResultPayload != nullptr) {
                    writer.String("InfoResultPayload");
                    InfoResultPayload->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator InfoResultPayload_member = obj.FindMember("InfoResultPayload");
                if (InfoResultPayload_member != obj.MemberEnd() && !InfoResultPayload_member->value.IsNull()) InfoResultPayload = new GetPlayerCombinedInfoResultPayload(InfoResultPayload_member->value);

                return true;
            }
        };

        struct GetPlayerProfileRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayerProfileRequest,"{26e94a1b-8136-5c47-8d8e-05da8393c1cd}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string PlayFabId;
            PlayerProfileViewConstraints* ProfileConstraints;

            GetPlayerProfileRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                ProfileConstraints(nullptr)
            {}

            GetPlayerProfileRequest(const GetPlayerProfileRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                ProfileConstraints(src.ProfileConstraints ? new PlayerProfileViewConstraints(*src.ProfileConstraints) : nullptr)
            {}

            GetPlayerProfileRequest(const rapidjson::Value& obj) : GetPlayerProfileRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerProfileRequest()
            {
                if (ProfileConstraints != nullptr) delete ProfileConstraints;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                if (ProfileConstraints != nullptr) {
                    writer.String("ProfileConstraints");
                    ProfileConstraints->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator ProfileConstraints_member = obj.FindMember("ProfileConstraints");
                if (ProfileConstraints_member != obj.MemberEnd() && !ProfileConstraints_member->value.IsNull()) ProfileConstraints = new PlayerProfileViewConstraints(ProfileConstraints_member->value);

                return true;
            }
        };

        struct GetPlayerProfileResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayerProfileResult,"{b0634d52-d54e-55a5-9c08-01e5ee94de1d}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            PlayerProfileModel* PlayerProfile;

            GetPlayerProfileResult() :
                PlayFabBaseModel(),
                PlayerProfile(nullptr)
            {}

            GetPlayerProfileResult(const GetPlayerProfileResult& src) :
                PlayFabBaseModel(),
                PlayerProfile(src.PlayerProfile ? new PlayerProfileModel(*src.PlayerProfile) : nullptr)
            {}

            GetPlayerProfileResult(const rapidjson::Value& obj) : GetPlayerProfileResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerProfileResult()
            {
                if (PlayerProfile != nullptr) delete PlayerProfile;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayerProfile != nullptr) {
                    writer.String("PlayerProfile");
                    PlayerProfile->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayerProfile_member = obj.FindMember("PlayerProfile");
                if (PlayerProfile_member != obj.MemberEnd() && !PlayerProfile_member->value.IsNull()) PlayerProfile = new PlayerProfileModel(PlayerProfile_member->value);

                return true;
            }
        };

        struct GetPlayerSegmentsRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayerSegmentsRequest,"{a37dd4fd-5f9b-5f51-b29f-e194ae500cce}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            GetPlayerSegmentsRequest() :
                PlayFabBaseModel()
            {}

            GetPlayerSegmentsRequest(const GetPlayerSegmentsRequest& src) :
                PlayFabBaseModel()
            {}

            GetPlayerSegmentsRequest(const rapidjson::Value& obj) : GetPlayerSegmentsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerSegmentsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct GetSegmentResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetSegmentResult,"{2740c00b-c2ed-5f0f-8d45-d0a5bf54e486}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string Id;
            AZStd::string Name;
            AZStd::string ABTestParent;

            GetSegmentResult() :
                PlayFabBaseModel(),
                Id(),
                Name(),
                ABTestParent()
            {}

            GetSegmentResult(const GetSegmentResult& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                Name(src.Name),
                ABTestParent(src.ABTestParent)
            {}

            GetSegmentResult(const rapidjson::Value& obj) : GetSegmentResult()
            {
                readFromValue(obj);
            }

            ~GetSegmentResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Id");
                writer.String(Id.c_str());
                if (Name.length() > 0) {
                    writer.String("Name");
                    writer.String(Name.c_str());
                }
                if (ABTestParent.length() > 0) {
                    writer.String("ABTestParent");
                    writer.String(ABTestParent.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
                if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
                const Value::ConstMemberIterator ABTestParent_member = obj.FindMember("ABTestParent");
                if (ABTestParent_member != obj.MemberEnd() && !ABTestParent_member->value.IsNull()) ABTestParent = ABTestParent_member->value.GetString();

                return true;
            }
        };

        struct GetPlayerSegmentsResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayerSegmentsResult,"{d9a1e974-e612-5526-b29c-2d0ec0aec7f8}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<GetSegmentResult> Segments; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayerSegmentsResult() :
                PlayFabBaseModel(),
                Segments()
            {}

            GetPlayerSegmentsResult(const GetPlayerSegmentsResult& src) :
                PlayFabBaseModel(),
                Segments(src.Segments)
            {}

            GetPlayerSegmentsResult(const rapidjson::Value& obj) : GetPlayerSegmentsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerSegmentsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Segments.empty()) {
                    writer.String("Segments");
                    writer.StartArray();
                    for (auto iter = Segments.begin(); iter != Segments.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Segments_member = obj.FindMember("Segments");
                if (Segments_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Segments_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Segments.push_back(GetSegmentResult(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct StatisticNameVersion : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::StatisticNameVersion,"{b1b09fb7-a2d3-5779-97a3-20526467e95e}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string StatisticName;
            Uint32 Version;

            StatisticNameVersion() :
                PlayFabBaseModel(),
                StatisticName(),
                Version(0)
            {}

            StatisticNameVersion(const StatisticNameVersion& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Version(src.Version)
            {}

            StatisticNameVersion(const rapidjson::Value& obj) : StatisticNameVersion()
            {
                readFromValue(obj);
            }

            ~StatisticNameVersion()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("StatisticName");
                writer.String(StatisticName.c_str());
                writer.String("Version");
                writer.Uint(Version);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetUint();

                return true;
            }
        };

        struct GetPlayerStatisticsRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayerStatisticsRequest,"{9d0e231f-c965-5a14-a8ad-17ed8445bb55}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<AZStd::string> StatisticNames; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<StatisticNameVersion> StatisticNameVersions; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayerStatisticsRequest() :
                PlayFabBaseModel(),
                StatisticNames(),
                StatisticNameVersions()
            {}

            GetPlayerStatisticsRequest(const GetPlayerStatisticsRequest& src) :
                PlayFabBaseModel(),
                StatisticNames(src.StatisticNames),
                StatisticNameVersions(src.StatisticNameVersions)
            {}

            GetPlayerStatisticsRequest(const rapidjson::Value& obj) : GetPlayerStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!StatisticNames.empty()) {
                    writer.String("StatisticNames");
                    writer.StartArray();
                    for (auto iter = StatisticNames.begin(); iter != StatisticNames.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!StatisticNameVersions.empty()) {
                    writer.String("StatisticNameVersions");
                    writer.StartArray();
                    for (auto iter = StatisticNameVersions.begin(); iter != StatisticNameVersions.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticNames_member = obj.FindMember("StatisticNames");
                if (StatisticNames_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = StatisticNames_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        StatisticNames.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator StatisticNameVersions_member = obj.FindMember("StatisticNameVersions");
                if (StatisticNameVersions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = StatisticNameVersions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        StatisticNameVersions.push_back(StatisticNameVersion(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayerStatisticsResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayerStatisticsResult,"{13c2dfdd-4742-5fac-9997-3db4b3016bd2}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<StatisticValue> Statistics; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayerStatisticsResult() :
                PlayFabBaseModel(),
                Statistics()
            {}

            GetPlayerStatisticsResult(const GetPlayerStatisticsResult& src) :
                PlayFabBaseModel(),
                Statistics(src.Statistics)
            {}

            GetPlayerStatisticsResult(const rapidjson::Value& obj) : GetPlayerStatisticsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Statistics.empty()) {
                    writer.String("Statistics");
                    writer.StartArray();
                    for (auto iter = Statistics.begin(); iter != Statistics.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Statistics_member = obj.FindMember("Statistics");
                if (Statistics_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Statistics_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Statistics.push_back(StatisticValue(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayerStatisticVersionsRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayerStatisticVersionsRequest,"{62f2cab5-8e12-5250-823e-21e0f6818bce}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string StatisticName;

            GetPlayerStatisticVersionsRequest() :
                PlayFabBaseModel(),
                StatisticName()
            {}

            GetPlayerStatisticVersionsRequest(const GetPlayerStatisticVersionsRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName)
            {}

            GetPlayerStatisticVersionsRequest(const rapidjson::Value& obj) : GetPlayerStatisticVersionsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticVersionsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (StatisticName.length() > 0) {
                    writer.String("StatisticName");
                    writer.String(StatisticName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();

                return true;
            }
        };

        struct PlayerStatisticVersion : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::PlayerStatisticVersion,"{b4b4550f-a7db-5a7d-bf2e-1175aad2c08c}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string StatisticName;
            Uint32 Version;
            OptionalTime ScheduledActivationTime;
            time_t ActivationTime;
            OptionalTime ScheduledDeactivationTime;
            OptionalTime DeactivationTime;

            PlayerStatisticVersion() :
                PlayFabBaseModel(),
                StatisticName(),
                Version(0),
                ScheduledActivationTime(),
                ActivationTime(0),
                ScheduledDeactivationTime(),
                DeactivationTime()
            {}

            PlayerStatisticVersion(const PlayerStatisticVersion& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Version(src.Version),
                ScheduledActivationTime(src.ScheduledActivationTime),
                ActivationTime(src.ActivationTime),
                ScheduledDeactivationTime(src.ScheduledDeactivationTime),
                DeactivationTime(src.DeactivationTime)
            {}

            PlayerStatisticVersion(const rapidjson::Value& obj) : PlayerStatisticVersion()
            {
                readFromValue(obj);
            }

            ~PlayerStatisticVersion()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (StatisticName.length() > 0) {
                    writer.String("StatisticName");
                    writer.String(StatisticName.c_str());
                }
                writer.String("Version");
                writer.Uint(Version);
                if (ScheduledActivationTime.notNull()) {
                    writer.String("ScheduledActivationTime");
                    writeDatetime(ScheduledActivationTime, writer);
                }
                writer.String("ActivationTime");
                writeDatetime(ActivationTime, writer);
                if (ScheduledDeactivationTime.notNull()) {
                    writer.String("ScheduledDeactivationTime");
                    writeDatetime(ScheduledDeactivationTime, writer);
                }
                if (DeactivationTime.notNull()) {
                    writer.String("DeactivationTime");
                    writeDatetime(DeactivationTime, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetUint();
                const Value::ConstMemberIterator ScheduledActivationTime_member = obj.FindMember("ScheduledActivationTime");
                if (ScheduledActivationTime_member != obj.MemberEnd() && !ScheduledActivationTime_member->value.IsNull()) ScheduledActivationTime = readDatetime(ScheduledActivationTime_member->value);
                const Value::ConstMemberIterator ActivationTime_member = obj.FindMember("ActivationTime");
                if (ActivationTime_member != obj.MemberEnd() && !ActivationTime_member->value.IsNull()) ActivationTime = readDatetime(ActivationTime_member->value);
                const Value::ConstMemberIterator ScheduledDeactivationTime_member = obj.FindMember("ScheduledDeactivationTime");
                if (ScheduledDeactivationTime_member != obj.MemberEnd() && !ScheduledDeactivationTime_member->value.IsNull()) ScheduledDeactivationTime = readDatetime(ScheduledDeactivationTime_member->value);
                const Value::ConstMemberIterator DeactivationTime_member = obj.FindMember("DeactivationTime");
                if (DeactivationTime_member != obj.MemberEnd() && !DeactivationTime_member->value.IsNull()) DeactivationTime = readDatetime(DeactivationTime_member->value);

                return true;
            }
        };

        struct GetPlayerStatisticVersionsResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayerStatisticVersionsResult,"{6795d998-78a7-5b8e-8e33-61ef14cfef98}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<PlayerStatisticVersion> StatisticVersions; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayerStatisticVersionsResult() :
                PlayFabBaseModel(),
                StatisticVersions()
            {}

            GetPlayerStatisticVersionsResult(const GetPlayerStatisticVersionsResult& src) :
                PlayFabBaseModel(),
                StatisticVersions(src.StatisticVersions)
            {}

            GetPlayerStatisticVersionsResult(const rapidjson::Value& obj) : GetPlayerStatisticVersionsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticVersionsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!StatisticVersions.empty()) {
                    writer.String("StatisticVersions");
                    writer.StartArray();
                    for (auto iter = StatisticVersions.begin(); iter != StatisticVersions.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticVersions_member = obj.FindMember("StatisticVersions");
                if (StatisticVersions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = StatisticVersions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        StatisticVersions.push_back(PlayerStatisticVersion(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayerTagsRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayerTagsRequest,"{3653dbbb-0b6e-5316-9e82-94adad74519b}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string PlayFabId;
            AZStd::string Namespace;

            GetPlayerTagsRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                Namespace()
            {}

            GetPlayerTagsRequest(const GetPlayerTagsRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Namespace(src.Namespace)
            {}

            GetPlayerTagsRequest(const rapidjson::Value& obj) : GetPlayerTagsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerTagsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                if (Namespace.length() > 0) {
                    writer.String("Namespace");
                    writer.String(Namespace.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Namespace_member = obj.FindMember("Namespace");
                if (Namespace_member != obj.MemberEnd() && !Namespace_member->value.IsNull()) Namespace = Namespace_member->value.GetString();

                return true;
            }
        };

        struct GetPlayerTagsResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayerTagsResult,"{80ce1fa8-f2a0-5a02-b38d-d17e58a41a50}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string PlayFabId;
            AZStd::vector<AZStd::string> Tags; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayerTagsResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                Tags()
            {}

            GetPlayerTagsResult(const GetPlayerTagsResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Tags(src.Tags)
            {}

            GetPlayerTagsResult(const rapidjson::Value& obj) : GetPlayerTagsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerTagsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                writer.String("Tags");
                writer.StartArray();
                for (auto iter = Tags.begin(); iter != Tags.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
                if (Tags_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Tags_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Tags.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct GetPlayerTradesRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayerTradesRequest,"{f75be75b-bc47-5ad2-92fc-578405ec5e92}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            Boxed<TradeStatus> StatusFilter;

            GetPlayerTradesRequest() :
                PlayFabBaseModel(),
                StatusFilter()
            {}

            GetPlayerTradesRequest(const GetPlayerTradesRequest& src) :
                PlayFabBaseModel(),
                StatusFilter(src.StatusFilter)
            {}

            GetPlayerTradesRequest(const rapidjson::Value& obj) : GetPlayerTradesRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerTradesRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (StatusFilter.notNull()) {
                    writer.String("StatusFilter");
                    writeTradeStatusEnumJSON(StatusFilter, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatusFilter_member = obj.FindMember("StatusFilter");
                if (StatusFilter_member != obj.MemberEnd() && !StatusFilter_member->value.IsNull()) StatusFilter = readTradeStatusFromValue(StatusFilter_member->value);

                return true;
            }
        };

        struct GetPlayerTradesResponse : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayerTradesResponse,"{571cbb4f-e54d-5fc1-b273-088cda731872}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<TradeInfo> OpenedTrades; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<TradeInfo> AcceptedTrades; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayerTradesResponse() :
                PlayFabBaseModel(),
                OpenedTrades(),
                AcceptedTrades()
            {}

            GetPlayerTradesResponse(const GetPlayerTradesResponse& src) :
                PlayFabBaseModel(),
                OpenedTrades(src.OpenedTrades),
                AcceptedTrades(src.AcceptedTrades)
            {}

            GetPlayerTradesResponse(const rapidjson::Value& obj) : GetPlayerTradesResponse()
            {
                readFromValue(obj);
            }

            ~GetPlayerTradesResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!OpenedTrades.empty()) {
                    writer.String("OpenedTrades");
                    writer.StartArray();
                    for (auto iter = OpenedTrades.begin(); iter != OpenedTrades.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!AcceptedTrades.empty()) {
                    writer.String("AcceptedTrades");
                    writer.StartArray();
                    for (auto iter = AcceptedTrades.begin(); iter != AcceptedTrades.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator OpenedTrades_member = obj.FindMember("OpenedTrades");
                if (OpenedTrades_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = OpenedTrades_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        OpenedTrades.push_back(TradeInfo(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator AcceptedTrades_member = obj.FindMember("AcceptedTrades");
                if (AcceptedTrades_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = AcceptedTrades_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        AcceptedTrades.push_back(TradeInfo(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayFabIDsFromFacebookIDsRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayFabIDsFromFacebookIDsRequest,"{ee32da3e-e261-5264-bc65-fb5e6396e3ba}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<AZStd::string> FacebookIDs; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromFacebookIDsRequest() :
                PlayFabBaseModel(),
                FacebookIDs()
            {}

            GetPlayFabIDsFromFacebookIDsRequest(const GetPlayFabIDsFromFacebookIDsRequest& src) :
                PlayFabBaseModel(),
                FacebookIDs(src.FacebookIDs)
            {}

            GetPlayFabIDsFromFacebookIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromFacebookIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromFacebookIDsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("FacebookIDs");
                writer.StartArray();
                for (auto iter = FacebookIDs.begin(); iter != FacebookIDs.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FacebookIDs_member = obj.FindMember("FacebookIDs");
                if (FacebookIDs_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = FacebookIDs_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        FacebookIDs.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct GetPlayFabIDsFromFacebookIDsResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayFabIDsFromFacebookIDsResult,"{9fc21067-5227-58cc-bcfc-3a92f7bf4643}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<FacebookPlayFabIdPair> Data; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromFacebookIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromFacebookIDsResult(const GetPlayFabIDsFromFacebookIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromFacebookIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromFacebookIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromFacebookIDsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartArray();
                    for (auto iter = Data.begin(); iter != Data.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Data_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Data.push_back(FacebookPlayFabIdPair(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayFabIDsFromGameCenterIDsRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayFabIDsFromGameCenterIDsRequest,"{8bf67893-1d6b-5c93-b86e-cfbf686ca69d}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<AZStd::string> GameCenterIDs; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromGameCenterIDsRequest() :
                PlayFabBaseModel(),
                GameCenterIDs()
            {}

            GetPlayFabIDsFromGameCenterIDsRequest(const GetPlayFabIDsFromGameCenterIDsRequest& src) :
                PlayFabBaseModel(),
                GameCenterIDs(src.GameCenterIDs)
            {}

            GetPlayFabIDsFromGameCenterIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromGameCenterIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromGameCenterIDsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("GameCenterIDs");
                writer.StartArray();
                for (auto iter = GameCenterIDs.begin(); iter != GameCenterIDs.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GameCenterIDs_member = obj.FindMember("GameCenterIDs");
                if (GameCenterIDs_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = GameCenterIDs_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        GameCenterIDs.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct GetPlayFabIDsFromGameCenterIDsResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayFabIDsFromGameCenterIDsResult,"{b50db01a-bfb8-59bf-90cd-db7005f00f89}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<GameCenterPlayFabIdPair> Data; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromGameCenterIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromGameCenterIDsResult(const GetPlayFabIDsFromGameCenterIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromGameCenterIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromGameCenterIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromGameCenterIDsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartArray();
                    for (auto iter = Data.begin(); iter != Data.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Data_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Data.push_back(GameCenterPlayFabIdPair(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayFabIDsFromGenericIDsRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayFabIDsFromGenericIDsRequest,"{1ad77e55-3cdb-5c64-8d66-4829dd5aac9c}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<GenericServiceId> GenericIDs; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromGenericIDsRequest() :
                PlayFabBaseModel(),
                GenericIDs()
            {}

            GetPlayFabIDsFromGenericIDsRequest(const GetPlayFabIDsFromGenericIDsRequest& src) :
                PlayFabBaseModel(),
                GenericIDs(src.GenericIDs)
            {}

            GetPlayFabIDsFromGenericIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromGenericIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromGenericIDsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("GenericIDs");
                writer.StartArray();
                for (auto iter = GenericIDs.begin(); iter != GenericIDs.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GenericIDs_member = obj.FindMember("GenericIDs");
                if (GenericIDs_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = GenericIDs_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        GenericIDs.push_back(GenericServiceId(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayFabIDsFromGenericIDsResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayFabIDsFromGenericIDsResult,"{b1e2a8f5-f85a-5fbb-9867-4ca101c656ad}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<GenericPlayFabIdPair> Data; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromGenericIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromGenericIDsResult(const GetPlayFabIDsFromGenericIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromGenericIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromGenericIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromGenericIDsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartArray();
                    for (auto iter = Data.begin(); iter != Data.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Data_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Data.push_back(GenericPlayFabIdPair(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayFabIDsFromGoogleIDsRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayFabIDsFromGoogleIDsRequest,"{72c9da23-3b69-515a-be9c-e34d9058479f}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<AZStd::string> GoogleIDs; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromGoogleIDsRequest() :
                PlayFabBaseModel(),
                GoogleIDs()
            {}

            GetPlayFabIDsFromGoogleIDsRequest(const GetPlayFabIDsFromGoogleIDsRequest& src) :
                PlayFabBaseModel(),
                GoogleIDs(src.GoogleIDs)
            {}

            GetPlayFabIDsFromGoogleIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromGoogleIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromGoogleIDsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("GoogleIDs");
                writer.StartArray();
                for (auto iter = GoogleIDs.begin(); iter != GoogleIDs.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GoogleIDs_member = obj.FindMember("GoogleIDs");
                if (GoogleIDs_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = GoogleIDs_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        GoogleIDs.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct GooglePlayFabIdPair : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GooglePlayFabIdPair,"{b67b0262-bcf1-5561-9904-a92dba54f4e1}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string GoogleId;
            AZStd::string PlayFabId;

            GooglePlayFabIdPair() :
                PlayFabBaseModel(),
                GoogleId(),
                PlayFabId()
            {}

            GooglePlayFabIdPair(const GooglePlayFabIdPair& src) :
                PlayFabBaseModel(),
                GoogleId(src.GoogleId),
                PlayFabId(src.PlayFabId)
            {}

            GooglePlayFabIdPair(const rapidjson::Value& obj) : GooglePlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~GooglePlayFabIdPair()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (GoogleId.length() > 0) {
                    writer.String("GoogleId");
                    writer.String(GoogleId.c_str());
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GoogleId_member = obj.FindMember("GoogleId");
                if (GoogleId_member != obj.MemberEnd() && !GoogleId_member->value.IsNull()) GoogleId = GoogleId_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct GetPlayFabIDsFromGoogleIDsResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayFabIDsFromGoogleIDsResult,"{15d1207e-ba69-598e-af20-4e287077c5cb}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<GooglePlayFabIdPair> Data; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromGoogleIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromGoogleIDsResult(const GetPlayFabIDsFromGoogleIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromGoogleIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromGoogleIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromGoogleIDsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartArray();
                    for (auto iter = Data.begin(); iter != Data.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Data_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Data.push_back(GooglePlayFabIdPair(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayFabIDsFromKongregateIDsRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayFabIDsFromKongregateIDsRequest,"{d7987dbc-3ced-5c12-9e0d-601a8dfdf6c7}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<AZStd::string> KongregateIDs; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromKongregateIDsRequest() :
                PlayFabBaseModel(),
                KongregateIDs()
            {}

            GetPlayFabIDsFromKongregateIDsRequest(const GetPlayFabIDsFromKongregateIDsRequest& src) :
                PlayFabBaseModel(),
                KongregateIDs(src.KongregateIDs)
            {}

            GetPlayFabIDsFromKongregateIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromKongregateIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromKongregateIDsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("KongregateIDs");
                writer.StartArray();
                for (auto iter = KongregateIDs.begin(); iter != KongregateIDs.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator KongregateIDs_member = obj.FindMember("KongregateIDs");
                if (KongregateIDs_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = KongregateIDs_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        KongregateIDs.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct KongregatePlayFabIdPair : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::KongregatePlayFabIdPair,"{799bdd24-87cb-581e-9b4e-ecf83d1043a5}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string KongregateId;
            AZStd::string PlayFabId;

            KongregatePlayFabIdPair() :
                PlayFabBaseModel(),
                KongregateId(),
                PlayFabId()
            {}

            KongregatePlayFabIdPair(const KongregatePlayFabIdPair& src) :
                PlayFabBaseModel(),
                KongregateId(src.KongregateId),
                PlayFabId(src.PlayFabId)
            {}

            KongregatePlayFabIdPair(const rapidjson::Value& obj) : KongregatePlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~KongregatePlayFabIdPair()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (KongregateId.length() > 0) {
                    writer.String("KongregateId");
                    writer.String(KongregateId.c_str());
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator KongregateId_member = obj.FindMember("KongregateId");
                if (KongregateId_member != obj.MemberEnd() && !KongregateId_member->value.IsNull()) KongregateId = KongregateId_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct GetPlayFabIDsFromKongregateIDsResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayFabIDsFromKongregateIDsResult,"{fe2c8330-b5d4-5e23-ae10-489f23986a03}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<KongregatePlayFabIdPair> Data; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromKongregateIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromKongregateIDsResult(const GetPlayFabIDsFromKongregateIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromKongregateIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromKongregateIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromKongregateIDsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartArray();
                    for (auto iter = Data.begin(); iter != Data.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Data_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Data.push_back(KongregatePlayFabIdPair(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayFabIDsFromSteamIDsRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayFabIDsFromSteamIDsRequest,"{d0d86d7a-e8fa-58f7-9ce7-a1bca6309a9a}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<AZStd::string> SteamStringIDs; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromSteamIDsRequest() :
                PlayFabBaseModel(),
                SteamStringIDs()
            {}

            GetPlayFabIDsFromSteamIDsRequest(const GetPlayFabIDsFromSteamIDsRequest& src) :
                PlayFabBaseModel(),
                SteamStringIDs(src.SteamStringIDs)
            {}

            GetPlayFabIDsFromSteamIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromSteamIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromSteamIDsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!SteamStringIDs.empty()) {
                    writer.String("SteamStringIDs");
                    writer.StartArray();
                    for (auto iter = SteamStringIDs.begin(); iter != SteamStringIDs.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SteamStringIDs_member = obj.FindMember("SteamStringIDs");
                if (SteamStringIDs_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = SteamStringIDs_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        SteamStringIDs.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct SteamPlayFabIdPair : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::SteamPlayFabIdPair,"{77a4e437-51d5-5e5f-8b2d-1e775490711d}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string SteamStringId;
            AZStd::string PlayFabId;

            SteamPlayFabIdPair() :
                PlayFabBaseModel(),
                SteamStringId(),
                PlayFabId()
            {}

            SteamPlayFabIdPair(const SteamPlayFabIdPair& src) :
                PlayFabBaseModel(),
                SteamStringId(src.SteamStringId),
                PlayFabId(src.PlayFabId)
            {}

            SteamPlayFabIdPair(const rapidjson::Value& obj) : SteamPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~SteamPlayFabIdPair()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (SteamStringId.length() > 0) {
                    writer.String("SteamStringId");
                    writer.String(SteamStringId.c_str());
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SteamStringId_member = obj.FindMember("SteamStringId");
                if (SteamStringId_member != obj.MemberEnd() && !SteamStringId_member->value.IsNull()) SteamStringId = SteamStringId_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct GetPlayFabIDsFromSteamIDsResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayFabIDsFromSteamIDsResult,"{a6002914-6aea-5717-bb66-0ded322e81ed}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<SteamPlayFabIdPair> Data; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromSteamIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromSteamIDsResult(const GetPlayFabIDsFromSteamIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromSteamIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromSteamIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromSteamIDsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartArray();
                    for (auto iter = Data.begin(); iter != Data.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Data_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Data.push_back(SteamPlayFabIdPair(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayFabIDsFromTwitchIDsRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayFabIDsFromTwitchIDsRequest,"{422752f9-4aca-5498-8fb3-c760cc8f0221}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<AZStd::string> TwitchIds; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromTwitchIDsRequest() :
                PlayFabBaseModel(),
                TwitchIds()
            {}

            GetPlayFabIDsFromTwitchIDsRequest(const GetPlayFabIDsFromTwitchIDsRequest& src) :
                PlayFabBaseModel(),
                TwitchIds(src.TwitchIds)
            {}

            GetPlayFabIDsFromTwitchIDsRequest(const rapidjson::Value& obj) : GetPlayFabIDsFromTwitchIDsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromTwitchIDsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("TwitchIds");
                writer.StartArray();
                for (auto iter = TwitchIds.begin(); iter != TwitchIds.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TwitchIds_member = obj.FindMember("TwitchIds");
                if (TwitchIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = TwitchIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        TwitchIds.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct TwitchPlayFabIdPair : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::TwitchPlayFabIdPair,"{0dc38556-a343-5324-bccc-69c72d4a41f1}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string TwitchId;
            AZStd::string PlayFabId;

            TwitchPlayFabIdPair() :
                PlayFabBaseModel(),
                TwitchId(),
                PlayFabId()
            {}

            TwitchPlayFabIdPair(const TwitchPlayFabIdPair& src) :
                PlayFabBaseModel(),
                TwitchId(src.TwitchId),
                PlayFabId(src.PlayFabId)
            {}

            TwitchPlayFabIdPair(const rapidjson::Value& obj) : TwitchPlayFabIdPair()
            {
                readFromValue(obj);
            }

            ~TwitchPlayFabIdPair()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (TwitchId.length() > 0) {
                    writer.String("TwitchId");
                    writer.String(TwitchId.c_str());
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TwitchId_member = obj.FindMember("TwitchId");
                if (TwitchId_member != obj.MemberEnd() && !TwitchId_member->value.IsNull()) TwitchId = TwitchId_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct GetPlayFabIDsFromTwitchIDsResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPlayFabIDsFromTwitchIDsResult,"{9a27c75e-6832-595b-9f9e-f3ab28767701}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<TwitchPlayFabIdPair> Data; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPlayFabIDsFromTwitchIDsResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPlayFabIDsFromTwitchIDsResult(const GetPlayFabIDsFromTwitchIDsResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPlayFabIDsFromTwitchIDsResult(const rapidjson::Value& obj) : GetPlayFabIDsFromTwitchIDsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayFabIDsFromTwitchIDsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartArray();
                    for (auto iter = Data.begin(); iter != Data.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Data_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Data.push_back(TwitchPlayFabIdPair(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPublisherDataRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPublisherDataRequest,"{65843d76-5ccb-5d9b-9292-f2ec8cbf0fb4}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<AZStd::string> Keys; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetPublisherDataRequest() :
                PlayFabBaseModel(),
                Keys()
            {}

            GetPublisherDataRequest(const GetPublisherDataRequest& src) :
                PlayFabBaseModel(),
                Keys(src.Keys)
            {}

            GetPublisherDataRequest(const rapidjson::Value& obj) : GetPublisherDataRequest()
            {
                readFromValue(obj);
            }

            ~GetPublisherDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Keys");
                writer.StartArray();
                for (auto iter = Keys.begin(); iter != Keys.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
                if (Keys_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Keys_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Keys.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct GetPublisherDataResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPublisherDataResult,"{92243b37-7620-5cac-9312-2e8cbb602f0f}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::unordered_map<AZStd::string, AZStd::string> Data;

            GetPublisherDataResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetPublisherDataResult(const GetPublisherDataResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetPublisherDataResult(const rapidjson::Value& obj) : GetPublisherDataResult()
            {
                readFromValue(obj);
            }

            ~GetPublisherDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartObject();
                    for (auto iter = Data.begin(); iter != Data.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
                        Data[iter->name.GetString()] = iter->value.GetString();
                    }
                }

                return true;
            }
        };

        struct GetPurchaseRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPurchaseRequest,"{f6aa9ba9-50c8-58fd-bd4c-fde9cafba23c}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string OrderId;

            GetPurchaseRequest() :
                PlayFabBaseModel(),
                OrderId()
            {}

            GetPurchaseRequest(const GetPurchaseRequest& src) :
                PlayFabBaseModel(),
                OrderId(src.OrderId)
            {}

            GetPurchaseRequest(const rapidjson::Value& obj) : GetPurchaseRequest()
            {
                readFromValue(obj);
            }

            ~GetPurchaseRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("OrderId");
                writer.String(OrderId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator OrderId_member = obj.FindMember("OrderId");
                if (OrderId_member != obj.MemberEnd() && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();

                return true;
            }
        };

        struct GetPurchaseResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetPurchaseResult,"{b37d21be-7f68-523a-af42-e8b80470362d}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string OrderId;
            AZStd::string PaymentProvider;
            AZStd::string TransactionId;
            AZStd::string TransactionStatus;
            time_t PurchaseDate;

            GetPurchaseResult() :
                PlayFabBaseModel(),
                OrderId(),
                PaymentProvider(),
                TransactionId(),
                TransactionStatus(),
                PurchaseDate(0)
            {}

            GetPurchaseResult(const GetPurchaseResult& src) :
                PlayFabBaseModel(),
                OrderId(src.OrderId),
                PaymentProvider(src.PaymentProvider),
                TransactionId(src.TransactionId),
                TransactionStatus(src.TransactionStatus),
                PurchaseDate(src.PurchaseDate)
            {}

            GetPurchaseResult(const rapidjson::Value& obj) : GetPurchaseResult()
            {
                readFromValue(obj);
            }

            ~GetPurchaseResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (OrderId.length() > 0) {
                    writer.String("OrderId");
                    writer.String(OrderId.c_str());
                }
                if (PaymentProvider.length() > 0) {
                    writer.String("PaymentProvider");
                    writer.String(PaymentProvider.c_str());
                }
                if (TransactionId.length() > 0) {
                    writer.String("TransactionId");
                    writer.String(TransactionId.c_str());
                }
                if (TransactionStatus.length() > 0) {
                    writer.String("TransactionStatus");
                    writer.String(TransactionStatus.c_str());
                }
                writer.String("PurchaseDate");
                writeDatetime(PurchaseDate, writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator OrderId_member = obj.FindMember("OrderId");
                if (OrderId_member != obj.MemberEnd() && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();
                const Value::ConstMemberIterator PaymentProvider_member = obj.FindMember("PaymentProvider");
                if (PaymentProvider_member != obj.MemberEnd() && !PaymentProvider_member->value.IsNull()) PaymentProvider = PaymentProvider_member->value.GetString();
                const Value::ConstMemberIterator TransactionId_member = obj.FindMember("TransactionId");
                if (TransactionId_member != obj.MemberEnd() && !TransactionId_member->value.IsNull()) TransactionId = TransactionId_member->value.GetString();
                const Value::ConstMemberIterator TransactionStatus_member = obj.FindMember("TransactionStatus");
                if (TransactionStatus_member != obj.MemberEnd() && !TransactionStatus_member->value.IsNull()) TransactionStatus = TransactionStatus_member->value.GetString();
                const Value::ConstMemberIterator PurchaseDate_member = obj.FindMember("PurchaseDate");
                if (PurchaseDate_member != obj.MemberEnd() && !PurchaseDate_member->value.IsNull()) PurchaseDate = readDatetime(PurchaseDate_member->value);

                return true;
            }
        };

        struct GetSharedGroupDataRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetSharedGroupDataRequest,"{283b85c1-29e3-5fb6-9bc9-08cc39827f68}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string SharedGroupId;
            AZStd::vector<AZStd::string> Keys; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            OptionalBool GetMembers;

            GetSharedGroupDataRequest() :
                PlayFabBaseModel(),
                SharedGroupId(),
                Keys(),
                GetMembers()
            {}

            GetSharedGroupDataRequest(const GetSharedGroupDataRequest& src) :
                PlayFabBaseModel(),
                SharedGroupId(src.SharedGroupId),
                Keys(src.Keys),
                GetMembers(src.GetMembers)
            {}

            GetSharedGroupDataRequest(const rapidjson::Value& obj) : GetSharedGroupDataRequest()
            {
                readFromValue(obj);
            }

            ~GetSharedGroupDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("SharedGroupId");
                writer.String(SharedGroupId.c_str());
                if (!Keys.empty()) {
                    writer.String("Keys");
                    writer.StartArray();
                    for (auto iter = Keys.begin(); iter != Keys.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (GetMembers.notNull()) {
                    writer.String("GetMembers");
                    writer.Bool(GetMembers);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
                if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();
                const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
                if (Keys_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Keys_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Keys.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator GetMembers_member = obj.FindMember("GetMembers");
                if (GetMembers_member != obj.MemberEnd() && !GetMembers_member->value.IsNull()) GetMembers = GetMembers_member->value.GetBool();

                return true;
            }
        };

        struct SharedGroupDataRecord : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::SharedGroupDataRecord,"{b91a9a58-3388-577f-90cd-ec3a5dd7b7cf}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string Value;
            AZStd::string LastUpdatedBy;
            time_t LastUpdated;
            Boxed<UserDataPermission> Permission;

            SharedGroupDataRecord() :
                PlayFabBaseModel(),
                Value(),
                LastUpdatedBy(),
                LastUpdated(0),
                Permission()
            {}

            SharedGroupDataRecord(const SharedGroupDataRecord& src) :
                PlayFabBaseModel(),
                Value(src.Value),
                LastUpdatedBy(src.LastUpdatedBy),
                LastUpdated(src.LastUpdated),
                Permission(src.Permission)
            {}

            SharedGroupDataRecord(const rapidjson::Value& obj) : SharedGroupDataRecord()
            {
                readFromValue(obj);
            }

            ~SharedGroupDataRecord()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Value.length() > 0) {
                    writer.String("Value");
                    writer.String(Value.c_str());
                }
                if (LastUpdatedBy.length() > 0) {
                    writer.String("LastUpdatedBy");
                    writer.String(LastUpdatedBy.c_str());
                }
                writer.String("LastUpdated");
                writeDatetime(LastUpdated, writer);
                if (Permission.notNull()) {
                    writer.String("Permission");
                    writeUserDataPermissionEnumJSON(Permission, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
                if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetString();
                const Value::ConstMemberIterator LastUpdatedBy_member = obj.FindMember("LastUpdatedBy");
                if (LastUpdatedBy_member != obj.MemberEnd() && !LastUpdatedBy_member->value.IsNull()) LastUpdatedBy = LastUpdatedBy_member->value.GetString();
                const Value::ConstMemberIterator LastUpdated_member = obj.FindMember("LastUpdated");
                if (LastUpdated_member != obj.MemberEnd() && !LastUpdated_member->value.IsNull()) LastUpdated = readDatetime(LastUpdated_member->value);
                const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
                if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

                return true;
            }
        };

        struct GetSharedGroupDataResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetSharedGroupDataResult,"{7443e8d8-d7db-5a31-8ccb-f88688cde2cb}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::unordered_map<AZStd::string, SharedGroupDataRecord> Data;
            AZStd::vector<AZStd::string> Members; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetSharedGroupDataResult() :
                PlayFabBaseModel(),
                Data(),
                Members()
            {}

            GetSharedGroupDataResult(const GetSharedGroupDataResult& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                Members(src.Members)
            {}

            GetSharedGroupDataResult(const rapidjson::Value& obj) : GetSharedGroupDataResult()
            {
                readFromValue(obj);
            }

            ~GetSharedGroupDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartObject();
                    for (auto iter = Data.begin(); iter != Data.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                if (!Members.empty()) {
                    writer.String("Members");
                    writer.StartArray();
                    for (auto iter = Members.begin(); iter != Members.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
                        Data[iter->name.GetString()] = SharedGroupDataRecord(iter->value);
                    }
                }
                const Value::ConstMemberIterator Members_member = obj.FindMember("Members");
                if (Members_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Members_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Members.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct GetStoreItemsRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetStoreItemsRequest,"{295d5175-0b7f-5303-ae43-47883dbd6208}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string CatalogVersion;
            AZStd::string StoreId;

            GetStoreItemsRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                StoreId()
            {}

            GetStoreItemsRequest(const GetStoreItemsRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                StoreId(src.StoreId)
            {}

            GetStoreItemsRequest(const rapidjson::Value& obj) : GetStoreItemsRequest()
            {
                readFromValue(obj);
            }

            ~GetStoreItemsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                writer.String("StoreId");
                writer.String(StoreId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator StoreId_member = obj.FindMember("StoreId");
                if (StoreId_member != obj.MemberEnd() && !StoreId_member->value.IsNull()) StoreId = StoreId_member->value.GetString();

                return true;
            }
        };

        struct StoreItem : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::StoreItem,"{ed93ba1b-7dc6-5810-874f-1b4f2cea4a50}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string ItemId;
            AZStd::unordered_map<AZStd::string, Uint32> VirtualCurrencyPrices;
            AZStd::unordered_map<AZStd::string, Uint32> RealCurrencyPrices;
            MultitypeVar CustomData;
            OptionalUint32 DisplayPosition;

            StoreItem() :
                PlayFabBaseModel(),
                ItemId(),
                VirtualCurrencyPrices(),
                RealCurrencyPrices(),
                CustomData(),
                DisplayPosition()
            {}

            StoreItem(const StoreItem& src) :
                PlayFabBaseModel(),
                ItemId(src.ItemId),
                VirtualCurrencyPrices(src.VirtualCurrencyPrices),
                RealCurrencyPrices(src.RealCurrencyPrices),
                CustomData(src.CustomData),
                DisplayPosition(src.DisplayPosition)
            {}

            StoreItem(const rapidjson::Value& obj) : StoreItem()
            {
                readFromValue(obj);
            }

            ~StoreItem()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ItemId");
                writer.String(ItemId.c_str());
                if (!VirtualCurrencyPrices.empty()) {
                    writer.String("VirtualCurrencyPrices");
                    writer.StartObject();
                    for (auto iter = VirtualCurrencyPrices.begin(); iter != VirtualCurrencyPrices.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                if (!RealCurrencyPrices.empty()) {
                    writer.String("RealCurrencyPrices");
                    writer.StartObject();
                    for (auto iter = RealCurrencyPrices.begin(); iter != RealCurrencyPrices.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                if (CustomData.notNull()) {
                    writer.String("CustomData");
                    CustomData.writeJSON(writer);
                }
                if (DisplayPosition.notNull()) {
                    writer.String("DisplayPosition");
                    writer.Uint(DisplayPosition);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
                const Value::ConstMemberIterator VirtualCurrencyPrices_member = obj.FindMember("VirtualCurrencyPrices");
                if (VirtualCurrencyPrices_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrencyPrices_member->value.MemberBegin(); iter != VirtualCurrencyPrices_member->value.MemberEnd(); ++iter) {
                        VirtualCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
                    }
                }
                const Value::ConstMemberIterator RealCurrencyPrices_member = obj.FindMember("RealCurrencyPrices");
                if (RealCurrencyPrices_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = RealCurrencyPrices_member->value.MemberBegin(); iter != RealCurrencyPrices_member->value.MemberEnd(); ++iter) {
                        RealCurrencyPrices[iter->name.GetString()] = iter->value.GetUint();
                    }
                }
                const Value::ConstMemberIterator CustomData_member = obj.FindMember("CustomData");
                if (CustomData_member != obj.MemberEnd() && !CustomData_member->value.IsNull()) CustomData = MultitypeVar(CustomData_member->value);
                const Value::ConstMemberIterator DisplayPosition_member = obj.FindMember("DisplayPosition");
                if (DisplayPosition_member != obj.MemberEnd() && !DisplayPosition_member->value.IsNull()) DisplayPosition = DisplayPosition_member->value.GetUint();

                return true;
            }
        };

        enum SourceType
        {
            SourceTypeAdmin,
            SourceTypeBackEnd,
            SourceTypeGameClient,
            SourceTypeGameServer,
            SourceTypePartner
        };

        inline void writeSourceTypeEnumJSON(SourceType enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case SourceTypeAdmin: writer.String("Admin"); break;
            case SourceTypeBackEnd: writer.String("BackEnd"); break;
            case SourceTypeGameClient: writer.String("GameClient"); break;
            case SourceTypeGameServer: writer.String("GameServer"); break;
            case SourceTypePartner: writer.String("Partner"); break;

            }
        }

        inline SourceType readSourceTypeFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<SourceType>(obj.GetInt());

            static std::map<const char *, SourceType, PlayFabComboSdk::StringCompare> _SourceTypeMap;
            if (_SourceTypeMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _SourceTypeMap["Admin"] = SourceTypeAdmin;
                _SourceTypeMap["BackEnd"] = SourceTypeBackEnd;
                _SourceTypeMap["GameClient"] = SourceTypeGameClient;
                _SourceTypeMap["GameServer"] = SourceTypeGameServer;
                _SourceTypeMap["Partner"] = SourceTypePartner;

            }

            auto output = _SourceTypeMap.find(obj.GetString());
            if (output != _SourceTypeMap.end())
                return output->second;

            return SourceTypeAdmin; // Basically critical fail
        }

        struct StoreMarketingModel : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::StoreMarketingModel,"{6486cb0e-bd34-5191-aa5a-32c4e5f380dc}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string DisplayName;
            AZStd::string Description;
            MultitypeVar Metadata;

            StoreMarketingModel() :
                PlayFabBaseModel(),
                DisplayName(),
                Description(),
                Metadata()
            {}

            StoreMarketingModel(const StoreMarketingModel& src) :
                PlayFabBaseModel(),
                DisplayName(src.DisplayName),
                Description(src.Description),
                Metadata(src.Metadata)
            {}

            StoreMarketingModel(const rapidjson::Value& obj) : StoreMarketingModel()
            {
                readFromValue(obj);
            }

            ~StoreMarketingModel()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (DisplayName.length() > 0) {
                    writer.String("DisplayName");
                    writer.String(DisplayName.c_str());
                }
                if (Description.length() > 0) {
                    writer.String("Description");
                    writer.String(Description.c_str());
                }
                if (Metadata.notNull()) {
                    writer.String("Metadata");
                    Metadata.writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator Description_member = obj.FindMember("Description");
                if (Description_member != obj.MemberEnd() && !Description_member->value.IsNull()) Description = Description_member->value.GetString();
                const Value::ConstMemberIterator Metadata_member = obj.FindMember("Metadata");
                if (Metadata_member != obj.MemberEnd() && !Metadata_member->value.IsNull()) Metadata = MultitypeVar(Metadata_member->value);

                return true;
            }
        };

        struct GetStoreItemsResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetStoreItemsResult,"{1d01c176-ee8b-5fa0-987d-b11a3b9144ee}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<StoreItem> Store; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            Boxed<SourceType> Source;
            AZStd::string CatalogVersion;
            AZStd::string StoreId;
            StoreMarketingModel* MarketingData;

            GetStoreItemsResult() :
                PlayFabBaseModel(),
                Store(),
                Source(),
                CatalogVersion(),
                StoreId(),
                MarketingData(nullptr)
            {}

            GetStoreItemsResult(const GetStoreItemsResult& src) :
                PlayFabBaseModel(),
                Store(src.Store),
                Source(src.Source),
                CatalogVersion(src.CatalogVersion),
                StoreId(src.StoreId),
                MarketingData(src.MarketingData ? new StoreMarketingModel(*src.MarketingData) : nullptr)
            {}

            GetStoreItemsResult(const rapidjson::Value& obj) : GetStoreItemsResult()
            {
                readFromValue(obj);
            }

            ~GetStoreItemsResult()
            {
                if (MarketingData != nullptr) delete MarketingData;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Store.empty()) {
                    writer.String("Store");
                    writer.StartArray();
                    for (auto iter = Store.begin(); iter != Store.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (Source.notNull()) {
                    writer.String("Source");
                    writeSourceTypeEnumJSON(Source, writer);
                }
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                if (StoreId.length() > 0) {
                    writer.String("StoreId");
                    writer.String(StoreId.c_str());
                }
                if (MarketingData != nullptr) {
                    writer.String("MarketingData");
                    MarketingData->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Store_member = obj.FindMember("Store");
                if (Store_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Store_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Store.push_back(StoreItem(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator Source_member = obj.FindMember("Source");
                if (Source_member != obj.MemberEnd() && !Source_member->value.IsNull()) Source = readSourceTypeFromValue(Source_member->value);
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator StoreId_member = obj.FindMember("StoreId");
                if (StoreId_member != obj.MemberEnd() && !StoreId_member->value.IsNull()) StoreId = StoreId_member->value.GetString();
                const Value::ConstMemberIterator MarketingData_member = obj.FindMember("MarketingData");
                if (MarketingData_member != obj.MemberEnd() && !MarketingData_member->value.IsNull()) MarketingData = new StoreMarketingModel(MarketingData_member->value);

                return true;
            }
        };

        struct GetTimeRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetTimeRequest,"{f3c1c170-a933-569c-8af4-2a8484d6b0d6}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            GetTimeRequest() :
                PlayFabBaseModel()
            {}

            GetTimeRequest(const GetTimeRequest& src) :
                PlayFabBaseModel()
            {}

            GetTimeRequest(const rapidjson::Value& obj) : GetTimeRequest()
            {
                readFromValue(obj);
            }

            ~GetTimeRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct GetTimeResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetTimeResult,"{9f044b09-8e75-5fb0-b4e2-1831e2662e17}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            time_t Time;

            GetTimeResult() :
                PlayFabBaseModel(),
                Time(0)
            {}

            GetTimeResult(const GetTimeResult& src) :
                PlayFabBaseModel(),
                Time(src.Time)
            {}

            GetTimeResult(const rapidjson::Value& obj) : GetTimeResult()
            {
                readFromValue(obj);
            }

            ~GetTimeResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Time");
                writeDatetime(Time, writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Time_member = obj.FindMember("Time");
                if (Time_member != obj.MemberEnd() && !Time_member->value.IsNull()) Time = readDatetime(Time_member->value);

                return true;
            }
        };

        struct GetTitleDataRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetTitleDataRequest,"{be70bda3-84a0-50c8-b7c8-9c76cd78063a}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<AZStd::string> Keys; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetTitleDataRequest() :
                PlayFabBaseModel(),
                Keys()
            {}

            GetTitleDataRequest(const GetTitleDataRequest& src) :
                PlayFabBaseModel(),
                Keys(src.Keys)
            {}

            GetTitleDataRequest(const rapidjson::Value& obj) : GetTitleDataRequest()
            {
                readFromValue(obj);
            }

            ~GetTitleDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Keys.empty()) {
                    writer.String("Keys");
                    writer.StartArray();
                    for (auto iter = Keys.begin(); iter != Keys.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
                if (Keys_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Keys_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Keys.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct GetTitleDataResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetTitleDataResult,"{c6c7c47a-bcb1-5937-a186-082655e17a03}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::unordered_map<AZStd::string, AZStd::string> Data;

            GetTitleDataResult() :
                PlayFabBaseModel(),
                Data()
            {}

            GetTitleDataResult(const GetTitleDataResult& src) :
                PlayFabBaseModel(),
                Data(src.Data)
            {}

            GetTitleDataResult(const rapidjson::Value& obj) : GetTitleDataResult()
            {
                readFromValue(obj);
            }

            ~GetTitleDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartObject();
                    for (auto iter = Data.begin(); iter != Data.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
                        Data[iter->name.GetString()] = iter->value.GetString();
                    }
                }

                return true;
            }
        };

        struct GetTitleNewsRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetTitleNewsRequest,"{3b8a16e6-34a4-5f2a-85d3-6627a92597fb}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            OptionalInt32 Count;

            GetTitleNewsRequest() :
                PlayFabBaseModel(),
                Count()
            {}

            GetTitleNewsRequest(const GetTitleNewsRequest& src) :
                PlayFabBaseModel(),
                Count(src.Count)
            {}

            GetTitleNewsRequest(const rapidjson::Value& obj) : GetTitleNewsRequest()
            {
                readFromValue(obj);
            }

            ~GetTitleNewsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Count.notNull()) {
                    writer.String("Count");
                    writer.Int(Count);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Count_member = obj.FindMember("Count");
                if (Count_member != obj.MemberEnd() && !Count_member->value.IsNull()) Count = Count_member->value.GetInt();

                return true;
            }
        };

        struct TitleNewsItem : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::TitleNewsItem,"{2fcf048f-0bcf-57aa-9c22-e91b267f6311}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            time_t Timestamp;
            AZStd::string NewsId;
            AZStd::string Title;
            AZStd::string Body;

            TitleNewsItem() :
                PlayFabBaseModel(),
                Timestamp(0),
                NewsId(),
                Title(),
                Body()
            {}

            TitleNewsItem(const TitleNewsItem& src) :
                PlayFabBaseModel(),
                Timestamp(src.Timestamp),
                NewsId(src.NewsId),
                Title(src.Title),
                Body(src.Body)
            {}

            TitleNewsItem(const rapidjson::Value& obj) : TitleNewsItem()
            {
                readFromValue(obj);
            }

            ~TitleNewsItem()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Timestamp");
                writeDatetime(Timestamp, writer);
                if (NewsId.length() > 0) {
                    writer.String("NewsId");
                    writer.String(NewsId.c_str());
                }
                if (Title.length() > 0) {
                    writer.String("Title");
                    writer.String(Title.c_str());
                }
                if (Body.length() > 0) {
                    writer.String("Body");
                    writer.String(Body.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
                if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
                const Value::ConstMemberIterator NewsId_member = obj.FindMember("NewsId");
                if (NewsId_member != obj.MemberEnd() && !NewsId_member->value.IsNull()) NewsId = NewsId_member->value.GetString();
                const Value::ConstMemberIterator Title_member = obj.FindMember("Title");
                if (Title_member != obj.MemberEnd() && !Title_member->value.IsNull()) Title = Title_member->value.GetString();
                const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
                if (Body_member != obj.MemberEnd() && !Body_member->value.IsNull()) Body = Body_member->value.GetString();

                return true;
            }
        };

        struct GetTitleNewsResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetTitleNewsResult,"{386c218c-e47d-50c7-b9d2-70994a797987}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<TitleNewsItem> News; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            GetTitleNewsResult() :
                PlayFabBaseModel(),
                News()
            {}

            GetTitleNewsResult(const GetTitleNewsResult& src) :
                PlayFabBaseModel(),
                News(src.News)
            {}

            GetTitleNewsResult(const rapidjson::Value& obj) : GetTitleNewsResult()
            {
                readFromValue(obj);
            }

            ~GetTitleNewsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!News.empty()) {
                    writer.String("News");
                    writer.StartArray();
                    for (auto iter = News.begin(); iter != News.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator News_member = obj.FindMember("News");
                if (News_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = News_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        News.push_back(TitleNewsItem(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetTitlePublicKeyRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetTitlePublicKeyRequest,"{9f1b160d-5e23-52ec-8431-dcb653798eca}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string TitleId;
            AZStd::string TitleSharedSecret;

            GetTitlePublicKeyRequest() :
                PlayFabBaseModel(),
                TitleId(),
                TitleSharedSecret()
            {}

            GetTitlePublicKeyRequest(const GetTitlePublicKeyRequest& src) :
                PlayFabBaseModel(),
                TitleId(src.TitleId),
                TitleSharedSecret(src.TitleSharedSecret)
            {}

            GetTitlePublicKeyRequest(const rapidjson::Value& obj) : GetTitlePublicKeyRequest()
            {
                readFromValue(obj);
            }

            ~GetTitlePublicKeyRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                writer.String("TitleSharedSecret");
                writer.String(TitleSharedSecret.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator TitleSharedSecret_member = obj.FindMember("TitleSharedSecret");
                if (TitleSharedSecret_member != obj.MemberEnd() && !TitleSharedSecret_member->value.IsNull()) TitleSharedSecret = TitleSharedSecret_member->value.GetString();

                return true;
            }
        };

        struct GetTitlePublicKeyResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetTitlePublicKeyResult,"{27d91643-3ca3-56b1-ba80-acdc67b8f76c}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string RSAPublicKey;

            GetTitlePublicKeyResult() :
                PlayFabBaseModel(),
                RSAPublicKey()
            {}

            GetTitlePublicKeyResult(const GetTitlePublicKeyResult& src) :
                PlayFabBaseModel(),
                RSAPublicKey(src.RSAPublicKey)
            {}

            GetTitlePublicKeyResult(const rapidjson::Value& obj) : GetTitlePublicKeyResult()
            {
                readFromValue(obj);
            }

            ~GetTitlePublicKeyResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (RSAPublicKey.length() > 0) {
                    writer.String("RSAPublicKey");
                    writer.String(RSAPublicKey.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator RSAPublicKey_member = obj.FindMember("RSAPublicKey");
                if (RSAPublicKey_member != obj.MemberEnd() && !RSAPublicKey_member->value.IsNull()) RSAPublicKey = RSAPublicKey_member->value.GetString();

                return true;
            }
        };

        struct GetTradeStatusRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetTradeStatusRequest,"{44e83593-039b-5a84-a098-7b211958e374}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string OfferingPlayerId;
            AZStd::string TradeId;

            GetTradeStatusRequest() :
                PlayFabBaseModel(),
                OfferingPlayerId(),
                TradeId()
            {}

            GetTradeStatusRequest(const GetTradeStatusRequest& src) :
                PlayFabBaseModel(),
                OfferingPlayerId(src.OfferingPlayerId),
                TradeId(src.TradeId)
            {}

            GetTradeStatusRequest(const rapidjson::Value& obj) : GetTradeStatusRequest()
            {
                readFromValue(obj);
            }

            ~GetTradeStatusRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("OfferingPlayerId");
                writer.String(OfferingPlayerId.c_str());
                writer.String("TradeId");
                writer.String(TradeId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator OfferingPlayerId_member = obj.FindMember("OfferingPlayerId");
                if (OfferingPlayerId_member != obj.MemberEnd() && !OfferingPlayerId_member->value.IsNull()) OfferingPlayerId = OfferingPlayerId_member->value.GetString();
                const Value::ConstMemberIterator TradeId_member = obj.FindMember("TradeId");
                if (TradeId_member != obj.MemberEnd() && !TradeId_member->value.IsNull()) TradeId = TradeId_member->value.GetString();

                return true;
            }
        };

        struct GetTradeStatusResponse : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetTradeStatusResponse,"{47adaf94-2475-5783-8260-39b0ad3900b8}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            TradeInfo* Trade;

            GetTradeStatusResponse() :
                PlayFabBaseModel(),
                Trade(nullptr)
            {}

            GetTradeStatusResponse(const GetTradeStatusResponse& src) :
                PlayFabBaseModel(),
                Trade(src.Trade ? new TradeInfo(*src.Trade) : nullptr)
            {}

            GetTradeStatusResponse(const rapidjson::Value& obj) : GetTradeStatusResponse()
            {
                readFromValue(obj);
            }

            ~GetTradeStatusResponse()
            {
                if (Trade != nullptr) delete Trade;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Trade != nullptr) {
                    writer.String("Trade");
                    Trade->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Trade_member = obj.FindMember("Trade");
                if (Trade_member != obj.MemberEnd() && !Trade_member->value.IsNull()) Trade = new TradeInfo(Trade_member->value);

                return true;
            }
        };

        struct GetUserDataRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetUserDataRequest,"{b725f2a9-535e-589f-8c3d-46f77773d098}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<AZStd::string> Keys; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::string PlayFabId;
            OptionalUint32 IfChangedFromDataVersion;

            GetUserDataRequest() :
                PlayFabBaseModel(),
                Keys(),
                PlayFabId(),
                IfChangedFromDataVersion()
            {}

            GetUserDataRequest(const GetUserDataRequest& src) :
                PlayFabBaseModel(),
                Keys(src.Keys),
                PlayFabId(src.PlayFabId),
                IfChangedFromDataVersion(src.IfChangedFromDataVersion)
            {}

            GetUserDataRequest(const rapidjson::Value& obj) : GetUserDataRequest()
            {
                readFromValue(obj);
            }

            ~GetUserDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Keys.empty()) {
                    writer.String("Keys");
                    writer.StartArray();
                    for (auto iter = Keys.begin(); iter != Keys.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                if (IfChangedFromDataVersion.notNull()) {
                    writer.String("IfChangedFromDataVersion");
                    writer.Uint(IfChangedFromDataVersion);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Keys_member = obj.FindMember("Keys");
                if (Keys_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Keys_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Keys.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator IfChangedFromDataVersion_member = obj.FindMember("IfChangedFromDataVersion");
                if (IfChangedFromDataVersion_member != obj.MemberEnd() && !IfChangedFromDataVersion_member->value.IsNull()) IfChangedFromDataVersion = IfChangedFromDataVersion_member->value.GetUint();

                return true;
            }
        };

        struct GetUserDataResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetUserDataResult,"{734a8efb-8466-5e8e-962c-dfd0f9acd900}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::unordered_map<AZStd::string, UserDataRecord> Data;
            Uint32 DataVersion;

            GetUserDataResult() :
                PlayFabBaseModel(),
                Data(),
                DataVersion(0)
            {}

            GetUserDataResult(const GetUserDataResult& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                DataVersion(src.DataVersion)
            {}

            GetUserDataResult(const rapidjson::Value& obj) : GetUserDataResult()
            {
                readFromValue(obj);
            }

            ~GetUserDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartObject();
                    for (auto iter = Data.begin(); iter != Data.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.String("DataVersion");
                writer.Uint(DataVersion);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
                        Data[iter->name.GetString()] = UserDataRecord(iter->value);
                    }
                }
                const Value::ConstMemberIterator DataVersion_member = obj.FindMember("DataVersion");
                if (DataVersion_member != obj.MemberEnd() && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();

                return true;
            }
        };

        struct GetUserInventoryRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetUserInventoryRequest,"{9579de40-cd0d-5892-b1e2-e973a41cd788}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            GetUserInventoryRequest() :
                PlayFabBaseModel()
            {}

            GetUserInventoryRequest(const GetUserInventoryRequest& src) :
                PlayFabBaseModel()
            {}

            GetUserInventoryRequest(const rapidjson::Value& obj) : GetUserInventoryRequest()
            {
                readFromValue(obj);
            }

            ~GetUserInventoryRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct GetUserInventoryResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetUserInventoryResult,"{5cd88279-d1eb-5f85-a34d-1b562732ab12}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<ItemInstance> Inventory; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::unordered_map<AZStd::string, Int32> VirtualCurrency;
            AZStd::unordered_map<AZStd::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            GetUserInventoryResult() :
                PlayFabBaseModel(),
                Inventory(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            GetUserInventoryResult(const GetUserInventoryResult& src) :
                PlayFabBaseModel(),
                Inventory(src.Inventory),
                VirtualCurrency(src.VirtualCurrency),
                VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes)
            {}

            GetUserInventoryResult(const rapidjson::Value& obj) : GetUserInventoryResult()
            {
                readFromValue(obj);
            }

            ~GetUserInventoryResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Inventory.empty()) {
                    writer.String("Inventory");
                    writer.StartArray();
                    for (auto iter = Inventory.begin(); iter != Inventory.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!VirtualCurrency.empty()) {
                    writer.String("VirtualCurrency");
                    writer.StartObject();
                    for (auto iter = VirtualCurrency.begin(); iter != VirtualCurrency.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.Int(iter->second);
                    }
                    writer.EndObject();
                }
                if (!VirtualCurrencyRechargeTimes.empty()) {
                    writer.String("VirtualCurrencyRechargeTimes");
                    writer.StartObject();
                    for (auto iter = VirtualCurrencyRechargeTimes.begin(); iter != VirtualCurrencyRechargeTimes.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Inventory_member = obj.FindMember("Inventory");
                if (Inventory_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Inventory_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Inventory.push_back(ItemInstance(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrency_member->value.MemberBegin(); iter != VirtualCurrency_member->value.MemberEnd(); ++iter) {
                        VirtualCurrency[iter->name.GetString()] = iter->value.GetInt();
                    }
                }
                const Value::ConstMemberIterator VirtualCurrencyRechargeTimes_member = obj.FindMember("VirtualCurrencyRechargeTimes");
                if (VirtualCurrencyRechargeTimes_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrencyRechargeTimes_member->value.MemberBegin(); iter != VirtualCurrencyRechargeTimes_member->value.MemberEnd(); ++iter) {
                        VirtualCurrencyRechargeTimes[iter->name.GetString()] = VirtualCurrencyRechargeTime(iter->value);
                    }
                }

                return true;
            }
        };

        struct GetWindowsHelloChallengeRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetWindowsHelloChallengeRequest,"{71690b4d-6d8a-5236-876e-4a46a8e34739}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string TitleId;
            AZStd::string PublicKeyHint;

            GetWindowsHelloChallengeRequest() :
                PlayFabBaseModel(),
                TitleId(),
                PublicKeyHint()
            {}

            GetWindowsHelloChallengeRequest(const GetWindowsHelloChallengeRequest& src) :
                PlayFabBaseModel(),
                TitleId(src.TitleId),
                PublicKeyHint(src.PublicKeyHint)
            {}

            GetWindowsHelloChallengeRequest(const rapidjson::Value& obj) : GetWindowsHelloChallengeRequest()
            {
                readFromValue(obj);
            }

            ~GetWindowsHelloChallengeRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                writer.String("PublicKeyHint");
                writer.String(PublicKeyHint.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator PublicKeyHint_member = obj.FindMember("PublicKeyHint");
                if (PublicKeyHint_member != obj.MemberEnd() && !PublicKeyHint_member->value.IsNull()) PublicKeyHint = PublicKeyHint_member->value.GetString();

                return true;
            }
        };

        struct GetWindowsHelloChallengeResponse : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GetWindowsHelloChallengeResponse,"{da24b79c-6787-53b0-af4a-01e4dd580561}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string Challenge;

            GetWindowsHelloChallengeResponse() :
                PlayFabBaseModel(),
                Challenge()
            {}

            GetWindowsHelloChallengeResponse(const GetWindowsHelloChallengeResponse& src) :
                PlayFabBaseModel(),
                Challenge(src.Challenge)
            {}

            GetWindowsHelloChallengeResponse(const rapidjson::Value& obj) : GetWindowsHelloChallengeResponse()
            {
                readFromValue(obj);
            }

            ~GetWindowsHelloChallengeResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Challenge.length() > 0) {
                    writer.String("Challenge");
                    writer.String(Challenge.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Challenge_member = obj.FindMember("Challenge");
                if (Challenge_member != obj.MemberEnd() && !Challenge_member->value.IsNull()) Challenge = Challenge_member->value.GetString();

                return true;
            }
        };

        struct GrantCharacterToUserRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GrantCharacterToUserRequest,"{e8475d27-06a3-5974-ab5d-ce713d4ba8f3}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string CatalogVersion;
            AZStd::string ItemId;
            AZStd::string CharacterName;

            GrantCharacterToUserRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                ItemId(),
                CharacterName()
            {}

            GrantCharacterToUserRequest(const GrantCharacterToUserRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                ItemId(src.ItemId),
                CharacterName(src.CharacterName)
            {}

            GrantCharacterToUserRequest(const rapidjson::Value& obj) : GrantCharacterToUserRequest()
            {
                readFromValue(obj);
            }

            ~GrantCharacterToUserRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                writer.String("ItemId");
                writer.String(ItemId.c_str());
                writer.String("CharacterName");
                writer.String(CharacterName.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
                const Value::ConstMemberIterator CharacterName_member = obj.FindMember("CharacterName");
                if (CharacterName_member != obj.MemberEnd() && !CharacterName_member->value.IsNull()) CharacterName = CharacterName_member->value.GetString();

                return true;
            }
        };

        struct GrantCharacterToUserResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::GrantCharacterToUserResult,"{0f0bd6ad-f925-524f-8414-fa2c1af42968}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string CharacterId;
            AZStd::string CharacterType;
            bool Result;

            GrantCharacterToUserResult() :
                PlayFabBaseModel(),
                CharacterId(),
                CharacterType(),
                Result(false)
            {}

            GrantCharacterToUserResult(const GrantCharacterToUserResult& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CharacterType(src.CharacterType),
                Result(src.Result)
            {}

            GrantCharacterToUserResult(const rapidjson::Value& obj) : GrantCharacterToUserResult()
            {
                readFromValue(obj);
            }

            ~GrantCharacterToUserResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                if (CharacterType.length() > 0) {
                    writer.String("CharacterType");
                    writer.String(CharacterType.c_str());
                }
                writer.String("Result");
                writer.Bool(Result);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator CharacterType_member = obj.FindMember("CharacterType");
                if (CharacterType_member != obj.MemberEnd() && !CharacterType_member->value.IsNull()) CharacterType = CharacterType_member->value.GetString();
                const Value::ConstMemberIterator Result_member = obj.FindMember("Result");
                if (Result_member != obj.MemberEnd() && !Result_member->value.IsNull()) Result = Result_member->value.GetBool();

                return true;
            }
        };

        struct ItemPurchaseRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ItemPurchaseRequest,"{027d38c2-da5a-59a8-bc26-1c35ac75344e}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string ItemId;
            Uint32 Quantity;
            AZStd::string Annotation;
            AZStd::vector<AZStd::string> UpgradeFromItems; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            ItemPurchaseRequest() :
                PlayFabBaseModel(),
                ItemId(),
                Quantity(0),
                Annotation(),
                UpgradeFromItems()
            {}

            ItemPurchaseRequest(const ItemPurchaseRequest& src) :
                PlayFabBaseModel(),
                ItemId(src.ItemId),
                Quantity(src.Quantity),
                Annotation(src.Annotation),
                UpgradeFromItems(src.UpgradeFromItems)
            {}

            ItemPurchaseRequest(const rapidjson::Value& obj) : ItemPurchaseRequest()
            {
                readFromValue(obj);
            }

            ~ItemPurchaseRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ItemId");
                writer.String(ItemId.c_str());
                writer.String("Quantity");
                writer.Uint(Quantity);
                if (Annotation.length() > 0) {
                    writer.String("Annotation");
                    writer.String(Annotation.c_str());
                }
                if (!UpgradeFromItems.empty()) {
                    writer.String("UpgradeFromItems");
                    writer.StartArray();
                    for (auto iter = UpgradeFromItems.begin(); iter != UpgradeFromItems.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
                const Value::ConstMemberIterator Quantity_member = obj.FindMember("Quantity");
                if (Quantity_member != obj.MemberEnd() && !Quantity_member->value.IsNull()) Quantity = Quantity_member->value.GetUint();
                const Value::ConstMemberIterator Annotation_member = obj.FindMember("Annotation");
                if (Annotation_member != obj.MemberEnd() && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
                const Value::ConstMemberIterator UpgradeFromItems_member = obj.FindMember("UpgradeFromItems");
                if (UpgradeFromItems_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = UpgradeFromItems_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        UpgradeFromItems.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct LinkAndroidDeviceIDRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LinkAndroidDeviceIDRequest,"{89976c0c-801c-5dcc-a001-212453b55d5f}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string AndroidDeviceId;
            AZStd::string OS;
            AZStd::string AndroidDevice;
            OptionalBool ForceLink;

            LinkAndroidDeviceIDRequest() :
                PlayFabBaseModel(),
                AndroidDeviceId(),
                OS(),
                AndroidDevice(),
                ForceLink()
            {}

            LinkAndroidDeviceIDRequest(const LinkAndroidDeviceIDRequest& src) :
                PlayFabBaseModel(),
                AndroidDeviceId(src.AndroidDeviceId),
                OS(src.OS),
                AndroidDevice(src.AndroidDevice),
                ForceLink(src.ForceLink)
            {}

            LinkAndroidDeviceIDRequest(const rapidjson::Value& obj) : LinkAndroidDeviceIDRequest()
            {
                readFromValue(obj);
            }

            ~LinkAndroidDeviceIDRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("AndroidDeviceId");
                writer.String(AndroidDeviceId.c_str());
                if (OS.length() > 0) {
                    writer.String("OS");
                    writer.String(OS.c_str());
                }
                if (AndroidDevice.length() > 0) {
                    writer.String("AndroidDevice");
                    writer.String(AndroidDevice.c_str());
                }
                if (ForceLink.notNull()) {
                    writer.String("ForceLink");
                    writer.Bool(ForceLink);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AndroidDeviceId_member = obj.FindMember("AndroidDeviceId");
                if (AndroidDeviceId_member != obj.MemberEnd() && !AndroidDeviceId_member->value.IsNull()) AndroidDeviceId = AndroidDeviceId_member->value.GetString();
                const Value::ConstMemberIterator OS_member = obj.FindMember("OS");
                if (OS_member != obj.MemberEnd() && !OS_member->value.IsNull()) OS = OS_member->value.GetString();
                const Value::ConstMemberIterator AndroidDevice_member = obj.FindMember("AndroidDevice");
                if (AndroidDevice_member != obj.MemberEnd() && !AndroidDevice_member->value.IsNull()) AndroidDevice = AndroidDevice_member->value.GetString();
                const Value::ConstMemberIterator ForceLink_member = obj.FindMember("ForceLink");
                if (ForceLink_member != obj.MemberEnd() && !ForceLink_member->value.IsNull()) ForceLink = ForceLink_member->value.GetBool();

                return true;
            }
        };

        struct LinkAndroidDeviceIDResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LinkAndroidDeviceIDResult,"{66497823-4158-51a4-8168-a23d2f2d3265}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            LinkAndroidDeviceIDResult() :
                PlayFabBaseModel()
            {}

            LinkAndroidDeviceIDResult(const LinkAndroidDeviceIDResult& src) :
                PlayFabBaseModel()
            {}

            LinkAndroidDeviceIDResult(const rapidjson::Value& obj) : LinkAndroidDeviceIDResult()
            {
                readFromValue(obj);
            }

            ~LinkAndroidDeviceIDResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct LinkCustomIDRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LinkCustomIDRequest,"{9ea1a0e2-200d-5ccb-835c-6870efd6287d}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string CustomId;
            OptionalBool ForceLink;

            LinkCustomIDRequest() :
                PlayFabBaseModel(),
                CustomId(),
                ForceLink()
            {}

            LinkCustomIDRequest(const LinkCustomIDRequest& src) :
                PlayFabBaseModel(),
                CustomId(src.CustomId),
                ForceLink(src.ForceLink)
            {}

            LinkCustomIDRequest(const rapidjson::Value& obj) : LinkCustomIDRequest()
            {
                readFromValue(obj);
            }

            ~LinkCustomIDRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("CustomId");
                writer.String(CustomId.c_str());
                if (ForceLink.notNull()) {
                    writer.String("ForceLink");
                    writer.Bool(ForceLink);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CustomId_member = obj.FindMember("CustomId");
                if (CustomId_member != obj.MemberEnd() && !CustomId_member->value.IsNull()) CustomId = CustomId_member->value.GetString();
                const Value::ConstMemberIterator ForceLink_member = obj.FindMember("ForceLink");
                if (ForceLink_member != obj.MemberEnd() && !ForceLink_member->value.IsNull()) ForceLink = ForceLink_member->value.GetBool();

                return true;
            }
        };

        struct LinkCustomIDResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LinkCustomIDResult,"{4c95cdd1-51fb-5d16-9be5-72f5c2d9c6fe}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            LinkCustomIDResult() :
                PlayFabBaseModel()
            {}

            LinkCustomIDResult(const LinkCustomIDResult& src) :
                PlayFabBaseModel()
            {}

            LinkCustomIDResult(const rapidjson::Value& obj) : LinkCustomIDResult()
            {
                readFromValue(obj);
            }

            ~LinkCustomIDResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct LinkFacebookAccountRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LinkFacebookAccountRequest,"{fae52fd4-4744-54ad-ad58-ac5d1c0141fe}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string AccessToken;
            OptionalBool ForceLink;

            LinkFacebookAccountRequest() :
                PlayFabBaseModel(),
                AccessToken(),
                ForceLink()
            {}

            LinkFacebookAccountRequest(const LinkFacebookAccountRequest& src) :
                PlayFabBaseModel(),
                AccessToken(src.AccessToken),
                ForceLink(src.ForceLink)
            {}

            LinkFacebookAccountRequest(const rapidjson::Value& obj) : LinkFacebookAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkFacebookAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("AccessToken");
                writer.String(AccessToken.c_str());
                if (ForceLink.notNull()) {
                    writer.String("ForceLink");
                    writer.Bool(ForceLink);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AccessToken_member = obj.FindMember("AccessToken");
                if (AccessToken_member != obj.MemberEnd() && !AccessToken_member->value.IsNull()) AccessToken = AccessToken_member->value.GetString();
                const Value::ConstMemberIterator ForceLink_member = obj.FindMember("ForceLink");
                if (ForceLink_member != obj.MemberEnd() && !ForceLink_member->value.IsNull()) ForceLink = ForceLink_member->value.GetBool();

                return true;
            }
        };

        struct LinkFacebookAccountResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LinkFacebookAccountResult,"{94000132-6912-5c45-88a7-a99ccaa3d9c0}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            LinkFacebookAccountResult() :
                PlayFabBaseModel()
            {}

            LinkFacebookAccountResult(const LinkFacebookAccountResult& src) :
                PlayFabBaseModel()
            {}

            LinkFacebookAccountResult(const rapidjson::Value& obj) : LinkFacebookAccountResult()
            {
                readFromValue(obj);
            }

            ~LinkFacebookAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct LinkGameCenterAccountRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LinkGameCenterAccountRequest,"{9c279b49-46d2-5316-a0af-3798a34df156}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string GameCenterId;
            OptionalBool ForceLink;

            LinkGameCenterAccountRequest() :
                PlayFabBaseModel(),
                GameCenterId(),
                ForceLink()
            {}

            LinkGameCenterAccountRequest(const LinkGameCenterAccountRequest& src) :
                PlayFabBaseModel(),
                GameCenterId(src.GameCenterId),
                ForceLink(src.ForceLink)
            {}

            LinkGameCenterAccountRequest(const rapidjson::Value& obj) : LinkGameCenterAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkGameCenterAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("GameCenterId");
                writer.String(GameCenterId.c_str());
                if (ForceLink.notNull()) {
                    writer.String("ForceLink");
                    writer.Bool(ForceLink);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GameCenterId_member = obj.FindMember("GameCenterId");
                if (GameCenterId_member != obj.MemberEnd() && !GameCenterId_member->value.IsNull()) GameCenterId = GameCenterId_member->value.GetString();
                const Value::ConstMemberIterator ForceLink_member = obj.FindMember("ForceLink");
                if (ForceLink_member != obj.MemberEnd() && !ForceLink_member->value.IsNull()) ForceLink = ForceLink_member->value.GetBool();

                return true;
            }
        };

        struct LinkGameCenterAccountResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LinkGameCenterAccountResult,"{3aa64c4b-f846-5f77-a151-bc540aad61c9}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            LinkGameCenterAccountResult() :
                PlayFabBaseModel()
            {}

            LinkGameCenterAccountResult(const LinkGameCenterAccountResult& src) :
                PlayFabBaseModel()
            {}

            LinkGameCenterAccountResult(const rapidjson::Value& obj) : LinkGameCenterAccountResult()
            {
                readFromValue(obj);
            }

            ~LinkGameCenterAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct LinkGoogleAccountRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LinkGoogleAccountRequest,"{473504d8-e2f5-52f7-b665-99e771342b76}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string ServerAuthCode;
            OptionalBool ForceLink;

            LinkGoogleAccountRequest() :
                PlayFabBaseModel(),
                ServerAuthCode(),
                ForceLink()
            {}

            LinkGoogleAccountRequest(const LinkGoogleAccountRequest& src) :
                PlayFabBaseModel(),
                ServerAuthCode(src.ServerAuthCode),
                ForceLink(src.ForceLink)
            {}

            LinkGoogleAccountRequest(const rapidjson::Value& obj) : LinkGoogleAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkGoogleAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (ServerAuthCode.length() > 0) {
                    writer.String("ServerAuthCode");
                    writer.String(ServerAuthCode.c_str());
                }
                if (ForceLink.notNull()) {
                    writer.String("ForceLink");
                    writer.Bool(ForceLink);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ServerAuthCode_member = obj.FindMember("ServerAuthCode");
                if (ServerAuthCode_member != obj.MemberEnd() && !ServerAuthCode_member->value.IsNull()) ServerAuthCode = ServerAuthCode_member->value.GetString();
                const Value::ConstMemberIterator ForceLink_member = obj.FindMember("ForceLink");
                if (ForceLink_member != obj.MemberEnd() && !ForceLink_member->value.IsNull()) ForceLink = ForceLink_member->value.GetBool();

                return true;
            }
        };

        struct LinkGoogleAccountResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LinkGoogleAccountResult,"{2f35410c-2de0-5e86-8afa-f80bfaf10834}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            LinkGoogleAccountResult() :
                PlayFabBaseModel()
            {}

            LinkGoogleAccountResult(const LinkGoogleAccountResult& src) :
                PlayFabBaseModel()
            {}

            LinkGoogleAccountResult(const rapidjson::Value& obj) : LinkGoogleAccountResult()
            {
                readFromValue(obj);
            }

            ~LinkGoogleAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct LinkIOSDeviceIDRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LinkIOSDeviceIDRequest,"{1c06893c-ce28-5232-b1f3-410b71755de4}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string DeviceId;
            AZStd::string OS;
            AZStd::string DeviceModel;
            OptionalBool ForceLink;

            LinkIOSDeviceIDRequest() :
                PlayFabBaseModel(),
                DeviceId(),
                OS(),
                DeviceModel(),
                ForceLink()
            {}

            LinkIOSDeviceIDRequest(const LinkIOSDeviceIDRequest& src) :
                PlayFabBaseModel(),
                DeviceId(src.DeviceId),
                OS(src.OS),
                DeviceModel(src.DeviceModel),
                ForceLink(src.ForceLink)
            {}

            LinkIOSDeviceIDRequest(const rapidjson::Value& obj) : LinkIOSDeviceIDRequest()
            {
                readFromValue(obj);
            }

            ~LinkIOSDeviceIDRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("DeviceId");
                writer.String(DeviceId.c_str());
                if (OS.length() > 0) {
                    writer.String("OS");
                    writer.String(OS.c_str());
                }
                if (DeviceModel.length() > 0) {
                    writer.String("DeviceModel");
                    writer.String(DeviceModel.c_str());
                }
                if (ForceLink.notNull()) {
                    writer.String("ForceLink");
                    writer.Bool(ForceLink);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DeviceId_member = obj.FindMember("DeviceId");
                if (DeviceId_member != obj.MemberEnd() && !DeviceId_member->value.IsNull()) DeviceId = DeviceId_member->value.GetString();
                const Value::ConstMemberIterator OS_member = obj.FindMember("OS");
                if (OS_member != obj.MemberEnd() && !OS_member->value.IsNull()) OS = OS_member->value.GetString();
                const Value::ConstMemberIterator DeviceModel_member = obj.FindMember("DeviceModel");
                if (DeviceModel_member != obj.MemberEnd() && !DeviceModel_member->value.IsNull()) DeviceModel = DeviceModel_member->value.GetString();
                const Value::ConstMemberIterator ForceLink_member = obj.FindMember("ForceLink");
                if (ForceLink_member != obj.MemberEnd() && !ForceLink_member->value.IsNull()) ForceLink = ForceLink_member->value.GetBool();

                return true;
            }
        };

        struct LinkIOSDeviceIDResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LinkIOSDeviceIDResult,"{38e27a03-53ed-522b-9973-28ec12bba23a}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            LinkIOSDeviceIDResult() :
                PlayFabBaseModel()
            {}

            LinkIOSDeviceIDResult(const LinkIOSDeviceIDResult& src) :
                PlayFabBaseModel()
            {}

            LinkIOSDeviceIDResult(const rapidjson::Value& obj) : LinkIOSDeviceIDResult()
            {
                readFromValue(obj);
            }

            ~LinkIOSDeviceIDResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct LinkKongregateAccountRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LinkKongregateAccountRequest,"{68c73770-2da7-5867-8565-3c9aebc2f1bc}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string KongregateId;
            AZStd::string AuthTicket;
            OptionalBool ForceLink;

            LinkKongregateAccountRequest() :
                PlayFabBaseModel(),
                KongregateId(),
                AuthTicket(),
                ForceLink()
            {}

            LinkKongregateAccountRequest(const LinkKongregateAccountRequest& src) :
                PlayFabBaseModel(),
                KongregateId(src.KongregateId),
                AuthTicket(src.AuthTicket),
                ForceLink(src.ForceLink)
            {}

            LinkKongregateAccountRequest(const rapidjson::Value& obj) : LinkKongregateAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkKongregateAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("KongregateId");
                writer.String(KongregateId.c_str());
                writer.String("AuthTicket");
                writer.String(AuthTicket.c_str());
                if (ForceLink.notNull()) {
                    writer.String("ForceLink");
                    writer.Bool(ForceLink);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator KongregateId_member = obj.FindMember("KongregateId");
                if (KongregateId_member != obj.MemberEnd() && !KongregateId_member->value.IsNull()) KongregateId = KongregateId_member->value.GetString();
                const Value::ConstMemberIterator AuthTicket_member = obj.FindMember("AuthTicket");
                if (AuthTicket_member != obj.MemberEnd() && !AuthTicket_member->value.IsNull()) AuthTicket = AuthTicket_member->value.GetString();
                const Value::ConstMemberIterator ForceLink_member = obj.FindMember("ForceLink");
                if (ForceLink_member != obj.MemberEnd() && !ForceLink_member->value.IsNull()) ForceLink = ForceLink_member->value.GetBool();

                return true;
            }
        };

        struct LinkKongregateAccountResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LinkKongregateAccountResult,"{f4344bd7-814b-5581-a4c7-a45ce7e49ef3}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            LinkKongregateAccountResult() :
                PlayFabBaseModel()
            {}

            LinkKongregateAccountResult(const LinkKongregateAccountResult& src) :
                PlayFabBaseModel()
            {}

            LinkKongregateAccountResult(const rapidjson::Value& obj) : LinkKongregateAccountResult()
            {
                readFromValue(obj);
            }

            ~LinkKongregateAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct LinkSteamAccountRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LinkSteamAccountRequest,"{9cb59b26-5053-57da-80e6-9eb12d36558e}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string SteamTicket;
            OptionalBool ForceLink;

            LinkSteamAccountRequest() :
                PlayFabBaseModel(),
                SteamTicket(),
                ForceLink()
            {}

            LinkSteamAccountRequest(const LinkSteamAccountRequest& src) :
                PlayFabBaseModel(),
                SteamTicket(src.SteamTicket),
                ForceLink(src.ForceLink)
            {}

            LinkSteamAccountRequest(const rapidjson::Value& obj) : LinkSteamAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkSteamAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("SteamTicket");
                writer.String(SteamTicket.c_str());
                if (ForceLink.notNull()) {
                    writer.String("ForceLink");
                    writer.Bool(ForceLink);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SteamTicket_member = obj.FindMember("SteamTicket");
                if (SteamTicket_member != obj.MemberEnd() && !SteamTicket_member->value.IsNull()) SteamTicket = SteamTicket_member->value.GetString();
                const Value::ConstMemberIterator ForceLink_member = obj.FindMember("ForceLink");
                if (ForceLink_member != obj.MemberEnd() && !ForceLink_member->value.IsNull()) ForceLink = ForceLink_member->value.GetBool();

                return true;
            }
        };

        struct LinkSteamAccountResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LinkSteamAccountResult,"{6348ba31-735c-5189-bcfa-d6df713ecac8}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            LinkSteamAccountResult() :
                PlayFabBaseModel()
            {}

            LinkSteamAccountResult(const LinkSteamAccountResult& src) :
                PlayFabBaseModel()
            {}

            LinkSteamAccountResult(const rapidjson::Value& obj) : LinkSteamAccountResult()
            {
                readFromValue(obj);
            }

            ~LinkSteamAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct LinkTwitchAccountRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LinkTwitchAccountRequest,"{2e0ce48a-7632-5c7e-880d-4a3a48010e7d}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string AccessToken;
            OptionalBool ForceLink;

            LinkTwitchAccountRequest() :
                PlayFabBaseModel(),
                AccessToken(),
                ForceLink()
            {}

            LinkTwitchAccountRequest(const LinkTwitchAccountRequest& src) :
                PlayFabBaseModel(),
                AccessToken(src.AccessToken),
                ForceLink(src.ForceLink)
            {}

            LinkTwitchAccountRequest(const rapidjson::Value& obj) : LinkTwitchAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkTwitchAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("AccessToken");
                writer.String(AccessToken.c_str());
                if (ForceLink.notNull()) {
                    writer.String("ForceLink");
                    writer.Bool(ForceLink);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AccessToken_member = obj.FindMember("AccessToken");
                if (AccessToken_member != obj.MemberEnd() && !AccessToken_member->value.IsNull()) AccessToken = AccessToken_member->value.GetString();
                const Value::ConstMemberIterator ForceLink_member = obj.FindMember("ForceLink");
                if (ForceLink_member != obj.MemberEnd() && !ForceLink_member->value.IsNull()) ForceLink = ForceLink_member->value.GetBool();

                return true;
            }
        };

        struct LinkTwitchAccountResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LinkTwitchAccountResult,"{6a4646fb-7820-574d-976f-1c94e69d8d55}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            LinkTwitchAccountResult() :
                PlayFabBaseModel()
            {}

            LinkTwitchAccountResult(const LinkTwitchAccountResult& src) :
                PlayFabBaseModel()
            {}

            LinkTwitchAccountResult(const rapidjson::Value& obj) : LinkTwitchAccountResult()
            {
                readFromValue(obj);
            }

            ~LinkTwitchAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct LinkWindowsHelloAccountRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LinkWindowsHelloAccountRequest,"{950a86a8-b0a5-5d50-b3ff-f7eabf5216d7}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string UserName;
            AZStd::string PublicKey;
            AZStd::string DeviceName;
            OptionalBool ForceLink;

            LinkWindowsHelloAccountRequest() :
                PlayFabBaseModel(),
                UserName(),
                PublicKey(),
                DeviceName(),
                ForceLink()
            {}

            LinkWindowsHelloAccountRequest(const LinkWindowsHelloAccountRequest& src) :
                PlayFabBaseModel(),
                UserName(src.UserName),
                PublicKey(src.PublicKey),
                DeviceName(src.DeviceName),
                ForceLink(src.ForceLink)
            {}

            LinkWindowsHelloAccountRequest(const rapidjson::Value& obj) : LinkWindowsHelloAccountRequest()
            {
                readFromValue(obj);
            }

            ~LinkWindowsHelloAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("UserName");
                writer.String(UserName.c_str());
                writer.String("PublicKey");
                writer.String(PublicKey.c_str());
                if (DeviceName.length() > 0) {
                    writer.String("DeviceName");
                    writer.String(DeviceName.c_str());
                }
                if (ForceLink.notNull()) {
                    writer.String("ForceLink");
                    writer.Bool(ForceLink);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator UserName_member = obj.FindMember("UserName");
                if (UserName_member != obj.MemberEnd() && !UserName_member->value.IsNull()) UserName = UserName_member->value.GetString();
                const Value::ConstMemberIterator PublicKey_member = obj.FindMember("PublicKey");
                if (PublicKey_member != obj.MemberEnd() && !PublicKey_member->value.IsNull()) PublicKey = PublicKey_member->value.GetString();
                const Value::ConstMemberIterator DeviceName_member = obj.FindMember("DeviceName");
                if (DeviceName_member != obj.MemberEnd() && !DeviceName_member->value.IsNull()) DeviceName = DeviceName_member->value.GetString();
                const Value::ConstMemberIterator ForceLink_member = obj.FindMember("ForceLink");
                if (ForceLink_member != obj.MemberEnd() && !ForceLink_member->value.IsNull()) ForceLink = ForceLink_member->value.GetBool();

                return true;
            }
        };

        struct LinkWindowsHelloAccountResponse : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LinkWindowsHelloAccountResponse,"{eedea973-55d7-5b95-8dc3-e023a3f6fa8c}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            LinkWindowsHelloAccountResponse() :
                PlayFabBaseModel()
            {}

            LinkWindowsHelloAccountResponse(const LinkWindowsHelloAccountResponse& src) :
                PlayFabBaseModel()
            {}

            LinkWindowsHelloAccountResponse(const rapidjson::Value& obj) : LinkWindowsHelloAccountResponse()
            {
                readFromValue(obj);
            }

            ~LinkWindowsHelloAccountResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct ListUsersCharactersRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ListUsersCharactersRequest,"{b907d54c-1892-54f4-a50a-64f1d9eed43f}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string PlayFabId;

            ListUsersCharactersRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            ListUsersCharactersRequest(const ListUsersCharactersRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            ListUsersCharactersRequest(const rapidjson::Value& obj) : ListUsersCharactersRequest()
            {
                readFromValue(obj);
            }

            ~ListUsersCharactersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct ListUsersCharactersResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ListUsersCharactersResult,"{552eea42-8586-5ee0-8f6c-fc35d3abda2f}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<CharacterResult> Characters; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            ListUsersCharactersResult() :
                PlayFabBaseModel(),
                Characters()
            {}

            ListUsersCharactersResult(const ListUsersCharactersResult& src) :
                PlayFabBaseModel(),
                Characters(src.Characters)
            {}

            ListUsersCharactersResult(const rapidjson::Value& obj) : ListUsersCharactersResult()
            {
                readFromValue(obj);
            }

            ~ListUsersCharactersResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Characters.empty()) {
                    writer.String("Characters");
                    writer.StartArray();
                    for (auto iter = Characters.begin(); iter != Characters.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Characters_member = obj.FindMember("Characters");
                if (Characters_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Characters_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Characters.push_back(CharacterResult(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct UserSettings : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UserSettings,"{58f6bc8b-5aa4-50e5-854d-01caffc4938a}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            bool NeedsAttribution;

            UserSettings() :
                PlayFabBaseModel(),
                NeedsAttribution(false)
            {}

            UserSettings(const UserSettings& src) :
                PlayFabBaseModel(),
                NeedsAttribution(src.NeedsAttribution)
            {}

            UserSettings(const rapidjson::Value& obj) : UserSettings()
            {
                readFromValue(obj);
            }

            ~UserSettings()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("NeedsAttribution");
                writer.Bool(NeedsAttribution);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator NeedsAttribution_member = obj.FindMember("NeedsAttribution");
                if (NeedsAttribution_member != obj.MemberEnd() && !NeedsAttribution_member->value.IsNull()) NeedsAttribution = NeedsAttribution_member->value.GetBool();

                return true;
            }
        };

        struct LoginResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LoginResult,"{dfe454cd-71f2-5032-b1ac-4b735a8fce90}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string SessionTicket;
            AZStd::string PlayFabId;
            bool NewlyCreated;
            UserSettings* SettingsForUser;
            OptionalTime LastLoginTime;
            GetPlayerCombinedInfoResultPayload* InfoResultPayload;

            LoginResult() :
                PlayFabBaseModel(),
                SessionTicket(),
                PlayFabId(),
                NewlyCreated(false),
                SettingsForUser(nullptr),
                LastLoginTime(),
                InfoResultPayload(nullptr)
            {}

            LoginResult(const LoginResult& src) :
                PlayFabBaseModel(),
                SessionTicket(src.SessionTicket),
                PlayFabId(src.PlayFabId),
                NewlyCreated(src.NewlyCreated),
                SettingsForUser(src.SettingsForUser ? new UserSettings(*src.SettingsForUser) : nullptr),
                LastLoginTime(src.LastLoginTime),
                InfoResultPayload(src.InfoResultPayload ? new GetPlayerCombinedInfoResultPayload(*src.InfoResultPayload) : nullptr)
            {}

            LoginResult(const rapidjson::Value& obj) : LoginResult()
            {
                readFromValue(obj);
            }

            ~LoginResult()
            {
                if (SettingsForUser != nullptr) delete SettingsForUser;
                if (InfoResultPayload != nullptr) delete InfoResultPayload;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (SessionTicket.length() > 0) {
                    writer.String("SessionTicket");
                    writer.String(SessionTicket.c_str());
                }
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.String("NewlyCreated");
                writer.Bool(NewlyCreated);
                if (SettingsForUser != nullptr) {
                    writer.String("SettingsForUser");
                    SettingsForUser->writeJSON(writer);
                }
                if (LastLoginTime.notNull()) {
                    writer.String("LastLoginTime");
                    writeDatetime(LastLoginTime, writer);
                }
                if (InfoResultPayload != nullptr) {
                    writer.String("InfoResultPayload");
                    InfoResultPayload->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SessionTicket_member = obj.FindMember("SessionTicket");
                if (SessionTicket_member != obj.MemberEnd() && !SessionTicket_member->value.IsNull()) SessionTicket = SessionTicket_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator NewlyCreated_member = obj.FindMember("NewlyCreated");
                if (NewlyCreated_member != obj.MemberEnd() && !NewlyCreated_member->value.IsNull()) NewlyCreated = NewlyCreated_member->value.GetBool();
                const Value::ConstMemberIterator SettingsForUser_member = obj.FindMember("SettingsForUser");
                if (SettingsForUser_member != obj.MemberEnd() && !SettingsForUser_member->value.IsNull()) SettingsForUser = new UserSettings(SettingsForUser_member->value);
                const Value::ConstMemberIterator LastLoginTime_member = obj.FindMember("LastLoginTime");
                if (LastLoginTime_member != obj.MemberEnd() && !LastLoginTime_member->value.IsNull()) LastLoginTime = readDatetime(LastLoginTime_member->value);
                const Value::ConstMemberIterator InfoResultPayload_member = obj.FindMember("InfoResultPayload");
                if (InfoResultPayload_member != obj.MemberEnd() && !InfoResultPayload_member->value.IsNull()) InfoResultPayload = new GetPlayerCombinedInfoResultPayload(InfoResultPayload_member->value);

                return true;
            }
        };

        struct LoginWithAndroidDeviceIDRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LoginWithAndroidDeviceIDRequest,"{096ef37d-484e-5dba-bb0f-49a16db3b683}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string AndroidDeviceId;
            AZStd::string OS;
            AZStd::string AndroidDevice;
            OptionalBool CreateAccount;
            AZStd::string TitleId;
            AZStd::string EncryptedRequest;
            AZStd::string PlayerSecret;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;

            LoginWithAndroidDeviceIDRequest() :
                PlayFabBaseModel(),
                AndroidDeviceId(),
                OS(),
                AndroidDevice(),
                CreateAccount(),
                TitleId(),
                EncryptedRequest(),
                PlayerSecret(),
                InfoRequestParameters(nullptr)
            {}

            LoginWithAndroidDeviceIDRequest(const LoginWithAndroidDeviceIDRequest& src) :
                PlayFabBaseModel(),
                AndroidDeviceId(src.AndroidDeviceId),
                OS(src.OS),
                AndroidDevice(src.AndroidDevice),
                CreateAccount(src.CreateAccount),
                TitleId(src.TitleId),
                EncryptedRequest(src.EncryptedRequest),
                PlayerSecret(src.PlayerSecret),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr)
            {}

            LoginWithAndroidDeviceIDRequest(const rapidjson::Value& obj) : LoginWithAndroidDeviceIDRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithAndroidDeviceIDRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (AndroidDeviceId.length() > 0) {
                    writer.String("AndroidDeviceId");
                    writer.String(AndroidDeviceId.c_str());
                }
                if (OS.length() > 0) {
                    writer.String("OS");
                    writer.String(OS.c_str());
                }
                if (AndroidDevice.length() > 0) {
                    writer.String("AndroidDevice");
                    writer.String(AndroidDevice.c_str());
                }
                if (CreateAccount.notNull()) {
                    writer.String("CreateAccount");
                    writer.Bool(CreateAccount);
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AndroidDeviceId_member = obj.FindMember("AndroidDeviceId");
                if (AndroidDeviceId_member != obj.MemberEnd() && !AndroidDeviceId_member->value.IsNull()) AndroidDeviceId = AndroidDeviceId_member->value.GetString();
                const Value::ConstMemberIterator OS_member = obj.FindMember("OS");
                if (OS_member != obj.MemberEnd() && !OS_member->value.IsNull()) OS = OS_member->value.GetString();
                const Value::ConstMemberIterator AndroidDevice_member = obj.FindMember("AndroidDevice");
                if (AndroidDevice_member != obj.MemberEnd() && !AndroidDevice_member->value.IsNull()) AndroidDevice = AndroidDevice_member->value.GetString();
                const Value::ConstMemberIterator CreateAccount_member = obj.FindMember("CreateAccount");
                if (CreateAccount_member != obj.MemberEnd() && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);

                return true;
            }
        };

        struct LoginWithCustomIDRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LoginWithCustomIDRequest,"{0d358a76-0184-567c-94db-2f5c28e5994a}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string CustomId;
            OptionalBool CreateAccount;
            AZStd::string TitleId;
            AZStd::string EncryptedRequest;
            AZStd::string PlayerSecret;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;

            LoginWithCustomIDRequest() :
                PlayFabBaseModel(),
                CustomId(),
                CreateAccount(),
                TitleId(),
                EncryptedRequest(),
                PlayerSecret(),
                InfoRequestParameters(nullptr)
            {}

            LoginWithCustomIDRequest(const LoginWithCustomIDRequest& src) :
                PlayFabBaseModel(),
                CustomId(src.CustomId),
                CreateAccount(src.CreateAccount),
                TitleId(src.TitleId),
                EncryptedRequest(src.EncryptedRequest),
                PlayerSecret(src.PlayerSecret),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr)
            {}

            LoginWithCustomIDRequest(const rapidjson::Value& obj) : LoginWithCustomIDRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithCustomIDRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CustomId.length() > 0) {
                    writer.String("CustomId");
                    writer.String(CustomId.c_str());
                }
                if (CreateAccount.notNull()) {
                    writer.String("CreateAccount");
                    writer.Bool(CreateAccount);
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CustomId_member = obj.FindMember("CustomId");
                if (CustomId_member != obj.MemberEnd() && !CustomId_member->value.IsNull()) CustomId = CustomId_member->value.GetString();
                const Value::ConstMemberIterator CreateAccount_member = obj.FindMember("CreateAccount");
                if (CreateAccount_member != obj.MemberEnd() && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);

                return true;
            }
        };

        struct LoginWithEmailAddressRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LoginWithEmailAddressRequest,"{0a5c32da-42d9-5790-a0d8-19e19d06ef4a}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string TitleId;
            AZStd::string Email;
            AZStd::string Password;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;

            LoginWithEmailAddressRequest() :
                PlayFabBaseModel(),
                TitleId(),
                Email(),
                Password(),
                InfoRequestParameters(nullptr)
            {}

            LoginWithEmailAddressRequest(const LoginWithEmailAddressRequest& src) :
                PlayFabBaseModel(),
                TitleId(src.TitleId),
                Email(src.Email),
                Password(src.Password),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr)
            {}

            LoginWithEmailAddressRequest(const rapidjson::Value& obj) : LoginWithEmailAddressRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithEmailAddressRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                writer.String("Email");
                writer.String(Email.c_str());
                writer.String("Password");
                writer.String(Password.c_str());
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
                if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
                const Value::ConstMemberIterator Password_member = obj.FindMember("Password");
                if (Password_member != obj.MemberEnd() && !Password_member->value.IsNull()) Password = Password_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);

                return true;
            }
        };

        struct LoginWithFacebookRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LoginWithFacebookRequest,"{cf85b912-7e08-561f-828f-b787d7fa48ea}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string AccessToken;
            OptionalBool CreateAccount;
            AZStd::string TitleId;
            AZStd::string EncryptedRequest;
            AZStd::string PlayerSecret;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;

            LoginWithFacebookRequest() :
                PlayFabBaseModel(),
                AccessToken(),
                CreateAccount(),
                TitleId(),
                EncryptedRequest(),
                PlayerSecret(),
                InfoRequestParameters(nullptr)
            {}

            LoginWithFacebookRequest(const LoginWithFacebookRequest& src) :
                PlayFabBaseModel(),
                AccessToken(src.AccessToken),
                CreateAccount(src.CreateAccount),
                TitleId(src.TitleId),
                EncryptedRequest(src.EncryptedRequest),
                PlayerSecret(src.PlayerSecret),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr)
            {}

            LoginWithFacebookRequest(const rapidjson::Value& obj) : LoginWithFacebookRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithFacebookRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("AccessToken");
                writer.String(AccessToken.c_str());
                if (CreateAccount.notNull()) {
                    writer.String("CreateAccount");
                    writer.Bool(CreateAccount);
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AccessToken_member = obj.FindMember("AccessToken");
                if (AccessToken_member != obj.MemberEnd() && !AccessToken_member->value.IsNull()) AccessToken = AccessToken_member->value.GetString();
                const Value::ConstMemberIterator CreateAccount_member = obj.FindMember("CreateAccount");
                if (CreateAccount_member != obj.MemberEnd() && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);

                return true;
            }
        };

        struct LoginWithGameCenterRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LoginWithGameCenterRequest,"{4ad0c047-3604-5e95-a092-e2362cbb7949}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string PlayerId;
            OptionalBool CreateAccount;
            AZStd::string TitleId;
            AZStd::string EncryptedRequest;
            AZStd::string PlayerSecret;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;

            LoginWithGameCenterRequest() :
                PlayFabBaseModel(),
                PlayerId(),
                CreateAccount(),
                TitleId(),
                EncryptedRequest(),
                PlayerSecret(),
                InfoRequestParameters(nullptr)
            {}

            LoginWithGameCenterRequest(const LoginWithGameCenterRequest& src) :
                PlayFabBaseModel(),
                PlayerId(src.PlayerId),
                CreateAccount(src.CreateAccount),
                TitleId(src.TitleId),
                EncryptedRequest(src.EncryptedRequest),
                PlayerSecret(src.PlayerSecret),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr)
            {}

            LoginWithGameCenterRequest(const rapidjson::Value& obj) : LoginWithGameCenterRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithGameCenterRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayerId.length() > 0) {
                    writer.String("PlayerId");
                    writer.String(PlayerId.c_str());
                }
                if (CreateAccount.notNull()) {
                    writer.String("CreateAccount");
                    writer.Bool(CreateAccount);
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayerId_member = obj.FindMember("PlayerId");
                if (PlayerId_member != obj.MemberEnd() && !PlayerId_member->value.IsNull()) PlayerId = PlayerId_member->value.GetString();
                const Value::ConstMemberIterator CreateAccount_member = obj.FindMember("CreateAccount");
                if (CreateAccount_member != obj.MemberEnd() && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);

                return true;
            }
        };

        struct LoginWithGoogleAccountRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LoginWithGoogleAccountRequest,"{8dd922b6-d330-5ae0-bfc0-38c34dd8c6d9}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string ServerAuthCode;
            OptionalBool CreateAccount;
            AZStd::string TitleId;
            AZStd::string EncryptedRequest;
            AZStd::string PlayerSecret;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;

            LoginWithGoogleAccountRequest() :
                PlayFabBaseModel(),
                ServerAuthCode(),
                CreateAccount(),
                TitleId(),
                EncryptedRequest(),
                PlayerSecret(),
                InfoRequestParameters(nullptr)
            {}

            LoginWithGoogleAccountRequest(const LoginWithGoogleAccountRequest& src) :
                PlayFabBaseModel(),
                ServerAuthCode(src.ServerAuthCode),
                CreateAccount(src.CreateAccount),
                TitleId(src.TitleId),
                EncryptedRequest(src.EncryptedRequest),
                PlayerSecret(src.PlayerSecret),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr)
            {}

            LoginWithGoogleAccountRequest(const rapidjson::Value& obj) : LoginWithGoogleAccountRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithGoogleAccountRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (ServerAuthCode.length() > 0) {
                    writer.String("ServerAuthCode");
                    writer.String(ServerAuthCode.c_str());
                }
                if (CreateAccount.notNull()) {
                    writer.String("CreateAccount");
                    writer.Bool(CreateAccount);
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ServerAuthCode_member = obj.FindMember("ServerAuthCode");
                if (ServerAuthCode_member != obj.MemberEnd() && !ServerAuthCode_member->value.IsNull()) ServerAuthCode = ServerAuthCode_member->value.GetString();
                const Value::ConstMemberIterator CreateAccount_member = obj.FindMember("CreateAccount");
                if (CreateAccount_member != obj.MemberEnd() && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);

                return true;
            }
        };

        struct LoginWithIOSDeviceIDRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LoginWithIOSDeviceIDRequest,"{5eb25413-eaa1-59d6-adb6-8f0c027fd8be}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string DeviceId;
            AZStd::string OS;
            AZStd::string DeviceModel;
            OptionalBool CreateAccount;
            AZStd::string TitleId;
            AZStd::string EncryptedRequest;
            AZStd::string PlayerSecret;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;

            LoginWithIOSDeviceIDRequest() :
                PlayFabBaseModel(),
                DeviceId(),
                OS(),
                DeviceModel(),
                CreateAccount(),
                TitleId(),
                EncryptedRequest(),
                PlayerSecret(),
                InfoRequestParameters(nullptr)
            {}

            LoginWithIOSDeviceIDRequest(const LoginWithIOSDeviceIDRequest& src) :
                PlayFabBaseModel(),
                DeviceId(src.DeviceId),
                OS(src.OS),
                DeviceModel(src.DeviceModel),
                CreateAccount(src.CreateAccount),
                TitleId(src.TitleId),
                EncryptedRequest(src.EncryptedRequest),
                PlayerSecret(src.PlayerSecret),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr)
            {}

            LoginWithIOSDeviceIDRequest(const rapidjson::Value& obj) : LoginWithIOSDeviceIDRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithIOSDeviceIDRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (DeviceId.length() > 0) {
                    writer.String("DeviceId");
                    writer.String(DeviceId.c_str());
                }
                if (OS.length() > 0) {
                    writer.String("OS");
                    writer.String(OS.c_str());
                }
                if (DeviceModel.length() > 0) {
                    writer.String("DeviceModel");
                    writer.String(DeviceModel.c_str());
                }
                if (CreateAccount.notNull()) {
                    writer.String("CreateAccount");
                    writer.Bool(CreateAccount);
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DeviceId_member = obj.FindMember("DeviceId");
                if (DeviceId_member != obj.MemberEnd() && !DeviceId_member->value.IsNull()) DeviceId = DeviceId_member->value.GetString();
                const Value::ConstMemberIterator OS_member = obj.FindMember("OS");
                if (OS_member != obj.MemberEnd() && !OS_member->value.IsNull()) OS = OS_member->value.GetString();
                const Value::ConstMemberIterator DeviceModel_member = obj.FindMember("DeviceModel");
                if (DeviceModel_member != obj.MemberEnd() && !DeviceModel_member->value.IsNull()) DeviceModel = DeviceModel_member->value.GetString();
                const Value::ConstMemberIterator CreateAccount_member = obj.FindMember("CreateAccount");
                if (CreateAccount_member != obj.MemberEnd() && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);

                return true;
            }
        };

        struct LoginWithKongregateRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LoginWithKongregateRequest,"{53773d45-6582-5ed8-87e0-79af1b76f4f1}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string KongregateId;
            AZStd::string AuthTicket;
            OptionalBool CreateAccount;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;
            AZStd::string TitleId;
            AZStd::string EncryptedRequest;
            AZStd::string PlayerSecret;

            LoginWithKongregateRequest() :
                PlayFabBaseModel(),
                KongregateId(),
                AuthTicket(),
                CreateAccount(),
                InfoRequestParameters(nullptr),
                TitleId(),
                EncryptedRequest(),
                PlayerSecret()
            {}

            LoginWithKongregateRequest(const LoginWithKongregateRequest& src) :
                PlayFabBaseModel(),
                KongregateId(src.KongregateId),
                AuthTicket(src.AuthTicket),
                CreateAccount(src.CreateAccount),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr),
                TitleId(src.TitleId),
                EncryptedRequest(src.EncryptedRequest),
                PlayerSecret(src.PlayerSecret)
            {}

            LoginWithKongregateRequest(const rapidjson::Value& obj) : LoginWithKongregateRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithKongregateRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (KongregateId.length() > 0) {
                    writer.String("KongregateId");
                    writer.String(KongregateId.c_str());
                }
                if (AuthTicket.length() > 0) {
                    writer.String("AuthTicket");
                    writer.String(AuthTicket.c_str());
                }
                if (CreateAccount.notNull()) {
                    writer.String("CreateAccount");
                    writer.Bool(CreateAccount);
                }
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator KongregateId_member = obj.FindMember("KongregateId");
                if (KongregateId_member != obj.MemberEnd() && !KongregateId_member->value.IsNull()) KongregateId = KongregateId_member->value.GetString();
                const Value::ConstMemberIterator AuthTicket_member = obj.FindMember("AuthTicket");
                if (AuthTicket_member != obj.MemberEnd() && !AuthTicket_member->value.IsNull()) AuthTicket = AuthTicket_member->value.GetString();
                const Value::ConstMemberIterator CreateAccount_member = obj.FindMember("CreateAccount");
                if (CreateAccount_member != obj.MemberEnd() && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();

                return true;
            }
        };

        struct LoginWithPlayFabRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LoginWithPlayFabRequest,"{b149c08a-1cdd-5247-8c48-f33e77143803}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string TitleId;
            AZStd::string Username;
            AZStd::string Password;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;

            LoginWithPlayFabRequest() :
                PlayFabBaseModel(),
                TitleId(),
                Username(),
                Password(),
                InfoRequestParameters(nullptr)
            {}

            LoginWithPlayFabRequest(const LoginWithPlayFabRequest& src) :
                PlayFabBaseModel(),
                TitleId(src.TitleId),
                Username(src.Username),
                Password(src.Password),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr)
            {}

            LoginWithPlayFabRequest(const rapidjson::Value& obj) : LoginWithPlayFabRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithPlayFabRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                writer.String("Username");
                writer.String(Username.c_str());
                writer.String("Password");
                writer.String(Password.c_str());
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
                const Value::ConstMemberIterator Password_member = obj.FindMember("Password");
                if (Password_member != obj.MemberEnd() && !Password_member->value.IsNull()) Password = Password_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);

                return true;
            }
        };

        struct LoginWithSteamRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LoginWithSteamRequest,"{879dbe88-86a8-5867-a7cc-3baca43659a9}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string SteamTicket;
            OptionalBool CreateAccount;
            AZStd::string TitleId;
            AZStd::string EncryptedRequest;
            AZStd::string PlayerSecret;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;

            LoginWithSteamRequest() :
                PlayFabBaseModel(),
                SteamTicket(),
                CreateAccount(),
                TitleId(),
                EncryptedRequest(),
                PlayerSecret(),
                InfoRequestParameters(nullptr)
            {}

            LoginWithSteamRequest(const LoginWithSteamRequest& src) :
                PlayFabBaseModel(),
                SteamTicket(src.SteamTicket),
                CreateAccount(src.CreateAccount),
                TitleId(src.TitleId),
                EncryptedRequest(src.EncryptedRequest),
                PlayerSecret(src.PlayerSecret),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr)
            {}

            LoginWithSteamRequest(const rapidjson::Value& obj) : LoginWithSteamRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithSteamRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (SteamTicket.length() > 0) {
                    writer.String("SteamTicket");
                    writer.String(SteamTicket.c_str());
                }
                if (CreateAccount.notNull()) {
                    writer.String("CreateAccount");
                    writer.Bool(CreateAccount);
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SteamTicket_member = obj.FindMember("SteamTicket");
                if (SteamTicket_member != obj.MemberEnd() && !SteamTicket_member->value.IsNull()) SteamTicket = SteamTicket_member->value.GetString();
                const Value::ConstMemberIterator CreateAccount_member = obj.FindMember("CreateAccount");
                if (CreateAccount_member != obj.MemberEnd() && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);

                return true;
            }
        };

        struct LoginWithTwitchRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LoginWithTwitchRequest,"{373cbf64-6a2e-58d8-a01c-f3129a20eefc}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string AccessToken;
            OptionalBool CreateAccount;
            AZStd::string TitleId;
            AZStd::string EncryptedRequest;
            AZStd::string PlayerSecret;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;

            LoginWithTwitchRequest() :
                PlayFabBaseModel(),
                AccessToken(),
                CreateAccount(),
                TitleId(),
                EncryptedRequest(),
                PlayerSecret(),
                InfoRequestParameters(nullptr)
            {}

            LoginWithTwitchRequest(const LoginWithTwitchRequest& src) :
                PlayFabBaseModel(),
                AccessToken(src.AccessToken),
                CreateAccount(src.CreateAccount),
                TitleId(src.TitleId),
                EncryptedRequest(src.EncryptedRequest),
                PlayerSecret(src.PlayerSecret),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr)
            {}

            LoginWithTwitchRequest(const rapidjson::Value& obj) : LoginWithTwitchRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithTwitchRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (AccessToken.length() > 0) {
                    writer.String("AccessToken");
                    writer.String(AccessToken.c_str());
                }
                if (CreateAccount.notNull()) {
                    writer.String("CreateAccount");
                    writer.Bool(CreateAccount);
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AccessToken_member = obj.FindMember("AccessToken");
                if (AccessToken_member != obj.MemberEnd() && !AccessToken_member->value.IsNull()) AccessToken = AccessToken_member->value.GetString();
                const Value::ConstMemberIterator CreateAccount_member = obj.FindMember("CreateAccount");
                if (CreateAccount_member != obj.MemberEnd() && !CreateAccount_member->value.IsNull()) CreateAccount = CreateAccount_member->value.GetBool();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);

                return true;
            }
        };

        struct LoginWithWindowsHelloRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::LoginWithWindowsHelloRequest,"{bf68ea47-4534-5d42-8f8c-e65d5aa6b3a2}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string TitleId;
            AZStd::string ChallengeSignature;
            AZStd::string PublicKeyHint;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;

            LoginWithWindowsHelloRequest() :
                PlayFabBaseModel(),
                TitleId(),
                ChallengeSignature(),
                PublicKeyHint(),
                InfoRequestParameters(nullptr)
            {}

            LoginWithWindowsHelloRequest(const LoginWithWindowsHelloRequest& src) :
                PlayFabBaseModel(),
                TitleId(src.TitleId),
                ChallengeSignature(src.ChallengeSignature),
                PublicKeyHint(src.PublicKeyHint),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr)
            {}

            LoginWithWindowsHelloRequest(const rapidjson::Value& obj) : LoginWithWindowsHelloRequest()
            {
                readFromValue(obj);
            }

            ~LoginWithWindowsHelloRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                writer.String("ChallengeSignature");
                writer.String(ChallengeSignature.c_str());
                writer.String("PublicKeyHint");
                writer.String(PublicKeyHint.c_str());
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator ChallengeSignature_member = obj.FindMember("ChallengeSignature");
                if (ChallengeSignature_member != obj.MemberEnd() && !ChallengeSignature_member->value.IsNull()) ChallengeSignature = ChallengeSignature_member->value.GetString();
                const Value::ConstMemberIterator PublicKeyHint_member = obj.FindMember("PublicKeyHint");
                if (PublicKeyHint_member != obj.MemberEnd() && !PublicKeyHint_member->value.IsNull()) PublicKeyHint = PublicKeyHint_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);

                return true;
            }
        };

        struct MatchmakeRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::MatchmakeRequest,"{401053c2-1fa2-5be3-8607-76bc50583738}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string BuildVersion;
            Boxed<Region> pfRegion;
            AZStd::string GameMode;
            AZStd::string LobbyId;
            AZStd::string StatisticName;
            AZStd::string CharacterId;
            OptionalBool StartNewIfNoneFound;
            CollectionFilter* TagFilter;

            MatchmakeRequest() :
                PlayFabBaseModel(),
                BuildVersion(),
                pfRegion(),
                GameMode(),
                LobbyId(),
                StatisticName(),
                CharacterId(),
                StartNewIfNoneFound(),
                TagFilter(nullptr)
            {}

            MatchmakeRequest(const MatchmakeRequest& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion),
                pfRegion(src.pfRegion),
                GameMode(src.GameMode),
                LobbyId(src.LobbyId),
                StatisticName(src.StatisticName),
                CharacterId(src.CharacterId),
                StartNewIfNoneFound(src.StartNewIfNoneFound),
                TagFilter(src.TagFilter ? new CollectionFilter(*src.TagFilter) : nullptr)
            {}

            MatchmakeRequest(const rapidjson::Value& obj) : MatchmakeRequest()
            {
                readFromValue(obj);
            }

            ~MatchmakeRequest()
            {
                if (TagFilter != nullptr) delete TagFilter;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (BuildVersion.length() > 0) {
                    writer.String("BuildVersion");
                    writer.String(BuildVersion.c_str());
                }
                if (pfRegion.notNull()) {
                    writer.String("Region");
                    writeRegionEnumJSON(pfRegion, writer);
                }
                if (GameMode.length() > 0) {
                    writer.String("GameMode");
                    writer.String(GameMode.c_str());
                }
                if (LobbyId.length() > 0) {
                    writer.String("LobbyId");
                    writer.String(LobbyId.c_str());
                }
                if (StatisticName.length() > 0) {
                    writer.String("StatisticName");
                    writer.String(StatisticName.c_str());
                }
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                if (StartNewIfNoneFound.notNull()) {
                    writer.String("StartNewIfNoneFound");
                    writer.Bool(StartNewIfNoneFound);
                }
                if (TagFilter != nullptr) {
                    writer.String("TagFilter");
                    TagFilter->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildVersion_member = obj.FindMember("BuildVersion");
                if (BuildVersion_member != obj.MemberEnd() && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
                const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
                if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);
                const Value::ConstMemberIterator GameMode_member = obj.FindMember("GameMode");
                if (GameMode_member != obj.MemberEnd() && !GameMode_member->value.IsNull()) GameMode = GameMode_member->value.GetString();
                const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
                if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator StartNewIfNoneFound_member = obj.FindMember("StartNewIfNoneFound");
                if (StartNewIfNoneFound_member != obj.MemberEnd() && !StartNewIfNoneFound_member->value.IsNull()) StartNewIfNoneFound = StartNewIfNoneFound_member->value.GetBool();
                const Value::ConstMemberIterator TagFilter_member = obj.FindMember("TagFilter");
                if (TagFilter_member != obj.MemberEnd() && !TagFilter_member->value.IsNull()) TagFilter = new CollectionFilter(TagFilter_member->value);

                return true;
            }
        };

        enum MatchmakeStatus
        {
            MatchmakeStatusComplete,
            MatchmakeStatusWaiting,
            MatchmakeStatusGameNotFound,
            MatchmakeStatusNoAvailableSlots,
            MatchmakeStatusSessionClosed
        };

        inline void writeMatchmakeStatusEnumJSON(MatchmakeStatus enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case MatchmakeStatusComplete: writer.String("Complete"); break;
            case MatchmakeStatusWaiting: writer.String("Waiting"); break;
            case MatchmakeStatusGameNotFound: writer.String("GameNotFound"); break;
            case MatchmakeStatusNoAvailableSlots: writer.String("NoAvailableSlots"); break;
            case MatchmakeStatusSessionClosed: writer.String("SessionClosed"); break;

            }
        }

        inline MatchmakeStatus readMatchmakeStatusFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<MatchmakeStatus>(obj.GetInt());

            static std::map<const char *, MatchmakeStatus, PlayFabComboSdk::StringCompare> _MatchmakeStatusMap;
            if (_MatchmakeStatusMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _MatchmakeStatusMap["Complete"] = MatchmakeStatusComplete;
                _MatchmakeStatusMap["Waiting"] = MatchmakeStatusWaiting;
                _MatchmakeStatusMap["GameNotFound"] = MatchmakeStatusGameNotFound;
                _MatchmakeStatusMap["NoAvailableSlots"] = MatchmakeStatusNoAvailableSlots;
                _MatchmakeStatusMap["SessionClosed"] = MatchmakeStatusSessionClosed;

            }

            auto output = _MatchmakeStatusMap.find(obj.GetString());
            if (output != _MatchmakeStatusMap.end())
                return output->second;

            return MatchmakeStatusComplete; // Basically critical fail
        }

        struct MatchmakeResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::MatchmakeResult,"{f74060c7-73bf-562a-8d03-b59893d3ab50}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string LobbyID;
            AZStd::string ServerHostname;
            OptionalInt32 ServerPort;
            AZStd::string Ticket;
            AZStd::string Expires;
            OptionalInt32 PollWaitTimeMS;
            Boxed<MatchmakeStatus> Status;

            MatchmakeResult() :
                PlayFabBaseModel(),
                LobbyID(),
                ServerHostname(),
                ServerPort(),
                Ticket(),
                Expires(),
                PollWaitTimeMS(),
                Status()
            {}

            MatchmakeResult(const MatchmakeResult& src) :
                PlayFabBaseModel(),
                LobbyID(src.LobbyID),
                ServerHostname(src.ServerHostname),
                ServerPort(src.ServerPort),
                Ticket(src.Ticket),
                Expires(src.Expires),
                PollWaitTimeMS(src.PollWaitTimeMS),
                Status(src.Status)
            {}

            MatchmakeResult(const rapidjson::Value& obj) : MatchmakeResult()
            {
                readFromValue(obj);
            }

            ~MatchmakeResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (LobbyID.length() > 0) {
                    writer.String("LobbyID");
                    writer.String(LobbyID.c_str());
                }
                if (ServerHostname.length() > 0) {
                    writer.String("ServerHostname");
                    writer.String(ServerHostname.c_str());
                }
                if (ServerPort.notNull()) {
                    writer.String("ServerPort");
                    writer.Int(ServerPort);
                }
                if (Ticket.length() > 0) {
                    writer.String("Ticket");
                    writer.String(Ticket.c_str());
                }
                if (Expires.length() > 0) {
                    writer.String("Expires");
                    writer.String(Expires.c_str());
                }
                if (PollWaitTimeMS.notNull()) {
                    writer.String("PollWaitTimeMS");
                    writer.Int(PollWaitTimeMS);
                }
                if (Status.notNull()) {
                    writer.String("Status");
                    writeMatchmakeStatusEnumJSON(Status, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator LobbyID_member = obj.FindMember("LobbyID");
                if (LobbyID_member != obj.MemberEnd() && !LobbyID_member->value.IsNull()) LobbyID = LobbyID_member->value.GetString();
                const Value::ConstMemberIterator ServerHostname_member = obj.FindMember("ServerHostname");
                if (ServerHostname_member != obj.MemberEnd() && !ServerHostname_member->value.IsNull()) ServerHostname = ServerHostname_member->value.GetString();
                const Value::ConstMemberIterator ServerPort_member = obj.FindMember("ServerPort");
                if (ServerPort_member != obj.MemberEnd() && !ServerPort_member->value.IsNull()) ServerPort = ServerPort_member->value.GetInt();
                const Value::ConstMemberIterator Ticket_member = obj.FindMember("Ticket");
                if (Ticket_member != obj.MemberEnd() && !Ticket_member->value.IsNull()) Ticket = Ticket_member->value.GetString();
                const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
                if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = Expires_member->value.GetString();
                const Value::ConstMemberIterator PollWaitTimeMS_member = obj.FindMember("PollWaitTimeMS");
                if (PollWaitTimeMS_member != obj.MemberEnd() && !PollWaitTimeMS_member->value.IsNull()) PollWaitTimeMS = PollWaitTimeMS_member->value.GetInt();
                const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
                if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readMatchmakeStatusFromValue(Status_member->value);

                return true;
            }
        };

        struct ModifyUserVirtualCurrencyResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ModifyUserVirtualCurrencyResult,"{43fef3b5-029a-5c11-90b6-458bf819677c}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string PlayFabId;
            AZStd::string VirtualCurrency;
            Int32 BalanceChange;
            Int32 Balance;

            ModifyUserVirtualCurrencyResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                VirtualCurrency(),
                BalanceChange(0),
                Balance(0)
            {}

            ModifyUserVirtualCurrencyResult(const ModifyUserVirtualCurrencyResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                VirtualCurrency(src.VirtualCurrency),
                BalanceChange(src.BalanceChange),
                Balance(src.Balance)
            {}

            ModifyUserVirtualCurrencyResult(const rapidjson::Value& obj) : ModifyUserVirtualCurrencyResult()
            {
                readFromValue(obj);
            }

            ~ModifyUserVirtualCurrencyResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                if (VirtualCurrency.length() > 0) {
                    writer.String("VirtualCurrency");
                    writer.String(VirtualCurrency.c_str());
                }
                writer.String("BalanceChange");
                writer.Int(BalanceChange);
                writer.String("Balance");
                writer.Int(Balance);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
                const Value::ConstMemberIterator BalanceChange_member = obj.FindMember("BalanceChange");
                if (BalanceChange_member != obj.MemberEnd() && !BalanceChange_member->value.IsNull()) BalanceChange = BalanceChange_member->value.GetInt();
                const Value::ConstMemberIterator Balance_member = obj.FindMember("Balance");
                if (Balance_member != obj.MemberEnd() && !Balance_member->value.IsNull()) Balance = Balance_member->value.GetInt();

                return true;
            }
        };

        struct NameIdentifier : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::NameIdentifier,"{62c90435-0207-59bd-bc22-93037d0d79f4}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string Name;
            AZStd::string Id;

            NameIdentifier() :
                PlayFabBaseModel(),
                Name(),
                Id()
            {}

            NameIdentifier(const NameIdentifier& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Id(src.Id)
            {}

            NameIdentifier(const rapidjson::Value& obj) : NameIdentifier()
            {
                readFromValue(obj);
            }

            ~NameIdentifier()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Name.length() > 0) {
                    writer.String("Name");
                    writer.String(Name.c_str());
                }
                if (Id.length() > 0) {
                    writer.String("Id");
                    writer.String(Id.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
                const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
                if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();

                return true;
            }
        };

        struct OpenTradeRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::OpenTradeRequest,"{1b86ba05-6c7a-52db-9b1f-0582269c1b1b}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<AZStd::string> OfferedInventoryInstanceIds; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<AZStd::string> RequestedCatalogItemIds; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<AZStd::string> AllowedPlayerIds; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            OpenTradeRequest() :
                PlayFabBaseModel(),
                OfferedInventoryInstanceIds(),
                RequestedCatalogItemIds(),
                AllowedPlayerIds()
            {}

            OpenTradeRequest(const OpenTradeRequest& src) :
                PlayFabBaseModel(),
                OfferedInventoryInstanceIds(src.OfferedInventoryInstanceIds),
                RequestedCatalogItemIds(src.RequestedCatalogItemIds),
                AllowedPlayerIds(src.AllowedPlayerIds)
            {}

            OpenTradeRequest(const rapidjson::Value& obj) : OpenTradeRequest()
            {
                readFromValue(obj);
            }

            ~OpenTradeRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!OfferedInventoryInstanceIds.empty()) {
                    writer.String("OfferedInventoryInstanceIds");
                    writer.StartArray();
                    for (auto iter = OfferedInventoryInstanceIds.begin(); iter != OfferedInventoryInstanceIds.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!RequestedCatalogItemIds.empty()) {
                    writer.String("RequestedCatalogItemIds");
                    writer.StartArray();
                    for (auto iter = RequestedCatalogItemIds.begin(); iter != RequestedCatalogItemIds.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!AllowedPlayerIds.empty()) {
                    writer.String("AllowedPlayerIds");
                    writer.StartArray();
                    for (auto iter = AllowedPlayerIds.begin(); iter != AllowedPlayerIds.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator OfferedInventoryInstanceIds_member = obj.FindMember("OfferedInventoryInstanceIds");
                if (OfferedInventoryInstanceIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = OfferedInventoryInstanceIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        OfferedInventoryInstanceIds.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator RequestedCatalogItemIds_member = obj.FindMember("RequestedCatalogItemIds");
                if (RequestedCatalogItemIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = RequestedCatalogItemIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        RequestedCatalogItemIds.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator AllowedPlayerIds_member = obj.FindMember("AllowedPlayerIds");
                if (AllowedPlayerIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = AllowedPlayerIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        AllowedPlayerIds.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct OpenTradeResponse : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::OpenTradeResponse,"{27fa1d4f-bc9b-5bc5-8c2a-87612f979846}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            TradeInfo* Trade;

            OpenTradeResponse() :
                PlayFabBaseModel(),
                Trade(nullptr)
            {}

            OpenTradeResponse(const OpenTradeResponse& src) :
                PlayFabBaseModel(),
                Trade(src.Trade ? new TradeInfo(*src.Trade) : nullptr)
            {}

            OpenTradeResponse(const rapidjson::Value& obj) : OpenTradeResponse()
            {
                readFromValue(obj);
            }

            ~OpenTradeResponse()
            {
                if (Trade != nullptr) delete Trade;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Trade != nullptr) {
                    writer.String("Trade");
                    Trade->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Trade_member = obj.FindMember("Trade");
                if (Trade_member != obj.MemberEnd() && !Trade_member->value.IsNull()) Trade = new TradeInfo(Trade_member->value);

                return true;
            }
        };

        struct PayForPurchaseRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::PayForPurchaseRequest,"{1112626b-80ca-56e0-bd3e-9132ab0062bf}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string OrderId;
            AZStd::string ProviderName;
            AZStd::string Currency;
            AZStd::string ProviderTransactionId;

            PayForPurchaseRequest() :
                PlayFabBaseModel(),
                OrderId(),
                ProviderName(),
                Currency(),
                ProviderTransactionId()
            {}

            PayForPurchaseRequest(const PayForPurchaseRequest& src) :
                PlayFabBaseModel(),
                OrderId(src.OrderId),
                ProviderName(src.ProviderName),
                Currency(src.Currency),
                ProviderTransactionId(src.ProviderTransactionId)
            {}

            PayForPurchaseRequest(const rapidjson::Value& obj) : PayForPurchaseRequest()
            {
                readFromValue(obj);
            }

            ~PayForPurchaseRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("OrderId");
                writer.String(OrderId.c_str());
                writer.String("ProviderName");
                writer.String(ProviderName.c_str());
                writer.String("Currency");
                writer.String(Currency.c_str());
                if (ProviderTransactionId.length() > 0) {
                    writer.String("ProviderTransactionId");
                    writer.String(ProviderTransactionId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator OrderId_member = obj.FindMember("OrderId");
                if (OrderId_member != obj.MemberEnd() && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();
                const Value::ConstMemberIterator ProviderName_member = obj.FindMember("ProviderName");
                if (ProviderName_member != obj.MemberEnd() && !ProviderName_member->value.IsNull()) ProviderName = ProviderName_member->value.GetString();
                const Value::ConstMemberIterator Currency_member = obj.FindMember("Currency");
                if (Currency_member != obj.MemberEnd() && !Currency_member->value.IsNull()) Currency = Currency_member->value.GetString();
                const Value::ConstMemberIterator ProviderTransactionId_member = obj.FindMember("ProviderTransactionId");
                if (ProviderTransactionId_member != obj.MemberEnd() && !ProviderTransactionId_member->value.IsNull()) ProviderTransactionId = ProviderTransactionId_member->value.GetString();

                return true;
            }
        };

        enum TransactionStatus
        {
            TransactionStatusCreateCart,
            TransactionStatusInit,
            TransactionStatusApproved,
            TransactionStatusSucceeded,
            TransactionStatusFailedByProvider,
            TransactionStatusDisputePending,
            TransactionStatusRefundPending,
            TransactionStatusRefunded,
            TransactionStatusRefundFailed,
            TransactionStatusChargedBack,
            TransactionStatusFailedByUber,
            TransactionStatusFailedByPlayFab,
            TransactionStatusRevoked,
            TransactionStatusTradePending,
            TransactionStatusTraded,
            TransactionStatusUpgraded,
            TransactionStatusStackPending,
            TransactionStatusStacked,
            TransactionStatusOther,
            TransactionStatusFailed
        };

        inline void writeTransactionStatusEnumJSON(TransactionStatus enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case TransactionStatusCreateCart: writer.String("CreateCart"); break;
            case TransactionStatusInit: writer.String("Init"); break;
            case TransactionStatusApproved: writer.String("Approved"); break;
            case TransactionStatusSucceeded: writer.String("Succeeded"); break;
            case TransactionStatusFailedByProvider: writer.String("FailedByProvider"); break;
            case TransactionStatusDisputePending: writer.String("DisputePending"); break;
            case TransactionStatusRefundPending: writer.String("RefundPending"); break;
            case TransactionStatusRefunded: writer.String("Refunded"); break;
            case TransactionStatusRefundFailed: writer.String("RefundFailed"); break;
            case TransactionStatusChargedBack: writer.String("ChargedBack"); break;
            case TransactionStatusFailedByUber: writer.String("FailedByUber"); break;
            case TransactionStatusFailedByPlayFab: writer.String("FailedByPlayFab"); break;
            case TransactionStatusRevoked: writer.String("Revoked"); break;
            case TransactionStatusTradePending: writer.String("TradePending"); break;
            case TransactionStatusTraded: writer.String("Traded"); break;
            case TransactionStatusUpgraded: writer.String("Upgraded"); break;
            case TransactionStatusStackPending: writer.String("StackPending"); break;
            case TransactionStatusStacked: writer.String("Stacked"); break;
            case TransactionStatusOther: writer.String("Other"); break;
            case TransactionStatusFailed: writer.String("Failed"); break;

            }
        }

        inline TransactionStatus readTransactionStatusFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<TransactionStatus>(obj.GetInt());

            static std::map<const char *, TransactionStatus, PlayFabComboSdk::StringCompare> _TransactionStatusMap;
            if (_TransactionStatusMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _TransactionStatusMap["CreateCart"] = TransactionStatusCreateCart;
                _TransactionStatusMap["Init"] = TransactionStatusInit;
                _TransactionStatusMap["Approved"] = TransactionStatusApproved;
                _TransactionStatusMap["Succeeded"] = TransactionStatusSucceeded;
                _TransactionStatusMap["FailedByProvider"] = TransactionStatusFailedByProvider;
                _TransactionStatusMap["DisputePending"] = TransactionStatusDisputePending;
                _TransactionStatusMap["RefundPending"] = TransactionStatusRefundPending;
                _TransactionStatusMap["Refunded"] = TransactionStatusRefunded;
                _TransactionStatusMap["RefundFailed"] = TransactionStatusRefundFailed;
                _TransactionStatusMap["ChargedBack"] = TransactionStatusChargedBack;
                _TransactionStatusMap["FailedByUber"] = TransactionStatusFailedByUber;
                _TransactionStatusMap["FailedByPlayFab"] = TransactionStatusFailedByPlayFab;
                _TransactionStatusMap["Revoked"] = TransactionStatusRevoked;
                _TransactionStatusMap["TradePending"] = TransactionStatusTradePending;
                _TransactionStatusMap["Traded"] = TransactionStatusTraded;
                _TransactionStatusMap["Upgraded"] = TransactionStatusUpgraded;
                _TransactionStatusMap["StackPending"] = TransactionStatusStackPending;
                _TransactionStatusMap["Stacked"] = TransactionStatusStacked;
                _TransactionStatusMap["Other"] = TransactionStatusOther;
                _TransactionStatusMap["Failed"] = TransactionStatusFailed;

            }

            auto output = _TransactionStatusMap.find(obj.GetString());
            if (output != _TransactionStatusMap.end())
                return output->second;

            return TransactionStatusCreateCart; // Basically critical fail
        }

        struct PayForPurchaseResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::PayForPurchaseResult,"{2776ef1d-3647-52b2-9f08-a11d15692366}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string OrderId;
            Boxed<TransactionStatus> Status;
            AZStd::unordered_map<AZStd::string, Int32> VCAmount;
            AZStd::string PurchaseCurrency;
            Uint32 PurchasePrice;
            Uint32 CreditApplied;
            AZStd::string ProviderData;
            AZStd::string PurchaseConfirmationPageURL;
            AZStd::unordered_map<AZStd::string, Int32> VirtualCurrency;
            AZStd::string ProviderToken;

            PayForPurchaseResult() :
                PlayFabBaseModel(),
                OrderId(),
                Status(),
                VCAmount(),
                PurchaseCurrency(),
                PurchasePrice(0),
                CreditApplied(0),
                ProviderData(),
                PurchaseConfirmationPageURL(),
                VirtualCurrency(),
                ProviderToken()
            {}

            PayForPurchaseResult(const PayForPurchaseResult& src) :
                PlayFabBaseModel(),
                OrderId(src.OrderId),
                Status(src.Status),
                VCAmount(src.VCAmount),
                PurchaseCurrency(src.PurchaseCurrency),
                PurchasePrice(src.PurchasePrice),
                CreditApplied(src.CreditApplied),
                ProviderData(src.ProviderData),
                PurchaseConfirmationPageURL(src.PurchaseConfirmationPageURL),
                VirtualCurrency(src.VirtualCurrency),
                ProviderToken(src.ProviderToken)
            {}

            PayForPurchaseResult(const rapidjson::Value& obj) : PayForPurchaseResult()
            {
                readFromValue(obj);
            }

            ~PayForPurchaseResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (OrderId.length() > 0) {
                    writer.String("OrderId");
                    writer.String(OrderId.c_str());
                }
                if (Status.notNull()) {
                    writer.String("Status");
                    writeTransactionStatusEnumJSON(Status, writer);
                }
                if (!VCAmount.empty()) {
                    writer.String("VCAmount");
                    writer.StartObject();
                    for (auto iter = VCAmount.begin(); iter != VCAmount.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.Int(iter->second);
                    }
                    writer.EndObject();
                }
                if (PurchaseCurrency.length() > 0) {
                    writer.String("PurchaseCurrency");
                    writer.String(PurchaseCurrency.c_str());
                }
                writer.String("PurchasePrice");
                writer.Uint(PurchasePrice);
                writer.String("CreditApplied");
                writer.Uint(CreditApplied);
                if (ProviderData.length() > 0) {
                    writer.String("ProviderData");
                    writer.String(ProviderData.c_str());
                }
                if (PurchaseConfirmationPageURL.length() > 0) {
                    writer.String("PurchaseConfirmationPageURL");
                    writer.String(PurchaseConfirmationPageURL.c_str());
                }
                if (!VirtualCurrency.empty()) {
                    writer.String("VirtualCurrency");
                    writer.StartObject();
                    for (auto iter = VirtualCurrency.begin(); iter != VirtualCurrency.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.Int(iter->second);
                    }
                    writer.EndObject();
                }
                if (ProviderToken.length() > 0) {
                    writer.String("ProviderToken");
                    writer.String(ProviderToken.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator OrderId_member = obj.FindMember("OrderId");
                if (OrderId_member != obj.MemberEnd() && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();
                const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
                if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readTransactionStatusFromValue(Status_member->value);
                const Value::ConstMemberIterator VCAmount_member = obj.FindMember("VCAmount");
                if (VCAmount_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VCAmount_member->value.MemberBegin(); iter != VCAmount_member->value.MemberEnd(); ++iter) {
                        VCAmount[iter->name.GetString()] = iter->value.GetInt();
                    }
                }
                const Value::ConstMemberIterator PurchaseCurrency_member = obj.FindMember("PurchaseCurrency");
                if (PurchaseCurrency_member != obj.MemberEnd() && !PurchaseCurrency_member->value.IsNull()) PurchaseCurrency = PurchaseCurrency_member->value.GetString();
                const Value::ConstMemberIterator PurchasePrice_member = obj.FindMember("PurchasePrice");
                if (PurchasePrice_member != obj.MemberEnd() && !PurchasePrice_member->value.IsNull()) PurchasePrice = PurchasePrice_member->value.GetUint();
                const Value::ConstMemberIterator CreditApplied_member = obj.FindMember("CreditApplied");
                if (CreditApplied_member != obj.MemberEnd() && !CreditApplied_member->value.IsNull()) CreditApplied = CreditApplied_member->value.GetUint();
                const Value::ConstMemberIterator ProviderData_member = obj.FindMember("ProviderData");
                if (ProviderData_member != obj.MemberEnd() && !ProviderData_member->value.IsNull()) ProviderData = ProviderData_member->value.GetString();
                const Value::ConstMemberIterator PurchaseConfirmationPageURL_member = obj.FindMember("PurchaseConfirmationPageURL");
                if (PurchaseConfirmationPageURL_member != obj.MemberEnd() && !PurchaseConfirmationPageURL_member->value.IsNull()) PurchaseConfirmationPageURL = PurchaseConfirmationPageURL_member->value.GetString();
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrency_member->value.MemberBegin(); iter != VirtualCurrency_member->value.MemberEnd(); ++iter) {
                        VirtualCurrency[iter->name.GetString()] = iter->value.GetInt();
                    }
                }
                const Value::ConstMemberIterator ProviderToken_member = obj.FindMember("ProviderToken");
                if (ProviderToken_member != obj.MemberEnd() && !ProviderToken_member->value.IsNull()) ProviderToken = ProviderToken_member->value.GetString();

                return true;
            }
        };

        struct PaymentOption : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::PaymentOption,"{df6b1c25-0119-58e0-aeb6-8c2c2f86e82a}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string Currency;
            AZStd::string ProviderName;
            Uint32 Price;
            Uint32 StoreCredit;

            PaymentOption() :
                PlayFabBaseModel(),
                Currency(),
                ProviderName(),
                Price(0),
                StoreCredit(0)
            {}

            PaymentOption(const PaymentOption& src) :
                PlayFabBaseModel(),
                Currency(src.Currency),
                ProviderName(src.ProviderName),
                Price(src.Price),
                StoreCredit(src.StoreCredit)
            {}

            PaymentOption(const rapidjson::Value& obj) : PaymentOption()
            {
                readFromValue(obj);
            }

            ~PaymentOption()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Currency.length() > 0) {
                    writer.String("Currency");
                    writer.String(Currency.c_str());
                }
                if (ProviderName.length() > 0) {
                    writer.String("ProviderName");
                    writer.String(ProviderName.c_str());
                }
                writer.String("Price");
                writer.Uint(Price);
                writer.String("StoreCredit");
                writer.Uint(StoreCredit);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Currency_member = obj.FindMember("Currency");
                if (Currency_member != obj.MemberEnd() && !Currency_member->value.IsNull()) Currency = Currency_member->value.GetString();
                const Value::ConstMemberIterator ProviderName_member = obj.FindMember("ProviderName");
                if (ProviderName_member != obj.MemberEnd() && !ProviderName_member->value.IsNull()) ProviderName = ProviderName_member->value.GetString();
                const Value::ConstMemberIterator Price_member = obj.FindMember("Price");
                if (Price_member != obj.MemberEnd() && !Price_member->value.IsNull()) Price = Price_member->value.GetUint();
                const Value::ConstMemberIterator StoreCredit_member = obj.FindMember("StoreCredit");
                if (StoreCredit_member != obj.MemberEnd() && !StoreCredit_member->value.IsNull()) StoreCredit = StoreCredit_member->value.GetUint();

                return true;
            }
        };

        struct PurchaseItemRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::PurchaseItemRequest,"{7568127a-b41a-5a7a-b90d-51a8add83b1b}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string ItemId;
            AZStd::string VirtualCurrency;
            Int32 Price;
            AZStd::string CatalogVersion;
            AZStd::string StoreId;
            AZStd::string CharacterId;

            PurchaseItemRequest() :
                PlayFabBaseModel(),
                ItemId(),
                VirtualCurrency(),
                Price(0),
                CatalogVersion(),
                StoreId(),
                CharacterId()
            {}

            PurchaseItemRequest(const PurchaseItemRequest& src) :
                PlayFabBaseModel(),
                ItemId(src.ItemId),
                VirtualCurrency(src.VirtualCurrency),
                Price(src.Price),
                CatalogVersion(src.CatalogVersion),
                StoreId(src.StoreId),
                CharacterId(src.CharacterId)
            {}

            PurchaseItemRequest(const rapidjson::Value& obj) : PurchaseItemRequest()
            {
                readFromValue(obj);
            }

            ~PurchaseItemRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ItemId");
                writer.String(ItemId.c_str());
                writer.String("VirtualCurrency");
                writer.String(VirtualCurrency.c_str());
                writer.String("Price");
                writer.Int(Price);
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                if (StoreId.length() > 0) {
                    writer.String("StoreId");
                    writer.String(StoreId.c_str());
                }
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
                const Value::ConstMemberIterator Price_member = obj.FindMember("Price");
                if (Price_member != obj.MemberEnd() && !Price_member->value.IsNull()) Price = Price_member->value.GetInt();
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator StoreId_member = obj.FindMember("StoreId");
                if (StoreId_member != obj.MemberEnd() && !StoreId_member->value.IsNull()) StoreId = StoreId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

                return true;
            }
        };

        struct PurchaseItemResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::PurchaseItemResult,"{7c211989-7be9-5495-bbec-0820acb74cde}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<ItemInstance> Items; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            PurchaseItemResult() :
                PlayFabBaseModel(),
                Items()
            {}

            PurchaseItemResult(const PurchaseItemResult& src) :
                PlayFabBaseModel(),
                Items(src.Items)
            {}

            PurchaseItemResult(const rapidjson::Value& obj) : PurchaseItemResult()
            {
                readFromValue(obj);
            }

            ~PurchaseItemResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Items.empty()) {
                    writer.String("Items");
                    writer.StartArray();
                    for (auto iter = Items.begin(); iter != Items.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Items_member = obj.FindMember("Items");
                if (Items_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Items_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Items.push_back(ItemInstance(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct RedeemCouponRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::RedeemCouponRequest,"{aec51a6d-e2b5-599b-9ea6-084524f1953c}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string CouponCode;
            AZStd::string CatalogVersion;
            AZStd::string CharacterId;

            RedeemCouponRequest() :
                PlayFabBaseModel(),
                CouponCode(),
                CatalogVersion(),
                CharacterId()
            {}

            RedeemCouponRequest(const RedeemCouponRequest& src) :
                PlayFabBaseModel(),
                CouponCode(src.CouponCode),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId)
            {}

            RedeemCouponRequest(const rapidjson::Value& obj) : RedeemCouponRequest()
            {
                readFromValue(obj);
            }

            ~RedeemCouponRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("CouponCode");
                writer.String(CouponCode.c_str());
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CouponCode_member = obj.FindMember("CouponCode");
                if (CouponCode_member != obj.MemberEnd() && !CouponCode_member->value.IsNull()) CouponCode = CouponCode_member->value.GetString();
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

                return true;
            }
        };

        struct RedeemCouponResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::RedeemCouponResult,"{a4ab7622-2eec-5285-aadc-32cedf60aa1e}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<ItemInstance> GrantedItems; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            RedeemCouponResult() :
                PlayFabBaseModel(),
                GrantedItems()
            {}

            RedeemCouponResult(const RedeemCouponResult& src) :
                PlayFabBaseModel(),
                GrantedItems(src.GrantedItems)
            {}

            RedeemCouponResult(const rapidjson::Value& obj) : RedeemCouponResult()
            {
                readFromValue(obj);
            }

            ~RedeemCouponResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!GrantedItems.empty()) {
                    writer.String("GrantedItems");
                    writer.StartArray();
                    for (auto iter = GrantedItems.begin(); iter != GrantedItems.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GrantedItems_member = obj.FindMember("GrantedItems");
                if (GrantedItems_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = GrantedItems_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        GrantedItems.push_back(ItemInstance(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct RegisterForIOSPushNotificationRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::RegisterForIOSPushNotificationRequest,"{25c48145-ed82-5d04-9a81-944b5cef9f46}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string DeviceToken;
            OptionalBool SendPushNotificationConfirmation;
            AZStd::string ConfirmationMessage;

            RegisterForIOSPushNotificationRequest() :
                PlayFabBaseModel(),
                DeviceToken(),
                SendPushNotificationConfirmation(),
                ConfirmationMessage()
            {}

            RegisterForIOSPushNotificationRequest(const RegisterForIOSPushNotificationRequest& src) :
                PlayFabBaseModel(),
                DeviceToken(src.DeviceToken),
                SendPushNotificationConfirmation(src.SendPushNotificationConfirmation),
                ConfirmationMessage(src.ConfirmationMessage)
            {}

            RegisterForIOSPushNotificationRequest(const rapidjson::Value& obj) : RegisterForIOSPushNotificationRequest()
            {
                readFromValue(obj);
            }

            ~RegisterForIOSPushNotificationRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("DeviceToken");
                writer.String(DeviceToken.c_str());
                if (SendPushNotificationConfirmation.notNull()) {
                    writer.String("SendPushNotificationConfirmation");
                    writer.Bool(SendPushNotificationConfirmation);
                }
                if (ConfirmationMessage.length() > 0) {
                    writer.String("ConfirmationMessage");
                    writer.String(ConfirmationMessage.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DeviceToken_member = obj.FindMember("DeviceToken");
                if (DeviceToken_member != obj.MemberEnd() && !DeviceToken_member->value.IsNull()) DeviceToken = DeviceToken_member->value.GetString();
                const Value::ConstMemberIterator SendPushNotificationConfirmation_member = obj.FindMember("SendPushNotificationConfirmation");
                if (SendPushNotificationConfirmation_member != obj.MemberEnd() && !SendPushNotificationConfirmation_member->value.IsNull()) SendPushNotificationConfirmation = SendPushNotificationConfirmation_member->value.GetBool();
                const Value::ConstMemberIterator ConfirmationMessage_member = obj.FindMember("ConfirmationMessage");
                if (ConfirmationMessage_member != obj.MemberEnd() && !ConfirmationMessage_member->value.IsNull()) ConfirmationMessage = ConfirmationMessage_member->value.GetString();

                return true;
            }
        };

        struct RegisterForIOSPushNotificationResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::RegisterForIOSPushNotificationResult,"{6e39550d-e8ab-5630-bc03-3552fcec9614}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            RegisterForIOSPushNotificationResult() :
                PlayFabBaseModel()
            {}

            RegisterForIOSPushNotificationResult(const RegisterForIOSPushNotificationResult& src) :
                PlayFabBaseModel()
            {}

            RegisterForIOSPushNotificationResult(const rapidjson::Value& obj) : RegisterForIOSPushNotificationResult()
            {
                readFromValue(obj);
            }

            ~RegisterForIOSPushNotificationResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct RegisterPlayFabUserRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::RegisterPlayFabUserRequest,"{e59b9484-eb9b-52a5-9ee4-5f1d5f6109a7}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string Username;
            AZStd::string Email;
            AZStd::string Password;
            OptionalBool RequireBothUsernameAndEmail;
            AZStd::string DisplayName;
            AZStd::string TitleId;
            AZStd::string EncryptedRequest;
            AZStd::string PlayerSecret;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;

            RegisterPlayFabUserRequest() :
                PlayFabBaseModel(),
                Username(),
                Email(),
                Password(),
                RequireBothUsernameAndEmail(),
                DisplayName(),
                TitleId(),
                EncryptedRequest(),
                PlayerSecret(),
                InfoRequestParameters(nullptr)
            {}

            RegisterPlayFabUserRequest(const RegisterPlayFabUserRequest& src) :
                PlayFabBaseModel(),
                Username(src.Username),
                Email(src.Email),
                Password(src.Password),
                RequireBothUsernameAndEmail(src.RequireBothUsernameAndEmail),
                DisplayName(src.DisplayName),
                TitleId(src.TitleId),
                EncryptedRequest(src.EncryptedRequest),
                PlayerSecret(src.PlayerSecret),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr)
            {}

            RegisterPlayFabUserRequest(const rapidjson::Value& obj) : RegisterPlayFabUserRequest()
            {
                readFromValue(obj);
            }

            ~RegisterPlayFabUserRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Username.length() > 0) {
                    writer.String("Username");
                    writer.String(Username.c_str());
                }
                if (Email.length() > 0) {
                    writer.String("Email");
                    writer.String(Email.c_str());
                }
                if (Password.length() > 0) {
                    writer.String("Password");
                    writer.String(Password.c_str());
                }
                if (RequireBothUsernameAndEmail.notNull()) {
                    writer.String("RequireBothUsernameAndEmail");
                    writer.Bool(RequireBothUsernameAndEmail);
                }
                if (DisplayName.length() > 0) {
                    writer.String("DisplayName");
                    writer.String(DisplayName.c_str());
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
                const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
                if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
                const Value::ConstMemberIterator Password_member = obj.FindMember("Password");
                if (Password_member != obj.MemberEnd() && !Password_member->value.IsNull()) Password = Password_member->value.GetString();
                const Value::ConstMemberIterator RequireBothUsernameAndEmail_member = obj.FindMember("RequireBothUsernameAndEmail");
                if (RequireBothUsernameAndEmail_member != obj.MemberEnd() && !RequireBothUsernameAndEmail_member->value.IsNull()) RequireBothUsernameAndEmail = RequireBothUsernameAndEmail_member->value.GetBool();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);

                return true;
            }
        };

        struct RegisterPlayFabUserResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::RegisterPlayFabUserResult,"{13f6e940-c9c2-5dfd-bf1d-c60eadb273e0}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string PlayFabId;
            AZStd::string SessionTicket;
            AZStd::string Username;
            UserSettings* SettingsForUser;

            RegisterPlayFabUserResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                SessionTicket(),
                Username(),
                SettingsForUser(nullptr)
            {}

            RegisterPlayFabUserResult(const RegisterPlayFabUserResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                SessionTicket(src.SessionTicket),
                Username(src.Username),
                SettingsForUser(src.SettingsForUser ? new UserSettings(*src.SettingsForUser) : nullptr)
            {}

            RegisterPlayFabUserResult(const rapidjson::Value& obj) : RegisterPlayFabUserResult()
            {
                readFromValue(obj);
            }

            ~RegisterPlayFabUserResult()
            {
                if (SettingsForUser != nullptr) delete SettingsForUser;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                if (SessionTicket.length() > 0) {
                    writer.String("SessionTicket");
                    writer.String(SessionTicket.c_str());
                }
                if (Username.length() > 0) {
                    writer.String("Username");
                    writer.String(Username.c_str());
                }
                if (SettingsForUser != nullptr) {
                    writer.String("SettingsForUser");
                    SettingsForUser->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator SessionTicket_member = obj.FindMember("SessionTicket");
                if (SessionTicket_member != obj.MemberEnd() && !SessionTicket_member->value.IsNull()) SessionTicket = SessionTicket_member->value.GetString();
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
                const Value::ConstMemberIterator SettingsForUser_member = obj.FindMember("SettingsForUser");
                if (SettingsForUser_member != obj.MemberEnd() && !SettingsForUser_member->value.IsNull()) SettingsForUser = new UserSettings(SettingsForUser_member->value);

                return true;
            }
        };

        struct RegisterWithWindowsHelloRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::RegisterWithWindowsHelloRequest,"{96074eeb-db4d-5c13-8c57-2ab7cae2f893}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string UserName;
            AZStd::string PublicKey;
            AZStd::string DeviceName;
            AZStd::string TitleId;
            AZStd::string EncryptedRequest;
            AZStd::string PlayerSecret;
            GetPlayerCombinedInfoRequestParams* InfoRequestParameters;

            RegisterWithWindowsHelloRequest() :
                PlayFabBaseModel(),
                UserName(),
                PublicKey(),
                DeviceName(),
                TitleId(),
                EncryptedRequest(),
                PlayerSecret(),
                InfoRequestParameters(nullptr)
            {}

            RegisterWithWindowsHelloRequest(const RegisterWithWindowsHelloRequest& src) :
                PlayFabBaseModel(),
                UserName(src.UserName),
                PublicKey(src.PublicKey),
                DeviceName(src.DeviceName),
                TitleId(src.TitleId),
                EncryptedRequest(src.EncryptedRequest),
                PlayerSecret(src.PlayerSecret),
                InfoRequestParameters(src.InfoRequestParameters ? new GetPlayerCombinedInfoRequestParams(*src.InfoRequestParameters) : nullptr)
            {}

            RegisterWithWindowsHelloRequest(const rapidjson::Value& obj) : RegisterWithWindowsHelloRequest()
            {
                readFromValue(obj);
            }

            ~RegisterWithWindowsHelloRequest()
            {
                if (InfoRequestParameters != nullptr) delete InfoRequestParameters;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (UserName.length() > 0) {
                    writer.String("UserName");
                    writer.String(UserName.c_str());
                }
                if (PublicKey.length() > 0) {
                    writer.String("PublicKey");
                    writer.String(PublicKey.c_str());
                }
                if (DeviceName.length() > 0) {
                    writer.String("DeviceName");
                    writer.String(DeviceName.c_str());
                }
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                if (InfoRequestParameters != nullptr) {
                    writer.String("InfoRequestParameters");
                    InfoRequestParameters->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator UserName_member = obj.FindMember("UserName");
                if (UserName_member != obj.MemberEnd() && !UserName_member->value.IsNull()) UserName = UserName_member->value.GetString();
                const Value::ConstMemberIterator PublicKey_member = obj.FindMember("PublicKey");
                if (PublicKey_member != obj.MemberEnd() && !PublicKey_member->value.IsNull()) PublicKey = PublicKey_member->value.GetString();
                const Value::ConstMemberIterator DeviceName_member = obj.FindMember("DeviceName");
                if (DeviceName_member != obj.MemberEnd() && !DeviceName_member->value.IsNull()) DeviceName = DeviceName_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator InfoRequestParameters_member = obj.FindMember("InfoRequestParameters");
                if (InfoRequestParameters_member != obj.MemberEnd() && !InfoRequestParameters_member->value.IsNull()) InfoRequestParameters = new GetPlayerCombinedInfoRequestParams(InfoRequestParameters_member->value);

                return true;
            }
        };

        struct RemoveFriendRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::RemoveFriendRequest,"{6564aabd-a3ea-5e9f-b1e3-2d94f54ab79f}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string FriendPlayFabId;

            RemoveFriendRequest() :
                PlayFabBaseModel(),
                FriendPlayFabId()
            {}

            RemoveFriendRequest(const RemoveFriendRequest& src) :
                PlayFabBaseModel(),
                FriendPlayFabId(src.FriendPlayFabId)
            {}

            RemoveFriendRequest(const rapidjson::Value& obj) : RemoveFriendRequest()
            {
                readFromValue(obj);
            }

            ~RemoveFriendRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("FriendPlayFabId");
                writer.String(FriendPlayFabId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
                if (FriendPlayFabId_member != obj.MemberEnd() && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();

                return true;
            }
        };

        struct RemoveFriendResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::RemoveFriendResult,"{63075a72-3c67-5b22-a279-4504d105f9ad}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            RemoveFriendResult() :
                PlayFabBaseModel()
            {}

            RemoveFriendResult(const RemoveFriendResult& src) :
                PlayFabBaseModel()
            {}

            RemoveFriendResult(const rapidjson::Value& obj) : RemoveFriendResult()
            {
                readFromValue(obj);
            }

            ~RemoveFriendResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct RemoveGenericIDRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::RemoveGenericIDRequest,"{686c5e80-4597-5e9f-bbc0-90c25d33dd26}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            GenericServiceId GenericId;

            RemoveGenericIDRequest() :
                PlayFabBaseModel(),
                GenericId()
            {}

            RemoveGenericIDRequest(const RemoveGenericIDRequest& src) :
                PlayFabBaseModel(),
                GenericId(src.GenericId)
            {}

            RemoveGenericIDRequest(const rapidjson::Value& obj) : RemoveGenericIDRequest()
            {
                readFromValue(obj);
            }

            ~RemoveGenericIDRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("GenericId");
                GenericId.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GenericId_member = obj.FindMember("GenericId");
                if (GenericId_member != obj.MemberEnd() && !GenericId_member->value.IsNull()) GenericId = GenericServiceId(GenericId_member->value);

                return true;
            }
        };

        struct RemoveGenericIDResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::RemoveGenericIDResult,"{2dffff34-d54b-5c5b-872f-ad27553b2efe}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            RemoveGenericIDResult() :
                PlayFabBaseModel()
            {}

            RemoveGenericIDResult(const RemoveGenericIDResult& src) :
                PlayFabBaseModel()
            {}

            RemoveGenericIDResult(const rapidjson::Value& obj) : RemoveGenericIDResult()
            {
                readFromValue(obj);
            }

            ~RemoveGenericIDResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct RemoveSharedGroupMembersRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::RemoveSharedGroupMembersRequest,"{71ff2e6c-4115-5985-b0e6-a472a8abdf0b}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string SharedGroupId;
            AZStd::vector<AZStd::string> PlayFabIds; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            RemoveSharedGroupMembersRequest() :
                PlayFabBaseModel(),
                SharedGroupId(),
                PlayFabIds()
            {}

            RemoveSharedGroupMembersRequest(const RemoveSharedGroupMembersRequest& src) :
                PlayFabBaseModel(),
                SharedGroupId(src.SharedGroupId),
                PlayFabIds(src.PlayFabIds)
            {}

            RemoveSharedGroupMembersRequest(const rapidjson::Value& obj) : RemoveSharedGroupMembersRequest()
            {
                readFromValue(obj);
            }

            ~RemoveSharedGroupMembersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("SharedGroupId");
                writer.String(SharedGroupId.c_str());
                writer.String("PlayFabIds");
                writer.StartArray();
                for (auto iter = PlayFabIds.begin(); iter != PlayFabIds.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
                if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();
                const Value::ConstMemberIterator PlayFabIds_member = obj.FindMember("PlayFabIds");
                if (PlayFabIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = PlayFabIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        PlayFabIds.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct RemoveSharedGroupMembersResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::RemoveSharedGroupMembersResult,"{5e17ac7c-bc3e-5c70-b2bb-827b05945779}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            RemoveSharedGroupMembersResult() :
                PlayFabBaseModel()
            {}

            RemoveSharedGroupMembersResult(const RemoveSharedGroupMembersResult& src) :
                PlayFabBaseModel()
            {}

            RemoveSharedGroupMembersResult(const rapidjson::Value& obj) : RemoveSharedGroupMembersResult()
            {
                readFromValue(obj);
            }

            ~RemoveSharedGroupMembersResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct ReportPlayerClientRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ReportPlayerClientRequest,"{f0aa33ba-8f5a-50f3-9bd1-aa9617ad2fba}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string ReporteeId;
            AZStd::string Comment;

            ReportPlayerClientRequest() :
                PlayFabBaseModel(),
                ReporteeId(),
                Comment()
            {}

            ReportPlayerClientRequest(const ReportPlayerClientRequest& src) :
                PlayFabBaseModel(),
                ReporteeId(src.ReporteeId),
                Comment(src.Comment)
            {}

            ReportPlayerClientRequest(const rapidjson::Value& obj) : ReportPlayerClientRequest()
            {
                readFromValue(obj);
            }

            ~ReportPlayerClientRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ReporteeId");
                writer.String(ReporteeId.c_str());
                if (Comment.length() > 0) {
                    writer.String("Comment");
                    writer.String(Comment.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ReporteeId_member = obj.FindMember("ReporteeId");
                if (ReporteeId_member != obj.MemberEnd() && !ReporteeId_member->value.IsNull()) ReporteeId = ReporteeId_member->value.GetString();
                const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
                if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();

                return true;
            }
        };

        struct ReportPlayerClientResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ReportPlayerClientResult,"{172dc8c4-5f00-5c17-97fd-42057361d12e}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            OptionalBool Updated;
            Int32 SubmissionsRemaining;

            ReportPlayerClientResult() :
                PlayFabBaseModel(),
                Updated(),
                SubmissionsRemaining(0)
            {}

            ReportPlayerClientResult(const ReportPlayerClientResult& src) :
                PlayFabBaseModel(),
                Updated(src.Updated),
                SubmissionsRemaining(src.SubmissionsRemaining)
            {}

            ReportPlayerClientResult(const rapidjson::Value& obj) : ReportPlayerClientResult()
            {
                readFromValue(obj);
            }

            ~ReportPlayerClientResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Updated.notNull()) {
                    writer.String("Updated");
                    writer.Bool(Updated);
                }
                writer.String("SubmissionsRemaining");
                writer.Int(SubmissionsRemaining);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Updated_member = obj.FindMember("Updated");
                if (Updated_member != obj.MemberEnd() && !Updated_member->value.IsNull()) Updated = Updated_member->value.GetBool();
                const Value::ConstMemberIterator SubmissionsRemaining_member = obj.FindMember("SubmissionsRemaining");
                if (SubmissionsRemaining_member != obj.MemberEnd() && !SubmissionsRemaining_member->value.IsNull()) SubmissionsRemaining = SubmissionsRemaining_member->value.GetInt();

                return true;
            }
        };

        struct RestoreIOSPurchasesRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::RestoreIOSPurchasesRequest,"{05b0a19d-948a-5093-9322-3dcb6ddab854}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string ReceiptData;

            RestoreIOSPurchasesRequest() :
                PlayFabBaseModel(),
                ReceiptData()
            {}

            RestoreIOSPurchasesRequest(const RestoreIOSPurchasesRequest& src) :
                PlayFabBaseModel(),
                ReceiptData(src.ReceiptData)
            {}

            RestoreIOSPurchasesRequest(const rapidjson::Value& obj) : RestoreIOSPurchasesRequest()
            {
                readFromValue(obj);
            }

            ~RestoreIOSPurchasesRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ReceiptData");
                writer.String(ReceiptData.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ReceiptData_member = obj.FindMember("ReceiptData");
                if (ReceiptData_member != obj.MemberEnd() && !ReceiptData_member->value.IsNull()) ReceiptData = ReceiptData_member->value.GetString();

                return true;
            }
        };

        struct RestoreIOSPurchasesResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::RestoreIOSPurchasesResult,"{afa12e2e-3554-5f0f-b328-2d0444299f48}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            RestoreIOSPurchasesResult() :
                PlayFabBaseModel()
            {}

            RestoreIOSPurchasesResult(const RestoreIOSPurchasesResult& src) :
                PlayFabBaseModel()
            {}

            RestoreIOSPurchasesResult(const rapidjson::Value& obj) : RestoreIOSPurchasesResult()
            {
                readFromValue(obj);
            }

            ~RestoreIOSPurchasesResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct SendAccountRecoveryEmailRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::SendAccountRecoveryEmailRequest,"{80928221-7645-54f4-af9b-a67d826fb08a}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string Email;
            AZStd::string TitleId;

            SendAccountRecoveryEmailRequest() :
                PlayFabBaseModel(),
                Email(),
                TitleId()
            {}

            SendAccountRecoveryEmailRequest(const SendAccountRecoveryEmailRequest& src) :
                PlayFabBaseModel(),
                Email(src.Email),
                TitleId(src.TitleId)
            {}

            SendAccountRecoveryEmailRequest(const rapidjson::Value& obj) : SendAccountRecoveryEmailRequest()
            {
                readFromValue(obj);
            }

            ~SendAccountRecoveryEmailRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Email");
                writer.String(Email.c_str());
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
                if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

                return true;
            }
        };

        struct SendAccountRecoveryEmailResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::SendAccountRecoveryEmailResult,"{e7690244-b5d7-5e82-87e4-89013496bf75}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            SendAccountRecoveryEmailResult() :
                PlayFabBaseModel()
            {}

            SendAccountRecoveryEmailResult(const SendAccountRecoveryEmailResult& src) :
                PlayFabBaseModel()
            {}

            SendAccountRecoveryEmailResult(const rapidjson::Value& obj) : SendAccountRecoveryEmailResult()
            {
                readFromValue(obj);
            }

            ~SendAccountRecoveryEmailResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct SetFriendTagsRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::SetFriendTagsRequest,"{4f6bc224-ac5f-58a3-a5ad-74c80ad0a8ad}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string FriendPlayFabId;
            AZStd::vector<AZStd::string> Tags; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            SetFriendTagsRequest() :
                PlayFabBaseModel(),
                FriendPlayFabId(),
                Tags()
            {}

            SetFriendTagsRequest(const SetFriendTagsRequest& src) :
                PlayFabBaseModel(),
                FriendPlayFabId(src.FriendPlayFabId),
                Tags(src.Tags)
            {}

            SetFriendTagsRequest(const rapidjson::Value& obj) : SetFriendTagsRequest()
            {
                readFromValue(obj);
            }

            ~SetFriendTagsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("FriendPlayFabId");
                writer.String(FriendPlayFabId.c_str());
                writer.String("Tags");
                writer.StartArray();
                for (auto iter = Tags.begin(); iter != Tags.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FriendPlayFabId_member = obj.FindMember("FriendPlayFabId");
                if (FriendPlayFabId_member != obj.MemberEnd() && !FriendPlayFabId_member->value.IsNull()) FriendPlayFabId = FriendPlayFabId_member->value.GetString();
                const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
                if (Tags_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Tags_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Tags.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct SetFriendTagsResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::SetFriendTagsResult,"{007b8227-6c00-5696-8ab7-fa242d2de1b1}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            SetFriendTagsResult() :
                PlayFabBaseModel()
            {}

            SetFriendTagsResult(const SetFriendTagsResult& src) :
                PlayFabBaseModel()
            {}

            SetFriendTagsResult(const rapidjson::Value& obj) : SetFriendTagsResult()
            {
                readFromValue(obj);
            }

            ~SetFriendTagsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct SetPlayerSecretRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::SetPlayerSecretRequest,"{4c3023a4-9675-5374-9ebb-c6ddb0feea9f}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string PlayerSecret;
            AZStd::string EncryptedRequest;

            SetPlayerSecretRequest() :
                PlayFabBaseModel(),
                PlayerSecret(),
                EncryptedRequest()
            {}

            SetPlayerSecretRequest(const SetPlayerSecretRequest& src) :
                PlayFabBaseModel(),
                PlayerSecret(src.PlayerSecret),
                EncryptedRequest(src.EncryptedRequest)
            {}

            SetPlayerSecretRequest(const rapidjson::Value& obj) : SetPlayerSecretRequest()
            {
                readFromValue(obj);
            }

            ~SetPlayerSecretRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayerSecret.length() > 0) {
                    writer.String("PlayerSecret");
                    writer.String(PlayerSecret.c_str());
                }
                if (EncryptedRequest.length() > 0) {
                    writer.String("EncryptedRequest");
                    writer.String(EncryptedRequest.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator EncryptedRequest_member = obj.FindMember("EncryptedRequest");
                if (EncryptedRequest_member != obj.MemberEnd() && !EncryptedRequest_member->value.IsNull()) EncryptedRequest = EncryptedRequest_member->value.GetString();

                return true;
            }
        };

        struct SetPlayerSecretResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::SetPlayerSecretResult,"{591f04f5-51f8-57ba-90d2-bf6a5e275f5a}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            SetPlayerSecretResult() :
                PlayFabBaseModel()
            {}

            SetPlayerSecretResult(const SetPlayerSecretResult& src) :
                PlayFabBaseModel()
            {}

            SetPlayerSecretResult(const rapidjson::Value& obj) : SetPlayerSecretResult()
            {
                readFromValue(obj);
            }

            ~SetPlayerSecretResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct StartGameRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::StartGameRequest,"{f4d5a91d-9954-5534-a895-4bb1ffb6219c}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string BuildVersion;
            Region pfRegion;
            AZStd::string GameMode;
            AZStd::string StatisticName;
            AZStd::string CharacterId;
            AZStd::string CustomCommandLineData;

            StartGameRequest() :
                PlayFabBaseModel(),
                BuildVersion(),
                pfRegion(),
                GameMode(),
                StatisticName(),
                CharacterId(),
                CustomCommandLineData()
            {}

            StartGameRequest(const StartGameRequest& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion),
                pfRegion(src.pfRegion),
                GameMode(src.GameMode),
                StatisticName(src.StatisticName),
                CharacterId(src.CharacterId),
                CustomCommandLineData(src.CustomCommandLineData)
            {}

            StartGameRequest(const rapidjson::Value& obj) : StartGameRequest()
            {
                readFromValue(obj);
            }

            ~StartGameRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("BuildVersion");
                writer.String(BuildVersion.c_str());
                writer.String("Region");
                writeRegionEnumJSON(pfRegion, writer);
                writer.String("GameMode");
                writer.String(GameMode.c_str());
                if (StatisticName.length() > 0) {
                    writer.String("StatisticName");
                    writer.String(StatisticName.c_str());
                }
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                if (CustomCommandLineData.length() > 0) {
                    writer.String("CustomCommandLineData");
                    writer.String(CustomCommandLineData.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildVersion_member = obj.FindMember("BuildVersion");
                if (BuildVersion_member != obj.MemberEnd() && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
                const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
                if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);
                const Value::ConstMemberIterator GameMode_member = obj.FindMember("GameMode");
                if (GameMode_member != obj.MemberEnd() && !GameMode_member->value.IsNull()) GameMode = GameMode_member->value.GetString();
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator CustomCommandLineData_member = obj.FindMember("CustomCommandLineData");
                if (CustomCommandLineData_member != obj.MemberEnd() && !CustomCommandLineData_member->value.IsNull()) CustomCommandLineData = CustomCommandLineData_member->value.GetString();

                return true;
            }
        };

        struct StartGameResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::StartGameResult,"{d11b6c4c-1a52-5a5c-9fe8-657f4085e301}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string LobbyID;
            AZStd::string ServerHostname;
            OptionalInt32 ServerPort;
            AZStd::string Ticket;
            AZStd::string Expires;
            AZStd::string Password;

            StartGameResult() :
                PlayFabBaseModel(),
                LobbyID(),
                ServerHostname(),
                ServerPort(),
                Ticket(),
                Expires(),
                Password()
            {}

            StartGameResult(const StartGameResult& src) :
                PlayFabBaseModel(),
                LobbyID(src.LobbyID),
                ServerHostname(src.ServerHostname),
                ServerPort(src.ServerPort),
                Ticket(src.Ticket),
                Expires(src.Expires),
                Password(src.Password)
            {}

            StartGameResult(const rapidjson::Value& obj) : StartGameResult()
            {
                readFromValue(obj);
            }

            ~StartGameResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (LobbyID.length() > 0) {
                    writer.String("LobbyID");
                    writer.String(LobbyID.c_str());
                }
                if (ServerHostname.length() > 0) {
                    writer.String("ServerHostname");
                    writer.String(ServerHostname.c_str());
                }
                if (ServerPort.notNull()) {
                    writer.String("ServerPort");
                    writer.Int(ServerPort);
                }
                if (Ticket.length() > 0) {
                    writer.String("Ticket");
                    writer.String(Ticket.c_str());
                }
                if (Expires.length() > 0) {
                    writer.String("Expires");
                    writer.String(Expires.c_str());
                }
                if (Password.length() > 0) {
                    writer.String("Password");
                    writer.String(Password.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator LobbyID_member = obj.FindMember("LobbyID");
                if (LobbyID_member != obj.MemberEnd() && !LobbyID_member->value.IsNull()) LobbyID = LobbyID_member->value.GetString();
                const Value::ConstMemberIterator ServerHostname_member = obj.FindMember("ServerHostname");
                if (ServerHostname_member != obj.MemberEnd() && !ServerHostname_member->value.IsNull()) ServerHostname = ServerHostname_member->value.GetString();
                const Value::ConstMemberIterator ServerPort_member = obj.FindMember("ServerPort");
                if (ServerPort_member != obj.MemberEnd() && !ServerPort_member->value.IsNull()) ServerPort = ServerPort_member->value.GetInt();
                const Value::ConstMemberIterator Ticket_member = obj.FindMember("Ticket");
                if (Ticket_member != obj.MemberEnd() && !Ticket_member->value.IsNull()) Ticket = Ticket_member->value.GetString();
                const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
                if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = Expires_member->value.GetString();
                const Value::ConstMemberIterator Password_member = obj.FindMember("Password");
                if (Password_member != obj.MemberEnd() && !Password_member->value.IsNull()) Password = Password_member->value.GetString();

                return true;
            }
        };

        struct StartPurchaseRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::StartPurchaseRequest,"{16ef6704-8b8c-507f-b035-19a1ecf42766}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string CatalogVersion;
            AZStd::string StoreId;
            AZStd::vector<ItemPurchaseRequest> Items; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            StartPurchaseRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                StoreId(),
                Items()
            {}

            StartPurchaseRequest(const StartPurchaseRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                StoreId(src.StoreId),
                Items(src.Items)
            {}

            StartPurchaseRequest(const rapidjson::Value& obj) : StartPurchaseRequest()
            {
                readFromValue(obj);
            }

            ~StartPurchaseRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                if (StoreId.length() > 0) {
                    writer.String("StoreId");
                    writer.String(StoreId.c_str());
                }
                writer.String("Items");
                writer.StartArray();
                for (auto iter = Items.begin(); iter != Items.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator StoreId_member = obj.FindMember("StoreId");
                if (StoreId_member != obj.MemberEnd() && !StoreId_member->value.IsNull()) StoreId = StoreId_member->value.GetString();
                const Value::ConstMemberIterator Items_member = obj.FindMember("Items");
                if (Items_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Items_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Items.push_back(ItemPurchaseRequest(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct StartPurchaseResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::StartPurchaseResult,"{426ed2d7-4f17-588f-aa74-76eeeeafed41}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string OrderId;
            AZStd::vector<CartItem> Contents; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::vector<PaymentOption> PaymentOptions; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::unordered_map<AZStd::string, Int32> VirtualCurrencyBalances;

            StartPurchaseResult() :
                PlayFabBaseModel(),
                OrderId(),
                Contents(),
                PaymentOptions(),
                VirtualCurrencyBalances()
            {}

            StartPurchaseResult(const StartPurchaseResult& src) :
                PlayFabBaseModel(),
                OrderId(src.OrderId),
                Contents(src.Contents),
                PaymentOptions(src.PaymentOptions),
                VirtualCurrencyBalances(src.VirtualCurrencyBalances)
            {}

            StartPurchaseResult(const rapidjson::Value& obj) : StartPurchaseResult()
            {
                readFromValue(obj);
            }

            ~StartPurchaseResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (OrderId.length() > 0) {
                    writer.String("OrderId");
                    writer.String(OrderId.c_str());
                }
                if (!Contents.empty()) {
                    writer.String("Contents");
                    writer.StartArray();
                    for (auto iter = Contents.begin(); iter != Contents.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!PaymentOptions.empty()) {
                    writer.String("PaymentOptions");
                    writer.StartArray();
                    for (auto iter = PaymentOptions.begin(); iter != PaymentOptions.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!VirtualCurrencyBalances.empty()) {
                    writer.String("VirtualCurrencyBalances");
                    writer.StartObject();
                    for (auto iter = VirtualCurrencyBalances.begin(); iter != VirtualCurrencyBalances.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.Int(iter->second);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator OrderId_member = obj.FindMember("OrderId");
                if (OrderId_member != obj.MemberEnd() && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();
                const Value::ConstMemberIterator Contents_member = obj.FindMember("Contents");
                if (Contents_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Contents_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Contents.push_back(CartItem(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator PaymentOptions_member = obj.FindMember("PaymentOptions");
                if (PaymentOptions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = PaymentOptions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        PaymentOptions.push_back(PaymentOption(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator VirtualCurrencyBalances_member = obj.FindMember("VirtualCurrencyBalances");
                if (VirtualCurrencyBalances_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrencyBalances_member->value.MemberBegin(); iter != VirtualCurrencyBalances_member->value.MemberEnd(); ++iter) {
                        VirtualCurrencyBalances[iter->name.GetString()] = iter->value.GetInt();
                    }
                }

                return true;
            }
        };

        struct StatisticUpdate : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::StatisticUpdate,"{95a6af98-ecd8-531f-a75a-b7d1653512a0}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string StatisticName;
            OptionalUint32 Version;
            Int32 Value;

            StatisticUpdate() :
                PlayFabBaseModel(),
                StatisticName(),
                Version(),
                Value(0)
            {}

            StatisticUpdate(const StatisticUpdate& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Version(src.Version),
                Value(src.Value)
            {}

            StatisticUpdate(const rapidjson::Value& obj) : StatisticUpdate()
            {
                readFromValue(obj);
            }

            ~StatisticUpdate()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("StatisticName");
                writer.String(StatisticName.c_str());
                if (Version.notNull()) {
                    writer.String("Version");
                    writer.Uint(Version);
                }
                writer.String("Value");
                writer.Int(Value);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetUint();
                const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
                if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetInt();

                return true;
            }
        };

        struct SubtractUserVirtualCurrencyRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::SubtractUserVirtualCurrencyRequest,"{fdda59e1-f1bb-5a83-8f27-27827c479431}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string VirtualCurrency;
            Int32 Amount;

            SubtractUserVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                VirtualCurrency(),
                Amount(0)
            {}

            SubtractUserVirtualCurrencyRequest(const SubtractUserVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                VirtualCurrency(src.VirtualCurrency),
                Amount(src.Amount)
            {}

            SubtractUserVirtualCurrencyRequest(const rapidjson::Value& obj) : SubtractUserVirtualCurrencyRequest()
            {
                readFromValue(obj);
            }

            ~SubtractUserVirtualCurrencyRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("VirtualCurrency");
                writer.String(VirtualCurrency.c_str());
                writer.String("Amount");
                writer.Int(Amount);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
                const Value::ConstMemberIterator Amount_member = obj.FindMember("Amount");
                if (Amount_member != obj.MemberEnd() && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();

                return true;
            }
        };

        struct UnlinkAndroidDeviceIDRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlinkAndroidDeviceIDRequest,"{98f26794-8d59-5bbe-beea-e3a75100b380}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string AndroidDeviceId;

            UnlinkAndroidDeviceIDRequest() :
                PlayFabBaseModel(),
                AndroidDeviceId()
            {}

            UnlinkAndroidDeviceIDRequest(const UnlinkAndroidDeviceIDRequest& src) :
                PlayFabBaseModel(),
                AndroidDeviceId(src.AndroidDeviceId)
            {}

            UnlinkAndroidDeviceIDRequest(const rapidjson::Value& obj) : UnlinkAndroidDeviceIDRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkAndroidDeviceIDRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (AndroidDeviceId.length() > 0) {
                    writer.String("AndroidDeviceId");
                    writer.String(AndroidDeviceId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator AndroidDeviceId_member = obj.FindMember("AndroidDeviceId");
                if (AndroidDeviceId_member != obj.MemberEnd() && !AndroidDeviceId_member->value.IsNull()) AndroidDeviceId = AndroidDeviceId_member->value.GetString();

                return true;
            }
        };

        struct UnlinkAndroidDeviceIDResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlinkAndroidDeviceIDResult,"{5338e327-d7af-516a-8bb6-24d163cc7fa0}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            UnlinkAndroidDeviceIDResult() :
                PlayFabBaseModel()
            {}

            UnlinkAndroidDeviceIDResult(const UnlinkAndroidDeviceIDResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkAndroidDeviceIDResult(const rapidjson::Value& obj) : UnlinkAndroidDeviceIDResult()
            {
                readFromValue(obj);
            }

            ~UnlinkAndroidDeviceIDResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkCustomIDRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlinkCustomIDRequest,"{1591fa08-4f52-5b50-9e67-59d1653cbb10}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string CustomId;

            UnlinkCustomIDRequest() :
                PlayFabBaseModel(),
                CustomId()
            {}

            UnlinkCustomIDRequest(const UnlinkCustomIDRequest& src) :
                PlayFabBaseModel(),
                CustomId(src.CustomId)
            {}

            UnlinkCustomIDRequest(const rapidjson::Value& obj) : UnlinkCustomIDRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkCustomIDRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CustomId.length() > 0) {
                    writer.String("CustomId");
                    writer.String(CustomId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CustomId_member = obj.FindMember("CustomId");
                if (CustomId_member != obj.MemberEnd() && !CustomId_member->value.IsNull()) CustomId = CustomId_member->value.GetString();

                return true;
            }
        };

        struct UnlinkCustomIDResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlinkCustomIDResult,"{dd0d71e2-368d-55dc-8fd3-26e93be3cadc}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            UnlinkCustomIDResult() :
                PlayFabBaseModel()
            {}

            UnlinkCustomIDResult(const UnlinkCustomIDResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkCustomIDResult(const rapidjson::Value& obj) : UnlinkCustomIDResult()
            {
                readFromValue(obj);
            }

            ~UnlinkCustomIDResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkFacebookAccountRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlinkFacebookAccountRequest,"{f709f744-97bf-5778-9b00-1cdb35bbf56b}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            UnlinkFacebookAccountRequest() :
                PlayFabBaseModel()
            {}

            UnlinkFacebookAccountRequest(const UnlinkFacebookAccountRequest& src) :
                PlayFabBaseModel()
            {}

            UnlinkFacebookAccountRequest(const rapidjson::Value& obj) : UnlinkFacebookAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkFacebookAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkFacebookAccountResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlinkFacebookAccountResult,"{165c57d1-d446-59e2-8584-5422f5590ee8}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            UnlinkFacebookAccountResult() :
                PlayFabBaseModel()
            {}

            UnlinkFacebookAccountResult(const UnlinkFacebookAccountResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkFacebookAccountResult(const rapidjson::Value& obj) : UnlinkFacebookAccountResult()
            {
                readFromValue(obj);
            }

            ~UnlinkFacebookAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkGameCenterAccountRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlinkGameCenterAccountRequest,"{fdd4a772-5cc7-5b1f-b00a-7a5a5293b82d}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            UnlinkGameCenterAccountRequest() :
                PlayFabBaseModel()
            {}

            UnlinkGameCenterAccountRequest(const UnlinkGameCenterAccountRequest& src) :
                PlayFabBaseModel()
            {}

            UnlinkGameCenterAccountRequest(const rapidjson::Value& obj) : UnlinkGameCenterAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkGameCenterAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkGameCenterAccountResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlinkGameCenterAccountResult,"{75bf3d00-2001-555f-bdec-c461088d2b19}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            UnlinkGameCenterAccountResult() :
                PlayFabBaseModel()
            {}

            UnlinkGameCenterAccountResult(const UnlinkGameCenterAccountResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkGameCenterAccountResult(const rapidjson::Value& obj) : UnlinkGameCenterAccountResult()
            {
                readFromValue(obj);
            }

            ~UnlinkGameCenterAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkGoogleAccountRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlinkGoogleAccountRequest,"{6f1805ce-38c1-5918-8bcb-ba3c4f658429}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            UnlinkGoogleAccountRequest() :
                PlayFabBaseModel()
            {}

            UnlinkGoogleAccountRequest(const UnlinkGoogleAccountRequest& src) :
                PlayFabBaseModel()
            {}

            UnlinkGoogleAccountRequest(const rapidjson::Value& obj) : UnlinkGoogleAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkGoogleAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkGoogleAccountResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlinkGoogleAccountResult,"{cc26accb-75e4-5330-a651-3adbacc79e83}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            UnlinkGoogleAccountResult() :
                PlayFabBaseModel()
            {}

            UnlinkGoogleAccountResult(const UnlinkGoogleAccountResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkGoogleAccountResult(const rapidjson::Value& obj) : UnlinkGoogleAccountResult()
            {
                readFromValue(obj);
            }

            ~UnlinkGoogleAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkIOSDeviceIDRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlinkIOSDeviceIDRequest,"{6aa08f65-161b-5a54-929e-287cb7bc05ba}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string DeviceId;

            UnlinkIOSDeviceIDRequest() :
                PlayFabBaseModel(),
                DeviceId()
            {}

            UnlinkIOSDeviceIDRequest(const UnlinkIOSDeviceIDRequest& src) :
                PlayFabBaseModel(),
                DeviceId(src.DeviceId)
            {}

            UnlinkIOSDeviceIDRequest(const rapidjson::Value& obj) : UnlinkIOSDeviceIDRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkIOSDeviceIDRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (DeviceId.length() > 0) {
                    writer.String("DeviceId");
                    writer.String(DeviceId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DeviceId_member = obj.FindMember("DeviceId");
                if (DeviceId_member != obj.MemberEnd() && !DeviceId_member->value.IsNull()) DeviceId = DeviceId_member->value.GetString();

                return true;
            }
        };

        struct UnlinkIOSDeviceIDResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlinkIOSDeviceIDResult,"{b930b2de-b005-5db7-ba68-47a3c62e2c18}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            UnlinkIOSDeviceIDResult() :
                PlayFabBaseModel()
            {}

            UnlinkIOSDeviceIDResult(const UnlinkIOSDeviceIDResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkIOSDeviceIDResult(const rapidjson::Value& obj) : UnlinkIOSDeviceIDResult()
            {
                readFromValue(obj);
            }

            ~UnlinkIOSDeviceIDResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkKongregateAccountRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlinkKongregateAccountRequest,"{30eaaa28-78e2-5148-b3fe-c2f3cce0fde7}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            UnlinkKongregateAccountRequest() :
                PlayFabBaseModel()
            {}

            UnlinkKongregateAccountRequest(const UnlinkKongregateAccountRequest& src) :
                PlayFabBaseModel()
            {}

            UnlinkKongregateAccountRequest(const rapidjson::Value& obj) : UnlinkKongregateAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkKongregateAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkKongregateAccountResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlinkKongregateAccountResult,"{8d4268d1-401d-5dce-bd1f-3f5bbc3df040}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            UnlinkKongregateAccountResult() :
                PlayFabBaseModel()
            {}

            UnlinkKongregateAccountResult(const UnlinkKongregateAccountResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkKongregateAccountResult(const rapidjson::Value& obj) : UnlinkKongregateAccountResult()
            {
                readFromValue(obj);
            }

            ~UnlinkKongregateAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkSteamAccountRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlinkSteamAccountRequest,"{3974a82a-6c5b-5ab6-97d4-d3c40ac8c8fb}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            UnlinkSteamAccountRequest() :
                PlayFabBaseModel()
            {}

            UnlinkSteamAccountRequest(const UnlinkSteamAccountRequest& src) :
                PlayFabBaseModel()
            {}

            UnlinkSteamAccountRequest(const rapidjson::Value& obj) : UnlinkSteamAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkSteamAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkSteamAccountResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlinkSteamAccountResult,"{65c6d5f9-46ab-58df-ace4-68661e4899f8}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            UnlinkSteamAccountResult() :
                PlayFabBaseModel()
            {}

            UnlinkSteamAccountResult(const UnlinkSteamAccountResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkSteamAccountResult(const rapidjson::Value& obj) : UnlinkSteamAccountResult()
            {
                readFromValue(obj);
            }

            ~UnlinkSteamAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkTwitchAccountRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlinkTwitchAccountRequest,"{f68bda26-2fe0-575b-b7cd-c19419da15be}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            UnlinkTwitchAccountRequest() :
                PlayFabBaseModel()
            {}

            UnlinkTwitchAccountRequest(const UnlinkTwitchAccountRequest& src) :
                PlayFabBaseModel()
            {}

            UnlinkTwitchAccountRequest(const rapidjson::Value& obj) : UnlinkTwitchAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkTwitchAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkTwitchAccountResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlinkTwitchAccountResult,"{fa5116bd-1d1b-5c1e-8e84-92394f87f8d5}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            UnlinkTwitchAccountResult() :
                PlayFabBaseModel()
            {}

            UnlinkTwitchAccountResult(const UnlinkTwitchAccountResult& src) :
                PlayFabBaseModel()
            {}

            UnlinkTwitchAccountResult(const rapidjson::Value& obj) : UnlinkTwitchAccountResult()
            {
                readFromValue(obj);
            }

            ~UnlinkTwitchAccountResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlinkWindowsHelloAccountRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlinkWindowsHelloAccountRequest,"{d9811aef-13fc-55f2-86a2-55bd6312711e}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string PublicKeyHint;

            UnlinkWindowsHelloAccountRequest() :
                PlayFabBaseModel(),
                PublicKeyHint()
            {}

            UnlinkWindowsHelloAccountRequest(const UnlinkWindowsHelloAccountRequest& src) :
                PlayFabBaseModel(),
                PublicKeyHint(src.PublicKeyHint)
            {}

            UnlinkWindowsHelloAccountRequest(const rapidjson::Value& obj) : UnlinkWindowsHelloAccountRequest()
            {
                readFromValue(obj);
            }

            ~UnlinkWindowsHelloAccountRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PublicKeyHint");
                writer.String(PublicKeyHint.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PublicKeyHint_member = obj.FindMember("PublicKeyHint");
                if (PublicKeyHint_member != obj.MemberEnd() && !PublicKeyHint_member->value.IsNull()) PublicKeyHint = PublicKeyHint_member->value.GetString();

                return true;
            }
        };

        struct UnlinkWindowsHelloAccountResponse : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlinkWindowsHelloAccountResponse,"{b9d92591-64a9-5e45-b068-d9b982ee0a45}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            UnlinkWindowsHelloAccountResponse() :
                PlayFabBaseModel()
            {}

            UnlinkWindowsHelloAccountResponse(const UnlinkWindowsHelloAccountResponse& src) :
                PlayFabBaseModel()
            {}

            UnlinkWindowsHelloAccountResponse(const rapidjson::Value& obj) : UnlinkWindowsHelloAccountResponse()
            {
                readFromValue(obj);
            }

            ~UnlinkWindowsHelloAccountResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UnlockContainerInstanceRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlockContainerInstanceRequest,"{999b9c57-aea9-50ca-94f1-7a3a77e04132}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string CharacterId;
            AZStd::string ContainerItemInstanceId;
            AZStd::string KeyItemInstanceId;
            AZStd::string CatalogVersion;

            UnlockContainerInstanceRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                ContainerItemInstanceId(),
                KeyItemInstanceId(),
                CatalogVersion()
            {}

            UnlockContainerInstanceRequest(const UnlockContainerInstanceRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                ContainerItemInstanceId(src.ContainerItemInstanceId),
                KeyItemInstanceId(src.KeyItemInstanceId),
                CatalogVersion(src.CatalogVersion)
            {}

            UnlockContainerInstanceRequest(const rapidjson::Value& obj) : UnlockContainerInstanceRequest()
            {
                readFromValue(obj);
            }

            ~UnlockContainerInstanceRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                writer.String("ContainerItemInstanceId");
                writer.String(ContainerItemInstanceId.c_str());
                if (KeyItemInstanceId.length() > 0) {
                    writer.String("KeyItemInstanceId");
                    writer.String(KeyItemInstanceId.c_str());
                }
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator ContainerItemInstanceId_member = obj.FindMember("ContainerItemInstanceId");
                if (ContainerItemInstanceId_member != obj.MemberEnd() && !ContainerItemInstanceId_member->value.IsNull()) ContainerItemInstanceId = ContainerItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator KeyItemInstanceId_member = obj.FindMember("KeyItemInstanceId");
                if (KeyItemInstanceId_member != obj.MemberEnd() && !KeyItemInstanceId_member->value.IsNull()) KeyItemInstanceId = KeyItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();

                return true;
            }
        };

        struct UnlockContainerItemRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlockContainerItemRequest,"{6575a654-517f-5a3e-9ced-ff96d52d2345}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string ContainerItemId;
            AZStd::string CatalogVersion;
            AZStd::string CharacterId;

            UnlockContainerItemRequest() :
                PlayFabBaseModel(),
                ContainerItemId(),
                CatalogVersion(),
                CharacterId()
            {}

            UnlockContainerItemRequest(const UnlockContainerItemRequest& src) :
                PlayFabBaseModel(),
                ContainerItemId(src.ContainerItemId),
                CatalogVersion(src.CatalogVersion),
                CharacterId(src.CharacterId)
            {}

            UnlockContainerItemRequest(const rapidjson::Value& obj) : UnlockContainerItemRequest()
            {
                readFromValue(obj);
            }

            ~UnlockContainerItemRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ContainerItemId");
                writer.String(ContainerItemId.c_str());
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ContainerItemId_member = obj.FindMember("ContainerItemId");
                if (ContainerItemId_member != obj.MemberEnd() && !ContainerItemId_member->value.IsNull()) ContainerItemId = ContainerItemId_member->value.GetString();
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

                return true;
            }
        };

        struct UnlockContainerItemResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UnlockContainerItemResult,"{953d9ebf-27c7-57b1-b049-0923c5bf610f}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string UnlockedItemInstanceId;
            AZStd::string UnlockedWithItemInstanceId;
            AZStd::vector<ItemInstance> GrantedItems; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            AZStd::unordered_map<AZStd::string, Uint32> VirtualCurrency;

            UnlockContainerItemResult() :
                PlayFabBaseModel(),
                UnlockedItemInstanceId(),
                UnlockedWithItemInstanceId(),
                GrantedItems(),
                VirtualCurrency()
            {}

            UnlockContainerItemResult(const UnlockContainerItemResult& src) :
                PlayFabBaseModel(),
                UnlockedItemInstanceId(src.UnlockedItemInstanceId),
                UnlockedWithItemInstanceId(src.UnlockedWithItemInstanceId),
                GrantedItems(src.GrantedItems),
                VirtualCurrency(src.VirtualCurrency)
            {}

            UnlockContainerItemResult(const rapidjson::Value& obj) : UnlockContainerItemResult()
            {
                readFromValue(obj);
            }

            ~UnlockContainerItemResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (UnlockedItemInstanceId.length() > 0) {
                    writer.String("UnlockedItemInstanceId");
                    writer.String(UnlockedItemInstanceId.c_str());
                }
                if (UnlockedWithItemInstanceId.length() > 0) {
                    writer.String("UnlockedWithItemInstanceId");
                    writer.String(UnlockedWithItemInstanceId.c_str());
                }
                if (!GrantedItems.empty()) {
                    writer.String("GrantedItems");
                    writer.StartArray();
                    for (auto iter = GrantedItems.begin(); iter != GrantedItems.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!VirtualCurrency.empty()) {
                    writer.String("VirtualCurrency");
                    writer.StartObject();
                    for (auto iter = VirtualCurrency.begin(); iter != VirtualCurrency.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator UnlockedItemInstanceId_member = obj.FindMember("UnlockedItemInstanceId");
                if (UnlockedItemInstanceId_member != obj.MemberEnd() && !UnlockedItemInstanceId_member->value.IsNull()) UnlockedItemInstanceId = UnlockedItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator UnlockedWithItemInstanceId_member = obj.FindMember("UnlockedWithItemInstanceId");
                if (UnlockedWithItemInstanceId_member != obj.MemberEnd() && !UnlockedWithItemInstanceId_member->value.IsNull()) UnlockedWithItemInstanceId = UnlockedWithItemInstanceId_member->value.GetString();
                const Value::ConstMemberIterator GrantedItems_member = obj.FindMember("GrantedItems");
                if (GrantedItems_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = GrantedItems_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        GrantedItems.push_back(ItemInstance(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrency_member->value.MemberBegin(); iter != VirtualCurrency_member->value.MemberEnd(); ++iter) {
                        VirtualCurrency[iter->name.GetString()] = iter->value.GetUint();
                    }
                }

                return true;
            }
        };

        struct UpdateAvatarUrlRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UpdateAvatarUrlRequest,"{fb1890e1-d4cf-57cf-8860-244f8c7294a0}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string ImageUrl;

            UpdateAvatarUrlRequest() :
                PlayFabBaseModel(),
                ImageUrl()
            {}

            UpdateAvatarUrlRequest(const UpdateAvatarUrlRequest& src) :
                PlayFabBaseModel(),
                ImageUrl(src.ImageUrl)
            {}

            UpdateAvatarUrlRequest(const rapidjson::Value& obj) : UpdateAvatarUrlRequest()
            {
                readFromValue(obj);
            }

            ~UpdateAvatarUrlRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ImageUrl");
                writer.String(ImageUrl.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ImageUrl_member = obj.FindMember("ImageUrl");
                if (ImageUrl_member != obj.MemberEnd() && !ImageUrl_member->value.IsNull()) ImageUrl = ImageUrl_member->value.GetString();

                return true;
            }
        };

        struct UpdateCharacterDataRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UpdateCharacterDataRequest,"{339b8e44-a831-5aff-a2d2-9d0685baf204}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string CharacterId;
            AZStd::unordered_map<AZStd::string, AZStd::string> Data;
            AZStd::vector<AZStd::string> KeysToRemove; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            Boxed<UserDataPermission> Permission;

            UpdateCharacterDataRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                Data(),
                KeysToRemove(),
                Permission()
            {}

            UpdateCharacterDataRequest(const UpdateCharacterDataRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission)
            {}

            UpdateCharacterDataRequest(const rapidjson::Value& obj) : UpdateCharacterDataRequest()
            {
                readFromValue(obj);
            }

            ~UpdateCharacterDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("CharacterId");
                writer.String(CharacterId.c_str());
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartObject();
                    for (auto iter = Data.begin(); iter != Data.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                if (!KeysToRemove.empty()) {
                    writer.String("KeysToRemove");
                    writer.StartArray();
                    for (auto iter = KeysToRemove.begin(); iter != KeysToRemove.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (Permission.notNull()) {
                    writer.String("Permission");
                    writeUserDataPermissionEnumJSON(Permission, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
                        Data[iter->name.GetString()] = iter->value.GetString();
                    }
                }
                const Value::ConstMemberIterator KeysToRemove_member = obj.FindMember("KeysToRemove");
                if (KeysToRemove_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = KeysToRemove_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        KeysToRemove.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
                if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

                return true;
            }
        };

        struct UpdateCharacterDataResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UpdateCharacterDataResult,"{7f1fcf01-d138-5169-a198-91057301f6ef}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            Uint32 DataVersion;

            UpdateCharacterDataResult() :
                PlayFabBaseModel(),
                DataVersion(0)
            {}

            UpdateCharacterDataResult(const UpdateCharacterDataResult& src) :
                PlayFabBaseModel(),
                DataVersion(src.DataVersion)
            {}

            UpdateCharacterDataResult(const rapidjson::Value& obj) : UpdateCharacterDataResult()
            {
                readFromValue(obj);
            }

            ~UpdateCharacterDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("DataVersion");
                writer.Uint(DataVersion);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DataVersion_member = obj.FindMember("DataVersion");
                if (DataVersion_member != obj.MemberEnd() && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();

                return true;
            }
        };

        struct UpdateCharacterStatisticsRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UpdateCharacterStatisticsRequest,"{480248df-a81d-5860-8a8d-21c109663838}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string CharacterId;
            AZStd::unordered_map<AZStd::string, Int32> CharacterStatistics;

            UpdateCharacterStatisticsRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                CharacterStatistics()
            {}

            UpdateCharacterStatisticsRequest(const UpdateCharacterStatisticsRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                CharacterStatistics(src.CharacterStatistics)
            {}

            UpdateCharacterStatisticsRequest(const rapidjson::Value& obj) : UpdateCharacterStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~UpdateCharacterStatisticsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("CharacterId");
                writer.String(CharacterId.c_str());
                if (!CharacterStatistics.empty()) {
                    writer.String("CharacterStatistics");
                    writer.StartObject();
                    for (auto iter = CharacterStatistics.begin(); iter != CharacterStatistics.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.Int(iter->second);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator CharacterStatistics_member = obj.FindMember("CharacterStatistics");
                if (CharacterStatistics_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = CharacterStatistics_member->value.MemberBegin(); iter != CharacterStatistics_member->value.MemberEnd(); ++iter) {
                        CharacterStatistics[iter->name.GetString()] = iter->value.GetInt();
                    }
                }

                return true;
            }
        };

        struct UpdateCharacterStatisticsResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UpdateCharacterStatisticsResult,"{15ec35aa-4231-5426-ba67-1d9f93cf76dd}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            UpdateCharacterStatisticsResult() :
                PlayFabBaseModel()
            {}

            UpdateCharacterStatisticsResult(const UpdateCharacterStatisticsResult& src) :
                PlayFabBaseModel()
            {}

            UpdateCharacterStatisticsResult(const rapidjson::Value& obj) : UpdateCharacterStatisticsResult()
            {
                readFromValue(obj);
            }

            ~UpdateCharacterStatisticsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UpdatePlayerStatisticsRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UpdatePlayerStatisticsRequest,"{7339f24b-2981-583d-8245-7257061db126}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::vector<StatisticUpdate> Statistics; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.

            UpdatePlayerStatisticsRequest() :
                PlayFabBaseModel(),
                Statistics()
            {}

            UpdatePlayerStatisticsRequest(const UpdatePlayerStatisticsRequest& src) :
                PlayFabBaseModel(),
                Statistics(src.Statistics)
            {}

            UpdatePlayerStatisticsRequest(const rapidjson::Value& obj) : UpdatePlayerStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~UpdatePlayerStatisticsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Statistics");
                writer.StartArray();
                for (auto iter = Statistics.begin(); iter != Statistics.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Statistics_member = obj.FindMember("Statistics");
                if (Statistics_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Statistics_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Statistics.push_back(StatisticUpdate(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct UpdatePlayerStatisticsResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UpdatePlayerStatisticsResult,"{c230cf58-ab85-5d77-8407-e5bebf582098}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            UpdatePlayerStatisticsResult() :
                PlayFabBaseModel()
            {}

            UpdatePlayerStatisticsResult(const UpdatePlayerStatisticsResult& src) :
                PlayFabBaseModel()
            {}

            UpdatePlayerStatisticsResult(const rapidjson::Value& obj) : UpdatePlayerStatisticsResult()
            {
                readFromValue(obj);
            }

            ~UpdatePlayerStatisticsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UpdateSharedGroupDataRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UpdateSharedGroupDataRequest,"{d6c2b1db-29cb-523c-935c-74b257bab3f7}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string SharedGroupId;
            AZStd::unordered_map<AZStd::string, AZStd::string> Data;
            AZStd::vector<AZStd::string> KeysToRemove; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            Boxed<UserDataPermission> Permission;

            UpdateSharedGroupDataRequest() :
                PlayFabBaseModel(),
                SharedGroupId(),
                Data(),
                KeysToRemove(),
                Permission()
            {}

            UpdateSharedGroupDataRequest(const UpdateSharedGroupDataRequest& src) :
                PlayFabBaseModel(),
                SharedGroupId(src.SharedGroupId),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission)
            {}

            UpdateSharedGroupDataRequest(const rapidjson::Value& obj) : UpdateSharedGroupDataRequest()
            {
                readFromValue(obj);
            }

            ~UpdateSharedGroupDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("SharedGroupId");
                writer.String(SharedGroupId.c_str());
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartObject();
                    for (auto iter = Data.begin(); iter != Data.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                if (!KeysToRemove.empty()) {
                    writer.String("KeysToRemove");
                    writer.StartArray();
                    for (auto iter = KeysToRemove.begin(); iter != KeysToRemove.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (Permission.notNull()) {
                    writer.String("Permission");
                    writeUserDataPermissionEnumJSON(Permission, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SharedGroupId_member = obj.FindMember("SharedGroupId");
                if (SharedGroupId_member != obj.MemberEnd() && !SharedGroupId_member->value.IsNull()) SharedGroupId = SharedGroupId_member->value.GetString();
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
                        Data[iter->name.GetString()] = iter->value.GetString();
                    }
                }
                const Value::ConstMemberIterator KeysToRemove_member = obj.FindMember("KeysToRemove");
                if (KeysToRemove_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = KeysToRemove_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        KeysToRemove.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
                if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

                return true;
            }
        };

        struct UpdateSharedGroupDataResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UpdateSharedGroupDataResult,"{c0d47df4-51c7-5178-9886-079a7b531a56}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            UpdateSharedGroupDataResult() :
                PlayFabBaseModel()
            {}

            UpdateSharedGroupDataResult(const UpdateSharedGroupDataResult& src) :
                PlayFabBaseModel()
            {}

            UpdateSharedGroupDataResult(const rapidjson::Value& obj) : UpdateSharedGroupDataResult()
            {
                readFromValue(obj);
            }

            ~UpdateSharedGroupDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct UpdateUserDataRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UpdateUserDataRequest,"{f6129c03-a3e4-539b-8784-c9b5844edb26}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::unordered_map<AZStd::string, AZStd::string> Data;
            AZStd::vector<AZStd::string> KeysToRemove; 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context.
            Boxed<UserDataPermission> Permission;

            UpdateUserDataRequest() :
                PlayFabBaseModel(),
                Data(),
                KeysToRemove(),
                Permission()
            {}

            UpdateUserDataRequest(const UpdateUserDataRequest& src) :
                PlayFabBaseModel(),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove),
                Permission(src.Permission)
            {}

            UpdateUserDataRequest(const rapidjson::Value& obj) : UpdateUserDataRequest()
            {
                readFromValue(obj);
            }

            ~UpdateUserDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartObject();
                    for (auto iter = Data.begin(); iter != Data.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                if (!KeysToRemove.empty()) {
                    writer.String("KeysToRemove");
                    writer.StartArray();
                    for (auto iter = KeysToRemove.begin(); iter != KeysToRemove.end(); iter++) { 	// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::list to AZStd::vector because the latter supports reflection to behavior context. 
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (Permission.notNull()) {
                    writer.String("Permission");
                    writeUserDataPermissionEnumJSON(Permission, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
                        Data[iter->name.GetString()] = iter->value.GetString();
                    }
                }
                const Value::ConstMemberIterator KeysToRemove_member = obj.FindMember("KeysToRemove");
                if (KeysToRemove_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = KeysToRemove_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        KeysToRemove.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator Permission_member = obj.FindMember("Permission");
                if (Permission_member != obj.MemberEnd() && !Permission_member->value.IsNull()) Permission = readUserDataPermissionFromValue(Permission_member->value);

                return true;
            }
        };

        struct UpdateUserDataResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UpdateUserDataResult,"{4f3b9cc0-bb49-5773-8676-7638ae1bfa47}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            Uint32 DataVersion;

            UpdateUserDataResult() :
                PlayFabBaseModel(),
                DataVersion(0)
            {}

            UpdateUserDataResult(const UpdateUserDataResult& src) :
                PlayFabBaseModel(),
                DataVersion(src.DataVersion)
            {}

            UpdateUserDataResult(const rapidjson::Value& obj) : UpdateUserDataResult()
            {
                readFromValue(obj);
            }

            ~UpdateUserDataResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("DataVersion");
                writer.Uint(DataVersion);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DataVersion_member = obj.FindMember("DataVersion");
                if (DataVersion_member != obj.MemberEnd() && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();

                return true;
            }
        };

        struct UpdateUserTitleDisplayNameRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UpdateUserTitleDisplayNameRequest,"{ff6d0c58-a83b-50b8-8278-243804a3abfe}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string DisplayName;

            UpdateUserTitleDisplayNameRequest() :
                PlayFabBaseModel(),
                DisplayName()
            {}

            UpdateUserTitleDisplayNameRequest(const UpdateUserTitleDisplayNameRequest& src) :
                PlayFabBaseModel(),
                DisplayName(src.DisplayName)
            {}

            UpdateUserTitleDisplayNameRequest(const rapidjson::Value& obj) : UpdateUserTitleDisplayNameRequest()
            {
                readFromValue(obj);
            }

            ~UpdateUserTitleDisplayNameRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("DisplayName");
                writer.String(DisplayName.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();

                return true;
            }
        };

        struct UpdateUserTitleDisplayNameResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::UpdateUserTitleDisplayNameResult,"{7a89cf16-b0b5-5185-a140-f8118b37a15f}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string DisplayName;

            UpdateUserTitleDisplayNameResult() :
                PlayFabBaseModel(),
                DisplayName()
            {}

            UpdateUserTitleDisplayNameResult(const UpdateUserTitleDisplayNameResult& src) :
                PlayFabBaseModel(),
                DisplayName(src.DisplayName)
            {}

            UpdateUserTitleDisplayNameResult(const rapidjson::Value& obj) : UpdateUserTitleDisplayNameResult()
            {
                readFromValue(obj);
            }

            ~UpdateUserTitleDisplayNameResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (DisplayName.length() > 0) {
                    writer.String("DisplayName");
                    writer.String(DisplayName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();

                return true;
            }
        };

        struct ValidateAmazonReceiptRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ValidateAmazonReceiptRequest,"{feaecd8f-6008-502f-b44e-b6eb8e5a2388}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string ReceiptId;
            AZStd::string UserId;
            AZStd::string CatalogVersion;
            AZStd::string CurrencyCode;
            Int32 PurchasePrice;

            ValidateAmazonReceiptRequest() :
                PlayFabBaseModel(),
                ReceiptId(),
                UserId(),
                CatalogVersion(),
                CurrencyCode(),
                PurchasePrice(0)
            {}

            ValidateAmazonReceiptRequest(const ValidateAmazonReceiptRequest& src) :
                PlayFabBaseModel(),
                ReceiptId(src.ReceiptId),
                UserId(src.UserId),
                CatalogVersion(src.CatalogVersion),
                CurrencyCode(src.CurrencyCode),
                PurchasePrice(src.PurchasePrice)
            {}

            ValidateAmazonReceiptRequest(const rapidjson::Value& obj) : ValidateAmazonReceiptRequest()
            {
                readFromValue(obj);
            }

            ~ValidateAmazonReceiptRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ReceiptId");
                writer.String(ReceiptId.c_str());
                writer.String("UserId");
                writer.String(UserId.c_str());
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                writer.String("CurrencyCode");
                writer.String(CurrencyCode.c_str());
                writer.String("PurchasePrice");
                writer.Int(PurchasePrice);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ReceiptId_member = obj.FindMember("ReceiptId");
                if (ReceiptId_member != obj.MemberEnd() && !ReceiptId_member->value.IsNull()) ReceiptId = ReceiptId_member->value.GetString();
                const Value::ConstMemberIterator UserId_member = obj.FindMember("UserId");
                if (UserId_member != obj.MemberEnd() && !UserId_member->value.IsNull()) UserId = UserId_member->value.GetString();
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator CurrencyCode_member = obj.FindMember("CurrencyCode");
                if (CurrencyCode_member != obj.MemberEnd() && !CurrencyCode_member->value.IsNull()) CurrencyCode = CurrencyCode_member->value.GetString();
                const Value::ConstMemberIterator PurchasePrice_member = obj.FindMember("PurchasePrice");
                if (PurchasePrice_member != obj.MemberEnd() && !PurchasePrice_member->value.IsNull()) PurchasePrice = PurchasePrice_member->value.GetInt();

                return true;
            }
        };

        struct ValidateAmazonReceiptResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ValidateAmazonReceiptResult,"{3f2ad80f-d9f6-5be0-ba0e-f16e8eae5feb}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            ValidateAmazonReceiptResult() :
                PlayFabBaseModel()
            {}

            ValidateAmazonReceiptResult(const ValidateAmazonReceiptResult& src) :
                PlayFabBaseModel()
            {}

            ValidateAmazonReceiptResult(const rapidjson::Value& obj) : ValidateAmazonReceiptResult()
            {
                readFromValue(obj);
            }

            ~ValidateAmazonReceiptResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct ValidateGooglePlayPurchaseRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ValidateGooglePlayPurchaseRequest,"{f4862742-7643-5154-bb80-68b8982e2d0d}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string ReceiptJson;
            AZStd::string Signature;
            AZStd::string CurrencyCode;
            OptionalUint32 PurchasePrice;

            ValidateGooglePlayPurchaseRequest() :
                PlayFabBaseModel(),
                ReceiptJson(),
                Signature(),
                CurrencyCode(),
                PurchasePrice()
            {}

            ValidateGooglePlayPurchaseRequest(const ValidateGooglePlayPurchaseRequest& src) :
                PlayFabBaseModel(),
                ReceiptJson(src.ReceiptJson),
                Signature(src.Signature),
                CurrencyCode(src.CurrencyCode),
                PurchasePrice(src.PurchasePrice)
            {}

            ValidateGooglePlayPurchaseRequest(const rapidjson::Value& obj) : ValidateGooglePlayPurchaseRequest()
            {
                readFromValue(obj);
            }

            ~ValidateGooglePlayPurchaseRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ReceiptJson");
                writer.String(ReceiptJson.c_str());
                writer.String("Signature");
                writer.String(Signature.c_str());
                if (CurrencyCode.length() > 0) {
                    writer.String("CurrencyCode");
                    writer.String(CurrencyCode.c_str());
                }
                if (PurchasePrice.notNull()) {
                    writer.String("PurchasePrice");
                    writer.Uint(PurchasePrice);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ReceiptJson_member = obj.FindMember("ReceiptJson");
                if (ReceiptJson_member != obj.MemberEnd() && !ReceiptJson_member->value.IsNull()) ReceiptJson = ReceiptJson_member->value.GetString();
                const Value::ConstMemberIterator Signature_member = obj.FindMember("Signature");
                if (Signature_member != obj.MemberEnd() && !Signature_member->value.IsNull()) Signature = Signature_member->value.GetString();
                const Value::ConstMemberIterator CurrencyCode_member = obj.FindMember("CurrencyCode");
                if (CurrencyCode_member != obj.MemberEnd() && !CurrencyCode_member->value.IsNull()) CurrencyCode = CurrencyCode_member->value.GetString();
                const Value::ConstMemberIterator PurchasePrice_member = obj.FindMember("PurchasePrice");
                if (PurchasePrice_member != obj.MemberEnd() && !PurchasePrice_member->value.IsNull()) PurchasePrice = PurchasePrice_member->value.GetUint();

                return true;
            }
        };

        struct ValidateGooglePlayPurchaseResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ValidateGooglePlayPurchaseResult,"{0439a622-9897-5432-b678-694b1eee489f}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            ValidateGooglePlayPurchaseResult() :
                PlayFabBaseModel()
            {}

            ValidateGooglePlayPurchaseResult(const ValidateGooglePlayPurchaseResult& src) :
                PlayFabBaseModel()
            {}

            ValidateGooglePlayPurchaseResult(const rapidjson::Value& obj) : ValidateGooglePlayPurchaseResult()
            {
                readFromValue(obj);
            }

            ~ValidateGooglePlayPurchaseResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct ValidateIOSReceiptRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ValidateIOSReceiptRequest,"{fd3890d4-c13b-56b5-bca9-f03f877b4cfd}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string ReceiptData;
            AZStd::string CurrencyCode;
            Int32 PurchasePrice;

            ValidateIOSReceiptRequest() :
                PlayFabBaseModel(),
                ReceiptData(),
                CurrencyCode(),
                PurchasePrice(0)
            {}

            ValidateIOSReceiptRequest(const ValidateIOSReceiptRequest& src) :
                PlayFabBaseModel(),
                ReceiptData(src.ReceiptData),
                CurrencyCode(src.CurrencyCode),
                PurchasePrice(src.PurchasePrice)
            {}

            ValidateIOSReceiptRequest(const rapidjson::Value& obj) : ValidateIOSReceiptRequest()
            {
                readFromValue(obj);
            }

            ~ValidateIOSReceiptRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ReceiptData");
                writer.String(ReceiptData.c_str());
                writer.String("CurrencyCode");
                writer.String(CurrencyCode.c_str());
                writer.String("PurchasePrice");
                writer.Int(PurchasePrice);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ReceiptData_member = obj.FindMember("ReceiptData");
                if (ReceiptData_member != obj.MemberEnd() && !ReceiptData_member->value.IsNull()) ReceiptData = ReceiptData_member->value.GetString();
                const Value::ConstMemberIterator CurrencyCode_member = obj.FindMember("CurrencyCode");
                if (CurrencyCode_member != obj.MemberEnd() && !CurrencyCode_member->value.IsNull()) CurrencyCode = CurrencyCode_member->value.GetString();
                const Value::ConstMemberIterator PurchasePrice_member = obj.FindMember("PurchasePrice");
                if (PurchasePrice_member != obj.MemberEnd() && !PurchasePrice_member->value.IsNull()) PurchasePrice = PurchasePrice_member->value.GetInt();

                return true;
            }
        };

        struct ValidateIOSReceiptResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ValidateIOSReceiptResult,"{816c2c4e-2161-5eba-841a-7efe89c404c2}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            ValidateIOSReceiptResult() :
                PlayFabBaseModel()
            {}

            ValidateIOSReceiptResult(const ValidateIOSReceiptResult& src) :
                PlayFabBaseModel()
            {}

            ValidateIOSReceiptResult(const rapidjson::Value& obj) : ValidateIOSReceiptResult()
            {
                readFromValue(obj);
            }

            ~ValidateIOSReceiptResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct ValidateWindowsReceiptRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ValidateWindowsReceiptRequest,"{d692a09a-a27f-569e-b486-5e086b4c4212}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string Receipt;
            AZStd::string CatalogVersion;
            AZStd::string CurrencyCode;
            Uint32 PurchasePrice;

            ValidateWindowsReceiptRequest() :
                PlayFabBaseModel(),
                Receipt(),
                CatalogVersion(),
                CurrencyCode(),
                PurchasePrice(0)
            {}

            ValidateWindowsReceiptRequest(const ValidateWindowsReceiptRequest& src) :
                PlayFabBaseModel(),
                Receipt(src.Receipt),
                CatalogVersion(src.CatalogVersion),
                CurrencyCode(src.CurrencyCode),
                PurchasePrice(src.PurchasePrice)
            {}

            ValidateWindowsReceiptRequest(const rapidjson::Value& obj) : ValidateWindowsReceiptRequest()
            {
                readFromValue(obj);
            }

            ~ValidateWindowsReceiptRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Receipt");
                writer.String(Receipt.c_str());
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                writer.String("CurrencyCode");
                writer.String(CurrencyCode.c_str());
                writer.String("PurchasePrice");
                writer.Uint(PurchasePrice);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Receipt_member = obj.FindMember("Receipt");
                if (Receipt_member != obj.MemberEnd() && !Receipt_member->value.IsNull()) Receipt = Receipt_member->value.GetString();
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator CurrencyCode_member = obj.FindMember("CurrencyCode");
                if (CurrencyCode_member != obj.MemberEnd() && !CurrencyCode_member->value.IsNull()) CurrencyCode = CurrencyCode_member->value.GetString();
                const Value::ConstMemberIterator PurchasePrice_member = obj.FindMember("PurchasePrice");
                if (PurchasePrice_member != obj.MemberEnd() && !PurchasePrice_member->value.IsNull()) PurchasePrice = PurchasePrice_member->value.GetUint();

                return true;
            }
        };

        struct ValidateWindowsReceiptResult : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::ValidateWindowsReceiptResult,"{d1bac065-5a39-5d4c-98a3-800a716eba5c}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)


            ValidateWindowsReceiptResult() :
                PlayFabBaseModel()
            {}

            ValidateWindowsReceiptResult(const ValidateWindowsReceiptResult& src) :
                PlayFabBaseModel()
            {}

            ValidateWindowsReceiptResult(const rapidjson::Value& obj) : ValidateWindowsReceiptResult()
            {
                readFromValue(obj);
            }

            ~ValidateWindowsReceiptResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {

                return true;
            }
        };

        struct WriteClientCharacterEventRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::WriteClientCharacterEventRequest,"{ae64fce5-1768-5f9e-9ab7-465f6545e17a}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string CharacterId;
            AZStd::string EventName;
            OptionalTime Timestamp;
            AZStd::unordered_map<AZStd::string, MultitypeVar> Body;

            WriteClientCharacterEventRequest() :
                PlayFabBaseModel(),
                CharacterId(),
                EventName(),
                Timestamp(),
                Body()
            {}

            WriteClientCharacterEventRequest(const WriteClientCharacterEventRequest& src) :
                PlayFabBaseModel(),
                CharacterId(src.CharacterId),
                EventName(src.EventName),
                Timestamp(src.Timestamp),
                Body(src.Body)
            {}

            WriteClientCharacterEventRequest(const rapidjson::Value& obj) : WriteClientCharacterEventRequest()
            {
                readFromValue(obj);
            }

            ~WriteClientCharacterEventRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("CharacterId");
                writer.String(CharacterId.c_str());
                writer.String("EventName");
                writer.String(EventName.c_str());
                if (Timestamp.notNull()) {
                    writer.String("Timestamp");
                    writeDatetime(Timestamp, writer);
                }
                if (!Body.empty()) {
                    writer.String("Body");
                    writer.StartObject();
                    for (auto iter = Body.begin(); iter != Body.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator EventName_member = obj.FindMember("EventName");
                if (EventName_member != obj.MemberEnd() && !EventName_member->value.IsNull()) EventName = EventName_member->value.GetString();
                const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
                if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
                const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
                if (Body_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Body_member->value.MemberBegin(); iter != Body_member->value.MemberEnd(); ++iter) {
                        Body[iter->name.GetString()] = MultitypeVar(iter->value);
                    }
                }

                return true;
            }
        };

        struct WriteClientPlayerEventRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::WriteClientPlayerEventRequest,"{d6393a4d-c1ab-526d-83b2-334d4dee9dad}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string EventName;
            OptionalTime Timestamp;
            AZStd::unordered_map<AZStd::string, MultitypeVar> Body;

            WriteClientPlayerEventRequest() :
                PlayFabBaseModel(),
                EventName(),
                Timestamp(),
                Body()
            {}

            WriteClientPlayerEventRequest(const WriteClientPlayerEventRequest& src) :
                PlayFabBaseModel(),
                EventName(src.EventName),
                Timestamp(src.Timestamp),
                Body(src.Body)
            {}

            WriteClientPlayerEventRequest(const rapidjson::Value& obj) : WriteClientPlayerEventRequest()
            {
                readFromValue(obj);
            }

            ~WriteClientPlayerEventRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("EventName");
                writer.String(EventName.c_str());
                if (Timestamp.notNull()) {
                    writer.String("Timestamp");
                    writeDatetime(Timestamp, writer);
                }
                if (!Body.empty()) {
                    writer.String("Body");
                    writer.StartObject();
                    for (auto iter = Body.begin(); iter != Body.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator EventName_member = obj.FindMember("EventName");
                if (EventName_member != obj.MemberEnd() && !EventName_member->value.IsNull()) EventName = EventName_member->value.GetString();
                const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
                if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
                const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
                if (Body_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Body_member->value.MemberBegin(); iter != Body_member->value.MemberEnd(); ++iter) {
                        Body[iter->name.GetString()] = MultitypeVar(iter->value);
                    }
                }

                return true;
            }
        };

        struct WriteEventResponse : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::WriteEventResponse,"{4e3c5939-1107-5d6d-99d3-dcbc3b66ed61}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string EventId;

            WriteEventResponse() :
                PlayFabBaseModel(),
                EventId()
            {}

            WriteEventResponse(const WriteEventResponse& src) :
                PlayFabBaseModel(),
                EventId(src.EventId)
            {}

            WriteEventResponse(const rapidjson::Value& obj) : WriteEventResponse()
            {
                readFromValue(obj);
            }

            ~WriteEventResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (EventId.length() > 0) {
                    writer.String("EventId");
                    writer.String(EventId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator EventId_member = obj.FindMember("EventId");
                if (EventId_member != obj.MemberEnd() && !EventId_member->value.IsNull()) EventId = EventId_member->value.GetString();

                return true;
            }
        };

        struct WriteTitleEventRequest : public PlayFabBaseModel
        {
		    
			AZ_TYPE_INFO(PlayFabComboSdk::ClientModels::WriteTitleEventRequest,"{f7c695b3-029e-5a2c-b4ec-cb8b6844840a}"); // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)

            AZStd::string EventName;
            OptionalTime Timestamp;
            AZStd::unordered_map<AZStd::string, MultitypeVar> Body;

            WriteTitleEventRequest() :
                PlayFabBaseModel(),
                EventName(),
                Timestamp(),
                Body()
            {}

            WriteTitleEventRequest(const WriteTitleEventRequest& src) :
                PlayFabBaseModel(),
                EventName(src.EventName),
                Timestamp(src.Timestamp),
                Body(src.Body)
            {}

            WriteTitleEventRequest(const rapidjson::Value& obj) : WriteTitleEventRequest()
            {
                readFromValue(obj);
            }

            ~WriteTitleEventRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("EventName");
                writer.String(EventName.c_str());
                if (Timestamp.notNull()) {
                    writer.String("Timestamp");
                    writeDatetime(Timestamp, writer);
                }
                if (!Body.empty()) {
                    writer.String("Body");
                    writer.StartObject();
                    for (auto iter = Body.begin(); iter != Body.end(); ++iter) { // #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11) - Change std::map to AZStd::AZStd::unordered_map because the latter supports reflection to behavior context in LY1.10+. 
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator EventName_member = obj.FindMember("EventName");
                if (EventName_member != obj.MemberEnd() && !EventName_member->value.IsNull()) EventName = EventName_member->value.GetString();
                const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
                if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
                const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
                if (Body_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Body_member->value.MemberBegin(); iter != Body_member->value.MemberEnd(); ++iter) {
                        Body[iter->name.GetString()] = MultitypeVar(iter->value);
                    }
                }

                return true;
            }
        };


    }
}


// #THIRD_KIND_PLAYFAB_BEHAVIOR_CONTEXT: dbowen (2017/08/11)
namespace AZ
{
    // Generate RTTI uuids for each enum type, these are needed to reflect any optional enums which are wrapped with Boxed<T>.
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<PlayFabComboSdk::ClientModels::TradeStatus>, "{6e474a93-5650-5715-82da-223c08587c51}");
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<PlayFabComboSdk::ClientModels::CloudScriptRevisionOption>, "{62edcc65-0425-5057-bf97-5ec2331bcab9}");
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<PlayFabComboSdk::ClientModels::ContinentCode>, "{bdbb7768-d70e-50b9-9e23-5a8781df3b37}");
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<PlayFabComboSdk::ClientModels::CountryCode>, "{f9895bee-5695-5c1b-be72-187b187aa865}");
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<PlayFabComboSdk::ClientModels::Currency>, "{af50876f-f6c2-5087-b1d0-29a811625014}");
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<PlayFabComboSdk::ClientModels::Region>, "{5f87a8df-963e-5a28-96e9-c919089ba063}");
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<PlayFabComboSdk::ClientModels::GameInstanceState>, "{63633531-a8c4-56d9-ab09-c435bcc9865b}");
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<PlayFabComboSdk::ClientModels::TitleActivationStatus>, "{00c1ad90-5a04-5aeb-8bac-1a3b7fa29ec1}");
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<PlayFabComboSdk::ClientModels::LoginIdentityProvider>, "{c5470981-5a0a-5471-8f9f-966e05be585b}");
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<PlayFabComboSdk::ClientModels::PushNotificationPlatform>, "{1e1c8b2b-5530-5704-ab3b-ef1cc7a5d551}");
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<PlayFabComboSdk::ClientModels::UserOrigination>, "{76ecf97f-402a-5633-a726-705aabdb17c6}");
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<PlayFabComboSdk::ClientModels::UserDataPermission>, "{5c9c5abf-f1fb-5320-ab24-3df756902b48}");
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<PlayFabComboSdk::ClientModels::SourceType>, "{d8b3fbd5-e9a1-58bb-ba83-b103f89fa632}");
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<PlayFabComboSdk::ClientModels::MatchmakeStatus>, "{0ba9165e-263a-5026-9275-9ed06bcd67f0}");
    AZ_TYPE_INFO_SPECIALIZE(PlayFabComboSdk::Boxed<PlayFabComboSdk::ClientModels::TransactionStatus>, "{8f4631e7-7af2-509d-ad72-79d8b65cf84c}");


}
// #THIRD_KIND_END

