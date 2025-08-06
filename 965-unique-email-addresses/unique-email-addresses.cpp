class Solution {
public:
    int numUniqueEmails(vector<string>& emails) 
    {

        for(int i = 0; i < emails.size(); ++i)
        {
            string dummy;
            bool before_at = true;
            bool first_plus = false;
            for(int j = 0; j < emails[i].size(); ++j) //front for ignoring dots until I find an @
            {
                if(emails[i][j] == '@')
                {
                    before_at = false;
                }
                if(before_at && emails[i][j] == '.')
                {
                    continue;
                }
                dummy.push_back(emails[i][j]);
            } 
            emails[i] = dummy;
            dummy.clear();
            before_at = true;
            first_plus = false;
            for(int j = 0; j < emails[i].size(); ++j) //front for the first + sign
            {
                if(emails[i][j] == '@')
                {
                    before_at = false;
                }
                if(emails[i][j] == '+' && !first_plus)
                {
                    first_plus = true;
                }
                if(first_plus && before_at)
                {
                    continue;
                }
                dummy.push_back(emails[i][j]);
            } 
            emails[i] = dummy;
            dummy.clear();
        }
        sort(emails.begin(), emails.end());
        int distinct = 1;
        string visited = emails[0];
        for(int i = 1; i < emails.size(); ++i)
        {
                if(emails[i] == visited)
                {
                    continue;
                }
                else
                {
                    distinct++;
                    visited = emails[i];
                }
        }
        return distinct;
    }
};