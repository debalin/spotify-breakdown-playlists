#include "pch.h"
#include "Playlist.h"
#if __has_include("Playlist.g.cpp")
#include "Playlist.g.cpp"
#endif
#include "Constants.h"

using namespace winrt;
using namespace winrt::Windows::UI::Xaml::Media::Imaging;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::Foundation;
using json = nlohmann::json;

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
	Playlist::Playlist(const winrt::hstring& itemJson)
	{
		json j = json::parse(to_mbs(itemJson.c_str()));
		m_Name = to_wcs(j.at(to_mbs(SpotifyQueryConstants::g_Name)).get<std::string>());
		m_Id = to_wcs(j.at(to_mbs(SpotifyQueryConstants::g_Id)).get<std::string>());

		std::wstring imageUri = j.at("images").size() > 0 ?
			to_wcs(j.at("images")[0].at("url").get<std::string>()) :
			L"";

		m_Image = BitmapImage(Uri(imageUri));
	}

	winrt::hstring Playlist::Name()
	{
		return winrt::hstring(m_Name);
	}

	void Playlist::Name(const winrt::hstring& name)
	{
		m_Name = name.c_str();
	}
	Windows::UI::Xaml::Media::Imaging::BitmapImage Playlist::Thumbnail()
	{
		return m_Image;
	}

	void Playlist::Thumbnail(const Windows::UI::Xaml::Media::Imaging::BitmapImage& image)
	{
		m_Image = image;
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
