#pragma once

#include "Sources.g.h"
#include "HttpManager.h"
#include "Playlist.h"

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    struct Sources : SourcesT<Sources>
    {
	public:
		Sources();

		Windows::Foundation::Collections::IObservableVector<IInspectable> SpotifySources() const;
		Windows::Foundation::IAsyncAction OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs e); 
		void ListView_ItemClick(const Windows::Foundation::IInspectable& sender, const Windows::UI::Xaml::Controls::ItemClickEventArgs& e);

	private:
		Windows::Foundation::Collections::IObservableVector<IInspectable> m_Sources{ nullptr };

		Windows::Foundation::IAsyncOperation<hstring> CollectSources();
	};
}

namespace winrt::spotify_breakdown_playlists_cppwinrt::factory_implementation
{
    struct Sources : SourcesT<Sources, implementation::Sources>
    {
    };
}
