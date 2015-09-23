// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#include "SearchResultModel.h"

namespace ExampleApp
{
    namespace Search
    {
        namespace SdkModel
        {
            /*
             3: Yelp support (27/2/15)
             4: Added review count (7/7/15)
             */
            const int SearchResultModel::CurrentVersion = 4;
            
            SearchResultModel::SearchResultModel()
            : m_version(-1)
            , m_identifier("")
            , m_title("")
            , m_subtitle("")
            , m_location(Eegeo::Space::LatLong(0.f, 0.f))
            , m_heightAboveTerrainMetres(0.0f)
            , m_interior(false)
            , m_building("")
            , m_floor(0)
            , m_applicationCategory("")
            , m_humanReadableCategories()
            , m_vendor("")
            , m_jsonData("")
            , m_searchResultCreationTimeStamp(-1)
            {
                
            }
            
            SearchResultModel::SearchResultModel(int version,
                                                         const std::string& identifier,
                                                         const std::string& title,
                                                         const std::string& subtitle,
                                                         const Eegeo::Space::LatLong& location,
                                                         float heightAboveTerrainMetres,
                                                         bool interior,
                                                         const Eegeo::Resources::Interiors::InteriorId& building,
                                                         int floor,
                                                         const std::string& applicationCategory,
                                                         const std::vector<std::string>& humanReadableCategories,
                                                         const std::string& vendor,
                                                         const std::string& jsonData,
                                                         int64_t searchResultCreationTimeStamp)
            : m_version(version)
            , m_identifier(identifier)
            , m_title(title)
            , m_subtitle(subtitle)
            , m_location(location)
            , m_heightAboveTerrainMetres(heightAboveTerrainMetres)
            , m_interior(interior)
            , m_building(building)
            , m_floor(floor)
            , m_applicationCategory(applicationCategory)
            , m_humanReadableCategories(humanReadableCategories)
            , m_vendor(vendor)
            , m_jsonData(jsonData)
            , m_searchResultCreationTimeStamp(searchResultCreationTimeStamp)
            {
            }
            
            SearchResultModel::~SearchResultModel()
            {
                
            }
            
            int SearchResultModel::GetVersion() const
            {
                return m_version;
            }
            
            const std::string& SearchResultModel::GetTitle() const
            {
                return m_title;
            }
            
            const std::string& SearchResultModel::GetIdentifier() const
            {
                return m_identifier;
            }
            
            const Eegeo::Space::LatLong& SearchResultModel::GetLocation() const
            {
                return m_location;
            }
            
            float SearchResultModel::GetHeightAboveTerrainMetres() const
            {
                return m_heightAboveTerrainMetres;
            }
            
            bool SearchResultModel::IsInterior() const
            {
                return m_interior;
            }
            
            const Eegeo::Resources::Interiors::InteriorId& SearchResultModel::GetBuildingId() const
            {
                return m_building;
            }
            
            int SearchResultModel::GetFloor() const
            {
                return m_floor;
            }
            
            const std::string& SearchResultModel::GetSubtitle() const
            {
                return m_subtitle;
            }
            
            const std::string& SearchResultModel::GetJsonData() const
            {
                return m_jsonData;
            }
            
            const std::string& SearchResultModel::GetCategory() const
            {
                return m_applicationCategory;
            }
            
            const std::vector<std::string>& SearchResultModel::GetHumanReadableCategories() const
            {
                return m_humanReadableCategories;
            }
            
            const std::string& SearchResultModel::GetVendor() const
            {
                return m_vendor;
            }
            
            int64_t SearchResultModel::GetCreationTimestamp() const
            {
                return m_searchResultCreationTimeStamp;
            }
            
            const bool operator< (const SearchResultModel& a, const SearchResultModel& b)
            {
                if(a.GetTitle() < b.GetTitle())
                {
                    return true;
                }
                else if (a.GetTitle() == b.GetTitle() && a.GetSubtitle() < b.GetSubtitle())
                {
                    return true;
                }
                else if (a.GetTitle() == b.GetTitle() && a.GetSubtitle() == b.GetSubtitle() && a.GetIdentifier() < b.GetIdentifier())
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            
            const bool operator== (const SearchResultModel& a, const SearchResultModel& b)
            {
                return (a.GetTitle() == b.GetTitle() && a.GetSubtitle() == b.GetSubtitle() && a.GetIdentifier() == b.GetIdentifier());
            }
        }
    }
}
