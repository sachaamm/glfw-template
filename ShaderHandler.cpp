#include "ShaderHandler.h"
#include "StringUtil.h"
#include <fstream>

char* ShaderHandler::ImportDefaultVertexShader() {
	std::ifstream t("vertex.glsl");
	std::string str((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());

	char* fileContent = StringUtil::AsCharPtr(str);

	return fileContent;
}

char* ShaderHandler::ImportDefaultFragShader()
{
	std::ifstream t("frag.glsl");
	std::string str((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());

	char* fileContent = StringUtil::AsCharPtr(str);

	return fileContent;
}
