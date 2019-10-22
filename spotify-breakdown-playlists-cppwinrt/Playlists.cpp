#include "pch.h"
#include "Playlists.h"
#if __has_include("Playlists.g.cpp")
#include "Playlists.g.cpp"
#endif
#include "Constants.h"
#include "Utils.h"

using namespace winrt;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Controls;
using namespace winrt::Windows::UI::Xaml::Navigation;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Foundation::Collections;
using json = nlohmann::json;

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
	Playlists::Playlists()
	{
		InitializeComponent();

		m_Playlists = single_threaded_observable_vector<IInspectable>();
	}

	IObservableVector<IInspectable> Playlists::SpotifyPlaylists() const
	{
		return m_Playlists;
	}

	IAsyncOperation<hstring> Playlists::OnNavigatedTo(NavigationEventArgs e)
	{
		m_AccessToken = unbox_value<hstring>(e.Parameter()).c_str();
		m_Requestor = HttpManager(m_AccessToken);
		m_UserId = co_await m_Requestor.Request(
			SpotifyUriConstants::g_Me, 
			SpotifyQueryConstants::g_Id);

		co_await CollectPlaylists();

		return hstring(m_AccessToken);
	}

	IAsyncOperation<hstring> Playlists::CollectPlaylists()
	{
		auto playlistsStr = co_await m_Requestor.Request(SpotifyUriConstants::g_Playlists(m_UserId));

		json playlistsJson = json::parse(std::wstring(playlistsStr.c_str()));

		for (const auto& item : playlistsJson.at(to_mbs(SpotifyQueryConstants::g_Items)))
		{
			auto playlist = winrt::make<spotify_breakdown_playlists_cppwinrt::implementation::Playlist>(to_hstring(item.dump()));
			SpotifyPlaylists().Append(playlist);
		}

		return L"";
	}

	void Playlists::ListView_ItemClick(
		IInspectable const& sender,
		ItemClickEventArgs const& e)
	{
		auto clickedPlaylist = e.ClickedItem().as<Playlist>();
	}
}
