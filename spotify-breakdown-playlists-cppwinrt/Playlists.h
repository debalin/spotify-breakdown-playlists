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
		void ListView_ItemClick(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::Controls::ItemClickEventArgs const& e);

	private:
		std::wstring m_AccessToken;
		std::wstring m_UserId;
		HttpManager m_Requestor;

		Windows::Foundation::IAsyncOperation<hstring> CollectPlaylists();
		Windows::Foundation::Collections::IObservableVector<IInspectable> m_Playlists{ nullptr };
	};
}

namespace winrt::spotify_breakdown_playlists_cppwinrt::factory_implementation
{
    struct Playlists : PlaylistsT<Playlists, implementation::Playlists>
    {
    };
}
