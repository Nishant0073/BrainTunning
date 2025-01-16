class Solution {
public:
    int getXor(vector<int> &num){
        int result = 0;
        for(int i=0;i<num.size();i++)
        {
            result = result ^ num[i];
        }
        return result;
    }
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;

        int n = nums1.size();
        int m = nums2.size();

        if(n%2!=0){
            result = result ^ getXor(nums2);
        }
        if(m%2!=0){
            result = result ^ getXor(nums1);
        }
        return result;

    }
};