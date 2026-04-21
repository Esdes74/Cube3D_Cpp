#ifndef OPTIONS_HPP
# define OPTIONS_HPP

# include <map>
# include <string>
# include <iostream>
# include "Cli.hpp"

using namespace std;

class Options
{
	private:
		map<string, void (*)(int &, char **)>	optionsMap;

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
		Options(){
			optionsMap["--cli"] = cli;
			optionsMap["--cli-file"] = cliFile;
			optionsMap["--debug"] = debug;
			optionsMap["--headless"] = headless;
		};

		void	find(int &i, char **av){
			map<string, void (*)(int &, char **)>::iterator	it;
			it = optionsMap.find(av[i]);

			if (it != optionsMap.end())
			{
				it->second(i, av);
			}
		};
};

#endif