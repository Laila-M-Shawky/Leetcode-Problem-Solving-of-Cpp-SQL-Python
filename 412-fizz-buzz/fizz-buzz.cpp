class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> lol;
        for (int i = 0; i < n; ++i)
        {
            if ( ((i + 1) % 3 == 0) && ((i + 1) % 5 == 0) )
                lol.push_back("FizzBuzz");

            else if  ((i + 1) % 5 == 0) 
                lol.push_back("Buzz");

            else if  ((i + 1) % 3 == 0) 
                lol.push_back("Fizz");

            else
                lol.push_back(to_string(i + 1));
        }
        return lol;
    }
};