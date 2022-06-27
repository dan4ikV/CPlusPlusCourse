#pragma once

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

    CTable(CTable&& pcOther) {
        s_name = pcOther.s_name;
        arr = pcOther.arr;
        size = pcOther.size;
        pcOther.arr = NULL;
        cout << "move" << endl;
    }

    CTable operator=(CTable& ctableOther) {
        delete[] arr;
        size = ctableOther.getSize();
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            setValueAt(i, ctableOther.getArr()[i]);
        }
        return *this;
    }

    CTable operator=(CTable&& ctableOther) {
        this->~CTable();
        arr = ctableOther.arr;
        size = ctableOther.size;
        s_name = ctableOther.s_name;
        ctableOther.arr = NULL;
        ctableOther.size = 0;
        ctableOther.s_name = "undefined";
        return *this;
    }


    CTable operator+(CTable&& ctableOther) {
        CTable tempTab;
        tempTab.bSetNewSize(size + ctableOther.getSize());
        for (int i = 0; i < size; i++) {
            tempTab.setValueAt(i, arr[i]);
        }
        cout << ctableOther.getSize();
        for (int i = 0; i < ctableOther.getSize(); i++) {
            tempTab.setValueAt(size + i, ctableOther.getArr()[i]);
        }
        return std::move(tempTab);
    }

    CTable operator+(CTable& ctableOther) {
        CTable tempTab;
        tempTab.bSetNewSize(size + ctableOther.getSize());
        for (int i = 0; i < size; i++) {
            tempTab.setValueAt(i, arr[i]);
        }
        cout << ctableOther.getSize();
        for (int i = 0; i < ctableOther.getSize(); i++) {
            tempTab.setValueAt(size + i, ctableOther.getArr()[i]);
        }
        return std::move(tempTab);
    }


    CTable operator--() {
        int* tempArr = new int[size - 1];
        for (int i = 0; i < size - 1; i++) {
            tempArr[i] = arr[i];
        }
        delete[] arr;
        arr = tempArr;
        size -= 1;
        return *this;
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