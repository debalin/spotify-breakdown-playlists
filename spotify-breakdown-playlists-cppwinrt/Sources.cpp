#include "pch.h"
#include "Sources.h"
#include "Source.h"
#if __has_include("Sources.g.cpp")
#include "Sources.g.cpp"
#endif
#include "Constants.h"
#include "DataStore.h"
#include "Methods.h"
#include "Utils.h"

using namespace winrt;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Foundation::Collections;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Controls;
using namespace winrt::Windows::UI::Xaml::Navigation;

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
	Sources::Sources()
	{
		InitializeComponent();

		m_Sources = single_threaded_observable_vector<IInspectable>();
	}

	IObservableVector<IInspectable> Sources::SpotifySources() const
	{
		return m_Sources;
	}

	IAsyncAction Sources::OnNavigatedTo(NavigationEventArgs e)
	{
		co_await CollectSources();

		co_return;
	}

	IAsyncOperation<hstring> Sources::CollectSources()
	{
		auto sourcesStr = co_await HttpManager::Instance()->Request(SpotifyUriConstants::g_MyPlaylists);

		nlohmann::json sourcesJson = nlohmann::json::parse(std::wstring(sourcesStr.c_str()));

		for (const auto& item : sourcesJson.at(to_string(SpotifyQueryConstants::g_Items)))
		{
			auto source = winrt::make<spotify_breakdown_playlists_cppwinrt::implementation::Source>(to_hstring(item.dump()));
			SpotifySources().Append(source);
		}

		co_return L"";
	}

	void Sources::ListView_ItemClick(
		const IInspectable&,
		const ItemClickEventArgs& e)
	{
		DataStore::Instance()->SetSource(std::move(*(e.ClickedItem().as<Source>())));
		this->Frame().Navigate(xaml_typename<spotify_breakdown_playlists_cppwinrt::Methods>());
	}
}