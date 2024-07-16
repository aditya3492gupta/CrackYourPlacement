class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            int cnt = 0;
            for (auto i : nums)
            {
                if (i <= m)
                    cnt++;
            }
            if (cnt > m)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};