// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

#include<stack>
#include<string>
// Function to return if the paranthesis are balanced or not
bool ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}
bool ispar(string x)
{
    stack<char> S;
    int n = x.length();
    for(int i=0;i<n;i++)
    {
        if(x[i]=='(' || x[i]=='{' || x[i]=='[')
        {
            S.push(x[i]);
        }
        else if(x[i]==')' || x[i]=='}' || x[i]==']')
        {
            if(S.empty()==true || !ArePair(S.top(),x[i]))
            {
                return false;
            }
            else
            {
                S.pop();
            }
        }
    }
    if(S.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
    
    // Your code here
}


// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       if(ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends