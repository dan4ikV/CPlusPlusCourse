#include "CTreeDynamic.h"

using namespace std;

CTreeDynamic::CTreeDynamic() { c_root = new CNodeDynamic(); };

CTreeDynamic::CTreeDynamic(CNodeDynamic* root) { c_root = root; };

CTreeDynamic::~CTreeDynamic() {};

CNodeDynamic* CTreeDynamic::pcGetRoot() { return c_root; };

void CTreeDynamic::vPrintTree() { c_root->vPrintAllBelow(); };

void CTreeDynamic::bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode, CNodeDynamic* pc2ParentNode) {
    pcParentNode->vAddNewChild();
    pcParentNode->setChild(pcParentNode->iGetChildrenNumber() - 1, pcNewChildNode);
    pcNewChildNode->setRoot(pcParentNode);
    if (pc2ParentNode != NULL) {
        pc2ParentNode->removeChild(pcNewChildNode);
    }
};

int CTreeDynamic::countOccurences(int val) {
    return pcGetRoot()->count(val);
};
