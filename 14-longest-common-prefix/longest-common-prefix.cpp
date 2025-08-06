class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string commonPrefix = strs[0];
        int counter = 0;
        for(int i = 1; i < strs.size(); ++i)
        {
            if(strs[i] == "") return "";
            for(int j = 0; j < strs[i].size(); ++j)
            {
                counter = 0;
                while( (j < strs[i].size()) &&  (j < commonPrefix.size()) && commonPrefix[j] == strs[i][j])
                {
                    j++;
                    counter++;
                }
                break;
            }
            commonPrefix = commonPrefix.substr(0, counter);
        }
        return commonPrefix;
    }
};