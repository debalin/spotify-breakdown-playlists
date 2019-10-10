#include "pch.h"

#include "MainPage.h"
#include "MainPage.g.cpp"

using namespace Windows::ApplicationModel::Core;
using namespace winrt::Windows::UI::Xaml::Input;
using namespace winrt::Windows::UI::Core;

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
    }

	IAsyncOperation<winrt::hstring> MainPage::ClickHandler(
		IInspectable const&, 
		RoutedEventArgs const&)
    {
		return winrt::hstring(co_await m_authManager.AuthenticateAsync());
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
