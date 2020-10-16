#include "pch.h"
#include "HttpManager.h"
#include "Utils.h"

using namespace winrt;
using namespace Windows::UI::Xaml::Media::Imaging;
using namespace winrt::Windows::Web::Http::Headers;
using namespace winrt::Windows::Foundation;
using json = nlohmann::json;

namespace winrt::spotify_breakdown_playlists_cppwinrt
{
	HttpManager::HttpManager()
	{

	}

	HttpManager* HttpManager::Instance()
	{
		static std::unique_ptr<HttpManager> g_pHttpManager(new HttpManager());

		return g_pHttpManager.get();
	}

	IAsyncOperation<hstring> HttpManager::Request(const std::wstring& uri)
	{
		m_HttpClient.DefaultRequestHeaders().Authorization(HttpCredentialsHeaderValue(
			L"Bearer",
			to_hstring(AuthenticationManager::Instance()->GetAccessToken().c_str())));

		return co_await m_HttpClient.GetStringAsync(Uri(uri));
	}

	IAsyncOperation<hstring> HttpManager::Request(
		const std::wstring& uri,
		const std::wstring& responseParam)
	{
		hstring value;

		const auto response = co_await Request(uri);
		const auto responseJson = json::parse(std::wstring(response.c_str()));

		value = responseJson.at(to_string(responseParam)).get<std::wstring>();
		co_return value;
	}
}
