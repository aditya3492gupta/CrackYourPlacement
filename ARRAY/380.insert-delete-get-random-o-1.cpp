/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
class RandomizedSet
{
public:
    vector<pair<int, int>> a;
    unordered_map<int, vector<int>> mp;

    RandomizedCollection()
    {
    }

    bool insert(int val)
    {
        auto it = mp.find(val);
        if (it == mp.end())
        {
            mp[val].push_back(a.size());
            a.push_back(make_pair(val, mp[val].size() - 1));
            return true;
        }
        else
        {
            mp[val].push_back(a.size());
            a.push_back(make_pair(val, mp[val].size() - 1));
            return false;
        }
    }

    bool remove(int val)
    {
        auto it = mp.find(val);
        if (it != mp.end())
        {
            auto last = a.back();
            mp[last.first][last.second] = mp[val].back();
            a[mp[val].back()] = last;
            mp[val].pop_back();
            if (mp[val].empty())
                mp.erase(val);
            a.pop_back();
            return true;
        }
        return false;
    }

    int getRandom()
    {
        return a[rand() % a.size()].first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
