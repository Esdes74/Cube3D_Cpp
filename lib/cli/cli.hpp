#ifndef CLI_HPP
# define CLI_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <vector>
# include "utils.hpp"

using namespace std;

class Cli
{
	private:
		map<string, void (*)(vector<string> &)>	cliMap;

		static void	bonjour(vector<string> &args){
			cout << "bonjour" << endl;
			for (size_t i = 1; i < args.size(); i++)
			{
				cout << args[i] << endl;
			}
		};

	public:
		Cli(){
			cliMap["bonjour"] = bonjour;
		};

		void openCli()
		{
			// TODO: Ajouter une logique de thread
			string										line;
			vector<string>								args;
			map<string, void (*)(vector<string> &)>::iterator	it;

			while (getline(cin, line))
			{
				args = Utils::splitString(line, ' ');

				if (args.size() > 0)
				{
					it = cliMap.find(args[0]);
					if (it != cliMap.end()){
						it->second(args);
					}
				}
			}
		}

		void	openCliFile(string str){
			// TODO: Ajouter une logique de thread
			string												line;
			vector<string>										args;
			map<string, void (*)(vector<string> &)>::iterator	it;

			ifstream	file(str);

			if (file)
			{
				while (getline(file, line))
				{
					args = Utils::splitString(line, ' ');

					if (args.size() > 0)
					{
						it = cliMap.find(args[0]);
						if (it != cliMap.end()){
							it->second(args);
						}
					}
				}
			}
		};
};

#endif