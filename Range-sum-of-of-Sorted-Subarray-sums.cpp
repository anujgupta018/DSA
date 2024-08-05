class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod=1e9+7;
        int j=0,sum=0;
        int res[n*(n+1)/2];
        int k=0;
        while(j<n){
            sum=0;
            for(int i=j;i<n;i++){
                sum+=nums[i];
                res[k++]=sum;
            }
            j++;
        }
        sort(res,res+n*(n+1)/2);
        sum=0;
        for(int i=left-1;i<right;i++){
            sum=(sum+res[i])%mod;
        }
        return sum;
    }
};
