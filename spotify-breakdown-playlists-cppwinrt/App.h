﻿#pragma once
#include "App.xaml.g.h"

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
    struct App : AppT<App>
    {
        App();

        void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs const&);
        void OnSuspending(IInspectable const&, Windows::ApplicationModel::SuspendingEventArgs const&);
        void OnNavigationFailed(IInspectable const&, Windows::UI::Xaml::Navigation::NavigationFailedEventArgs const&);

	private:
		void CustomizeTitleBar();
		void ExtendViewIntoTitleBar();
    };
}
