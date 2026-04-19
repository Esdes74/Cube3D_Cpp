#ifndef ARGUMENTS_HPP
# define ARGUMENTS_HPP

# include <map>
# include <string>
# include <iostream>
# include "cli.hpp"

using namespace std;

class Arguments
{
	private:
		map<string, void (*)(int &, char **)>	argumentsMap;

		static void	cli(int &i, char **av){
			cout << "Dans la fonction de cli" << endl;
			Cli().openCli();
		};

		static void	cliFile(int &i, char **av){
			cout << "Dans la fonction de cli file" << endl;
			// TODO: Gérer le cas ou il n'y a pas d'arguments
			Cli().openCliFile(av[++i]);
		};

		static void	debug(int &i, char **av){
			cout << "Dans la fonction de debug" << endl;
		};

		static void	headless(int &i, char **av){
			cout << "Dans la fonction de headless" << endl;
		};

	public:
		Arguments(){
			argumentsMap["--cli"] = cli;
			argumentsMap["--cli-file"] = cliFile;
			argumentsMap["--debug"] = debug;
			argumentsMap["--headless"] = headless;
		};

		void	find(int &i, char **av){
			map<string, void (*)(int &, char **)>::iterator	it;
			it = argumentsMap.find(av[i]);

			if (it != argumentsMap.end())
			{
				it->second(i, av);
			}
		};
};

#endif