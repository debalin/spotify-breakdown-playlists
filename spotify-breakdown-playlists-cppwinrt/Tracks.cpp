#include "pch.h"
#include "Tracks.h"
#if __has_include("Tracks.g.cpp")
#include "Tracks.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml::Media::Imaging;

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
	Tracks::Tracks()
	{
	}

	BitmapImage Tracks::CoverImage()
	{
		return m_Playlist.Thumbnail();
	}

	void Tracks::CoverImage(const BitmapImage& image)
	{
		m_Playlist.Thumbnail(image);
	}

	IAsyncOperation<hstring> Tracks::OnNavigatedTo(NavigationEventArgs e)
	{
		m_Playlist = e.Parameter().as<IVector<IInspectable>>().GetAt(0).as<Source>();
		m_Requestor = HttpManager(unbox_value<hstring>(e.Parameter().as<IVector<IInspectable>>().GetAt(1)).c_str());

		auto tracksJson = co_await m_Requestor.Request(m_Playlist.TracksUri().c_str());

		co_return L"";
	}
}