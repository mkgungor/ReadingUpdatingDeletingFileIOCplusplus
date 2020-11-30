//Murat Gungor 
//Reading file content into parallel arrays - and managing file content
#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
	const string FILE_NAME = "accounts.txt";

	ifstream fin;
	fin.open(FILE_NAME);

	if (!fin.is_open()) 
	{
		cout << "File " << FILE_NAME << " cannot be found\n";
		exit(0);
	}

	string name[20];
	double balance[20];
	bool toBeDeleted[20];

	int firstIndex = 0;

	//Read all the data from the file
	while (!fin.eof()) 
	{
		//Read from file
		fin >> name[firstIndex];
		if (name[firstIndex].empty())
			break;

		fin >> balance[firstIndex];
		toBeDeleted[firstIndex] = false; // Not to be deleted 
		// Print out to console
		cout << name[firstIndex] << " " << balance[firstIndex] << endl;

		//Next data will be written in to this index
		firstIndex++;	
	}
	fin.close();

	// Do updates here
	balance[1] -= 1000;

	// Write all the data once back to file

	ofstream fout;
	fout.open(FILE_NAME);

	if (!fout.is_open())
	{
		cout << "File " << FILE_NAME << " cannot be found\n";
		exit(0);
	}

	toBeDeleted[1] = true;

	for (int i = 0; i < firstIndex; i++) 
	{
		if (toBeDeleted[i])
			continue;

		//Write to the file
		fout << name[i] << endl;
		fout << balance[i] << endl;
	}
	fout.close();

}