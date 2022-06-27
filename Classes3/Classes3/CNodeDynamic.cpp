#include <iostream>
#include <vector>
#include "CNodeDynamic.h"

using namespace std;

CNodeDynamic::CNodeDynamic(CNodeDynamic* root) {
    c_root = root;
};

CNodeDynamic::~CNodeDynamic() {
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        (*pcGetChild(i)).~CNodeDynamic();
    }
};

void CNodeDynamic::vSetValue(int iNewVal) { i_val = iNewVal; };

int CNodeDynamic::iGetChildrenNumber() { return(v_children.size()); };

void CNodeDynamic::vAddNewChild() { v_children.push_back(new CNodeDynamic(this)); }

CNodeDynamic* CNodeDynamic::pcGetChild(int iChildOffset) {
    if (iChildOffset < v_children.size() && iChildOffset >= 0) {
        return v_children.at(iChildOffset);
    }
    else {
        return NULL;
    }
}

void CNodeDynamic::vPrint() { cout << " " << i_val; };

void CNodeDynamic::vPrintAllBelow() {
    vPrint();
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        (*pcGetChild(i)).vPrintAllBelow();
    }
}


void CNodeDynamic::setRoot(CNodeDynamic* new_root) {
    c_root = new_root;
}

void CNodeDynamic::vPrintUp() {
    vPrint();
    if (!c_root == NULL) {
        c_root->vPrintUp();
    }
}

CNodeDynamic* CNodeDynamic::pcGetRoot() { return(c_root); }

bool CNodeDynamic::setChild(int num, CNodeDynamic* newChild) {
    if (num >= 0 && num < iGetChildrenNumber()) {
        v_children.at(num) = newChild;
        return true;
    }
    else {
        return false;
    }
}

bool CNodeDynamic::removeChild(CNodeDynamic* childNode) {
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        if (childNode == v_children.at(i)) {
            v_children.erase(v_children.begin() + i);
            return true;
        }
    }
    return false;
}

int CNodeDynamic::count(int val) {
    int found = 0;
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        found += v_children.at(i)->count(val);
    }
    if (val == i_val) {
        return found + 1;
    }
    return found;
}