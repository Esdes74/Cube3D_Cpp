#ifndef UTILS_HPP
# define UTILS_HPP

# include <vector>
# include <string>
# include <sstream>

using namespace std;

class Utils
{
	public:
		static vector<string>	splitString(const string &str, char delimiter)
		{
			stringstream ss(str);
			string token;
			vector<string> out;

			while (getline(ss, token, delimiter))
			{
				out.push_back(token);
			}

			return out;
		};
};

#endif