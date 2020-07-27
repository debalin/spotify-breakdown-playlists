#include "pch.h"
#include "Methods_Methods.h"
#if __has_include("Methods_Methods.g.cpp")
#include "Methods_Methods.g.cpp"
#include "Constants.h"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    Methods_Methods::Methods_Methods()
    {
        InitializeComponent();

        m_MethodNames = single_threaded_observable_vector<IInspectable>();
        for (const auto& methodName : AppConstants::g_MethodNames)
        {
            MethodNames().Append(box_value(to_hstring(methodName.c_str())));
        }
        MethodList().SelectedItem(MethodNames().GetAt(0));
    }

    Windows::Foundation::Collections::IObservableVector<IInspectable> Methods_Methods::MethodNames() const
    {
        return m_MethodNames;
    }
}
