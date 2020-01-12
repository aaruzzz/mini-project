#include <iostream>
#include "stack.h"
#include<string.h>
using namespace std;


int pr(char a){
	
	if (a=='+') return 1;
	if (a=='-') return 1;
	if (a=='/') return 2;
	if (a=='*') return 2;
}

int main()
{
Stack s;
char infix[40];
char postfix[40];
int count=0;
int pf=0;
char fetch;
int invalidCheck=0;

scanf("%s",infix);


//scanf("%s",postfix);

while(count<strlen(infix)){
	char fetch= infix[count];
		if(fetch=='+'||fetch=='-'||fetch=='/'||fetch=='*')
		{
			if(s.isEmpty()) {s.push(fetch) ;} //if stack is empty 
			else if(s.tops()=='(') {s.push(fetch);}//if previous element in stact is (
			else if(pr(fetch)>pr(s.tops())){ s.push(fetch);}  //priority check
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
				
				if(!s.isEmpty()) z=s.pop();
				
					if(s.isEmpty()) {cout<<"more closing brackets";invalidCheck=1;break;}
					else postfix[pf++]=z; 
				}
				
				//else printf("%c",z);
				//else {printf("%c",c);break;}
			}while(z!='(');
			
				
				
				
			}
			
		
		
		else postfix[pf++]=fetch;//printf("%c3",fetch);
count++;

}

while(!s.isEmpty() && !invalidCheck){
	char p=s.pop();
	if(p=='(') 
	{
		cout <<"more opening brackets"<<endl;
		invalidCheck=1;
		break;
	}
	else postfix[pf++]=p;
	
}

postfix[pf]='\0';
if(!invalidCheck) puts(postfix);

return 0;
}



