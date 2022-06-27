#include <iostream>

using namespace std;

//task1
void v_alloc_table_add_5(int iSize) {
    if (iSize > 0) {
        int* pointer = new int[iSize];
        int* pointer2 = new int[iSize];
        for (int i = 0; i < iSize; i++) {
            pointer[i] = i + 5;
            pointer2[i] = iSize - i + 4;
        }
        for (int i = 0; i < iSize; i++) {
            cout << pointer[i];
            if (i < iSize - 1) {
                cout << ", ";
            }
        }
        cout << endl;
        for (int i = 0; i < iSize; i++) {
            cout << pointer2[i];
            if (i < iSize - 1) {
                cout << ", ";
            }
        }
        cout << endl;
        delete[] pointer;
        delete[] pointer2;
    }
    else {
        cout << "Improper array size";
    }
}

void v_alloc_table_add_5_2(int iSize) {
    if (iSize > 0) {
        int* pointer = new int[iSize];
        for (int i = 0; i < iSize; i++) {
            pointer[i] = iSize - i + 4;
        }
        for (int i = 0; i < iSize; i++) {
            cout << pointer[i];
            if (i < iSize - 1) {
                cout << ", ";
            }
        }
        cout << endl;
        delete[] pointer;
    }
    else {
        cout << "Improper array size";
    }
}

//task2
bool b_alloc_table_2_dim(int**& piTable, int iSizeX, int iSizeY) {
    if (iSizeX > 0 && iSizeY > 0) {
        piTable = new int* [iSizeX];
        for (int i = 0; i < iSizeX; i++) {
            piTable[i] = new int[iSizeY];
            for (int j = 0; j < iSizeY; j++) {
                piTable[i][j] = 5;
            }
        }
        return true;
    }
    else {
        return false;
    }
}

bool b_alloc_table_2_dim_v2(int*** piTableLink, int iSizeX, int iSizeY) {
    int** piTable = *piTableLink;
    if (iSizeX > 0 && iSizeY > 0) {
        piTable = new int* [iSizeX];
        for (int i = 0; i < iSizeX; i++) {
            piTable[i] = new int[iSizeY];
            for (int j = 0; j < iSizeY; j++) {
                piTable[i][j] = 5;
            }
        }
        *piTableLink = piTable;
        return true;
    }
    else {
        cout << "improper array size!" << endl;
        return false;
    }
}

//bool b_alloc_table_2_dim_v2(int** (*piTableLink), int iSizeX, int iSizeY) {
//    if (iSizeX > 0 && iSizeY > 0) {
//        *piTableLink = new int* [iSizeX];
//        for (int i = 0; i < iSizeX; i++) {
//            *piTableLink[i] = new int[iSizeY];
//            for (int j = 0; j < iSizeY; j++) {
//                *piTableLink[i][j] = 5;
//            }
//        }
//        return true;
//    }
//    else {
//        return false;
//    }
//}

//task 3
bool b_dealloc_table_2_dim(int**& piTable, int iSizeX) {
    for (int i = 0; i < iSizeX; i++) {
        delete[] piTable[i];
    }
    delete[] piTable;
    return true;
}

//task4
class CTable {
private:
    string s_name;
    int* arr;
    int size;

public:
    CTable() {
        s_name = "default name";
        size = 10;
        arr = new int[size];
        cout << "without: " << s_name << endl;
    }
    CTable(string sName, int iTableLen) {
        s_name = sName;
        size = iTableLen;
        arr = new int[iTableLen];
        cout << "parameter: " << s_name << endl;
    }

    CTable(string sName, int* arr,int size) {
        this->arr = arr;
        this->size = size;
        cout << "parameter: " << s_name << endl;
    }

    CTable(CTable& pcOther) {
        s_name = pcOther.getName() + "_copy";
        arr = pcOther.getArr();
        size = pcOther.getSize();
        cout << "copy: " << s_name << endl;
    }


    CTable operator+(CTable & ctableOther) {
        CTable tempTab;
        tempTab.bSetNewSize(this->size + ctableOther.getSize());
        for (int i = 0; i < size; i++) {
            tempTab.setValueAt(i, arr[i]);
        }
        cout << ctableOther.getSize();
        for (int i = 0; i < ctableOther.getSize(); i++) {
             tempTab.setValueAt(size + i, ctableOther.getArr()[i]);
        }
        return tempTab;
    }

    string getName() {
        return s_name;
    }

    int* getArr() {
        return arr;
    }

    int getSize() {
        return size;
    }
    
    bool setValueAt(int iOffset, int iNewVal) {
        if (iOffset < size && iOffset >= 0) {
            arr[iOffset] = iNewVal;
            return true;
        }
        else {
            return false;
        }
    }

    void vPrint() {
        for (int i = 0; i < size; i++) {
            if (i > 0) {
                cout << ", " << arr[i];
            }
            else {
                cout << arr[i];
            }
        }
        cout << endl;
    }

    void bSetNewSize(int size) {
        delete[] arr;
        arr = new int[size];
        this->size = size;
    }

    void setName(string sName) {
        s_name = sName;
    }

    CTable* pcClone() {
        CTable* tableClone = new CTable(*this);
        return tableClone;
    }
};

//void v_mod_tab(CTable* pcTab, int iNewSize) {
//    pcTab->changeSize(iNewSize);
//}
//
////creating the copy not changing the object in main
//void v_mod_tab(CTable pcTab, int iNewSize) {
//    pcTab.changeSize(iNewSize);
//}

int main()
{
    //task1
    cout << "task1: create two-dimensional array" << endl;
    cout << "enter the size of a one-dimensional array: ";
    int i;
    cin >> i;
    cout << endl;
    v_alloc_table_add_5(i);

//    //task2
//    cout << endl << "task2: " << endl << "creating a two-dimensional array:" << endl;
//    int x;
//    int y;
//    cout << "enter number of rows" << endl;
//    cin >> x;
//    cout << "enter number of columns" << endl;
//    cin >> y;
//    int** piTable;
//    b_alloc_table_2_dim(piTable, x, y);
//    b_alloc_table_2_dim_v2(&piTable, x, y);
//    for (int i = 0; i < x; i++) {
//        for (int j = 0; j < y; j++) {
//            cout << piTable[i][j];
//            if (j < y - 1) {
//                cout << ", ";
//            }
//        }
//
//        cout << endl;
//    }
//
//    //task3
//    cout << "task 3: " << "deallocating array:" << endl;
//    b_dealloc_table_2_dim(piTable, x);
//    //testing if going throught the deallocated array would cause an error
///*   for (int i = 0; i < x; i++) {
//        for (int j = 0; j < y; j++) {
//            cout << piTable[i][j];
//            if (j < y - 1) {
//                cout << ", ";
//            }
//        }
//
//        cout << endl;
//    }
//    */
//
//    //task4
//    //cout << "task4: " << "defining a class and creating it's instances" << endl;
//    //cout << "enter the s_name parameter for crerating an object :";
//    //string name;
//    //cin >> name;
//    //cout << endl;
//    //cout << "enter the iSize parameter for crerating an object :";
//    //int age;
//    //cin >> age;
//    //cout << endl;
//    //cout << "creating a pointer to an object by calling a constructor" << endl;
//    //CTable* pointerTable = new CTable(name, age);
//    //cout << "creating a direct instance of class CTable" << endl;
//    //CTable ctable(name, age);
//    //cout << "cloning the first object into the second";
//    //ctable = *(pointerTable->pcClone());
//    //cout << ctable.getName() << endl;
//    //cout << "changing the size of the table in the object to 20" << endl;
//    //v_mod_tab(&ctable, 20);

    CTable c_tab_0, c_tab_1;
    c_tab_0.bSetNewSize(6);
    c_tab_1.bSetNewSize(4);
//    c_tab_0 = c_tab_1;
    //the error here appears because at the end of the program when cleaning memory the allready free memory
    //is being cleaned again, as both c_tab_0, and c_tab_1 are pointing to the same memory address

    c_tab_0.vPrint();
    c_tab_0.setValueAt(5, 10);
    c_tab_0.vPrint();
    c_tab_0 = c_tab_0 + c_tab_1;
    c_tab_0.vPrint();
}
