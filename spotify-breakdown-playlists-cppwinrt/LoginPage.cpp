#include "pch.h"

#include "LoginPage.h"
#include "LoginPage.g.cpp"
#include "DataStore.h"
#include "Sources.h"

using namespace winrt;
using namespace winrt::Windows::ApplicationModel::Core;
using namespace Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Input;
using namespace winrt::Windows::UI::Core;
using namespace winrt::Windows::Foundation;

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    LoginPage::LoginPage()
    {
        InitializeComponent();
    }

	IAsyncAction LoginPage::LoginHandler(
		const IInspectable&,
		const RoutedEventArgs& e)
    {
		co_await AuthenticationManager::Instance()->AuthenticateAsync();

		this->Frame().Navigate(xaml_typename<spotify_breakdown_playlists_cppwinrt::Sources>());

		co_return;
    }

	void LoginPage::loginButton_PointerEntered(
		const IInspectable&,
		const PointerRoutedEventArgs&)
	{
		Window::Current().CoreWindow().PointerCursor(CoreCursor(CoreCursorType::Hand, 0));
	}

	void LoginPage::loginButton_PointerExited(
		const IInspectable&,
		const PointerRoutedEventArgs&)
	{
		Window::Current().CoreWindow().PointerCursor(CoreCursor(CoreCursorType::Arrow, 0));
	}
}
