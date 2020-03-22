#pragma once

#include "MainPage.g.h"
#include "AuthenticationManager.h"

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
		AuthenticationManager m_authManager = AuthenticationManager(AuthenticationManager::Mode::ImplicitGrant);

        MainPage();

		winrt::Windows::Foundation::IAsyncOperation<hstring> LoginHandler(const IInspectable& sender, const Windows::UI::Xaml::RoutedEventArgs& args);
		void loginButton_PointerEntered(const Windows::Foundation::IInspectable& sender, const Windows::UI::Xaml::Input::PointerRoutedEventArgs& e);
		void loginButton_PointerExited(const Windows::Foundation::IInspectable& sender, const Windows::UI::Xaml::Input::PointerRoutedEventArgs& e);
	};
}

namespace winrt::spotify_breakdown_playlists_cppwinrt::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
