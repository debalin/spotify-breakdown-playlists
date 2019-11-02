#pragma once

#include "Track.g.h"

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    struct Track : TrackT<Track>
    {
        Track() = default;

		Track(const hstring& itemJson);

		hstring Name();
		void Name(const hstring&);

	private:
		std::wstring m_Name;
    };
}

namespace winrt::spotify_breakdown_playlists_cppwinrt::factory_implementation
{
    struct Track : TrackT<Track, implementation::Track>
    {
    };
}
