class Solution {
public:
    bool check(vector<int>& nums) {
        int startIndex = 0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                startIndex = i;
                break;
            }
        }
        cout<<startIndex<<endl;
        int prevElement = nums[startIndex];
        for(int i=1;i<n;i++){
            
            if(prevElement>nums[(startIndex+i)%n]){
                return false;
            }
            prevElement = nums[(startIndex+i)%n];
        }
        return true;
    }
};