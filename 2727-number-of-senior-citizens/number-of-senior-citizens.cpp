class Solution {
public:
    int countSeniors(vector<string>& details) 
    {
        int counter = 0;
        for (auto it : details)
        {
            string age = "";
            age.push_back(it[11]);
            age.push_back(it[12]);
            if(stoi(age) > 60) counter++;
        }
        return counter;
    }
};