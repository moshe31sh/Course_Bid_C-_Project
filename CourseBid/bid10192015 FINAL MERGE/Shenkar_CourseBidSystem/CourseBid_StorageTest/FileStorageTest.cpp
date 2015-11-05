/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** CourseBid_Storage Unit Tests
** File Storage Class Tests
**
** Author: Yossi Gleyzer
** -------------------------------------------------------------------------*/

#include "stdafx.h"
#include "CppUnitTest.h"
#include "DBEventLog.h"
#include "FileStorage.h"
#include "IdObj.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CourseBid_StorageTest
{		
	/*
	* FileStorage Test Class
	*/
	TEST_CLASS(FileStorageTest)
	{
	public:
		
		TEST_METHOD(getNumberFromStringByTagTest)
		{
			//Arrange
			class MockStorage : public IStorage {
			private:
				vector<long> vecLong;
				vector<string> vecString;
			public:
				MockStorage() {}
				virtual long getNumberFromStringByTag(string str, string tag) { return 0; }
				virtual string getStringFromStringByTag(string str, string tag) { return NULL; }
				virtual vector<long> getInnerNumbersByTag(string str, string tag) { return vecLong; }
				virtual vector<string> getAll(long serial) { return vecString; }
				virtual void save(string line = "") { }
				virtual void deleteObj(long serial, long id) { }
				virtual long generateId(long serial) { return 0; }
			};
			
			class MockObject : public IdObj {
			private:
				long number;
			public:
				const int SERIAL = 10;
				const string TAG_NUMBER = "number";
				long getNumber() { return number; }
				void setNumber(long num) { number = num; }
				MockObject(long mockId, IStorage * mockStorage) : IdObj(mockId, mockStorage) { }
				virtual void save(bool recursive) { }
				virtual void deleteMe() { }
				string toString()
				{
					string mockString = string("<" + FileStorage::TAG_OBJ + ">");
					mockString += string("<" + FileStorage::TAG_SERIAL + "=\"" + static_cast<ostringstream*>(&(ostringstream() << SERIAL))->str() + "\">");
					mockString += string("<" + FileStorage::TAG_ID + "=\"" + static_cast<ostringstream*>(&(ostringstream() << id))->str() + "\">");
					mockString += string("<" + this->TAG_NUMBER + "=\"" + static_cast<ostringstream*>(&(ostringstream() << number))->str() + "\">");
					mockString += string("<\\" + FileStorage::TAG_OBJ + ">");
					return mockString;
				}
			};

			long value = 123;
			long mockId = 10;
			string mockFileName = ".";
			MockStorage * mockStorage = new MockStorage();
			MockObject * mockObject = new MockObject(mockId, mockStorage);
			mockObject->setNumber(value);
			string mockObjectAsString = mockObject->toString();
			vector<string> buffer;
			buffer.push_back(mockObjectAsString);
			
			//act
			FileStorage * fileStorage = new FileStorage(buffer, mockFileName);
			long expectedValue = fileStorage->getNumberFromStringByTag(mockObjectAsString, mockObject->TAG_NUMBER);

			//assert
			Assert::AreEqual(value, expectedValue);
			delete mockStorage;
			delete mockObject;
			delete fileStorage;
		}

		TEST_METHOD(getStringFromStringByTagTest)
		{
			//Arrange
			class MockStorage : public IStorage {
			private:
				vector<long> vecLong;
				vector<string> vecString;
			public:
				MockStorage() {}
				virtual long getNumberFromStringByTag(string str, string tag) { return 0; }
				virtual string getStringFromStringByTag(string str, string tag) { return NULL; }
				virtual vector<long> getInnerNumbersByTag(string str, string tag) { return vecLong; }
				virtual vector<string> getAll(long serial) { return vecString; }
				virtual void save(string line = "") { }
				virtual void deleteObj(long serial, long id) { }
				virtual long generateId(long serial) { return 0; }
			};

			class MockObject : public IdObj {
			private:
				string str;
			public:
				const int SERIAL = 10;
				const string TAG_STRING = "string";
				string getString() { return str; }
				void setString(string s) { str = s; }
				MockObject(long mockId, IStorage * mockStorage) : IdObj(mockId, mockStorage) { }
				virtual void save(bool recursive) { }
				virtual void deleteMe() { }
				string toString()
				{
					string mockString = string("<" + FileStorage::TAG_OBJ + ">");
					mockString += string("<" + FileStorage::TAG_SERIAL + "=\"" + static_cast<ostringstream*>(&(ostringstream() << SERIAL))->str() + "\">");
					mockString += string("<" + FileStorage::TAG_ID + "=\"" + static_cast<ostringstream*>(&(ostringstream() << id))->str() + "\">");
					mockString += string("<" + this->TAG_STRING + "=\"" + str + "\">");
					mockString += string("<\\" + FileStorage::TAG_OBJ + ">");
					return mockString;
				}
			};

			string value = "Hello world!";
			long mockId = 10;
			string mockFileName = ".";
			MockStorage * mockStorage = new MockStorage();
			MockObject * mockObject = new MockObject(mockId, mockStorage);
			mockObject->setString(value);
			string mockObjectAsString = mockObject->toString();
			vector<string> buffer;
			buffer.push_back(mockObjectAsString);

			//act
			FileStorage * fileStorage = new FileStorage(buffer, mockFileName);
			string expectedValue = fileStorage->getStringFromStringByTag(mockObjectAsString, mockObject->TAG_STRING);

			//assert
			Assert::AreEqual(value, expectedValue);
			delete mockStorage;
			delete mockObject;
			delete fileStorage;
		}

		TEST_METHOD(getInnerNumbersByTagTest)
		{
			//Arrange
			class MockStorage : public IStorage {
			private:
				vector<long> vecLong;
				vector<string> vecString;
			public:
				MockStorage() {}
				virtual long getNumberFromStringByTag(string str, string tag) { return 0; }
				virtual string getStringFromStringByTag(string str, string tag) { return NULL; }
				virtual vector<long> getInnerNumbersByTag(string str, string tag) { return vecLong; }
				virtual vector<string> getAll(long serial) { return vecString; }
				virtual void save(string line = "") { }
				virtual void deleteObj(long serial, long id) { }
				virtual long generateId(long serial) { return 0; }
			};

			class MockObject : public IdObj {
			private:
				vector<long> vec;
			public:
				const int SERIAL = 10;
				const string TAG_STRING = "string";
				vector<long> getVector() { return vec; }
				void setVector(vector<long> v) { vec = v; }
				MockObject(long mockId, IStorage * mockStorage) : IdObj(mockId, mockStorage) { }
				virtual void save(bool recursive) { }
				virtual void deleteMe() { }
				string toString()
				{
					string mockString = string("<" + FileStorage::TAG_OBJ + ">");
					mockString += string("<" + FileStorage::TAG_SERIAL + "=\"" + static_cast<ostringstream*>(&(ostringstream() << SERIAL))->str() + "\">");
					mockString += string("<" + FileStorage::TAG_ID + "=\"" + static_cast<ostringstream*>(&(ostringstream() << id))->str() + "\">");
					mockString += string("<" + this->TAG_STRING + ">");
					for each (long var in vec)
					{
						mockString += string("<" + FileStorage::TAG_ID + "=\"" + static_cast<ostringstream*>(&(ostringstream() << var))->str() + "\">");
					}
					mockString += string("<\\" + this->TAG_STRING + ">");
					mockString += string("<\\" + FileStorage::TAG_OBJ + ">");
					return mockString;
				}
			};

			long first = 123;
			long second = 234;
			long third = 345;

			bool contains[3];
			for (int i = 0; i < 3; i++) {
				contains[i] = false;
			}

			vector<long> value;
			value.push_back(first);
			value.push_back(second);
			value.push_back(third);

			long mockId = 10;
			string mockFileName = ".";
			MockStorage * mockStorage = new MockStorage();
			MockObject * mockObject = new MockObject(mockId, mockStorage);
			mockObject->setVector(value);
			string mockObjectAsString = mockObject->toString();
			vector<string> buffer;
			buffer.push_back(mockObjectAsString);

			//act
			FileStorage * fileStorage = new FileStorage(buffer, mockFileName);
			vector<long> expectedValue = fileStorage->getInnerNumbersByTag(mockObjectAsString, mockObject->TAG_STRING);

			//assert
			for each (long var in expectedValue)
			{
				if (var == first) contains[0] = true;
				if (var == second) contains[1] = true;
				if (var == third) contains[2] = true;
			}
			for (int i = 0; i < 3; i++) {
				Assert::IsTrue(contains[i]);
			}
			delete mockStorage;
			delete mockObject;
			delete fileStorage;
		}

		TEST_METHOD(getAllTest)
		{
			//Arrange
			class MockStorage : public IStorage {
			private:
				vector<long> vecLong;
				vector<string> vecString;
			public:
				MockStorage() {}
				virtual long getNumberFromStringByTag(string str, string tag) { return 0; }
				virtual string getStringFromStringByTag(string str, string tag) { return NULL; }
				virtual vector<long> getInnerNumbersByTag(string str, string tag) { return vecLong; }
				virtual vector<string> getAll(long serial) { return vecString; }
				virtual void save(string line = "") { }
				virtual void deleteObj(long serial, long id) { }
				virtual long generateId(long serial) { return 0; }
			};

			class MockObject : public IdObj {
			private:
				long number;
			public:
				const int SERIAL = 10;
				const string TAG_NUMBER = "number";
				long getNumber() { return number; }
				void setNumber(long num) { number = num; }
				MockObject(long mockId, IStorage * mockStorage) : IdObj(mockId, mockStorage) { }
				virtual void save(bool recursive) { }
				virtual void deleteMe() { }
				string toString()
				{
					string mockString = string("<" + FileStorage::TAG_OBJ + ">");
					mockString += string("<" + FileStorage::TAG_SERIAL + "=\"" + static_cast<ostringstream*>(&(ostringstream() << SERIAL))->str() + "\">");
					mockString += string("<" + FileStorage::TAG_ID + "=\"" + static_cast<ostringstream*>(&(ostringstream() << id))->str() + "\">");
					mockString += string("<" + this->TAG_NUMBER + "=\"" + static_cast<ostringstream*>(&(ostringstream() << number))->str() + "\">");
					mockString += string("<\\" + FileStorage::TAG_OBJ + ">");
					return mockString;
				}
			};

			long innerVal = 123;
			long mockId = 10;
			string mockFileName = ".";
			MockStorage * mockStorage = new MockStorage();
			MockObject * mockObject = new MockObject(mockId, mockStorage);
			mockObject->setNumber(innerVal);
			string mockObjectAsString = mockObject->toString();
			vector<string> buffer;
			buffer.push_back(mockObjectAsString);

			//act
			FileStorage * fileStorage = new FileStorage(buffer, mockFileName);
			vector<string> allObjects = fileStorage->getAll(mockObject->SERIAL);

			string expectedValue = allObjects[0];
			string value = buffer[0];
			//assert
			Assert::AreEqual(value, expectedValue);
			delete mockStorage;
			delete mockObject;
			delete fileStorage;
		}

		TEST_METHOD(deleteObjTest)
		{
			//Arrange
			class MockStorage : public IStorage {
			private:
				vector<long> vecLong;
				vector<string> vecString;
			public:
				MockStorage() {}
				virtual long getNumberFromStringByTag(string str, string tag) { return 0; }
				virtual string getStringFromStringByTag(string str, string tag) { return NULL; }
				virtual vector<long> getInnerNumbersByTag(string str, string tag) { return vecLong; }
				virtual vector<string> getAll(long serial) { return vecString; }
				virtual void save(string line = "") { }
				virtual void deleteObj(long serial, long id) { }
				virtual long generateId(long serial) { return 0; }
			};

			class MockObject : public IdObj {
			private:
				long number;
			public:
				const int SERIAL = 10;
				const string TAG_NUMBER = "number";
				long getNumber() { return number; }
				void setNumber(long num) { number = num; }
				MockObject(long mockId, IStorage * mockStorage) : IdObj(mockId, mockStorage) { }
				virtual void save(bool recursive) { }
				virtual void deleteMe() { }
				string toString()
				{
					string mockString = string("<" + FileStorage::TAG_OBJ + ">");
					mockString += string("<" + FileStorage::TAG_SERIAL + "=\"" + static_cast<ostringstream*>(&(ostringstream() << SERIAL))->str() + "\">");
					mockString += string("<" + FileStorage::TAG_ID + "=\"" + static_cast<ostringstream*>(&(ostringstream() << id))->str() + "\">");
					mockString += string("<" + this->TAG_NUMBER + "=\"" + static_cast<ostringstream*>(&(ostringstream() << number))->str() + "\">");
					mockString += string("<\\" + FileStorage::TAG_OBJ + ">");
					return mockString;
				}
			};

			long innerVal = 123;
			long mockId = 10;
			string mockFileName = ".";
			MockStorage * mockStorage = new MockStorage();
			MockObject * mockObject = new MockObject(mockId, mockStorage);
			mockObject->setNumber(innerVal);
			string mockObjectAsString = mockObject->toString();
			vector<string> buffer;
			buffer.push_back(mockObjectAsString);

			//act
			FileStorage * fileStorage = new FileStorage(buffer, mockFileName);
			fileStorage->deleteObj(mockObject->SERIAL, mockObject->getId());

			vector<string> allObjects = fileStorage->getAll(mockObject->SERIAL);
			
			//assert
			Assert::IsTrue(allObjects.empty());
			delete mockStorage;
			delete mockObject;
			delete fileStorage;
		}

		TEST_METHOD(generateIdTest)
		{
			//Arrange
			class MockStorage : public IStorage {
			private:
				vector<long> vecLong;
				vector<string> vecString;
			public:
				MockStorage() {}
				virtual long getNumberFromStringByTag(string str, string tag) { return 0; }
				virtual string getStringFromStringByTag(string str, string tag) { return NULL; }
				virtual vector<long> getInnerNumbersByTag(string str, string tag) { return vecLong; }
				virtual vector<string> getAll(long serial) { return vecString; }
				virtual void save(string line = "") { }
				virtual void deleteObj(long serial, long id) { }
				virtual long generateId(long serial) { return 0; }
			};

			class MockObject : public IdObj {
			private:
				long number;
			public:
				const int SERIAL = 10;
				const string TAG_NUMBER = "number";
				long getNumber() { return number; }
				void setNumber(long num) { number = num; }
				MockObject(long mockId, IStorage * mockStorage) : IdObj(mockId, mockStorage) { }
				virtual void save(bool recursive) { }
				virtual void deleteMe() { }
				string toString()
				{
					string mockString = string("<" + FileStorage::TAG_OBJ + ">");
					mockString += string("<" + FileStorage::TAG_SERIAL + "=\"" + static_cast<ostringstream*>(&(ostringstream() << SERIAL))->str() + "\">");
					mockString += string("<" + FileStorage::TAG_ID + "=\"" + static_cast<ostringstream*>(&(ostringstream() << id))->str() + "\">");
					mockString += string("<" + this->TAG_NUMBER + "=\"" + static_cast<ostringstream*>(&(ostringstream() << number))->str() + "\">");
					mockString += string("<\\" + FileStorage::TAG_OBJ + ">");
					return mockString;
				}
			};

			string mockFileName = ".";
			MockStorage * mockStorage = new MockStorage();

			long mockIdFirst = 10;
			MockObject * mockObjectFirst = new MockObject(mockIdFirst, mockStorage);

			long mockIdSecond = 1;
			MockObject * mockObjectSecond = new MockObject(mockIdSecond, mockStorage);

			long mockIdThird = 2;
			MockObject * mockObjectThird = new MockObject(mockIdThird, mockStorage);

			string mockObjectAsStringFirst = mockObjectFirst->toString();
			string mockObjectAsStringSecond = mockObjectSecond->toString();
			string mockObjectAsStringThird = mockObjectThird->toString();
			vector<string> buffer;
			buffer.push_back(mockObjectAsStringFirst);
			buffer.push_back(mockObjectAsStringSecond);
			buffer.push_back(mockObjectAsStringThird);

			//act
			FileStorage * fileStorage = new FileStorage(buffer, mockFileName);
			long val = fileStorage->generateId(mockObjectFirst->SERIAL);

			//assert
			Assert::AreNotEqual(val, mockIdFirst);
			Assert::AreNotEqual(val, mockIdSecond);
			Assert::AreNotEqual(val, mockIdThird);
			delete mockStorage;
			delete mockObjectFirst;
			delete mockObjectSecond;
			delete mockObjectThird;
			delete fileStorage;
		}
	};
}