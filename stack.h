#define MAX 100

class Stack
{
private:
int top;
char elements[MAX];
public:
Stack();
~Stack();

void push(char element);
int pop();
int tops();
bool isEmpty();
};

