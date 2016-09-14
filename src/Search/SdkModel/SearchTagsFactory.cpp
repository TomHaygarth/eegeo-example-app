// Copyright eeGeo Ltd (2012-2016), All Rights Reserved

#include "SearchTagsFactory.h"
#include "document.h"
#include "Types.h"
#include "FileHelpers.h"

namespace ExampleApp
{
    namespace Search
    {
        namespace SdkModel
        {
            void PopulateSearchTagsFromFile(
                                                Eegeo::Helpers::IFileIO& fileIO,
                                                const std::string& fileName,
                                                SearchTagRepository& searchTags)
            {
                const std::string& jsonText = Helpers::FileHelpers::GetFileContentsAsString(fileIO, fileName);
                rapidjson::Document document;
                
                if (document.Parse<0>(jsonText.c_str()).HasParseError())
                {
                    Eegeo_ASSERT(false, "Failed to parse tag to icon key mapping");
                }
                
                Eegeo_ASSERT(document.IsObject(), "Document root should be an object");
                
                const char* defaultReadableTagKeyName = "default_readable_tag";
                Eegeo_ASSERT(document.HasMember(defaultReadableTagKeyName), "no member named %s", defaultReadableTagKeyName);
                Eegeo_ASSERT(document[defaultReadableTagKeyName].IsString(), "value of %s was not a string", defaultReadableTagKeyName);
                const std::string defaultReadableTag = document[defaultReadableTagKeyName].GetString();
                
                const char* defaultIconJsonKeyName = "default_icon_key";
                Eegeo_ASSERT(document.HasMember(defaultIconJsonKeyName ), "no member named %s", defaultIconJsonKeyName );
                Eegeo_ASSERT(document[defaultIconJsonKeyName ].IsString(), "value of %s was not a string", defaultIconJsonKeyName );
                const TagIconKey defaultIconKey = document[defaultIconJsonKeyName].GetString();
                
                const char* tagsKeyName = "tags";
                Eegeo_ASSERT(document.HasMember(tagsKeyName), "no member named %s", tagsKeyName);
                
                const auto& tagsArray = document[tagsKeyName];
                Eegeo_ASSERT(tagsArray.IsArray(), "value of %s was not an array", tagsKeyName);
                searchTags.SetDefaultReadableTag(defaultReadableTag);
                searchTags.SetDefaultIconKey(defaultIconKey);
                
                for (rapidjson::Value::ConstValueIterator itr = tagsArray.Begin(); itr != tagsArray.End(); ++itr)
                {
                    const auto& tagElem = *itr;
                    
                    Eegeo_ASSERT(tagElem.IsObject(), "value of was not an object");
                    
                    const char* tagKeyName = "tag";
                    Eegeo_ASSERT(tagElem.HasMember(tagKeyName), "no member named %s", tagKeyName);
                    Eegeo_ASSERT(tagElem[tagKeyName].IsString(), "value of %s was not a string", tagKeyName);
                    const std::string tag = tagElem[tagKeyName].GetString();
                    
                    const char* readableTagKeyName = "readable_tag";
                    Eegeo_ASSERT(tagElem.HasMember(readableTagKeyName), "no member named %s", readableTagKeyName);
                    Eegeo_ASSERT(tagElem[readableTagKeyName].IsString(), "value of %s was not a string", readableTagKeyName);
                    const std::string readableTag = tagElem[readableTagKeyName].GetString();
                    
                    const char* iconKeyJsonKeyName= "icon_key";
                    Eegeo_ASSERT(tagElem.HasMember(iconKeyJsonKeyName), "no member named %s", iconKeyJsonKeyName);
                    Eegeo_ASSERT(tagElem[iconKeyJsonKeyName].IsString(), "value of %s was not a string", iconKeyJsonKeyName);
                    const TagIconKey iconKey = tagElem[iconKeyJsonKeyName].GetString();
                    
                    SearchTag t(tag, readableTag, iconKey);
                    searchTags.AddItem(t);
                }
            }
        }
    }
}