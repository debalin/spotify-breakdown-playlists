#include "pch.h"

#include "MainPage.h"
#include "MainPage.g.cpp"
#include <Playlists.h>

using namespace winrt;
using namespace winrt::Windows::ApplicationModel::Core;
using namespace Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Input;
using namespace winrt::Windows::UI::Core;
using namespace winrt::Windows::Foundation;

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
    }

	IAsyncOperation<hstring> MainPage::LoginHandler(
		const IInspectable&,
		const RoutedEventArgs& e)
    {
		auto accessToken = co_await m_authManager.AuthenticateAsync();

		this->Frame().Navigate(
			xaml_typename<spotify_breakdown_playlists_cppwinrt::Playlists>(), 
			box_value(to_hstring(accessToken)));

		co_return accessToken;
    }

	void MainPage::loginButton_PointerEntered(
		const IInspectable&,
		const PointerRoutedEventArgs&)
	{
		Window::Current().CoreWindow().PointerCursor(CoreCursor(CoreCursorType::Hand, 0));
	}

	void MainPage::loginButton_PointerExited(
		const IInspectable&,
		const PointerRoutedEventArgs&)
	{
		Window::Current().CoreWindow().PointerCursor(CoreCursor(CoreCursorType::Arrow, 0));
	}
}
