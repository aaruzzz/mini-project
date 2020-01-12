#include <iostream>
#include "stack.h"
#include<string.h>
using namespace std;


int pr(char a){                 //function to check priority
	
	if (a=='+') return 1; //lower and same precedence
	if (a=='-') return 1;
	if (a=='/') return 2; //higher and same precedence
	if (a=='*') return 2;
}

int main()
{
Stack s;
char infix[40];
char postfix[40];
int count=0;                        //index for infix expression array
int pf=0;			    //index of postfix expression array
char fetch;			    //seperating each char of infix expression
int invalidCheck=0;		    //to keep check if the expression is invalid so postfix 

scanf("%s",infix);

while(count<strlen(infix)){
	char fetch= infix[count];
		if(fetch=='+'||fetch=='-'||fetch=='/'||fetch=='*')   
		{
			if(s.isEmpty()) {s.push(fetch) ;}                      //if stack is empty 
			else if(s.tops()=='(') {s.push(fetch);}               //if previous element in stact is (
			else if(pr(fetch)>pr(s.tops())){ s.push(fetch);}     //priority check
			else 
			{
				postfix[pf++]= s.pop();
				s.push(fetch);
			}
		}
		
		else if(fetch == '(') {s.push(fetch);} //push opening brackets
				
		else if (fetch == ')'){
			char z='0' ;
			do
			{	
				if(!s.isEmpty()) z=s.pop();        //to avoid popping from empty stack
				if(z!='('){
					if(s.isEmpty()) 
					{
						cout<<"more closing brackets";
						invalidCheck=1;
						break;
					}
					else postfix[pf++]=z;
				}
				
				
			}while(z!='(');
		}
				
		else postfix[pf++]=fetch;		//for operands
count++;
}

while(!s.isEmpty() && !invalidCheck){
	char p=s.pop();
	if(p=='(') 			//if open brackets left in the stack than invalid
	{
		cout <<"more opening brackets"<<endl;  
		invalidCheck=1;
		break;
	}
	else postfix[pf++]=p;
	
}

postfix[pf]='\0';			   //making the array a string
if(!invalidCheck) puts(postfix);          //if the expression isn't invalid print postfix expression

return 0;
}



