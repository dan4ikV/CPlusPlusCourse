// Homework5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CMySmartPointer.h"
#include "CTab.h"
#include "CTable.h"

using namespace std;

static string staticVar = "temp";

template <typename T> void testDeletion(CMySmartPointer<T> x) { //argument here for the sake of seing it's destructor called at the end of the function
    //simple test
    CMySmartPointer<int> pointer(new int(30));
    cout << *pointer << endl;

    //using copy constructor and operator =
    CMySmartPointer<int> pointer2(new int(40));
    CMySmartPointer<int> pointer3 = pointer2;
    pointer=pointer2;
    cout << *pointer2 << endl;
    cout << *pointer3 << endl;
    cout << *pointer << endl;
}

int main()
{
    CMySmartPointer<int> pointer1(new int(10));
    cout << *pointer1 << endl;
    CMySmartPointer<int> pointer2(new int(20));
    CMySmartPointer<int> pointer3 = pointer2;
    cout << *pointer2 << endl;
    cout << *pointer3 << endl;
    testDeletion(pointer1);
    string* staticPointer = &staticVar;
    //CMySmartPointer<string> staticSmartPointer(staticPointer);
    CTab c_tab;
    CTab c_other;
    /*initialize c_tab, c_other*/
    c_tab = std::move(c_other);

    //task5 with cTable
    CTable c_tab_0, c_tab_1;
    c_tab_0.bSetNewSize(6);
    c_tab_1.bSetNewSize(4);
    //    c_tab_0 = c_tab_1;
        //the error here appears because at the end of the program when cleaning memory the allready free memory
        //is being cleaned again, as both c_tab_0, and c_tab_1 are pointing to the same memory address

    c_tab_0.vPrint();
    c_tab_0.setValueAt(5, 10);
    c_tab_0.vPrint();
    c_tab_0 = std::move(c_tab_1);
    c_tab_0.vPrint();
    --c_tab_0;
    c_tab_1.bSetNewSize(4);
    CTable c_tab_3 = c_tab_0 + c_tab_1;
//    c_tab_0.vPrint();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
