// Run Length Algorithm Implementation by Jonah McElfatrick
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

string inputFile() {
	// Variables for the contents of the file to be assigned to and the line in which the file will assigned each lines contents to
	string contents;
	string line;

	// Opens the text file for reading
	fstream myInputFile;
	myInputFile.open("TextFile.txt", ios::in);

	// Check to see if the TextFile.txt file was sucessfully opened
	if (!myInputFile) {
		cout << "Unable to open TextFile.txt";
		exit(1);
	}
	// Loops untill there is no more data to read from the text file
	while (myInputFile.good()) {
		getline(myInputFile, line);
		contents += line;
	}

	//Closes the input textfile
	myInputFile.close();

	return contents;
}

int main() {
	// Variables for the contents of the file and the length of the contents
	string fileContents;
	int length_of_inputFile;

	// Calls the function that will read the file in and passes the contents to the assigned variable
	fileContents = inputFile();

	// Calcualtes the length of the file contents and assigns it to a variable
	length_of_inputFile = fileContents.length();

	// Loops through the contents of the file
	for (int i = 0; i < length_of_inputFile; i++) {
		int numberOfOccurrences = 1;
		while (fileContents[i+1]==fileContents[i]) {
			numberOfOccurrences += 1;
			//cout << numberOfOccurrences;
			i++;
		}
		cout << numberOfOccurrences << fileContents[i] << endl;
		// Open's the output file to store the compressed version of the input file
		fstream myOutputFile;
		myOutputFile.open("Output.txt", ios::app);
		// Stores the variables one after the other
		myOutputFile << numberOfOccurrences;
		myOutputFile << fileContents[i];
		myOutputFile << endl;
	}
	int enter;
	system("pause");
}