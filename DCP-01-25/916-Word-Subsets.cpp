class Solution {
public:
    bool universalOrNot(unordered_map<char,int> &mp1,unordered_map<char,int> &mp2){
        for(int i=0;i<26;i++){
            char ch = 'a'+i;
            if(mp1[ch]>mp2[ch]){
                return false;
            }
        }
        return true; 
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        //first create universal word count 
        unordered_map<char,int> mp;
        for(int i=0;i<words2.size();i++){
            unordered_map<char,int> mp2;
            string cword = words2[i];
            for(int j=0;j<cword.size();j++){
                mp2[cword[j]]++;
            }
            for(int i=0;i<26;i++){
                if(mp['a'+i]<mp2['a'+i]){
                    mp['a'+i] = mp2['a'+i];
                }
            }
        }
        vector<string> result;
        // count frq of each word in words1 
        for(int i=0;i<words1.size();i++){
            string cword = words1[i];
            unordered_map<char,int> mp1;
            for(char ch:cword){
                mp1[ch]++;
            }
            //check if current word is universal or not
            if(universalOrNot(mp,mp1)){
                result.push_back(cword);
            }
        }
        return result;
    }
};
