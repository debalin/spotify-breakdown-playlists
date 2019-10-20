#pragma once

namespace winrt::spotify_breakdown_playlists_cppwinrt
{
	class HttpManager
	{
	public:
		HttpManager() { };
		HttpManager(const std::wstring& accessToken);

		Windows::Foundation::IAsyncOperation<hstring> Request(const std::wstring& uri);

		// Assumption: response is in JSON.
		Windows::Foundation::IAsyncOperation<hstring> Request(const std::wstring& uri, const std::wstring& responseParam);

	private:
		std::wstring m_AccessToken;
		Windows::Web::Http::HttpClient m_HttpClient{};
	};
}

