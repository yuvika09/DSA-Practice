#include <bits/stdc++.h>
using namespace std;

// Approach1- Using struct
struct meeting
{
    int start;
    int end;
    int pos;
};
bool comp(meeting m1, meeting m2)
{
    if (m1.end < m2.end)
    {
        return true;
    }
    else if (m1.end = m2.end)
    {
        if (m1.pos < m2.pos)
        {
            return true;
        }
        return false;
    }
    return false;
}
vector<int> maxMeetings1(int st[], int e[], int n)
{
    struct meeting meet[n];
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        meet[i].start = st[i];
        meet[i].end = e[i];
        meet[i].pos = i + 1;
    }
    sort(meet, meet + n, comp);

    int endLimit = meet[0].end;
    ans.push_back(meet[0].pos);
    for (int i = 1; i < n; i++)
    {
        if (meet[i].start > endLimit)
        {
            endLimit = meet[i].end;
            ans.push_back(meet[i].pos);
        }
    }
    return ans;
}

// Approach2 - Using vector pair
int maxMeetings2(int start[], int end[], int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({end[i], start[i]});
    }
    sort(v.begin(), v.end());
    int count = 1;
    int endLimit = v[0].first;
    for (int i = 1; i < n; i++)
    {
        if (endLimit < v[i].second)
        {
            count++;
            endLimit = v[i].first;
        }
    }
    return count;
}

int main()
{
    int start[] = {1, 0, 3, 8, 5, 8};
    int end[] = {2, 6, 4, 9, 7, 9};
    int size = sizeof(start) / sizeof(start[0]);

    vector<int> ans = maxMeetings1(start, end, size);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << maxMeetings2(start, end, size);
    return 0;
}