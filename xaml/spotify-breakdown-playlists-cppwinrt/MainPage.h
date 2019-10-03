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

		int32_t MyProperty();
        void MyProperty(int32_t value);

        IAsyncOperation<winrt::hstring> ClickHandler(IInspectable const& sender, RoutedEventArgs const& args);
    };
}

namespace winrt::spotify_breakdown_playlists_cppwinrt::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
