#pragma once

#include "Playlist.g.h"

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    struct Playlist : PlaylistT<Playlist>
    {
	public:
        Playlist() = default;
		Playlist(const winrt::hstring& itemJson);

		hstring Name();
		void Name(const hstring&);
		event_token PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& value);
		void PropertyChanged(event_token const& token);

	private:
		event<Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
		std::wstring m_Name;
    };
}

namespace winrt::spotify_breakdown_playlists_cppwinrt::factory_implementation
{
    struct Playlist : PlaylistT<Playlist, implementation::Playlist>
    {
    };
}
