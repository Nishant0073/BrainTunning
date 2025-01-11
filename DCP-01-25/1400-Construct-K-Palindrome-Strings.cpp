class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n==k)
            return true;

        if(k>n)
            return false;

        vector<int> v(26,0);

        for(int i=0;i<n;i++){
            v[s[i]-'a']++;
        }
        
        int  OddCount = 0;
        for(int i=0;i<26;i++){
            if(v[i]%2!=0){
                OddCount+=1;
            }
        }

        return OddCount<=k;
    }
};