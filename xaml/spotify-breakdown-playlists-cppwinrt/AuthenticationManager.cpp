#include "pch.h"

#include "AuthenticationManager.h"
#include "Constants.h"
#include "Utils.h"

AuthenticationManager::AuthenticationManager(Mode mode) :
	m_mode(mode) 
{
	m_redirectUri = WebAuthenticationBroker::GetCurrentApplicationCallbackUri().ToString();
}

IAsyncOperation<winrt::hstring> AuthenticationManager::AuthenticateAsync()
{
	std::vector<std::pair<std::wstring, std::wstring>> spotifyAuthParams;
	spotifyAuthParams.push_back(std::make_pair(SpotifyQueryConstants::g_ClientIdParam, SpotifyQueryConstants::g_ClientIdValue));
	spotifyAuthParams.push_back(std::make_pair(SpotifyQueryConstants::g_RedirectUriParam, m_redirectUri));
	spotifyAuthParams.push_back(std::make_pair(SpotifyQueryConstants::g_ResponseTypeParam, SpotifyQueryConstants::g_ResponseTypeValue));
	std::wstring authUri = Utils::FormUri(SpotifyUriConstants::g_Authorize, spotifyAuthParams);

	Uri uri(authUri);

	try
	{
		WebAuthenticationResult response = co_await WebAuthenticationBroker::AuthenticateAsync(
			WebAuthenticationOptions::None,
			uri);

		m_accessToken = Utils::GetQueryValue(
			response.ResponseData().c_str(),
			SpotifyQueryConstants::g_accessToken);

		m_expiresIn = std::stoi(Utils::GetQueryValue(
			response.ResponseData().c_str(),
			SpotifyQueryConstants::g_expiresIn));
	}
	catch (...)
	{ }

	return winrt::hstring(m_accessToken);
}

std::wstring AuthenticationManager::GetAccessToken()
{
	return m_accessToken;
}

int AuthenticationManager::SecondsLeft()
{
	throw_hresult(E_NOTIMPL);
}
