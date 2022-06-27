#pragma once
#include <vector>
using namespace std;

class CNodeStatic {
public: 
	CNodeStatic();
	CNodeStatic(CNodeStatic* root);
	~CNodeStatic();
	void vSetValue(int iNewVal);
	int iGetChildrenNumber();
	void vAddNewChild();
	CNodeStatic* pcGetChild(int iChildOffset);
	void vPrint();
	void vPrintAllBelow();
	void vPrintUp();
	CNodeStatic* pcGetRoot();
	bool setChild(int num, CNodeStatic* newChild);
	bool removeChild(CNodeStatic* childNode);
	int count(int val);
	void setRoot(CNodeStatic* new_root);
private:
	vector<CNodeStatic> v_children;
	int i_val;
	CNodeStatic* c_root;
};