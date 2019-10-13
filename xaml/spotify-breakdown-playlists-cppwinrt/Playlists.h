#pragma once

#include "Playlists.g.h"
#include "AuthenticationManager.h"
#include "HttpManager.h"
#include "Playlist.h"

using namespace winrt::Windows::UI::Xaml::Navigation;

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    struct Playlists : PlaylistsT<Playlists>
    {
		Playlists();

		IAsyncOperation<winrt::hstring> OnNavigatedTo(NavigationEventArgs e);

	private:
		std::wstring m_accessToken;
		std::wstring m_userId;
		std::vector<Playlist> m_playLists;
		HttpManager m_requestor;
    };
}

namespace winrt::spotify_breakdown_playlists_cppwinrt::factory_implementation
{
    struct Playlists : PlaylistsT<Playlists, implementation::Playlists>
    {
    };
}
