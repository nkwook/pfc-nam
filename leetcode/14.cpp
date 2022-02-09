class Solution
{

    // think about readable code.... simple is the best
    // simple idea but can be messed up, always have to check logics, data structure
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int i = 0;
        string ans = "";
        bool condition = true;
        char target;
        while (condition && i < strs[0].size())
        {
            target = strs[0][i];
            for (int j = 0; j < strs.size(); j++)
            {
                if (strs[j][i] != target)
                {
                    condition = false;
                    break;
                }
            }
            if (condition)
            {
                i++;
                ans += target;
            }
        }

        return ans;
    }
};