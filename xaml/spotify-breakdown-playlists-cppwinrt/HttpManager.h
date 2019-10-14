#pragma once

namespace winrt::spotify_breakdown_playlists_cppwinrt
{
	class HttpManager
	{
	public:
		HttpManager() { };
		HttpManager(const std::wstring& accessToken);

		IAsyncOperation<winrt::hstring> Request(const std::wstring& uri);

		// It assumes that the response is in JSON.
		IAsyncOperation<winrt::hstring> Request(const std::wstring& uri, const std::wstring& responseParam);

	private:
		std::wstring m_accessToken;
		Windows::Web::Http::HttpClient m_httpClient{};
	};
}

