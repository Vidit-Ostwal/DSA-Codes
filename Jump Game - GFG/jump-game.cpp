// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
    bool recursion(int nums[], int index,vector<int>&dp,int size)
  {
    if (index >= size -1)
        return true;

    if (dp[index] != -1)
      return dp[index];
    
    bool flag = false;
    int jump = nums[index];
  
    for (int i = 1 ; i <= jump; i++)
    {
      flag = (dp[index+i] == -1) ? recursion(nums,index+i,dp,size) : dp[index+i];
      
      if (flag)
        break;
    }
    return dp[index] = flag;
  }
    
    bool top_down_solution(int nums[],int N)
  {
    vector<bool> reach(N,false);
    int i = 0;
    reach[i] = true;

    for (int k = 0; k < N;k++)
    {
      if (reach[k])
      {
        int jump = nums[k]+k;
        while (i <= jump && i < N)
        {
          reach[i] = true;
          i++;
        }
      }
    }
    return reach[reach.size()-1];
  }
  public:
    int canReach(int A[], int N) {
        return top_down_solution(A,N);
        vector<int> dp(N,-1);
        return recursion(A,0,dp,N);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends