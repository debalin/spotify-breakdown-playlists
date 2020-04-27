#include "pch.h"
#include "Source.h"
#if __has_include("Source.g.cpp")
#include "Source.g.cpp"
#endif
#include "Constants.h"

using namespace winrt;
using namespace winrt::Windows::UI::Xaml::Media::Imaging;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::Foundation;
using json = nlohmann::json;

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
	Source::Source(const hstring& itemJson)
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

	hstring Source::Name()
	{
		return hstring(m_Name);
	}

	void Source::Name(const hstring& name)
	{
		m_Name = name.c_str();
	}

	BitmapImage Source::Thumbnail()
	{
		return m_Image;
	}

	void Source::Thumbnail(const Windows::UI::Xaml::Media::Imaging::BitmapImage& image)
	{
		m_Image = image;
	}

	hstring Source::SongCount()
	{
		return to_hstring(m_SongCount) + L" songs";
	}

	void Source::SongCount(const hstring& songCount)
	{
		m_SongCount = static_cast<unsigned int>(std::stoi(songCount.c_str()));
	}

	hstring Source::TracksUri()
	{
		return hstring(m_TracksUri);
	}

	void Source::TracksUri(const hstring& tracksUri)
	{
		m_TracksUri = tracksUri.c_str();
	}

	event_token Source::PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler const& value)
	{
		return m_propertyChanged.add(value);
	}

	void Source::PropertyChanged(event_token const& token)
	{
		m_propertyChanged.remove(token);
	}
}
