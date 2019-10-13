#pragma once

class HttpManager
{
public:
	HttpManager() { };
	HttpManager(const std::wstring& accessToken);

	IAsyncOperation<winrt::hstring> Request(const std::wstring& uri);

private:
	std::wstring m_accessToken;
	Windows::Web::Http::HttpClient m_httpClient{};
};

