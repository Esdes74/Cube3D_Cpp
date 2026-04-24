#ifndef CLITEST_HPP
# define CLITEST_HPP

# include <fstream>
# include <iostream>

using namespace std;

class	CliTest
{
	private:
		ofstream	logFile;
	
	public:
		CliTest(){
			logFile.open("tests/log/cli_test_log.txt");
		}

		~CliTest(){
			// Vérification du fichier de log
			logFile.close();
		}
};

#endif