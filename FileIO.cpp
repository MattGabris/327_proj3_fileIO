/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	contents.clear();

	ifstream file;
	file.open(filename, ios::in);

	if(file.is_open()){
		std::string line;
		while (!file.eof()){
			getline(file,line);
			contents = contents + " " + line;
		}
	} else {
		return COULD_NOT_OPEN_FILE_TO_READ;
	}
	file.close();
	return SUCCESS;
}

int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	ofstream stream;
	stream.open(filename, ios::out);

	if (stream.is_open()){
		for(std::vector<string>::iterator i = myEntryVector.begin(); i != myEntryVector.end(); i++){
			stream << *i << " ";
		}
		stream << '\n';
	} else {
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	}
	stream.close();
	return SUCCESS;
}


