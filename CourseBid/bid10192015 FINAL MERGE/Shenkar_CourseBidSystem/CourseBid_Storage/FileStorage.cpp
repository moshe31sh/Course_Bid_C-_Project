/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** FileStorage.cpp
** FileStorage using XML implementing IStorage interface implementation.
**
** Author: Yossi Gleyzer
** -------------------------------------------------------------------------*/
#include "FileStorage.h"
#include <fstream>
#include <sstream>
#include <sys/stat.h>

const long IStorage::VALUE_NOT_EXISTS = -2;
const long IStorage::KEY_NOT_EXISTS = -1;
const string IStorage::TAG_SERIAL = string("serial");
const string IStorage::TAG_ID = string("id");
const string IStorage::TAG_OBJ = string("idobj");

/*
** Constructor: creates File Storage DB if not exists or reads memory to buffer.
*/
FileStorage::FileStorage()
{
	string logCategory = "FileStorage";
	ifstream file(filename.c_str());
	if (file.good()) {
		DBEventLog::debug("Storage exists. Loading from file...", logCategory);
		//read from file to memory
		string line;
		while (getline(file, line))
		{
			buffer.push_back(line);
		}
		DBEventLog::debug("Storage loaded to memory.", logCategory);
		file.close();
	}
	else
	{
		file.close();
		DBEventLog::debug("No DB exists. Creating DB file.", logCategory);
		ofstream output;
		output.open(filename);
		output.close();
		DBEventLog::debug("DB file created.", logCategory);
	}

}

/*
** Returns all objects of given class serial as string.
*/
vector<string> FileStorage::getAll(long serial)
{
	string logCategory = "getAll";

	DBEventLog::debug("Getting all objects by serial [" + to_string(serial) + "].", logCategory);
	vector<string> result;
	for each (string line in buffer)
	{
		if (serial == getNumberFromStringByTag(line, TAG_SERIAL))
		{
			result.push_back(line);
		}
	}
	DBEventLog::debug("Number of objects by serial [" + to_string(serial) + "] is [" + to_string(result.size()) + "]", logCategory);
	
	return result;
}


/*
** Public function:	Stores memory in DB.
** 					If given line == "" not changing before saving
** 					Else searching for serial and id all memory
** 						if exists => overriding line
** 						else  => adding line
** Throws: exception : new line does not contain serial or ID
** To see how to build a string please see: IStorage::save(string line)
*/
void FileStorage::save(string line)
{
	string logCategory = "save";
	DBEventLog::debug("Saving DB!", logCategory);
	if (line != "")
	{
		DBEventLog::debug("Saving record: [" + line + "]", logCategory);
		bool recordFound = false;	//flag if record already exists
		long existingLineSerial;	//existing record serial
		long existingLineId;		//existing record ID

		long newLineSerial = getNumberFromStringByTag(line, TAG_SERIAL);	//exclude new line serial
		long newLineId = getNumberFromStringByTag(line, TAG_ID);			//exclude new line ID
		DBEventLog::debug("New record id [" + to_string(newLineId) + "] and serial [" + to_string(newLineSerial) + "]", logCategory);
		if ((newLineSerial < 0) || (newLineId < 0)) throw new exception();	//wrong line added - no ID or serial

		int lineNumber = 0;
		for (lineNumber; lineNumber < (int)buffer.size(); lineNumber++) //iterate thrue all lines
		{
			existingLineSerial = getNumberFromStringByTag(buffer[lineNumber], TAG_SERIAL);	//exclude existing line serial
			existingLineId = getNumberFromStringByTag(buffer[lineNumber], TAG_ID);			//exclude existing line ID
			
			//if same id and serial => record already exists
			if ((existingLineSerial == newLineSerial) && (existingLineId == newLineId)) 
			{
				DBEventLog::debug("Record already exists [" + buffer[lineNumber] + "]", logCategory);
				recordFound = true;
				break;
			}
		}

		//remove existing record from memory if already exists
		if (recordFound)
		{
			buffer.erase(buffer.begin() + lineNumber);
			DBEventLog::debug("Old record removed.", logCategory);
		}

		//add new record
		buffer.push_back(line);
		DBEventLog::debug("New record added.", logCategory);
	}

	//OPEN DB and STORE Line By Line
	DBEventLog::debug("Saving memory to file [" + filename + "]...", logCategory);
	ofstream output;
	output.open(filename);
	for each(string obj in buffer)
	{
		output << obj << endl;
	}
	output.close();
	DBEventLog::debug("Memory saved to file [" + filename + "].", logCategory);
}

/*
** This  function will delete the record with given class serial and id if such line found in DB
**  NOTE: Change will take place in DB only after save()
*/
void FileStorage::deleteObj(long serial, long id)
{
	string logCategory = "deleteObj";

	long existingId;
	long existingSerial;
	bool recordFound = false;

	int lineNumber = 0;
	for (lineNumber; lineNumber < (int)buffer.size(); lineNumber++) //iterate thrue all lines
	{
		existingSerial = getNumberFromStringByTag(buffer[lineNumber], TAG_SERIAL);
		existingId = getNumberFromStringByTag(buffer[lineNumber], TAG_ID);
		if ((serial == existingSerial) && (id == existingId))
		{
			DBEventLog::debug("Record to delete with serial [" + to_string(serial) + "] and id [" + to_string(id) + "] found [" + buffer[lineNumber] + "]", logCategory);
			recordFound = true;
			buffer.erase(buffer.begin() + lineNumber);
			DBEventLog::debug("Record deleted! NOTE: This action will not take affect on DB.xml till saved, only buffer!!!", logCategory);
			break;
		}
	}
	if (!recordFound)
	{
		DBEventLog::warning("Record with serial [" + to_string(serial) + "] and id [" + to_string(id) + "] not found in DB. This might mean an error or the item was not saved in DB.", logCategory);
	}
}

/*
** This function will return minimal unique id>0 for given class.
*/
long FileStorage::generateId(long serial)
{
	string logCategory = "generateId";
	DBEventLog::debug("Generating ID for serial [" + to_string(serial) + "].", logCategory);

	long generatedId = 0;
	bool idExists = true;
	while (idExists)
	{
		generatedId++;
		idExists = false; 
		for each (string line in buffer)
		{
			if (serial == getNumberFromStringByTag(line, TAG_SERIAL))
			{
				if (generatedId == getNumberFromStringByTag(line, TAG_ID))
				{
					idExists = true;
					continue;
				}
			}
		}
	}
	DBEventLog::debug("Generated ID for serial [" + to_string(serial) + "] is [" + to_string(generatedId) + "].", logCategory);
	return generatedId;
}


/*
** Returns long value by tag (key) in given line
*/
long FileStorage::getNumberFromStringByTag(string str, string tag)
{
	long result = KEY_NOT_EXISTS;
	size_t bracketsLength = 3;							//length of '<', '=' and '"'
	size_t tagBeginPos = str.find("<" + tag + "=\"");	//tag beggining position

	if (string::npos != tagBeginPos)					//if KEY exists
	{
		result = VALUE_NOT_EXISTS;
		size_t valueBeginPos = tagBeginPos + tag.length() + bracketsLength;	//begin of value after tag
		size_t valueLength = str.substr(valueBeginPos).find("\"");			//end of value by '"'
		if (((size_t)string::npos != valueBeginPos) && ((size_t)string::npos != valueLength)) //if VALUE exists
		{
			istringstream(str.substr(valueBeginPos, valueLength)) >> result;
		}
	}
	return result;
}


/*
** Returns string value by tag (key) in given line
*/
string FileStorage::getStringFromStringByTag(string str, string tag)
{
	string result = to_string(KEY_NOT_EXISTS);
	size_t bracketsLength = 3;							//length of '<', '=' and '"'
	size_t tagBeginPos = str.find("<" + tag + "=\"");	//tag beggining position

	if (string::npos != tagBeginPos)					//if KEY exists
	{
		result = to_string(VALUE_NOT_EXISTS);
		size_t valueBeginPos = tagBeginPos + tag.length() + bracketsLength;	//begin of value after tag
		size_t valueLength = str.substr(valueBeginPos).find("\"");			//end of value by '"'
		if (((size_t)string::npos != valueBeginPos) && ((size_t)string::npos != valueLength)) //if VALUE exists
		{
			result = str.substr(valueBeginPos, valueLength);
		}
	}
	return result;
}

vector<long> FileStorage::getInnerNumbersByTag(string str, string tag)
{
	string result = to_string(KEY_NOT_EXISTS);
	size_t bracketsLength = 2;							//length of '<', '=' and '"'
	size_t tagBeginPos = str.find("<" + tag + ">");		//tag beggining position

	if (string::npos != tagBeginPos)					//if KEY exists
	{
		result = to_string(VALUE_NOT_EXISTS);
		size_t valueBeginPos = tagBeginPos + tag.length() + bracketsLength;	//begin of value after tag
		size_t valueLength = str.substr(valueBeginPos).find("<\\" + tag + ">");			//end of value by '"'
		if (((size_t)string::npos != valueBeginPos) && ((size_t)string::npos != valueLength)) //if VALUE exists
		{
			result = str.substr(valueBeginPos, valueLength);
		}
	}

	//string within brackets : result ex : <id = "1"><id = "2">
	vector<long> results;

	long currentResult = 0;
	while (currentResult != KEY_NOT_EXISTS)
	{
		currentResult = KEY_NOT_EXISTS;
		bracketsLength = 3;
		tagBeginPos = result.find("<" + TAG_ID + "=\"");
		
		if (string::npos != tagBeginPos)					//if KEY exists
		{
			currentResult = VALUE_NOT_EXISTS;
			size_t valueBeginPos = tagBeginPos + TAG_ID.length() + bracketsLength;	//begin of value after tag
			size_t valueLength = result.substr(valueBeginPos).find("\"");			//end of value by '"'
			if (((size_t)string::npos != valueBeginPos) && ((size_t)string::npos != valueLength)) //if VALUE exists
			{
				istringstream(result.substr(valueBeginPos, valueLength)) >> currentResult;
				results.push_back(currentResult);
				result = result.substr(valueBeginPos + valueLength);
			}
		}
		
	}

	return results;
}