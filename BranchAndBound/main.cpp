#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Item
{
    // Масса
    int m;
    // Стоимость
    int c;
    // Ценность
    double e;
    // Индекс
    int index;
};

struct Node
{
    // Оценка
    double estimation;
    // Уровень
    int level;
    // Список предметов
    vector<Item> taken_items;
    // Текущая масса
    int m;
    // Текущая стоимость
    int c;
};

// Правило для сравнения вершин
struct NodeCompare
{
    bool operator() (const Node& n1, const Node& n2) 
    {
        return n1.estimation < n2.estimation;
    }
};


int main()
{
    // Количество предметов
    int N;
    // Вместимость
    int M;
    
    cin >> N >> M;

    // Общий список предметов
    vector<Item> items(N);

    priority_queue<Node, vector<Node>, NodeCompare> pq;

    Node node0;
    node0.estimation = 0;
    node0.level = 0;
    node0.m = 0;
    node0.c = 0;

    pq.push(node0);

    for (int i = 0; i < N; i++)
    {
        cin >> items[i].m;
        items[i].index = i;
    }

    for (int i = 0; i < N; i++)
    {
        cin >> items[i].c;
        items[i].e = (double) items[i].c / items[i].m;
    }

    // Сортировка по убыванию ценности
    sort(items.begin(), items.end(), [](Item a, Item b){ return a.e > b.e; });

    int level = 0;
    Node n;
    Node new_node;
    while (true)
    {
        new_node = pq.top();
        pq.pop();
        if (new_node.level == N + 1)
        {
            if (new_node.estimation != -1)
                break;
            continue;
        }
        // l - "условно" левое поддерево - очередной предмет берется
        Node l;
        // r - "условно" правое поддерево - очередной предмет не берется
        Node r;
        n = new_node;
        int k = n.level;

        l.m = n.m + items[k].m;
        l.c = n.c + items[k].c;
        l.level = k + 1;
        l.taken_items = n.taken_items;
        l.taken_items.push_back(items[k]);
        if (l.m <= M)
        {
            l.estimation = l.c + (M - l.m) * items[k + 1].e;
        }
        else
        {
            l.estimation = -1;
        }

        r.m = n.m;
        r.c = n.c;
        r.level = k + 1;
        r.taken_items = n.taken_items;
        if (r.m <= M)
        {
            r.estimation = r.c + (M - r.m) * items[k + 1].e;
        }
        else
        {
            r.estimation = -1;
        }

        pq.push(l);
        pq.push(r);
    }

    auto res = n.taken_items;
    sort(res.begin(), res.end(), [](Item a, Item b){ return a.index < b.index; });
    if (res.size() == 0)
    {
        cout<<"Ничего не влезло"<<endl;
    }
    else for (const auto& x : res)
    {
        cout<<x.index + 1<<' ';
    }

    cout << endl;
}