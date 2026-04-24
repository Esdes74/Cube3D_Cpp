#ifndef CLITEST_HPP
# define CLITEST_HPP

# include <string>
# include <fstream>
# include <iostream>
# include "AbstractTest.hpp"

using namespace std;

class	CliTest: public AbstractTest
{
	private:
		string	test;

	protected:
		void	initTest(){
			test = "test001";
		};

		void	run(){
			logFile << "bonjour je suis le test " << test << endl;
		};

		void	errorMSG(){
			cout << "Error message with " << file << endl;
		};

	public:
		CliTest(): AbstractTest("cli_test_log.txt"){};
};

#endif