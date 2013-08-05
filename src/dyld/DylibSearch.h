#ifndef DYLIBSEARCH_H
#define DYLIBSEARCH_H
#include <util/IniConfig.h>
#include <string>
#include <regex.h>

namespace Darling {

class MachOObject;

class DylibSearch
{
private:
	DylibSearch();
public:
	static DylibSearch* instance();
	
	std::string resolve(std::string name, MachOObject* requester);
private:
	std::string resolveViaRpath(std::string name, MachOObject* requester);
	std::string resolveInLdPath(std::string name);
	const char* resolveAlias(const std::string& library);
	static std::string filenameFromPath(const std::string& path);
private:
	IniConfig* m_config;
	regex_t m_reFrameworkPath;
};

}

#endif
