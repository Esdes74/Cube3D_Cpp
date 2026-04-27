#ifndef OPTIONTEST_HPP
# define OPTIONTEST_HPP

# include <string>
# include <fstream>
# include <iostream>
# include "AbstractTest.hpp"
# include "Option.hpp"

using namespace std;

class	OptionTest: public AbstractTest
{
	private:
		Option	option;

	protected:
		void	initTest(){
			// --debug
			debug = true;

			// --cli
			// Debug is true with the first test
			logout.open("tests/log/" + file);
		};

		void	run(){
			// --debug
			logFile << "Début du test de l'option --debug" << endl;
			option.find("--debug");
			logFile << "After debug option debug = ";
			if (debug){
				logFile << "true" << endl;
			} else {
				logFile << "false" << endl;
			}

			// --cli
			logFile << "Début du test de l'option --cli" << endl;
			option.find("--cli");
		};

		void	errorMSG(){
			cout << "Error message with " << file << endl;
		};

	public:
		OptionTest(): AbstractTest("option_test_log.txt"){};
};

#endif