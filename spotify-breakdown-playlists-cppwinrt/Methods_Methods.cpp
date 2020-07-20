#include "pch.h"
#include "Methods_Methods.h"
#if __has_include("Methods_Methods.g.cpp")
#include "Methods_Methods.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    Methods_Methods::Methods_Methods()
    {
        InitializeComponent();
    }

    int32_t Methods_Methods::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void Methods_Methods::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void Methods_Methods::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
}
