#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cctype>

#define  DFS_WHITE -1
#define  DFS_BLACK 1
#define  MAX 26

using namespace std;

typedef pair<int,int>ii;
typedef vector<int>vi;
typedef vector<ii>vii;

vector<vi>graph;
vi dfs_num;
vi vertices;
int totalNodesSG;

vector<int> readVertices(string cad)
{
vector<int> res;
    for(int u=0; u<cad.size(); u++)
        if(isalpha(cad[u]))
           res.push_back(cad[u] - 65);
return res;
}

bool nodeExist(int x)
{
    for(int z=0; z<vertices.size(); z++)
        if(vertices[z] == x)
           return true;
    return false;
}

void dfs(int node)
{
    if(nodeExist(node))
    {   totalNodesSG++;
        dfs_num[node] = DFS_BLACK;
        for(int x=0; x<graph[node].size(); x++)
            if(dfs_num[graph[node][x]] == DFS_WHITE)
               dfs(graph[node][x]);

    }
    else
        return;
}

int main()
{
//vector <pair<int,int> > edges;
string str;
int casos, CC;

scanf("%d", &casos);
while(casos--)
{
    graph.assign(MAX, vi());
    CC = 0;
    while(cin>>str)
    {
        if(str[0] == '*')
           break;
        int node1 = str[1] - 65;
        int node2 = str[3] - 65;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
        //ii p = make_pair(node1, node2);
        //edges.push_back(p);
    }
    cin>>str;
    vertices = readVertices(str);    dfs_num.assign(MAX, DFS_WHITE);
    int totalTrees, totalAcorn;
    totalTrees = totalAcorn = 0;
    for(int x=0; x<graph.size(); x++)
    {
        if(nodeExist(x) && dfs_num[x] == DFS_WHITE)
        {
            totalNodesSG = 0;
            dfs(x);
            if(totalNodesSG > 1)
               totalTrees++;
            else if(totalNodesSG == 1)
                    totalAcorn++;
        }
    }
    printf("There are %d tree(s) and %d acorn(s).\n", totalTrees, totalAcorn);
}
return 0;
}
