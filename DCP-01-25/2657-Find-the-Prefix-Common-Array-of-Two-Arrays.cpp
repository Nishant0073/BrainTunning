class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
         unordered_map<int,bool> mpA;
         unordered_map<int,bool> mpB;
        int cnt = 0;
        vector<int> result;
        for(int i=0;i<A.size();i++){
            int eleFromA = A[i];
            int eleFromB = B[i];
            mpA[eleFromA] = true;
            mpB[eleFromB] = true;
            if(mpB[eleFromA]==true){
                cnt++;
            }
            if(mpA[eleFromB]==true && eleFromA!=eleFromB){
                cnt++;
            }
            
            result.push_back(cnt);
        }
        return result;
    }
};
