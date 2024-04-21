class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        int n1=nums1.size(),n2=nums2.size();
        vector<int>result;
        while(i!=n1&&j!=n2){
            if(nums1[i]<=nums2[j]){
                result.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i]>nums2[j]){
                result.push_back(nums2[j]);
                j++;
            }
        }
        while(i!=n1){
            result.push_back(nums1[i]);
            i++;
        }
        while(j!=n2){
            result.push_back(nums2[j]);
            j++;
        }
        int size=result.size();
        if(size%2==0){
            return (result[size/2-1]+result[size/2])/2.0;
        }
        else{
            return result[size/2];
        }
    }
};