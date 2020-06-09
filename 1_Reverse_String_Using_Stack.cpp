// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
void reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        reverse(str,len);
        cout<<str;
        cout<<endl;
    }
        return 0;
}
// } Driver Code Ends

#include<stack>
void reverse(char *str, int len)
{
    // Your code goes here
     stack<char> S;
     for(int i=0;i<len;i++)
     {
         S.push(str[i]);
     }
     for(int j=0;j<len;j++)
     {
         str[j]=S.top();
         S.pop();
     }
     
}