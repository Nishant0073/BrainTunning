class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mp;
        int cnt =0;
        vector<int> result;
        for(int i=0;i<A.size();i++){
            int eleFromA = A[i];
            int eleFromB = B[i];
            mp[eleFromA]++;
            mp[eleFromB]++;
            if(mp[eleFromA]==2){
                cnt++;
            }
            if(mp[eleFromB]==2 && eleFromB!=eleFromA){
                cnt++;
            }
            result.push_back(cnt);
        }
        return result;
    }
};

