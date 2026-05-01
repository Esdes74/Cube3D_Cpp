#ifndef OPTIONS_HPP
# define OPTIONS_HPP

# include <map>
# include <string>
# include <iostream>
# include <unistd.h>
# include <cstring>
# include "Cli.hpp"
# include "Utils.hpp"

using namespace std;

class Options
{
	private:
		map<string, void (*)(int &, char **)>	optionsMap;

		static void	cliOpt(int &i, char **av){
			cout << "Dans la fonction de cli" << endl;
			Cli().openCli();
		};

		static void	cliFileOpt(int &i, char **av){
			if (av[++i]){
				verifCliFileArg(av[i]);
				Cli().openCliFile(av[++i]);
			} else {
				throw NoCliFileArgument();
			}
		};

		static void	debugOpt(int &i, char **av){
			debug = true;
		};

		static void	headlessOpt(int &i, char **av){
			headed = false;
		};

		static void	logoutOpt(int &i, char **av){
			if (av[++i]){
				verifLogoutArg(av[i]);
				logout = av[i];
			} else {
				throw NoLogoutArgument();
			}
		};

		static void	logrepOpt(int &i, char **av){
			if (av[++i]){
				verifLogrepArg(av[i]);
				log_rep = av[i];
			} else {
				throw NoLogrepArgument();
			}
		};

		static void	verifCliFileArg(char *path){
			if (access(path, F_OK | R_OK)){
				return ;
			}
			throw CliFileArgumentUnvalid();
		}

		static void	verifLogoutArg(char *file){
			vector<string>	file_name;

			file_name = Utils::splitString(file, '.');
			if (file_name.back() == "log"){
				return ;
			}
			throw LogoutArgumentUnvalid();
		}

		static void	verifLogrepArg(char *rep){
			if (access(rep, F_OK | R_OK)){
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
			optionsMap["--log-rep"] = logrepOpt;
		};

		void	find(int &i, char **av){
			map<string, void (*)(int &, char **)>::iterator	it;
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