#ifndef ARGUMENTS_HPP
# define ARGUMENTS_HPP

# include <map>
# include <string>
# include <iostream>

class Arguments
{
	private:
		std::map<std::string, void (*)()>	argumentsMap;
		
		static void	handlerCli(){
			std::cout << "Dans la fonction de cli" << std::endl;
		};
	
		static void	handlerCliFile(){
			std::cout << "Dans la fonction de cli file" << std::endl;
		};
	
		static void	handlerDebug(){
			std::cout << "Dans la fonction de debug" << std::endl;
		};
	
		static void	handlerHeadless(){
			std::cout << "Dans la fonction de headless" << std::endl;
		};

	public:
		Arguments(){
			argumentsMap["--cli"] = handlerCli;
			argumentsMap["--cli-file"] = handlerCliFile;
			argumentsMap["--debug"] = handlerDebug;
			argumentsMap["--headless"] = handlerHeadless;
		};

		void	find(std::string str){
			std::map<std::string, void (*)()>::iterator	it;
			it = argumentsMap.find(str);

			if (it != argumentsMap.end())
			{
				it->second();
			}
		};
};

#endif