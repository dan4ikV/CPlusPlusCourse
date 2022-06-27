#include <iostream>
#include <vector>
#include "CNodeStatic.h"
#include "CTreeStatic.h"
#include "CNodeDynamic.h"
#include "CTreeDynamic.h"
using namespace std;


void v_tree_test()
{
    cout << "testing with static tree" << endl;
    CNodeStatic c_root;
    c_root.vSetValue(0);
    c_root.vAddNewChild();
    c_root.vAddNewChild();
    c_root.pcGetChild(0)->vSetValue(1);
    c_root.pcGetChild(1)->vSetValue(2);
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    c_root.vPrintAllBelow();
    cout << endl;

    CNodeStatic c_root_2;
    c_root_2.vSetValue(0);
    c_root_2.vAddNewChild();
    c_root_2.vAddNewChild();
    c_root_2.pcGetChild(0)->vSetValue(5);
    c_root_2.pcGetChild(1)->vSetValue(6);
    c_root_2.pcGetChild(0)->vAddNewChild();
    c_root_2.pcGetChild(0)->vAddNewChild();
    c_root_2.pcGetChild(0)->pcGetChild(0)->vSetValue(5);
    c_root_2.pcGetChild(0)->pcGetChild(1)->vSetValue(8);
    c_root_2.pcGetChild(1)->vAddNewChild();
    c_root_2.pcGetChild(1)->vAddNewChild();
    c_root_2.pcGetChild(1)->pcGetChild(0)->vSetValue(9);
    c_root_2.pcGetChild(1)->pcGetChild(1)->vSetValue(5);
    c_root_2.vPrintAllBelow();
    cout << endl << "Testing static tree print up:" << endl;
    c_root_2.pcGetChild(0)->pcGetChild(0)->vPrintUp();
    cout << endl;
    c_root_2.pcGetChild(0)->pcGetChild(1)->vPrintUp();
    cout << endl;
    c_root_2.pcGetChild(1)->pcGetChild(1)->vPrintUp();
    cout << endl;


    cout << endl;

    CTreeStatic tree(&c_root_2);
    tree.bMoveSubtree(tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0), c_root.pcGetChild(0), c_root.pcGetChild(0)->pcGetRoot());
    tree.vPrintTree();
    cout << endl;
    cout << "occurrences of 1 in that tree : " <<tree.countOccurences(1)  << endl;
    cout << "occurrences of 5 in that tree : " <<tree.countOccurences(5)  << endl;
    cout << "occurrences of 100 in that tree : " <<tree.countOccurences(100)  << endl;
    cout << "all that's left in the tree: " << endl;
    c_root.vPrintAllBelow();

}

void v_dynamic_tree_test()
{
    cout << "testing with dynamic tree" << endl;

    CNodeDynamic c_root_1;
    cout << "c_root_1 tree:";
    c_root_1.vSetValue(0);
    c_root_1.vAddNewChild();
    c_root_1.vAddNewChild();
    c_root_1.pcGetChild(0)->vSetValue(1);
    c_root_1.pcGetChild(1)->vSetValue(2);
    c_root_1.pcGetChild(0)->vAddNewChild();
    c_root_1.pcGetChild(0)->vAddNewChild();
    c_root_1.pcGetChild(0)->pcGetChild(0)->vSetValue(3);
    c_root_1.pcGetChild(0)->pcGetChild(1)->vSetValue(4);
    c_root_1.pcGetChild(1)->vAddNewChild();
    c_root_1.pcGetChild(1)->vAddNewChild();
    c_root_1.pcGetChild(1)->pcGetChild(0)->vSetValue(5);
    c_root_1.pcGetChild(1)->pcGetChild(1)->vSetValue(6);
    c_root_1.vPrintAllBelow();

    //testing print up
    cout << endl << "testing print up: " << endl;
    c_root_1.pcGetChild(0)->pcGetChild(0)->vPrintUp();
    cout << endl;
    c_root_1.pcGetChild(0)->pcGetChild(1)->vPrintUp();
    cout << endl;

    CNodeDynamic c_root_2;
    c_root_2.vSetValue(3);
    c_root_2.vAddNewChild();
    c_root_2.vAddNewChild();
    c_root_2.pcGetChild(0)->vSetValue(1);
    c_root_2.pcGetChild(1)->vSetValue(2);
    c_root_2.pcGetChild(0)->vAddNewChild();
    c_root_2.pcGetChild(0)->vAddNewChild();
    c_root_2.pcGetChild(0)->pcGetChild(0)->vSetValue(4);
    c_root_2.pcGetChild(0)->pcGetChild(1)->vSetValue(3);
    c_root_2.pcGetChild(1)->vAddNewChild();
    c_root_2.pcGetChild(1)->vAddNewChild();
    c_root_2.pcGetChild(1)->pcGetChild(0)->vSetValue(4);
    c_root_2.pcGetChild(1)->pcGetChild(1)->vSetValue(3);

    c_root_2.vPrintAllBelow();
    CTreeDynamic tree(&c_root_2);
    tree.bMoveSubtree(c_root_2.pcGetChild(0)->pcGetChild(0), c_root_1.pcGetChild(0), c_root_1.pcGetChild(0)->pcGetRoot());
    cout << endl;
    tree.vPrintTree();
    cout << endl;
    cout << "testing upprint with a tree: " << endl;
    tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->pcGetChild(1)->vPrintUp();
    cout << endl;

    cout << "occurrences of 3 in that tree : " << tree.countOccurences(3) << endl;
    cout << "occurrences of 2 in that tree : " << tree.countOccurences(2) << endl;
    cout << "occurrences of 1 in that tree : " << tree.countOccurences(1) << endl;
    cout << "left in the c_root_1 tree: ";
    c_root_1.vPrintAllBelow();
    }

int main()
{
    v_tree_test();
    cout << endl << endl;
    v_dynamic_tree_test();
}