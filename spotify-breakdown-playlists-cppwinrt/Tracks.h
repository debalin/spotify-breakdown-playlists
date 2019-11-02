#pragma once

#include "Tracks.g.h"
#include "HttpManager.h"

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    struct Tracks : TracksT<Tracks>
    {
	public:
        Tracks();

		Windows::UI::Xaml::Media::Imaging::BitmapImage CoverImage();
		void CoverImage(const Windows::UI::Xaml::Media::Imaging::BitmapImage&);
		Windows::Foundation::IAsyncOperation<hstring> OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs e);

	private:
		Playlist m_Playlist;
		Windows::UI::Xaml::Media::Imaging::BitmapImage m_Image;
		HttpManager m_Requestor;
    };
}

namespace winrt::spotify_breakdown_playlists_cppwinrt::factory_implementation
{
    struct Tracks : TracksT<Tracks, implementation::Tracks>
    {
    };
}
