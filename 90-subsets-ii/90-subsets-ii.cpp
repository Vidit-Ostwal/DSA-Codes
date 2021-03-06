class Solution {
public:
  
  vector<vector<int>> convertToSet(vector<vector<int>> prev_vector)
{
    // Declaring the  set
   set<vector<int>> s(prev_vector.begin(),prev_vector.end());
   vector<vector<int>> final_vector(s.begin(),s.end());
    
    return final_vector;
}
  
  
    /*Approach 1*/
  vector<vector<int>> get_all_subsets(vector<int>&nums,int index,vector<int> prev_vector)
  {
    if (index == nums.size())
    {
      vector<vector<int>> temp_vector;
      temp_vector.push_back(prev_vector);
      return temp_vector;
    }
    
    vector<vector<int>> first_vector = get_all_subsets(nums,index+1,prev_vector);
   
    prev_vector.push_back(nums[index]);
    vector<vector<int>> second_vector = get_all_subsets(nums,index+1,prev_vector);
    
    first_vector.insert(first_vector.end(),second_vector.begin(),second_vector.end());
    
    return convertToSet(first_vector);
  }
  
  
  void get_all_subsets_void(vector<int>&nums,int index,vector<int> prev_vector,vector<vector<int>> & final_vector)
  {
    if (index == nums.size())
    {
      final_vector.push_back(prev_vector);
      return ;
    }
    
    get_all_subsets_void(nums,index+1,prev_vector,final_vector);
   
    prev_vector.push_back(nums[index]);
    get_all_subsets_void(nums,index+1,prev_vector,final_vector);
  }
  
  
  /*Iterative Approach
  Only add elements to the newly made array when duplicated elements are found
  Also sort so that founding the repeated element is easy
  Time Complexity = O(N * 2^N)
  N iteration and 2^N for copying the elements
  Space Complexity = O(2^N  * N)
  */
  vector<vector<int>> iterative_approach(vector<int> nums)
  {
    vector<vector<int>> final_vector = {{}};
    vector<vector<int>> temp_vector(final_vector.begin(),final_vector.end());
    for (int i = 0; i < nums.size(); i++)
    {
      if (i > 0 && nums[i-1] != nums[i])
      {
        temp_vector = final_vector;
      }
      for (int j= 0 ;j< temp_vector.size(); j++)
      {
        temp_vector[j].push_back(nums[i]);
        final_vector.push_back(temp_vector[j]);
      }
    }
    return final_vector;
  }
  
  
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      sort(nums.begin(),nums.end());
        return iterative_approach(nums);
    }
};