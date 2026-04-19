#include "cli.hpp"

int main() {
	vector<string>	str;
	Cli				cli;

	str.push_back("bonjour");
	str.push_back("je");
	str.push_back("suis");
	str.push_back("un");
	str.push_back("test");
	cli.executeBonjour(str);
	return 0;
}