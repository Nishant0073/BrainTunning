class Solution {
public:
    void setDigits(vector<char> & chars,int cnt,int& index){
        if(cnt>=2){
            string s = \\;
            while(cnt>0){
                s+= ('0' + (cnt%10));
                cnt = cnt/10;
            }
            for(int i=s.size()-1;i>=0;i--){
                chars[index++]=s[i];
            }
        }
    }
    int compress(vector<char>& chars) {
        char ch = chars[0];
        int cnt = 1;
        int index = 0;
        for(int i=1;i<chars.size();i++){
            if(chars[i]!=ch){
                chars[index++] = ch;
                setDigits(chars,cnt,index);
                cnt = 0;
            }
            ch = chars[i];
            cnt++;
        }

        chars[index++] = ch;
        setDigits(chars,cnt,index);
        return index;
    }
};
