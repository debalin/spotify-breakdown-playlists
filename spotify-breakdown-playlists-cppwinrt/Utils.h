#pragma once

#include "Playlist.h"

namespace winrt::spotify_breakdown_playlists_cppwinrt
{
	namespace Utils
	{
		std::wstring FormUri(const std::wstring& baseUri, const std::vector<std::pair<std::wstring, std::wstring>>& paramsAndValues);
		std::wstring GetQueryValue(const std::wstring& uri, const std::wstring& queryParameter);
		Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> WrapNavigationArgs(const std::initializer_list< Windows::Foundation::IInspectable>&);
	};
}

