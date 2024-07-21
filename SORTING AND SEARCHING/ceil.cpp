pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    // Write your code here.
    int low = 0;
    int high = n - 1;
    int floor = INT_MIN;
    int ceil = INT_MAX;
    while (low <= high)
    {

        int mid = (high + low) / 2;

        if (a[mid] <= x)
        {

            floor = max(floor, a[mid]);

            low = mid + 1;
        }

        if (a[mid] >= x)
        {

            ceil = min(ceil, a[mid]);

            high = mid - 1;
        }
    }

    if (floor == INT_MIN)
    {
        floor = -1;
    }
    if (ceil == INT_MAX)
        ceil = -1;
    return {floor, ceil};
}