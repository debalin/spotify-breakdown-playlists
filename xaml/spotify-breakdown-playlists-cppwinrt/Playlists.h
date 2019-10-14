#pragma once

#include "Playlists.g.h"
#include "HttpManager.h"
#include "Playlist.h"

using namespace winrt::Windows::UI::Xaml::Navigation;

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    struct Playlists : PlaylistsT<Playlists>
    {
	public:
		Playlists();

		IAsyncOperation<winrt::hstring> OnNavigatedTo(NavigationEventArgs e);

	private:
		std::wstring m_accessToken;
		std::wstring m_userId;
		std::vector<Playlist> m_playlists;
		HttpManager m_requestor;

		IAsyncOperation<winrt::hstring> CollectPlaylists();
    };
}

namespace winrt::spotify_breakdown_playlists_cppwinrt::factory_implementation
{
    struct Playlists : PlaylistsT<Playlists, implementation::Playlists>
    {
    };
}
