/**
*	@file Test.h
*	@author Megana Chinalachaiagari
*	@date April 22, 2019
*	@brief header file for Test Class
*/

#ifndef TEST_H
#define TEST_H

#include <string>

#include "LinkedListOfInts.h"

using namespace std;

class Test
{
    public:
        Test();
        void runTests();

    private:
        int numberOfTest;
        string passOrFailTest(bool result);

        LinkedListOfInts createTempL();
      //emptyList Tests
        bool sizeOfEmpty();
        bool sizecreateTempL();
        bool nonEmpty();
      //Search methods
        bool trueSearch();
        bool falseSearch();
        bool manySearch();
        bool emptySearch();
      // Add Front tests
        bool oneAddFront();
        bool correctAF();
      // Add Back testing
        bool oneAddBack();
        bool correctAB();
      // Remove Front testing
        bool oneRemoveFront();
        bool multipleRemoveFront();
        bool correctEmptyAfterRF();
        bool correctRF();
        bool emptyRF();
      // Remove back testing
        bool oneRemoveBack();
        bool multipleRemoveBacks();
        bool correctEmptyAfterRB();
        bool correctRB();
        bool emptyRB();









};
#endif
