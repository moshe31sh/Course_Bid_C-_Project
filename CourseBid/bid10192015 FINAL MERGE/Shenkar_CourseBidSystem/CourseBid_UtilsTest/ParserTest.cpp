/* ---------------------------------------------------------------------------
** This software is Shenkar College for Engineering and Design final submission
** for course "Tools of Software Engineering".
** Authors: <Ohad Sasson, Moshe Shimon, Yaron Israeli, Maor Toubian, Yossi Gleyzer>
**
** CourseBid_Utils Unit Tests
** Parser Class Tests
**
** Author: Yossi Gleyzer
** -------------------------------------------------------------------------*/

#include "stdafx.h"
#include "CppUnitTest.h"
#include "Lexer.h"
#include "Token.h"
#include "Parser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CourseBid_UtilsTest
{		
	/*
	* Parser Class Test
	*/
	TEST_CLASS(ParserTest)
	{

	public:
		TEST_METHOD(getResultTestPositive)
		{
			//Arrange
			const string mockExpression = "100+2*@";
			const int mockNumber = 6;
			double expectedResult = 112;
			Parser parser = Parser();
			parser.parse(mockExpression, mockNumber);
			//Act
			bool error = parser.isError();
			double actualResult = parser.getResult();
			//Assert
			Assert::AreEqual(error, false);
			Assert::AreEqual(expectedResult, actualResult);
		}


		TEST_METHOD(isErrorTestNegative)
		{
			//Arrange
			const string mockExpression = "hello";
			const int mockNumber = 6;
			//Act
			Parser parser = Parser();
			parser.parse(mockExpression, mockNumber);
			bool error = parser.isError();
			//Assert
			Assert::AreEqual(error, true);
		}

	};
}