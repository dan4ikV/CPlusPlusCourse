#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
	Stack<int> intStack;
	intStack.push(1);
	intStack.push(2);
	intStack.printStack();
	intStack.pop();
	intStack.printStack();

	Stack<string> stringStack;
	stringStack.push("Danylo");
	stringStack.push("Illia");
	stringStack.push("Andrew");
	stringStack.printStack();
	stringStack.pop();
	stringStack.pop();
	stringStack.printStack();
}