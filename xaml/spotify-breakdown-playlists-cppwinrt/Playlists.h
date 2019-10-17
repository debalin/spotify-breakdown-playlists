#pragma once

#include "Playlists.g.h"
#include "HttpManager.h"
#include "Playlist.h"

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    struct Playlists : PlaylistsT<Playlists>
    {
	public:
		Playlists();

		Windows::Foundation::Collections::IObservableVector<IInspectable> SpotifyPlaylists() const;
		Windows::Foundation::IAsyncOperation<hstring> OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs e);

	private:
		std::wstring m_accessToken;
		std::wstring m_userId;
		HttpManager m_requestor;

		Windows::Foundation::IAsyncOperation<hstring> CollectPlaylists();
		Windows::Foundation::Collections::IObservableVector<IInspectable> m_playlists{ nullptr };
    };
}

namespace winrt::spotify_breakdown_playlists_cppwinrt::factory_implementation
{
    struct Playlists : PlaylistsT<Playlists, implementation::Playlists>
    {
    };
}
