//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
 
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int temp=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            temp+=arr[i]%mod;
        }
        if(temp-d<0 || (d+temp)%2)return 0;
        
        int w = ((d+temp)/2);
        
        //dp approach
       vector<vector<int>>t(n+1,vector<int>(w+1));
        
        // initialisation
        for(int i=0;i<n+1;i++){
            for(int j=0;j<w+1;j++){
               if(i==0)t[i][j]=0;
               if(j==0)t[i][j]=1;
            }
        }
        
        //iterative approach
        for(int i=1;i<n+1;i++){
            for(int j=0;j<w+1;j++){
                //include
                if(arr[i-1]<=j){
                    t[i][j]=(t[i-1][j]+t[i-1][j-arr[i-1]])%mod;
                }
                else{
                     //exclude
                t[i][j]=t[i-1][j]%mod;
                }
               
            }
        }
        return t[n][w]%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends
