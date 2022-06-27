#pragma once
#include "CNodeDynamic.h" 

class CTreeDynamic
{
private:
    CNodeDynamic* c_root;
public:
    CTreeDynamic();

    CTreeDynamic(CNodeDynamic* root);

    ~CTreeDynamic();

    CNodeDynamic* pcGetRoot();

    void vPrintTree();

    void bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode, CNodeDynamic* pc2ParentNode);

    int countOccurences(int val);
};

