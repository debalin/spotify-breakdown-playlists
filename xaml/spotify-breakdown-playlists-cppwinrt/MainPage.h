#pragma once

#include "MainPage.g.h"
#include "AuthenticationManager.h"

using namespace Windows::UI::Xaml;

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
		AuthenticationManager m_authManager = AuthenticationManager(AuthenticationManager::Mode::ImplicitGrant);

        MainPage();

        IAsyncOperation<winrt::hstring> ClickHandler(IInspectable const& sender, RoutedEventArgs const& args);
		void loginButton_PointerEntered(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e);
		void loginButton_PointerExited(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs const& e);
	};
}

namespace winrt::spotify_breakdown_playlists_cppwinrt::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
