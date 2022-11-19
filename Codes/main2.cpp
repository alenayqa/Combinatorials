#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n, M;
    cout<<"КОЛИЧЕСТВО ПРЕДМЕТОВ\n";
    cin >> n;
    vector<int> m(n);
    vector<int> c(n);
    vector<int> b(n+2);
    vector<bool> s(n, false);

    // cout<<"МАССЫ ПРЕДМЕТОВ\n";
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> m[i];
    // }
    // cout<<"СТОИМОСТИ ПРЕДМЕТОВ\n";
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> c[i];
    // }
    // cout<<"ВМЕСТИМОСТЬ\n";
    // cin>>M;

    int max_value = -1;
    vector<bool> max_sequence(n);

    int x = 0;
    for (int i = 0; i <= n; i++)
    {
        b[i] = i + 1;
    }
    while (x != n + 0)
    {

        // int new_value = 0;
        // int current_M = 0;

        for (int i = 0; i < n; i++)
        // {
            cout<<s[i]<<' ';
        //     if (s[i])
        //     {
        //         new_value += c[i];
        //         current_M += m[i];
        //     }
        // }
        cout<<endl;

        // if (current_M <= M && new_value > max_value)
        // {
        //     max_value = new_value;
        //     max_sequence = s;
        // }
        int idx = x;
        if (x==0)
        {
            x = b[0];
            b[0] = 1;
        }
        else
        {
            b[x - 1] = b[x];
            b[x] = b[x] + 1;
            x = 0;
        }

        // x = b[0];
        s[idx] = !s[idx];
        // b[0] = 1;
        // b[x - 1] = b[x];
        // b[x] = x + 1;
    }

    cout<<"Наибольшая допустимая ценность: " << max_value<<endl;
    cout<<"Предметы:\n";
    for (int i = 0; i < n; i++)
    {
        if (max_sequence[i])
        {
            cout<<i+1<<' ';
        }
    }
    cout<<endl;
    
}