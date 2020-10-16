#include "pch.h"
#include "Methods.h"
#include "DataStore.h"
#if __has_include("Methods.g.cpp")
#include "Methods.g.cpp"
#endif
#include "HttpManager.h"

using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml::Media::Imaging;

namespace winrt::spotify_breakdown_playlists_cppwinrt::implementation
{
	Methods::Methods()
	{
		InitializeComponent();
		m_pages.push_back(
			std::make_pair<std::wstring, Windows::UI::Xaml::Interop::TypeName>(
				L"methods", 
				winrt::xaml_typename<spotify_breakdown_playlists_cppwinrt::Methods_Methods>()));
		m_pages.push_back(
			std::make_pair<std::wstring, Windows::UI::Xaml::Interop::TypeName>(
				L"songs",
				winrt::xaml_typename<spotify_breakdown_playlists_cppwinrt::Methods_Songs>()));
	}

	BitmapImage Methods::CoverImage()
	{
		return DataStore::Instance()->GetSource().Thumbnail();
	}

	void Methods::CoverImage(const BitmapImage& image)
	{
		DataStore::Instance()->GetSource().Thumbnail(image);
	}

	IAsyncAction Methods::OnNavigatedTo(NavigationEventArgs e)
	{
		auto tracksJson = co_await HttpManager::Instance()->Request(DataStore::Instance()->GetSource().TracksUri().c_str());

		co_return;
	}

	void Methods::ContentFrame_NavigationFailed(
		const Windows::Foundation::IInspectable&, 
		const Windows::UI::Xaml::Navigation::NavigationFailedEventArgs& args)
	{
		throw hresult_error(
			E_FAIL, 
			hstring(L"Failed to load page: ") + args.SourcePageType().Name);
	}

	void Methods::NavView_SelectionChanged(
		const muxc::NavigationView&,
		const muxc::NavigationViewSelectionChangedEventArgs& args)
	{
		if (args.SelectedItemContainer())
		{
			NavView_Navigate(
				winrt::unbox_value_or<winrt::hstring>(args.SelectedItemContainer().Tag(), L"").c_str(),
				args.RecommendedNavigationTransitionInfo());
		}
	}

	void Methods::NavView_Navigate(
		const std::wstring& navItemTag, 
		const Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo& transitionInfo)
	{
		Windows::UI::Xaml::Interop::TypeName pageTypeName;
		std::wstring header;
		for (size_t i = 0; i < m_pages.size(); i++)
		{
			if (m_pages[i].first == navItemTag)
			{
				pageTypeName = m_pages[i].second;
				header = m_headers[i];
				break;
			}
		}

		Windows::UI::Xaml::Interop::TypeName preNavPageType = ContentFrame().CurrentSourcePageType();

		if ((pageTypeName.Name != L"") && 
			(preNavPageType.Name != pageTypeName.Name))
		{
			// Change header and navigate to page.
			NavView().Header(box_value(header.c_str()));
			ContentFrame().Navigate(pageTypeName, nullptr, transitionInfo);
		}
	}

	void Methods::NavView_Loaded(
		const Windows::Foundation::IInspectable&, 
		const winrt::Windows::UI::Xaml::RoutedEventArgs&)
	{
		NavView().SelectedItem(NavView().MenuItems().GetAt(0));
		NavView_Navigate(
			L"methods",
			Windows::UI::Xaml::Media::Animation::EntranceNavigationTransitionInfo());
	}
}
