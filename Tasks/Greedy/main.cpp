#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int lines[10];
int N, K;
bool minfound = false;
bool maxfound = false;
int minnum[110];
int maxnum[110];
int curnum[110];

void findmin(int n, int k)
{
    if (n > N || k > K || (n == N && k < K) || (k == K && n < N) || minfound)
    {
        return;
    }
    if (n == N && k == K)
    {
        minfound = true;
        for (int i = 0; i < N; i++)
        {
            minnum[i] = curnum[i];
        }
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (minfound) break;
        if (k + lines[i] + (N - n - 1)*2 > K || k + lines[i] + (N - n - 1)*7 < K)
        {
            continue;
        }
        curnum[n] = i;
        findmin(n + 1, k + lines[i]);
    }
}

void findmax(int n, int k)
{
    if (n > N || k > K || (n == N && k < K) || (k == K && n < N) || maxfound)
    {
        return;
    }
    if (n == N && k == K)
    {
        maxfound = true;
        for (int i = 0; i < N; i++)
        {
            maxnum[i] = curnum[i];
        }
        return;
    }
    for (int i = 9; i >= 0; i--)
    {
        if (maxfound) break;
        // Проверяем, что ответ достижим
        // Если все остальные цифры брать с наименьшим числом палочек,
        // то палочек не должно быть больше требуемого числа
        // Аналогично если брать цифры с наибольшим числом палочек,
        // то их по итогу не может быть меньше требуемого числа
        if (k + lines[i] + (N - n - 1)*2 > K || k + lines[i] + (N - n - 1)*7 < K)
        {
            continue;
        }
        curnum[n] = i;
        findmax(n + 1, k + lines[i]);
    }
}

int main()
{
    // Количества палочек в цифрах
    lines[0] = 6;
    lines[1] = 2;
    lines[2] = 5;
    lines[3] = 5;
    lines[4] = 4;
    lines[5] = 5;
    lines[6] = 6;
    lines[7] = 3;
    lines[8] = 7;
    lines[9] = 6;

    cin>>N>>K;

    for (int i = 1; i <= 9; i++)
    {
        if (minfound) break;
        curnum[0] = i;
        findmin(1, lines[i]);
    }

    for (int i = 9; i >= 1; i--)
    {
        if (maxfound) break;
        curnum[0] = i;
        findmax(1, lines[i]);
    }

    if (!minfound)
    {
        cout<<"NO SOLUTION"<<endl;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            cout<<minnum[i];
        }
        cout<<endl;
        for (int i = 0; i < N; i++)
        {
            cout<<maxnum[i];
        }
        cout<<endl;
    }

}