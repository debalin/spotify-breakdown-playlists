#include "pch.h"
#include "HttpManager.h"
#include "Utils.h"

using namespace winrt;
using namespace winrt::Windows::Web::Http::Headers;
using namespace winrt::Windows::Foundation;
using json = nlohmann::json;

namespace winrt::spotify_breakdown_playlists_cppwinrt
{
	HttpManager::HttpManager(const std::wstring& accessToken) :
		m_accessToken(accessToken)
	{

	}

	IAsyncOperation<hstring> HttpManager::Request(const std::wstring& uri)
	{
		if (m_accessToken.empty())
		{
			throw std::exception("No access token provided.");
		}

		m_httpClient.DefaultRequestHeaders().Authorization(HttpCredentialsHeaderValue(
			L"Bearer",
			to_hstring(m_accessToken.c_str())));

		return co_await m_httpClient.GetStringAsync(Uri(uri));
	}

	IAsyncOperation<hstring> HttpManager::Request(
		const std::wstring& uri,
		const std::wstring& responseParam)
	{
		hstring value;

		const auto response = co_await Request(uri);
		const auto responseJson = json::parse(std::wstring(response.c_str()));

		value = responseJson.at(to_mbs(responseParam)).get<std::wstring>();
		return value;
	}
}
