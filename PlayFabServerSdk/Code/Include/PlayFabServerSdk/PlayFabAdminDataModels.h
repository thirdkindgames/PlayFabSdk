#pragma once

#include <PlayFabServerSdk/PlayFabBaseModel.h>
#include <aws/core/utils/json/JsonSerializer.h>

using namespace rapidjson;

namespace PlayFabServerSdk
{
    namespace AdminModels
    {
        struct AbortTaskInstanceRequest : public PlayFabBaseModel
        {
            AZStd::string TaskInstanceId;

            AbortTaskInstanceRequest() :
                PlayFabBaseModel(),
                TaskInstanceId()
            {}

            AbortTaskInstanceRequest(const AbortTaskInstanceRequest& src) :
                PlayFabBaseModel(),
                TaskInstanceId(src.TaskInstanceId)
            {}

            AbortTaskInstanceRequest(const rapidjson::Value& obj) : AbortTaskInstanceRequest()
            {
                readFromValue(obj);
            }

            ~AbortTaskInstanceRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("TaskInstanceId");
                writer.String(TaskInstanceId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TaskInstanceId_member = obj.FindMember("TaskInstanceId");
                if (TaskInstanceId_member != obj.MemberEnd() && !TaskInstanceId_member->value.IsNull()) TaskInstanceId = TaskInstanceId_member->value.GetString();

                return true;
            }
        };

        struct ActionsOnPlayersInSegmentTaskParameter : public PlayFabBaseModel
        {
            AZStd::string SegmentId;
            AZStd::string ActionId;

            ActionsOnPlayersInSegmentTaskParameter() :
                PlayFabBaseModel(),
                SegmentId(),
                ActionId()
            {}

            ActionsOnPlayersInSegmentTaskParameter(const ActionsOnPlayersInSegmentTaskParameter& src) :
                PlayFabBaseModel(),
                SegmentId(src.SegmentId),
                ActionId(src.ActionId)
            {}

            ActionsOnPlayersInSegmentTaskParameter(const rapidjson::Value& obj) : ActionsOnPlayersInSegmentTaskParameter()
            {
                readFromValue(obj);
            }

            ~ActionsOnPlayersInSegmentTaskParameter()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("SegmentId");
                writer.String(SegmentId.c_str());
                writer.String("ActionId");
                writer.String(ActionId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SegmentId_member = obj.FindMember("SegmentId");
                if (SegmentId_member != obj.MemberEnd() && !SegmentId_member->value.IsNull()) SegmentId = SegmentId_member->value.GetString();
                const Value::ConstMemberIterator ActionId_member = obj.FindMember("ActionId");
                if (ActionId_member != obj.MemberEnd() && !ActionId_member->value.IsNull()) ActionId = ActionId_member->value.GetString();

                return true;
            }
        };

        struct NameIdentifier : public PlayFabBaseModel
        {
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

        enum TaskInstanceStatus
        {
            TaskInstanceStatusSucceeded,
            TaskInstanceStatusStarting,
            TaskInstanceStatusInProgress,
            TaskInstanceStatusFailed,
            TaskInstanceStatusAborted,
            TaskInstanceStatusPending
        };

        inline void writeTaskInstanceStatusEnumJSON(TaskInstanceStatus enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case TaskInstanceStatusSucceeded: writer.String("Succeeded"); break;
            case TaskInstanceStatusStarting: writer.String("Starting"); break;
            case TaskInstanceStatusInProgress: writer.String("InProgress"); break;
            case TaskInstanceStatusFailed: writer.String("Failed"); break;
            case TaskInstanceStatusAborted: writer.String("Aborted"); break;
            case TaskInstanceStatusPending: writer.String("Pending"); break;

            }
        }

        inline TaskInstanceStatus readTaskInstanceStatusFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<TaskInstanceStatus>(obj.GetInt());

            static std::map<const char *, TaskInstanceStatus, PlayFabServerSdk::StringCompare> _TaskInstanceStatusMap;
            if (_TaskInstanceStatusMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _TaskInstanceStatusMap["Succeeded"] = TaskInstanceStatusSucceeded;
                _TaskInstanceStatusMap["Starting"] = TaskInstanceStatusStarting;
                _TaskInstanceStatusMap["InProgress"] = TaskInstanceStatusInProgress;
                _TaskInstanceStatusMap["Failed"] = TaskInstanceStatusFailed;
                _TaskInstanceStatusMap["Aborted"] = TaskInstanceStatusAborted;
                _TaskInstanceStatusMap["Pending"] = TaskInstanceStatusPending;

            }

            auto output = _TaskInstanceStatusMap.find(obj.GetString());
            if (output != _TaskInstanceStatusMap.end())
                return output->second;

            return TaskInstanceStatusSucceeded; // Basically critical fail
        }

        struct ActionsOnPlayersInSegmentTaskSummary : public PlayFabBaseModel
        {
            AZStd::string TaskInstanceId;
            NameIdentifier* TaskIdentifier;
            time_t StartedAt;
            OptionalTime CompletedAt;
            Boxed<TaskInstanceStatus> Status;
            OptionalDouble PercentComplete;
            OptionalDouble EstimatedSecondsRemaining;
            AZStd::string ScheduledByUserId;
            AZStd::string ErrorMessage;
            OptionalBool ErrorWasFatal;
            OptionalInt32 TotalPlayersInSegment;
            OptionalInt32 TotalPlayersProcessed;

            ActionsOnPlayersInSegmentTaskSummary() :
                PlayFabBaseModel(),
                TaskInstanceId(),
                TaskIdentifier(nullptr),
                StartedAt(0),
                CompletedAt(),
                Status(),
                PercentComplete(),
                EstimatedSecondsRemaining(),
                ScheduledByUserId(),
                ErrorMessage(),
                ErrorWasFatal(),
                TotalPlayersInSegment(),
                TotalPlayersProcessed()
            {}

            ActionsOnPlayersInSegmentTaskSummary(const ActionsOnPlayersInSegmentTaskSummary& src) :
                PlayFabBaseModel(),
                TaskInstanceId(src.TaskInstanceId),
                TaskIdentifier(src.TaskIdentifier ? new NameIdentifier(*src.TaskIdentifier) : nullptr),
                StartedAt(src.StartedAt),
                CompletedAt(src.CompletedAt),
                Status(src.Status),
                PercentComplete(src.PercentComplete),
                EstimatedSecondsRemaining(src.EstimatedSecondsRemaining),
                ScheduledByUserId(src.ScheduledByUserId),
                ErrorMessage(src.ErrorMessage),
                ErrorWasFatal(src.ErrorWasFatal),
                TotalPlayersInSegment(src.TotalPlayersInSegment),
                TotalPlayersProcessed(src.TotalPlayersProcessed)
            {}

            ActionsOnPlayersInSegmentTaskSummary(const rapidjson::Value& obj) : ActionsOnPlayersInSegmentTaskSummary()
            {
                readFromValue(obj);
            }

            ~ActionsOnPlayersInSegmentTaskSummary()
            {
                if (TaskIdentifier != nullptr) delete TaskIdentifier;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (TaskInstanceId.length() > 0) {
                    writer.String("TaskInstanceId");
                    writer.String(TaskInstanceId.c_str());
                }
                if (TaskIdentifier != nullptr) {
                    writer.String("TaskIdentifier");
                    TaskIdentifier->writeJSON(writer);
                }
                writer.String("StartedAt");
                writeDatetime(StartedAt, writer);
                if (CompletedAt.notNull()) {
                    writer.String("CompletedAt");
                    writeDatetime(CompletedAt, writer);
                }
                if (Status.notNull()) {
                    writer.String("Status");
                    writeTaskInstanceStatusEnumJSON(Status, writer);
                }
                if (PercentComplete.notNull()) {
                    writer.String("PercentComplete");
                    writer.Double(PercentComplete);
                }
                if (EstimatedSecondsRemaining.notNull()) {
                    writer.String("EstimatedSecondsRemaining");
                    writer.Double(EstimatedSecondsRemaining);
                }
                if (ScheduledByUserId.length() > 0) {
                    writer.String("ScheduledByUserId");
                    writer.String(ScheduledByUserId.c_str());
                }
                if (ErrorMessage.length() > 0) {
                    writer.String("ErrorMessage");
                    writer.String(ErrorMessage.c_str());
                }
                if (ErrorWasFatal.notNull()) {
                    writer.String("ErrorWasFatal");
                    writer.Bool(ErrorWasFatal);
                }
                if (TotalPlayersInSegment.notNull()) {
                    writer.String("TotalPlayersInSegment");
                    writer.Int(TotalPlayersInSegment);
                }
                if (TotalPlayersProcessed.notNull()) {
                    writer.String("TotalPlayersProcessed");
                    writer.Int(TotalPlayersProcessed);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TaskInstanceId_member = obj.FindMember("TaskInstanceId");
                if (TaskInstanceId_member != obj.MemberEnd() && !TaskInstanceId_member->value.IsNull()) TaskInstanceId = TaskInstanceId_member->value.GetString();
                const Value::ConstMemberIterator TaskIdentifier_member = obj.FindMember("TaskIdentifier");
                if (TaskIdentifier_member != obj.MemberEnd() && !TaskIdentifier_member->value.IsNull()) TaskIdentifier = new NameIdentifier(TaskIdentifier_member->value);
                const Value::ConstMemberIterator StartedAt_member = obj.FindMember("StartedAt");
                if (StartedAt_member != obj.MemberEnd() && !StartedAt_member->value.IsNull()) StartedAt = readDatetime(StartedAt_member->value);
                const Value::ConstMemberIterator CompletedAt_member = obj.FindMember("CompletedAt");
                if (CompletedAt_member != obj.MemberEnd() && !CompletedAt_member->value.IsNull()) CompletedAt = readDatetime(CompletedAt_member->value);
                const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
                if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readTaskInstanceStatusFromValue(Status_member->value);
                const Value::ConstMemberIterator PercentComplete_member = obj.FindMember("PercentComplete");
                if (PercentComplete_member != obj.MemberEnd() && !PercentComplete_member->value.IsNull()) PercentComplete = PercentComplete_member->value.GetDouble();
                const Value::ConstMemberIterator EstimatedSecondsRemaining_member = obj.FindMember("EstimatedSecondsRemaining");
                if (EstimatedSecondsRemaining_member != obj.MemberEnd() && !EstimatedSecondsRemaining_member->value.IsNull()) EstimatedSecondsRemaining = EstimatedSecondsRemaining_member->value.GetDouble();
                const Value::ConstMemberIterator ScheduledByUserId_member = obj.FindMember("ScheduledByUserId");
                if (ScheduledByUserId_member != obj.MemberEnd() && !ScheduledByUserId_member->value.IsNull()) ScheduledByUserId = ScheduledByUserId_member->value.GetString();
                const Value::ConstMemberIterator ErrorMessage_member = obj.FindMember("ErrorMessage");
                if (ErrorMessage_member != obj.MemberEnd() && !ErrorMessage_member->value.IsNull()) ErrorMessage = ErrorMessage_member->value.GetString();
                const Value::ConstMemberIterator ErrorWasFatal_member = obj.FindMember("ErrorWasFatal");
                if (ErrorWasFatal_member != obj.MemberEnd() && !ErrorWasFatal_member->value.IsNull()) ErrorWasFatal = ErrorWasFatal_member->value.GetBool();
                const Value::ConstMemberIterator TotalPlayersInSegment_member = obj.FindMember("TotalPlayersInSegment");
                if (TotalPlayersInSegment_member != obj.MemberEnd() && !TotalPlayersInSegment_member->value.IsNull()) TotalPlayersInSegment = TotalPlayersInSegment_member->value.GetInt();
                const Value::ConstMemberIterator TotalPlayersProcessed_member = obj.FindMember("TotalPlayersProcessed");
                if (TotalPlayersProcessed_member != obj.MemberEnd() && !TotalPlayersProcessed_member->value.IsNull()) TotalPlayersProcessed = TotalPlayersProcessed_member->value.GetInt();

                return true;
            }
        };

        struct AdCampaignAttribution : public PlayFabBaseModel
        {
            AZStd::string Platform;
            AZStd::string CampaignId;
            time_t AttributedAt;

            AdCampaignAttribution() :
                PlayFabBaseModel(),
                Platform(),
                CampaignId(),
                AttributedAt(0)
            {}

            AdCampaignAttribution(const AdCampaignAttribution& src) :
                PlayFabBaseModel(),
                Platform(src.Platform),
                CampaignId(src.CampaignId),
                AttributedAt(src.AttributedAt)
            {}

            AdCampaignAttribution(const rapidjson::Value& obj) : AdCampaignAttribution()
            {
                readFromValue(obj);
            }

            ~AdCampaignAttribution()
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

        struct AddNewsRequest : public PlayFabBaseModel
        {
            OptionalTime Timestamp;
            AZStd::string Title;
            AZStd::string Body;

            AddNewsRequest() :
                PlayFabBaseModel(),
                Timestamp(),
                Title(),
                Body()
            {}

            AddNewsRequest(const AddNewsRequest& src) :
                PlayFabBaseModel(),
                Timestamp(src.Timestamp),
                Title(src.Title),
                Body(src.Body)
            {}

            AddNewsRequest(const rapidjson::Value& obj) : AddNewsRequest()
            {
                readFromValue(obj);
            }

            ~AddNewsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Timestamp.notNull()) {
                    writer.String("Timestamp");
                    writeDatetime(Timestamp, writer);
                }
                writer.String("Title");
                writer.String(Title.c_str());
                writer.String("Body");
                writer.String(Body.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
                if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
                const Value::ConstMemberIterator Title_member = obj.FindMember("Title");
                if (Title_member != obj.MemberEnd() && !Title_member->value.IsNull()) Title = Title_member->value.GetString();
                const Value::ConstMemberIterator Body_member = obj.FindMember("Body");
                if (Body_member != obj.MemberEnd() && !Body_member->value.IsNull()) Body = Body_member->value.GetString();

                return true;
            }
        };

        struct AddNewsResult : public PlayFabBaseModel
        {
            AZStd::string NewsId;

            AddNewsResult() :
                PlayFabBaseModel(),
                NewsId()
            {}

            AddNewsResult(const AddNewsResult& src) :
                PlayFabBaseModel(),
                NewsId(src.NewsId)
            {}

            AddNewsResult(const rapidjson::Value& obj) : AddNewsResult()
            {
                readFromValue(obj);
            }

            ~AddNewsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (NewsId.length() > 0) {
                    writer.String("NewsId");
                    writer.String(NewsId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator NewsId_member = obj.FindMember("NewsId");
                if (NewsId_member != obj.MemberEnd() && !NewsId_member->value.IsNull()) NewsId = NewsId_member->value.GetString();

                return true;
            }
        };

        struct AddPlayerTagRequest : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            AZStd::string TagName;

            AddPlayerTagRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                TagName()
            {}

            AddPlayerTagRequest(const AddPlayerTagRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                TagName(src.TagName)
            {}

            AddPlayerTagRequest(const rapidjson::Value& obj) : AddPlayerTagRequest()
            {
                readFromValue(obj);
            }

            ~AddPlayerTagRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                writer.String("TagName");
                writer.String(TagName.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator TagName_member = obj.FindMember("TagName");
                if (TagName_member != obj.MemberEnd() && !TagName_member->value.IsNull()) TagName = TagName_member->value.GetString();

                return true;
            }
        };

        struct AddPlayerTagResult : public PlayFabBaseModel
        {

            AddPlayerTagResult() :
                PlayFabBaseModel()
            {}

            AddPlayerTagResult(const AddPlayerTagResult& src) :
                PlayFabBaseModel()
            {}

            AddPlayerTagResult(const rapidjson::Value& obj) : AddPlayerTagResult()
            {
                readFromValue(obj);
            }

            ~AddPlayerTagResult()
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

            static std::map<const char *, Region, PlayFabServerSdk::StringCompare> _RegionMap;
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

        struct AddServerBuildRequest : public PlayFabBaseModel
        {
            AZStd::string BuildId;
            AZStd::string CommandLineTemplate;
            AZStd::string ExecutablePath;
            std::list<Region> ActiveRegions;
            AZStd::string Comment;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;

            AddServerBuildRequest() :
                PlayFabBaseModel(),
                BuildId(),
                CommandLineTemplate(),
                ExecutablePath(),
                ActiveRegions(),
                Comment(),
                MaxGamesPerHost(0),
                MinFreeGameSlots(0)
            {}

            AddServerBuildRequest(const AddServerBuildRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                CommandLineTemplate(src.CommandLineTemplate),
                ExecutablePath(src.ExecutablePath),
                ActiveRegions(src.ActiveRegions),
                Comment(src.Comment),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots)
            {}

            AddServerBuildRequest(const rapidjson::Value& obj) : AddServerBuildRequest()
            {
                readFromValue(obj);
            }

            ~AddServerBuildRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("BuildId");
                writer.String(BuildId.c_str());
                if (CommandLineTemplate.length() > 0) {
                    writer.String("CommandLineTemplate");
                    writer.String(CommandLineTemplate.c_str());
                }
                if (ExecutablePath.length() > 0) {
                    writer.String("ExecutablePath");
                    writer.String(ExecutablePath.c_str());
                }
                if (!ActiveRegions.empty()) {
                    writer.String("ActiveRegions");
                    writer.StartArray();
                    for (std::list<Region>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
                        writeRegionEnumJSON(*iter, writer);
                    }
                    writer.EndArray();
                }
                if (Comment.length() > 0) {
                    writer.String("Comment");
                    writer.String(Comment.c_str());
                }
                writer.String("MaxGamesPerHost");
                writer.Int(MaxGamesPerHost);
                writer.String("MinFreeGameSlots");
                writer.Int(MinFreeGameSlots);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
                if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
                const Value::ConstMemberIterator CommandLineTemplate_member = obj.FindMember("CommandLineTemplate");
                if (CommandLineTemplate_member != obj.MemberEnd() && !CommandLineTemplate_member->value.IsNull()) CommandLineTemplate = CommandLineTemplate_member->value.GetString();
                const Value::ConstMemberIterator ExecutablePath_member = obj.FindMember("ExecutablePath");
                if (ExecutablePath_member != obj.MemberEnd() && !ExecutablePath_member->value.IsNull()) ExecutablePath = ExecutablePath_member->value.GetString();
                const Value::ConstMemberIterator ActiveRegions_member = obj.FindMember("ActiveRegions");
                if (ActiveRegions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = ActiveRegions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        ActiveRegions.push_back(readRegionFromValue(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
                if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
                const Value::ConstMemberIterator MaxGamesPerHost_member = obj.FindMember("MaxGamesPerHost");
                if (MaxGamesPerHost_member != obj.MemberEnd() && !MaxGamesPerHost_member->value.IsNull()) MaxGamesPerHost = MaxGamesPerHost_member->value.GetInt();
                const Value::ConstMemberIterator MinFreeGameSlots_member = obj.FindMember("MinFreeGameSlots");
                if (MinFreeGameSlots_member != obj.MemberEnd() && !MinFreeGameSlots_member->value.IsNull()) MinFreeGameSlots = MinFreeGameSlots_member->value.GetInt();

                return true;
            }
        };

        enum GameBuildStatus
        {
            GameBuildStatusAvailable,
            GameBuildStatusValidating,
            GameBuildStatusInvalidBuildPackage,
            GameBuildStatusProcessing,
            GameBuildStatusFailedToProcess
        };

        inline void writeGameBuildStatusEnumJSON(GameBuildStatus enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case GameBuildStatusAvailable: writer.String("Available"); break;
            case GameBuildStatusValidating: writer.String("Validating"); break;
            case GameBuildStatusInvalidBuildPackage: writer.String("InvalidBuildPackage"); break;
            case GameBuildStatusProcessing: writer.String("Processing"); break;
            case GameBuildStatusFailedToProcess: writer.String("FailedToProcess"); break;

            }
        }

        inline GameBuildStatus readGameBuildStatusFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<GameBuildStatus>(obj.GetInt());

            static std::map<const char *, GameBuildStatus, PlayFabServerSdk::StringCompare> _GameBuildStatusMap;
            if (_GameBuildStatusMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _GameBuildStatusMap["Available"] = GameBuildStatusAvailable;
                _GameBuildStatusMap["Validating"] = GameBuildStatusValidating;
                _GameBuildStatusMap["InvalidBuildPackage"] = GameBuildStatusInvalidBuildPackage;
                _GameBuildStatusMap["Processing"] = GameBuildStatusProcessing;
                _GameBuildStatusMap["FailedToProcess"] = GameBuildStatusFailedToProcess;

            }

            auto output = _GameBuildStatusMap.find(obj.GetString());
            if (output != _GameBuildStatusMap.end())
                return output->second;

            return GameBuildStatusAvailable; // Basically critical fail
        }

        struct AddServerBuildResult : public PlayFabBaseModel
        {
            AZStd::string BuildId;
            std::list<Region> ActiveRegions;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            AZStd::string CommandLineTemplate;
            AZStd::string ExecutablePath;
            AZStd::string Comment;
            time_t Timestamp;
            AZStd::string TitleId;
            Boxed<GameBuildStatus> Status;

            AddServerBuildResult() :
                PlayFabBaseModel(),
                BuildId(),
                ActiveRegions(),
                MaxGamesPerHost(0),
                MinFreeGameSlots(0),
                CommandLineTemplate(),
                ExecutablePath(),
                Comment(),
                Timestamp(0),
                TitleId(),
                Status()
            {}

            AddServerBuildResult(const AddServerBuildResult& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                ActiveRegions(src.ActiveRegions),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                CommandLineTemplate(src.CommandLineTemplate),
                ExecutablePath(src.ExecutablePath),
                Comment(src.Comment),
                Timestamp(src.Timestamp),
                TitleId(src.TitleId),
                Status(src.Status)
            {}

            AddServerBuildResult(const rapidjson::Value& obj) : AddServerBuildResult()
            {
                readFromValue(obj);
            }

            ~AddServerBuildResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (BuildId.length() > 0) {
                    writer.String("BuildId");
                    writer.String(BuildId.c_str());
                }
                if (!ActiveRegions.empty()) {
                    writer.String("ActiveRegions");
                    writer.StartArray();
                    for (std::list<Region>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
                        writeRegionEnumJSON(*iter, writer);
                    }
                    writer.EndArray();
                }
                writer.String("MaxGamesPerHost");
                writer.Int(MaxGamesPerHost);
                writer.String("MinFreeGameSlots");
                writer.Int(MinFreeGameSlots);
                if (CommandLineTemplate.length() > 0) {
                    writer.String("CommandLineTemplate");
                    writer.String(CommandLineTemplate.c_str());
                }
                if (ExecutablePath.length() > 0) {
                    writer.String("ExecutablePath");
                    writer.String(ExecutablePath.c_str());
                }
                if (Comment.length() > 0) {
                    writer.String("Comment");
                    writer.String(Comment.c_str());
                }
                writer.String("Timestamp");
                writeDatetime(Timestamp, writer);
                if (TitleId.length() > 0) {
                    writer.String("TitleId");
                    writer.String(TitleId.c_str());
                }
                if (Status.notNull()) {
                    writer.String("Status");
                    writeGameBuildStatusEnumJSON(Status, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
                if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
                const Value::ConstMemberIterator ActiveRegions_member = obj.FindMember("ActiveRegions");
                if (ActiveRegions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = ActiveRegions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        ActiveRegions.push_back(readRegionFromValue(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator MaxGamesPerHost_member = obj.FindMember("MaxGamesPerHost");
                if (MaxGamesPerHost_member != obj.MemberEnd() && !MaxGamesPerHost_member->value.IsNull()) MaxGamesPerHost = MaxGamesPerHost_member->value.GetInt();
                const Value::ConstMemberIterator MinFreeGameSlots_member = obj.FindMember("MinFreeGameSlots");
                if (MinFreeGameSlots_member != obj.MemberEnd() && !MinFreeGameSlots_member->value.IsNull()) MinFreeGameSlots = MinFreeGameSlots_member->value.GetInt();
                const Value::ConstMemberIterator CommandLineTemplate_member = obj.FindMember("CommandLineTemplate");
                if (CommandLineTemplate_member != obj.MemberEnd() && !CommandLineTemplate_member->value.IsNull()) CommandLineTemplate = CommandLineTemplate_member->value.GetString();
                const Value::ConstMemberIterator ExecutablePath_member = obj.FindMember("ExecutablePath");
                if (ExecutablePath_member != obj.MemberEnd() && !ExecutablePath_member->value.IsNull()) ExecutablePath = ExecutablePath_member->value.GetString();
                const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
                if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
                const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
                if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
                if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readGameBuildStatusFromValue(Status_member->value);

                return true;
            }
        };

        struct AddUserVirtualCurrencyRequest : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            AZStd::string VirtualCurrency;
            Int32 Amount;

            AddUserVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                VirtualCurrency(),
                Amount(0)
            {}

            AddUserVirtualCurrencyRequest(const AddUserVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
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
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                writer.String("VirtualCurrency");
                writer.String(VirtualCurrency.c_str());
                writer.String("Amount");
                writer.Int(Amount);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
                const Value::ConstMemberIterator Amount_member = obj.FindMember("Amount");
                if (Amount_member != obj.MemberEnd() && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();

                return true;
            }
        };

        struct VirtualCurrencyData : public PlayFabBaseModel
        {
            AZStd::string CurrencyCode;
            AZStd::string DisplayName;
            OptionalInt32 InitialDeposit;
            OptionalInt32 RechargeRate;
            OptionalInt32 RechargeMax;

            VirtualCurrencyData() :
                PlayFabBaseModel(),
                CurrencyCode(),
                DisplayName(),
                InitialDeposit(),
                RechargeRate(),
                RechargeMax()
            {}

            VirtualCurrencyData(const VirtualCurrencyData& src) :
                PlayFabBaseModel(),
                CurrencyCode(src.CurrencyCode),
                DisplayName(src.DisplayName),
                InitialDeposit(src.InitialDeposit),
                RechargeRate(src.RechargeRate),
                RechargeMax(src.RechargeMax)
            {}

            VirtualCurrencyData(const rapidjson::Value& obj) : VirtualCurrencyData()
            {
                readFromValue(obj);
            }

            ~VirtualCurrencyData()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("CurrencyCode");
                writer.String(CurrencyCode.c_str());
                if (DisplayName.length() > 0) {
                    writer.String("DisplayName");
                    writer.String(DisplayName.c_str());
                }
                if (InitialDeposit.notNull()) {
                    writer.String("InitialDeposit");
                    writer.Int(InitialDeposit);
                }
                if (RechargeRate.notNull()) {
                    writer.String("RechargeRate");
                    writer.Int(RechargeRate);
                }
                if (RechargeMax.notNull()) {
                    writer.String("RechargeMax");
                    writer.Int(RechargeMax);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CurrencyCode_member = obj.FindMember("CurrencyCode");
                if (CurrencyCode_member != obj.MemberEnd() && !CurrencyCode_member->value.IsNull()) CurrencyCode = CurrencyCode_member->value.GetString();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator InitialDeposit_member = obj.FindMember("InitialDeposit");
                if (InitialDeposit_member != obj.MemberEnd() && !InitialDeposit_member->value.IsNull()) InitialDeposit = InitialDeposit_member->value.GetInt();
                const Value::ConstMemberIterator RechargeRate_member = obj.FindMember("RechargeRate");
                if (RechargeRate_member != obj.MemberEnd() && !RechargeRate_member->value.IsNull()) RechargeRate = RechargeRate_member->value.GetInt();
                const Value::ConstMemberIterator RechargeMax_member = obj.FindMember("RechargeMax");
                if (RechargeMax_member != obj.MemberEnd() && !RechargeMax_member->value.IsNull()) RechargeMax = RechargeMax_member->value.GetInt();

                return true;
            }
        };

        struct AddVirtualCurrencyTypesRequest : public PlayFabBaseModel
        {
            std::list<VirtualCurrencyData> VirtualCurrencies;

            AddVirtualCurrencyTypesRequest() :
                PlayFabBaseModel(),
                VirtualCurrencies()
            {}

            AddVirtualCurrencyTypesRequest(const AddVirtualCurrencyTypesRequest& src) :
                PlayFabBaseModel(),
                VirtualCurrencies(src.VirtualCurrencies)
            {}

            AddVirtualCurrencyTypesRequest(const rapidjson::Value& obj) : AddVirtualCurrencyTypesRequest()
            {
                readFromValue(obj);
            }

            ~AddVirtualCurrencyTypesRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("VirtualCurrencies");
                writer.StartArray();
                for (std::list<VirtualCurrencyData>::iterator iter = VirtualCurrencies.begin(); iter != VirtualCurrencies.end(); iter++) {
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator VirtualCurrencies_member = obj.FindMember("VirtualCurrencies");
                if (VirtualCurrencies_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = VirtualCurrencies_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        VirtualCurrencies.push_back(VirtualCurrencyData(memberList[i]));
                    }
                }

                return true;
            }
        };

        enum Conditionals
        {
            ConditionalsAny,
            ConditionalsTrue,
            ConditionalsFalse
        };

        inline void writeConditionalsEnumJSON(Conditionals enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case ConditionalsAny: writer.String("Any"); break;
            case ConditionalsTrue: writer.String("True"); break;
            case ConditionalsFalse: writer.String("False"); break;

            }
        }

        inline Conditionals readConditionalsFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<Conditionals>(obj.GetInt());

            static std::map<const char *, Conditionals, PlayFabServerSdk::StringCompare> _ConditionalsMap;
            if (_ConditionalsMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _ConditionalsMap["Any"] = ConditionalsAny;
                _ConditionalsMap["True"] = ConditionalsTrue;
                _ConditionalsMap["False"] = ConditionalsFalse;

            }

            auto output = _ConditionalsMap.find(obj.GetString());
            if (output != _ConditionalsMap.end())
                return output->second;

            return ConditionalsAny; // Basically critical fail
        }

        struct ApiCondition : public PlayFabBaseModel
        {
            Boxed<Conditionals> HasSignatureOrEncryption;

            ApiCondition() :
                PlayFabBaseModel(),
                HasSignatureOrEncryption()
            {}

            ApiCondition(const ApiCondition& src) :
                PlayFabBaseModel(),
                HasSignatureOrEncryption(src.HasSignatureOrEncryption)
            {}

            ApiCondition(const rapidjson::Value& obj) : ApiCondition()
            {
                readFromValue(obj);
            }

            ~ApiCondition()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (HasSignatureOrEncryption.notNull()) {
                    writer.String("HasSignatureOrEncryption");
                    writeConditionalsEnumJSON(HasSignatureOrEncryption, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator HasSignatureOrEncryption_member = obj.FindMember("HasSignatureOrEncryption");
                if (HasSignatureOrEncryption_member != obj.MemberEnd() && !HasSignatureOrEncryption_member->value.IsNull()) HasSignatureOrEncryption = readConditionalsFromValue(HasSignatureOrEncryption_member->value);

                return true;
            }
        };

        struct BanInfo : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            AZStd::string BanId;
            AZStd::string IPAddress;
            AZStd::string MACAddress;
            OptionalTime Created;
            OptionalTime Expires;
            AZStd::string Reason;
            bool Active;

            BanInfo() :
                PlayFabBaseModel(),
                PlayFabId(),
                BanId(),
                IPAddress(),
                MACAddress(),
                Created(),
                Expires(),
                Reason(),
                Active(false)
            {}

            BanInfo(const BanInfo& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                BanId(src.BanId),
                IPAddress(src.IPAddress),
                MACAddress(src.MACAddress),
                Created(src.Created),
                Expires(src.Expires),
                Reason(src.Reason),
                Active(src.Active)
            {}

            BanInfo(const rapidjson::Value& obj) : BanInfo()
            {
                readFromValue(obj);
            }

            ~BanInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                if (BanId.length() > 0) {
                    writer.String("BanId");
                    writer.String(BanId.c_str());
                }
                if (IPAddress.length() > 0) {
                    writer.String("IPAddress");
                    writer.String(IPAddress.c_str());
                }
                if (MACAddress.length() > 0) {
                    writer.String("MACAddress");
                    writer.String(MACAddress.c_str());
                }
                if (Created.notNull()) {
                    writer.String("Created");
                    writeDatetime(Created, writer);
                }
                if (Expires.notNull()) {
                    writer.String("Expires");
                    writeDatetime(Expires, writer);
                }
                if (Reason.length() > 0) {
                    writer.String("Reason");
                    writer.String(Reason.c_str());
                }
                writer.String("Active");
                writer.Bool(Active);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator BanId_member = obj.FindMember("BanId");
                if (BanId_member != obj.MemberEnd() && !BanId_member->value.IsNull()) BanId = BanId_member->value.GetString();
                const Value::ConstMemberIterator IPAddress_member = obj.FindMember("IPAddress");
                if (IPAddress_member != obj.MemberEnd() && !IPAddress_member->value.IsNull()) IPAddress = IPAddress_member->value.GetString();
                const Value::ConstMemberIterator MACAddress_member = obj.FindMember("MACAddress");
                if (MACAddress_member != obj.MemberEnd() && !MACAddress_member->value.IsNull()) MACAddress = MACAddress_member->value.GetString();
                const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
                if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
                const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
                if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = readDatetime(Expires_member->value);
                const Value::ConstMemberIterator Reason_member = obj.FindMember("Reason");
                if (Reason_member != obj.MemberEnd() && !Reason_member->value.IsNull()) Reason = Reason_member->value.GetString();
                const Value::ConstMemberIterator Active_member = obj.FindMember("Active");
                if (Active_member != obj.MemberEnd() && !Active_member->value.IsNull()) Active = Active_member->value.GetBool();

                return true;
            }
        };

        struct BanRequest : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            AZStd::string IPAddress;
            AZStd::string MACAddress;
            AZStd::string Reason;
            OptionalUint32 DurationInHours;

            BanRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                IPAddress(),
                MACAddress(),
                Reason(),
                DurationInHours()
            {}

            BanRequest(const BanRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                IPAddress(src.IPAddress),
                MACAddress(src.MACAddress),
                Reason(src.Reason),
                DurationInHours(src.DurationInHours)
            {}

            BanRequest(const rapidjson::Value& obj) : BanRequest()
            {
                readFromValue(obj);
            }

            ~BanRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                if (IPAddress.length() > 0) {
                    writer.String("IPAddress");
                    writer.String(IPAddress.c_str());
                }
                if (MACAddress.length() > 0) {
                    writer.String("MACAddress");
                    writer.String(MACAddress.c_str());
                }
                if (Reason.length() > 0) {
                    writer.String("Reason");
                    writer.String(Reason.c_str());
                }
                if (DurationInHours.notNull()) {
                    writer.String("DurationInHours");
                    writer.Uint(DurationInHours);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator IPAddress_member = obj.FindMember("IPAddress");
                if (IPAddress_member != obj.MemberEnd() && !IPAddress_member->value.IsNull()) IPAddress = IPAddress_member->value.GetString();
                const Value::ConstMemberIterator MACAddress_member = obj.FindMember("MACAddress");
                if (MACAddress_member != obj.MemberEnd() && !MACAddress_member->value.IsNull()) MACAddress = MACAddress_member->value.GetString();
                const Value::ConstMemberIterator Reason_member = obj.FindMember("Reason");
                if (Reason_member != obj.MemberEnd() && !Reason_member->value.IsNull()) Reason = Reason_member->value.GetString();
                const Value::ConstMemberIterator DurationInHours_member = obj.FindMember("DurationInHours");
                if (DurationInHours_member != obj.MemberEnd() && !DurationInHours_member->value.IsNull()) DurationInHours = DurationInHours_member->value.GetUint();

                return true;
            }
        };

        struct BanUsersRequest : public PlayFabBaseModel
        {
            std::list<BanRequest> Bans;

            BanUsersRequest() :
                PlayFabBaseModel(),
                Bans()
            {}

            BanUsersRequest(const BanUsersRequest& src) :
                PlayFabBaseModel(),
                Bans(src.Bans)
            {}

            BanUsersRequest(const rapidjson::Value& obj) : BanUsersRequest()
            {
                readFromValue(obj);
            }

            ~BanUsersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Bans");
                writer.StartArray();
                for (std::list<BanRequest>::iterator iter = Bans.begin(); iter != Bans.end(); iter++) {
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Bans_member = obj.FindMember("Bans");
                if (Bans_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Bans_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Bans.push_back(BanRequest(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct BanUsersResult : public PlayFabBaseModel
        {
            std::list<BanInfo> BanData;

            BanUsersResult() :
                PlayFabBaseModel(),
                BanData()
            {}

            BanUsersResult(const BanUsersResult& src) :
                PlayFabBaseModel(),
                BanData(src.BanData)
            {}

            BanUsersResult(const rapidjson::Value& obj) : BanUsersResult()
            {
                readFromValue(obj);
            }

            ~BanUsersResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!BanData.empty()) {
                    writer.String("BanData");
                    writer.StartArray();
                    for (std::list<BanInfo>::iterator iter = BanData.begin(); iter != BanData.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BanData_member = obj.FindMember("BanData");
                if (BanData_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = BanData_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        BanData.push_back(BanInfo(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct BlankResult : public PlayFabBaseModel
        {

            BlankResult() :
                PlayFabBaseModel()
            {}

            BlankResult(const BlankResult& src) :
                PlayFabBaseModel()
            {}

            BlankResult(const rapidjson::Value& obj) : BlankResult()
            {
                readFromValue(obj);
            }

            ~BlankResult()
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

        struct CatalogItemConsumableInfo : public PlayFabBaseModel
        {
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
            AZStd::string KeyItemId;
            std::list<AZStd::string> ItemContents;
            std::list<AZStd::string> ResultTableContents;
            std::map<AZStd::string, Uint32> VirtualCurrencyContents;

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
                    for (std::list<AZStd::string>::iterator iter = ItemContents.begin(); iter != ItemContents.end(); iter++) {
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!ResultTableContents.empty()) {
                    writer.String("ResultTableContents");
                    writer.StartArray();
                    for (std::list<AZStd::string>::iterator iter = ResultTableContents.begin(); iter != ResultTableContents.end(); iter++) {
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!VirtualCurrencyContents.empty()) {
                    writer.String("VirtualCurrencyContents");
                    writer.StartObject();
                    for (std::map<AZStd::string, Uint32>::iterator iter = VirtualCurrencyContents.begin(); iter != VirtualCurrencyContents.end(); ++iter) {
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
            std::list<AZStd::string> BundledItems;
            std::list<AZStd::string> BundledResultTables;
            std::map<AZStd::string, Uint32> BundledVirtualCurrencies;

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
                    for (std::list<AZStd::string>::iterator iter = BundledItems.begin(); iter != BundledItems.end(); iter++) {
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!BundledResultTables.empty()) {
                    writer.String("BundledResultTables");
                    writer.StartArray();
                    for (std::list<AZStd::string>::iterator iter = BundledResultTables.begin(); iter != BundledResultTables.end(); iter++) {
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!BundledVirtualCurrencies.empty()) {
                    writer.String("BundledVirtualCurrencies");
                    writer.StartObject();
                    for (std::map<AZStd::string, Uint32>::iterator iter = BundledVirtualCurrencies.begin(); iter != BundledVirtualCurrencies.end(); ++iter) {
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
            AZStd::string ItemId;
            AZStd::string ItemClass;
            AZStd::string CatalogVersion;
            AZStd::string DisplayName;
            AZStd::string Description;
            std::map<AZStd::string, Uint32> VirtualCurrencyPrices;
            std::map<AZStd::string, Uint32> RealCurrencyPrices;
            std::list<AZStd::string> Tags;
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
                    for (std::map<AZStd::string, Uint32>::iterator iter = VirtualCurrencyPrices.begin(); iter != VirtualCurrencyPrices.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                if (!RealCurrencyPrices.empty()) {
                    writer.String("RealCurrencyPrices");
                    writer.StartObject();
                    for (std::map<AZStd::string, Uint32>::iterator iter = RealCurrencyPrices.begin(); iter != RealCurrencyPrices.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                if (!Tags.empty()) {
                    writer.String("Tags");
                    writer.StartArray();
                    for (std::list<AZStd::string>::iterator iter = Tags.begin(); iter != Tags.end(); iter++) {
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

        struct CloudScriptFile : public PlayFabBaseModel
        {
            AZStd::string Filename;
            AZStd::string FileContents;

            CloudScriptFile() :
                PlayFabBaseModel(),
                Filename(),
                FileContents()
            {}

            CloudScriptFile(const CloudScriptFile& src) :
                PlayFabBaseModel(),
                Filename(src.Filename),
                FileContents(src.FileContents)
            {}

            CloudScriptFile(const rapidjson::Value& obj) : CloudScriptFile()
            {
                readFromValue(obj);
            }

            ~CloudScriptFile()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Filename");
                writer.String(Filename.c_str());
                writer.String("FileContents");
                writer.String(FileContents.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Filename_member = obj.FindMember("Filename");
                if (Filename_member != obj.MemberEnd() && !Filename_member->value.IsNull()) Filename = Filename_member->value.GetString();
                const Value::ConstMemberIterator FileContents_member = obj.FindMember("FileContents");
                if (FileContents_member != obj.MemberEnd() && !FileContents_member->value.IsNull()) FileContents = FileContents_member->value.GetString();

                return true;
            }
        };

        struct CloudScriptTaskParameter : public PlayFabBaseModel
        {
            AZStd::string FunctionName;
            MultitypeVar Argument;

            CloudScriptTaskParameter() :
                PlayFabBaseModel(),
                FunctionName(),
                Argument()
            {}

            CloudScriptTaskParameter(const CloudScriptTaskParameter& src) :
                PlayFabBaseModel(),
                FunctionName(src.FunctionName),
                Argument(src.Argument)
            {}

            CloudScriptTaskParameter(const rapidjson::Value& obj) : CloudScriptTaskParameter()
            {
                readFromValue(obj);
            }

            ~CloudScriptTaskParameter()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (FunctionName.length() > 0) {
                    writer.String("FunctionName");
                    writer.String(FunctionName.c_str());
                }
                if (Argument.notNull()) {
                    writer.String("Argument");
                    Argument.writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FunctionName_member = obj.FindMember("FunctionName");
                if (FunctionName_member != obj.MemberEnd() && !FunctionName_member->value.IsNull()) FunctionName = FunctionName_member->value.GetString();
                const Value::ConstMemberIterator Argument_member = obj.FindMember("Argument");
                if (Argument_member != obj.MemberEnd() && !Argument_member->value.IsNull()) Argument = MultitypeVar(Argument_member->value);

                return true;
            }
        };

        struct LogStatement : public PlayFabBaseModel
        {
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
            AZStd::string FunctionName;
            Int32 Revision;
            MultitypeVar FunctionResult;
            OptionalBool FunctionResultTooLarge;
            std::list<LogStatement> Logs;
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
                    for (std::list<LogStatement>::iterator iter = Logs.begin(); iter != Logs.end(); iter++) {
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

        struct CloudScriptTaskSummary : public PlayFabBaseModel
        {
            AZStd::string TaskInstanceId;
            NameIdentifier* TaskIdentifier;
            time_t StartedAt;
            OptionalTime CompletedAt;
            Boxed<TaskInstanceStatus> Status;
            OptionalDouble PercentComplete;
            OptionalDouble EstimatedSecondsRemaining;
            AZStd::string ScheduledByUserId;
            ExecuteCloudScriptResult* Result;

            CloudScriptTaskSummary() :
                PlayFabBaseModel(),
                TaskInstanceId(),
                TaskIdentifier(nullptr),
                StartedAt(0),
                CompletedAt(),
                Status(),
                PercentComplete(),
                EstimatedSecondsRemaining(),
                ScheduledByUserId(),
                Result(nullptr)
            {}

            CloudScriptTaskSummary(const CloudScriptTaskSummary& src) :
                PlayFabBaseModel(),
                TaskInstanceId(src.TaskInstanceId),
                TaskIdentifier(src.TaskIdentifier ? new NameIdentifier(*src.TaskIdentifier) : nullptr),
                StartedAt(src.StartedAt),
                CompletedAt(src.CompletedAt),
                Status(src.Status),
                PercentComplete(src.PercentComplete),
                EstimatedSecondsRemaining(src.EstimatedSecondsRemaining),
                ScheduledByUserId(src.ScheduledByUserId),
                Result(src.Result ? new ExecuteCloudScriptResult(*src.Result) : nullptr)
            {}

            CloudScriptTaskSummary(const rapidjson::Value& obj) : CloudScriptTaskSummary()
            {
                readFromValue(obj);
            }

            ~CloudScriptTaskSummary()
            {
                if (TaskIdentifier != nullptr) delete TaskIdentifier;
                if (Result != nullptr) delete Result;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (TaskInstanceId.length() > 0) {
                    writer.String("TaskInstanceId");
                    writer.String(TaskInstanceId.c_str());
                }
                if (TaskIdentifier != nullptr) {
                    writer.String("TaskIdentifier");
                    TaskIdentifier->writeJSON(writer);
                }
                writer.String("StartedAt");
                writeDatetime(StartedAt, writer);
                if (CompletedAt.notNull()) {
                    writer.String("CompletedAt");
                    writeDatetime(CompletedAt, writer);
                }
                if (Status.notNull()) {
                    writer.String("Status");
                    writeTaskInstanceStatusEnumJSON(Status, writer);
                }
                if (PercentComplete.notNull()) {
                    writer.String("PercentComplete");
                    writer.Double(PercentComplete);
                }
                if (EstimatedSecondsRemaining.notNull()) {
                    writer.String("EstimatedSecondsRemaining");
                    writer.Double(EstimatedSecondsRemaining);
                }
                if (ScheduledByUserId.length() > 0) {
                    writer.String("ScheduledByUserId");
                    writer.String(ScheduledByUserId.c_str());
                }
                if (Result != nullptr) {
                    writer.String("Result");
                    Result->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TaskInstanceId_member = obj.FindMember("TaskInstanceId");
                if (TaskInstanceId_member != obj.MemberEnd() && !TaskInstanceId_member->value.IsNull()) TaskInstanceId = TaskInstanceId_member->value.GetString();
                const Value::ConstMemberIterator TaskIdentifier_member = obj.FindMember("TaskIdentifier");
                if (TaskIdentifier_member != obj.MemberEnd() && !TaskIdentifier_member->value.IsNull()) TaskIdentifier = new NameIdentifier(TaskIdentifier_member->value);
                const Value::ConstMemberIterator StartedAt_member = obj.FindMember("StartedAt");
                if (StartedAt_member != obj.MemberEnd() && !StartedAt_member->value.IsNull()) StartedAt = readDatetime(StartedAt_member->value);
                const Value::ConstMemberIterator CompletedAt_member = obj.FindMember("CompletedAt");
                if (CompletedAt_member != obj.MemberEnd() && !CompletedAt_member->value.IsNull()) CompletedAt = readDatetime(CompletedAt_member->value);
                const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
                if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readTaskInstanceStatusFromValue(Status_member->value);
                const Value::ConstMemberIterator PercentComplete_member = obj.FindMember("PercentComplete");
                if (PercentComplete_member != obj.MemberEnd() && !PercentComplete_member->value.IsNull()) PercentComplete = PercentComplete_member->value.GetDouble();
                const Value::ConstMemberIterator EstimatedSecondsRemaining_member = obj.FindMember("EstimatedSecondsRemaining");
                if (EstimatedSecondsRemaining_member != obj.MemberEnd() && !EstimatedSecondsRemaining_member->value.IsNull()) EstimatedSecondsRemaining = EstimatedSecondsRemaining_member->value.GetDouble();
                const Value::ConstMemberIterator ScheduledByUserId_member = obj.FindMember("ScheduledByUserId");
                if (ScheduledByUserId_member != obj.MemberEnd() && !ScheduledByUserId_member->value.IsNull()) ScheduledByUserId = ScheduledByUserId_member->value.GetString();
                const Value::ConstMemberIterator Result_member = obj.FindMember("Result");
                if (Result_member != obj.MemberEnd() && !Result_member->value.IsNull()) Result = new ExecuteCloudScriptResult(Result_member->value);

                return true;
            }
        };

        struct CloudScriptVersionStatus : public PlayFabBaseModel
        {
            Int32 Version;
            Int32 PublishedRevision;
            Int32 LatestRevision;

            CloudScriptVersionStatus() :
                PlayFabBaseModel(),
                Version(0),
                PublishedRevision(0),
                LatestRevision(0)
            {}

            CloudScriptVersionStatus(const CloudScriptVersionStatus& src) :
                PlayFabBaseModel(),
                Version(src.Version),
                PublishedRevision(src.PublishedRevision),
                LatestRevision(src.LatestRevision)
            {}

            CloudScriptVersionStatus(const rapidjson::Value& obj) : CloudScriptVersionStatus()
            {
                readFromValue(obj);
            }

            ~CloudScriptVersionStatus()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Version");
                writer.Int(Version);
                writer.String("PublishedRevision");
                writer.Int(PublishedRevision);
                writer.String("LatestRevision");
                writer.Int(LatestRevision);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator PublishedRevision_member = obj.FindMember("PublishedRevision");
                if (PublishedRevision_member != obj.MemberEnd() && !PublishedRevision_member->value.IsNull()) PublishedRevision = PublishedRevision_member->value.GetInt();
                const Value::ConstMemberIterator LatestRevision_member = obj.FindMember("LatestRevision");
                if (LatestRevision_member != obj.MemberEnd() && !LatestRevision_member->value.IsNull()) LatestRevision = LatestRevision_member->value.GetInt();

                return true;
            }
        };

        enum EmailVerificationStatus
        {
            EmailVerificationStatusUnverified,
            EmailVerificationStatusPending,
            EmailVerificationStatusConfirmed
        };

        inline void writeEmailVerificationStatusEnumJSON(EmailVerificationStatus enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case EmailVerificationStatusUnverified: writer.String("Unverified"); break;
            case EmailVerificationStatusPending: writer.String("Pending"); break;
            case EmailVerificationStatusConfirmed: writer.String("Confirmed"); break;

            }
        }

        inline EmailVerificationStatus readEmailVerificationStatusFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<EmailVerificationStatus>(obj.GetInt());

            static std::map<const char *, EmailVerificationStatus, PlayFabServerSdk::StringCompare> _EmailVerificationStatusMap;
            if (_EmailVerificationStatusMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _EmailVerificationStatusMap["Unverified"] = EmailVerificationStatusUnverified;
                _EmailVerificationStatusMap["Pending"] = EmailVerificationStatusPending;
                _EmailVerificationStatusMap["Confirmed"] = EmailVerificationStatusConfirmed;

            }

            auto output = _EmailVerificationStatusMap.find(obj.GetString());
            if (output != _EmailVerificationStatusMap.end())
                return output->second;

            return EmailVerificationStatusUnverified; // Basically critical fail
        }

        struct ContactEmailInfo : public PlayFabBaseModel
        {
            AZStd::string Name;
            AZStd::string EmailAddress;
            Boxed<EmailVerificationStatus> VerificationStatus;

            ContactEmailInfo() :
                PlayFabBaseModel(),
                Name(),
                EmailAddress(),
                VerificationStatus()
            {}

            ContactEmailInfo(const ContactEmailInfo& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                EmailAddress(src.EmailAddress),
                VerificationStatus(src.VerificationStatus)
            {}

            ContactEmailInfo(const rapidjson::Value& obj) : ContactEmailInfo()
            {
                readFromValue(obj);
            }

            ~ContactEmailInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Name.length() > 0) {
                    writer.String("Name");
                    writer.String(Name.c_str());
                }
                if (EmailAddress.length() > 0) {
                    writer.String("EmailAddress");
                    writer.String(EmailAddress.c_str());
                }
                if (VerificationStatus.notNull()) {
                    writer.String("VerificationStatus");
                    writeEmailVerificationStatusEnumJSON(VerificationStatus, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
                const Value::ConstMemberIterator EmailAddress_member = obj.FindMember("EmailAddress");
                if (EmailAddress_member != obj.MemberEnd() && !EmailAddress_member->value.IsNull()) EmailAddress = EmailAddress_member->value.GetString();
                const Value::ConstMemberIterator VerificationStatus_member = obj.FindMember("VerificationStatus");
                if (VerificationStatus_member != obj.MemberEnd() && !VerificationStatus_member->value.IsNull()) VerificationStatus = readEmailVerificationStatusFromValue(VerificationStatus_member->value);

                return true;
            }
        };

        struct ContentInfo : public PlayFabBaseModel
        {
            AZStd::string Key;
            Uint32 Size;
            time_t LastModified;

            ContentInfo() :
                PlayFabBaseModel(),
                Key(),
                Size(0),
                LastModified(0)
            {}

            ContentInfo(const ContentInfo& src) :
                PlayFabBaseModel(),
                Key(src.Key),
                Size(src.Size),
                LastModified(src.LastModified)
            {}

            ContentInfo(const rapidjson::Value& obj) : ContentInfo()
            {
                readFromValue(obj);
            }

            ~ContentInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Key.length() > 0) {
                    writer.String("Key");
                    writer.String(Key.c_str());
                }
                writer.String("Size");
                writer.Uint(Size);
                writer.String("LastModified");
                writeDatetime(LastModified, writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
                if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
                const Value::ConstMemberIterator Size_member = obj.FindMember("Size");
                if (Size_member != obj.MemberEnd() && !Size_member->value.IsNull()) Size = Size_member->value.GetUint();
                const Value::ConstMemberIterator LastModified_member = obj.FindMember("LastModified");
                if (LastModified_member != obj.MemberEnd() && !LastModified_member->value.IsNull()) LastModified = readDatetime(LastModified_member->value);

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

            static std::map<const char *, ContinentCode, PlayFabServerSdk::StringCompare> _ContinentCodeMap;
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

            static std::map<const char *, CountryCode, PlayFabServerSdk::StringCompare> _CountryCodeMap;
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

        struct CreateActionsOnPlayerSegmentTaskRequest : public PlayFabBaseModel
        {
            AZStd::string Name;
            AZStd::string Description;
            AZStd::string Schedule;
            bool IsActive;
            ActionsOnPlayersInSegmentTaskParameter Parameter;

            CreateActionsOnPlayerSegmentTaskRequest() :
                PlayFabBaseModel(),
                Name(),
                Description(),
                Schedule(),
                IsActive(false),
                Parameter()
            {}

            CreateActionsOnPlayerSegmentTaskRequest(const CreateActionsOnPlayerSegmentTaskRequest& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Description(src.Description),
                Schedule(src.Schedule),
                IsActive(src.IsActive),
                Parameter(src.Parameter)
            {}

            CreateActionsOnPlayerSegmentTaskRequest(const rapidjson::Value& obj) : CreateActionsOnPlayerSegmentTaskRequest()
            {
                readFromValue(obj);
            }

            ~CreateActionsOnPlayerSegmentTaskRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Name");
                writer.String(Name.c_str());
                if (Description.length() > 0) {
                    writer.String("Description");
                    writer.String(Description.c_str());
                }
                if (Schedule.length() > 0) {
                    writer.String("Schedule");
                    writer.String(Schedule.c_str());
                }
                writer.String("IsActive");
                writer.Bool(IsActive);
                writer.String("Parameter");
                Parameter.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
                const Value::ConstMemberIterator Description_member = obj.FindMember("Description");
                if (Description_member != obj.MemberEnd() && !Description_member->value.IsNull()) Description = Description_member->value.GetString();
                const Value::ConstMemberIterator Schedule_member = obj.FindMember("Schedule");
                if (Schedule_member != obj.MemberEnd() && !Schedule_member->value.IsNull()) Schedule = Schedule_member->value.GetString();
                const Value::ConstMemberIterator IsActive_member = obj.FindMember("IsActive");
                if (IsActive_member != obj.MemberEnd() && !IsActive_member->value.IsNull()) IsActive = IsActive_member->value.GetBool();
                const Value::ConstMemberIterator Parameter_member = obj.FindMember("Parameter");
                if (Parameter_member != obj.MemberEnd() && !Parameter_member->value.IsNull()) Parameter = ActionsOnPlayersInSegmentTaskParameter(Parameter_member->value);

                return true;
            }
        };

        struct CreateCloudScriptTaskRequest : public PlayFabBaseModel
        {
            AZStd::string Name;
            AZStd::string Description;
            AZStd::string Schedule;
            bool IsActive;
            CloudScriptTaskParameter Parameter;

            CreateCloudScriptTaskRequest() :
                PlayFabBaseModel(),
                Name(),
                Description(),
                Schedule(),
                IsActive(false),
                Parameter()
            {}

            CreateCloudScriptTaskRequest(const CreateCloudScriptTaskRequest& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Description(src.Description),
                Schedule(src.Schedule),
                IsActive(src.IsActive),
                Parameter(src.Parameter)
            {}

            CreateCloudScriptTaskRequest(const rapidjson::Value& obj) : CreateCloudScriptTaskRequest()
            {
                readFromValue(obj);
            }

            ~CreateCloudScriptTaskRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Name");
                writer.String(Name.c_str());
                if (Description.length() > 0) {
                    writer.String("Description");
                    writer.String(Description.c_str());
                }
                if (Schedule.length() > 0) {
                    writer.String("Schedule");
                    writer.String(Schedule.c_str());
                }
                writer.String("IsActive");
                writer.Bool(IsActive);
                writer.String("Parameter");
                Parameter.writeJSON(writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
                const Value::ConstMemberIterator Description_member = obj.FindMember("Description");
                if (Description_member != obj.MemberEnd() && !Description_member->value.IsNull()) Description = Description_member->value.GetString();
                const Value::ConstMemberIterator Schedule_member = obj.FindMember("Schedule");
                if (Schedule_member != obj.MemberEnd() && !Schedule_member->value.IsNull()) Schedule = Schedule_member->value.GetString();
                const Value::ConstMemberIterator IsActive_member = obj.FindMember("IsActive");
                if (IsActive_member != obj.MemberEnd() && !IsActive_member->value.IsNull()) IsActive = IsActive_member->value.GetBool();
                const Value::ConstMemberIterator Parameter_member = obj.FindMember("Parameter");
                if (Parameter_member != obj.MemberEnd() && !Parameter_member->value.IsNull()) Parameter = CloudScriptTaskParameter(Parameter_member->value);

                return true;
            }
        };

        struct CreatePlayerSharedSecretRequest : public PlayFabBaseModel
        {
            AZStd::string FriendlyName;

            CreatePlayerSharedSecretRequest() :
                PlayFabBaseModel(),
                FriendlyName()
            {}

            CreatePlayerSharedSecretRequest(const CreatePlayerSharedSecretRequest& src) :
                PlayFabBaseModel(),
                FriendlyName(src.FriendlyName)
            {}

            CreatePlayerSharedSecretRequest(const rapidjson::Value& obj) : CreatePlayerSharedSecretRequest()
            {
                readFromValue(obj);
            }

            ~CreatePlayerSharedSecretRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (FriendlyName.length() > 0) {
                    writer.String("FriendlyName");
                    writer.String(FriendlyName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator FriendlyName_member = obj.FindMember("FriendlyName");
                if (FriendlyName_member != obj.MemberEnd() && !FriendlyName_member->value.IsNull()) FriendlyName = FriendlyName_member->value.GetString();

                return true;
            }
        };

        struct CreatePlayerSharedSecretResult : public PlayFabBaseModel
        {
            AZStd::string SecretKey;

            CreatePlayerSharedSecretResult() :
                PlayFabBaseModel(),
                SecretKey()
            {}

            CreatePlayerSharedSecretResult(const CreatePlayerSharedSecretResult& src) :
                PlayFabBaseModel(),
                SecretKey(src.SecretKey)
            {}

            CreatePlayerSharedSecretResult(const rapidjson::Value& obj) : CreatePlayerSharedSecretResult()
            {
                readFromValue(obj);
            }

            ~CreatePlayerSharedSecretResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (SecretKey.length() > 0) {
                    writer.String("SecretKey");
                    writer.String(SecretKey.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SecretKey_member = obj.FindMember("SecretKey");
                if (SecretKey_member != obj.MemberEnd() && !SecretKey_member->value.IsNull()) SecretKey = SecretKey_member->value.GetString();

                return true;
            }
        };

        enum StatisticResetIntervalOption
        {
            StatisticResetIntervalOptionNever,
            StatisticResetIntervalOptionHour,
            StatisticResetIntervalOptionDay,
            StatisticResetIntervalOptionWeek,
            StatisticResetIntervalOptionMonth
        };

        inline void writeStatisticResetIntervalOptionEnumJSON(StatisticResetIntervalOption enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case StatisticResetIntervalOptionNever: writer.String("Never"); break;
            case StatisticResetIntervalOptionHour: writer.String("Hour"); break;
            case StatisticResetIntervalOptionDay: writer.String("Day"); break;
            case StatisticResetIntervalOptionWeek: writer.String("Week"); break;
            case StatisticResetIntervalOptionMonth: writer.String("Month"); break;

            }
        }

        inline StatisticResetIntervalOption readStatisticResetIntervalOptionFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<StatisticResetIntervalOption>(obj.GetInt());

            static std::map<const char *, StatisticResetIntervalOption, PlayFabServerSdk::StringCompare> _StatisticResetIntervalOptionMap;
            if (_StatisticResetIntervalOptionMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _StatisticResetIntervalOptionMap["Never"] = StatisticResetIntervalOptionNever;
                _StatisticResetIntervalOptionMap["Hour"] = StatisticResetIntervalOptionHour;
                _StatisticResetIntervalOptionMap["Day"] = StatisticResetIntervalOptionDay;
                _StatisticResetIntervalOptionMap["Week"] = StatisticResetIntervalOptionWeek;
                _StatisticResetIntervalOptionMap["Month"] = StatisticResetIntervalOptionMonth;

            }

            auto output = _StatisticResetIntervalOptionMap.find(obj.GetString());
            if (output != _StatisticResetIntervalOptionMap.end())
                return output->second;

            return StatisticResetIntervalOptionNever; // Basically critical fail
        }

        enum StatisticAggregationMethod
        {
            StatisticAggregationMethodLast,
            StatisticAggregationMethodMin,
            StatisticAggregationMethodMax,
            StatisticAggregationMethodSum
        };

        inline void writeStatisticAggregationMethodEnumJSON(StatisticAggregationMethod enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case StatisticAggregationMethodLast: writer.String("Last"); break;
            case StatisticAggregationMethodMin: writer.String("Min"); break;
            case StatisticAggregationMethodMax: writer.String("Max"); break;
            case StatisticAggregationMethodSum: writer.String("Sum"); break;

            }
        }

        inline StatisticAggregationMethod readStatisticAggregationMethodFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<StatisticAggregationMethod>(obj.GetInt());

            static std::map<const char *, StatisticAggregationMethod, PlayFabServerSdk::StringCompare> _StatisticAggregationMethodMap;
            if (_StatisticAggregationMethodMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _StatisticAggregationMethodMap["Last"] = StatisticAggregationMethodLast;
                _StatisticAggregationMethodMap["Min"] = StatisticAggregationMethodMin;
                _StatisticAggregationMethodMap["Max"] = StatisticAggregationMethodMax;
                _StatisticAggregationMethodMap["Sum"] = StatisticAggregationMethodSum;

            }

            auto output = _StatisticAggregationMethodMap.find(obj.GetString());
            if (output != _StatisticAggregationMethodMap.end())
                return output->second;

            return StatisticAggregationMethodLast; // Basically critical fail
        }

        struct CreatePlayerStatisticDefinitionRequest : public PlayFabBaseModel
        {
            AZStd::string StatisticName;
            Boxed<StatisticResetIntervalOption> VersionChangeInterval;
            Boxed<StatisticAggregationMethod> AggregationMethod;

            CreatePlayerStatisticDefinitionRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                VersionChangeInterval(),
                AggregationMethod()
            {}

            CreatePlayerStatisticDefinitionRequest(const CreatePlayerStatisticDefinitionRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                VersionChangeInterval(src.VersionChangeInterval),
                AggregationMethod(src.AggregationMethod)
            {}

            CreatePlayerStatisticDefinitionRequest(const rapidjson::Value& obj) : CreatePlayerStatisticDefinitionRequest()
            {
                readFromValue(obj);
            }

            ~CreatePlayerStatisticDefinitionRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("StatisticName");
                writer.String(StatisticName.c_str());
                if (VersionChangeInterval.notNull()) {
                    writer.String("VersionChangeInterval");
                    writeStatisticResetIntervalOptionEnumJSON(VersionChangeInterval, writer);
                }
                if (AggregationMethod.notNull()) {
                    writer.String("AggregationMethod");
                    writeStatisticAggregationMethodEnumJSON(AggregationMethod, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator VersionChangeInterval_member = obj.FindMember("VersionChangeInterval");
                if (VersionChangeInterval_member != obj.MemberEnd() && !VersionChangeInterval_member->value.IsNull()) VersionChangeInterval = readStatisticResetIntervalOptionFromValue(VersionChangeInterval_member->value);
                const Value::ConstMemberIterator AggregationMethod_member = obj.FindMember("AggregationMethod");
                if (AggregationMethod_member != obj.MemberEnd() && !AggregationMethod_member->value.IsNull()) AggregationMethod = readStatisticAggregationMethodFromValue(AggregationMethod_member->value);

                return true;
            }
        };

        struct PlayerStatisticDefinition : public PlayFabBaseModel
        {
            AZStd::string StatisticName;
            Uint32 CurrentVersion;
            Boxed<StatisticResetIntervalOption> VersionChangeInterval;
            Boxed<StatisticAggregationMethod> AggregationMethod;

            PlayerStatisticDefinition() :
                PlayFabBaseModel(),
                StatisticName(),
                CurrentVersion(0),
                VersionChangeInterval(),
                AggregationMethod()
            {}

            PlayerStatisticDefinition(const PlayerStatisticDefinition& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                CurrentVersion(src.CurrentVersion),
                VersionChangeInterval(src.VersionChangeInterval),
                AggregationMethod(src.AggregationMethod)
            {}

            PlayerStatisticDefinition(const rapidjson::Value& obj) : PlayerStatisticDefinition()
            {
                readFromValue(obj);
            }

            ~PlayerStatisticDefinition()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (StatisticName.length() > 0) {
                    writer.String("StatisticName");
                    writer.String(StatisticName.c_str());
                }
                writer.String("CurrentVersion");
                writer.Uint(CurrentVersion);
                if (VersionChangeInterval.notNull()) {
                    writer.String("VersionChangeInterval");
                    writeStatisticResetIntervalOptionEnumJSON(VersionChangeInterval, writer);
                }
                if (AggregationMethod.notNull()) {
                    writer.String("AggregationMethod");
                    writeStatisticAggregationMethodEnumJSON(AggregationMethod, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator CurrentVersion_member = obj.FindMember("CurrentVersion");
                if (CurrentVersion_member != obj.MemberEnd() && !CurrentVersion_member->value.IsNull()) CurrentVersion = CurrentVersion_member->value.GetUint();
                const Value::ConstMemberIterator VersionChangeInterval_member = obj.FindMember("VersionChangeInterval");
                if (VersionChangeInterval_member != obj.MemberEnd() && !VersionChangeInterval_member->value.IsNull()) VersionChangeInterval = readStatisticResetIntervalOptionFromValue(VersionChangeInterval_member->value);
                const Value::ConstMemberIterator AggregationMethod_member = obj.FindMember("AggregationMethod");
                if (AggregationMethod_member != obj.MemberEnd() && !AggregationMethod_member->value.IsNull()) AggregationMethod = readStatisticAggregationMethodFromValue(AggregationMethod_member->value);

                return true;
            }
        };

        struct CreatePlayerStatisticDefinitionResult : public PlayFabBaseModel
        {
            PlayerStatisticDefinition* Statistic;

            CreatePlayerStatisticDefinitionResult() :
                PlayFabBaseModel(),
                Statistic(nullptr)
            {}

            CreatePlayerStatisticDefinitionResult(const CreatePlayerStatisticDefinitionResult& src) :
                PlayFabBaseModel(),
                Statistic(src.Statistic ? new PlayerStatisticDefinition(*src.Statistic) : nullptr)
            {}

            CreatePlayerStatisticDefinitionResult(const rapidjson::Value& obj) : CreatePlayerStatisticDefinitionResult()
            {
                readFromValue(obj);
            }

            ~CreatePlayerStatisticDefinitionResult()
            {
                if (Statistic != nullptr) delete Statistic;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Statistic != nullptr) {
                    writer.String("Statistic");
                    Statistic->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Statistic_member = obj.FindMember("Statistic");
                if (Statistic_member != obj.MemberEnd() && !Statistic_member->value.IsNull()) Statistic = new PlayerStatisticDefinition(Statistic_member->value);

                return true;
            }
        };

        struct CreateTaskResult : public PlayFabBaseModel
        {
            AZStd::string TaskId;

            CreateTaskResult() :
                PlayFabBaseModel(),
                TaskId()
            {}

            CreateTaskResult(const CreateTaskResult& src) :
                PlayFabBaseModel(),
                TaskId(src.TaskId)
            {}

            CreateTaskResult(const rapidjson::Value& obj) : CreateTaskResult()
            {
                readFromValue(obj);
            }

            ~CreateTaskResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (TaskId.length() > 0) {
                    writer.String("TaskId");
                    writer.String(TaskId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TaskId_member = obj.FindMember("TaskId");
                if (TaskId_member != obj.MemberEnd() && !TaskId_member->value.IsNull()) TaskId = TaskId_member->value.GetString();

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

            static std::map<const char *, Currency, PlayFabServerSdk::StringCompare> _CurrencyMap;
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

        struct DeleteContentRequest : public PlayFabBaseModel
        {
            AZStd::string Key;

            DeleteContentRequest() :
                PlayFabBaseModel(),
                Key()
            {}

            DeleteContentRequest(const DeleteContentRequest& src) :
                PlayFabBaseModel(),
                Key(src.Key)
            {}

            DeleteContentRequest(const rapidjson::Value& obj) : DeleteContentRequest()
            {
                readFromValue(obj);
            }

            ~DeleteContentRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Key");
                writer.String(Key.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
                if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();

                return true;
            }
        };

        struct DeletePlayerRequest : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;

            DeletePlayerRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            DeletePlayerRequest(const DeletePlayerRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            DeletePlayerRequest(const rapidjson::Value& obj) : DeletePlayerRequest()
            {
                readFromValue(obj);
            }

            ~DeletePlayerRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct DeletePlayerResult : public PlayFabBaseModel
        {

            DeletePlayerResult() :
                PlayFabBaseModel()
            {}

            DeletePlayerResult(const DeletePlayerResult& src) :
                PlayFabBaseModel()
            {}

            DeletePlayerResult(const rapidjson::Value& obj) : DeletePlayerResult()
            {
                readFromValue(obj);
            }

            ~DeletePlayerResult()
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

        struct DeletePlayerSharedSecretRequest : public PlayFabBaseModel
        {
            AZStd::string SecretKey;

            DeletePlayerSharedSecretRequest() :
                PlayFabBaseModel(),
                SecretKey()
            {}

            DeletePlayerSharedSecretRequest(const DeletePlayerSharedSecretRequest& src) :
                PlayFabBaseModel(),
                SecretKey(src.SecretKey)
            {}

            DeletePlayerSharedSecretRequest(const rapidjson::Value& obj) : DeletePlayerSharedSecretRequest()
            {
                readFromValue(obj);
            }

            ~DeletePlayerSharedSecretRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (SecretKey.length() > 0) {
                    writer.String("SecretKey");
                    writer.String(SecretKey.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SecretKey_member = obj.FindMember("SecretKey");
                if (SecretKey_member != obj.MemberEnd() && !SecretKey_member->value.IsNull()) SecretKey = SecretKey_member->value.GetString();

                return true;
            }
        };

        struct DeletePlayerSharedSecretResult : public PlayFabBaseModel
        {

            DeletePlayerSharedSecretResult() :
                PlayFabBaseModel()
            {}

            DeletePlayerSharedSecretResult(const DeletePlayerSharedSecretResult& src) :
                PlayFabBaseModel()
            {}

            DeletePlayerSharedSecretResult(const rapidjson::Value& obj) : DeletePlayerSharedSecretResult()
            {
                readFromValue(obj);
            }

            ~DeletePlayerSharedSecretResult()
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

        struct DeleteStoreRequest : public PlayFabBaseModel
        {
            AZStd::string CatalogVersion;
            AZStd::string StoreId;

            DeleteStoreRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                StoreId()
            {}

            DeleteStoreRequest(const DeleteStoreRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                StoreId(src.StoreId)
            {}

            DeleteStoreRequest(const rapidjson::Value& obj) : DeleteStoreRequest()
            {
                readFromValue(obj);
            }

            ~DeleteStoreRequest()
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

        struct DeleteStoreResult : public PlayFabBaseModel
        {

            DeleteStoreResult() :
                PlayFabBaseModel()
            {}

            DeleteStoreResult(const DeleteStoreResult& src) :
                PlayFabBaseModel()
            {}

            DeleteStoreResult(const rapidjson::Value& obj) : DeleteStoreResult()
            {
                readFromValue(obj);
            }

            ~DeleteStoreResult()
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

        struct DeleteTaskRequest : public PlayFabBaseModel
        {
            NameIdentifier* Identifier;

            DeleteTaskRequest() :
                PlayFabBaseModel(),
                Identifier(nullptr)
            {}

            DeleteTaskRequest(const DeleteTaskRequest& src) :
                PlayFabBaseModel(),
                Identifier(src.Identifier ? new NameIdentifier(*src.Identifier) : nullptr)
            {}

            DeleteTaskRequest(const rapidjson::Value& obj) : DeleteTaskRequest()
            {
                readFromValue(obj);
            }

            ~DeleteTaskRequest()
            {
                if (Identifier != nullptr) delete Identifier;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Identifier != nullptr) {
                    writer.String("Identifier");
                    Identifier->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Identifier_member = obj.FindMember("Identifier");
                if (Identifier_member != obj.MemberEnd() && !Identifier_member->value.IsNull()) Identifier = new NameIdentifier(Identifier_member->value);

                return true;
            }
        };

        struct DeleteUsersRequest : public PlayFabBaseModel
        {
            std::list<AZStd::string> PlayFabIds;
            AZStd::string TitleId;

            DeleteUsersRequest() :
                PlayFabBaseModel(),
                PlayFabIds(),
                TitleId()
            {}

            DeleteUsersRequest(const DeleteUsersRequest& src) :
                PlayFabBaseModel(),
                PlayFabIds(src.PlayFabIds),
                TitleId(src.TitleId)
            {}

            DeleteUsersRequest(const rapidjson::Value& obj) : DeleteUsersRequest()
            {
                readFromValue(obj);
            }

            ~DeleteUsersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabIds");
                writer.StartArray();
                for (std::list<AZStd::string>::iterator iter = PlayFabIds.begin(); iter != PlayFabIds.end(); iter++) {
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.String("TitleId");
                writer.String(TitleId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabIds_member = obj.FindMember("PlayFabIds");
                if (PlayFabIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = PlayFabIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        PlayFabIds.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();

                return true;
            }
        };

        struct DeleteUsersResult : public PlayFabBaseModel
        {

            DeleteUsersResult() :
                PlayFabBaseModel()
            {}

            DeleteUsersResult(const DeleteUsersResult& src) :
                PlayFabBaseModel()
            {}

            DeleteUsersResult(const rapidjson::Value& obj) : DeleteUsersResult()
            {
                readFromValue(obj);
            }

            ~DeleteUsersResult()
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

        enum EffectType
        {
            EffectTypeAllow,
            EffectTypeDeny
        };

        inline void writeEffectTypeEnumJSON(EffectType enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case EffectTypeAllow: writer.String("Allow"); break;
            case EffectTypeDeny: writer.String("Deny"); break;

            }
        }

        inline EffectType readEffectTypeFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<EffectType>(obj.GetInt());

            static std::map<const char *, EffectType, PlayFabServerSdk::StringCompare> _EffectTypeMap;
            if (_EffectTypeMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _EffectTypeMap["Allow"] = EffectTypeAllow;
                _EffectTypeMap["Deny"] = EffectTypeDeny;

            }

            auto output = _EffectTypeMap.find(obj.GetString());
            if (output != _EffectTypeMap.end())
                return output->second;

            return EffectTypeAllow; // Basically critical fail
        }

        struct EmptyResult : public PlayFabBaseModel
        {

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

        struct GameModeInfo : public PlayFabBaseModel
        {
            AZStd::string Gamemode;
            Uint32 MinPlayerCount;
            Uint32 MaxPlayerCount;
            OptionalBool StartOpen;

            GameModeInfo() :
                PlayFabBaseModel(),
                Gamemode(),
                MinPlayerCount(0),
                MaxPlayerCount(0),
                StartOpen()
            {}

            GameModeInfo(const GameModeInfo& src) :
                PlayFabBaseModel(),
                Gamemode(src.Gamemode),
                MinPlayerCount(src.MinPlayerCount),
                MaxPlayerCount(src.MaxPlayerCount),
                StartOpen(src.StartOpen)
            {}

            GameModeInfo(const rapidjson::Value& obj) : GameModeInfo()
            {
                readFromValue(obj);
            }

            ~GameModeInfo()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Gamemode");
                writer.String(Gamemode.c_str());
                writer.String("MinPlayerCount");
                writer.Uint(MinPlayerCount);
                writer.String("MaxPlayerCount");
                writer.Uint(MaxPlayerCount);
                if (StartOpen.notNull()) {
                    writer.String("StartOpen");
                    writer.Bool(StartOpen);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Gamemode_member = obj.FindMember("Gamemode");
                if (Gamemode_member != obj.MemberEnd() && !Gamemode_member->value.IsNull()) Gamemode = Gamemode_member->value.GetString();
                const Value::ConstMemberIterator MinPlayerCount_member = obj.FindMember("MinPlayerCount");
                if (MinPlayerCount_member != obj.MemberEnd() && !MinPlayerCount_member->value.IsNull()) MinPlayerCount = MinPlayerCount_member->value.GetUint();
                const Value::ConstMemberIterator MaxPlayerCount_member = obj.FindMember("MaxPlayerCount");
                if (MaxPlayerCount_member != obj.MemberEnd() && !MaxPlayerCount_member->value.IsNull()) MaxPlayerCount = MaxPlayerCount_member->value.GetUint();
                const Value::ConstMemberIterator StartOpen_member = obj.FindMember("StartOpen");
                if (StartOpen_member != obj.MemberEnd() && !StartOpen_member->value.IsNull()) StartOpen = StartOpen_member->value.GetBool();

                return true;
            }
        };

        struct GetActionGroupResult : public PlayFabBaseModel
        {
            AZStd::string Name;
            AZStd::string Id;

            GetActionGroupResult() :
                PlayFabBaseModel(),
                Name(),
                Id()
            {}

            GetActionGroupResult(const GetActionGroupResult& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Id(src.Id)
            {}

            GetActionGroupResult(const rapidjson::Value& obj) : GetActionGroupResult()
            {
                readFromValue(obj);
            }

            ~GetActionGroupResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Name");
                writer.String(Name.c_str());
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

        struct GetActionsOnPlayersInSegmentTaskInstanceResult : public PlayFabBaseModel
        {
            ActionsOnPlayersInSegmentTaskSummary* Summary;
            ActionsOnPlayersInSegmentTaskParameter* Parameter;

            GetActionsOnPlayersInSegmentTaskInstanceResult() :
                PlayFabBaseModel(),
                Summary(nullptr),
                Parameter(nullptr)
            {}

            GetActionsOnPlayersInSegmentTaskInstanceResult(const GetActionsOnPlayersInSegmentTaskInstanceResult& src) :
                PlayFabBaseModel(),
                Summary(src.Summary ? new ActionsOnPlayersInSegmentTaskSummary(*src.Summary) : nullptr),
                Parameter(src.Parameter ? new ActionsOnPlayersInSegmentTaskParameter(*src.Parameter) : nullptr)
            {}

            GetActionsOnPlayersInSegmentTaskInstanceResult(const rapidjson::Value& obj) : GetActionsOnPlayersInSegmentTaskInstanceResult()
            {
                readFromValue(obj);
            }

            ~GetActionsOnPlayersInSegmentTaskInstanceResult()
            {
                if (Summary != nullptr) delete Summary;
                if (Parameter != nullptr) delete Parameter;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Summary != nullptr) {
                    writer.String("Summary");
                    Summary->writeJSON(writer);
                }
                if (Parameter != nullptr) {
                    writer.String("Parameter");
                    Parameter->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Summary_member = obj.FindMember("Summary");
                if (Summary_member != obj.MemberEnd() && !Summary_member->value.IsNull()) Summary = new ActionsOnPlayersInSegmentTaskSummary(Summary_member->value);
                const Value::ConstMemberIterator Parameter_member = obj.FindMember("Parameter");
                if (Parameter_member != obj.MemberEnd() && !Parameter_member->value.IsNull()) Parameter = new ActionsOnPlayersInSegmentTaskParameter(Parameter_member->value);

                return true;
            }
        };

        struct GetAllActionGroupsRequest : public PlayFabBaseModel
        {

            GetAllActionGroupsRequest() :
                PlayFabBaseModel()
            {}

            GetAllActionGroupsRequest(const GetAllActionGroupsRequest& src) :
                PlayFabBaseModel()
            {}

            GetAllActionGroupsRequest(const rapidjson::Value& obj) : GetAllActionGroupsRequest()
            {
                readFromValue(obj);
            }

            ~GetAllActionGroupsRequest()
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

        struct GetAllActionGroupsResult : public PlayFabBaseModel
        {
            std::list<GetActionGroupResult> ActionGroups;

            GetAllActionGroupsResult() :
                PlayFabBaseModel(),
                ActionGroups()
            {}

            GetAllActionGroupsResult(const GetAllActionGroupsResult& src) :
                PlayFabBaseModel(),
                ActionGroups(src.ActionGroups)
            {}

            GetAllActionGroupsResult(const rapidjson::Value& obj) : GetAllActionGroupsResult()
            {
                readFromValue(obj);
            }

            ~GetAllActionGroupsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ActionGroups");
                writer.StartArray();
                for (std::list<GetActionGroupResult>::iterator iter = ActionGroups.begin(); iter != ActionGroups.end(); iter++) {
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ActionGroups_member = obj.FindMember("ActionGroups");
                if (ActionGroups_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = ActionGroups_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        ActionGroups.push_back(GetActionGroupResult(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetAllSegmentsRequest : public PlayFabBaseModel
        {

            GetAllSegmentsRequest() :
                PlayFabBaseModel()
            {}

            GetAllSegmentsRequest(const GetAllSegmentsRequest& src) :
                PlayFabBaseModel()
            {}

            GetAllSegmentsRequest(const rapidjson::Value& obj) : GetAllSegmentsRequest()
            {
                readFromValue(obj);
            }

            ~GetAllSegmentsRequest()
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

        struct GetAllSegmentsResult : public PlayFabBaseModel
        {
            std::list<GetSegmentResult> Segments;

            GetAllSegmentsResult() :
                PlayFabBaseModel(),
                Segments()
            {}

            GetAllSegmentsResult(const GetAllSegmentsResult& src) :
                PlayFabBaseModel(),
                Segments(src.Segments)
            {}

            GetAllSegmentsResult(const rapidjson::Value& obj) : GetAllSegmentsResult()
            {
                readFromValue(obj);
            }

            ~GetAllSegmentsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Segments.empty()) {
                    writer.String("Segments");
                    writer.StartArray();
                    for (std::list<GetSegmentResult>::iterator iter = Segments.begin(); iter != Segments.end(); iter++) {
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

        struct GetCatalogItemsRequest : public PlayFabBaseModel
        {
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
            std::list<CatalogItem> Catalog;

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
                    for (std::list<CatalogItem>::iterator iter = Catalog.begin(); iter != Catalog.end(); iter++) {
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

        struct GetCloudScriptRevisionRequest : public PlayFabBaseModel
        {
            OptionalInt32 Version;
            OptionalInt32 Revision;

            GetCloudScriptRevisionRequest() :
                PlayFabBaseModel(),
                Version(),
                Revision()
            {}

            GetCloudScriptRevisionRequest(const GetCloudScriptRevisionRequest& src) :
                PlayFabBaseModel(),
                Version(src.Version),
                Revision(src.Revision)
            {}

            GetCloudScriptRevisionRequest(const rapidjson::Value& obj) : GetCloudScriptRevisionRequest()
            {
                readFromValue(obj);
            }

            ~GetCloudScriptRevisionRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Version.notNull()) {
                    writer.String("Version");
                    writer.Int(Version);
                }
                if (Revision.notNull()) {
                    writer.String("Revision");
                    writer.Int(Revision);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator Revision_member = obj.FindMember("Revision");
                if (Revision_member != obj.MemberEnd() && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();

                return true;
            }
        };

        struct GetCloudScriptRevisionResult : public PlayFabBaseModel
        {
            Int32 Version;
            Int32 Revision;
            time_t CreatedAt;
            std::list<CloudScriptFile> Files;
            bool IsPublished;

            GetCloudScriptRevisionResult() :
                PlayFabBaseModel(),
                Version(0),
                Revision(0),
                CreatedAt(0),
                Files(),
                IsPublished(false)
            {}

            GetCloudScriptRevisionResult(const GetCloudScriptRevisionResult& src) :
                PlayFabBaseModel(),
                Version(src.Version),
                Revision(src.Revision),
                CreatedAt(src.CreatedAt),
                Files(src.Files),
                IsPublished(src.IsPublished)
            {}

            GetCloudScriptRevisionResult(const rapidjson::Value& obj) : GetCloudScriptRevisionResult()
            {
                readFromValue(obj);
            }

            ~GetCloudScriptRevisionResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Version");
                writer.Int(Version);
                writer.String("Revision");
                writer.Int(Revision);
                writer.String("CreatedAt");
                writeDatetime(CreatedAt, writer);
                if (!Files.empty()) {
                    writer.String("Files");
                    writer.StartArray();
                    for (std::list<CloudScriptFile>::iterator iter = Files.begin(); iter != Files.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.String("IsPublished");
                writer.Bool(IsPublished);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator Revision_member = obj.FindMember("Revision");
                if (Revision_member != obj.MemberEnd() && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();
                const Value::ConstMemberIterator CreatedAt_member = obj.FindMember("CreatedAt");
                if (CreatedAt_member != obj.MemberEnd() && !CreatedAt_member->value.IsNull()) CreatedAt = readDatetime(CreatedAt_member->value);
                const Value::ConstMemberIterator Files_member = obj.FindMember("Files");
                if (Files_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Files_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Files.push_back(CloudScriptFile(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator IsPublished_member = obj.FindMember("IsPublished");
                if (IsPublished_member != obj.MemberEnd() && !IsPublished_member->value.IsNull()) IsPublished = IsPublished_member->value.GetBool();

                return true;
            }
        };

        struct GetCloudScriptTaskInstanceResult : public PlayFabBaseModel
        {
            CloudScriptTaskSummary* Summary;
            CloudScriptTaskParameter* Parameter;

            GetCloudScriptTaskInstanceResult() :
                PlayFabBaseModel(),
                Summary(nullptr),
                Parameter(nullptr)
            {}

            GetCloudScriptTaskInstanceResult(const GetCloudScriptTaskInstanceResult& src) :
                PlayFabBaseModel(),
                Summary(src.Summary ? new CloudScriptTaskSummary(*src.Summary) : nullptr),
                Parameter(src.Parameter ? new CloudScriptTaskParameter(*src.Parameter) : nullptr)
            {}

            GetCloudScriptTaskInstanceResult(const rapidjson::Value& obj) : GetCloudScriptTaskInstanceResult()
            {
                readFromValue(obj);
            }

            ~GetCloudScriptTaskInstanceResult()
            {
                if (Summary != nullptr) delete Summary;
                if (Parameter != nullptr) delete Parameter;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Summary != nullptr) {
                    writer.String("Summary");
                    Summary->writeJSON(writer);
                }
                if (Parameter != nullptr) {
                    writer.String("Parameter");
                    Parameter->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Summary_member = obj.FindMember("Summary");
                if (Summary_member != obj.MemberEnd() && !Summary_member->value.IsNull()) Summary = new CloudScriptTaskSummary(Summary_member->value);
                const Value::ConstMemberIterator Parameter_member = obj.FindMember("Parameter");
                if (Parameter_member != obj.MemberEnd() && !Parameter_member->value.IsNull()) Parameter = new CloudScriptTaskParameter(Parameter_member->value);

                return true;
            }
        };

        struct GetCloudScriptVersionsRequest : public PlayFabBaseModel
        {

            GetCloudScriptVersionsRequest() :
                PlayFabBaseModel()
            {}

            GetCloudScriptVersionsRequest(const GetCloudScriptVersionsRequest& src) :
                PlayFabBaseModel()
            {}

            GetCloudScriptVersionsRequest(const rapidjson::Value& obj) : GetCloudScriptVersionsRequest()
            {
                readFromValue(obj);
            }

            ~GetCloudScriptVersionsRequest()
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

        struct GetCloudScriptVersionsResult : public PlayFabBaseModel
        {
            std::list<CloudScriptVersionStatus> Versions;

            GetCloudScriptVersionsResult() :
                PlayFabBaseModel(),
                Versions()
            {}

            GetCloudScriptVersionsResult(const GetCloudScriptVersionsResult& src) :
                PlayFabBaseModel(),
                Versions(src.Versions)
            {}

            GetCloudScriptVersionsResult(const rapidjson::Value& obj) : GetCloudScriptVersionsResult()
            {
                readFromValue(obj);
            }

            ~GetCloudScriptVersionsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Versions.empty()) {
                    writer.String("Versions");
                    writer.StartArray();
                    for (std::list<CloudScriptVersionStatus>::iterator iter = Versions.begin(); iter != Versions.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Versions_member = obj.FindMember("Versions");
                if (Versions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Versions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Versions.push_back(CloudScriptVersionStatus(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetContentListRequest : public PlayFabBaseModel
        {
            AZStd::string Prefix;

            GetContentListRequest() :
                PlayFabBaseModel(),
                Prefix()
            {}

            GetContentListRequest(const GetContentListRequest& src) :
                PlayFabBaseModel(),
                Prefix(src.Prefix)
            {}

            GetContentListRequest(const rapidjson::Value& obj) : GetContentListRequest()
            {
                readFromValue(obj);
            }

            ~GetContentListRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Prefix.length() > 0) {
                    writer.String("Prefix");
                    writer.String(Prefix.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Prefix_member = obj.FindMember("Prefix");
                if (Prefix_member != obj.MemberEnd() && !Prefix_member->value.IsNull()) Prefix = Prefix_member->value.GetString();

                return true;
            }
        };

        struct GetContentListResult : public PlayFabBaseModel
        {
            Int32 ItemCount;
            Uint32 TotalSize;
            std::list<ContentInfo> Contents;

            GetContentListResult() :
                PlayFabBaseModel(),
                ItemCount(0),
                TotalSize(0),
                Contents()
            {}

            GetContentListResult(const GetContentListResult& src) :
                PlayFabBaseModel(),
                ItemCount(src.ItemCount),
                TotalSize(src.TotalSize),
                Contents(src.Contents)
            {}

            GetContentListResult(const rapidjson::Value& obj) : GetContentListResult()
            {
                readFromValue(obj);
            }

            ~GetContentListResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ItemCount");
                writer.Int(ItemCount);
                writer.String("TotalSize");
                writer.Uint(TotalSize);
                if (!Contents.empty()) {
                    writer.String("Contents");
                    writer.StartArray();
                    for (std::list<ContentInfo>::iterator iter = Contents.begin(); iter != Contents.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemCount_member = obj.FindMember("ItemCount");
                if (ItemCount_member != obj.MemberEnd() && !ItemCount_member->value.IsNull()) ItemCount = ItemCount_member->value.GetInt();
                const Value::ConstMemberIterator TotalSize_member = obj.FindMember("TotalSize");
                if (TotalSize_member != obj.MemberEnd() && !TotalSize_member->value.IsNull()) TotalSize = TotalSize_member->value.GetUint();
                const Value::ConstMemberIterator Contents_member = obj.FindMember("Contents");
                if (Contents_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Contents_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Contents.push_back(ContentInfo(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetContentUploadUrlRequest : public PlayFabBaseModel
        {
            AZStd::string Key;
            AZStd::string ContentType;

            GetContentUploadUrlRequest() :
                PlayFabBaseModel(),
                Key(),
                ContentType()
            {}

            GetContentUploadUrlRequest(const GetContentUploadUrlRequest& src) :
                PlayFabBaseModel(),
                Key(src.Key),
                ContentType(src.ContentType)
            {}

            GetContentUploadUrlRequest(const rapidjson::Value& obj) : GetContentUploadUrlRequest()
            {
                readFromValue(obj);
            }

            ~GetContentUploadUrlRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Key");
                writer.String(Key.c_str());
                if (ContentType.length() > 0) {
                    writer.String("ContentType");
                    writer.String(ContentType.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
                if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
                const Value::ConstMemberIterator ContentType_member = obj.FindMember("ContentType");
                if (ContentType_member != obj.MemberEnd() && !ContentType_member->value.IsNull()) ContentType = ContentType_member->value.GetString();

                return true;
            }
        };

        struct GetContentUploadUrlResult : public PlayFabBaseModel
        {
            AZStd::string URL;

            GetContentUploadUrlResult() :
                PlayFabBaseModel(),
                URL()
            {}

            GetContentUploadUrlResult(const GetContentUploadUrlResult& src) :
                PlayFabBaseModel(),
                URL(src.URL)
            {}

            GetContentUploadUrlResult(const rapidjson::Value& obj) : GetContentUploadUrlResult()
            {
                readFromValue(obj);
            }

            ~GetContentUploadUrlResult()
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

        struct GetDataReportRequest : public PlayFabBaseModel
        {
            AZStd::string ReportName;
            Int32 Year;
            Int32 Month;
            Int32 Day;

            GetDataReportRequest() :
                PlayFabBaseModel(),
                ReportName(),
                Year(0),
                Month(0),
                Day(0)
            {}

            GetDataReportRequest(const GetDataReportRequest& src) :
                PlayFabBaseModel(),
                ReportName(src.ReportName),
                Year(src.Year),
                Month(src.Month),
                Day(src.Day)
            {}

            GetDataReportRequest(const rapidjson::Value& obj) : GetDataReportRequest()
            {
                readFromValue(obj);
            }

            ~GetDataReportRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ReportName");
                writer.String(ReportName.c_str());
                writer.String("Year");
                writer.Int(Year);
                writer.String("Month");
                writer.Int(Month);
                writer.String("Day");
                writer.Int(Day);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ReportName_member = obj.FindMember("ReportName");
                if (ReportName_member != obj.MemberEnd() && !ReportName_member->value.IsNull()) ReportName = ReportName_member->value.GetString();
                const Value::ConstMemberIterator Year_member = obj.FindMember("Year");
                if (Year_member != obj.MemberEnd() && !Year_member->value.IsNull()) Year = Year_member->value.GetInt();
                const Value::ConstMemberIterator Month_member = obj.FindMember("Month");
                if (Month_member != obj.MemberEnd() && !Month_member->value.IsNull()) Month = Month_member->value.GetInt();
                const Value::ConstMemberIterator Day_member = obj.FindMember("Day");
                if (Day_member != obj.MemberEnd() && !Day_member->value.IsNull()) Day = Day_member->value.GetInt();

                return true;
            }
        };

        struct GetDataReportResult : public PlayFabBaseModel
        {
            AZStd::string DownloadUrl;

            GetDataReportResult() :
                PlayFabBaseModel(),
                DownloadUrl()
            {}

            GetDataReportResult(const GetDataReportResult& src) :
                PlayFabBaseModel(),
                DownloadUrl(src.DownloadUrl)
            {}

            GetDataReportResult(const rapidjson::Value& obj) : GetDataReportResult()
            {
                readFromValue(obj);
            }

            ~GetDataReportResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (DownloadUrl.length() > 0) {
                    writer.String("DownloadUrl");
                    writer.String(DownloadUrl.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator DownloadUrl_member = obj.FindMember("DownloadUrl");
                if (DownloadUrl_member != obj.MemberEnd() && !DownloadUrl_member->value.IsNull()) DownloadUrl = DownloadUrl_member->value.GetString();

                return true;
            }
        };

        struct GetMatchmakerGameInfoRequest : public PlayFabBaseModel
        {
            AZStd::string LobbyId;

            GetMatchmakerGameInfoRequest() :
                PlayFabBaseModel(),
                LobbyId()
            {}

            GetMatchmakerGameInfoRequest(const GetMatchmakerGameInfoRequest& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId)
            {}

            GetMatchmakerGameInfoRequest(const rapidjson::Value& obj) : GetMatchmakerGameInfoRequest()
            {
                readFromValue(obj);
            }

            ~GetMatchmakerGameInfoRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("LobbyId");
                writer.String(LobbyId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
                if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();

                return true;
            }
        };

        struct GetMatchmakerGameInfoResult : public PlayFabBaseModel
        {
            AZStd::string LobbyId;
            AZStd::string TitleId;
            time_t StartTime;
            OptionalTime EndTime;
            AZStd::string Mode;
            AZStd::string BuildVersion;
            Boxed<Region> pfRegion;
            std::list<AZStd::string> Players;
            AZStd::string ServerAddress;
            Uint32 ServerPort;

            GetMatchmakerGameInfoResult() :
                PlayFabBaseModel(),
                LobbyId(),
                TitleId(),
                StartTime(0),
                EndTime(),
                Mode(),
                BuildVersion(),
                pfRegion(),
                Players(),
                ServerAddress(),
                ServerPort(0)
            {}

            GetMatchmakerGameInfoResult(const GetMatchmakerGameInfoResult& src) :
                PlayFabBaseModel(),
                LobbyId(src.LobbyId),
                TitleId(src.TitleId),
                StartTime(src.StartTime),
                EndTime(src.EndTime),
                Mode(src.Mode),
                BuildVersion(src.BuildVersion),
                pfRegion(src.pfRegion),
                Players(src.Players),
                ServerAddress(src.ServerAddress),
                ServerPort(src.ServerPort)
            {}

            GetMatchmakerGameInfoResult(const rapidjson::Value& obj) : GetMatchmakerGameInfoResult()
            {
                readFromValue(obj);
            }

            ~GetMatchmakerGameInfoResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (LobbyId.length() > 0) {
                    writer.String("LobbyId");
                    writer.String(LobbyId.c_str());
                }
                if (TitleId.length() > 0) {
                    writer.String("TitleId");
                    writer.String(TitleId.c_str());
                }
                writer.String("StartTime");
                writeDatetime(StartTime, writer);
                if (EndTime.notNull()) {
                    writer.String("EndTime");
                    writeDatetime(EndTime, writer);
                }
                if (Mode.length() > 0) {
                    writer.String("Mode");
                    writer.String(Mode.c_str());
                }
                if (BuildVersion.length() > 0) {
                    writer.String("BuildVersion");
                    writer.String(BuildVersion.c_str());
                }
                if (pfRegion.notNull()) {
                    writer.String("Region");
                    writeRegionEnumJSON(pfRegion, writer);
                }
                if (!Players.empty()) {
                    writer.String("Players");
                    writer.StartArray();
                    for (std::list<AZStd::string>::iterator iter = Players.begin(); iter != Players.end(); iter++) {
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (ServerAddress.length() > 0) {
                    writer.String("ServerAddress");
                    writer.String(ServerAddress.c_str());
                }
                writer.String("ServerPort");
                writer.Uint(ServerPort);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator LobbyId_member = obj.FindMember("LobbyId");
                if (LobbyId_member != obj.MemberEnd() && !LobbyId_member->value.IsNull()) LobbyId = LobbyId_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator StartTime_member = obj.FindMember("StartTime");
                if (StartTime_member != obj.MemberEnd() && !StartTime_member->value.IsNull()) StartTime = readDatetime(StartTime_member->value);
                const Value::ConstMemberIterator EndTime_member = obj.FindMember("EndTime");
                if (EndTime_member != obj.MemberEnd() && !EndTime_member->value.IsNull()) EndTime = readDatetime(EndTime_member->value);
                const Value::ConstMemberIterator Mode_member = obj.FindMember("Mode");
                if (Mode_member != obj.MemberEnd() && !Mode_member->value.IsNull()) Mode = Mode_member->value.GetString();
                const Value::ConstMemberIterator BuildVersion_member = obj.FindMember("BuildVersion");
                if (BuildVersion_member != obj.MemberEnd() && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
                const Value::ConstMemberIterator Region_member = obj.FindMember("Region");
                if (Region_member != obj.MemberEnd() && !Region_member->value.IsNull()) pfRegion = readRegionFromValue(Region_member->value);
                const Value::ConstMemberIterator Players_member = obj.FindMember("Players");
                if (Players_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Players_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Players.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator ServerAddress_member = obj.FindMember("ServerAddress");
                if (ServerAddress_member != obj.MemberEnd() && !ServerAddress_member->value.IsNull()) ServerAddress = ServerAddress_member->value.GetString();
                const Value::ConstMemberIterator ServerPort_member = obj.FindMember("ServerPort");
                if (ServerPort_member != obj.MemberEnd() && !ServerPort_member->value.IsNull()) ServerPort = ServerPort_member->value.GetUint();

                return true;
            }
        };

        struct GetMatchmakerGameModesRequest : public PlayFabBaseModel
        {
            AZStd::string BuildVersion;

            GetMatchmakerGameModesRequest() :
                PlayFabBaseModel(),
                BuildVersion()
            {}

            GetMatchmakerGameModesRequest(const GetMatchmakerGameModesRequest& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion)
            {}

            GetMatchmakerGameModesRequest(const rapidjson::Value& obj) : GetMatchmakerGameModesRequest()
            {
                readFromValue(obj);
            }

            ~GetMatchmakerGameModesRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("BuildVersion");
                writer.String(BuildVersion.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildVersion_member = obj.FindMember("BuildVersion");
                if (BuildVersion_member != obj.MemberEnd() && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();

                return true;
            }
        };

        struct GetMatchmakerGameModesResult : public PlayFabBaseModel
        {
            std::list<GameModeInfo> GameModes;

            GetMatchmakerGameModesResult() :
                PlayFabBaseModel(),
                GameModes()
            {}

            GetMatchmakerGameModesResult(const GetMatchmakerGameModesResult& src) :
                PlayFabBaseModel(),
                GameModes(src.GameModes)
            {}

            GetMatchmakerGameModesResult(const rapidjson::Value& obj) : GetMatchmakerGameModesResult()
            {
                readFromValue(obj);
            }

            ~GetMatchmakerGameModesResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!GameModes.empty()) {
                    writer.String("GameModes");
                    writer.StartArray();
                    for (std::list<GameModeInfo>::iterator iter = GameModes.begin(); iter != GameModes.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator GameModes_member = obj.FindMember("GameModes");
                if (GameModes_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = GameModes_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        GameModes.push_back(GameModeInfo(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayerSegmentsResult : public PlayFabBaseModel
        {
            std::list<GetSegmentResult> Segments;

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
                    for (std::list<GetSegmentResult>::iterator iter = Segments.begin(); iter != Segments.end(); iter++) {
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

        struct GetPlayerSharedSecretsRequest : public PlayFabBaseModel
        {

            GetPlayerSharedSecretsRequest() :
                PlayFabBaseModel()
            {}

            GetPlayerSharedSecretsRequest(const GetPlayerSharedSecretsRequest& src) :
                PlayFabBaseModel()
            {}

            GetPlayerSharedSecretsRequest(const rapidjson::Value& obj) : GetPlayerSharedSecretsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerSharedSecretsRequest()
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

        struct SharedSecret : public PlayFabBaseModel
        {
            AZStd::string SecretKey;
            AZStd::string FriendlyName;
            bool Disabled;

            SharedSecret() :
                PlayFabBaseModel(),
                SecretKey(),
                FriendlyName(),
                Disabled(false)
            {}

            SharedSecret(const SharedSecret& src) :
                PlayFabBaseModel(),
                SecretKey(src.SecretKey),
                FriendlyName(src.FriendlyName),
                Disabled(src.Disabled)
            {}

            SharedSecret(const rapidjson::Value& obj) : SharedSecret()
            {
                readFromValue(obj);
            }

            ~SharedSecret()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (SecretKey.length() > 0) {
                    writer.String("SecretKey");
                    writer.String(SecretKey.c_str());
                }
                if (FriendlyName.length() > 0) {
                    writer.String("FriendlyName");
                    writer.String(FriendlyName.c_str());
                }
                writer.String("Disabled");
                writer.Bool(Disabled);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SecretKey_member = obj.FindMember("SecretKey");
                if (SecretKey_member != obj.MemberEnd() && !SecretKey_member->value.IsNull()) SecretKey = SecretKey_member->value.GetString();
                const Value::ConstMemberIterator FriendlyName_member = obj.FindMember("FriendlyName");
                if (FriendlyName_member != obj.MemberEnd() && !FriendlyName_member->value.IsNull()) FriendlyName = FriendlyName_member->value.GetString();
                const Value::ConstMemberIterator Disabled_member = obj.FindMember("Disabled");
                if (Disabled_member != obj.MemberEnd() && !Disabled_member->value.IsNull()) Disabled = Disabled_member->value.GetBool();

                return true;
            }
        };

        struct GetPlayerSharedSecretsResult : public PlayFabBaseModel
        {
            std::list<SharedSecret> SharedSecrets;

            GetPlayerSharedSecretsResult() :
                PlayFabBaseModel(),
                SharedSecrets()
            {}

            GetPlayerSharedSecretsResult(const GetPlayerSharedSecretsResult& src) :
                PlayFabBaseModel(),
                SharedSecrets(src.SharedSecrets)
            {}

            GetPlayerSharedSecretsResult(const rapidjson::Value& obj) : GetPlayerSharedSecretsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerSharedSecretsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!SharedSecrets.empty()) {
                    writer.String("SharedSecrets");
                    writer.StartArray();
                    for (std::list<SharedSecret>::iterator iter = SharedSecrets.begin(); iter != SharedSecrets.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SharedSecrets_member = obj.FindMember("SharedSecrets");
                if (SharedSecrets_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = SharedSecrets_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        SharedSecrets.push_back(SharedSecret(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayersInSegmentRequest : public PlayFabBaseModel
        {
            AZStd::string SegmentId;
            OptionalUint32 SecondsToLive;
            OptionalUint32 MaxBatchSize;
            AZStd::string ContinuationToken;

            GetPlayersInSegmentRequest() :
                PlayFabBaseModel(),
                SegmentId(),
                SecondsToLive(),
                MaxBatchSize(),
                ContinuationToken()
            {}

            GetPlayersInSegmentRequest(const GetPlayersInSegmentRequest& src) :
                PlayFabBaseModel(),
                SegmentId(src.SegmentId),
                SecondsToLive(src.SecondsToLive),
                MaxBatchSize(src.MaxBatchSize),
                ContinuationToken(src.ContinuationToken)
            {}

            GetPlayersInSegmentRequest(const rapidjson::Value& obj) : GetPlayersInSegmentRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayersInSegmentRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("SegmentId");
                writer.String(SegmentId.c_str());
                if (SecondsToLive.notNull()) {
                    writer.String("SecondsToLive");
                    writer.Uint(SecondsToLive);
                }
                if (MaxBatchSize.notNull()) {
                    writer.String("MaxBatchSize");
                    writer.Uint(MaxBatchSize);
                }
                if (ContinuationToken.length() > 0) {
                    writer.String("ContinuationToken");
                    writer.String(ContinuationToken.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SegmentId_member = obj.FindMember("SegmentId");
                if (SegmentId_member != obj.MemberEnd() && !SegmentId_member->value.IsNull()) SegmentId = SegmentId_member->value.GetString();
                const Value::ConstMemberIterator SecondsToLive_member = obj.FindMember("SecondsToLive");
                if (SecondsToLive_member != obj.MemberEnd() && !SecondsToLive_member->value.IsNull()) SecondsToLive = SecondsToLive_member->value.GetUint();
                const Value::ConstMemberIterator MaxBatchSize_member = obj.FindMember("MaxBatchSize");
                if (MaxBatchSize_member != obj.MemberEnd() && !MaxBatchSize_member->value.IsNull()) MaxBatchSize = MaxBatchSize_member->value.GetUint();
                const Value::ConstMemberIterator ContinuationToken_member = obj.FindMember("ContinuationToken");
                if (ContinuationToken_member != obj.MemberEnd() && !ContinuationToken_member->value.IsNull()) ContinuationToken = ContinuationToken_member->value.GetString();

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

            static std::map<const char *, LoginIdentityProvider, PlayFabServerSdk::StringCompare> _LoginIdentityProviderMap;
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

        struct PlayerLocation : public PlayFabBaseModel
        {
            ContinentCode pfContinentCode;
            CountryCode pfCountryCode;
            AZStd::string City;
            OptionalDouble Latitude;
            OptionalDouble Longitude;

            PlayerLocation() :
                PlayFabBaseModel(),
                pfContinentCode(),
                pfCountryCode(),
                City(),
                Latitude(),
                Longitude()
            {}

            PlayerLocation(const PlayerLocation& src) :
                PlayFabBaseModel(),
                pfContinentCode(src.pfContinentCode),
                pfCountryCode(src.pfCountryCode),
                City(src.City),
                Latitude(src.Latitude),
                Longitude(src.Longitude)
            {}

            PlayerLocation(const rapidjson::Value& obj) : PlayerLocation()
            {
                readFromValue(obj);
            }

            ~PlayerLocation()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ContinentCode");
                writeContinentCodeEnumJSON(pfContinentCode, writer);
                writer.String("CountryCode");
                writeCountryCodeEnumJSON(pfCountryCode, writer);
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

            static std::map<const char *, PushNotificationPlatform, PlayFabServerSdk::StringCompare> _PushNotificationPlatformMap;
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

        struct PushNotificationRegistration : public PlayFabBaseModel
        {
            Boxed<PushNotificationPlatform> Platform;
            AZStd::string NotificationEndpointARN;

            PushNotificationRegistration() :
                PlayFabBaseModel(),
                Platform(),
                NotificationEndpointARN()
            {}

            PushNotificationRegistration(const PushNotificationRegistration& src) :
                PlayFabBaseModel(),
                Platform(src.Platform),
                NotificationEndpointARN(src.NotificationEndpointARN)
            {}

            PushNotificationRegistration(const rapidjson::Value& obj) : PushNotificationRegistration()
            {
                readFromValue(obj);
            }

            ~PushNotificationRegistration()
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

        struct PlayerLinkedAccount : public PlayFabBaseModel
        {
            Boxed<LoginIdentityProvider> Platform;
            AZStd::string PlatformUserId;
            AZStd::string Username;
            AZStd::string Email;

            PlayerLinkedAccount() :
                PlayFabBaseModel(),
                Platform(),
                PlatformUserId(),
                Username(),
                Email()
            {}

            PlayerLinkedAccount(const PlayerLinkedAccount& src) :
                PlayFabBaseModel(),
                Platform(src.Platform),
                PlatformUserId(src.PlatformUserId),
                Username(src.Username),
                Email(src.Email)
            {}

            PlayerLinkedAccount(const rapidjson::Value& obj) : PlayerLinkedAccount()
            {
                readFromValue(obj);
            }

            ~PlayerLinkedAccount()
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

        struct PlayerStatistic : public PlayFabBaseModel
        {
            AZStd::string Id;
            Int32 StatisticVersion;
            Int32 StatisticValue;
            AZStd::string Name;

            PlayerStatistic() :
                PlayFabBaseModel(),
                Id(),
                StatisticVersion(0),
                StatisticValue(0),
                Name()
            {}

            PlayerStatistic(const PlayerStatistic& src) :
                PlayFabBaseModel(),
                Id(src.Id),
                StatisticVersion(src.StatisticVersion),
                StatisticValue(src.StatisticValue),
                Name(src.Name)
            {}

            PlayerStatistic(const rapidjson::Value& obj) : PlayerStatistic()
            {
                readFromValue(obj);
            }

            ~PlayerStatistic()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Id.length() > 0) {
                    writer.String("Id");
                    writer.String(Id.c_str());
                }
                writer.String("StatisticVersion");
                writer.Int(StatisticVersion);
                writer.String("StatisticValue");
                writer.Int(StatisticValue);
                if (Name.length() > 0) {
                    writer.String("Name");
                    writer.String(Name.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Id_member = obj.FindMember("Id");
                if (Id_member != obj.MemberEnd() && !Id_member->value.IsNull()) Id = Id_member->value.GetString();
                const Value::ConstMemberIterator StatisticVersion_member = obj.FindMember("StatisticVersion");
                if (StatisticVersion_member != obj.MemberEnd() && !StatisticVersion_member->value.IsNull()) StatisticVersion = StatisticVersion_member->value.GetInt();
                const Value::ConstMemberIterator StatisticValue_member = obj.FindMember("StatisticValue");
                if (StatisticValue_member != obj.MemberEnd() && !StatisticValue_member->value.IsNull()) StatisticValue = StatisticValue_member->value.GetInt();
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();

                return true;
            }
        };

        struct PlayerProfile : public PlayFabBaseModel
        {
            AZStd::string PlayerId;
            AZStd::string TitleId;
            AZStd::string DisplayName;
            AZStd::string PublisherId;
            Boxed<LoginIdentityProvider> Origination;
            OptionalTime Created;
            OptionalTime LastLogin;
            OptionalTime BannedUntil;
            AZStd::string AvatarUrl;
            std::map<AZStd::string, Int32> Statistics;
            OptionalUint32 TotalValueToDateInUSD;
            std::map<AZStd::string, Uint32> ValuesToDate;
            std::list<AZStd::string> Tags;
            std::map<AZStd::string, PlayerLocation> Locations;
            std::map<AZStd::string, Int32> VirtualCurrencyBalances;
            std::list<AdCampaignAttribution> AdCampaignAttributions;
            std::list<PushNotificationRegistration> PushNotificationRegistrations;
            std::list<PlayerLinkedAccount> LinkedAccounts;
            std::list<PlayerStatistic> PlayerStatistics;
            std::list<ContactEmailInfo> ContactEmailAddresses;

            PlayerProfile() :
                PlayFabBaseModel(),
                PlayerId(),
                TitleId(),
                DisplayName(),
                PublisherId(),
                Origination(),
                Created(),
                LastLogin(),
                BannedUntil(),
                AvatarUrl(),
                Statistics(),
                TotalValueToDateInUSD(),
                ValuesToDate(),
                Tags(),
                Locations(),
                VirtualCurrencyBalances(),
                AdCampaignAttributions(),
                PushNotificationRegistrations(),
                LinkedAccounts(),
                PlayerStatistics(),
                ContactEmailAddresses()
            {}

            PlayerProfile(const PlayerProfile& src) :
                PlayFabBaseModel(),
                PlayerId(src.PlayerId),
                TitleId(src.TitleId),
                DisplayName(src.DisplayName),
                PublisherId(src.PublisherId),
                Origination(src.Origination),
                Created(src.Created),
                LastLogin(src.LastLogin),
                BannedUntil(src.BannedUntil),
                AvatarUrl(src.AvatarUrl),
                Statistics(src.Statistics),
                TotalValueToDateInUSD(src.TotalValueToDateInUSD),
                ValuesToDate(src.ValuesToDate),
                Tags(src.Tags),
                Locations(src.Locations),
                VirtualCurrencyBalances(src.VirtualCurrencyBalances),
                AdCampaignAttributions(src.AdCampaignAttributions),
                PushNotificationRegistrations(src.PushNotificationRegistrations),
                LinkedAccounts(src.LinkedAccounts),
                PlayerStatistics(src.PlayerStatistics),
                ContactEmailAddresses(src.ContactEmailAddresses)
            {}

            PlayerProfile(const rapidjson::Value& obj) : PlayerProfile()
            {
                readFromValue(obj);
            }

            ~PlayerProfile()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayerId.length() > 0) {
                    writer.String("PlayerId");
                    writer.String(PlayerId.c_str());
                }
                if (TitleId.length() > 0) {
                    writer.String("TitleId");
                    writer.String(TitleId.c_str());
                }
                if (DisplayName.length() > 0) {
                    writer.String("DisplayName");
                    writer.String(DisplayName.c_str());
                }
                if (PublisherId.length() > 0) {
                    writer.String("PublisherId");
                    writer.String(PublisherId.c_str());
                }
                if (Origination.notNull()) {
                    writer.String("Origination");
                    writeLoginIdentityProviderEnumJSON(Origination, writer);
                }
                if (Created.notNull()) {
                    writer.String("Created");
                    writeDatetime(Created, writer);
                }
                if (LastLogin.notNull()) {
                    writer.String("LastLogin");
                    writeDatetime(LastLogin, writer);
                }
                if (BannedUntil.notNull()) {
                    writer.String("BannedUntil");
                    writeDatetime(BannedUntil, writer);
                }
                if (AvatarUrl.length() > 0) {
                    writer.String("AvatarUrl");
                    writer.String(AvatarUrl.c_str());
                }
                if (!Statistics.empty()) {
                    writer.String("Statistics");
                    writer.StartObject();
                    for (std::map<AZStd::string, Int32>::iterator iter = Statistics.begin(); iter != Statistics.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Int(iter->second);
                    }
                    writer.EndObject();
                }
                if (TotalValueToDateInUSD.notNull()) {
                    writer.String("TotalValueToDateInUSD");
                    writer.Uint(TotalValueToDateInUSD);
                }
                if (!ValuesToDate.empty()) {
                    writer.String("ValuesToDate");
                    writer.StartObject();
                    for (std::map<AZStd::string, Uint32>::iterator iter = ValuesToDate.begin(); iter != ValuesToDate.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                if (!Tags.empty()) {
                    writer.String("Tags");
                    writer.StartArray();
                    for (std::list<AZStd::string>::iterator iter = Tags.begin(); iter != Tags.end(); iter++) {
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!Locations.empty()) {
                    writer.String("Locations");
                    writer.StartObject();
                    for (std::map<AZStd::string, PlayerLocation>::iterator iter = Locations.begin(); iter != Locations.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                if (!VirtualCurrencyBalances.empty()) {
                    writer.String("VirtualCurrencyBalances");
                    writer.StartObject();
                    for (std::map<AZStd::string, Int32>::iterator iter = VirtualCurrencyBalances.begin(); iter != VirtualCurrencyBalances.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Int(iter->second);
                    }
                    writer.EndObject();
                }
                if (!AdCampaignAttributions.empty()) {
                    writer.String("AdCampaignAttributions");
                    writer.StartArray();
                    for (std::list<AdCampaignAttribution>::iterator iter = AdCampaignAttributions.begin(); iter != AdCampaignAttributions.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!PushNotificationRegistrations.empty()) {
                    writer.String("PushNotificationRegistrations");
                    writer.StartArray();
                    for (std::list<PushNotificationRegistration>::iterator iter = PushNotificationRegistrations.begin(); iter != PushNotificationRegistrations.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!LinkedAccounts.empty()) {
                    writer.String("LinkedAccounts");
                    writer.StartArray();
                    for (std::list<PlayerLinkedAccount>::iterator iter = LinkedAccounts.begin(); iter != LinkedAccounts.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!PlayerStatistics.empty()) {
                    writer.String("PlayerStatistics");
                    writer.StartArray();
                    for (std::list<PlayerStatistic>::iterator iter = PlayerStatistics.begin(); iter != PlayerStatistics.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!ContactEmailAddresses.empty()) {
                    writer.String("ContactEmailAddresses");
                    writer.StartArray();
                    for (std::list<ContactEmailInfo>::iterator iter = ContactEmailAddresses.begin(); iter != ContactEmailAddresses.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayerId_member = obj.FindMember("PlayerId");
                if (PlayerId_member != obj.MemberEnd() && !PlayerId_member->value.IsNull()) PlayerId = PlayerId_member->value.GetString();
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();
                const Value::ConstMemberIterator PublisherId_member = obj.FindMember("PublisherId");
                if (PublisherId_member != obj.MemberEnd() && !PublisherId_member->value.IsNull()) PublisherId = PublisherId_member->value.GetString();
                const Value::ConstMemberIterator Origination_member = obj.FindMember("Origination");
                if (Origination_member != obj.MemberEnd() && !Origination_member->value.IsNull()) Origination = readLoginIdentityProviderFromValue(Origination_member->value);
                const Value::ConstMemberIterator Created_member = obj.FindMember("Created");
                if (Created_member != obj.MemberEnd() && !Created_member->value.IsNull()) Created = readDatetime(Created_member->value);
                const Value::ConstMemberIterator LastLogin_member = obj.FindMember("LastLogin");
                if (LastLogin_member != obj.MemberEnd() && !LastLogin_member->value.IsNull()) LastLogin = readDatetime(LastLogin_member->value);
                const Value::ConstMemberIterator BannedUntil_member = obj.FindMember("BannedUntil");
                if (BannedUntil_member != obj.MemberEnd() && !BannedUntil_member->value.IsNull()) BannedUntil = readDatetime(BannedUntil_member->value);
                const Value::ConstMemberIterator AvatarUrl_member = obj.FindMember("AvatarUrl");
                if (AvatarUrl_member != obj.MemberEnd() && !AvatarUrl_member->value.IsNull()) AvatarUrl = AvatarUrl_member->value.GetString();
                const Value::ConstMemberIterator Statistics_member = obj.FindMember("Statistics");
                if (Statistics_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Statistics_member->value.MemberBegin(); iter != Statistics_member->value.MemberEnd(); ++iter) {
                        Statistics[iter->name.GetString()] = iter->value.GetInt();
                    }
                }
                const Value::ConstMemberIterator TotalValueToDateInUSD_member = obj.FindMember("TotalValueToDateInUSD");
                if (TotalValueToDateInUSD_member != obj.MemberEnd() && !TotalValueToDateInUSD_member->value.IsNull()) TotalValueToDateInUSD = TotalValueToDateInUSD_member->value.GetUint();
                const Value::ConstMemberIterator ValuesToDate_member = obj.FindMember("ValuesToDate");
                if (ValuesToDate_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = ValuesToDate_member->value.MemberBegin(); iter != ValuesToDate_member->value.MemberEnd(); ++iter) {
                        ValuesToDate[iter->name.GetString()] = iter->value.GetUint();
                    }
                }
                const Value::ConstMemberIterator Tags_member = obj.FindMember("Tags");
                if (Tags_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Tags_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Tags.push_back(memberList[i].GetString());
                    }
                }
                const Value::ConstMemberIterator Locations_member = obj.FindMember("Locations");
                if (Locations_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Locations_member->value.MemberBegin(); iter != Locations_member->value.MemberEnd(); ++iter) {
                        Locations[iter->name.GetString()] = PlayerLocation(iter->value);
                    }
                }
                const Value::ConstMemberIterator VirtualCurrencyBalances_member = obj.FindMember("VirtualCurrencyBalances");
                if (VirtualCurrencyBalances_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = VirtualCurrencyBalances_member->value.MemberBegin(); iter != VirtualCurrencyBalances_member->value.MemberEnd(); ++iter) {
                        VirtualCurrencyBalances[iter->name.GetString()] = iter->value.GetInt();
                    }
                }
                const Value::ConstMemberIterator AdCampaignAttributions_member = obj.FindMember("AdCampaignAttributions");
                if (AdCampaignAttributions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = AdCampaignAttributions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        AdCampaignAttributions.push_back(AdCampaignAttribution(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator PushNotificationRegistrations_member = obj.FindMember("PushNotificationRegistrations");
                if (PushNotificationRegistrations_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = PushNotificationRegistrations_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        PushNotificationRegistrations.push_back(PushNotificationRegistration(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator LinkedAccounts_member = obj.FindMember("LinkedAccounts");
                if (LinkedAccounts_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = LinkedAccounts_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        LinkedAccounts.push_back(PlayerLinkedAccount(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator PlayerStatistics_member = obj.FindMember("PlayerStatistics");
                if (PlayerStatistics_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = PlayerStatistics_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        PlayerStatistics.push_back(PlayerStatistic(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator ContactEmailAddresses_member = obj.FindMember("ContactEmailAddresses");
                if (ContactEmailAddresses_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = ContactEmailAddresses_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        ContactEmailAddresses.push_back(ContactEmailInfo(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayersInSegmentResult : public PlayFabBaseModel
        {
            Int32 ProfilesInSegment;
            AZStd::string ContinuationToken;
            std::list<PlayerProfile> PlayerProfiles;

            GetPlayersInSegmentResult() :
                PlayFabBaseModel(),
                ProfilesInSegment(0),
                ContinuationToken(),
                PlayerProfiles()
            {}

            GetPlayersInSegmentResult(const GetPlayersInSegmentResult& src) :
                PlayFabBaseModel(),
                ProfilesInSegment(src.ProfilesInSegment),
                ContinuationToken(src.ContinuationToken),
                PlayerProfiles(src.PlayerProfiles)
            {}

            GetPlayersInSegmentResult(const rapidjson::Value& obj) : GetPlayersInSegmentResult()
            {
                readFromValue(obj);
            }

            ~GetPlayersInSegmentResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ProfilesInSegment");
                writer.Int(ProfilesInSegment);
                if (ContinuationToken.length() > 0) {
                    writer.String("ContinuationToken");
                    writer.String(ContinuationToken.c_str());
                }
                if (!PlayerProfiles.empty()) {
                    writer.String("PlayerProfiles");
                    writer.StartArray();
                    for (std::list<PlayerProfile>::iterator iter = PlayerProfiles.begin(); iter != PlayerProfiles.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ProfilesInSegment_member = obj.FindMember("ProfilesInSegment");
                if (ProfilesInSegment_member != obj.MemberEnd() && !ProfilesInSegment_member->value.IsNull()) ProfilesInSegment = ProfilesInSegment_member->value.GetInt();
                const Value::ConstMemberIterator ContinuationToken_member = obj.FindMember("ContinuationToken");
                if (ContinuationToken_member != obj.MemberEnd() && !ContinuationToken_member->value.IsNull()) ContinuationToken = ContinuationToken_member->value.GetString();
                const Value::ConstMemberIterator PlayerProfiles_member = obj.FindMember("PlayerProfiles");
                if (PlayerProfiles_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = PlayerProfiles_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        PlayerProfiles.push_back(PlayerProfile(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayersSegmentsRequest : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;

            GetPlayersSegmentsRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            GetPlayersSegmentsRequest(const GetPlayersSegmentsRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            GetPlayersSegmentsRequest(const rapidjson::Value& obj) : GetPlayersSegmentsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayersSegmentsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct GetPlayerStatisticDefinitionsRequest : public PlayFabBaseModel
        {

            GetPlayerStatisticDefinitionsRequest() :
                PlayFabBaseModel()
            {}

            GetPlayerStatisticDefinitionsRequest(const GetPlayerStatisticDefinitionsRequest& src) :
                PlayFabBaseModel()
            {}

            GetPlayerStatisticDefinitionsRequest(const rapidjson::Value& obj) : GetPlayerStatisticDefinitionsRequest()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticDefinitionsRequest()
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

        struct GetPlayerStatisticDefinitionsResult : public PlayFabBaseModel
        {
            std::list<PlayerStatisticDefinition> Statistics;

            GetPlayerStatisticDefinitionsResult() :
                PlayFabBaseModel(),
                Statistics()
            {}

            GetPlayerStatisticDefinitionsResult(const GetPlayerStatisticDefinitionsResult& src) :
                PlayFabBaseModel(),
                Statistics(src.Statistics)
            {}

            GetPlayerStatisticDefinitionsResult(const rapidjson::Value& obj) : GetPlayerStatisticDefinitionsResult()
            {
                readFromValue(obj);
            }

            ~GetPlayerStatisticDefinitionsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Statistics.empty()) {
                    writer.String("Statistics");
                    writer.StartArray();
                    for (std::list<PlayerStatisticDefinition>::iterator iter = Statistics.begin(); iter != Statistics.end(); iter++) {
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
                        Statistics.push_back(PlayerStatisticDefinition(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPlayerStatisticVersionsRequest : public PlayFabBaseModel
        {
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

        enum StatisticVersionStatus
        {
            StatisticVersionStatusActive,
            StatisticVersionStatusSnapshotPending,
            StatisticVersionStatusSnapshot,
            StatisticVersionStatusArchivalPending,
            StatisticVersionStatusArchived
        };

        inline void writeStatisticVersionStatusEnumJSON(StatisticVersionStatus enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case StatisticVersionStatusActive: writer.String("Active"); break;
            case StatisticVersionStatusSnapshotPending: writer.String("SnapshotPending"); break;
            case StatisticVersionStatusSnapshot: writer.String("Snapshot"); break;
            case StatisticVersionStatusArchivalPending: writer.String("ArchivalPending"); break;
            case StatisticVersionStatusArchived: writer.String("Archived"); break;

            }
        }

        inline StatisticVersionStatus readStatisticVersionStatusFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<StatisticVersionStatus>(obj.GetInt());

            static std::map<const char *, StatisticVersionStatus, PlayFabServerSdk::StringCompare> _StatisticVersionStatusMap;
            if (_StatisticVersionStatusMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _StatisticVersionStatusMap["Active"] = StatisticVersionStatusActive;
                _StatisticVersionStatusMap["SnapshotPending"] = StatisticVersionStatusSnapshotPending;
                _StatisticVersionStatusMap["Snapshot"] = StatisticVersionStatusSnapshot;
                _StatisticVersionStatusMap["ArchivalPending"] = StatisticVersionStatusArchivalPending;
                _StatisticVersionStatusMap["Archived"] = StatisticVersionStatusArchived;

            }

            auto output = _StatisticVersionStatusMap.find(obj.GetString());
            if (output != _StatisticVersionStatusMap.end())
                return output->second;

            return StatisticVersionStatusActive; // Basically critical fail
        }

        struct PlayerStatisticVersion : public PlayFabBaseModel
        {
            AZStd::string StatisticName;
            Uint32 Version;
            OptionalTime ScheduledActivationTime;
            time_t ActivationTime;
            OptionalTime ScheduledDeactivationTime;
            OptionalTime DeactivationTime;
            Boxed<StatisticVersionStatus> Status;
            AZStd::string ArchiveDownloadUrl;

            PlayerStatisticVersion() :
                PlayFabBaseModel(),
                StatisticName(),
                Version(0),
                ScheduledActivationTime(),
                ActivationTime(0),
                ScheduledDeactivationTime(),
                DeactivationTime(),
                Status(),
                ArchiveDownloadUrl()
            {}

            PlayerStatisticVersion(const PlayerStatisticVersion& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                Version(src.Version),
                ScheduledActivationTime(src.ScheduledActivationTime),
                ActivationTime(src.ActivationTime),
                ScheduledDeactivationTime(src.ScheduledDeactivationTime),
                DeactivationTime(src.DeactivationTime),
                Status(src.Status),
                ArchiveDownloadUrl(src.ArchiveDownloadUrl)
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
                if (Status.notNull()) {
                    writer.String("Status");
                    writeStatisticVersionStatusEnumJSON(Status, writer);
                }
                if (ArchiveDownloadUrl.length() > 0) {
                    writer.String("ArchiveDownloadUrl");
                    writer.String(ArchiveDownloadUrl.c_str());
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
                const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
                if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readStatisticVersionStatusFromValue(Status_member->value);
                const Value::ConstMemberIterator ArchiveDownloadUrl_member = obj.FindMember("ArchiveDownloadUrl");
                if (ArchiveDownloadUrl_member != obj.MemberEnd() && !ArchiveDownloadUrl_member->value.IsNull()) ArchiveDownloadUrl = ArchiveDownloadUrl_member->value.GetString();

                return true;
            }
        };

        struct GetPlayerStatisticVersionsResult : public PlayFabBaseModel
        {
            std::list<PlayerStatisticVersion> StatisticVersions;

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
                    for (std::list<PlayerStatisticVersion>::iterator iter = StatisticVersions.begin(); iter != StatisticVersions.end(); iter++) {
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
            AZStd::string PlayFabId;
            std::list<AZStd::string> Tags;

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
                for (std::list<AZStd::string>::iterator iter = Tags.begin(); iter != Tags.end(); iter++) {
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

        struct GetPolicyRequest : public PlayFabBaseModel
        {
            AZStd::string PolicyName;

            GetPolicyRequest() :
                PlayFabBaseModel(),
                PolicyName()
            {}

            GetPolicyRequest(const GetPolicyRequest& src) :
                PlayFabBaseModel(),
                PolicyName(src.PolicyName)
            {}

            GetPolicyRequest(const rapidjson::Value& obj) : GetPolicyRequest()
            {
                readFromValue(obj);
            }

            ~GetPolicyRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PolicyName.length() > 0) {
                    writer.String("PolicyName");
                    writer.String(PolicyName.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PolicyName_member = obj.FindMember("PolicyName");
                if (PolicyName_member != obj.MemberEnd() && !PolicyName_member->value.IsNull()) PolicyName = PolicyName_member->value.GetString();

                return true;
            }
        };

        struct PermissionStatement : public PlayFabBaseModel
        {
            AZStd::string Resource;
            AZStd::string Action;
            EffectType Effect;
            AZStd::string Principal;
            AZStd::string Comment;
            ApiCondition* ApiConditions;

            PermissionStatement() :
                PlayFabBaseModel(),
                Resource(),
                Action(),
                Effect(),
                Principal(),
                Comment(),
                ApiConditions(nullptr)
            {}

            PermissionStatement(const PermissionStatement& src) :
                PlayFabBaseModel(),
                Resource(src.Resource),
                Action(src.Action),
                Effect(src.Effect),
                Principal(src.Principal),
                Comment(src.Comment),
                ApiConditions(src.ApiConditions ? new ApiCondition(*src.ApiConditions) : nullptr)
            {}

            PermissionStatement(const rapidjson::Value& obj) : PermissionStatement()
            {
                readFromValue(obj);
            }

            ~PermissionStatement()
            {
                if (ApiConditions != nullptr) delete ApiConditions;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Resource");
                writer.String(Resource.c_str());
                writer.String("Action");
                writer.String(Action.c_str());
                writer.String("Effect");
                writeEffectTypeEnumJSON(Effect, writer);
                writer.String("Principal");
                writer.String(Principal.c_str());
                if (Comment.length() > 0) {
                    writer.String("Comment");
                    writer.String(Comment.c_str());
                }
                if (ApiConditions != nullptr) {
                    writer.String("ApiConditions");
                    ApiConditions->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Resource_member = obj.FindMember("Resource");
                if (Resource_member != obj.MemberEnd() && !Resource_member->value.IsNull()) Resource = Resource_member->value.GetString();
                const Value::ConstMemberIterator Action_member = obj.FindMember("Action");
                if (Action_member != obj.MemberEnd() && !Action_member->value.IsNull()) Action = Action_member->value.GetString();
                const Value::ConstMemberIterator Effect_member = obj.FindMember("Effect");
                if (Effect_member != obj.MemberEnd() && !Effect_member->value.IsNull()) Effect = readEffectTypeFromValue(Effect_member->value);
                const Value::ConstMemberIterator Principal_member = obj.FindMember("Principal");
                if (Principal_member != obj.MemberEnd() && !Principal_member->value.IsNull()) Principal = Principal_member->value.GetString();
                const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
                if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
                const Value::ConstMemberIterator ApiConditions_member = obj.FindMember("ApiConditions");
                if (ApiConditions_member != obj.MemberEnd() && !ApiConditions_member->value.IsNull()) ApiConditions = new ApiCondition(ApiConditions_member->value);

                return true;
            }
        };

        struct GetPolicyResponse : public PlayFabBaseModel
        {
            AZStd::string PolicyName;
            std::list<PermissionStatement> Statements;

            GetPolicyResponse() :
                PlayFabBaseModel(),
                PolicyName(),
                Statements()
            {}

            GetPolicyResponse(const GetPolicyResponse& src) :
                PlayFabBaseModel(),
                PolicyName(src.PolicyName),
                Statements(src.Statements)
            {}

            GetPolicyResponse(const rapidjson::Value& obj) : GetPolicyResponse()
            {
                readFromValue(obj);
            }

            ~GetPolicyResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PolicyName.length() > 0) {
                    writer.String("PolicyName");
                    writer.String(PolicyName.c_str());
                }
                if (!Statements.empty()) {
                    writer.String("Statements");
                    writer.StartArray();
                    for (std::list<PermissionStatement>::iterator iter = Statements.begin(); iter != Statements.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PolicyName_member = obj.FindMember("PolicyName");
                if (PolicyName_member != obj.MemberEnd() && !PolicyName_member->value.IsNull()) PolicyName = PolicyName_member->value.GetString();
                const Value::ConstMemberIterator Statements_member = obj.FindMember("Statements");
                if (Statements_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Statements_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Statements.push_back(PermissionStatement(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetPublisherDataRequest : public PlayFabBaseModel
        {
            std::list<AZStd::string> Keys;

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
                for (std::list<AZStd::string>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
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
            std::map<AZStd::string, AZStd::string> Data;

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
                    for (std::map<AZStd::string, AZStd::string>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
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

        struct GetRandomResultTablesRequest : public PlayFabBaseModel
        {
            AZStd::string CatalogVersion;

            GetRandomResultTablesRequest() :
                PlayFabBaseModel(),
                CatalogVersion()
            {}

            GetRandomResultTablesRequest(const GetRandomResultTablesRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion)
            {}

            GetRandomResultTablesRequest(const rapidjson::Value& obj) : GetRandomResultTablesRequest()
            {
                readFromValue(obj);
            }

            ~GetRandomResultTablesRequest()
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

        enum ResultTableNodeType
        {
            ResultTableNodeTypeItemId,
            ResultTableNodeTypeTableId
        };

        inline void writeResultTableNodeTypeEnumJSON(ResultTableNodeType enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case ResultTableNodeTypeItemId: writer.String("ItemId"); break;
            case ResultTableNodeTypeTableId: writer.String("TableId"); break;

            }
        }

        inline ResultTableNodeType readResultTableNodeTypeFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<ResultTableNodeType>(obj.GetInt());

            static std::map<const char *, ResultTableNodeType, PlayFabServerSdk::StringCompare> _ResultTableNodeTypeMap;
            if (_ResultTableNodeTypeMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _ResultTableNodeTypeMap["ItemId"] = ResultTableNodeTypeItemId;
                _ResultTableNodeTypeMap["TableId"] = ResultTableNodeTypeTableId;

            }

            auto output = _ResultTableNodeTypeMap.find(obj.GetString());
            if (output != _ResultTableNodeTypeMap.end())
                return output->second;

            return ResultTableNodeTypeItemId; // Basically critical fail
        }

        struct ResultTableNode : public PlayFabBaseModel
        {
            ResultTableNodeType ResultItemType;
            AZStd::string ResultItem;
            Int32 Weight;

            ResultTableNode() :
                PlayFabBaseModel(),
                ResultItemType(),
                ResultItem(),
                Weight(0)
            {}

            ResultTableNode(const ResultTableNode& src) :
                PlayFabBaseModel(),
                ResultItemType(src.ResultItemType),
                ResultItem(src.ResultItem),
                Weight(src.Weight)
            {}

            ResultTableNode(const rapidjson::Value& obj) : ResultTableNode()
            {
                readFromValue(obj);
            }

            ~ResultTableNode()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("ResultItemType");
                writeResultTableNodeTypeEnumJSON(ResultItemType, writer);
                writer.String("ResultItem");
                writer.String(ResultItem.c_str());
                writer.String("Weight");
                writer.Int(Weight);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ResultItemType_member = obj.FindMember("ResultItemType");
                if (ResultItemType_member != obj.MemberEnd() && !ResultItemType_member->value.IsNull()) ResultItemType = readResultTableNodeTypeFromValue(ResultItemType_member->value);
                const Value::ConstMemberIterator ResultItem_member = obj.FindMember("ResultItem");
                if (ResultItem_member != obj.MemberEnd() && !ResultItem_member->value.IsNull()) ResultItem = ResultItem_member->value.GetString();
                const Value::ConstMemberIterator Weight_member = obj.FindMember("Weight");
                if (Weight_member != obj.MemberEnd() && !Weight_member->value.IsNull()) Weight = Weight_member->value.GetInt();

                return true;
            }
        };

        struct RandomResultTableListing : public PlayFabBaseModel
        {
            AZStd::string CatalogVersion;
            AZStd::string TableId;
            std::list<ResultTableNode> Nodes;

            RandomResultTableListing() :
                PlayFabBaseModel(),
                CatalogVersion(),
                TableId(),
                Nodes()
            {}

            RandomResultTableListing(const RandomResultTableListing& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                TableId(src.TableId),
                Nodes(src.Nodes)
            {}

            RandomResultTableListing(const rapidjson::Value& obj) : RandomResultTableListing()
            {
                readFromValue(obj);
            }

            ~RandomResultTableListing()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                writer.String("TableId");
                writer.String(TableId.c_str());
                writer.String("Nodes");
                writer.StartArray();
                for (std::list<ResultTableNode>::iterator iter = Nodes.begin(); iter != Nodes.end(); iter++) {
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator TableId_member = obj.FindMember("TableId");
                if (TableId_member != obj.MemberEnd() && !TableId_member->value.IsNull()) TableId = TableId_member->value.GetString();
                const Value::ConstMemberIterator Nodes_member = obj.FindMember("Nodes");
                if (Nodes_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Nodes_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Nodes.push_back(ResultTableNode(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetRandomResultTablesResult : public PlayFabBaseModel
        {
            std::map<AZStd::string, RandomResultTableListing> Tables;

            GetRandomResultTablesResult() :
                PlayFabBaseModel(),
                Tables()
            {}

            GetRandomResultTablesResult(const GetRandomResultTablesResult& src) :
                PlayFabBaseModel(),
                Tables(src.Tables)
            {}

            GetRandomResultTablesResult(const rapidjson::Value& obj) : GetRandomResultTablesResult()
            {
                readFromValue(obj);
            }

            ~GetRandomResultTablesResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Tables.empty()) {
                    writer.String("Tables");
                    writer.StartObject();
                    for (std::map<AZStd::string, RandomResultTableListing>::iterator iter = Tables.begin(); iter != Tables.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Tables_member = obj.FindMember("Tables");
                if (Tables_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Tables_member->value.MemberBegin(); iter != Tables_member->value.MemberEnd(); ++iter) {
                        Tables[iter->name.GetString()] = RandomResultTableListing(iter->value);
                    }
                }

                return true;
            }
        };

        struct GetServerBuildInfoRequest : public PlayFabBaseModel
        {
            AZStd::string BuildId;

            GetServerBuildInfoRequest() :
                PlayFabBaseModel(),
                BuildId()
            {}

            GetServerBuildInfoRequest(const GetServerBuildInfoRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId)
            {}

            GetServerBuildInfoRequest(const rapidjson::Value& obj) : GetServerBuildInfoRequest()
            {
                readFromValue(obj);
            }

            ~GetServerBuildInfoRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("BuildId");
                writer.String(BuildId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
                if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();

                return true;
            }
        };

        struct GetServerBuildInfoResult : public PlayFabBaseModel
        {
            AZStd::string BuildId;
            std::list<Region> ActiveRegions;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            AZStd::string Comment;
            time_t Timestamp;
            AZStd::string TitleId;
            Boxed<GameBuildStatus> Status;
            AZStd::string ErrorMessage;

            GetServerBuildInfoResult() :
                PlayFabBaseModel(),
                BuildId(),
                ActiveRegions(),
                MaxGamesPerHost(0),
                MinFreeGameSlots(0),
                Comment(),
                Timestamp(0),
                TitleId(),
                Status(),
                ErrorMessage()
            {}

            GetServerBuildInfoResult(const GetServerBuildInfoResult& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                ActiveRegions(src.ActiveRegions),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                Comment(src.Comment),
                Timestamp(src.Timestamp),
                TitleId(src.TitleId),
                Status(src.Status),
                ErrorMessage(src.ErrorMessage)
            {}

            GetServerBuildInfoResult(const rapidjson::Value& obj) : GetServerBuildInfoResult()
            {
                readFromValue(obj);
            }

            ~GetServerBuildInfoResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (BuildId.length() > 0) {
                    writer.String("BuildId");
                    writer.String(BuildId.c_str());
                }
                if (!ActiveRegions.empty()) {
                    writer.String("ActiveRegions");
                    writer.StartArray();
                    for (std::list<Region>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
                        writeRegionEnumJSON(*iter, writer);
                    }
                    writer.EndArray();
                }
                writer.String("MaxGamesPerHost");
                writer.Int(MaxGamesPerHost);
                writer.String("MinFreeGameSlots");
                writer.Int(MinFreeGameSlots);
                if (Comment.length() > 0) {
                    writer.String("Comment");
                    writer.String(Comment.c_str());
                }
                writer.String("Timestamp");
                writeDatetime(Timestamp, writer);
                if (TitleId.length() > 0) {
                    writer.String("TitleId");
                    writer.String(TitleId.c_str());
                }
                if (Status.notNull()) {
                    writer.String("Status");
                    writeGameBuildStatusEnumJSON(Status, writer);
                }
                if (ErrorMessage.length() > 0) {
                    writer.String("ErrorMessage");
                    writer.String(ErrorMessage.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
                if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
                const Value::ConstMemberIterator ActiveRegions_member = obj.FindMember("ActiveRegions");
                if (ActiveRegions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = ActiveRegions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        ActiveRegions.push_back(readRegionFromValue(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator MaxGamesPerHost_member = obj.FindMember("MaxGamesPerHost");
                if (MaxGamesPerHost_member != obj.MemberEnd() && !MaxGamesPerHost_member->value.IsNull()) MaxGamesPerHost = MaxGamesPerHost_member->value.GetInt();
                const Value::ConstMemberIterator MinFreeGameSlots_member = obj.FindMember("MinFreeGameSlots");
                if (MinFreeGameSlots_member != obj.MemberEnd() && !MinFreeGameSlots_member->value.IsNull()) MinFreeGameSlots = MinFreeGameSlots_member->value.GetInt();
                const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
                if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
                const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
                if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
                if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readGameBuildStatusFromValue(Status_member->value);
                const Value::ConstMemberIterator ErrorMessage_member = obj.FindMember("ErrorMessage");
                if (ErrorMessage_member != obj.MemberEnd() && !ErrorMessage_member->value.IsNull()) ErrorMessage = ErrorMessage_member->value.GetString();

                return true;
            }
        };

        struct GetServerBuildUploadURLRequest : public PlayFabBaseModel
        {
            AZStd::string BuildId;

            GetServerBuildUploadURLRequest() :
                PlayFabBaseModel(),
                BuildId()
            {}

            GetServerBuildUploadURLRequest(const GetServerBuildUploadURLRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId)
            {}

            GetServerBuildUploadURLRequest(const rapidjson::Value& obj) : GetServerBuildUploadURLRequest()
            {
                readFromValue(obj);
            }

            ~GetServerBuildUploadURLRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("BuildId");
                writer.String(BuildId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
                if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();

                return true;
            }
        };

        struct GetServerBuildUploadURLResult : public PlayFabBaseModel
        {
            AZStd::string URL;

            GetServerBuildUploadURLResult() :
                PlayFabBaseModel(),
                URL()
            {}

            GetServerBuildUploadURLResult(const GetServerBuildUploadURLResult& src) :
                PlayFabBaseModel(),
                URL(src.URL)
            {}

            GetServerBuildUploadURLResult(const rapidjson::Value& obj) : GetServerBuildUploadURLResult()
            {
                readFromValue(obj);
            }

            ~GetServerBuildUploadURLResult()
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

        struct GetStoreItemsRequest : public PlayFabBaseModel
        {
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
            AZStd::string ItemId;
            std::map<AZStd::string, Uint32> VirtualCurrencyPrices;
            std::map<AZStd::string, Uint32> RealCurrencyPrices;
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
                    for (std::map<AZStd::string, Uint32>::iterator iter = VirtualCurrencyPrices.begin(); iter != VirtualCurrencyPrices.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Uint(iter->second);
                    }
                    writer.EndObject();
                }
                if (!RealCurrencyPrices.empty()) {
                    writer.String("RealCurrencyPrices");
                    writer.StartObject();
                    for (std::map<AZStd::string, Uint32>::iterator iter = RealCurrencyPrices.begin(); iter != RealCurrencyPrices.end(); ++iter) {
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

            static std::map<const char *, SourceType, PlayFabServerSdk::StringCompare> _SourceTypeMap;
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
            std::list<StoreItem> Store;
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
                    for (std::list<StoreItem>::iterator iter = Store.begin(); iter != Store.end(); iter++) {
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

        struct GetTaskInstanceRequest : public PlayFabBaseModel
        {
            AZStd::string TaskInstanceId;

            GetTaskInstanceRequest() :
                PlayFabBaseModel(),
                TaskInstanceId()
            {}

            GetTaskInstanceRequest(const GetTaskInstanceRequest& src) :
                PlayFabBaseModel(),
                TaskInstanceId(src.TaskInstanceId)
            {}

            GetTaskInstanceRequest(const rapidjson::Value& obj) : GetTaskInstanceRequest()
            {
                readFromValue(obj);
            }

            ~GetTaskInstanceRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("TaskInstanceId");
                writer.String(TaskInstanceId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TaskInstanceId_member = obj.FindMember("TaskInstanceId");
                if (TaskInstanceId_member != obj.MemberEnd() && !TaskInstanceId_member->value.IsNull()) TaskInstanceId = TaskInstanceId_member->value.GetString();

                return true;
            }
        };

        struct GetTaskInstancesRequest : public PlayFabBaseModel
        {
            NameIdentifier* TaskIdentifier;
            Boxed<TaskInstanceStatus> StatusFilter;
            OptionalTime StartedAtRangeFrom;
            OptionalTime StartedAtRangeTo;

            GetTaskInstancesRequest() :
                PlayFabBaseModel(),
                TaskIdentifier(nullptr),
                StatusFilter(),
                StartedAtRangeFrom(),
                StartedAtRangeTo()
            {}

            GetTaskInstancesRequest(const GetTaskInstancesRequest& src) :
                PlayFabBaseModel(),
                TaskIdentifier(src.TaskIdentifier ? new NameIdentifier(*src.TaskIdentifier) : nullptr),
                StatusFilter(src.StatusFilter),
                StartedAtRangeFrom(src.StartedAtRangeFrom),
                StartedAtRangeTo(src.StartedAtRangeTo)
            {}

            GetTaskInstancesRequest(const rapidjson::Value& obj) : GetTaskInstancesRequest()
            {
                readFromValue(obj);
            }

            ~GetTaskInstancesRequest()
            {
                if (TaskIdentifier != nullptr) delete TaskIdentifier;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (TaskIdentifier != nullptr) {
                    writer.String("TaskIdentifier");
                    TaskIdentifier->writeJSON(writer);
                }
                if (StatusFilter.notNull()) {
                    writer.String("StatusFilter");
                    writeTaskInstanceStatusEnumJSON(StatusFilter, writer);
                }
                if (StartedAtRangeFrom.notNull()) {
                    writer.String("StartedAtRangeFrom");
                    writeDatetime(StartedAtRangeFrom, writer);
                }
                if (StartedAtRangeTo.notNull()) {
                    writer.String("StartedAtRangeTo");
                    writeDatetime(StartedAtRangeTo, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TaskIdentifier_member = obj.FindMember("TaskIdentifier");
                if (TaskIdentifier_member != obj.MemberEnd() && !TaskIdentifier_member->value.IsNull()) TaskIdentifier = new NameIdentifier(TaskIdentifier_member->value);
                const Value::ConstMemberIterator StatusFilter_member = obj.FindMember("StatusFilter");
                if (StatusFilter_member != obj.MemberEnd() && !StatusFilter_member->value.IsNull()) StatusFilter = readTaskInstanceStatusFromValue(StatusFilter_member->value);
                const Value::ConstMemberIterator StartedAtRangeFrom_member = obj.FindMember("StartedAtRangeFrom");
                if (StartedAtRangeFrom_member != obj.MemberEnd() && !StartedAtRangeFrom_member->value.IsNull()) StartedAtRangeFrom = readDatetime(StartedAtRangeFrom_member->value);
                const Value::ConstMemberIterator StartedAtRangeTo_member = obj.FindMember("StartedAtRangeTo");
                if (StartedAtRangeTo_member != obj.MemberEnd() && !StartedAtRangeTo_member->value.IsNull()) StartedAtRangeTo = readDatetime(StartedAtRangeTo_member->value);

                return true;
            }
        };

        enum ScheduledTaskType
        {
            ScheduledTaskTypeCloudScript,
            ScheduledTaskTypeActionsOnPlayerSegment
        };

        inline void writeScheduledTaskTypeEnumJSON(ScheduledTaskType enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case ScheduledTaskTypeCloudScript: writer.String("CloudScript"); break;
            case ScheduledTaskTypeActionsOnPlayerSegment: writer.String("ActionsOnPlayerSegment"); break;

            }
        }

        inline ScheduledTaskType readScheduledTaskTypeFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<ScheduledTaskType>(obj.GetInt());

            static std::map<const char *, ScheduledTaskType, PlayFabServerSdk::StringCompare> _ScheduledTaskTypeMap;
            if (_ScheduledTaskTypeMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _ScheduledTaskTypeMap["CloudScript"] = ScheduledTaskTypeCloudScript;
                _ScheduledTaskTypeMap["ActionsOnPlayerSegment"] = ScheduledTaskTypeActionsOnPlayerSegment;

            }

            auto output = _ScheduledTaskTypeMap.find(obj.GetString());
            if (output != _ScheduledTaskTypeMap.end())
                return output->second;

            return ScheduledTaskTypeCloudScript; // Basically critical fail
        }

        struct TaskInstanceBasicSummary : public PlayFabBaseModel
        {
            AZStd::string TaskInstanceId;
            NameIdentifier* TaskIdentifier;
            time_t StartedAt;
            OptionalTime CompletedAt;
            Boxed<TaskInstanceStatus> Status;
            OptionalDouble PercentComplete;
            OptionalDouble EstimatedSecondsRemaining;
            AZStd::string ScheduledByUserId;
            Boxed<ScheduledTaskType> Type;

            TaskInstanceBasicSummary() :
                PlayFabBaseModel(),
                TaskInstanceId(),
                TaskIdentifier(nullptr),
                StartedAt(0),
                CompletedAt(),
                Status(),
                PercentComplete(),
                EstimatedSecondsRemaining(),
                ScheduledByUserId(),
                Type()
            {}

            TaskInstanceBasicSummary(const TaskInstanceBasicSummary& src) :
                PlayFabBaseModel(),
                TaskInstanceId(src.TaskInstanceId),
                TaskIdentifier(src.TaskIdentifier ? new NameIdentifier(*src.TaskIdentifier) : nullptr),
                StartedAt(src.StartedAt),
                CompletedAt(src.CompletedAt),
                Status(src.Status),
                PercentComplete(src.PercentComplete),
                EstimatedSecondsRemaining(src.EstimatedSecondsRemaining),
                ScheduledByUserId(src.ScheduledByUserId),
                Type(src.Type)
            {}

            TaskInstanceBasicSummary(const rapidjson::Value& obj) : TaskInstanceBasicSummary()
            {
                readFromValue(obj);
            }

            ~TaskInstanceBasicSummary()
            {
                if (TaskIdentifier != nullptr) delete TaskIdentifier;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (TaskInstanceId.length() > 0) {
                    writer.String("TaskInstanceId");
                    writer.String(TaskInstanceId.c_str());
                }
                if (TaskIdentifier != nullptr) {
                    writer.String("TaskIdentifier");
                    TaskIdentifier->writeJSON(writer);
                }
                writer.String("StartedAt");
                writeDatetime(StartedAt, writer);
                if (CompletedAt.notNull()) {
                    writer.String("CompletedAt");
                    writeDatetime(CompletedAt, writer);
                }
                if (Status.notNull()) {
                    writer.String("Status");
                    writeTaskInstanceStatusEnumJSON(Status, writer);
                }
                if (PercentComplete.notNull()) {
                    writer.String("PercentComplete");
                    writer.Double(PercentComplete);
                }
                if (EstimatedSecondsRemaining.notNull()) {
                    writer.String("EstimatedSecondsRemaining");
                    writer.Double(EstimatedSecondsRemaining);
                }
                if (ScheduledByUserId.length() > 0) {
                    writer.String("ScheduledByUserId");
                    writer.String(ScheduledByUserId.c_str());
                }
                if (Type.notNull()) {
                    writer.String("Type");
                    writeScheduledTaskTypeEnumJSON(Type, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TaskInstanceId_member = obj.FindMember("TaskInstanceId");
                if (TaskInstanceId_member != obj.MemberEnd() && !TaskInstanceId_member->value.IsNull()) TaskInstanceId = TaskInstanceId_member->value.GetString();
                const Value::ConstMemberIterator TaskIdentifier_member = obj.FindMember("TaskIdentifier");
                if (TaskIdentifier_member != obj.MemberEnd() && !TaskIdentifier_member->value.IsNull()) TaskIdentifier = new NameIdentifier(TaskIdentifier_member->value);
                const Value::ConstMemberIterator StartedAt_member = obj.FindMember("StartedAt");
                if (StartedAt_member != obj.MemberEnd() && !StartedAt_member->value.IsNull()) StartedAt = readDatetime(StartedAt_member->value);
                const Value::ConstMemberIterator CompletedAt_member = obj.FindMember("CompletedAt");
                if (CompletedAt_member != obj.MemberEnd() && !CompletedAt_member->value.IsNull()) CompletedAt = readDatetime(CompletedAt_member->value);
                const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
                if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readTaskInstanceStatusFromValue(Status_member->value);
                const Value::ConstMemberIterator PercentComplete_member = obj.FindMember("PercentComplete");
                if (PercentComplete_member != obj.MemberEnd() && !PercentComplete_member->value.IsNull()) PercentComplete = PercentComplete_member->value.GetDouble();
                const Value::ConstMemberIterator EstimatedSecondsRemaining_member = obj.FindMember("EstimatedSecondsRemaining");
                if (EstimatedSecondsRemaining_member != obj.MemberEnd() && !EstimatedSecondsRemaining_member->value.IsNull()) EstimatedSecondsRemaining = EstimatedSecondsRemaining_member->value.GetDouble();
                const Value::ConstMemberIterator ScheduledByUserId_member = obj.FindMember("ScheduledByUserId");
                if (ScheduledByUserId_member != obj.MemberEnd() && !ScheduledByUserId_member->value.IsNull()) ScheduledByUserId = ScheduledByUserId_member->value.GetString();
                const Value::ConstMemberIterator Type_member = obj.FindMember("Type");
                if (Type_member != obj.MemberEnd() && !Type_member->value.IsNull()) Type = readScheduledTaskTypeFromValue(Type_member->value);

                return true;
            }
        };

        struct GetTaskInstancesResult : public PlayFabBaseModel
        {
            std::list<TaskInstanceBasicSummary> Summaries;

            GetTaskInstancesResult() :
                PlayFabBaseModel(),
                Summaries()
            {}

            GetTaskInstancesResult(const GetTaskInstancesResult& src) :
                PlayFabBaseModel(),
                Summaries(src.Summaries)
            {}

            GetTaskInstancesResult(const rapidjson::Value& obj) : GetTaskInstancesResult()
            {
                readFromValue(obj);
            }

            ~GetTaskInstancesResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Summaries.empty()) {
                    writer.String("Summaries");
                    writer.StartArray();
                    for (std::list<TaskInstanceBasicSummary>::iterator iter = Summaries.begin(); iter != Summaries.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Summaries_member = obj.FindMember("Summaries");
                if (Summaries_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Summaries_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Summaries.push_back(TaskInstanceBasicSummary(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetTasksRequest : public PlayFabBaseModel
        {
            NameIdentifier* Identifier;

            GetTasksRequest() :
                PlayFabBaseModel(),
                Identifier(nullptr)
            {}

            GetTasksRequest(const GetTasksRequest& src) :
                PlayFabBaseModel(),
                Identifier(src.Identifier ? new NameIdentifier(*src.Identifier) : nullptr)
            {}

            GetTasksRequest(const rapidjson::Value& obj) : GetTasksRequest()
            {
                readFromValue(obj);
            }

            ~GetTasksRequest()
            {
                if (Identifier != nullptr) delete Identifier;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Identifier != nullptr) {
                    writer.String("Identifier");
                    Identifier->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Identifier_member = obj.FindMember("Identifier");
                if (Identifier_member != obj.MemberEnd() && !Identifier_member->value.IsNull()) Identifier = new NameIdentifier(Identifier_member->value);

                return true;
            }
        };

        struct ScheduledTask : public PlayFabBaseModel
        {
            AZStd::string TaskId;
            AZStd::string Name;
            AZStd::string Description;
            AZStd::string Schedule;
            bool IsActive;
            Boxed<ScheduledTaskType> Type;
            MultitypeVar Parameter;
            OptionalTime LastRunTime;
            OptionalTime NextRunTime;

            ScheduledTask() :
                PlayFabBaseModel(),
                TaskId(),
                Name(),
                Description(),
                Schedule(),
                IsActive(false),
                Type(),
                Parameter(),
                LastRunTime(),
                NextRunTime()
            {}

            ScheduledTask(const ScheduledTask& src) :
                PlayFabBaseModel(),
                TaskId(src.TaskId),
                Name(src.Name),
                Description(src.Description),
                Schedule(src.Schedule),
                IsActive(src.IsActive),
                Type(src.Type),
                Parameter(src.Parameter),
                LastRunTime(src.LastRunTime),
                NextRunTime(src.NextRunTime)
            {}

            ScheduledTask(const rapidjson::Value& obj) : ScheduledTask()
            {
                readFromValue(obj);
            }

            ~ScheduledTask()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (TaskId.length() > 0) {
                    writer.String("TaskId");
                    writer.String(TaskId.c_str());
                }
                writer.String("Name");
                writer.String(Name.c_str());
                if (Description.length() > 0) {
                    writer.String("Description");
                    writer.String(Description.c_str());
                }
                if (Schedule.length() > 0) {
                    writer.String("Schedule");
                    writer.String(Schedule.c_str());
                }
                writer.String("IsActive");
                writer.Bool(IsActive);
                if (Type.notNull()) {
                    writer.String("Type");
                    writeScheduledTaskTypeEnumJSON(Type, writer);
                }
                if (Parameter.notNull()) {
                    writer.String("Parameter");
                    Parameter.writeJSON(writer);
                }
                if (LastRunTime.notNull()) {
                    writer.String("LastRunTime");
                    writeDatetime(LastRunTime, writer);
                }
                if (NextRunTime.notNull()) {
                    writer.String("NextRunTime");
                    writeDatetime(NextRunTime, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TaskId_member = obj.FindMember("TaskId");
                if (TaskId_member != obj.MemberEnd() && !TaskId_member->value.IsNull()) TaskId = TaskId_member->value.GetString();
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
                const Value::ConstMemberIterator Description_member = obj.FindMember("Description");
                if (Description_member != obj.MemberEnd() && !Description_member->value.IsNull()) Description = Description_member->value.GetString();
                const Value::ConstMemberIterator Schedule_member = obj.FindMember("Schedule");
                if (Schedule_member != obj.MemberEnd() && !Schedule_member->value.IsNull()) Schedule = Schedule_member->value.GetString();
                const Value::ConstMemberIterator IsActive_member = obj.FindMember("IsActive");
                if (IsActive_member != obj.MemberEnd() && !IsActive_member->value.IsNull()) IsActive = IsActive_member->value.GetBool();
                const Value::ConstMemberIterator Type_member = obj.FindMember("Type");
                if (Type_member != obj.MemberEnd() && !Type_member->value.IsNull()) Type = readScheduledTaskTypeFromValue(Type_member->value);
                const Value::ConstMemberIterator Parameter_member = obj.FindMember("Parameter");
                if (Parameter_member != obj.MemberEnd() && !Parameter_member->value.IsNull()) Parameter = MultitypeVar(Parameter_member->value);
                const Value::ConstMemberIterator LastRunTime_member = obj.FindMember("LastRunTime");
                if (LastRunTime_member != obj.MemberEnd() && !LastRunTime_member->value.IsNull()) LastRunTime = readDatetime(LastRunTime_member->value);
                const Value::ConstMemberIterator NextRunTime_member = obj.FindMember("NextRunTime");
                if (NextRunTime_member != obj.MemberEnd() && !NextRunTime_member->value.IsNull()) NextRunTime = readDatetime(NextRunTime_member->value);

                return true;
            }
        };

        struct GetTasksResult : public PlayFabBaseModel
        {
            std::list<ScheduledTask> Tasks;

            GetTasksResult() :
                PlayFabBaseModel(),
                Tasks()
            {}

            GetTasksResult(const GetTasksResult& src) :
                PlayFabBaseModel(),
                Tasks(src.Tasks)
            {}

            GetTasksResult(const rapidjson::Value& obj) : GetTasksResult()
            {
                readFromValue(obj);
            }

            ~GetTasksResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Tasks.empty()) {
                    writer.String("Tasks");
                    writer.StartArray();
                    for (std::list<ScheduledTask>::iterator iter = Tasks.begin(); iter != Tasks.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Tasks_member = obj.FindMember("Tasks");
                if (Tasks_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Tasks_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Tasks.push_back(ScheduledTask(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetTitleDataRequest : public PlayFabBaseModel
        {
            std::list<AZStd::string> Keys;

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
                    for (std::list<AZStd::string>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
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
            std::map<AZStd::string, AZStd::string> Data;

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
                    for (std::map<AZStd::string, AZStd::string>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
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

        struct GetUserBansRequest : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;

            GetUserBansRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            GetUserBansRequest(const GetUserBansRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            GetUserBansRequest(const rapidjson::Value& obj) : GetUserBansRequest()
            {
                readFromValue(obj);
            }

            ~GetUserBansRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct GetUserBansResult : public PlayFabBaseModel
        {
            std::list<BanInfo> BanData;

            GetUserBansResult() :
                PlayFabBaseModel(),
                BanData()
            {}

            GetUserBansResult(const GetUserBansResult& src) :
                PlayFabBaseModel(),
                BanData(src.BanData)
            {}

            GetUserBansResult(const rapidjson::Value& obj) : GetUserBansResult()
            {
                readFromValue(obj);
            }

            ~GetUserBansResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!BanData.empty()) {
                    writer.String("BanData");
                    writer.StartArray();
                    for (std::list<BanInfo>::iterator iter = BanData.begin(); iter != BanData.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BanData_member = obj.FindMember("BanData");
                if (BanData_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = BanData_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        BanData.push_back(BanInfo(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GetUserDataRequest : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            std::list<AZStd::string> Keys;
            OptionalUint32 IfChangedFromDataVersion;

            GetUserDataRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                Keys(),
                IfChangedFromDataVersion()
            {}

            GetUserDataRequest(const GetUserDataRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Keys(src.Keys),
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
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                if (!Keys.empty()) {
                    writer.String("Keys");
                    writer.StartArray();
                    for (std::list<AZStd::string>::iterator iter = Keys.begin(); iter != Keys.end(); iter++) {
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

            static std::map<const char *, UserDataPermission, PlayFabServerSdk::StringCompare> _UserDataPermissionMap;
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

        struct GetUserDataResult : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            Uint32 DataVersion;
            std::map<AZStd::string, UserDataRecord> Data;

            GetUserDataResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                DataVersion(0),
                Data()
            {}

            GetUserDataResult(const GetUserDataResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                DataVersion(src.DataVersion),
                Data(src.Data)
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
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                writer.String("DataVersion");
                writer.Uint(DataVersion);
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartObject();
                    for (std::map<AZStd::string, UserDataRecord>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator DataVersion_member = obj.FindMember("DataVersion");
                if (DataVersion_member != obj.MemberEnd() && !DataVersion_member->value.IsNull()) DataVersion = DataVersion_member->value.GetUint();
                const Value::ConstMemberIterator Data_member = obj.FindMember("Data");
                if (Data_member != obj.MemberEnd()) {
                    for (Value::ConstMemberIterator iter = Data_member->value.MemberBegin(); iter != Data_member->value.MemberEnd(); ++iter) {
                        Data[iter->name.GetString()] = UserDataRecord(iter->value);
                    }
                }

                return true;
            }
        };

        struct GetUserInventoryRequest : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;

            GetUserInventoryRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            GetUserInventoryRequest(const GetUserInventoryRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
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
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct ItemInstance : public PlayFabBaseModel
        {
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
            std::list<AZStd::string> BundleContents;
            std::map<AZStd::string, AZStd::string> CustomData;

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
                    for (std::list<AZStd::string>::iterator iter = BundleContents.begin(); iter != BundleContents.end(); iter++) {
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!CustomData.empty()) {
                    writer.String("CustomData");
                    writer.StartObject();
                    for (std::map<AZStd::string, AZStd::string>::iterator iter = CustomData.begin(); iter != CustomData.end(); ++iter) {
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

        struct VirtualCurrencyRechargeTime : public PlayFabBaseModel
        {
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

        struct GetUserInventoryResult : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            std::list<ItemInstance> Inventory;
            std::map<AZStd::string, Int32> VirtualCurrency;
            std::map<AZStd::string, VirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;

            GetUserInventoryResult() :
                PlayFabBaseModel(),
                PlayFabId(),
                Inventory(),
                VirtualCurrency(),
                VirtualCurrencyRechargeTimes()
            {}

            GetUserInventoryResult(const GetUserInventoryResult& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
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
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                if (!Inventory.empty()) {
                    writer.String("Inventory");
                    writer.StartArray();
                    for (std::list<ItemInstance>::iterator iter = Inventory.begin(); iter != Inventory.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                if (!VirtualCurrency.empty()) {
                    writer.String("VirtualCurrency");
                    writer.StartObject();
                    for (std::map<AZStd::string, Int32>::iterator iter = VirtualCurrency.begin(); iter != VirtualCurrency.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.Int(iter->second);
                    }
                    writer.EndObject();
                }
                if (!VirtualCurrencyRechargeTimes.empty()) {
                    writer.String("VirtualCurrencyRechargeTimes");
                    writer.StartObject();
                    for (std::map<AZStd::string, VirtualCurrencyRechargeTime>::iterator iter = VirtualCurrencyRechargeTimes.begin(); iter != VirtualCurrencyRechargeTimes.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        iter->second.writeJSON(writer);
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
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

        struct GrantedItemInstance : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            AZStd::string CharacterId;
            bool Result;
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
            std::list<AZStd::string> BundleContents;
            std::map<AZStd::string, AZStd::string> CustomData;

            GrantedItemInstance() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                Result(false),
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

            GrantedItemInstance(const GrantedItemInstance& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                Result(src.Result),
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

            GrantedItemInstance(const rapidjson::Value& obj) : GrantedItemInstance()
            {
                readFromValue(obj);
            }

            ~GrantedItemInstance()
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
                writer.String("Result");
                writer.Bool(Result);
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
                    for (std::list<AZStd::string>::iterator iter = BundleContents.begin(); iter != BundleContents.end(); iter++) {
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                if (!CustomData.empty()) {
                    writer.String("CustomData");
                    writer.StartObject();
                    for (std::map<AZStd::string, AZStd::string>::iterator iter = CustomData.begin(); iter != CustomData.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator Result_member = obj.FindMember("Result");
                if (Result_member != obj.MemberEnd() && !Result_member->value.IsNull()) Result = Result_member->value.GetBool();
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

        struct ItemGrant : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            AZStd::string ItemId;
            AZStd::string Annotation;
            AZStd::string CharacterId;
            std::map<AZStd::string, AZStd::string> Data;
            std::list<AZStd::string> KeysToRemove;

            ItemGrant() :
                PlayFabBaseModel(),
                PlayFabId(),
                ItemId(),
                Annotation(),
                CharacterId(),
                Data(),
                KeysToRemove()
            {}

            ItemGrant(const ItemGrant& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                ItemId(src.ItemId),
                Annotation(src.Annotation),
                CharacterId(src.CharacterId),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove)
            {}

            ItemGrant(const rapidjson::Value& obj) : ItemGrant()
            {
                readFromValue(obj);
            }

            ~ItemGrant()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                writer.String("ItemId");
                writer.String(ItemId.c_str());
                if (Annotation.length() > 0) {
                    writer.String("Annotation");
                    writer.String(Annotation.c_str());
                }
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartObject();
                    for (std::map<AZStd::string, AZStd::string>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                if (!KeysToRemove.empty()) {
                    writer.String("KeysToRemove");
                    writer.StartArray();
                    for (std::list<AZStd::string>::iterator iter = KeysToRemove.begin(); iter != KeysToRemove.end(); iter++) {
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator ItemId_member = obj.FindMember("ItemId");
                if (ItemId_member != obj.MemberEnd() && !ItemId_member->value.IsNull()) ItemId = ItemId_member->value.GetString();
                const Value::ConstMemberIterator Annotation_member = obj.FindMember("Annotation");
                if (Annotation_member != obj.MemberEnd() && !Annotation_member->value.IsNull()) Annotation = Annotation_member->value.GetString();
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

                return true;
            }
        };

        struct GrantItemsToUsersRequest : public PlayFabBaseModel
        {
            AZStd::string CatalogVersion;
            std::list<ItemGrant> ItemGrants;

            GrantItemsToUsersRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                ItemGrants()
            {}

            GrantItemsToUsersRequest(const GrantItemsToUsersRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                ItemGrants(src.ItemGrants)
            {}

            GrantItemsToUsersRequest(const rapidjson::Value& obj) : GrantItemsToUsersRequest()
            {
                readFromValue(obj);
            }

            ~GrantItemsToUsersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                writer.String("ItemGrants");
                writer.StartArray();
                for (std::list<ItemGrant>::iterator iter = ItemGrants.begin(); iter != ItemGrants.end(); iter++) {
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator ItemGrants_member = obj.FindMember("ItemGrants");
                if (ItemGrants_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = ItemGrants_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        ItemGrants.push_back(ItemGrant(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct GrantItemsToUsersResult : public PlayFabBaseModel
        {
            std::list<GrantedItemInstance> ItemGrantResults;

            GrantItemsToUsersResult() :
                PlayFabBaseModel(),
                ItemGrantResults()
            {}

            GrantItemsToUsersResult(const GrantItemsToUsersResult& src) :
                PlayFabBaseModel(),
                ItemGrantResults(src.ItemGrantResults)
            {}

            GrantItemsToUsersResult(const rapidjson::Value& obj) : GrantItemsToUsersResult()
            {
                readFromValue(obj);
            }

            ~GrantItemsToUsersResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!ItemGrantResults.empty()) {
                    writer.String("ItemGrantResults");
                    writer.StartArray();
                    for (std::list<GrantedItemInstance>::iterator iter = ItemGrantResults.begin(); iter != ItemGrantResults.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ItemGrantResults_member = obj.FindMember("ItemGrantResults");
                if (ItemGrantResults_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = ItemGrantResults_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        ItemGrantResults.push_back(GrantedItemInstance(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct IncrementPlayerStatisticVersionRequest : public PlayFabBaseModel
        {
            AZStd::string StatisticName;

            IncrementPlayerStatisticVersionRequest() :
                PlayFabBaseModel(),
                StatisticName()
            {}

            IncrementPlayerStatisticVersionRequest(const IncrementPlayerStatisticVersionRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName)
            {}

            IncrementPlayerStatisticVersionRequest(const rapidjson::Value& obj) : IncrementPlayerStatisticVersionRequest()
            {
                readFromValue(obj);
            }

            ~IncrementPlayerStatisticVersionRequest()
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

        struct IncrementPlayerStatisticVersionResult : public PlayFabBaseModel
        {
            PlayerStatisticVersion* StatisticVersion;

            IncrementPlayerStatisticVersionResult() :
                PlayFabBaseModel(),
                StatisticVersion(nullptr)
            {}

            IncrementPlayerStatisticVersionResult(const IncrementPlayerStatisticVersionResult& src) :
                PlayFabBaseModel(),
                StatisticVersion(src.StatisticVersion ? new PlayerStatisticVersion(*src.StatisticVersion) : nullptr)
            {}

            IncrementPlayerStatisticVersionResult(const rapidjson::Value& obj) : IncrementPlayerStatisticVersionResult()
            {
                readFromValue(obj);
            }

            ~IncrementPlayerStatisticVersionResult()
            {
                if (StatisticVersion != nullptr) delete StatisticVersion;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (StatisticVersion != nullptr) {
                    writer.String("StatisticVersion");
                    StatisticVersion->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticVersion_member = obj.FindMember("StatisticVersion");
                if (StatisticVersion_member != obj.MemberEnd() && !StatisticVersion_member->value.IsNull()) StatisticVersion = new PlayerStatisticVersion(StatisticVersion_member->value);

                return true;
            }
        };

        struct ListBuildsRequest : public PlayFabBaseModel
        {

            ListBuildsRequest() :
                PlayFabBaseModel()
            {}

            ListBuildsRequest(const ListBuildsRequest& src) :
                PlayFabBaseModel()
            {}

            ListBuildsRequest(const rapidjson::Value& obj) : ListBuildsRequest()
            {
                readFromValue(obj);
            }

            ~ListBuildsRequest()
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

        struct ListBuildsResult : public PlayFabBaseModel
        {
            std::list<GetServerBuildInfoResult> Builds;

            ListBuildsResult() :
                PlayFabBaseModel(),
                Builds()
            {}

            ListBuildsResult(const ListBuildsResult& src) :
                PlayFabBaseModel(),
                Builds(src.Builds)
            {}

            ListBuildsResult(const rapidjson::Value& obj) : ListBuildsResult()
            {
                readFromValue(obj);
            }

            ~ListBuildsResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!Builds.empty()) {
                    writer.String("Builds");
                    writer.StartArray();
                    for (std::list<GetServerBuildInfoResult>::iterator iter = Builds.begin(); iter != Builds.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Builds_member = obj.FindMember("Builds");
                if (Builds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Builds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Builds.push_back(GetServerBuildInfoResult(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct ListVirtualCurrencyTypesRequest : public PlayFabBaseModel
        {

            ListVirtualCurrencyTypesRequest() :
                PlayFabBaseModel()
            {}

            ListVirtualCurrencyTypesRequest(const ListVirtualCurrencyTypesRequest& src) :
                PlayFabBaseModel()
            {}

            ListVirtualCurrencyTypesRequest(const rapidjson::Value& obj) : ListVirtualCurrencyTypesRequest()
            {
                readFromValue(obj);
            }

            ~ListVirtualCurrencyTypesRequest()
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

        struct ListVirtualCurrencyTypesResult : public PlayFabBaseModel
        {
            std::list<VirtualCurrencyData> VirtualCurrencies;

            ListVirtualCurrencyTypesResult() :
                PlayFabBaseModel(),
                VirtualCurrencies()
            {}

            ListVirtualCurrencyTypesResult(const ListVirtualCurrencyTypesResult& src) :
                PlayFabBaseModel(),
                VirtualCurrencies(src.VirtualCurrencies)
            {}

            ListVirtualCurrencyTypesResult(const rapidjson::Value& obj) : ListVirtualCurrencyTypesResult()
            {
                readFromValue(obj);
            }

            ~ListVirtualCurrencyTypesResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!VirtualCurrencies.empty()) {
                    writer.String("VirtualCurrencies");
                    writer.StartArray();
                    for (std::list<VirtualCurrencyData>::iterator iter = VirtualCurrencies.begin(); iter != VirtualCurrencies.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator VirtualCurrencies_member = obj.FindMember("VirtualCurrencies");
                if (VirtualCurrencies_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = VirtualCurrencies_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        VirtualCurrencies.push_back(VirtualCurrencyData(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct LookupUserAccountInfoRequest : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            AZStd::string Email;
            AZStd::string Username;
            AZStd::string TitleDisplayName;

            LookupUserAccountInfoRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                Email(),
                Username(),
                TitleDisplayName()
            {}

            LookupUserAccountInfoRequest(const LookupUserAccountInfoRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Email(src.Email),
                Username(src.Username),
                TitleDisplayName(src.TitleDisplayName)
            {}

            LookupUserAccountInfoRequest(const rapidjson::Value& obj) : LookupUserAccountInfoRequest()
            {
                readFromValue(obj);
            }

            ~LookupUserAccountInfoRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PlayFabId.length() > 0) {
                    writer.String("PlayFabId");
                    writer.String(PlayFabId.c_str());
                }
                if (Email.length() > 0) {
                    writer.String("Email");
                    writer.String(Email.c_str());
                }
                if (Username.length() > 0) {
                    writer.String("Username");
                    writer.String(Username.c_str());
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
                const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
                if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();
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

            static std::map<const char *, UserOrigination, PlayFabServerSdk::StringCompare> _UserOriginationMap;
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

        struct UserFacebookInfo : public PlayFabBaseModel
        {
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

            static std::map<const char *, TitleActivationStatus, PlayFabServerSdk::StringCompare> _TitleActivationStatusMap;
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

        struct UserIosDeviceInfo : public PlayFabBaseModel
        {
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

        struct LookupUserAccountInfoResult : public PlayFabBaseModel
        {
            UserAccountInfo* UserInfo;

            LookupUserAccountInfoResult() :
                PlayFabBaseModel(),
                UserInfo(nullptr)
            {}

            LookupUserAccountInfoResult(const LookupUserAccountInfoResult& src) :
                PlayFabBaseModel(),
                UserInfo(src.UserInfo ? new UserAccountInfo(*src.UserInfo) : nullptr)
            {}

            LookupUserAccountInfoResult(const rapidjson::Value& obj) : LookupUserAccountInfoResult()
            {
                readFromValue(obj);
            }

            ~LookupUserAccountInfoResult()
            {
                if (UserInfo != nullptr) delete UserInfo;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (UserInfo != nullptr) {
                    writer.String("UserInfo");
                    UserInfo->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator UserInfo_member = obj.FindMember("UserInfo");
                if (UserInfo_member != obj.MemberEnd() && !UserInfo_member->value.IsNull()) UserInfo = new UserAccountInfo(UserInfo_member->value);

                return true;
            }
        };

        struct ModifyMatchmakerGameModesRequest : public PlayFabBaseModel
        {
            AZStd::string BuildVersion;
            std::list<GameModeInfo> GameModes;

            ModifyMatchmakerGameModesRequest() :
                PlayFabBaseModel(),
                BuildVersion(),
                GameModes()
            {}

            ModifyMatchmakerGameModesRequest(const ModifyMatchmakerGameModesRequest& src) :
                PlayFabBaseModel(),
                BuildVersion(src.BuildVersion),
                GameModes(src.GameModes)
            {}

            ModifyMatchmakerGameModesRequest(const rapidjson::Value& obj) : ModifyMatchmakerGameModesRequest()
            {
                readFromValue(obj);
            }

            ~ModifyMatchmakerGameModesRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("BuildVersion");
                writer.String(BuildVersion.c_str());
                writer.String("GameModes");
                writer.StartArray();
                for (std::list<GameModeInfo>::iterator iter = GameModes.begin(); iter != GameModes.end(); iter++) {
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildVersion_member = obj.FindMember("BuildVersion");
                if (BuildVersion_member != obj.MemberEnd() && !BuildVersion_member->value.IsNull()) BuildVersion = BuildVersion_member->value.GetString();
                const Value::ConstMemberIterator GameModes_member = obj.FindMember("GameModes");
                if (GameModes_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = GameModes_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        GameModes.push_back(GameModeInfo(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct ModifyMatchmakerGameModesResult : public PlayFabBaseModel
        {

            ModifyMatchmakerGameModesResult() :
                PlayFabBaseModel()
            {}

            ModifyMatchmakerGameModesResult(const ModifyMatchmakerGameModesResult& src) :
                PlayFabBaseModel()
            {}

            ModifyMatchmakerGameModesResult(const rapidjson::Value& obj) : ModifyMatchmakerGameModesResult()
            {
                readFromValue(obj);
            }

            ~ModifyMatchmakerGameModesResult()
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

        struct ModifyServerBuildRequest : public PlayFabBaseModel
        {
            AZStd::string BuildId;
            OptionalTime Timestamp;
            std::list<Region> ActiveRegions;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            AZStd::string CommandLineTemplate;
            AZStd::string ExecutablePath;
            AZStd::string Comment;

            ModifyServerBuildRequest() :
                PlayFabBaseModel(),
                BuildId(),
                Timestamp(),
                ActiveRegions(),
                MaxGamesPerHost(0),
                MinFreeGameSlots(0),
                CommandLineTemplate(),
                ExecutablePath(),
                Comment()
            {}

            ModifyServerBuildRequest(const ModifyServerBuildRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                Timestamp(src.Timestamp),
                ActiveRegions(src.ActiveRegions),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                CommandLineTemplate(src.CommandLineTemplate),
                ExecutablePath(src.ExecutablePath),
                Comment(src.Comment)
            {}

            ModifyServerBuildRequest(const rapidjson::Value& obj) : ModifyServerBuildRequest()
            {
                readFromValue(obj);
            }

            ~ModifyServerBuildRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("BuildId");
                writer.String(BuildId.c_str());
                if (Timestamp.notNull()) {
                    writer.String("Timestamp");
                    writeDatetime(Timestamp, writer);
                }
                if (!ActiveRegions.empty()) {
                    writer.String("ActiveRegions");
                    writer.StartArray();
                    for (std::list<Region>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
                        writeRegionEnumJSON(*iter, writer);
                    }
                    writer.EndArray();
                }
                writer.String("MaxGamesPerHost");
                writer.Int(MaxGamesPerHost);
                writer.String("MinFreeGameSlots");
                writer.Int(MinFreeGameSlots);
                if (CommandLineTemplate.length() > 0) {
                    writer.String("CommandLineTemplate");
                    writer.String(CommandLineTemplate.c_str());
                }
                if (ExecutablePath.length() > 0) {
                    writer.String("ExecutablePath");
                    writer.String(ExecutablePath.c_str());
                }
                if (Comment.length() > 0) {
                    writer.String("Comment");
                    writer.String(Comment.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
                if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
                const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
                if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
                const Value::ConstMemberIterator ActiveRegions_member = obj.FindMember("ActiveRegions");
                if (ActiveRegions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = ActiveRegions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        ActiveRegions.push_back(readRegionFromValue(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator MaxGamesPerHost_member = obj.FindMember("MaxGamesPerHost");
                if (MaxGamesPerHost_member != obj.MemberEnd() && !MaxGamesPerHost_member->value.IsNull()) MaxGamesPerHost = MaxGamesPerHost_member->value.GetInt();
                const Value::ConstMemberIterator MinFreeGameSlots_member = obj.FindMember("MinFreeGameSlots");
                if (MinFreeGameSlots_member != obj.MemberEnd() && !MinFreeGameSlots_member->value.IsNull()) MinFreeGameSlots = MinFreeGameSlots_member->value.GetInt();
                const Value::ConstMemberIterator CommandLineTemplate_member = obj.FindMember("CommandLineTemplate");
                if (CommandLineTemplate_member != obj.MemberEnd() && !CommandLineTemplate_member->value.IsNull()) CommandLineTemplate = CommandLineTemplate_member->value.GetString();
                const Value::ConstMemberIterator ExecutablePath_member = obj.FindMember("ExecutablePath");
                if (ExecutablePath_member != obj.MemberEnd() && !ExecutablePath_member->value.IsNull()) ExecutablePath = ExecutablePath_member->value.GetString();
                const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
                if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();

                return true;
            }
        };

        struct ModifyServerBuildResult : public PlayFabBaseModel
        {
            AZStd::string BuildId;
            std::list<Region> ActiveRegions;
            Int32 MaxGamesPerHost;
            Int32 MinFreeGameSlots;
            AZStd::string CommandLineTemplate;
            AZStd::string ExecutablePath;
            AZStd::string Comment;
            time_t Timestamp;
            AZStd::string TitleId;
            Boxed<GameBuildStatus> Status;

            ModifyServerBuildResult() :
                PlayFabBaseModel(),
                BuildId(),
                ActiveRegions(),
                MaxGamesPerHost(0),
                MinFreeGameSlots(0),
                CommandLineTemplate(),
                ExecutablePath(),
                Comment(),
                Timestamp(0),
                TitleId(),
                Status()
            {}

            ModifyServerBuildResult(const ModifyServerBuildResult& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId),
                ActiveRegions(src.ActiveRegions),
                MaxGamesPerHost(src.MaxGamesPerHost),
                MinFreeGameSlots(src.MinFreeGameSlots),
                CommandLineTemplate(src.CommandLineTemplate),
                ExecutablePath(src.ExecutablePath),
                Comment(src.Comment),
                Timestamp(src.Timestamp),
                TitleId(src.TitleId),
                Status(src.Status)
            {}

            ModifyServerBuildResult(const rapidjson::Value& obj) : ModifyServerBuildResult()
            {
                readFromValue(obj);
            }

            ~ModifyServerBuildResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (BuildId.length() > 0) {
                    writer.String("BuildId");
                    writer.String(BuildId.c_str());
                }
                if (!ActiveRegions.empty()) {
                    writer.String("ActiveRegions");
                    writer.StartArray();
                    for (std::list<Region>::iterator iter = ActiveRegions.begin(); iter != ActiveRegions.end(); iter++) {
                        writeRegionEnumJSON(*iter, writer);
                    }
                    writer.EndArray();
                }
                writer.String("MaxGamesPerHost");
                writer.Int(MaxGamesPerHost);
                writer.String("MinFreeGameSlots");
                writer.Int(MinFreeGameSlots);
                if (CommandLineTemplate.length() > 0) {
                    writer.String("CommandLineTemplate");
                    writer.String(CommandLineTemplate.c_str());
                }
                if (ExecutablePath.length() > 0) {
                    writer.String("ExecutablePath");
                    writer.String(ExecutablePath.c_str());
                }
                if (Comment.length() > 0) {
                    writer.String("Comment");
                    writer.String(Comment.c_str());
                }
                writer.String("Timestamp");
                writeDatetime(Timestamp, writer);
                if (TitleId.length() > 0) {
                    writer.String("TitleId");
                    writer.String(TitleId.c_str());
                }
                if (Status.notNull()) {
                    writer.String("Status");
                    writeGameBuildStatusEnumJSON(Status, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
                if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();
                const Value::ConstMemberIterator ActiveRegions_member = obj.FindMember("ActiveRegions");
                if (ActiveRegions_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = ActiveRegions_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        ActiveRegions.push_back(readRegionFromValue(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator MaxGamesPerHost_member = obj.FindMember("MaxGamesPerHost");
                if (MaxGamesPerHost_member != obj.MemberEnd() && !MaxGamesPerHost_member->value.IsNull()) MaxGamesPerHost = MaxGamesPerHost_member->value.GetInt();
                const Value::ConstMemberIterator MinFreeGameSlots_member = obj.FindMember("MinFreeGameSlots");
                if (MinFreeGameSlots_member != obj.MemberEnd() && !MinFreeGameSlots_member->value.IsNull()) MinFreeGameSlots = MinFreeGameSlots_member->value.GetInt();
                const Value::ConstMemberIterator CommandLineTemplate_member = obj.FindMember("CommandLineTemplate");
                if (CommandLineTemplate_member != obj.MemberEnd() && !CommandLineTemplate_member->value.IsNull()) CommandLineTemplate = CommandLineTemplate_member->value.GetString();
                const Value::ConstMemberIterator ExecutablePath_member = obj.FindMember("ExecutablePath");
                if (ExecutablePath_member != obj.MemberEnd() && !ExecutablePath_member->value.IsNull()) ExecutablePath = ExecutablePath_member->value.GetString();
                const Value::ConstMemberIterator Comment_member = obj.FindMember("Comment");
                if (Comment_member != obj.MemberEnd() && !Comment_member->value.IsNull()) Comment = Comment_member->value.GetString();
                const Value::ConstMemberIterator Timestamp_member = obj.FindMember("Timestamp");
                if (Timestamp_member != obj.MemberEnd() && !Timestamp_member->value.IsNull()) Timestamp = readDatetime(Timestamp_member->value);
                const Value::ConstMemberIterator TitleId_member = obj.FindMember("TitleId");
                if (TitleId_member != obj.MemberEnd() && !TitleId_member->value.IsNull()) TitleId = TitleId_member->value.GetString();
                const Value::ConstMemberIterator Status_member = obj.FindMember("Status");
                if (Status_member != obj.MemberEnd() && !Status_member->value.IsNull()) Status = readGameBuildStatusFromValue(Status_member->value);

                return true;
            }
        };

        struct ModifyUserVirtualCurrencyResult : public PlayFabBaseModel
        {
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

        enum PushSetupPlatform
        {
            PushSetupPlatformGCM,
            PushSetupPlatformAPNS,
            PushSetupPlatformAPNS_SANDBOX
        };

        inline void writePushSetupPlatformEnumJSON(PushSetupPlatform enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case PushSetupPlatformGCM: writer.String("GCM"); break;
            case PushSetupPlatformAPNS: writer.String("APNS"); break;
            case PushSetupPlatformAPNS_SANDBOX: writer.String("APNS_SANDBOX"); break;

            }
        }

        inline PushSetupPlatform readPushSetupPlatformFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<PushSetupPlatform>(obj.GetInt());

            static std::map<const char *, PushSetupPlatform, PlayFabServerSdk::StringCompare> _PushSetupPlatformMap;
            if (_PushSetupPlatformMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _PushSetupPlatformMap["GCM"] = PushSetupPlatformGCM;
                _PushSetupPlatformMap["APNS"] = PushSetupPlatformAPNS;
                _PushSetupPlatformMap["APNS_SANDBOX"] = PushSetupPlatformAPNS_SANDBOX;

            }

            auto output = _PushSetupPlatformMap.find(obj.GetString());
            if (output != _PushSetupPlatformMap.end())
                return output->second;

            return PushSetupPlatformGCM; // Basically critical fail
        }

        struct RandomResultTable : public PlayFabBaseModel
        {
            AZStd::string TableId;
            std::list<ResultTableNode> Nodes;

            RandomResultTable() :
                PlayFabBaseModel(),
                TableId(),
                Nodes()
            {}

            RandomResultTable(const RandomResultTable& src) :
                PlayFabBaseModel(),
                TableId(src.TableId),
                Nodes(src.Nodes)
            {}

            RandomResultTable(const rapidjson::Value& obj) : RandomResultTable()
            {
                readFromValue(obj);
            }

            ~RandomResultTable()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("TableId");
                writer.String(TableId.c_str());
                writer.String("Nodes");
                writer.StartArray();
                for (std::list<ResultTableNode>::iterator iter = Nodes.begin(); iter != Nodes.end(); iter++) {
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TableId_member = obj.FindMember("TableId");
                if (TableId_member != obj.MemberEnd() && !TableId_member->value.IsNull()) TableId = TableId_member->value.GetString();
                const Value::ConstMemberIterator Nodes_member = obj.FindMember("Nodes");
                if (Nodes_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Nodes_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Nodes.push_back(ResultTableNode(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct RefundPurchaseRequest : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            AZStd::string OrderId;
            AZStd::string Reason;

            RefundPurchaseRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                OrderId(),
                Reason()
            {}

            RefundPurchaseRequest(const RefundPurchaseRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                OrderId(src.OrderId),
                Reason(src.Reason)
            {}

            RefundPurchaseRequest(const rapidjson::Value& obj) : RefundPurchaseRequest()
            {
                readFromValue(obj);
            }

            ~RefundPurchaseRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                writer.String("OrderId");
                writer.String(OrderId.c_str());
                if (Reason.length() > 0) {
                    writer.String("Reason");
                    writer.String(Reason.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator OrderId_member = obj.FindMember("OrderId");
                if (OrderId_member != obj.MemberEnd() && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();
                const Value::ConstMemberIterator Reason_member = obj.FindMember("Reason");
                if (Reason_member != obj.MemberEnd() && !Reason_member->value.IsNull()) Reason = Reason_member->value.GetString();

                return true;
            }
        };

        struct RefundPurchaseResponse : public PlayFabBaseModel
        {
            AZStd::string PurchaseStatus;

            RefundPurchaseResponse() :
                PlayFabBaseModel(),
                PurchaseStatus()
            {}

            RefundPurchaseResponse(const RefundPurchaseResponse& src) :
                PlayFabBaseModel(),
                PurchaseStatus(src.PurchaseStatus)
            {}

            RefundPurchaseResponse(const rapidjson::Value& obj) : RefundPurchaseResponse()
            {
                readFromValue(obj);
            }

            ~RefundPurchaseResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PurchaseStatus.length() > 0) {
                    writer.String("PurchaseStatus");
                    writer.String(PurchaseStatus.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PurchaseStatus_member = obj.FindMember("PurchaseStatus");
                if (PurchaseStatus_member != obj.MemberEnd() && !PurchaseStatus_member->value.IsNull()) PurchaseStatus = PurchaseStatus_member->value.GetString();

                return true;
            }
        };

        struct RemovePlayerTagRequest : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            AZStd::string TagName;

            RemovePlayerTagRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                TagName()
            {}

            RemovePlayerTagRequest(const RemovePlayerTagRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                TagName(src.TagName)
            {}

            RemovePlayerTagRequest(const rapidjson::Value& obj) : RemovePlayerTagRequest()
            {
                readFromValue(obj);
            }

            ~RemovePlayerTagRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                writer.String("TagName");
                writer.String(TagName.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator TagName_member = obj.FindMember("TagName");
                if (TagName_member != obj.MemberEnd() && !TagName_member->value.IsNull()) TagName = TagName_member->value.GetString();

                return true;
            }
        };

        struct RemovePlayerTagResult : public PlayFabBaseModel
        {

            RemovePlayerTagResult() :
                PlayFabBaseModel()
            {}

            RemovePlayerTagResult(const RemovePlayerTagResult& src) :
                PlayFabBaseModel()
            {}

            RemovePlayerTagResult(const rapidjson::Value& obj) : RemovePlayerTagResult()
            {
                readFromValue(obj);
            }

            ~RemovePlayerTagResult()
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

        struct RemoveServerBuildRequest : public PlayFabBaseModel
        {
            AZStd::string BuildId;

            RemoveServerBuildRequest() :
                PlayFabBaseModel(),
                BuildId()
            {}

            RemoveServerBuildRequest(const RemoveServerBuildRequest& src) :
                PlayFabBaseModel(),
                BuildId(src.BuildId)
            {}

            RemoveServerBuildRequest(const rapidjson::Value& obj) : RemoveServerBuildRequest()
            {
                readFromValue(obj);
            }

            ~RemoveServerBuildRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("BuildId");
                writer.String(BuildId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BuildId_member = obj.FindMember("BuildId");
                if (BuildId_member != obj.MemberEnd() && !BuildId_member->value.IsNull()) BuildId = BuildId_member->value.GetString();

                return true;
            }
        };

        struct RemoveServerBuildResult : public PlayFabBaseModel
        {

            RemoveServerBuildResult() :
                PlayFabBaseModel()
            {}

            RemoveServerBuildResult(const RemoveServerBuildResult& src) :
                PlayFabBaseModel()
            {}

            RemoveServerBuildResult(const rapidjson::Value& obj) : RemoveServerBuildResult()
            {
                readFromValue(obj);
            }

            ~RemoveServerBuildResult()
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

        struct RemoveVirtualCurrencyTypesRequest : public PlayFabBaseModel
        {
            std::list<VirtualCurrencyData> VirtualCurrencies;

            RemoveVirtualCurrencyTypesRequest() :
                PlayFabBaseModel(),
                VirtualCurrencies()
            {}

            RemoveVirtualCurrencyTypesRequest(const RemoveVirtualCurrencyTypesRequest& src) :
                PlayFabBaseModel(),
                VirtualCurrencies(src.VirtualCurrencies)
            {}

            RemoveVirtualCurrencyTypesRequest(const rapidjson::Value& obj) : RemoveVirtualCurrencyTypesRequest()
            {
                readFromValue(obj);
            }

            ~RemoveVirtualCurrencyTypesRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("VirtualCurrencies");
                writer.StartArray();
                for (std::list<VirtualCurrencyData>::iterator iter = VirtualCurrencies.begin(); iter != VirtualCurrencies.end(); iter++) {
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator VirtualCurrencies_member = obj.FindMember("VirtualCurrencies");
                if (VirtualCurrencies_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = VirtualCurrencies_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        VirtualCurrencies.push_back(VirtualCurrencyData(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct ResetCharacterStatisticsRequest : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            AZStd::string CharacterId;

            ResetCharacterStatisticsRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId()
            {}

            ResetCharacterStatisticsRequest(const ResetCharacterStatisticsRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId)
            {}

            ResetCharacterStatisticsRequest(const rapidjson::Value& obj) : ResetCharacterStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~ResetCharacterStatisticsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                writer.String("CharacterId");
                writer.String(CharacterId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();

                return true;
            }
        };

        struct ResetCharacterStatisticsResult : public PlayFabBaseModel
        {

            ResetCharacterStatisticsResult() :
                PlayFabBaseModel()
            {}

            ResetCharacterStatisticsResult(const ResetCharacterStatisticsResult& src) :
                PlayFabBaseModel()
            {}

            ResetCharacterStatisticsResult(const rapidjson::Value& obj) : ResetCharacterStatisticsResult()
            {
                readFromValue(obj);
            }

            ~ResetCharacterStatisticsResult()
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

        struct UserCredentials : public PlayFabBaseModel
        {
            AZStd::string Username;

            UserCredentials() :
                PlayFabBaseModel(),
                Username()
            {}

            UserCredentials(const UserCredentials& src) :
                PlayFabBaseModel(),
                Username(src.Username)
            {}

            UserCredentials(const rapidjson::Value& obj) : UserCredentials()
            {
                readFromValue(obj);
            }

            ~UserCredentials()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Username");
                writer.String(Username.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Username_member = obj.FindMember("Username");
                if (Username_member != obj.MemberEnd() && !Username_member->value.IsNull()) Username = Username_member->value.GetString();

                return true;
            }
        };

        struct ResetUsersRequest : public PlayFabBaseModel
        {
            std::list<UserCredentials> Users;

            ResetUsersRequest() :
                PlayFabBaseModel(),
                Users()
            {}

            ResetUsersRequest(const ResetUsersRequest& src) :
                PlayFabBaseModel(),
                Users(src.Users)
            {}

            ResetUsersRequest(const rapidjson::Value& obj) : ResetUsersRequest()
            {
                readFromValue(obj);
            }

            ~ResetUsersRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Users");
                writer.StartArray();
                for (std::list<UserCredentials>::iterator iter = Users.begin(); iter != Users.end(); iter++) {
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Users_member = obj.FindMember("Users");
                if (Users_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Users_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Users.push_back(UserCredentials(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct ResetUserStatisticsRequest : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;

            ResetUserStatisticsRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            ResetUserStatisticsRequest(const ResetUserStatisticsRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            ResetUserStatisticsRequest(const rapidjson::Value& obj) : ResetUserStatisticsRequest()
            {
                readFromValue(obj);
            }

            ~ResetUserStatisticsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct ResetUserStatisticsResult : public PlayFabBaseModel
        {

            ResetUserStatisticsResult() :
                PlayFabBaseModel()
            {}

            ResetUserStatisticsResult(const ResetUserStatisticsResult& src) :
                PlayFabBaseModel()
            {}

            ResetUserStatisticsResult(const rapidjson::Value& obj) : ResetUserStatisticsResult()
            {
                readFromValue(obj);
            }

            ~ResetUserStatisticsResult()
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

        enum ResolutionOutcome
        {
            ResolutionOutcomeRevoke,
            ResolutionOutcomeReinstate,
            ResolutionOutcomeManual
        };

        inline void writeResolutionOutcomeEnumJSON(ResolutionOutcome enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case ResolutionOutcomeRevoke: writer.String("Revoke"); break;
            case ResolutionOutcomeReinstate: writer.String("Reinstate"); break;
            case ResolutionOutcomeManual: writer.String("Manual"); break;

            }
        }

        inline ResolutionOutcome readResolutionOutcomeFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<ResolutionOutcome>(obj.GetInt());

            static std::map<const char *, ResolutionOutcome, PlayFabServerSdk::StringCompare> _ResolutionOutcomeMap;
            if (_ResolutionOutcomeMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _ResolutionOutcomeMap["Revoke"] = ResolutionOutcomeRevoke;
                _ResolutionOutcomeMap["Reinstate"] = ResolutionOutcomeReinstate;
                _ResolutionOutcomeMap["Manual"] = ResolutionOutcomeManual;

            }

            auto output = _ResolutionOutcomeMap.find(obj.GetString());
            if (output != _ResolutionOutcomeMap.end())
                return output->second;

            return ResolutionOutcomeRevoke; // Basically critical fail
        }

        struct ResolvePurchaseDisputeRequest : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            AZStd::string OrderId;
            AZStd::string Reason;
            ResolutionOutcome Outcome;

            ResolvePurchaseDisputeRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                OrderId(),
                Reason(),
                Outcome()
            {}

            ResolvePurchaseDisputeRequest(const ResolvePurchaseDisputeRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                OrderId(src.OrderId),
                Reason(src.Reason),
                Outcome(src.Outcome)
            {}

            ResolvePurchaseDisputeRequest(const rapidjson::Value& obj) : ResolvePurchaseDisputeRequest()
            {
                readFromValue(obj);
            }

            ~ResolvePurchaseDisputeRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                writer.String("OrderId");
                writer.String(OrderId.c_str());
                if (Reason.length() > 0) {
                    writer.String("Reason");
                    writer.String(Reason.c_str());
                }
                writer.String("Outcome");
                writeResolutionOutcomeEnumJSON(Outcome, writer);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator OrderId_member = obj.FindMember("OrderId");
                if (OrderId_member != obj.MemberEnd() && !OrderId_member->value.IsNull()) OrderId = OrderId_member->value.GetString();
                const Value::ConstMemberIterator Reason_member = obj.FindMember("Reason");
                if (Reason_member != obj.MemberEnd() && !Reason_member->value.IsNull()) Reason = Reason_member->value.GetString();
                const Value::ConstMemberIterator Outcome_member = obj.FindMember("Outcome");
                if (Outcome_member != obj.MemberEnd() && !Outcome_member->value.IsNull()) Outcome = readResolutionOutcomeFromValue(Outcome_member->value);

                return true;
            }
        };

        struct ResolvePurchaseDisputeResponse : public PlayFabBaseModel
        {
            AZStd::string PurchaseStatus;

            ResolvePurchaseDisputeResponse() :
                PlayFabBaseModel(),
                PurchaseStatus()
            {}

            ResolvePurchaseDisputeResponse(const ResolvePurchaseDisputeResponse& src) :
                PlayFabBaseModel(),
                PurchaseStatus(src.PurchaseStatus)
            {}

            ResolvePurchaseDisputeResponse(const rapidjson::Value& obj) : ResolvePurchaseDisputeResponse()
            {
                readFromValue(obj);
            }

            ~ResolvePurchaseDisputeResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PurchaseStatus.length() > 0) {
                    writer.String("PurchaseStatus");
                    writer.String(PurchaseStatus.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PurchaseStatus_member = obj.FindMember("PurchaseStatus");
                if (PurchaseStatus_member != obj.MemberEnd() && !PurchaseStatus_member->value.IsNull()) PurchaseStatus = PurchaseStatus_member->value.GetString();

                return true;
            }
        };

        struct RevokeAllBansForUserRequest : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;

            RevokeAllBansForUserRequest() :
                PlayFabBaseModel(),
                PlayFabId()
            {}

            RevokeAllBansForUserRequest(const RevokeAllBansForUserRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId)
            {}

            RevokeAllBansForUserRequest(const rapidjson::Value& obj) : RevokeAllBansForUserRequest()
            {
                readFromValue(obj);
            }

            ~RevokeAllBansForUserRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct RevokeAllBansForUserResult : public PlayFabBaseModel
        {
            std::list<BanInfo> BanData;

            RevokeAllBansForUserResult() :
                PlayFabBaseModel(),
                BanData()
            {}

            RevokeAllBansForUserResult(const RevokeAllBansForUserResult& src) :
                PlayFabBaseModel(),
                BanData(src.BanData)
            {}

            RevokeAllBansForUserResult(const rapidjson::Value& obj) : RevokeAllBansForUserResult()
            {
                readFromValue(obj);
            }

            ~RevokeAllBansForUserResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!BanData.empty()) {
                    writer.String("BanData");
                    writer.StartArray();
                    for (std::list<BanInfo>::iterator iter = BanData.begin(); iter != BanData.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BanData_member = obj.FindMember("BanData");
                if (BanData_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = BanData_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        BanData.push_back(BanInfo(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct RevokeBansRequest : public PlayFabBaseModel
        {
            std::list<AZStd::string> BanIds;

            RevokeBansRequest() :
                PlayFabBaseModel(),
                BanIds()
            {}

            RevokeBansRequest(const RevokeBansRequest& src) :
                PlayFabBaseModel(),
                BanIds(src.BanIds)
            {}

            RevokeBansRequest(const rapidjson::Value& obj) : RevokeBansRequest()
            {
                readFromValue(obj);
            }

            ~RevokeBansRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("BanIds");
                writer.StartArray();
                for (std::list<AZStd::string>::iterator iter = BanIds.begin(); iter != BanIds.end(); iter++) {
                    writer.String(iter->c_str());
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BanIds_member = obj.FindMember("BanIds");
                if (BanIds_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = BanIds_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        BanIds.push_back(memberList[i].GetString());
                    }
                }

                return true;
            }
        };

        struct RevokeBansResult : public PlayFabBaseModel
        {
            std::list<BanInfo> BanData;

            RevokeBansResult() :
                PlayFabBaseModel(),
                BanData()
            {}

            RevokeBansResult(const RevokeBansResult& src) :
                PlayFabBaseModel(),
                BanData(src.BanData)
            {}

            RevokeBansResult(const rapidjson::Value& obj) : RevokeBansResult()
            {
                readFromValue(obj);
            }

            ~RevokeBansResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!BanData.empty()) {
                    writer.String("BanData");
                    writer.StartArray();
                    for (std::list<BanInfo>::iterator iter = BanData.begin(); iter != BanData.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BanData_member = obj.FindMember("BanData");
                if (BanData_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = BanData_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        BanData.push_back(BanInfo(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct RevokeInventoryItemRequest : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            AZStd::string CharacterId;
            AZStd::string ItemInstanceId;

            RevokeInventoryItemRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                CharacterId(),
                ItemInstanceId()
            {}

            RevokeInventoryItemRequest(const RevokeInventoryItemRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                CharacterId(src.CharacterId),
                ItemInstanceId(src.ItemInstanceId)
            {}

            RevokeInventoryItemRequest(const rapidjson::Value& obj) : RevokeInventoryItemRequest()
            {
                readFromValue(obj);
            }

            ~RevokeInventoryItemRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                if (CharacterId.length() > 0) {
                    writer.String("CharacterId");
                    writer.String(CharacterId.c_str());
                }
                writer.String("ItemInstanceId");
                writer.String(ItemInstanceId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator CharacterId_member = obj.FindMember("CharacterId");
                if (CharacterId_member != obj.MemberEnd() && !CharacterId_member->value.IsNull()) CharacterId = CharacterId_member->value.GetString();
                const Value::ConstMemberIterator ItemInstanceId_member = obj.FindMember("ItemInstanceId");
                if (ItemInstanceId_member != obj.MemberEnd() && !ItemInstanceId_member->value.IsNull()) ItemInstanceId = ItemInstanceId_member->value.GetString();

                return true;
            }
        };

        struct RevokeInventoryResult : public PlayFabBaseModel
        {

            RevokeInventoryResult() :
                PlayFabBaseModel()
            {}

            RevokeInventoryResult(const RevokeInventoryResult& src) :
                PlayFabBaseModel()
            {}

            RevokeInventoryResult(const rapidjson::Value& obj) : RevokeInventoryResult()
            {
                readFromValue(obj);
            }

            ~RevokeInventoryResult()
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

        struct RunTaskRequest : public PlayFabBaseModel
        {
            NameIdentifier* Identifier;

            RunTaskRequest() :
                PlayFabBaseModel(),
                Identifier(nullptr)
            {}

            RunTaskRequest(const RunTaskRequest& src) :
                PlayFabBaseModel(),
                Identifier(src.Identifier ? new NameIdentifier(*src.Identifier) : nullptr)
            {}

            RunTaskRequest(const rapidjson::Value& obj) : RunTaskRequest()
            {
                readFromValue(obj);
            }

            ~RunTaskRequest()
            {
                if (Identifier != nullptr) delete Identifier;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Identifier != nullptr) {
                    writer.String("Identifier");
                    Identifier->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Identifier_member = obj.FindMember("Identifier");
                if (Identifier_member != obj.MemberEnd() && !Identifier_member->value.IsNull()) Identifier = new NameIdentifier(Identifier_member->value);

                return true;
            }
        };

        struct RunTaskResult : public PlayFabBaseModel
        {
            AZStd::string TaskInstanceId;

            RunTaskResult() :
                PlayFabBaseModel(),
                TaskInstanceId()
            {}

            RunTaskResult(const RunTaskResult& src) :
                PlayFabBaseModel(),
                TaskInstanceId(src.TaskInstanceId)
            {}

            RunTaskResult(const rapidjson::Value& obj) : RunTaskResult()
            {
                readFromValue(obj);
            }

            ~RunTaskResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (TaskInstanceId.length() > 0) {
                    writer.String("TaskInstanceId");
                    writer.String(TaskInstanceId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator TaskInstanceId_member = obj.FindMember("TaskInstanceId");
                if (TaskInstanceId_member != obj.MemberEnd() && !TaskInstanceId_member->value.IsNull()) TaskInstanceId = TaskInstanceId_member->value.GetString();

                return true;
            }
        };

        struct SendAccountRecoveryEmailRequest : public PlayFabBaseModel
        {
            AZStd::string Email;

            SendAccountRecoveryEmailRequest() :
                PlayFabBaseModel(),
                Email()
            {}

            SendAccountRecoveryEmailRequest(const SendAccountRecoveryEmailRequest& src) :
                PlayFabBaseModel(),
                Email(src.Email)
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
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Email_member = obj.FindMember("Email");
                if (Email_member != obj.MemberEnd() && !Email_member->value.IsNull()) Email = Email_member->value.GetString();

                return true;
            }
        };

        struct SendAccountRecoveryEmailResult : public PlayFabBaseModel
        {

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

        struct SetPlayerSecretRequest : public PlayFabBaseModel
        {
            AZStd::string PlayerSecret;
            AZStd::string PlayFabId;

            SetPlayerSecretRequest() :
                PlayFabBaseModel(),
                PlayerSecret(),
                PlayFabId()
            {}

            SetPlayerSecretRequest(const SetPlayerSecretRequest& src) :
                PlayFabBaseModel(),
                PlayerSecret(src.PlayerSecret),
                PlayFabId(src.PlayFabId)
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
                writer.String("PlayerSecret");
                writer.String(PlayerSecret.c_str());
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayerSecret_member = obj.FindMember("PlayerSecret");
                if (PlayerSecret_member != obj.MemberEnd() && !PlayerSecret_member->value.IsNull()) PlayerSecret = PlayerSecret_member->value.GetString();
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();

                return true;
            }
        };

        struct SetPlayerSecretResult : public PlayFabBaseModel
        {

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

        struct SetPublishedRevisionRequest : public PlayFabBaseModel
        {
            Int32 Version;
            Int32 Revision;

            SetPublishedRevisionRequest() :
                PlayFabBaseModel(),
                Version(0),
                Revision(0)
            {}

            SetPublishedRevisionRequest(const SetPublishedRevisionRequest& src) :
                PlayFabBaseModel(),
                Version(src.Version),
                Revision(src.Revision)
            {}

            SetPublishedRevisionRequest(const rapidjson::Value& obj) : SetPublishedRevisionRequest()
            {
                readFromValue(obj);
            }

            ~SetPublishedRevisionRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Version");
                writer.Int(Version);
                writer.String("Revision");
                writer.Int(Revision);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator Revision_member = obj.FindMember("Revision");
                if (Revision_member != obj.MemberEnd() && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();

                return true;
            }
        };

        struct SetPublishedRevisionResult : public PlayFabBaseModel
        {

            SetPublishedRevisionResult() :
                PlayFabBaseModel()
            {}

            SetPublishedRevisionResult(const SetPublishedRevisionResult& src) :
                PlayFabBaseModel()
            {}

            SetPublishedRevisionResult(const rapidjson::Value& obj) : SetPublishedRevisionResult()
            {
                readFromValue(obj);
            }

            ~SetPublishedRevisionResult()
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

        struct SetPublisherDataRequest : public PlayFabBaseModel
        {
            AZStd::string Key;
            AZStd::string Value;

            SetPublisherDataRequest() :
                PlayFabBaseModel(),
                Key(),
                Value()
            {}

            SetPublisherDataRequest(const SetPublisherDataRequest& src) :
                PlayFabBaseModel(),
                Key(src.Key),
                Value(src.Value)
            {}

            SetPublisherDataRequest(const rapidjson::Value& obj) : SetPublisherDataRequest()
            {
                readFromValue(obj);
            }

            ~SetPublisherDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Key");
                writer.String(Key.c_str());
                if (Value.length() > 0) {
                    writer.String("Value");
                    writer.String(Value.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
                if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
                const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
                if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetString();

                return true;
            }
        };

        struct SetPublisherDataResult : public PlayFabBaseModel
        {

            SetPublisherDataResult() :
                PlayFabBaseModel()
            {}

            SetPublisherDataResult(const SetPublisherDataResult& src) :
                PlayFabBaseModel()
            {}

            SetPublisherDataResult(const rapidjson::Value& obj) : SetPublisherDataResult()
            {
                readFromValue(obj);
            }

            ~SetPublisherDataResult()
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

        struct SetTitleDataRequest : public PlayFabBaseModel
        {
            AZStd::string Key;
            AZStd::string Value;

            SetTitleDataRequest() :
                PlayFabBaseModel(),
                Key(),
                Value()
            {}

            SetTitleDataRequest(const SetTitleDataRequest& src) :
                PlayFabBaseModel(),
                Key(src.Key),
                Value(src.Value)
            {}

            SetTitleDataRequest(const rapidjson::Value& obj) : SetTitleDataRequest()
            {
                readFromValue(obj);
            }

            ~SetTitleDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Key");
                writer.String(Key.c_str());
                if (Value.length() > 0) {
                    writer.String("Value");
                    writer.String(Value.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
                if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
                const Value::ConstMemberIterator Value_member = obj.FindMember("Value");
                if (Value_member != obj.MemberEnd() && !Value_member->value.IsNull()) Value = Value_member->value.GetString();

                return true;
            }
        };

        struct SetTitleDataResult : public PlayFabBaseModel
        {

            SetTitleDataResult() :
                PlayFabBaseModel()
            {}

            SetTitleDataResult(const SetTitleDataResult& src) :
                PlayFabBaseModel()
            {}

            SetTitleDataResult(const rapidjson::Value& obj) : SetTitleDataResult()
            {
                readFromValue(obj);
            }

            ~SetTitleDataResult()
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

        struct SetupPushNotificationRequest : public PlayFabBaseModel
        {
            AZStd::string Name;
            PushSetupPlatform Platform;
            AZStd::string Key;
            AZStd::string Credential;
            bool OverwriteOldARN;

            SetupPushNotificationRequest() :
                PlayFabBaseModel(),
                Name(),
                Platform(),
                Key(),
                Credential(),
                OverwriteOldARN(false)
            {}

            SetupPushNotificationRequest(const SetupPushNotificationRequest& src) :
                PlayFabBaseModel(),
                Name(src.Name),
                Platform(src.Platform),
                Key(src.Key),
                Credential(src.Credential),
                OverwriteOldARN(src.OverwriteOldARN)
            {}

            SetupPushNotificationRequest(const rapidjson::Value& obj) : SetupPushNotificationRequest()
            {
                readFromValue(obj);
            }

            ~SetupPushNotificationRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Name");
                writer.String(Name.c_str());
                writer.String("Platform");
                writePushSetupPlatformEnumJSON(Platform, writer);
                if (Key.length() > 0) {
                    writer.String("Key");
                    writer.String(Key.c_str());
                }
                writer.String("Credential");
                writer.String(Credential.c_str());
                writer.String("OverwriteOldARN");
                writer.Bool(OverwriteOldARN);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
                const Value::ConstMemberIterator Platform_member = obj.FindMember("Platform");
                if (Platform_member != obj.MemberEnd() && !Platform_member->value.IsNull()) Platform = readPushSetupPlatformFromValue(Platform_member->value);
                const Value::ConstMemberIterator Key_member = obj.FindMember("Key");
                if (Key_member != obj.MemberEnd() && !Key_member->value.IsNull()) Key = Key_member->value.GetString();
                const Value::ConstMemberIterator Credential_member = obj.FindMember("Credential");
                if (Credential_member != obj.MemberEnd() && !Credential_member->value.IsNull()) Credential = Credential_member->value.GetString();
                const Value::ConstMemberIterator OverwriteOldARN_member = obj.FindMember("OverwriteOldARN");
                if (OverwriteOldARN_member != obj.MemberEnd() && !OverwriteOldARN_member->value.IsNull()) OverwriteOldARN = OverwriteOldARN_member->value.GetBool();

                return true;
            }
        };

        struct SetupPushNotificationResult : public PlayFabBaseModel
        {
            AZStd::string ARN;

            SetupPushNotificationResult() :
                PlayFabBaseModel(),
                ARN()
            {}

            SetupPushNotificationResult(const SetupPushNotificationResult& src) :
                PlayFabBaseModel(),
                ARN(src.ARN)
            {}

            SetupPushNotificationResult(const rapidjson::Value& obj) : SetupPushNotificationResult()
            {
                readFromValue(obj);
            }

            ~SetupPushNotificationResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (ARN.length() > 0) {
                    writer.String("ARN");
                    writer.String(ARN.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator ARN_member = obj.FindMember("ARN");
                if (ARN_member != obj.MemberEnd() && !ARN_member->value.IsNull()) ARN = ARN_member->value.GetString();

                return true;
            }
        };

        enum StatisticVersionArchivalStatus
        {
            StatisticVersionArchivalStatusNotScheduled,
            StatisticVersionArchivalStatusScheduled,
            StatisticVersionArchivalStatusQueued,
            StatisticVersionArchivalStatusInProgress,
            StatisticVersionArchivalStatusComplete
        };

        inline void writeStatisticVersionArchivalStatusEnumJSON(StatisticVersionArchivalStatus enumVal, PFStringJsonWriter& writer)
        {
            switch (enumVal)
            {
            case StatisticVersionArchivalStatusNotScheduled: writer.String("NotScheduled"); break;
            case StatisticVersionArchivalStatusScheduled: writer.String("Scheduled"); break;
            case StatisticVersionArchivalStatusQueued: writer.String("Queued"); break;
            case StatisticVersionArchivalStatusInProgress: writer.String("InProgress"); break;
            case StatisticVersionArchivalStatusComplete: writer.String("Complete"); break;

            }
        }

        inline StatisticVersionArchivalStatus readStatisticVersionArchivalStatusFromValue(const rapidjson::Value& obj)
        {
            // #THIRD_KIND_PLAYFAB_GAME_STATE_DESERIALISATION_FIX: - The json response from the server for some enums may still be numeric
            if (obj.IsNumber())
                return static_cast<StatisticVersionArchivalStatus>(obj.GetInt());

            static std::map<const char *, StatisticVersionArchivalStatus, PlayFabServerSdk::StringCompare> _StatisticVersionArchivalStatusMap;
            if (_StatisticVersionArchivalStatusMap.size() == 0)
            {
                // Auto-generate the map on the first use
                _StatisticVersionArchivalStatusMap["NotScheduled"] = StatisticVersionArchivalStatusNotScheduled;
                _StatisticVersionArchivalStatusMap["Scheduled"] = StatisticVersionArchivalStatusScheduled;
                _StatisticVersionArchivalStatusMap["Queued"] = StatisticVersionArchivalStatusQueued;
                _StatisticVersionArchivalStatusMap["InProgress"] = StatisticVersionArchivalStatusInProgress;
                _StatisticVersionArchivalStatusMap["Complete"] = StatisticVersionArchivalStatusComplete;

            }

            auto output = _StatisticVersionArchivalStatusMap.find(obj.GetString());
            if (output != _StatisticVersionArchivalStatusMap.end())
                return output->second;

            return StatisticVersionArchivalStatusNotScheduled; // Basically critical fail
        }

        struct SubtractUserVirtualCurrencyRequest : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            AZStd::string VirtualCurrency;
            Int32 Amount;

            SubtractUserVirtualCurrencyRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                VirtualCurrency(),
                Amount(0)
            {}

            SubtractUserVirtualCurrencyRequest(const SubtractUserVirtualCurrencyRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
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
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                writer.String("VirtualCurrency");
                writer.String(VirtualCurrency.c_str());
                writer.String("Amount");
                writer.Int(Amount);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator VirtualCurrency_member = obj.FindMember("VirtualCurrency");
                if (VirtualCurrency_member != obj.MemberEnd() && !VirtualCurrency_member->value.IsNull()) VirtualCurrency = VirtualCurrency_member->value.GetString();
                const Value::ConstMemberIterator Amount_member = obj.FindMember("Amount");
                if (Amount_member != obj.MemberEnd() && !Amount_member->value.IsNull()) Amount = Amount_member->value.GetInt();

                return true;
            }
        };

        struct UpdateBanRequest : public PlayFabBaseModel
        {
            AZStd::string BanId;
            AZStd::string Reason;
            OptionalTime Expires;
            AZStd::string IPAddress;
            AZStd::string MACAddress;
            OptionalBool Permanent;
            OptionalBool Active;

            UpdateBanRequest() :
                PlayFabBaseModel(),
                BanId(),
                Reason(),
                Expires(),
                IPAddress(),
                MACAddress(),
                Permanent(),
                Active()
            {}

            UpdateBanRequest(const UpdateBanRequest& src) :
                PlayFabBaseModel(),
                BanId(src.BanId),
                Reason(src.Reason),
                Expires(src.Expires),
                IPAddress(src.IPAddress),
                MACAddress(src.MACAddress),
                Permanent(src.Permanent),
                Active(src.Active)
            {}

            UpdateBanRequest(const rapidjson::Value& obj) : UpdateBanRequest()
            {
                readFromValue(obj);
            }

            ~UpdateBanRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("BanId");
                writer.String(BanId.c_str());
                if (Reason.length() > 0) {
                    writer.String("Reason");
                    writer.String(Reason.c_str());
                }
                if (Expires.notNull()) {
                    writer.String("Expires");
                    writeDatetime(Expires, writer);
                }
                if (IPAddress.length() > 0) {
                    writer.String("IPAddress");
                    writer.String(IPAddress.c_str());
                }
                if (MACAddress.length() > 0) {
                    writer.String("MACAddress");
                    writer.String(MACAddress.c_str());
                }
                if (Permanent.notNull()) {
                    writer.String("Permanent");
                    writer.Bool(Permanent);
                }
                if (Active.notNull()) {
                    writer.String("Active");
                    writer.Bool(Active);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BanId_member = obj.FindMember("BanId");
                if (BanId_member != obj.MemberEnd() && !BanId_member->value.IsNull()) BanId = BanId_member->value.GetString();
                const Value::ConstMemberIterator Reason_member = obj.FindMember("Reason");
                if (Reason_member != obj.MemberEnd() && !Reason_member->value.IsNull()) Reason = Reason_member->value.GetString();
                const Value::ConstMemberIterator Expires_member = obj.FindMember("Expires");
                if (Expires_member != obj.MemberEnd() && !Expires_member->value.IsNull()) Expires = readDatetime(Expires_member->value);
                const Value::ConstMemberIterator IPAddress_member = obj.FindMember("IPAddress");
                if (IPAddress_member != obj.MemberEnd() && !IPAddress_member->value.IsNull()) IPAddress = IPAddress_member->value.GetString();
                const Value::ConstMemberIterator MACAddress_member = obj.FindMember("MACAddress");
                if (MACAddress_member != obj.MemberEnd() && !MACAddress_member->value.IsNull()) MACAddress = MACAddress_member->value.GetString();
                const Value::ConstMemberIterator Permanent_member = obj.FindMember("Permanent");
                if (Permanent_member != obj.MemberEnd() && !Permanent_member->value.IsNull()) Permanent = Permanent_member->value.GetBool();
                const Value::ConstMemberIterator Active_member = obj.FindMember("Active");
                if (Active_member != obj.MemberEnd() && !Active_member->value.IsNull()) Active = Active_member->value.GetBool();

                return true;
            }
        };

        struct UpdateBansRequest : public PlayFabBaseModel
        {
            std::list<UpdateBanRequest> Bans;

            UpdateBansRequest() :
                PlayFabBaseModel(),
                Bans()
            {}

            UpdateBansRequest(const UpdateBansRequest& src) :
                PlayFabBaseModel(),
                Bans(src.Bans)
            {}

            UpdateBansRequest(const rapidjson::Value& obj) : UpdateBansRequest()
            {
                readFromValue(obj);
            }

            ~UpdateBansRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Bans");
                writer.StartArray();
                for (std::list<UpdateBanRequest>::iterator iter = Bans.begin(); iter != Bans.end(); iter++) {
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Bans_member = obj.FindMember("Bans");
                if (Bans_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Bans_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Bans.push_back(UpdateBanRequest(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct UpdateBansResult : public PlayFabBaseModel
        {
            std::list<BanInfo> BanData;

            UpdateBansResult() :
                PlayFabBaseModel(),
                BanData()
            {}

            UpdateBansResult(const UpdateBansResult& src) :
                PlayFabBaseModel(),
                BanData(src.BanData)
            {}

            UpdateBansResult(const rapidjson::Value& obj) : UpdateBansResult()
            {
                readFromValue(obj);
            }

            ~UpdateBansResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (!BanData.empty()) {
                    writer.String("BanData");
                    writer.StartArray();
                    for (std::list<BanInfo>::iterator iter = BanData.begin(); iter != BanData.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator BanData_member = obj.FindMember("BanData");
                if (BanData_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = BanData_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        BanData.push_back(BanInfo(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct UpdateCatalogItemsRequest : public PlayFabBaseModel
        {
            AZStd::string CatalogVersion;
            OptionalBool SetAsDefaultCatalog;
            std::list<CatalogItem> Catalog;

            UpdateCatalogItemsRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                SetAsDefaultCatalog(),
                Catalog()
            {}

            UpdateCatalogItemsRequest(const UpdateCatalogItemsRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                SetAsDefaultCatalog(src.SetAsDefaultCatalog),
                Catalog(src.Catalog)
            {}

            UpdateCatalogItemsRequest(const rapidjson::Value& obj) : UpdateCatalogItemsRequest()
            {
                readFromValue(obj);
            }

            ~UpdateCatalogItemsRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                if (SetAsDefaultCatalog.notNull()) {
                    writer.String("SetAsDefaultCatalog");
                    writer.Bool(SetAsDefaultCatalog);
                }
                if (!Catalog.empty()) {
                    writer.String("Catalog");
                    writer.StartArray();
                    for (std::list<CatalogItem>::iterator iter = Catalog.begin(); iter != Catalog.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator SetAsDefaultCatalog_member = obj.FindMember("SetAsDefaultCatalog");
                if (SetAsDefaultCatalog_member != obj.MemberEnd() && !SetAsDefaultCatalog_member->value.IsNull()) SetAsDefaultCatalog = SetAsDefaultCatalog_member->value.GetBool();
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

        struct UpdateCatalogItemsResult : public PlayFabBaseModel
        {

            UpdateCatalogItemsResult() :
                PlayFabBaseModel()
            {}

            UpdateCatalogItemsResult(const UpdateCatalogItemsResult& src) :
                PlayFabBaseModel()
            {}

            UpdateCatalogItemsResult(const rapidjson::Value& obj) : UpdateCatalogItemsResult()
            {
                readFromValue(obj);
            }

            ~UpdateCatalogItemsResult()
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

        struct UpdateCloudScriptRequest : public PlayFabBaseModel
        {
            std::list<CloudScriptFile> Files;
            bool Publish;
            AZStd::string DeveloperPlayFabId;

            UpdateCloudScriptRequest() :
                PlayFabBaseModel(),
                Files(),
                Publish(false),
                DeveloperPlayFabId()
            {}

            UpdateCloudScriptRequest(const UpdateCloudScriptRequest& src) :
                PlayFabBaseModel(),
                Files(src.Files),
                Publish(src.Publish),
                DeveloperPlayFabId(src.DeveloperPlayFabId)
            {}

            UpdateCloudScriptRequest(const rapidjson::Value& obj) : UpdateCloudScriptRequest()
            {
                readFromValue(obj);
            }

            ~UpdateCloudScriptRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Files");
                writer.StartArray();
                for (std::list<CloudScriptFile>::iterator iter = Files.begin(); iter != Files.end(); iter++) {
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.String("Publish");
                writer.Bool(Publish);
                if (DeveloperPlayFabId.length() > 0) {
                    writer.String("DeveloperPlayFabId");
                    writer.String(DeveloperPlayFabId.c_str());
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Files_member = obj.FindMember("Files");
                if (Files_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Files_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Files.push_back(CloudScriptFile(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator Publish_member = obj.FindMember("Publish");
                if (Publish_member != obj.MemberEnd() && !Publish_member->value.IsNull()) Publish = Publish_member->value.GetBool();
                const Value::ConstMemberIterator DeveloperPlayFabId_member = obj.FindMember("DeveloperPlayFabId");
                if (DeveloperPlayFabId_member != obj.MemberEnd() && !DeveloperPlayFabId_member->value.IsNull()) DeveloperPlayFabId = DeveloperPlayFabId_member->value.GetString();

                return true;
            }
        };

        struct UpdateCloudScriptResult : public PlayFabBaseModel
        {
            Int32 Version;
            Int32 Revision;

            UpdateCloudScriptResult() :
                PlayFabBaseModel(),
                Version(0),
                Revision(0)
            {}

            UpdateCloudScriptResult(const UpdateCloudScriptResult& src) :
                PlayFabBaseModel(),
                Version(src.Version),
                Revision(src.Revision)
            {}

            UpdateCloudScriptResult(const rapidjson::Value& obj) : UpdateCloudScriptResult()
            {
                readFromValue(obj);
            }

            ~UpdateCloudScriptResult()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("Version");
                writer.Int(Version);
                writer.String("Revision");
                writer.Int(Revision);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Version_member = obj.FindMember("Version");
                if (Version_member != obj.MemberEnd() && !Version_member->value.IsNull()) Version = Version_member->value.GetInt();
                const Value::ConstMemberIterator Revision_member = obj.FindMember("Revision");
                if (Revision_member != obj.MemberEnd() && !Revision_member->value.IsNull()) Revision = Revision_member->value.GetInt();

                return true;
            }
        };

        struct UpdatePlayerSharedSecretRequest : public PlayFabBaseModel
        {
            AZStd::string SecretKey;
            AZStd::string FriendlyName;
            bool Disabled;

            UpdatePlayerSharedSecretRequest() :
                PlayFabBaseModel(),
                SecretKey(),
                FriendlyName(),
                Disabled(false)
            {}

            UpdatePlayerSharedSecretRequest(const UpdatePlayerSharedSecretRequest& src) :
                PlayFabBaseModel(),
                SecretKey(src.SecretKey),
                FriendlyName(src.FriendlyName),
                Disabled(src.Disabled)
            {}

            UpdatePlayerSharedSecretRequest(const rapidjson::Value& obj) : UpdatePlayerSharedSecretRequest()
            {
                readFromValue(obj);
            }

            ~UpdatePlayerSharedSecretRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (SecretKey.length() > 0) {
                    writer.String("SecretKey");
                    writer.String(SecretKey.c_str());
                }
                if (FriendlyName.length() > 0) {
                    writer.String("FriendlyName");
                    writer.String(FriendlyName.c_str());
                }
                writer.String("Disabled");
                writer.Bool(Disabled);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator SecretKey_member = obj.FindMember("SecretKey");
                if (SecretKey_member != obj.MemberEnd() && !SecretKey_member->value.IsNull()) SecretKey = SecretKey_member->value.GetString();
                const Value::ConstMemberIterator FriendlyName_member = obj.FindMember("FriendlyName");
                if (FriendlyName_member != obj.MemberEnd() && !FriendlyName_member->value.IsNull()) FriendlyName = FriendlyName_member->value.GetString();
                const Value::ConstMemberIterator Disabled_member = obj.FindMember("Disabled");
                if (Disabled_member != obj.MemberEnd() && !Disabled_member->value.IsNull()) Disabled = Disabled_member->value.GetBool();

                return true;
            }
        };

        struct UpdatePlayerSharedSecretResult : public PlayFabBaseModel
        {

            UpdatePlayerSharedSecretResult() :
                PlayFabBaseModel()
            {}

            UpdatePlayerSharedSecretResult(const UpdatePlayerSharedSecretResult& src) :
                PlayFabBaseModel()
            {}

            UpdatePlayerSharedSecretResult(const rapidjson::Value& obj) : UpdatePlayerSharedSecretResult()
            {
                readFromValue(obj);
            }

            ~UpdatePlayerSharedSecretResult()
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

        struct UpdatePlayerStatisticDefinitionRequest : public PlayFabBaseModel
        {
            AZStd::string StatisticName;
            Boxed<StatisticResetIntervalOption> VersionChangeInterval;
            Boxed<StatisticAggregationMethod> AggregationMethod;

            UpdatePlayerStatisticDefinitionRequest() :
                PlayFabBaseModel(),
                StatisticName(),
                VersionChangeInterval(),
                AggregationMethod()
            {}

            UpdatePlayerStatisticDefinitionRequest(const UpdatePlayerStatisticDefinitionRequest& src) :
                PlayFabBaseModel(),
                StatisticName(src.StatisticName),
                VersionChangeInterval(src.VersionChangeInterval),
                AggregationMethod(src.AggregationMethod)
            {}

            UpdatePlayerStatisticDefinitionRequest(const rapidjson::Value& obj) : UpdatePlayerStatisticDefinitionRequest()
            {
                readFromValue(obj);
            }

            ~UpdatePlayerStatisticDefinitionRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("StatisticName");
                writer.String(StatisticName.c_str());
                if (VersionChangeInterval.notNull()) {
                    writer.String("VersionChangeInterval");
                    writeStatisticResetIntervalOptionEnumJSON(VersionChangeInterval, writer);
                }
                if (AggregationMethod.notNull()) {
                    writer.String("AggregationMethod");
                    writeStatisticAggregationMethodEnumJSON(AggregationMethod, writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator StatisticName_member = obj.FindMember("StatisticName");
                if (StatisticName_member != obj.MemberEnd() && !StatisticName_member->value.IsNull()) StatisticName = StatisticName_member->value.GetString();
                const Value::ConstMemberIterator VersionChangeInterval_member = obj.FindMember("VersionChangeInterval");
                if (VersionChangeInterval_member != obj.MemberEnd() && !VersionChangeInterval_member->value.IsNull()) VersionChangeInterval = readStatisticResetIntervalOptionFromValue(VersionChangeInterval_member->value);
                const Value::ConstMemberIterator AggregationMethod_member = obj.FindMember("AggregationMethod");
                if (AggregationMethod_member != obj.MemberEnd() && !AggregationMethod_member->value.IsNull()) AggregationMethod = readStatisticAggregationMethodFromValue(AggregationMethod_member->value);

                return true;
            }
        };

        struct UpdatePlayerStatisticDefinitionResult : public PlayFabBaseModel
        {
            PlayerStatisticDefinition* Statistic;

            UpdatePlayerStatisticDefinitionResult() :
                PlayFabBaseModel(),
                Statistic(nullptr)
            {}

            UpdatePlayerStatisticDefinitionResult(const UpdatePlayerStatisticDefinitionResult& src) :
                PlayFabBaseModel(),
                Statistic(src.Statistic ? new PlayerStatisticDefinition(*src.Statistic) : nullptr)
            {}

            UpdatePlayerStatisticDefinitionResult(const rapidjson::Value& obj) : UpdatePlayerStatisticDefinitionResult()
            {
                readFromValue(obj);
            }

            ~UpdatePlayerStatisticDefinitionResult()
            {
                if (Statistic != nullptr) delete Statistic;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Statistic != nullptr) {
                    writer.String("Statistic");
                    Statistic->writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Statistic_member = obj.FindMember("Statistic");
                if (Statistic_member != obj.MemberEnd() && !Statistic_member->value.IsNull()) Statistic = new PlayerStatisticDefinition(Statistic_member->value);

                return true;
            }
        };

        struct UpdatePolicyRequest : public PlayFabBaseModel
        {
            AZStd::string PolicyName;
            std::list<PermissionStatement> Statements;
            bool OverwritePolicy;

            UpdatePolicyRequest() :
                PlayFabBaseModel(),
                PolicyName(),
                Statements(),
                OverwritePolicy(false)
            {}

            UpdatePolicyRequest(const UpdatePolicyRequest& src) :
                PlayFabBaseModel(),
                PolicyName(src.PolicyName),
                Statements(src.Statements),
                OverwritePolicy(src.OverwritePolicy)
            {}

            UpdatePolicyRequest(const rapidjson::Value& obj) : UpdatePolicyRequest()
            {
                readFromValue(obj);
            }

            ~UpdatePolicyRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PolicyName");
                writer.String(PolicyName.c_str());
                writer.String("Statements");
                writer.StartArray();
                for (std::list<PermissionStatement>::iterator iter = Statements.begin(); iter != Statements.end(); iter++) {
                    iter->writeJSON(writer);
                }
                writer.EndArray();
                writer.String("OverwritePolicy");
                writer.Bool(OverwritePolicy);
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PolicyName_member = obj.FindMember("PolicyName");
                if (PolicyName_member != obj.MemberEnd() && !PolicyName_member->value.IsNull()) PolicyName = PolicyName_member->value.GetString();
                const Value::ConstMemberIterator Statements_member = obj.FindMember("Statements");
                if (Statements_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Statements_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Statements.push_back(PermissionStatement(memberList[i]));
                    }
                }
                const Value::ConstMemberIterator OverwritePolicy_member = obj.FindMember("OverwritePolicy");
                if (OverwritePolicy_member != obj.MemberEnd() && !OverwritePolicy_member->value.IsNull()) OverwritePolicy = OverwritePolicy_member->value.GetBool();

                return true;
            }
        };

        struct UpdatePolicyResponse : public PlayFabBaseModel
        {
            AZStd::string PolicyName;
            std::list<PermissionStatement> Statements;

            UpdatePolicyResponse() :
                PlayFabBaseModel(),
                PolicyName(),
                Statements()
            {}

            UpdatePolicyResponse(const UpdatePolicyResponse& src) :
                PlayFabBaseModel(),
                PolicyName(src.PolicyName),
                Statements(src.Statements)
            {}

            UpdatePolicyResponse(const rapidjson::Value& obj) : UpdatePolicyResponse()
            {
                readFromValue(obj);
            }

            ~UpdatePolicyResponse()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (PolicyName.length() > 0) {
                    writer.String("PolicyName");
                    writer.String(PolicyName.c_str());
                }
                if (!Statements.empty()) {
                    writer.String("Statements");
                    writer.StartArray();
                    for (std::list<PermissionStatement>::iterator iter = Statements.begin(); iter != Statements.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PolicyName_member = obj.FindMember("PolicyName");
                if (PolicyName_member != obj.MemberEnd() && !PolicyName_member->value.IsNull()) PolicyName = PolicyName_member->value.GetString();
                const Value::ConstMemberIterator Statements_member = obj.FindMember("Statements");
                if (Statements_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Statements_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Statements.push_back(PermissionStatement(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct UpdateRandomResultTablesRequest : public PlayFabBaseModel
        {
            AZStd::string CatalogVersion;
            std::list<RandomResultTable> Tables;

            UpdateRandomResultTablesRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                Tables()
            {}

            UpdateRandomResultTablesRequest(const UpdateRandomResultTablesRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                Tables(src.Tables)
            {}

            UpdateRandomResultTablesRequest(const rapidjson::Value& obj) : UpdateRandomResultTablesRequest()
            {
                readFromValue(obj);
            }

            ~UpdateRandomResultTablesRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (CatalogVersion.length() > 0) {
                    writer.String("CatalogVersion");
                    writer.String(CatalogVersion.c_str());
                }
                if (!Tables.empty()) {
                    writer.String("Tables");
                    writer.StartArray();
                    for (std::list<RandomResultTable>::iterator iter = Tables.begin(); iter != Tables.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator Tables_member = obj.FindMember("Tables");
                if (Tables_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Tables_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Tables.push_back(RandomResultTable(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct UpdateRandomResultTablesResult : public PlayFabBaseModel
        {

            UpdateRandomResultTablesResult() :
                PlayFabBaseModel()
            {}

            UpdateRandomResultTablesResult(const UpdateRandomResultTablesResult& src) :
                PlayFabBaseModel()
            {}

            UpdateRandomResultTablesResult(const rapidjson::Value& obj) : UpdateRandomResultTablesResult()
            {
                readFromValue(obj);
            }

            ~UpdateRandomResultTablesResult()
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

        struct UpdateStoreItemsRequest : public PlayFabBaseModel
        {
            AZStd::string CatalogVersion;
            AZStd::string StoreId;
            StoreMarketingModel* MarketingData;
            std::list<StoreItem> Store;

            UpdateStoreItemsRequest() :
                PlayFabBaseModel(),
                CatalogVersion(),
                StoreId(),
                MarketingData(nullptr),
                Store()
            {}

            UpdateStoreItemsRequest(const UpdateStoreItemsRequest& src) :
                PlayFabBaseModel(),
                CatalogVersion(src.CatalogVersion),
                StoreId(src.StoreId),
                MarketingData(src.MarketingData ? new StoreMarketingModel(*src.MarketingData) : nullptr),
                Store(src.Store)
            {}

            UpdateStoreItemsRequest(const rapidjson::Value& obj) : UpdateStoreItemsRequest()
            {
                readFromValue(obj);
            }

            ~UpdateStoreItemsRequest()
            {
                if (MarketingData != nullptr) delete MarketingData;
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
                if (MarketingData != nullptr) {
                    writer.String("MarketingData");
                    MarketingData->writeJSON(writer);
                }
                if (!Store.empty()) {
                    writer.String("Store");
                    writer.StartArray();
                    for (std::list<StoreItem>::iterator iter = Store.begin(); iter != Store.end(); iter++) {
                        iter->writeJSON(writer);
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator CatalogVersion_member = obj.FindMember("CatalogVersion");
                if (CatalogVersion_member != obj.MemberEnd() && !CatalogVersion_member->value.IsNull()) CatalogVersion = CatalogVersion_member->value.GetString();
                const Value::ConstMemberIterator StoreId_member = obj.FindMember("StoreId");
                if (StoreId_member != obj.MemberEnd() && !StoreId_member->value.IsNull()) StoreId = StoreId_member->value.GetString();
                const Value::ConstMemberIterator MarketingData_member = obj.FindMember("MarketingData");
                if (MarketingData_member != obj.MemberEnd() && !MarketingData_member->value.IsNull()) MarketingData = new StoreMarketingModel(MarketingData_member->value);
                const Value::ConstMemberIterator Store_member = obj.FindMember("Store");
                if (Store_member != obj.MemberEnd()) {
                    const rapidjson::Value& memberList = Store_member->value;
                    for (SizeType i = 0; i < memberList.Size(); i++) {
                        Store.push_back(StoreItem(memberList[i]));
                    }
                }

                return true;
            }
        };

        struct UpdateStoreItemsResult : public PlayFabBaseModel
        {

            UpdateStoreItemsResult() :
                PlayFabBaseModel()
            {}

            UpdateStoreItemsResult(const UpdateStoreItemsResult& src) :
                PlayFabBaseModel()
            {}

            UpdateStoreItemsResult(const rapidjson::Value& obj) : UpdateStoreItemsResult()
            {
                readFromValue(obj);
            }

            ~UpdateStoreItemsResult()
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

        struct UpdateTaskRequest : public PlayFabBaseModel
        {
            NameIdentifier* Identifier;
            AZStd::string Name;
            AZStd::string Description;
            AZStd::string Schedule;
            bool IsActive;
            ScheduledTaskType Type;
            MultitypeVar Parameter;

            UpdateTaskRequest() :
                PlayFabBaseModel(),
                Identifier(nullptr),
                Name(),
                Description(),
                Schedule(),
                IsActive(false),
                Type(),
                Parameter()
            {}

            UpdateTaskRequest(const UpdateTaskRequest& src) :
                PlayFabBaseModel(),
                Identifier(src.Identifier ? new NameIdentifier(*src.Identifier) : nullptr),
                Name(src.Name),
                Description(src.Description),
                Schedule(src.Schedule),
                IsActive(src.IsActive),
                Type(src.Type),
                Parameter(src.Parameter)
            {}

            UpdateTaskRequest(const rapidjson::Value& obj) : UpdateTaskRequest()
            {
                readFromValue(obj);
            }

            ~UpdateTaskRequest()
            {
                if (Identifier != nullptr) delete Identifier;
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                if (Identifier != nullptr) {
                    writer.String("Identifier");
                    Identifier->writeJSON(writer);
                }
                writer.String("Name");
                writer.String(Name.c_str());
                if (Description.length() > 0) {
                    writer.String("Description");
                    writer.String(Description.c_str());
                }
                if (Schedule.length() > 0) {
                    writer.String("Schedule");
                    writer.String(Schedule.c_str());
                }
                writer.String("IsActive");
                writer.Bool(IsActive);
                writer.String("Type");
                writeScheduledTaskTypeEnumJSON(Type, writer);
                if (Parameter.notNull()) {
                    writer.String("Parameter");
                    Parameter.writeJSON(writer);
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator Identifier_member = obj.FindMember("Identifier");
                if (Identifier_member != obj.MemberEnd() && !Identifier_member->value.IsNull()) Identifier = new NameIdentifier(Identifier_member->value);
                const Value::ConstMemberIterator Name_member = obj.FindMember("Name");
                if (Name_member != obj.MemberEnd() && !Name_member->value.IsNull()) Name = Name_member->value.GetString();
                const Value::ConstMemberIterator Description_member = obj.FindMember("Description");
                if (Description_member != obj.MemberEnd() && !Description_member->value.IsNull()) Description = Description_member->value.GetString();
                const Value::ConstMemberIterator Schedule_member = obj.FindMember("Schedule");
                if (Schedule_member != obj.MemberEnd() && !Schedule_member->value.IsNull()) Schedule = Schedule_member->value.GetString();
                const Value::ConstMemberIterator IsActive_member = obj.FindMember("IsActive");
                if (IsActive_member != obj.MemberEnd() && !IsActive_member->value.IsNull()) IsActive = IsActive_member->value.GetBool();
                const Value::ConstMemberIterator Type_member = obj.FindMember("Type");
                if (Type_member != obj.MemberEnd() && !Type_member->value.IsNull()) Type = readScheduledTaskTypeFromValue(Type_member->value);
                const Value::ConstMemberIterator Parameter_member = obj.FindMember("Parameter");
                if (Parameter_member != obj.MemberEnd() && !Parameter_member->value.IsNull()) Parameter = MultitypeVar(Parameter_member->value);

                return true;
            }
        };

        struct UpdateUserDataRequest : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            std::map<AZStd::string, AZStd::string> Data;
            std::list<AZStd::string> KeysToRemove;
            Boxed<UserDataPermission> Permission;

            UpdateUserDataRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                Data(),
                KeysToRemove(),
                Permission()
            {}

            UpdateUserDataRequest(const UpdateUserDataRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
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
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartObject();
                    for (std::map<AZStd::string, AZStd::string>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                if (!KeysToRemove.empty()) {
                    writer.String("KeysToRemove");
                    writer.StartArray();
                    for (std::list<AZStd::string>::iterator iter = KeysToRemove.begin(); iter != KeysToRemove.end(); iter++) {
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
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
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

        struct UpdateUserInternalDataRequest : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            std::map<AZStd::string, AZStd::string> Data;
            std::list<AZStd::string> KeysToRemove;

            UpdateUserInternalDataRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                Data(),
                KeysToRemove()
            {}

            UpdateUserInternalDataRequest(const UpdateUserInternalDataRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
                Data(src.Data),
                KeysToRemove(src.KeysToRemove)
            {}

            UpdateUserInternalDataRequest(const rapidjson::Value& obj) : UpdateUserInternalDataRequest()
            {
                readFromValue(obj);
            }

            ~UpdateUserInternalDataRequest()
            {
            }

            void writeJSON(PFStringJsonWriter& writer) override
            {
                writer.StartObject();
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                if (!Data.empty()) {
                    writer.String("Data");
                    writer.StartObject();
                    for (std::map<AZStd::string, AZStd::string>::iterator iter = Data.begin(); iter != Data.end(); ++iter) {
                        writer.String(iter->first.c_str());
                        writer.String(iter->second.c_str());
                    }
                    writer.EndObject();
                }
                if (!KeysToRemove.empty()) {
                    writer.String("KeysToRemove");
                    writer.StartArray();
                    for (std::list<AZStd::string>::iterator iter = KeysToRemove.begin(); iter != KeysToRemove.end(); iter++) {
                        writer.String(iter->c_str());
                    }
                    writer.EndArray();
                }
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
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

                return true;
            }
        };

        struct UpdateUserTitleDisplayNameRequest : public PlayFabBaseModel
        {
            AZStd::string PlayFabId;
            AZStd::string DisplayName;

            UpdateUserTitleDisplayNameRequest() :
                PlayFabBaseModel(),
                PlayFabId(),
                DisplayName()
            {}

            UpdateUserTitleDisplayNameRequest(const UpdateUserTitleDisplayNameRequest& src) :
                PlayFabBaseModel(),
                PlayFabId(src.PlayFabId),
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
                writer.String("PlayFabId");
                writer.String(PlayFabId.c_str());
                writer.String("DisplayName");
                writer.String(DisplayName.c_str());
                writer.EndObject();
            }

            bool readFromValue(const rapidjson::Value& obj) override
            {
                const Value::ConstMemberIterator PlayFabId_member = obj.FindMember("PlayFabId");
                if (PlayFabId_member != obj.MemberEnd() && !PlayFabId_member->value.IsNull()) PlayFabId = PlayFabId_member->value.GetString();
                const Value::ConstMemberIterator DisplayName_member = obj.FindMember("DisplayName");
                if (DisplayName_member != obj.MemberEnd() && !DisplayName_member->value.IsNull()) DisplayName = DisplayName_member->value.GetString();

                return true;
            }
        };

        struct UpdateUserTitleDisplayNameResult : public PlayFabBaseModel
        {
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


    }
}
