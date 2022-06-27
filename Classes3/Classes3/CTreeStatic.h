#pragma once
#include "CNodeStatic.h" 

class CTreeStatic
{
public:
    CTreeStatic();
    CTreeStatic(CNodeStatic* root);
    ~CTreeStatic();
    CNodeStatic* pcGetRoot();
    void bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode, CNodeStatic* pc2ParentNode);
    void vPrintTree();
    int countOccurences(int val);
private:
    CNodeStatic c_root;
};

