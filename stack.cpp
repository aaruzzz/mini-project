#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack()
{
top=-1;
}

Stack::~Stack(){}

void Stack::push(char element)
{
if (top>=MAX)
{
std::cout<<"Cannot push"<<element<<"Stack Overflow";
}
else
{
this->top++;
this->elements[top]=element;
}
}

bool Stack::isEmpty()
{
if (top<0)
return true;
else
return false;
}

int Stack::tops()
{
return this->elements[top];
}

int Stack::pop()
{
if (top<0)
std::cout<<"Cannot remove element. Stack Underflow";
else
{
return this->elements[top--];
}
}
