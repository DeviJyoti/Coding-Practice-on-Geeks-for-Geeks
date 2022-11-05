//LINK:-https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
   
class Solution{
    
  public:
  
  void merge(long long arr[],long long l,long long m,long long r,long long int &ans)
    {
        long long n1=(m-l)+1;
        long long n2=(r-m);
        
        long long a1[n1];
        long long a2[n2];
        long long k=0;
        for(long long i=l;i<=m;i++)
        {
            a1[k]=arr[i];
            k++;
        }
        k=0;
        for(long long i=m+1;i<=r;i++)
        {
            a2[k]=arr[i];
            k++;
        }
        
        
        long long i=0;
        long long j=0;
        k=l;
        while(i<n1&&j<n2)
        {
            if(a1[i]<=a2[j])
            {
                arr[k]=a1[i];
                i++;
                k++;
            }
            else
            {
                ans+=(n1-i);
                arr[k]=a2[j];
                j++;
                k++;
            }
        }
       
        while(i<n1)
        {
            arr[k]=a1[i];
            i++;
            k++;
        }
        
        while(j<n2)
        {
            arr[k]=a2[j];
            j++;
            k++;
        }
        return;
    }
    
    void mergesort(long long arr[],long long l,long long r,long long int &ans)
    {
        if(l<r)
        {
            int mid=l+(r-l)/2;
            mergesort(arr,l,mid,ans);
            mergesort(arr,mid+1,r,ans);
            
            merge(arr,l,mid,r,ans);
        }
         return;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long int ans=0;
       mergesort(arr,0,N-1,ans);
       return ans;
        
    }

};


//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
