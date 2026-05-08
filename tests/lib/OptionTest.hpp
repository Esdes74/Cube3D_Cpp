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

		vector<string>	optionTestDebug = {"--debug"};

		vector<string>	optionTestHeadless = {"--headless"};

		vector<string>	optionTestCliFileGoodCommand = {"--cli-file", "tests/filesCliFileTests/GoodCommands.cli"};
		vector<string>	optionTestCliFileNotGoodCommand = {"--cli-file", "tests/filesCliFileTests/NotGoodCommands.cli"};
		vector<string>	optionTestCliFileBadExtension = {"--cli-file", "tests/filesCliFileTests/BadExtension.txt"};
		vector<string>	optionTestCliFileUnreadable = {"--cli-file", "tests/filesCliFileTests/Unreadable.log"};
		vector<string>	optionTestCliFileUnexisting = {"--cli-file", "Unexisting.log"};
		vector<string>	optionTestCliFileEmpty = {"--cli-file", ""};
		vector<string>	optionTestCliFileNone = {"--cli-file"};

		vector<string>	optionTestLogout = {"--logout", "tests/log/option_test_log.log"};
		vector<string>	optionTestLogoutNotExisting = {"--logout", "tests/log/unexisting.log"};
		vector<string>	optionTestLogoutNullRep = {"--logout", "tests/logNull/null.log"};
		vector<string>	optionTestLogoutUnwritable = {"--logout", "tests/files/filesLogout/Unwritable.log"};
		vector<string>	optionTestLogoutBadExtension = {"--logout", "tests/files/filesLogout/BadExtension.txt"};
		vector<string>	optionTestLogoutEmpty = {"--logout", ""};
		vector<string>	optionTestLogoutNone = {"--logout"};

		vector<string>	optionTestLogRep = {"--log-repertory", "test/files/repLogRep/Rep"};
		vector<string>	optionTestLogRepUnaccessibleRep = {"--log-repertory", "test/files/repLogRep/Unaccessible"};
		vector<string>	optionTestLogRepUnexistingRep = {"--log-repertory", "test/files/repLogRep/Unexisting"};
		vector<string>	optionTestLogRepEmpty = {"--log-repertory", ""};
		vector<string>	optionTestLogRepNone = {"--log-repertory"};

	protected:
		void	initTest(){
			// // --debug
			// cout << optionDebug << endl;
			// debugStr[0] = optionDebug;
			debug = false;
			// TODO: Il faut supprimer le fichier de log qui est censé etre inexistant

			// // --cli-file
			// // Debug is true with the first test
			// logout.open("tests/log/" + file);

			// clifileGoodCommandStr[0] = optionCliFile;
			// clifileGoodCommandStr[1] = argGoodCommands;

			// clifileNotGoodCommandStr[0] = optionCliFile;
			// clifileNotGoodCommandStr[1] = argNotGoodCommands;

			// clifileNullStr[0] = optionCliFile;
			// clifileNullStr[1] = argNull;

			// clifileEmptyStr[0] = optionCliFile;

			// // --cli-file
			// headedStr[0] = optionHeaded;
		};

		void	run(){
			int	ind;

			ind = 0;
			// --debug
			logFile << "Début du test de l'option --debug" << endl;
			option.find(ind, optionTestDebug);
			logFile << "Après l'utilisation de l'option debug, debug = ";
			if (debug){
				logFile << "true" << endl;
			} else {
				logFile << "false" << endl;
			}

			// --cli-file
			logFile << "Début du test de l'option --cli-file" << endl;
			ind = 0;
			try{
				option.find(ind, optionTestCliFileGoodCommand);
			} catch (exception &expt){
				logFile << "Exception attrapé alors qu'il ne devrait pas y en avoir" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestCliFileNotGoodCommand);
			} catch (exception &expt){
				logFile << "Exception attrapé alors qu'il ne devrait pas y en avoir" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestCliFileNull);
			} catch (const Options::CliFileArgumentUnvalid &expt){
				logFile << "Exception CliFileArgumentUnvalid attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception attrapé alors qu'il ne devrait pas y en avoir" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestCliFileEmpty);
			} catch (const Options::CliFileArgumentUnvalid &expt){
				logFile << "Exception CliFileArgumentUnvalid attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception attrapé alors qu'il ne devrait pas y en avoir" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestCliFileNone);
			} catch (const Options::NoCliFileArgument &expt){
				logFile << "Exception NoCliFileArgument attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception attrapé alors qu'il ne devrait pas y en avoir" << endl;
			}

			// // --headed
			// logFile << "Début du test de l'option --headed" << endl;
			// option.find(ind, headedStr);
			// logFile << "Après l'utilisation de l'option headed, headed = ";
			// if (headed){
			// 	logFile << "true" << endl;
			// } else {
			// 	logFile << "false" << endl;
			// }
		};

		void	errorMSG(){
			cout << "Error message with " << file << endl;
		};

	public:
		OptionTest(): AbstractTest("option_test_log.txt"){};

		~OptionTest(){
			// delete debugStr;
			// delete[] clifileGoodCommandStr;
			// delete[] clifileNotGoodCommandStr;
			// delete[] clifileNullStr;
		}
};

#endif