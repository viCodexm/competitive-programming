#include <iostream>
#include <vector>
using namespace std;

struct Stack{
    int *volume, last = -1;
    Stack(int size){
        volume = new int[size];
    }
    void push(int x){
        ++last;
        volume[last] = x;
    }
    int top(){
        return volume[last];
    }
    void pop(){
        --last;
    }
};

int main()
{
    // 2 строки ниже значительно ускоряют время работы проги
    std::cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, u, v;
    cin >> n;
    
    //Ввод графа (список смежности)
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; ++i){
        cin >> u >> v;
        --u; --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
   
    //DFS  
    #define WHITE 0
    #define GRAY 1
    #define BLACK 2
            
    int parent[n]{0}, used[n]{1};
    bool hasCycle = false, needNextIter = false;
    Stack cycle(n);
  
    cycle.push(0);
    while (true){
        u = cycle.top();
        used[u] = GRAY;
        for (auto &v: graph[u]){
           if (parent[u] != v){
                if (used[v] == WHITE){
                    parent[v] = u;
                    cycle.push(v);
                    needNextIter = true;
                    break;
                }
                else if(used[v] == GRAY){
                    u = v;
                    hasCycle = true;
                    break;
                }
            }
        }
        if (hasCycle)
            break;
        if (needNextIter){
            needNextIter = false;
            continue;
        }
        used[u] = BLACK;
        cycle.pop();
    }
   
    //Считаем длину цикла и выводим сам цикл   
    int i = cycle.last, len_cycle = 1;
    while (cycle.volume[i] != u){
        ++len_cycle;
        --i;
    }
    cout << len_cycle << "\n";
    
    i = cycle.last;
    cout << cycle.volume[i] + 1 << " " << u + 1 << "\n";
    while (cycle.volume[i] != u){
        cout << cycle.volume[i] + 1 << " " << cycle.volume[i - 1] + 1 << "\n";
        --i;
    }
    
    return 0;
}