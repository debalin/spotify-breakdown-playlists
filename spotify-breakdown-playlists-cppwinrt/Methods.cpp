#include "pch.h"
#include "Methods.h"
#if __has_include("Methods.g.cpp")
#include "Methods.g.cpp"
#endif

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
		m_pages.push_back(std::make_pair<std::wstring, Windows::UI::Xaml::Interop::TypeName>
			(L"methods", winrt::xaml_typename<spotify_breakdown_playlists_cppwinrt::Methods_Methods>()));
	}

	BitmapImage Methods::CoverImage()
	{
		return m_Source.Thumbnail();
	}

	void Methods::CoverImage(const BitmapImage& image)
	{
		m_Source.Thumbnail(image);
	}

	IAsyncOperation<hstring> Methods::OnNavigatedTo(NavigationEventArgs e)
	{
		m_Source = e.Parameter().as<IVector<IInspectable>>().GetAt(0).as<Source>();
		m_Requestor = HttpManager(unbox_value<hstring>(e.Parameter().as<IVector<IInspectable>>().GetAt(1)).c_str());

		auto tracksJson = co_await m_Requestor.Request(m_Source.TracksUri().c_str());

		co_return L"";
	}

	void Methods::ContentFrame_NavigationFailed(
		const Windows::Foundation::IInspectable& sender, 
		const Windows::UI::Xaml::Navigation::NavigationFailedEventArgs& args)
	{

	}

	void Methods::NavView_SelectionChanged(
		const muxc::NavigationView& sender,
		const muxc::NavigationViewSelectionChangedEventArgs& args)
	{
		if (args.SelectedItemContainer())
		{
			NavView_Navigate(
				winrt::unbox_value_or<winrt::hstring>(
					args.SelectedItemContainer().Tag(), L"").c_str(),
				args.RecommendedNavigationTransitionInfo());
		}
	}

	void Methods::NavView_Navigate(
		const std::wstring& navItemTag, 
		const Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo& transitionInfo)
	{
		Windows::UI::Xaml::Interop::TypeName pageTypeName;
		for (auto&& eachPage : m_pages)
		{
			if (eachPage.first == navItemTag)
			{
				pageTypeName = eachPage.second;
				break;
			}
		}

		Windows::UI::Xaml::Interop::TypeName preNavPageType = ContentFrame().CurrentSourcePageType();

		if ((pageTypeName.Name != L"") && 
			(preNavPageType.Name != pageTypeName.Name))
		{
			ContentFrame().Navigate(pageTypeName, nullptr, transitionInfo);
		}
	}
}