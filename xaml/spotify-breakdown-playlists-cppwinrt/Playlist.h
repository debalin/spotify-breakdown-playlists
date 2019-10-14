#pragma once

namespace winrt::spotify_breakdown_playlists_cppwinrt
{
	class Playlist
	{
	public:
		std::wstring Name;

		static std::vector<Playlist> GetPlaylists(const std::wstring& playlistsJson);
	};

	inline void to_json(json& j, const Playlist& p)
	{
		j = json{ {"name", p.Name} };
	}

	inline void from_json(const json& j, Playlist& p)
	{
		j.at("name").get_to(p.Name);
	}
}
