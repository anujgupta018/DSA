
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(),hash[n+1];
        for(int i=0;i<n+1;i++){
            hash[i]=0;
        }
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for(int i=0;i<nums.size()+1;i++){
            if(hash[i]==0){
                return i;
            }
        }
        return -1;
    }
};