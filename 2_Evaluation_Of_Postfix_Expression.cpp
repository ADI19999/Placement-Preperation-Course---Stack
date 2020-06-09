// { Driver Code Starts
// C++ program to evaluate value of a postfix expression
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

#include<stack>
// The main function that returns value of a given postfix expression
int calculate(char ch,int a,int b)
{
    int c = 0;
    if(ch=='+')
    {
        c=a+b;
        return c;
    }
    else if(ch=='-')
    {
        c=a-b;
        return c;
    }
    else if(ch=='*')
    {
        c=a*b;
        return c;
    }
    else if(ch=='/')
    {
        c=a/b;
        return c;
    }
    
}
int evaluatePostfix(string &str)
{
    // Your code here
    stack<int> s;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            s.push(str[i]-'0');
        }
        else
        {
            int op2=s.top();
            s.pop();
            int op1=s.top();
            s.pop();
            int res = calculate(str[i],op1,op2);
            s.push(res);
        }
    }
    
    return s.top();
    
}


// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string str;
        cin>>str;
    
    cout<<evaluatePostfix(str)<<endl;
    }
    return 0;
}
  // } Driver Code Ends