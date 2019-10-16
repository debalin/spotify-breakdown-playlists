#pragma once

namespace winrt::spotify_breakdown_playlists_cppwinrt
{
	class AuthenticationManager
	{
	public:
		enum class Mode
		{
			ImplicitGrant
		};

		AuthenticationManager(Mode mode);

		IAsyncOperation<hstring> AuthenticateAsync();
		std::wstring GetAccessToken();
		int SecondsLeft();

	private:
		Mode m_mode;

		std::wstring m_accessToken;
		std::wstring m_redirectUri;

		int m_expiresIn;
		int m_lastAuthenticatedAt;
	};
}

