class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int result = 0;

        for(auto it:derived){
            result = result ^ it;
        }   

        return result == 0;
    }
};