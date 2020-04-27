#include "pch.h"
#include "Source.h"
#include "Sources.h"
#if __has_include("Sources.g.cpp")
#include "Sources.g.cpp"
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
	Sources::Sources()
	{
		InitializeComponent();

		m_Sources = single_threaded_observable_vector<IInspectable>();
	}

	IObservableVector<IInspectable> Sources::SpotifySources() const
	{
		return m_Sources;
	}

	IAsyncOperation<hstring> Sources::OnNavigatedTo(NavigationEventArgs e)
	{
		m_AccessToken = unbox_value<hstring>(e.Parameter()).c_str();
		m_Requestor = HttpManager(m_AccessToken);
		m_UserId = co_await m_Requestor.Request(
			SpotifyUriConstants::g_Me,
			SpotifyQueryConstants::g_Id);

		co_await CollectSources();

		co_return hstring(m_AccessToken);
	}

	IAsyncOperation<hstring> Sources::CollectSources()
	{
		auto playlistsStr = co_await m_Requestor.Request(SpotifyUriConstants::g_MyPlaylists);

		json playlistsJson = json::parse(std::wstring(playlistsStr.c_str()));

		for (const auto& item : playlistsJson.at(to_string(SpotifyQueryConstants::g_Items)))
		{
			auto playlist = winrt::make<spotify_breakdown_playlists_cppwinrt::implementation::Source>(to_hstring(item.dump()));
			SpotifySources().Append(playlist);
		}

		co_return L"";
	}

	void Sources::ListView_ItemClick(
		const IInspectable&,
		const ItemClickEventArgs& e)
	{
		this->Frame().Navigate(
			xaml_typename<spotify_breakdown_playlists_cppwinrt::Tracks>(),
			Utils::WrapNavigationArgs({ e.ClickedItem(), box_value(m_AccessToken) }));
	}
}