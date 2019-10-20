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

		Windows::Foundation::IAsyncOperation<hstring> AuthenticateAsync();
		std::wstring GetAccessToken();
		int SecondsLeft();

	private:
		Mode m_mode;

		std::wstring m_AccessToken;
		std::wstring m_RedirectUri;

		int m_ExpiresIn;
		int m_LastAuthenticatedAt;
	};
}

