#include <iostream>
#include <vector>
#include "CNodeStatic.h"

using namespace std;

CNodeStatic::CNodeStatic() { i_val = 0; };

CNodeStatic::CNodeStatic(CNodeStatic* root) {
    i_val = 0;
    c_root = root;
};

CNodeStatic::~CNodeStatic() {
    /*for (int i = 0; i < iGetChildrenNumber(); i++) {
        (*pcGetChild(i)).~CNodeStatic();
    }*/
};

void CNodeStatic::vSetValue(int iNewVal) { i_val = iNewVal; };

int CNodeStatic::iGetChildrenNumber() { return(v_children.size()); };

void CNodeStatic::vAddNewChild() { v_children.push_back(CNodeStatic(this)); };


CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset) {
    if (iChildOffset < v_children.size() && iChildOffset >= 0) {
        return &(v_children.at(iChildOffset));
    }
    else {
        return NULL;
    }
}

void CNodeStatic::setRoot(CNodeStatic* new_root) {
    c_root = new_root;
}

void CNodeStatic::vPrint() { cout << " " << i_val; };

void CNodeStatic::vPrintAllBelow() {
    vPrint();
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        (*pcGetChild(i)).vPrintAllBelow();
    }
}

void CNodeStatic::vPrintUp() {
    vPrint();
    if (!c_root == NULL) {
        c_root->vPrintUp();
    }
}

CNodeStatic* CNodeStatic::pcGetRoot() { return(c_root); }

bool CNodeStatic::setChild(int num, CNodeStatic* newChild) {
    if (num >= 0 && num < iGetChildrenNumber()) {
        v_children.at(num) = *newChild;
        return true;
    }
    else {
        return false;
    }
}

bool CNodeStatic::removeChild(CNodeStatic* childNode) {
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        if (childNode == &(v_children.at(i))) {
            v_children.erase(v_children.begin() + i);
            return true;
        }
    }
    return false;
}

int CNodeStatic::count(int val) {
    int found = 0;
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        found += v_children.at(i).count(val);
    }
    if (i_val == val) {
        return found + 1;
    }
        return found;
}