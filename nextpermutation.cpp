class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
		
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                sort(nums.begin()+i+1, nums.end());
                auto it = upper_bound(nums.begin()+i+1, nums.end(), nums[i]);
                swap(*it, nums[i]);
                sort(nums.begin()+i+1, nums.end());
                return ;
            }
        }
        sort(nums.begin(), nums.end());
        return;
    }
};
