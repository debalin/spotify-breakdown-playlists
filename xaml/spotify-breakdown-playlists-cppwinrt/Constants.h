#pragma once

#include "pch.h"

namespace HttpConstants
{
	const std::wstring g_Question = L"?";
	const std::wstring g_Equals = L"=";
	const std::wstring g_Ampersand = L"&";
}

namespace SpotifyUriConstants
{
	const std::wstring g_SpotifyAuthUri = L"https://accounts.spotify.com/authorize";
}

namespace SpotifyQueryConstants
{
	const std::wstring g_ClientIdParam = L"client_id";
	const std::wstring g_ClientIdValue = L"985a371b4fa24676818dc63468ca83d9";

	const std::wstring g_ResponseTypeParam = L"response_type";
	const std::wstring g_ResponseTypeValue = L"token";

	const std::wstring g_RedirectUriParam = L"redirect_uri";

	const std::wstring g_accessToken = L"access_token";

	const std::wstring g_expiresIn = L"expires_in";
}
