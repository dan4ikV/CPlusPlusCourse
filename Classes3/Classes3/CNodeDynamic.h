#pragma once
#include <vector>

using namespace std;
class CNodeDynamic
{
private:
    vector<CNodeDynamic*> v_children;
    int i_val;
    CNodeDynamic* c_root;

public:

    CNodeDynamic() {
    };

    CNodeDynamic(CNodeDynamic* root);

    ~CNodeDynamic();

    void vSetValue(int iNewVal);

    int iGetChildrenNumber();

    void vAddNewChild();

    CNodeDynamic* pcGetChild(int iChildOffset);

    void vPrint();

    void vPrintAllBelow();

    void vPrintUp();

    CNodeDynamic* pcGetRoot();

    bool setChild(int num, CNodeDynamic* newChild);

    bool removeChild(CNodeDynamic* childNode);

    int count(int val);

    void setRoot(CNodeDynamic* new_root);
};