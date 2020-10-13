#include "pch.h"
#include "Methods_Songs.h"
#if __has_include("Methods_Songs.g.cpp")
#include "Methods_Songs.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    Methods_Songs::Methods_Songs()
    {
        InitializeComponent();
    }

    Windows::Foundation::Collections::IObservableVector<IInspectable> Methods_Songs::Songs() const
    {
        return m_Songs;
    }
}
