﻿#pragma once

#include "Methods.g.h"

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
		Windows::Foundation::IAsyncAction OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs);
		void ContentFrame_NavigationFailed(const Windows::Foundation::IInspectable&, const Windows::UI::Xaml::Navigation::NavigationFailedEventArgs&);
		void NavView_SelectionChanged(const muxc::NavigationView&, const muxc::NavigationViewSelectionChangedEventArgs&);
		void NavView_Navigate(const std::wstring&, const Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo&);

	private:
		Windows::UI::Xaml::Media::Imaging::BitmapImage m_Image;

		std::vector<std::pair<std::wstring, Windows::UI::Xaml::Interop::TypeName>> m_pages;
		std::vector<std::wstring> m_headers{ 
			L"Divide using:", 
			L"Verify songs in playlist."};
	public:
		void NavView_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e);
	};
}

namespace winrt::spotify_breakdown_playlists_cppwinrt::factory_implementation
{
    struct Methods : MethodsT<Methods, implementation::Methods>
    {
    };
}
