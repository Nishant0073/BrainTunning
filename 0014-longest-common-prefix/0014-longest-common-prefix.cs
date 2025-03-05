public class Solution
{
    public string LongestCommonPrefix(string[] strs)
    {
        if(strs.Length==1)
            return strs[0];

        string result = "";
        for (int i = 0; i < strs[0].Length; i++)
        {
            Char ch = strs[0][i];
            for(int j=1;j<strs.Length;j++){
                if(strs[j].Length<=i || strs[j][i]!=ch){
                    return result;
                }
            }
            result += ch;
        }
        return result;
    }
}