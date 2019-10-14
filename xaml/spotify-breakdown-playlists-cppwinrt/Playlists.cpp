﻿#include "pch.h"
#include "Playlists.h"
#if __has_include("Playlists.g.cpp")
#include "Playlists.g.cpp"
#endif
#include "Constants.h"
#include "Utils.h"

using namespace Windows::UI::Xaml;

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
	Playlists::Playlists()
	{
		InitializeComponent();
	}

	IAsyncOperation<winrt::hstring> Playlists::OnNavigatedTo(NavigationEventArgs e)
	{
		m_accessToken = unbox_value<winrt::hstring>(e.Parameter()).c_str();
		m_requestor = HttpManager(m_accessToken);
		m_userId = co_await m_requestor.Request(
			SpotifyUriConstants::g_Me, 
			SpotifyQueryConstants::g_Id);

		auto playlistsStr = co_await m_requestor.Request(SpotifyUriConstants::g_Playlists(m_userId));

		return winrt::hstring(m_accessToken);
	}
}
