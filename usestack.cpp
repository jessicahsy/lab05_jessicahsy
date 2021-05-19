// usestack.cpp - for CS 24 lab practice using stacks
// NAME(S), DATE

#include "intstack.h"
#include <iostream>
#include <stack>

//#include <cstdlib>
using namespace std;

int main() {
    Stack s;
    // stack<int> x;
    // stack<int> y;
    // x.emplace(111);
    // x.emplace(222);
    // y.emplace(900);
    // y.emplace(800);
    // x.swap(y);
    // cout<<"x: ";
    // while (!x.empty()) {
	// 	cout << x.top() << " ";
	// 	x.pop();
	// }
    // cout<<endl;
    s.push(10);
    s.push(20);
    s.pop();
    cout<<"top: "<<s.top()<<endl;
    s.pop();
    cout<<"s empty? "<<s.empty()<<endl;
    cout<<"expect 0. size: "<<s.size()<<endl;

    s.pop();
    s.pop();
    cout<<"s next: ";s.get_next();
    s.push(9);
    s.push(8);
    cout<<"expect 2. size: "<<s.size()<<endl;
    s.push(7);
    s.push(6);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(0);
    s.push(11);
    s.push(12);
    cout<<"expect 10. size: "<<s.size()<<endl;
    cout<<"s full? "<<s.full()<<endl;

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
