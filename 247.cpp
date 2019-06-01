#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#define  DFS_BLACK 1
#define  DFS_WHITE -1

using namespace std;
typedef vector<int> vi;

vector<vi> graph;
vi dfs_num, dfs_low, S, visited;
int dfsNumberCounter, numSCC;
set<string> mySet;
map<string,int> myMap;
map<int, string> nameMap;

void init(int nodes)
{
    graph.clear();
    graph.resize(nodes);
    dfs_num.resize(nodes);
    fill(dfs_num.begin(), dfs_num.end(), DFS_WHITE);
    dfs_low.resize(nodes);
    fill(dfs_low.begin(), dfs_low.end(), 0);
    visited.resize(nodes);
    fill(visited.begin(), visited.end(), 0);
}

void readGraph(int edges)
{
    myMap.clear();
    mySet.clear();
    int index = 0;

    string str1, str2;
    int node1, node2;

    for(int x=0; x<edges; x++)
    {
        cin>> str1 >> str2;

        if(mySet.find(str1) == mySet.end())
        {
            myMap[str1] = index;
            nameMap[index] = str1;
            mySet.insert(str1);
            index++;
        }
        if(mySet.find(str2) == mySet.end())
        {
            myMap[str2] = index;
            nameMap[index] = str2;
            mySet.insert(str2);
            index++;
        }
        node1 = myMap[str1];
        node2 = myMap[str2];
        graph[node1].push_back(node2);
    }
}

void tarjanSCC(int node)
{
    dfs_low[node] = dfs_num[node] = dfsNumberCounter++;
    S.push_back(node);
    visited[node] = 1;

    for(int x=0; x<graph[node].size(); x++)
    {
        if(dfs_num[graph[node][x]] == DFS_WHITE)
          tarjanSCC(graph[node][x]);
        if(visited[graph[node][x]])
            dfs_low[node] = min(dfs_low[node], dfs_low[graph[node][x]]);
    }

    if(dfs_low[node] == dfs_num[node])//This is the root
    {
        ++numSCC;
        while(1)
        {
            int v = S.back();
            S.pop_back();

            visited[v] = 0;

            if(node == v)
            {
                printf("%s\n", nameMap[v].c_str());
                break;
            }
            else
                printf("%s, ", nameMap[v].c_str());
        }
    }
}

int main()
{
    string str;
    int nodes, edges, casos = 1;
    bool flag = false;
    while(scanf("%d %d", &nodes, &edges))
    {
        if(!nodes && !edges)
           break;

        init(nodes);
        readGraph(edges);

        dfsNumberCounter = numSCC = 0;
        if(!flag)
           flag = true;
        else
            printf("\n");
        printf("Calling circles for data set %d:\n", casos++);
        for(int i=0; i<graph.size(); i++)
        {
            if(dfs_num[i] == DFS_WHITE)
               tarjanSCC(i);
        }
    }
return 0;
}
