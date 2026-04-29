#ifndef OPTIONTEST_HPP
# define OPTIONTEST_HPP

# include <string>
# include <fstream>
# include <iostream>
# include "AbstractTest.hpp"
# include "Options.hpp"

using namespace std;

class	OptionTest: public AbstractTest
{
	private:
		Options	option;

		char*	optionDebug = (char*) "--debug";
		char*	optionCliFile = (char*) "--cli-file";
		char*	optionHeaded = (char*) "--headed";
		char*	argNull = (char*) "null";
		char*	argGoodCommands = (char*) "tests/files/CliFilesTests/GoodCommands.txt";
		char*	argNotGoodCommands = (char*) "tests/files/CliFilesTests/NotGoodCommands.txt";

		char**	debugStr = new char*;
		char**	clifileGoodCommandStr = new char*[2];
		char**	clifileNotGoodCommandStr = new char*[2];
		char**	clifileNullStr = new char*[2];
		char**	clifileEmptyStr = new char*;
		char**	headedStr = new char*;

	protected:
		void	initTest(){
			// --debug
			cout << optionDebug << endl;
			debugStr[0] = optionDebug;
			debug = false;

			// --cli-file
			// Debug is true with the first test
			logout.open("tests/log/" + file);

			clifileGoodCommandStr[0] = optionCliFile;
			clifileGoodCommandStr[1] = argGoodCommands;

			clifileNotGoodCommandStr[0] = optionCliFile;
			clifileNotGoodCommandStr[1] = argNotGoodCommands;

			clifileNullStr[0] = optionCliFile;
			clifileNullStr[1] = argNull;

			clifileEmptyStr[0] = optionCliFile;

			// --cli-file
			headedStr[0] = optionHeaded;
		};

		void	run(){
			int	ind;

			ind = 0;
			// --debug
			logFile << "Début du test de l'option --debug" << endl;
			option.find(ind, debugStr);
			logFile << "Après l'utilisation de l'option debug, debug = ";
			if (debug){
				logFile << "true" << endl;
			} else {
				logFile << "false" << endl;
			}

			// --cli-file
			logFile << "Début du test de l'option --cli-file" << endl;
			try{
				option.find(ind, clifileGoodCommandStr);
			} catch (exception &expt){
				logFile << "Exception attrapé alors qu'il ne devrait pas y en avoir" << endl;
			}

			try{
				option.find(ind, clifileNotGoodCommandStr);
			// } catch (const Options::FileCliCommandDontExist &expt){
			// 	logFile << "Exception FileCliCommandDontExist attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception attrapé alors qu'il ne devrait pas y en avoir" << endl;
			}

			try{
				option.find(ind, clifileNullStr);
			// } catch (const Options::FileCliArgumentDontExist &expt){
			// 	logFile << "Exception FileCliArgumentDontExist attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception attrapé alors qu'il ne devrait pas y en avoir" << endl;
			}

			try{
				option.find(ind, clifileEmptyStr);
			// } catch (const Options::NoFileCliArgument &expt){
			// 	logFile << "Exception NoFileCliArgument attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception attrapé alors qu'il ne devrait pas y en avoir" << endl;
			}

			// --headed
			logFile << "Début du test de l'option --headed" << endl;
			option.find(ind, headedStr);
			logFile << "Après l'utilisation de l'option headed, headed = ";
			if (headed){
				logFile << "true" << endl;
			} else {
				logFile << "false" << endl;
			}
		};

		void	errorMSG(){
			cout << "Error message with " << file << endl;
		};

	public:
		OptionTest(): AbstractTest("option_test_log.txt"){};

		~OptionTest(){
			delete debugStr;
			delete[] clifileGoodCommandStr;
			delete[] clifileNotGoodCommandStr;
			delete[] clifileNullStr;
		}
};

#endif