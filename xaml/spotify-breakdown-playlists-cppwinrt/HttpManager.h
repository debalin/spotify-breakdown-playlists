#pragma once

namespace winrt::spotify_breakdown_playlists_cppwinrt
{
	class HttpManager
	{
	public:
		HttpManager() { };
		HttpManager(const std::wstring& accessToken);

		IAsyncOperation<hstring> Request(const std::wstring& uri);

		// Assumption: response is in JSON.
		IAsyncOperation<hstring> Request(const std::wstring& uri, const std::wstring& responseParam);

	private:
		std::wstring m_accessToken;
		Windows::Web::Http::HttpClient m_httpClient{};
	};
}

