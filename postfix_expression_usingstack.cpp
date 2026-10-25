#include<iostream>
#include<cmath>
#include<cctype>
using namespace std;

class stack{
    private:
        int arr[100];
        int top;

        public:
        stack()
        {
            top=-1;
        }

        void push(int val)
        {
            top++;
            arr[top]=val;
        }
        int pop()
        {
            int p = arr[top];
            top--;
            return(p);
        }
};

int evaluate(char x,int op1,int op2)
{
    if(x=='+')
    return(op1 + op2);

    if(x=='-')
    return(op1 - op2);

    if(x=='*')
    return(op1 * op2);

    if(x=='/')
    return(op1 / op2);

    if(x=='%')
    return(op1 % op2);

    if(x=='$')
    return(pow(op1,op2));

    return 0;
}

int main(void)
{
    stack s;
    char x;
    int op1,op2,val;

    cout<<"\n enter postfix expression;";
    while((x=getchar())!='\n')
    {
        if(isdigit(x))
        {
            s.push(x-48);
        }
        else{
            op2=s.pop();
            op1 =s.pop();
            val =evaluate(x, op1 ,op2);
            s.push(val);
        }
    }

    val =s.pop();
    cout<<"\n answer="<<val;
    return 0;
}
//PS C:\Users\STUDENT\Desktop\manasi kulkarni 209> g++ postfix_expression_usingstack.cpp
//PS C:\Users\STUDENT\Desktop\manasi kulkarni 209> ./a.exe

// enter postfix expression;54-45+*35/3%6$

 //answer=0
//PS C:\Users\STUDENT\Desktop\manasi kulkarni 209> g++ postfix_expression_usingstack.cpp
//PS C:\Users\STUDENT\Desktop\manasi kulkarni 209> ./a.exe

 //enter postfix expression;8+-32*36\4%6$89

 //answer=9
//PS C:\Users\STUDENT\Desktop\manasi kulkarni 209> 