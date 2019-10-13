#include "pch.h"
#include "Playlists.h"
#if __has_include("Playlists.g.cpp")
#include "Playlists.g.cpp"
#endif
#include "Constants.h"
#include "Utils.h"

using namespace winrt;
using namespace Windows::UI::Xaml;
using json = nlohmann::json;

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

		auto response = co_await m_requestor.Request(SpotifyUriConstants::g_SpotifyMeUri);

		json j = json::parse(std::wstring(response.c_str()));

		auto userId = j.at("id").get<std::string>();

		return response;
	}
}
