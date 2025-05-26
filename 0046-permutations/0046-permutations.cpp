 class Solution {
 	vector<vector<int>> res_;
 	void dfs(int begin, int size, vector<int>& nums){
 		if(begin >= size){
 			res_.push_back(nums);
 			return;
 		}else{
 			for(int i = begin; i < size; ++i){
 				swap(nums[begin], nums[i]);
 				dfs(begin + 1, size, nums);
 				swap(nums[begin], nums[i]);
 			}
 		}
 	}
 public:
 	vector<vector<int>> permute(vector<int>& nums) {
 		dfs(0, nums.size(), nums);
 		return res_;
 	}
 };