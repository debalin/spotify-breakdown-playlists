#pragma once

#include "Methods_Songs.g.h"

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    struct Methods_Songs : Methods_SongsT<Methods_Songs>
    {
    public:
        Methods_Songs();

        Windows::Foundation::Collections::IObservableVector<IInspectable> Songs() const;

    private:
        Windows::Foundation::Collections::IObservableVector<IInspectable> m_Songs{ nullptr };
    };
}

namespace winrt::spotify_breakdown_playlists_cppwinrt::factory_implementation
{
    struct Methods_Songs : Methods_SongsT<Methods_Songs, implementation::Methods_Songs>
    {
    };
}
