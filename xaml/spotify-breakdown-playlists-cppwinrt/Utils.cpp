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

std::wstring Utils::StringToWString(const std::string& input)
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

std::string Utils::WStringToString(const std::wstring& input)
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