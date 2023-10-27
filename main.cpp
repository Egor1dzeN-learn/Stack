#include <iostream>
#include<stack>
using namespace std;
#include "TStack.h"
int main() {
    TStack<int> stack1(7);
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.push(6);
    stack1.push(7);
    stack1.push(8);
    stack1.push(9);
    return 0;
}
