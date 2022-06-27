#include <iostream>

using namespace std;


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

    CTable(string sName, int* arr, int size) {
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


    CTable operator+(CTable& ctableOther) {
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

    void operator--() {
        if (size > 0) {
            int* tempArr = new int[size - 1];
            for (int i = 0; i < size - 1; i++) {
                tempArr[i] = arr[i];
            }
            size = size - 1;
            delete[] this->arr;
            arr = tempArr;
        }
        else {
            cout << "size is allready 0" << endl;
        }
    }
};

int main()
{
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
    --c_tab_0;
    c_tab_0.vPrint();
}