public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int,int> mp = new Dictionary<int,int>();
        for(int i=0;i<nums.Length;i++){
            int rem = target - nums[i];
            if(mp.ContainsKey(rem)){
                return [mp[rem],i];
            }
            mp[nums[i]] = i;
        }
        return [];
    }
}