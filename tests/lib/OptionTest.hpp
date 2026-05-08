#ifndef OPTIONTEST_HPP
# define OPTIONTEST_HPP

# include <string>
# include <fstream>
# include <iostream>
# include <cstdlib>
# include "AbstractTest.hpp"
# include "Options.hpp"

using namespace std;

class	OptionTest: public AbstractTest
{
	private:
		Options	option;

		vector<string>	optionTestDebug = {"--debug"};

		vector<string>	optionTestHeadless = {"--headless"};

		vector<string>	optionTestCliFileGoodCommand = {"--cli-file", "tests/files/CliFileTests/GoodCommands.cli"};
		vector<string>	optionTestCliFileNotGoodCommand = {"--cli-file", "tests/files/CliFileTests/NotGoodCommands.cli"};
		vector<string>	optionTestCliFileBadExtension = {"--cli-file", "tests/files/CliFileTests/BadExtension.txt"};
		vector<string>	optionTestCliFileNoExtension = {"--cli-file", "tests/files/CliFileTests/NoExtension"};
		vector<string>	optionTestCliFileUnreadable = {"--cli-file", "tests/files/CliFilesTests/Unreadable.cli"};
		vector<string>	optionTestCliFileUnwritable = {"--cli-file", "tests/files/CliFilesTests/Unwritable.cli"};
		vector<string>	optionTestCliFileUnexecutable = {"--cli-file", "tests/files/CliFilesTests/Unexecutable.cli"};
		vector<string>	optionTestCliFileUnexisting = {"--cli-file", "Unexisting.cli"};
		vector<string>	optionTestCliFileEmpty = {"--cli-file", ""};
		vector<string>	optionTestCliFileNone = {"--cli-file"};

		vector<string>	optionTestLogout = {"--logout", "option_test_log.log"};
		vector<string>	optionTestLogoutNotExisting = {"--logout", "Unexisting.log"};
		vector<string>	optionTestLogoutUnexistingRep = {"--logout", "UnexistingRep/Null.log"};
		vector<string>	optionTestLogoutUnreadable = {"--logout", "Unreadable.log"};
		vector<string>	optionTestLogoutUnwritable = {"--logout", "Unwritable.log"};
		vector<string>	optionTestLogoutUnexecutable = {"--logout", "Unexecutable.log"};
		vector<string>	optionTestLogoutBadExtension = {"--logout", "BadExtension.txt"};
		vector<string>	optionTestLogoutNoExtension = {"--logout", "NoExtension"};
		vector<string>	optionTestLogoutEmpty = {"--logout", ""};
		vector<string>	optionTestLogoutNone = {"--logout"};

		vector<string>	optionTestLogRep = {"--log-repository", "test/log/"};
		vector<string>	optionTestLogRepUnwritableRep = {"--log-repository", "test/files/LogTests/Unwritable/"};
		vector<string>	optionTestLogRepUnreadableRep = {"--log-repository", "test/files/LogTests/Unreadable/"};
		vector<string>	optionTestLogRepUnexecutableRep = {"--log-repository", "test/files/LogTests/Unexecutable/"};
		vector<string>	optionTestLogRepUnexistingRep = {"--log-repository", "test/files/LogTests/Unexisting/"};
		vector<string>	optionTestLogRepEmpty = {"--log-repository", ""};
		vector<string>	optionTestLogRepNone = {"--log-repository"};

	protected:
		void	initDebugTest(){
			debug = false;
		}

		void	initHeadlessTest(){
			headed = true;
		}

		void	initLogoutTest(){
			log_rep = "tests/files/LogTests/";
			system("rm -rf tests/files/LogTests/Unexisting.log tests/files/LogTests/UnexistingRep");
		}

		void	initLogrepTest(){
			system("rm -rf tests/files/LogTests/UnexistingRep");
		}

		void	initCliFileTest(){
		};

		void	runDebugTest(){
			initDebugTest();
			int	ind;

			ind = 0;
			logFile << "##########################################" << endl;
			logFile << "Début du test de l'option --debug" << endl;
			logFile << "##########################################\n" << endl;

			option.find(ind, optionTestDebug);
			logFile << "Après l'utilisation de l'option debug, debug = ";
			if (debug){
				logFile << "true" << endl;
			} else {
				logFile << "false" << endl;
			}
		}

		void	runHeadlessTest(){
			initHeadlessTest();
			int	ind;

			ind = 0;
			logFile << "\n##########################################" << endl;
			logFile << "Début du test de l'option --headless" << endl;
			logFile << "##########################################\n" << endl;

			option.find(ind, optionTestHeadless);
			logFile << "Après l'utilisation de l'option headless, headed = ";
			if (headed){
				logFile << "true" << endl;
			} else {
				logFile << "false" << endl;
			}
		}

		void	runLogoutTest(){
			initLogoutTest();
			int	ind;

			logFile << "\n##########################################" << endl;
			logFile << "Début du test de l'option --logout" << endl;
			logFile << "##########################################\n" << endl;

			ind = 0;
			try{
				option.find(ind, optionTestLogoutNotExisting);

				if (system("find tests/files/LogTests/Unexisting.log")){
					logFile << "Après l'utilisation de l'option logout, le fichier tests/files/LogTests/Unexisting.log n'éxiste pas alors qu'il devrait" << endl;
				} else {
					logFile << "Fichier tests/files/LogTests/Unexisting.log correctement créée" << endl;
				}

				logFile << "Après l'utilisation de l'option logout, logout = " << logout << endl;
			} catch (exception &expt){
				logFile << "Exception attrapé pour optionTestLogoutNotExisting: il ne devrait pas y en avoir" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestLogoutUnexistingRep);

				if (system("find tests/files/LogTests/UnexistingRep")){
					logFile << "Après l'utilisation de l'option logout, le répertoire tests/files/LogTests/UnexistingRep n'éxiste pas alors qu'il devrait" << endl;
				} else {
					logFile << "Répertoire tests/files/LogTests/UnexistingRep correctement créée" << endl;
				}

				logFile << "Après l'utilisation de l'option logout, logout = " << logout << endl;
			} catch (exception &expt){
				logFile << "Exception attrapé pour optionTestLogoutUnexistingRep: il ne devrait pas y en avoir" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestLogoutUnreadable);
				logFile << "Après l'utilisation de l'option logout, logout = " << logout << endl;
			} catch (exception &expt){
				logFile << "Exception attrapé pour optionTestLogoutUnreadable: il ne devrait pas y en avoir" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestLogoutUnexecutable);
				logFile << "Après l'utilisation de l'option logout, logout = " << logout << endl;
			} catch (exception &expt){
				logFile << "Exception attrapé pour optionTestLogoutUnexecutable: il ne devrait pas y en avoir" << endl;
			}

			ind = 0;
			log_rep = "tests/log";
			try{
				option.find(ind, optionTestLogout);
				logFile << "Après l'utilisation de l'option logout, logout = " << logout << endl;
			} catch (exception &expt){
				logFile << "Exception attrapé pour optionTestLogout: il ne devrait pas y en avoir" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestLogoutUnwritable);
			} catch (const Options::LogoutArgumentUnvalid &expt){
				logFile << "Exception LogoutArgumentUnvalid attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception anormale attrapé pour optionTestLogoutUnwritable: il devrait y avoir l'exception CliFileArgumentUnvalid" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestLogoutBadExtension);
			} catch (const Options::LogoutArgumentUnvalid &expt){
				logFile << "Exception LogoutArgumentUnvalid attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception anormale attrapé pour optionTestLogoutBadExtension: il devrait y avoir l'exception CliFileArgumentUnvalid" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestLogoutNoExtension);
			} catch (const Options::LogoutArgumentUnvalid &expt){
				logFile << "Exception LogoutArgumentUnvalid attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception anormale attrapé pour optionTestLogoutNoExtension: il devrait y avoir l'exception CliFileArgumentUnvalid" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestLogoutEmpty);
			} catch (const Options::LogoutArgumentUnvalid &expt){
				logFile << "Exception LogoutArgumentUnvalid attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception anormale attrapé pour optionTestLogoutEmpty: il devrait y avoir l'exception CliFileArgumentUnvalid" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestLogoutNone);
			} catch (const Options::NoLogoutArgument &expt){
				logFile << "Exception NoLogoutArgument attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception anormale attrapé pour optionTestLogoutNone: il devrait y avoir l'exception NoCliFileArgument" << endl;
			}
		}

		void	runLogrepTest(){
			initLogrepTest();
			int	ind;

			logFile << "\n##########################################" << endl;
			logFile << "Début du test de l'option --log-repository" << endl;
			logFile << "##########################################\n" << endl;

			ind = 0;
			try{
				option.find(ind, optionTestLogRepUnexistingRep);

				if (system("find tests/files/LogTests/UnexistingRep")){
					logFile << "Après l'utilisation de l'option log rep, le répertoire tests/files/LogTests/UnexistingRep n'éxiste pas alors qu'il devrait" << endl;
				} else {
					logFile << "Répertoire tests/files/LogTests/UnexistingRep correctement créée" << endl;
				}

				logFile << "Après l'utilisation de l'option log rep, log_rep = " << log_rep << endl;
			} catch (exception &expt){
				logFile << "Exception anormale attrapé pour optionTestLogRepUnexistingRep: il devrait y avoir l'exception CliFileArgumentUnvalid" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestLogRep);
				logFile << "Après l'utilisation de l'option log rep, log_rep = " << log_rep << endl;
			} catch (exception &expt){
				logFile << "Exception attrapé pour optionTestLogRep: il ne devrait pas y en avoir" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestLogRepUnwritableRep);
			} catch (const Options::LogrepArgumentUnvalid &expt){
				logFile << "Exception LogrepArgumentUnvalid attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception anormale attrapé pour optionTestLogRepUnwritableRep: il devrait y avoir l'exception CliFileArgumentUnvalid" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestLogRepUnreadableRep);
			} catch (const Options::LogrepArgumentUnvalid &expt){
				logFile << "Exception LogrepArgumentUnvalid attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception anormale attrapé pour optionTestLogRepUnreadableRep: il devrait y avoir l'exception CliFileArgumentUnvalid" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestLogRepUnexecutableRep);
			} catch (const Options::LogrepArgumentUnvalid &expt){
				logFile << "Exception LogrepArgumentUnvalid attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception anormale attrapé pour optionTestLogRepUnexecutableRep: il devrait y avoir l'exception CliFileArgumentUnvalid" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestLogRepUnexistingRep);
			} catch (const Options::LogrepArgumentUnvalid &expt){
				logFile << "Exception LogrepArgumentUnvalid attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception anormale attrapé pour optionTestLogRepUnexistingRep: il devrait y avoir l'exception CliFileArgumentUnvalid" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestLogRepEmpty);
			} catch (const Options::LogrepArgumentUnvalid &expt){
				logFile << "Exception LogrepArgumentUnvalid attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception anormale attrapé pour optionTestLogRepEmpty: il devrait y avoir l'exception CliFileArgumentUnvalid" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestLogRepNone);
			} catch (const Options::NoLogrepArgument &expt){
				logFile << "Exception NoLogrepArgument attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception anormale attrapé pour optionTestLogRepNone: il devrait y avoir l'exception NoCliFileArgument" << endl;
			}
		}

		void	runCliFileTest(){
			initCliFileTest();
			int	ind;

			logFile << "\n##########################################" << endl;
			logFile << "Début du test de l'option --cli-file" << endl;
			logFile << "##########################################\n" << endl;

			ind = 0;
			try{
				option.find(ind, optionTestCliFileGoodCommand);
			} catch (exception &expt){
				logFile << "Exception attrapé pour optionTestCliFileGoodCommand: il ne devrait pas y en avoir" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestCliFileNotGoodCommand);
			} catch (exception &expt){
				logFile << "Exception attrapé pour optionTestCliFileNotGoodCommand: il ne devrait pas y en avoir" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestCliFileUnwritable);
			} catch (exception &expt){
				logFile << "Exception attrapé pour optionTestCliFileUnwritable: il ne devrait pas y en avoir" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestCliFileUnexecutable);
			} catch (exception &expt){
				logFile << "Exception attrapé pour optionTestCliFileUnexecutable: il ne devrait pas y en avoir" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestCliFileBadExtension);
			} catch (const Options::CliFileArgumentUnvalid &expt){
				logFile << "Exception CliFileArgumentUnvalid attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception anormale attrapé pour optionTestCliFileBadExtension: il devrait y avoir l'exception CliFileArgumentUnvalid" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestCliFileNoExtension);
			} catch (const Options::CliFileArgumentUnvalid &expt){
				logFile << "Exception CliFileArgumentUnvalid attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception anormale attrapé pour optionTestCliFileNoExtension: il devrait y avoir l'exception CliFileArgumentUnvalid" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestCliFileUnreadable);
			} catch (const Options::CliFileArgumentUnvalid &expt){
				logFile << "Exception CliFileArgumentUnvalid attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception anormale attrapé pour optionTestCliFileUnreadable: il devrait y avoir l'exception CliFileArgumentUnvalid" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestCliFileUnexisting);
			} catch (const Options::CliFileArgumentUnvalid &expt){
				logFile << "Exception CliFileArgumentUnvalid attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception anormale attrapé pour optionTestCliFileUnexisting: il devrait y avoir l'exception CliFileArgumentUnvalid" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestCliFileEmpty);
			} catch (const Options::CliFileArgumentUnvalid &expt){
				logFile << "Exception CliFileArgumentUnvalid attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception anormale attrapé pour optionTestCliFileEmpty: il devrait y avoir l'exception CliFileArgumentUnvalid" << endl;
			}

			ind = 0;
			try{
				option.find(ind, optionTestCliFileNone);
			} catch (const Options::NoCliFileArgument &expt){
				logFile << "Exception NoCliFileArgument attrapée" << endl;
			} catch (exception &expt){
				logFile << "Exception anormale attrapé pour optionTestCliFileNone: il devrait y avoir l'exception NoCliFileArgument" << endl;
			}
		}

		void	initTest(){
		};

		void	run(){
			runDebugTest();
			runHeadlessTest();
			runLogoutTest();
			runLogrepTest();
			runCliFileTest();
		};

		void	errorMSG(){
			cout << "Error message with " << file << endl;
		};

	public:
		OptionTest(): AbstractTest("option_test_log.txt"){};
};

#endif