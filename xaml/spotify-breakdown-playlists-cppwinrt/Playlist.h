#pragma once

#include "HttpManager.h"

class Playlist
{
public:
	std::wstring Name;

 	static std::vector<Playlist> GetPlaylists(const std::wstring& playlistsJson);
};

