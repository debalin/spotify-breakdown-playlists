#include "pch.h"
#include "AuthenticationManager.h"
#include "Constants.h"
#include "Utils.h"

using namespace winrt;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Security::Authentication::Web;

namespace winrt::spotify_breakdown_playlists_cppwinrt
{
	AuthenticationManager::AuthenticationManager(Mode mode) :
		m_mode(mode)
	{
		m_RedirectUri = WebAuthenticationBroker::GetCurrentApplicationCallbackUri().ToString();
	}

	IAsyncOperation<hstring> AuthenticationManager::AuthenticateAsync()
	{
		std::vector<std::pair<std::wstring, std::wstring>> spotifyAuthParams;
		spotifyAuthParams.push_back(std::make_pair(SpotifyQueryConstants::g_ClientIdParam, SpotifyQueryConstants::g_ClientIdValue));
		spotifyAuthParams.push_back(std::make_pair(SpotifyQueryConstants::g_RedirectUriParam, m_RedirectUri));
		spotifyAuthParams.push_back(std::make_pair(SpotifyQueryConstants::g_ResponseTypeParam, SpotifyQueryConstants::g_ResponseTypeValue));
		std::wstring authUri = Utils::FormUri(SpotifyUriConstants::g_Authorize, spotifyAuthParams);

		Uri uri(authUri);

		try
		{
			WebAuthenticationResult response = co_await WebAuthenticationBroker::AuthenticateAsync(
				WebAuthenticationOptions::None,
				uri);

			m_AccessToken = Utils::GetQueryValue(
				response.ResponseData().c_str(),
				SpotifyQueryConstants::g_AccessToken);

			m_ExpiresIn = std::stoi(Utils::GetQueryValue(
				response.ResponseData().c_str(),
				SpotifyQueryConstants::g_ExpiresIn));
		}
		catch (...)
		{
		}

		return hstring(m_AccessToken);
	}

	std::wstring AuthenticationManager::GetAccessToken()
	{
		return m_AccessToken;
	}

	int AuthenticationManager::SecondsLeft()
	{
		throw_hresult(E_NOTIMPL);
	}
}
