#pragma once

class AuthenticationManager
{
public:
	AuthenticationManager();

	void authenticate();
private:
	static const std::wstring s_clientId;
	static const std::wstring s_redirectUri;
};

