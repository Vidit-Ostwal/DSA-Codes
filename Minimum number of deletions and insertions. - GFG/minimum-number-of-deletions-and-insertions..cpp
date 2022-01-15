// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	int top_down_solution(string text1, string text2)
  {
    vector<vector<int>> dp(text1.length()+1,vector<int> (text2.length()+1,-1));
    for (int i = 0; i <= text1.length();i++)
    {
      for (int j = 0; j <= text2.length(); j++)
      {
        if (i == 0 || j == 0)
          dp[i][j] = 0;
        
        else
          dp[i][j] = (text1[i-1] == text2[j-1]) ? 1 + dp[i-1][j-1] : max(dp[i-1][j],dp[i][j-1]);
      }
    }
    return dp[text1.length()][text2.length()];
  }	

	public:
	int minOperations(string str1, string str2) 
	{ 
	    return str1.length() + str2.length() - 2*top_down_solution(str1,str2);
	    
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends