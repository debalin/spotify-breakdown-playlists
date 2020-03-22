#include "pch.h"
#include "Utils.h"
#include "Constants.h"

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;

namespace winrt::spotify_breakdown_playlists_cppwinrt
{
	std::wstring Utils::FormUri(
		const std::wstring& baseUri,
		const std::vector<std::pair<std::wstring, std::wstring>>& paramsAndValues)
	{
		std::wstring formedUri = baseUri + HttpConstants::g_Question;

		std::for_each(paramsAndValues.begin(), paramsAndValues.end(), [&](const auto& paramAndValue)
			{
				formedUri += paramAndValue.first +
					HttpConstants::g_Equals +
					paramAndValue.second +
					HttpConstants::g_Ampersand;
			});
		formedUri.pop_back();

		return formedUri;
	}

	std::wstring Utils::GetQueryValue(
		const std::wstring& uri,
		const std::wstring& queryParameter)
	{
		auto queryParamSize = queryParameter.size() + 1; // 1 for the "=" sign after the parameter.
		auto queryParamPosition = uri.find(queryParameter);
		auto queryValuePosition = queryParamPosition + queryParamSize;
		auto nextQueryPosition = uri.find(HttpConstants::g_Ampersand, queryValuePosition);

		auto value = uri.substr(queryValuePosition,
			(nextQueryPosition != std::wstring::npos) ?
			(nextQueryPosition - queryValuePosition) :
			uri.size());
		return value;
	}
	
	IVector<IInspectable> Utils::WrapNavigationArgs(const std::initializer_list<Windows::Foundation::IInspectable>& args)
	{
		IVector<IInspectable> v = single_threaded_vector<IInspectable>();
		
		for (const auto arg : args)
		{
			v.Append(arg);
		}

		return v;
	}
}