#include "pch.h"
#include "HttpManager.h"

HttpManager::HttpManager(const std::wstring& accessToken) :
	m_accessToken(accessToken)
{

}

IAsyncOperation<winrt::hstring> HttpManager::Request(const std::wstring& uri)
{
	if (m_accessToken.empty())
	{
		throw std::exception("No access token provided.");
	}

	m_httpClient.DefaultRequestHeaders().Authorization(winrt::Windows::Web::Http::Headers::HttpCredentialsHeaderValue(L"Bearer", m_accessToken));

	try
	{
		return co_await m_httpClient.GetStringAsync(Uri(uri));
	}
	catch (winrt::hresult_error const& ex)
	{
		return winrt::to_hstring(ex.message());
	}
}
