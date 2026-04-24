#include "cli.hpp"
#include "CliTest.hpp"

int main() {
	vector<string>	str;
	Cli				cli;
	CliTest			cliTest;

	str.push_back("bonjour");
	str.push_back("je");
	str.push_back("suis");
	str.push_back("un");
	str.push_back("test");
	cli.executeBonjour(str);
	return 0;
}