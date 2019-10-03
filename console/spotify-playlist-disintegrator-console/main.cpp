#include "pch.h"

using namespace winrt;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Security::Authentication::Web;

int main()
{
    init_apartment();

	winrt::hstring spotifyAuthUri = L"https://accounts.spotify.com/authorize";
	winrt::hstring clientId = L"client_id=985a371b4fa24676818dc63468ca83d9";
	winrt::hstring response_type = L"response_type=token";
	//winrt::Windows::Foundation::Uri redirect_uri(hstring(L"www.chilligarlicandme.com"));

	winrt::hstring formed_uri = spotifyAuthUri + L"?" + clientId + L"&" + response_type + L"&redirect_uri=www.chilligarlicandme.com";

	Uri uri(formed_uri);

	WebAuthenticationBroker::AuthenticateAndContinue(uri);

    printf("Hello, %ls!\n", uri.AbsoluteUri().c_str());
}
