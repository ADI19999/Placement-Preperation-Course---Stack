// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Position this line where user code will be pasted.
void printMaxOfMin(int arr[], int n);
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        printMaxOfMin(a, n);
    }
    return 0;
}
// } Driver Code Ends


// Function to print maximum of minimum of every window size
// arr[]: input array
// n: size of array
void printMaxOfMin(int arr[], int n) {
    // Your code here
    stack<int> s;
    int left[n+1];
    int right[n+1];
    
    for(int i=0;i<=n;i++)
    {
        left[i]=-1;
        right[i]=n;
    }
    for(int j=0;j<n;j++)
    {
        while(!s.empty() && arr[s.top()]>=arr[j])
        {
            s.pop();
        }
        if(!s.empty())
        {
            left[j]=s.top();
        }
        
        s.push(j);
    }
    while(!s.empty())
    {
        s.pop();
    }
    for(int k=n-1;k>=0;k--)
    {
        while(!s.empty() && arr[s.top()]>=arr[k])
        {
            s.pop();
        }
        if(!s.empty())
        {
            right[k]=s.top();
        }
        
        s.push(k);
    }
    int b[n+1];
    for(int m=0;m<=n;m++)
    {
        b[m]=0;
    }
    for(int h=0;h<n;h++)
    {
        int len = right[h] - left[h] - 1;
        b[len] = max(b[len],arr[h]);
    }
    for(int i=n-1;i>=1;i--)
    {
        b[i]=max(b[i],b[i+1]);
    }
    
    for(int i=1;i<=n;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
}