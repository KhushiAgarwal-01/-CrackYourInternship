class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=1;
        while(r<n){
            if(nums[l]==0 && nums[r]!=0){
                swap(nums[r],nums[l]);
                l++;
                r++;
            }else if(nums[l]==0 && nums[r]==0 && r<n-1){
                r++;

            }
            else {
                l++;
                r++;
            }
        }
    }
};