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
	HttpManager::HttpManager(const std::wstring& accessToken) :
		m_AccessToken(accessToken)
	{

	}

	IAsyncOperation<hstring> HttpManager::Request(const std::wstring& uri)
	{
		if (m_AccessToken.empty())
		{
			throw std::exception("No access token provided.");
		}

		m_HttpClient.DefaultRequestHeaders().Authorization(HttpCredentialsHeaderValue(
			L"Bearer",
			to_hstring(m_AccessToken.c_str())));

		return co_await m_HttpClient.GetStringAsync(Uri(uri));
	}

	IAsyncOperation<Windows::UI::Xaml::Media::Imaging::BitmapImage> HttpManager::RequestImage(const std::wstring& uri)
	{
		if (m_AccessToken.empty())
		{
			throw std::exception("No access token provided.");
		}

		BitmapImage image;

		auto response = co_await m_HttpClient.GetInputStreamAsync(Uri(uri));

		return image;
	}

	IAsyncOperation<hstring> HttpManager::Request(
		const std::wstring& uri,
		const std::wstring& responseParam)
	{
		hstring value;

		const auto response = co_await Request(uri);
		const auto responseJson = json::parse(std::wstring(response.c_str()));

		value = responseJson.at(to_string(responseParam)).get<std::wstring>();
		return value;
	}
}
