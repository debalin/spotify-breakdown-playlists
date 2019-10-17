#pragma once

#include "MainPage.g.h"
#include "AuthenticationManager.h"

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
		AuthenticationManager m_authManager = AuthenticationManager(AuthenticationManager::Mode::ImplicitGrant);

        MainPage();

		winrt::Windows::Foundation::IAsyncOperation<hstring> LoginHandler(IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
		void loginButton_PointerEntered(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e);
		void loginButton_PointerExited(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e);
	};
}

namespace winrt::spotify_breakdown_playlists_cppwinrt::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
