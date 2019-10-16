#include "pch.h"
#include "Playlist.h"
#if __has_include("Playlist.g.cpp")
#include "Playlist.g.cpp"
#endif
#include "Constants.h"

using namespace Windows::UI::Xaml;

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
	Playlist::Playlist(const winrt::hstring& itemJson)
	{
		json j = json::parse(to_mbs(itemJson.c_str()));
		m_Name = to_wcs(j.at(to_mbs(SpotifyQueryConstants::g_Name)).get<std::string>());
	}

	winrt::hstring Playlist::Name()
	{
		return winrt::hstring(m_Name);
	}

	void Playlist::Name(const winrt::hstring& name)
	{
		m_Name = name.c_str();
	}
	winrt::event_token Playlist::PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& value)
	{
		return m_propertyChanged.add(value);
	}

	void Playlist::PropertyChanged(winrt::event_token const& token)
	{
		m_propertyChanged.remove(token);
	}
}
