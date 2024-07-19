class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        map<int , int> mp;
        mp[0]=1;
        int count=0;

        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];

            int rem=sum-k;

            if(mp.find(rem)!=mp.end())
            {
             count=count+mp[rem];
            }
            mp[sum]+=1;

        }
        return count;
    }
};