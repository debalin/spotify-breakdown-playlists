#include "pch.h"

#include "MainPage.h"
#include "MainPage.g.cpp"

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
    }

    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

	IAsyncOperation<winrt::hstring> MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
		return co_await m_authManager.AuthenticateAsync();
    }
}
