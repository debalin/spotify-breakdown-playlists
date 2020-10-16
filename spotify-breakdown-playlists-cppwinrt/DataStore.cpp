#include "pch.h"
#include "DataStore.h"

namespace winrt::spotify_breakdown_playlists_cppwinrt
{
	DataStore* DataStore::Instance()
	{	
		static std::unique_ptr<DataStore> g_pDataStore(new DataStore());

		return g_pDataStore.get();
	}

	const Source& DataStore::GetSource()
	{
		return m_source;
	}

	void DataStore::SetSource(const Source& source)
	{
		m_source = source;
	}

	void DataStore::SetSource(Source&& source)
	{
		m_source = std::move(source);
	}
}
