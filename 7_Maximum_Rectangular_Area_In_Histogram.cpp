// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to return Maximum Rectangular area in a histogram
// arr[]: input array
// n: size of array
#include<stack>
long getMaxArea(long long arr[], int n){
    
    // Your code here
    stack<long long> S;
    long long top;
    long long maxarea=0;
    long long area;
    int i = 0;
    while(i<n)
    {
        if(S.empty() || arr[S.top()]<=arr[i])
        {
            S.push(i++);
        }
        else
        {
            top = S.top();
            S.pop();
            
            area = arr[top]*( S.empty()? i : (i-S.top()-1) );
            
            if(maxarea<area)
            {
                maxarea=area;
            }
        }
        
    }
    
    while(!S.empty())
    {
        top = S.top();
        S.pop();
        
        area = arr[top]*( S.empty()? i : (i-S.top()-1));
            
        if(maxarea<area)
        {
            maxarea=area;
        }
    }
    
    return maxarea;
    
}

// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout<<getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends