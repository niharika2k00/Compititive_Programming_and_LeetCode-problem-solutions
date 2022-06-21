

// https://takeuforward.org/data-structure/count-the-number-of-subarrays-with-given-xor-k/

// https://www.codingninjas.com/codestudio/problems/1115652?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

int subarraysXor(vector<int> &arr, int x)
{
    int len = arr.size(), prefixXor = 0, count = 0;
    unordered_map<int, int> map;

    for (int i = 0; i < len; i++)
    {
        prefixXor = prefixXor ^ arr[i];

        if (prefixXor == x)
            count++;

        if (map.find(prefixXor ^ x) != map.end())
            count = count + map[prefixXor ^ x];

        map[prefixXor]++;
    }

    return count;
}