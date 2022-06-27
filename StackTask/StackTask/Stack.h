#pragma once
#include<vector>
#include <iostream>
using namespace std;

template <typename T> class Stack {
private:
	vector<T> elements;
public:
	Stack() {}
	void push(T val) {
		elements.push_back(val);
	}
	void pop() {
		elements.pop_back();
	}
	void printStack() {
		for (int i = 0; i < elements.size(); i++) {
			if (i == elements.size() - 1) {
				cout << elements.at(i);
			}
			else {
				cout << elements.at(i) << ", ";
			}
		}
		cout << endl;
	}
};
