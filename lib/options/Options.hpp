#ifndef OPTIONS_HPP
# define OPTIONS_HPP

# include <map>
# include <string>
# include <iostream>
# include <unistd.h>
# include <cstring>
# include <algorithm>
# include "Cli.hpp"
# include "Utils.hpp"

using namespace std;

class Options
{
	private:
		map<string, void (*)(int &, vector<string>)>	optionsMap;

		static void	cliOpt(int &i, vector<string> av){
			cout << "Dans la fonction de cli" << endl;
			Cli().openCli();
		};

		static void	cliFileOpt(int &i, vector<string> av){
			if ((size_t)i < av.size()){
				verifCliFileArg(av[i]);
				Cli().openCliFile(av[i]);
			} else {
				throw NoCliFileArgument();
			}
		};

		static void	debugOpt(int &i, vector<string> av){
			debug = true;
		};

		static void	headlessOpt(int &i, vector<string> av){
			headed = false;
		};

		static void	logoutOpt(int &i, vector<string> av){
			if ((size_t)i < av.size()){
				verifLogoutArg(av[i]);
				logout = av[i];
			} else {
				throw NoLogoutArgument();
			}
		};

		static void	logrepOpt(int &i, vector<string> av){
			if ((size_t)i < av.size()){
				verifLogrepArg(av[i]);
				log_rep = av[i];
			} else {
				throw NoLogrepArgument();
			}
		};

		static void	verifCliFileArg(string path){
			if (access(path.c_str(), F_OK | R_OK)){
				return ;
			}
			throw CliFileArgumentUnvalid();
		}

		static void	verifLogoutArg(string file){
			vector<string>	file_name;

			file_name = Utils::splitString(file, '.');
			if (file_name.back() == "log"){
				return ;
			}
			throw LogoutArgumentUnvalid();
		}

		static void	verifLogrepArg(string rep){
			if (access(rep.c_str(), F_OK | R_OK)){
				return ;
			}
			throw LogrepArgumentUnvalid();
		}

	public:
		Options(){
			optionsMap["--cli"] = cliOpt;
			optionsMap["--cli-file"] = cliFileOpt;
			optionsMap["--debug"] = debugOpt;
			optionsMap["--headless"] = headlessOpt;
			optionsMap["--logout"] = logoutOpt;
			optionsMap["--log-repository"] = logrepOpt;
		};

		vector<string>	handleArgs(char **av){
			int				ind;
			vector<string>	argVector;
			vector<string>	optOrder = {"--debug", "--log-rep", "--logout"};

			for (size_t i = 0; i < optOrder.size(); i++){
				ind = 1;
				while (av[ind]){
					if (av[ind] == optOrder[i]){
						argVector.push_back(av[ind]);
						if (i > 0 && av[++ind]){
							argVector.push_back(av[ind]);
						}
					}
					ind++;
				}
			}

			ind = 0;
			while (av[ind]){
				if (std::find(argVector.begin(), argVector.end(), av[ind]) != argVector.end()){
					argVector.push_back(av[ind]);
				}
				ind++;
			}

			return (argVector);
		}

		void			find(int &i, vector<string> av){
			map<string, void (*)(int &, vector<string> )>::iterator	it;
			it = optionsMap.find(av[i]);

			if (it != optionsMap.end())
			{
				it->second(i, av);
			}
		};

		class NoLogoutArgument: public exception{
			public:
				virtual const char	*what() const throw(){
					return ("Need logout argument");
				}
		};

		class NoLogrepArgument: public exception{
			public:
				virtual const char	*what() const throw(){
					return ("Need log repository argument");
				}
		};

		class NoCliFileArgument: public exception{
			public:
				virtual const char	*what() const throw(){
					return ("Need cli file argument");
				}
		};

		class LogoutArgumentUnvalid: public exception{
			public:
				virtual const char	*what() const throw(){
					return ("Unvalid logout argument");
				}
		};

		class LogrepArgumentUnvalid: public exception{
			public:
				virtual const char	*what() const throw(){
					return ("Unvalid log repository argument");
				}
		};

		class CliFileArgumentUnvalid: public exception{
			public:
				virtual const char	*what() const throw(){
					return ("Unvalid cli file argument");
				}
		};
};

#endif