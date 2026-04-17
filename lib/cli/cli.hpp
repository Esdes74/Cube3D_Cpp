#ifndef CLI_HPP
# define CLI_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>

using namespace std;

class Cli
{
	private:
		map<string, void (*)(string &)>	cliMap;

		static void	bonjour(string &args){
			cout << "bonjour" << endl;
			cout << args << endl;
		};

	public:
		Cli(){
			cliMap["bonjour"] = bonjour;
		};

		void openCli(string str="")
		{
			// Il faut créer un thread ou un process pour la cli
			string	line;
			map<string, void (*)(string &)>::iterator	it;

			if (str != "")
			{
				ifstream	file(str);

				if (file)
				{
					while (getline(file, line, ' '))
					{
						// TODO: Mettre en place la logique d'appel des fonctions avec leurs arguments
						// cout << line << endl;
						it = cliMap.find(line);
						if (it != cliMap.end()){
							it->second(line);
						}
					}
				}
			}
			else
			{
				while(getline(cin, line, ' '))
				{
					// TODO: Mettre en place la logique d'appel des fonctions avec leurs arguments
					// TODO: Voir pourquoi il y a un problème avec cette fonction
					// (elle n'arrive pas a aller chercher la commande entrée dans le cin)
					// cout << line << endl;
					it = cliMap.find(line);
					if (it != cliMap.end()){
						it->second(line);
					}
				}
			}
		};
};

#endif