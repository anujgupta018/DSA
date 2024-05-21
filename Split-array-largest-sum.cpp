class Solution {
public:
    int ct(vector<int>&arr,int sum){
        int count=1;
        long long s=0;
        for(int i=0;i<arr.size();i++){
            if(s+arr[i]<=sum){
                s+=arr[i];
            }
            else{
                count+=1;
                s=arr[i];
            }
        }
        return count;
    }
    int f(vector<int>&arr,int n,int k){
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int s=ct(arr,mid);
            if(s>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
    int splitArray(vector<int>& nums, int k) {
        return f(nums,nums.size(),k);
    }
};
