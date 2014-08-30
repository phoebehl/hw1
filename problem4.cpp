#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

int main (int argc, char * argv[])
{
	//Read file
	ifstream ifs ( argv[1] );

	if ( !ifs )
	{
		cout << "Unable to open file: " << argv[1] <<endl;
		return -1;
	}

	//Identify how many lines in file
	string lines;
	getline(ifs, lines);
	int numLines = stoi (lines,NULL);

	//Allocate array to store file
	string * content;
	content = new string[numLines];

	for (int i = 0; i < numLines; i++)
	{
		getline(ifs, content[i]);
	}

	ifs.close();

	//Display line results
	for (int i = numLines-1; i > 0; i--)
	{
		cout << content[i] << endl;
	}

	delete [] content;

	return 0;


}
