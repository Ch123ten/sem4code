#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define N 100

class graph{
    set<vector<int>>s;
    vector<vector<int>>adj[N];
    int m,n;


    public:
    graph(int m,int n){
        this->m = m;
        this->n = n;
    }
    void addedge();
    int prims();
};
void graph :: addedge(){
    for(int i=0;i<n;i++){
        int p,q,r;
        cout<<"Enter vertices for connection : ";cin>>p>>q;          /////////////  1,2,3,4 
        cout<<"Enter weight for ("<<p<<","<<q<<") : ";  cin>>r;
        p--; q--;
        adj[p].push_back({q,r});
        adj[q].push_back({p,r});
    }
}
int graph :: prims(){
    int cost = 0;
    vector<bool>visit(N);
    vector<int>parent(N);
    vector<int>dist(N);
    for(int i=0;i<N;i++)   dist[i] = 99999;
    dist[0] = 0;
    s.insert({0,0});
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        visit[x[1]] = 1;
        int u = x[1];    int v = parent[x[1]];    int w = x[0];
        cout<<v+1<<" -> "<<u+1<<" , "<<w<<endl;
        cost+=w;
        for(auto it : adj[x[1]]){
            if(visit[it[0]]);
            else if(dist[it[0]] > it[1]){
                s.erase({dist[it[0]],it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]],it[0]});
                parent[it[0]] = x[1];
            }
        }
    }
    return cost;

}

int main(){
    int m,n;
    cout<<"Enter number of offices : ";  cin>>m;
    cout<<"Enter number of connections : ";  cin>>n;
    graph g(m,n);
    g.addedge();
    int cost = g.prims();
    cout<<endl<<"MINIMUM  COST : "<<cost<<endl;
}