﻿#pragma once

#include "Playlist.g.h"
#include "HttpManager.h"

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    struct Playlist : PlaylistT<Playlist>
    {
	public:
        Playlist() = default;
		Playlist(const hstring& itemJson);

		hstring Name();
		void Name(const hstring&);
		Windows::UI::Xaml::Media::Imaging::BitmapImage Thumbnail();
		void Thumbnail(const Windows::UI::Xaml::Media::Imaging::BitmapImage&);
		hstring SongCount();
		void SongCount(const hstring&);

		event_token PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& value);
		void PropertyChanged(event_token const& token);

	private:
		event<Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
		
		std::wstring m_Name;
		std::wstring m_Id;
		Windows::UI::Xaml::Media::Imaging::BitmapImage m_Image;
		unsigned int m_SongCount;
		std::wstring m_TracksUri;
    };
}

namespace winrt::spotify_breakdown_playlists_cppwinrt::factory_implementation
{
    struct Playlist : PlaylistT<Playlist, implementation::Playlist>
    {
    };
}
