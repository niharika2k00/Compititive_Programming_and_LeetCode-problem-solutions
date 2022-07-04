/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
class MyHashMap
{
public:
    vector<int> vec;
    MyHashMap()
    {
        vec.resize(1e6 + 1, -1);
    }

    void put(int key, int value)
    {
        vec[key] = value;
    }

    int get(int key)
    {
        // if (vec[key])
        return vec[key];
    }

    void remove(int key)
    {
        vec[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
