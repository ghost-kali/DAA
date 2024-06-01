#include<bits/stdc++.h>
using namespace std;
//prims Algorithm
int main(){
	int N=4,m=4;
	vector<pair<int,int> > adj[N];


    adj[0].push_back({1,2});
    adj[0].push_back({2,1});
    adj[1].push_back({0,2});
    adj[1].push_back({3,4});
    adj[2].push_back({3,5});
    adj[2].push_back({0,1});
    adj[3].push_back({1,4});
    adj[3].push_back({2,5});
    int parent[N];
    int key[N];
    bool mstSet[N];

    for (int i = 0; i < N; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    int ansWeight = 0;
    for (int count = 0; count < N - 1; count++)
    {

        int u = pq.top().second;
        pq.pop();
        mstSet[u] = true;

        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v])
                parent[v] = u;
                pq.push({key[v],v});
            key[v] = weight;;
        }

    }


    for (int i = 1; i < N; i++){
        cout << parent[i] << " - " << i <<" \n";
        for(auto it: adj[parent[i]]){
            if(it.first==i){
                ansWeight+= it.second;
            }
        }
    }
      cout<<ansWeight<<endl;
	return 0;
}
