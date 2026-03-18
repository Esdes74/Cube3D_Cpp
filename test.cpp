#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
 
int main(int ac, char** av)
{
    // greet the user
    std::string name;
    std::cout << "What is your name? ";
    std::getline(std::cin, name);
    std::cout << "Hello " << name << ", nice to meet you.\n";
 
    // read file line by line
    std::istringstream input;
    input.str("1\n2\n3\n4\n5\n6\n7\n");
    int sum = 0;
    for (std::string line; std::getline(input, line);)
        sum += std::stoi(line);
    std::cout << "\nThe sum is " << sum << ".\n\n";
 
    // use separator to read parts of the line
    std::istringstream input2;
    input2.str("a;b;c;d");
    for (std::string line; std::getline(input2, line, ';');)
        std::cout << line << '\n';
    std::cout << '\n';

    // lecture d'un fichier
    if (ac < 1)
        std::cout << "Error: Missing argument" << std::endl;
    std::ifstream inputFile = std::ifstream(av[1], std::ios_base::in);
    for (std::string line; std::getline(inputFile, line);)
        std::cout << line << '\n';

    return 0;
}