vector<int> nextSmallerElement(vector<int> arr, int n)

{

    stack<int> s;

    vector<int> ans(n);

    s.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {

        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] >= curr)
        {

            s.pop();
        }

        ans[i] = s.top();

        s.push(i);
    }

    return ans;
}

vector<int> prevSmallerElement(vector<int> arr, int n)

{

    stack<int> s;

    vector<int> ans(n);

    s.push(-1);

    for (int i = 0; i < n; i++)
    {

        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] >= curr)
        {

            s.pop();
        }

        ans[i] = s.top();

        s.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int> &heights, int n)
{

    vector<int> next(n);

    next = nextSmallerElement(heights, n);

    vector<int> prev(n);

    prev = prevSmallerElement(heights, n);

    int area = 0;

    for (int i = 0; i < n; i++)
    {

        int length = heights[i];

        if (next[i] == -1)
        {

            next[i] = n;
        }

        int breadth = (next[i] - prev[i] - 1);

        int new_area = length * breadth;

        area = max(new_area, area);
    }

    return area;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &M, int n, int m)
{

    int area = largestRectangleArea(M[0], m);

    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            if (M[i][j] != 0)

                M[i][j] += M[i - 1][j];

            else

                M[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {

        area = max(largestRectangleArea(M[i], m), area);
    }

    return area;
}