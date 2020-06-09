// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to store Next larger elements

#include<stack>
void nextLargerElement(long long arr[], int n){
    stack<long long> S;
    long long b[n];
    S.push(0);
    for(int i=1;i<n;i++)
    {
        while(!S.empty() && arr[S.top()]<arr[i])
        {
            b[S.top()]=arr[i];
            S.pop();
        }
        
        S.push(i);
    }
    
    while(!S.empty())
    {
        b[S.top()]=-1;
        S.pop();
    }
    
    for(int j=0;j<n;j++)
    {
        cout<<b[j]<<" ";
    }
    
    // Your code here
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        
        nextLargerElement(arr, n);
        
        cout<<endl;
    }
	return 0;
}
  // } Driver Code Ends