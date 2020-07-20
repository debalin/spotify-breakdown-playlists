#pragma once

#include "Methods_Methods.g.h"

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    struct Methods_Methods : Methods_MethodsT<Methods_Methods>
    {
    public:
        Methods_Methods();

        Windows::Foundation::Collections::IObservableVector<IInspectable> MethodNames() const;

    private:
        Windows::Foundation::Collections::IObservableVector<IInspectable> m_MethodNames{ nullptr };
    };
}

namespace winrt::spotify_breakdown_playlists_cppwinrt::factory_implementation
{
    struct Methods_Methods : Methods_MethodsT<Methods_Methods, implementation::Methods_Methods>
    {
    };
}
