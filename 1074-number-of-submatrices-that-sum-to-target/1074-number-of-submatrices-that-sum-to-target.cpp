class Solution
{
    public:
        int numSubmatrixSumTarget(vector<vector < int>> &matrix, int target)
        {

            for (int i = 0; i < matrix.size(); i++)
                for (int j = 1; j < matrix[0].size(); j++)
                    matrix[i][j] += matrix[i][j - 1];

            // for (int i = 1; i < matrix.size(); i++)
            //     for (int j = 0; j < matrix[0].size(); j++)
            //         matrix[i][j] += matrix[i - 1][j];

//             int count = 0;
//             for (int i = 0; i < matrix.size(); i++)
//             {
//                 for (int j = 0; j < matrix[0].size(); j++)
//                 {
//                    	// Iterating over the starting point
//                     for (int m = i; m < matrix.size(); m++)
//                     {
//                         for (int n = j; n < matrix[0].size(); n++)
//                         {
//                            	// Iterating over the ending point
//                             int answer = matrix[m][n];

//                             if (i)
//                                 answer -= matrix[i - 1][n];

//                             if (j)
//                                 answer -= matrix[m][j - 1];

//                             if (i && j)
//                                 answer += matrix[i - 1][j - 1];

//                             if (target == answer)
//                                 count++;
//                         }
//                     }
//                 }
//             }
          
          // unordered_map<int,int> freqmap;
          int count = 0;
          
          for (int start = 0; start < matrix[0].size(); start++)
          {
            for (int end = start; end < matrix[0].size(); end++)
            {
              unordered_map<int,int> freqmap;
              freqmap[0]++;
              int sum = 0;
              for (int row = 0; row < matrix.size(); row++)
              {
                sum += matrix[row][end];
                
                if (start)
                  sum -= matrix[row][start-1];
                
                count += freqmap[sum - target];
                freqmap[sum]++;
                
                // cout << start << "   " << end << "    " << count << endl;
              }
            }
          }
          
          return count;
        }
};