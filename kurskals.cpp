#include <bits/stdc++.h>
using namespace std;
//kurskals algorithm
struct Node
{
    int parent;
    int rank;
};

struct Edge
{
    int src;
    int dst;
    int wt;
};

vector<Node> dsuf;
vector<Edge> mst;

bool compare(Edge a, Edge b)
{
    return a.wt < b.wt;
}

int find(int v)
{
    if (dsuf[v].parent == -1)
        return v;

    return dsuf[v].parent = find(dsuf[v].parent);
}

void union_op(int fromP, int toP)
{

    if (dsuf[fromP].rank < dsuf[toP].rank)
    {
        dsuf[toP].parent = fromP;
    }
    else if (dsuf[fromP].rank > dsuf[toP].rank)
    {
        dsuf[fromP].parent = toP;
    }
    else
    {
        dsuf[fromP].parent = toP;
        dsuf[toP].rank += 1;
    }
}

void kurskal(vector<Edge> &edge_list, int V, int E)
{

    int i = 0, j = 0;

    while (i < V - 1 && j < E)
    {
        int fromP = find(edge_list[j].src);
        int toP = find(edge_list[j].dst);

        if (fromP == toP)
        {
            ++j;
            continue;
        }

        union_op(fromP, toP);
        mst.push_back(edge_list[j]);
    }
}

void printMST(vector<Edge>mst){

for(auto it:mst){
    cout<<"src: "<<it.src <<"dst: "<<it.dst<<endl;
}
}
int main()
{
    int E, V;
    cin >> V >> E;

    dsuf.resize(V);
    for(int i = 0 ; i<V ; i++){
        dsuf[i].parent = -1;
        dsuf[i].rank = 0;
    }

    vector<Edge> edge_List;
    Edge temp ;

    for(int i =0 ;i < E ; i++){
        int from , to ,wt;
        cin >> from >> to >> wt;
        temp.src = from;
        temp.dst = to;
        temp.wt = wt;
        edge_List.push_back(temp);
    }
    kurskal(edge_List,V,E);
    printMST(mst);
    return 0;
}
