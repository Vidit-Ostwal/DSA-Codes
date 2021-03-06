// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    /*Time Complexity = O(2^N) Recursive Tree
    Sapce Comlplexity = O(N) Height of recursion tree*/
    int recursive_solution (int left_weigth, int wt[], int val[], int index)
    {
        /*Base Condiditon*/
        if (index <0)
        return 0;
        
        /*Case when current weight is higher*/
        if (wt[index] > left_weigth)
        return recursive_solution(left_weigth,wt,val,index-1);
        
        else
        {
            return max(val[index]+recursive_solution(left_weigth - wt[index],wt,val,index),
            recursive_solution(left_weigth,wt,val,index-1));
        }
    }
    
    /*Complexity Analysis: 
    Time Complexity: O(N*W).
    where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
    Auxiliary Space: O(N*W).
    The use of 2-D array of size ‘N*W’.*/
    int memozization_solution (int left_weigth, int wt[], int val[], int index,vector<vector<int>> &memozise)
    {
        /*Base Condiditon*/
        if (index <0)
        return 0;
        
        /*Solution might be already calculated*/
        if (memozise[left_weigth][index] != -1)
        {
            return memozise[left_weigth][index];
        }
        
        /*Case when current weight is higher*/
        if (wt[index] > left_weigth)
        return memozise[left_weigth][index] = memozization_solution(left_weigth,wt,val,index-1,memozise);
        
        else
        {
            return memozise[left_weigth][index] = max(val[index]+memozization_solution(left_weigth - wt[index],wt,val,index,memozise),
            memozization_solution(left_weigth,wt,val,index-1,memozise));
        }
    }
    
    /*Top -Down Appraoch
    Complexity Analysis: 
    Time Complexity: O(N*W).
    where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
    Auxiliary Space: O(N*W).
    The use of 2-D array of size ‘N*W’.
    Mostly both Memozization solution and top_down_solution will have same complexity.*/
    int top_down_solution (int W, int wt[], int val[], int n)
    {
        vector<vector<int>> memozise(n+1,vector<int>(W+1));
       
       for (int a = 0; a <= n; a++)
       {
           for (int b = 0; b <= W;b++)
           {
               if (a == 0 || b == 0)
               memozise[a][b] = 0;
               
               else if (wt[a-1] <=  b)
               memozise[a][b] = max(val[a-1] + memozise[a][b-wt[a-1]],memozise[a-1][b]);
               
               else
               memozise[a][b] = memozise[a-1][b];
           }
       }
       return memozise[n][W];
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> memozise(W+1,vector<int>(N+1,-1));
        return memozization_solution(W,wt,val,N-1,memozise);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends