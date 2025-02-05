class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size()!=s2.size())
            return false;

        int n = s1.size();
        int cnt  = 0;
        vector<int> v;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                v.push_back(i);
                cnt++;
            }
        }
        if(cnt>2 || cnt==1)
            return false;
        
        return  cnt==0 ? true : (s1[v[0]]==s2[v[1]] && s2[v[0]]==s1[v[1]]);
    }
};