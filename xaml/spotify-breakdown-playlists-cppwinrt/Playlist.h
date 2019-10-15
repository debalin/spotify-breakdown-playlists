#pragma once

#include "Playlist.g.h"

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    struct Playlist : PlaylistT<Playlist>
    {
	public:
        Playlist() = default;
		Playlist(const winrt::hstring& itemJson);

        std::wstring m_Name;
		winrt::hstring Name();
		void Name(const winrt::hstring&);

	private:
    };
}

namespace winrt::spotify_breakdown_playlists_cppwinrt::factory_implementation
{
    struct Playlist : PlaylistT<Playlist, implementation::Playlist>
    {
    };
}
