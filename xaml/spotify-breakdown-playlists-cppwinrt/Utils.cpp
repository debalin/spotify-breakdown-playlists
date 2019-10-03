#include "pch.h"
#include "Utils.h"
#include "Constants.h"

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
