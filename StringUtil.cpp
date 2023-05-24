#include "StringUtil.h"

char* StringUtil::AsCharPtr(std::string str)
{
	int n = str.length();
	char* c = new char[n];

	for (int i = 0; i < n; i++) {
		c[i] = str[i];
	}

	return c;
}
