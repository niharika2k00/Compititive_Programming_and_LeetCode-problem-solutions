/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start

/*
        LOGIC / APPROACH
     -----------------------
   #  Some Words are given , push them into the HashMap
   #  Then Search WORD from the input array to find whether they EXIST in the HashMap or NOT

    b..
    c.t

           means any letter can be placed in that '.' position.
           So if cat is present in the HashMap , then RETURN True for c.t
 */
class WordDictionary
{
    unordered_map<int, vector<string>> hashMap; // length ,  word

public:
    WordDictionary()
    {
    }

    void addWord(string word)
    {
        int len = word.length();
        hashMap[len].push_back(word);
    }

    bool search(string word)
    {
        bool flag = false;
        int len = word.length();

        for (auto ele : hashMap[len])
        {
            flag = true;
            for (int i = 0; i < len; i++)
            {
                if (ele[i] != word[i] && word[i] != '.')
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
                break;
        }

        if (flag)
            return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
