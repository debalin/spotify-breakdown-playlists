#include "pch.h"
#include "Track.h"
#if __has_include("Track.g.cpp")
#include "Track.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
	Track::Track(const hstring& itemJson)
	{

	}

	hstring Track::Name()
	{
		return m_Name.c_str();
	}

	void Track::Name(const hstring& name)
	{
		m_Name = name.c_str();
	}
}
