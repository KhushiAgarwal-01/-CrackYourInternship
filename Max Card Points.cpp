class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxi=0;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        maxi=sum;
        int l=k-1;
        int r=cardPoints.size()-1;
        for(int i=0;i<k;i++){
            sum-=cardPoints[l];
            sum+=cardPoints[r];
            maxi=max(maxi,sum);
            l--;
            r--;
        }
        return maxi;
    }
};