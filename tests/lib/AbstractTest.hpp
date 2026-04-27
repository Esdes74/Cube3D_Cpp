#ifndef ABSTRACTTEST_HPP
# define ABSTRACTTEST_HPP

# include <string>
# include <fstream>
# include <sstream>

using namespace std;

bool	debug = true;
ofstream	logout;

class	AbstractTest
{
	protected:
		string			file;
		ofstream		logFile;
		ifstream		waitedLogFile;

		void			verif(){
			string		waitedLine;
			string		logLine;
			ifstream	givenLog("tests/log/" + file);

			while (getline(waitedLogFile, waitedLine)){
				getline(givenLog, logLine);
				if (waitedLine.compare(logLine) != 0){
					errorMSG();
				}
			}
		}

		void virtual	initTest() = 0;
		void virtual	run() = 0;
		void virtual	errorMSG() = 0;

	public:
		AbstractTest(string str): file(str){
			logFile.open("tests/log/" + file);
			waitedLogFile.open("tests/waited_log/" + file);
		}

		void	runTest(){
			initTest();
			run();
			verif();
		}
};

#endif