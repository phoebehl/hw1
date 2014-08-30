#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <fstream>
#include <cstdlib>

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
	int numLines;
	char * cstr = new char [lines.length()+1];
	numLines = atoi (cstr);

	delete [] cstr;

	cout << "reached here";
	//Allocate array to store file
	string * content;
	content = new string[numLines];

	for (int i = 0; i < numLines; i++)
	{
		getline(ifs, content[i]);
	}

	ifs.close();
	cout << "reached here";

	//Display line results
	for (int i = numLines-1; i > 0; i--)
	{
		cout << content[i] << endl;
	}

	delete [] content;

	return 0;


}
