#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
vector<vector<int>> m;
vector<bool> visited;
int maxlen = 0;
int maxsequence[5];
int cursequence[5];

void dfs(int len, int vertex)
{
    if (len > 5 || visited[vertex])
    {
        return;
    }
    visited[vertex] = true;
    cursequence[len - 1] = vertex;

    for (int i = 0; i < n; i++)
    {
        if (i <= vertex) continue;
        bool correct = true;
        for (int j = 0; j < len; j++)
        {
            correct = correct && m[cursequence[j]][i];
        }
        if (correct)
        {
            dfs(len+1, i);
        }
    }

    if (len > maxlen)
    {
        maxlen = len;
        for (int i = 0; i < len; i++)
        {
            maxsequence[i] = cursequence[i]; 
        }
    }
    visited[vertex] = false;
}

bool inAnswer(int x)
{
    for (int i = 0; i < maxlen; i++)
    {
        if (maxsequence[i] == x)
        {
            return true;
        }
    }
    return false;
}


int main()
{
    cin>>n;

    m.resize(n, vector<int>(n));
    visited.resize(n, false);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        dfs(1, i);
    }

    int newGroup = 0;
    string result = "";
    for (int i = 0; i < n; i++)
    {
        if (inAnswer(i))
        {
            result += "1 ";
        }
        else
        {
            result += to_string(newGroup+2) + " ";
            newGroup++;
        }
    }
    cout<<newGroup + 1<<endl;
    cout<<result<<endl;

}