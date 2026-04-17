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
		
		static void	handlerCli(int &i, char **av){
			cout << "Dans la fonction de cli" << endl;
			Cli().openCli();
		};
	
		static void	handlerCliFile(int &i, char **av){
			cout << "Dans la fonction de cli file" << endl;
			// TODO: Gérer le cas ou il n'y a pas d'arguments
			Cli().openCli(av[++i]);
		};
	
		static void	handlerDebug(int &i, char **av){
			cout << "Dans la fonction de debug" << endl;
		};
	
		static void	handlerHeadless(int &i, char **av){
			cout << "Dans la fonction de headless" << endl;
		};

	public:
		Arguments(){
			argumentsMap["--cli"] = handlerCli;
			argumentsMap["--cli-file"] = handlerCliFile;
			argumentsMap["--debug"] = handlerDebug;
			argumentsMap["--headless"] = handlerHeadless;
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