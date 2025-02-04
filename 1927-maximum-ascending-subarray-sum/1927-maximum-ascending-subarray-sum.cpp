class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int result =  sum;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                result = max(sum,result);
                sum = nums[i];
            }
            else{
                sum += nums[i];
            }
        }
        result = max(result,sum);
        return result;
    }
};