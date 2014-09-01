#include <sstream>
#include <cstring>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

void empty(int num, int buckets, string * content, string * allBuckets);
void put(int num, int buckets, string * content, string * allBuckets);
void output(int num, int buckets, string * content, string * allBuckets);

int main (int argc, char * argv[])
{
	//Read file
	ifstream ifs ( argv[1] );

	if ( !ifs )
	{
		cout << "Unable to open file: " << argv[1] <<endl;
		return -1;
	}

	//Identify how many buckets and commands in file
	string stats;
	getline(ifs, stats);
	int bucket;
	int command;
	char * cstr = new char [stats.length()+1];
	strcpy (cstr, stats.c_str());
	bucket = atoi (cstr);
	command = atoi (cstr+1);


	//Allocate array to store all bucket info
	string * allBuckets = new string[bucket];
	for (int i = 0; i < bucket; i++)
	{
		allBuckets[i] = "EMPTY";
	}

	//Allocate array to store all commands
	string * content;
	content = new string[command];

	for (int i = 0; i < command; i++)
	{
		getline(ifs, content[i]);
	}

	for (int i = 0; i < command; i++)
	{
		if (content[i].find("EMPTY") != string::npos)
		{
			empty(i, bucket, content, allBuckets);
		}

		else if (content[i].find("PUT") != string::npos && content[i].find("OUT") == string::npos)
		{
			put(i, bucket, content, allBuckets);
		}

		else if (content[i].find("OUTPUT") != string::npos)
		{
			output(i, bucket, content, allBuckets);
		}

		else
		{
			cout << "Your file is improperly formatted." << endl;
			return -1;
		}

	}

	delete [] cstr;
	delete [] allBuckets;
	cstr = NULL;
	allBuckets = NULL;


	ifs.close();
	return 0;

}

void empty(int num, int buckets, string * content, string * allBuckets)
{
	string command = *(content+num);

	char * newstr = new char [(command.length()+1)];
	strcpy (newstr, command.c_str());
	stringstream ss(newstr+5);
	int current;
	ss >> current;

	if (current > buckets || current <= 0)
	{
		cout << "Error - bucket " << current << " does not exist.empty" << endl;
	}

	else
	{
		*(allBuckets+(current-1)) = "EMPTY";
		cout << "emptied" << endl;

	}
	delete [] newstr;
	newstr = NULL;

}

void put(int num, int buckets, string * content, string * allBuckets)
{
	string command = *(content+num);
	char * newstr = new char [(command.length()+1)];

	strcpy (newstr, command.c_str());
	stringstream ss(newstr+3);
	int current;
	ss >> current;

	if (*(allBuckets+(current-1)) != "EMPTY")
	{
		cout << "Error - bucket " << current << " is not empty." << endl;
	}

	else if (current > buckets || current <= 0)
	{
		cout << "Error - bucket " << current << " does not exist.put" << endl;
	}

	else
	{

		string numbers = "0123456789";
		int i = 0;
		size_t found = 0;
		while (i < 3)
		{
			found = (content+num)->find_first_of(numbers.c_str(), found+i);
			i++;
		}

		(content+num)->erase(0, found);
		*(allBuckets+(current-1)) = *(content+num);

	}

	delete [] newstr;
	newstr = NULL;
}

void output(int num, int buckets, string * content, string * allBuckets)
{
	string command = *(content+num);
	char * newstr = new char [(command.length()+1)];
	strcpy (newstr, command.c_str());
	stringstream ss(newstr+6);
	int current;
	ss >> current;

	if (current > buckets || current <= 0)
	{
		cout << "Error - bucket " << current << " does not exist." << endl;
	}

	else
	{
		cout << *(allBuckets+(current-1)) << endl;

	}

	delete[] newstr;
	newstr = NULL;

}

