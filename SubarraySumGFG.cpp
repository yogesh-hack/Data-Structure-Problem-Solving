//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        long long sum = arr[0];
        int i = 0;
        int j = 0;
        
        while((j < n) && (sum != s)){
            j++;
            
            sum += arr[j];
            
            if(sum < s){
                continue;
            }
            else{
                while(sum > s){
                    sum -= arr[i];
                    i++;
                }
            }
        }
        if(sum != s || i > j){
            vector<int> ans{-1};
            return ans;
        } 
        
        vector<int> res{i+1,j+1};
        return res;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
