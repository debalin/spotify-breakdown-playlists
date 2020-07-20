#pragma once

#include "Methods_Methods.g.h"

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    struct Methods_Methods : Methods_MethodsT<Methods_Methods>
    {
        Methods_Methods();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::spotify_breakdown_playlists_cppwinrt::factory_implementation
{
    struct Methods_Methods : Methods_MethodsT<Methods_Methods, implementation::Methods_Methods>
    {
    };
}
