#include "pch.h"
#include "Playlists.h"
#if __has_include("Playlists.g.cpp")
#include "Playlists.g.cpp"
#endif
#include "Constants.h"
#include "Utils.h"

using namespace winrt;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Navigation;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Foundation::Collections;
using json = nlohmann::json;

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
	Playlists::Playlists()
	{
		InitializeComponent();

		m_playlists = single_threaded_vector<IInspectable>();
	}

	IVector<IInspectable> Playlists::SpotifyPlaylists() const
	{
		return m_playlists;
	}

	IAsyncOperation<hstring> Playlists::OnNavigatedTo(NavigationEventArgs e)
	{
		m_accessToken = unbox_value<hstring>(e.Parameter()).c_str();
		m_requestor = HttpManager(m_accessToken);
		m_userId = co_await m_requestor.Request(
			SpotifyUriConstants::g_Me, 
			SpotifyQueryConstants::g_Id);

		co_await CollectPlaylists();

		return hstring(m_accessToken);
	}

	IAsyncOperation<hstring> Playlists::CollectPlaylists()
	{
		auto playlistsStr = co_await m_requestor.Request(SpotifyUriConstants::g_Playlists(m_userId));

		json playlistsJson = json::parse(std::wstring(playlistsStr.c_str()));

		for (const auto& item : playlistsJson.at(to_mbs(SpotifyQueryConstants::g_Items)))
		{
			auto playlist = winrt::make<spotify_breakdown_playlists_cppwinrt::implementation::Playlist>(to_hstring(item.dump()));
			SpotifyPlaylists().Append(playlist);
		}

		return L"";
	}
}
