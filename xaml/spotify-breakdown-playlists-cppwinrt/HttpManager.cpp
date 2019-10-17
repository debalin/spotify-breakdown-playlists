#include "pch.h"
#include "HttpManager.h"
#include "Utils.h"

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

		m_httpClient.DefaultRequestHeaders().Authorization(Windows::Web::Http::Headers::HttpCredentialsHeaderValue(
			L"Bearer",
			m_accessToken));

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
