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
	std::wstring authUri = Utils::FormUri(SpotifyUriConstants::g_SpotifyAuthUri, spotifyAuthParams);

	Uri uri(authUri);

	WebAuthenticationResult response = co_await WebAuthenticationBroker::AuthenticateAsync(
		WebAuthenticationOptions::None,
		uri);

	return response.ResponseData();
}

std::wstring AuthenticationManager::GetAccessToken()
{
	return m_accessToken;
}

int AuthenticationManager::SecondsLeft()
{
	return 0;
}
