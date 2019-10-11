#include "pch.h"

#include "MainPage.h"
#include "MainPage.g.cpp"
#include <Playlists.h>

using namespace Windows::ApplicationModel::Core;
using namespace winrt::Windows::UI::Xaml::Input;
using namespace winrt::Windows::UI::Core;

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
    }

	IAsyncOperation<winrt::hstring> MainPage::LoginHandler(
		IInspectable const&, 
		RoutedEventArgs const& e)
    {
		auto accessToken = co_await m_authManager.AuthenticateAsync();

		this->Frame().Navigate(
			xaml_typename<spotify_breakdown_playlists_cppwinrt::Playlists>(), 
			box_value(winrt::to_hstring(accessToken)));

		return accessToken;
    }

	void MainPage::loginButton_PointerEntered(
		IInspectable const&, 
		PointerRoutedEventArgs const&)
	{
		Window::Current().CoreWindow().PointerCursor(CoreCursor(CoreCursorType::Hand, 0));
	}

	void MainPage::loginButton_PointerExited(
		IInspectable const&,
		PointerRoutedEventArgs const&)
	{
		Window::Current().CoreWindow().PointerCursor(CoreCursor(CoreCursorType::Arrow, 0));
	}
}
