#include "pch.h"
#include "Playlists.h"
#if __has_include("Playlists.g.cpp")
#include "Playlists.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
	Playlists::Playlists()
	{
		InitializeComponent();
	}

	void Playlists::OnNavigatedTo(NavigationEventArgs e)
	{
		m_accessToken = unbox_value<winrt::hstring>(e.Parameter()).c_str();


	}
}
