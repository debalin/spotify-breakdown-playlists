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
	Playlist::Playlist(const hstring& itemJson)
	{
		json j = json::parse(std::wstring(itemJson.c_str()));
		m_Name = j.at(to_string(SpotifyQueryConstants::g_Name)).get<std::wstring>();
		m_Id = j.at(to_string(SpotifyQueryConstants::g_Id)).get<std::wstring>();
		m_SongCount = j.at(to_string(SpotifyQueryConstants::g_Tracks)).at(to_string(SpotifyQueryConstants::g_Total)).get<unsigned int>();
		m_TracksUri = j.at(to_string(SpotifyQueryConstants::g_Tracks)).at(to_string(SpotifyQueryConstants::g_Href)).get<std::wstring>();

		std::string imagesConstant = to_string(SpotifyQueryConstants::g_Images);
		std::wstring imageUri = j.at(imagesConstant).size() > 0 ?
			to_wcs(j.at(imagesConstant)[0].at(to_string(SpotifyQueryConstants::g_Url)).get<std::string>()) :
			L"";
		m_Image = BitmapImage(Uri(imageUri));
	}

	hstring Playlist::Name()
	{
		return hstring(m_Name);
	}

	void Playlist::Name(const hstring& name)
	{
		m_Name = name.c_str();
	}

	BitmapImage Playlist::Thumbnail()
	{
		return m_Image;
	}

	void Playlist::Thumbnail(const Windows::UI::Xaml::Media::Imaging::BitmapImage& image)
	{
		m_Image = image;
	}

	hstring Playlist::SongCount()
	{
		return to_hstring(m_SongCount) + L" songs";
	}

	void Playlist::SongCount(const hstring& songCount)
	{
		m_SongCount = static_cast<unsigned int>(std::stoi(songCount.c_str()));
	}

	hstring Playlist::TracksUri()
	{
		return hstring(m_TracksUri);
	}

	void Playlist::TracksUri(const hstring& tracksUri)
	{
		m_TracksUri = tracksUri.c_str();
	}

	event_token Playlist::PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& value)
	{
		return m_propertyChanged.add(value);
	}

	void Playlist::PropertyChanged(event_token const& token)
	{
		m_propertyChanged.remove(token);
	}
}
