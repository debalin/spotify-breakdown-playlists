#pragma once

#include "pch.h"
#include "SpotifyClientId.h"

namespace winrt::spotify_breakdown_playlists_cppwinrt
{
	namespace HttpConstants
	{
		const std::wstring g_Question = L"?";
		const std::wstring g_Equals = L"=";
		const std::wstring g_Ampersand = L"&";
	}

	namespace SpotifyUriConstants
	{
		const std::wstring g_Authorize = L"https://accounts.spotify.com/authorize";
		const std::wstring g_Me = L"https://api.spotify.com/v1/me";

		std::wstring g_Playlists(const std::wstring& userId);
	}

	namespace SpotifyQueryConstants
	{
		const std::wstring g_ClientIdParam = L"client_id";
		const std::wstring g_ClientIdValue = spotify_app_info::client_id;

		const std::wstring g_ResponseTypeParam = L"response_type";
		const std::wstring g_ResponseTypeValue = L"token";

		const std::wstring g_RedirectUriParam = L"redirect_uri";

		const std::wstring g_AccessToken = L"access_token";
		const std::wstring g_ExpiresIn = L"expires_in";

		const std::wstring g_Id = L"id";
		const std::wstring g_Items = L"items";
		const std::wstring g_Name = L"name";
		const std::wstring g_Tracks = L"tracks";
		const std::wstring g_Total = L"total";
		const std::wstring g_Images = L"images";
		const std::wstring g_Url = L"url";
		const std::wstring g_Href = L"href";
	}
}
