#pragma once

#include "Source.h"

namespace winrt::spotify_breakdown_playlists_cppwinrt
{
	class DataStore
	{
	public:
		static DataStore* Instance();

		~DataStore() {};

		const Source& GetSource();
		void SetSource(const Source&);
		void SetSource(Source&&);

	private:
		std::wstring m_accessToken;
		Source m_source;

		DataStore() {};
	};
}

