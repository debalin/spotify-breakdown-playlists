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
		static AuthenticationManager* Instance();

		~AuthenticationManager() {};

		Windows::Foundation::IAsyncAction AuthenticateAsync();
		std::wstring GetAccessToken();
		int SecondsLeft();

		AuthenticationManager() = delete;
		AuthenticationManager(const AuthenticationManager&) = delete;
		AuthenticationManager& operator=(const AuthenticationManager&) = delete;

	private:
		Mode m_mode;
		std::wstring m_AccessToken;
		std::wstring m_RedirectUri;
		int m_ExpiresIn;
		int m_LastAuthenticatedAt;

		AuthenticationManager(Mode mode);
	};
}

