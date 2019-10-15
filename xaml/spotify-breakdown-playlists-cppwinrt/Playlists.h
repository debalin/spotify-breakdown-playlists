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

		// Retreives collection of Photo objects for thumbnail view.
		Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> SpotifyPlaylists() const
		{
			return m_playlists;
		}

		IAsyncOperation<winrt::hstring> OnNavigatedTo(NavigationEventArgs e);

	private:
		std::wstring m_accessToken;
		std::wstring m_userId;
		HttpManager m_requestor;

		IAsyncOperation<winrt::hstring> CollectPlaylists();

		// Backing field for Playlist collection.
		Windows::Foundation::Collections::IVector<IInspectable> m_playlists{ nullptr };
    };
}

namespace winrt::spotify_breakdown_playlists_cppwinrt::factory_implementation
{
    struct Playlists : PlaylistsT<Playlists, implementation::Playlists>
    {
    };
}
