class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1;
        int ans=0;
        int maxi1=0,maxi2=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>maxi1){
                    maxi1=height[left];
                }
                else{
                    ans+=maxi1-height[left];
                }
                left++;
            }
            else{
                if(height[right]>maxi2){
                    maxi2=height[right];
                }
                else{
                    ans+=maxi2-height[right];
                }
                right--;
            }
        }
        return ans;
    }
};
