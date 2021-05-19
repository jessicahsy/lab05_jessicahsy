// usestack.cpp - for CS 24 lab practice using stacks
// NAME(S), DATE

#include "intstack.h"
#include <iostream>
#include <cstring> 
#include <string> 
#include <stack>
#include <typeinfo>

//#include <cstdlib>
using namespace std;

int main() {
//____________use_stack____________
    cout<<"\n_____use_stack_____\n";
    Stack s;
    s.push(10);
    s.push(20);
    s.pop();
    cout<<"top: "<<s.top()<<endl;
    s.pop();
    cout<<"s empty? "<<s.empty()<<endl;
    cout<<"expect 0. size: "<<s.size()<<endl;
    s.pop();
    cout<<"s next: "<<s.get_next()<<endl;
    s.push(99);
    s.push(88);
    s.push(77);
    s.push(66);
    s.push(55);
    s.push(44);
    s.push(33);
    s.push(22);
    s.push(11);
    s.push(0);
    s.push(1);
    cout<<"expect 10. size: "<<s.size()<<endl;
    cout<<"s full? "<<s.full()<<endl;

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }



//____________postfix______________
cout<<"_____postfix_____(i)\n";
//evaluating "5 2 - 3 *"

//start with an empty stack

Stack numbers;

// first two tokens- push "5 2":
numbers.push(5);
numbers.push(2);

// third token is calculation to do "-":
int right = numbers.top();
numbers.pop();
int left = numbers.top();
numbers.pop();
numbers.push(left - right);
//top is 3

// fourth token- push "3":
numbers.push(3);

// fifth is another calculation "*":
right = numbers.top();
numbers.pop();
left = numbers.top();
numbers.pop();
numbers.push(left * right);
//top is 9

// done - print result:
cout << numbers.top() << endl;


// i'm still confused about this postfix section
// including this just in case...
cout<<"_____postfix_____(ii)\n";
    Stack post;
    cout<<"Enter postfix>>  ";
    char input[30], *tokens[15];
    cin.getline(input, CAPACITY);
    char *ptr = strtok(input, " ");
    int count=0;
    while (ptr != 0) {
        tokens[count] = ptr;
        ++count;
        ptr = strtok(0, " ");
    }

    for(int i=0;i<count;i++){
        int right,left;
        char tok=*tokens[i];
        if ((tok>='0')&&(tok<='9')){
            int T=tok-'0';                  //convert tok to int var so it can be
            post.push(T);                   //pushed and/or used w/ arithmetic operations
        }else{                              //only works with int 0-9...
            if (post.get_next()<2){cout<<"bad expression: unexpected operator"<<endl;return 1;}
            else{
                right = post.top();
                post.pop();
                left = post.top();
                post.pop();
                //cout<<"token: "<<tok<<endl;
                if (tok=='+'){post.push(left+right);}
                else if (tok=='-'){post.push(left-right);}
                else if (tok=='*'){post.push(left*right);}
                else if (tok=='/'){post.push(left/right);}
                else {cerr<<"bad expression: invalid char found"<<endl;return 1;}
                }
            }
    }
    if (post.get_next()!=1){cout<<"bad expression: operator expected"<<endl;return 1;}
    cout<<"Result: "<<post.top()<<endl;


    return 0;
}
