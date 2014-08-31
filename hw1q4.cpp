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
	strcpy (cstr, lines.c_str());
	numLines = atoi (cstr);

	//Allocate array to store file
	string * content;
	content = new string[numLines];

	for (int i = 0; i < numLines; i++)
	{
		getline(ifs, content[i]);
	}

	int * count = new int[numLines];
	for (int i = 0; i <numLines; i++)
	{
		int word_count = 0;
		stringstream ss (content[i]);
		string word;
		while (ss >> word)
		{
			word_count++;
		}
		count[i] = word_count;
	}

	//Display line results
	for (int i = numLines-1; i >= 0; i--)
	{
		cout << count[i] << endl;
	}

	delete [] content;
	delete [] count;
	delete [] cstr;

	content = NULL;
	count = NULL;
	cstr = NULL;
	ifs.close();

	return 0;


}
