#include "pch.h"
#include "Constants.h"

std::wstring SpotifyUriConstants::g_Playlists(const std::wstring& userId)
{
	return L"https://api.spotify.com/v1/users/" + userId + L"/playlists";
}
