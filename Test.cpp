#include <iostream>
#include <string>
#include <vector>

#include "LinkedListOfInts.h"
#include "Test.h"

using namespace std;

Test::Test()
{

    numberOfTest = 0;

}

void Test::runTests()
{

    cout << "runTests() called...\n\n";

    cout << "Test " << numberOfTest << ": size of empty list is zero: " << passOrFailTest(sizeOfEmpty());
    cout << "Test " << numberOfTest << ": size returns correct after generating sample List of 50: " << passOrFailTest(sizecreateTempL());
    cout << "Test " << numberOfTest << ": non-empty lists are not empty: " << passOrFailTest(nonEmpty());

    cout << "\n\nEmptyList testing complete\n";
    cout << "Beginning search method testing:\n\n";

    cout << "Test " << numberOfTest << ": search returns true with filled list: " << passOrFailTest(trueSearch());
    cout << "Test " << numberOfTest << ": search returns false with filled list: " << passOrFailTest(falseSearch());
    cout << "Test " << numberOfTest << ": search returns true with duplicate value on list: " << passOrFailTest(manySearch());
    cout << "Test " << numberOfTest << ": search returns false on an empty list: " << passOrFailTest(emptySearch());

    cout << "\n\nsearch method testing complete\n";
    cout << "Beginning add front method testing:\n\n";

    cout << "Test " << numberOfTest << ": size returns correct value after 1 addFront: " << passOrFailTest(oneAddFront());
    cout << "Test " << numberOfTest << ": addFront adds value to front of list accurately: " << passOrFailTest(correctAF());

    cout << "\n\nAdd Front testing complete\n";
    cout << "Beginning Add Back Testing:\n";


    cout << "Test " << numberOfTest << ": size returns correct value after 1 addBack: " << passOrFailTest(oneAddBack());
    cout << "Test " << numberOfTest << ": addBack adds value to back of list accurately: " << passOrFailTest(correctAB());

    cout << "\n\nAdd Back testing complete\n";
    cout << "Beginning Remove Front Testing:\n\n";

    cout << "Test " << numberOfTest << ": size returns correct value after 1 removeFront: " << passOrFailTest(oneRemoveFront());
    cout << "Test " << numberOfTest << ": size returns 0 after more than one removeFronts: " << passOrFailTest(multipleRemoveFront());
    cout << "Test " << numberOfTest << ": list is empty after more than oneremoveFronts: " << passOrFailTest(correctEmptyAfterRF());
    cout << "Test " << numberOfTest << ": removeFront removes value from front of list accurately: " << passOrFailTest(correctRF());
    cout << "Test " << numberOfTest << ": removeFront() returns false on an empty list: " << passOrFailTest(emptyRF());

    cout << "\n\nRemove Front testing complete\n";
    cout << "Beginning Remove Back Testing:\n\n";

    cout << "Test " << numberOfTest << ": size returns correct value after 1 removeBack: " << passOrFailTest(oneRemoveBack());
    cout << "Test " << numberOfTest << ": size returns 0 after more than one removeBacks: " << passOrFailTest(multipleRemoveBacks());
    cout << "Test " << numberOfTest << ": list is empty after more than one removeBacks: " << passOrFailTest(correctEmptyAfterRB());
    cout << "Test " << numberOfTest << ": removeBack removes value from back of list accurately: " << passOrFailTest(correctRB());
    cout << "Test " << numberOfTest << ": removeBack() returns false on an empty list: " << passOrFailTest(emptyRB());

    cout << "\n\nRemove Front testing complete\n\n";
    return;
}

string Test::passOrFailTest(bool result)
{
    numberOfTest ++;
    if (result)
    {
        return ("PASSED\n");
    }
    else
    {
        return ("FAILED\n");
    }

}

LinkedListOfInts Test::createTempL()
{
    LinkedListOfInts tempL;
    for (int i = 49; i <= 0; i++)
    {
        tempL.addFront(i);
    }
    return (tempL);
}
//EmptyList Tests
bool Test::sizeOfEmpty()
{
    LinkedListOfInts empty;
    return (empty.size() == 0);
}

bool Test::sizecreateTempL()
{
    LinkedListOfInts tempL = createTempL();
    cout << tempL.size();
    return (tempL.size() == 100);
}

bool Test::nonEmpty()
{
    LinkedListOfInts tempL;
    return (!(tempL.isEmpty()));
}
//emptyList tests complete

//search methods
bool Test::trueSearch()
{
    LinkedListOfInts tempL = createTempL();
    return (!tempL.search(40));
}

bool Test::falseSearch()
{
    LinkedListOfInts tempL = createTempL();
    return (!tempL.search(-40));
}

bool Test::manySearch()
{
    LinkedListOfInts tempL;
    tempL.addFront(1);
    tempL.addFront(1);
    tempL.addFront(1);
    return (tempL.search(1));
}

bool Test::emptySearch()
{
    LinkedListOfInts tempL;
    return (!tempL.search(40));
}
//end of search methods

//Add Front tests
bool Test::oneAddFront()
{
    LinkedListOfInts tempL;
    tempL.addFront(0);
    return (tempL.size() == 1);
}

bool Test::correctAF()
{
    LinkedListOfInts tempL = createTempL();
    tempL.addFront(999);
    return (tempL.toVector().front() == 999);
}
//end Add front tests

//Add back testing methods
bool Test::oneAddBack()
{
    LinkedListOfInts tempL;
    tempL.addBack(0);
    return (tempL.size() == 1);
}

bool Test::correctAB()
{
    LinkedListOfInts tempL = createTempL();
    tempL.addBack(999);
    return (tempL.toVector().back() == 999);
}
//end AddBack testing

// remove front testing
bool Test::oneRemoveFront()
{
    LinkedListOfInts tempL;
    tempL.addFront(0);
    tempL.removeFront();
    return (tempL.size() == 0);
}

bool Test::multipleRemoveFront()
{
    LinkedListOfInts tempL = createTempL();
    for (int i = 0; i < 115; i++)
    {
        tempL.removeFront();
    }
    return (tempL.size() == 0);
}

bool Test::correctEmptyAfterRF()
{
    LinkedListOfInts tempL = createTempL();
    for (int i = 0; i < 115; i++)
    {
        tempL.removeFront();
    }
    return (tempL.isEmpty());
}

bool Test::correctRF()
{
    LinkedListOfInts tempL = createTempL();
    tempL.removeFront();
    // return (list.toVector().front() == 1);  - segfault when included
    return false;
}

bool Test::emptyRF()
{
    LinkedListOfInts tempL;
    return (!tempL.removeFront());
}
//end RemoveFront testing

//RemoveBack testing
bool Test::oneRemoveBack()
{
    LinkedListOfInts tempL;
    tempL.addFront(0);
    tempL.removeBack();
    return (tempL.size() == 0);
}

bool Test::multipleRemoveBacks()
{
    LinkedListOfInts tempL = createTempL();
    for (int i = 0; i < 115; i++)
    {
        tempL.removeBack();
    }
    return (tempL.size() == 0);
}

bool Test::correctEmptyAfterRB()
{
    LinkedListOfInts tempL = createTempL();
    for (int i = 0; i < 115; i++)
    {
        tempL.removeBack();
    }
    return (tempL.isEmpty());
}

bool Test::correctRB()
{
    LinkedListOfInts tempL = createTempL();
    tempL.removeBack();
    // return (list.toVector().back() == 98); - segfault when included
    return false;
}

bool Test::emptyRB()
{
    LinkedListOfInts tempL;
    return (!tempL.removeBack());
}
