#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"
#include "cpprest/http_client.h"

using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace winrt::Windows::Security::Authentication::Web;
using namespace winrt::Windows::Foundation;

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

    IAsyncAction MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));

		winrt::hstring spotifyAuthUri = L"https://accounts.spotify.com/authorize";
		winrt::hstring clientId = L"client_id=985a371b4fa24676818dc63468ca83d9";
		winrt::hstring response_type = L"response_type=token";
		Uri redirect_uri = WebAuthenticationBroker::GetCurrentApplicationCallbackUri();

		winrt::hstring formed_uri = spotifyAuthUri + L"?" + clientId + L"&" + response_type + L"&redirect_uri=" + Uri::EscapeComponent(redirect_uri.ToString());

		Uri uri(formed_uri);

		auto response = co_await WebAuthenticationBroker::AuthenticateAsync(
			WebAuthenticationOptions::None,
			uri);

		web::uri_builder(spotifyAuthUri.c_str());

		auto status = response.ResponseStatus();
    }
}
