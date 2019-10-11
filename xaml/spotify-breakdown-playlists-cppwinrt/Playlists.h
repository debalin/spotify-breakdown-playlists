#pragma once

#include "Playlists.g.h"
#include "AuthenticationManager.h"

using namespace winrt::Windows::UI::Xaml::Navigation;

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    struct Playlists : PlaylistsT<Playlists>
    {
		Playlists();

		void OnNavigatedTo(NavigationEventArgs e);

	private:
		std::wstring m_accessToken;
    };
}

namespace winrt::spotify_breakdown_playlists_cppwinrt::factory_implementation
{
    struct Playlists : PlaylistsT<Playlists, implementation::Playlists>
    {
    };
}
