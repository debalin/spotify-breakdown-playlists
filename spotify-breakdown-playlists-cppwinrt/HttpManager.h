#pragma once

#include "AuthenticationManager.h"

namespace winrt::spotify_breakdown_playlists_cppwinrt
{
	class HttpManager
	{
	public:
		static HttpManager* Instance();

		~HttpManager() {};

		// Assumption: response is in JSON.
		Windows::Foundation::IAsyncOperation<hstring> Request(const std::wstring& uri, const std::wstring& responseParam);
		Windows::Foundation::IAsyncOperation<hstring> Request(const std::wstring& uri);

	private:
		std::wstring m_AccessToken;
		Windows::Web::Http::HttpClient m_HttpClient{};
		std::shared_ptr<AuthenticationManager> m_authManager;

		HttpManager();
	};
}

