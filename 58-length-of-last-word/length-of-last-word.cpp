class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        string lasty;
        long long siz = (s.length()) - 1;
        for(long long i = siz; i >= 0; --i)
        {
            while(i >= 0 && !isdigit(s[i]) && !isalpha(s[i]))
            {
                --i;
            }
            while(i >= 0 && (isdigit(s[i]) || isalpha(s[i])))
            {
                lasty.push_back(s[i]);
                --i;
            }
            if(lasty.size() != 0) break;
        }
        return lasty.size();
    }
};