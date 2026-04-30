class Solution {
public:

    string encode(vector<string>& strs) 
    {
        string encoded = "";

        for (string str : strs)
        {
            for (char c : str)
            {
                encoded += c;
            }

            encoded += "<NEXT>";
        }

        return encoded;
    }

    vector<string> decode(string s)
    {
        vector<string> decoded;

        string curStr = "";
        for (int index=0;index<s.size();index++)
        {
            if (s[index] == '<')
            {
                if (index + 5 < s.size() && s.substr(index, 6) == "<NEXT>")
                {
                    decoded.push_back(curStr);
                    curStr = "";
                    index += 5;
                }
                else
                {
                    curStr += s[index];
                }
            }
            else
            {
                curStr += s[index];
            }
        }

        return decoded;
    }
};

/*

basically need a viable delimiter.

*/