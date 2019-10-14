#pragma once

namespace Utils
{
	std::wstring FormUri(const std::wstring& baseUri, const std::vector<std::pair<std::wstring, std::wstring>>& paramsAndValues);
	std::wstring GetQueryValue(const std::wstring& uri, const std::wstring& queryParameter);
	std::wstring StringToWString(const std::string& input);
	std::string WStringToString(const std::wstring& input);
};

namespace nlohmann {
	template <>
	struct adl_serializer<std::wstring> {
		static void to_json(json& j, const std::wstring& str) {
			j = Utils::WStringToString(str);
		}

		static void from_json(const json& j, std::wstring& str) {
			str = Utils::StringToWString(j.get<std::string>());
		}
	};
}

