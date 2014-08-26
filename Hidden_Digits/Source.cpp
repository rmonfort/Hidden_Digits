#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::map;

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	map<char, int> conversion_table;

	// Populate conversion table
	for (int i = 0, c = 'a'; i <= 9; i++, c++) // How in the blue hell does it not have problems with the char... auto? =S
	{
		conversion_table[c] = i;
	}

	string line;
	while (getline(ifs, line))
	{
		int digit_exists = 0;

		// Cycle through each character in line and compare it against conversion table
		for (auto &c : line)
		{
			// Ignore blanks, punctuations, whitespace, and capital letters
			if (isblank(c)| ispunct(c) | isspace (c) | isupper (c))
			{
				continue;
			}
			// Print digits and continue loop
			else if (isdigit(c))
			{
				cout << c;
				digit_exists = 1;
				continue;
			}

			// Compare character against conversion table
			auto search = conversion_table.find(c);
			if (search != conversion_table.end())
			{
				digit_exists = 1;
				cout << conversion_table.find(c)->second;
			}
		}

		// If no hidden digits are found, output NONE, otherwise endl
		if (!digit_exists)
		{
			cout << "NONE" << endl;
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}