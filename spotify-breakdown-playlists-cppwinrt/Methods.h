#pragma once

#include "Methods.g.h"
#include "HttpManager.h"

namespace muxc
{
	using namespace winrt::Microsoft::UI::Xaml::Controls;
};

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    struct Methods : MethodsT<Methods>
    {
	public:
        Methods();

		Windows::UI::Xaml::Media::Imaging::BitmapImage CoverImage();
		void CoverImage(const Windows::UI::Xaml::Media::Imaging::BitmapImage&);
		Windows::Foundation::IAsyncOperation<hstring> OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs);
		void ContentFrame_NavigationFailed(const Windows::Foundation::IInspectable&, const Windows::UI::Xaml::Navigation::NavigationFailedEventArgs&);
		void NavView_SelectionChanged(const muxc::NavigationView&, const muxc::NavigationViewSelectionChangedEventArgs&);
		void NavView_Navigate(const std::wstring&, const Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo&);

	private:
		Source m_Source;
		Windows::UI::Xaml::Media::Imaging::BitmapImage m_Image;
		HttpManager m_Requestor;

		std::vector<std::pair<std::wstring, Windows::UI::Xaml::Interop::TypeName>> m_pages;
    };
}

namespace winrt::spotify_breakdown_playlists_cppwinrt::factory_implementation
{
    struct Methods : MethodsT<Methods, implementation::Methods>
    {
    };
}
