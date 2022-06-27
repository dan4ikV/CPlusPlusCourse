#include "CTreeStatic.h"
using namespace std;

CTreeStatic::CTreeStatic() { c_root = new CNodeStatic(); };
CTreeStatic::CTreeStatic(CNodeStatic *root) { c_root = *root; };
CTreeStatic::~CTreeStatic() {};
CNodeStatic* CTreeStatic::pcGetRoot() { return(&c_root); }
void CTreeStatic::vPrintTree() { c_root.vPrintAllBelow(); };
void CTreeStatic::bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode, CNodeStatic* pc2ParentNode) {
	pcParentNode->vAddNewChild();
	pcParentNode->setChild(pcParentNode->iGetChildrenNumber() - 1, pcNewChildNode);
	pcNewChildNode->setRoot(pcParentNode);
	if (pc2ParentNode != NULL) {
		pc2ParentNode->removeChild(pcNewChildNode);
	}

}
int CTreeStatic::countOccurences(int val) {
	return pcGetRoot()->count(val);
}