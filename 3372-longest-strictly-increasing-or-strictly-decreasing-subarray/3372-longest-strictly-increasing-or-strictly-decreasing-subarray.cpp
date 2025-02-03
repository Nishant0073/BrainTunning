class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int longInc = 1;
        int longDec = 1;
        for(int i=1;i<nums.size();i++){

            if(nums[i]>nums[i-1]){
                longInc++;
                longDec = 1;
            }
            else if(nums[i]<nums[i-1]){
                longDec++;
                longInc = 1;
            }
            else{
                longDec = 1;
                longInc = 1;
            }

            ans = max(ans,max(longInc,longDec));
        }
        return ans;
    }
};