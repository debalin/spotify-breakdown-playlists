#pragma once

#include <hstring.h>
#include <nlohmann/json.hpp>
#include <ppltasks.h>
#include <restrictederrorinfo.h>
#include <unknwn.h>
#include <windows.h>
#include "winrt/Microsoft.UI.Xaml.Automation.Peers.h"
#include "winrt/Microsoft.UI.Xaml.Controls.Primitives.h"
#include "winrt/Windows.UI.Xaml.Input.h"
#include "winrt/Microsoft.UI.Xaml.Media.h"
#include "winrt/Microsoft.UI.Xaml.XamlTypeInfo.h"
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.ApplicationModel.Activation.h>
#include <winrt/Windows.ApplicationModel.Core.h>
#include <winrt/Windows.UI.Xaml.h>
#include <winrt/Windows.UI.Xaml.Controls.h>
#include <winrt/Windows.UI.Xaml.Controls.Primitives.h>
#include <winrt/Windows.UI.Xaml.Data.h>
#include <winrt/Windows.UI.Xaml.Interop.h>
#include <winrt/Windows.UI.Xaml.Markup.h>
#include <winrt/Windows.UI.Xaml.Navigation.h>
#include <winrt/Windows.Security.Authentication.Web.h>
#include <winrt/Windows.UI.ViewManagement.h>
#include <winrt/Windows.UI.h>
#include <winrt/Windows.UI.Core.h>
#include <winrt/Windows.Web.Http.h>
#include <winrt/Windows.Web.Http.Headers.h>
#include <nlohmann/json.hpp>

using namespace winrt;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Security::Authentication::Web;

using json = nlohmann::json;

namespace winrt::spotify_breakdown_playlists_cppwinrt
{
	inline std::wstring to_wcs(const std::string& input)
	{
		if (input.empty())
		{
			return std::wstring();
		}

		// Passing a nulll deestination will provide the number of characters 
		// that would need to be written to the wstring.
		size_t required;
		::mbstowcs_s(
			&required,
			nullptr,
			0,
			input.data(),
			input.size());
		if (0 == required)
		{
			return std::wstring();
		}

		std::vector<wchar_t> output;
		output.resize(required);

		size_t converted;
		::mbstowcs_s(
			&converted,
			&output[0],
			output.size(),
			input.data(),
			input.size());
		if (0 == converted)
		{
			return std::wstring();
		}

		// Return one less charater as wcstombs_s will always null terminate. 
		return std::wstring(&output[0], output.size() - 1);
	}

	inline std::string to_mbs(const std::wstring& input)
	{
		if (input.empty())
		{
			return std::string();
		}

		// Passing a nulll deestination will provide the number of characters 
		// that would need to be written to the wstring.
		size_t required;
		auto res = ::wcstombs_s(
			&required,
			nullptr,
			0,
			input.data(),
			input.size());
		if (0 == required)
		{
			return std::string();
		}

		std::vector<char> output;
		output.resize(required);

		size_t converted;
		res = ::wcstombs_s(
			&converted,
			&output[0],
			output.size(),
			input.data(),
			input.size());
		if (0 == converted)
		{
			return std::string();
		}

		// Return one less charater as wcstombs_s will always null terminate. 
		return std::string(&output[0], output.size() - 1);
	}
}

// To make sure .get<std::wstring> works for nlohmann::json.
namespace nlohmann {
	template <>
	struct adl_serializer<std::wstring> {
		static void to_json(json& j, const std::wstring& str) {
			j = winrt::spotify_breakdown_playlists_cppwinrt::to_mbs(str);
		}

		static void from_json(const json& j, std::wstring& str) {
			str = winrt::spotify_breakdown_playlists_cppwinrt::to_wcs(j.get<std::string>());
		}
	};
}