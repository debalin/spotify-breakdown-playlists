#pragma once

namespace Utils
{
	std::wstring FormUri(const std::wstring& baseUri, const std::vector<std::pair<std::wstring, std::wstring>>& paramsAndValues);
	std::wstring GetQueryValue(const std::wstring& uri, const std::wstring& queryParameter);
};

