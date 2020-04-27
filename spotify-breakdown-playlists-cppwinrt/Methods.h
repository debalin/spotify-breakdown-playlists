#pragma once

#include "Methods.g.h"
#include "HttpManager.h"

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    struct Methods : MethodsT<Methods>
    {
	public:
        Methods();

		Windows::UI::Xaml::Media::Imaging::BitmapImage CoverImage();
		void CoverImage(const Windows::UI::Xaml::Media::Imaging::BitmapImage&);
		Windows::Foundation::IAsyncOperation<hstring> OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs e);

	private:
		Source m_Source;
		Windows::UI::Xaml::Media::Imaging::BitmapImage m_Image;
		HttpManager m_Requestor;
    };
}

namespace winrt::spotify_breakdown_playlists_cppwinrt::factory_implementation
{
    struct Methods : MethodsT<Methods, implementation::Methods>
    {
    };
}
