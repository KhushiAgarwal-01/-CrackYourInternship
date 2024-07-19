class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        
int n=arr.size();
 vector<vector<int>> ans;
sort(arr.begin(),arr.end());
 for(int i=0;i<n;i++)
 {
     if(i>0 && arr[i-1]==arr[i])
     {
         continue;
     }

     for(int j=i+1;j<n;j++)
     {
         if(j>i+1 && arr[j-1]==arr[j])
         {
             continue;
         }

         int k=j+1;
         int l=n-1;

         while(k<l){
        //    int sum=arr[i]+arr[j]+arr[k]+arr[l];
            long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];
             if(sum>target)
             {
                 l--;
             }
             else if(sum<target)
             {
                 k++;

             }
             else{
                  vector<int>temp={arr[i],arr[j],arr[k],arr[l]};
                     ans.push_back(temp);

                     k++;
                     l--;
                     while(k<l && arr[k-1]==arr[k])
                     {
                         k++;
                     }
                     while(k<l && arr[l]==arr[l+1])
                     {
                         l--;
                     }

             }
         }
     }
 }
return ans;
    }
};