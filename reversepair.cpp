class Solution {
    void merge(int l,int m,int h,vector<int>&nums){
        vector<int>temp;
        int i=l;
        int j=m+1;
        while(i<=m && j<=h ){
            if(nums[i]>nums[j]){
                temp.push_back(nums[j]);
                j++;
            }else {
                temp.push_back(nums[i]);
                i++;
            }
        }

        while(i<=m){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=h){
            temp.push_back(nums[j]);
            j++;
        }

        for(int i=l;i<=h;i++){
            nums[i]=temp[i-l];
        }
    }

    int countpairs( int low, int mid, int high,vector<int> &arr) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high && arr[i] > 2 * arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

    int mergesort(int i,int j,vector<int>&nums){
        int cnt=0;
        if(i>=j){
            return cnt;
        }
        int m =(i+j)/2;
        cnt+=mergesort(i,m,nums);
        cnt+=mergesort(m+1,j,nums);
        cnt+=countpairs(i,m,j,nums);
         merge(i,m,j,nums);
         return cnt;
    }

public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
    //     int cnt=0;
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //         if(nums[i]>2*nums[j]){
    //             cnt+=1;
              
    //         }
    //       }
    //     }
    // return cnt;
    return mergesort(0,n-1,nums);

    }
};