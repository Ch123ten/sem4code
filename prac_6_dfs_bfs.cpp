#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;
#define N 50

class graph{
    map<string,int>landmark;
    vector<int>adj[N];
    bool visit[N];
    int m,n;        //  vertex   and   edge
    public:
    graph(int m,int n){  this->m = m;  this->n = n;   init();   }
    void init(){  for(int i=0;i<N;i++)   visit[i] = 0;     }
    void addvertex();
    void displayland(int);
    void displayall();
    void addedge();
    void bfs(int);
    void dfs(int);
};

void graph :: addvertex(){
    for(int i=0;i<m;i++){
    string s;cout<<"Enter the landmark "<<i<<": ";  if(i==0)  cin.ignore();   getline(cin,s);
    landmark.insert({s,i});
    }
}
void graph :: displayland(int i){
    map<string,int> :: iterator it = landmark.begin();
    for(it;it!=landmark.end();it++){
        if((*it).second==i)   cout<<(*it).first<<" ";
    }
}
void graph :: displayall(){
    for(int i=0;i<m;i++){
        //map<string,int> :: iterator it = landmark.begin();
        displayland(i);cout<<"-> ";
        vector<int> :: iterator it1 = adj[i].begin();
		for(it1;it1!=adj[i].end();it1++){
			displayland(*it1);
		}
        cout<<endl;
    }
}
void graph :: addedge(){
    for(int i=0;i<n;i++){
        cout<<"Enter the vertices for path : "; int p,q;cin>>p>>q;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }
}
void graph :: bfs(int n=0){
    queue <int>q;
    q.push(n);
    visit[n]=1;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        //visit[temp] = 1;
        displayland(temp);
        vector<int> :: iterator it = adj[temp].begin();
        for(it;it!=adj[temp].end();it++){
            if(!visit[*it]){
                visit[*it]=1;
                q.push(*it);
            }
        }
    }
    init();
    cout<<endl;
}
void graph :: dfs(int n=0){
    displayland(n);
    visit[n] = 1;
    vector<int> :: iterator it = adj[n].begin();
        for(it;it!=adj[n].end();it++){
            if(!visit[*it]){
                dfs(*it);
            }
        }
}


int main(){
    int m,n;
    cout<<"Enter the number of landmarks : ";cin>>m;
    cout<<"Enter the number of paths : ";cin>>n;
    graph g(m,n);
    g.addvertex();
    g.addedge();
    cout<<endl;
    while (true)
    {
        cout<<"1.bfs   2.dfs   3.diaplay all path   4.exit"<<endl<<"Enter choice : ";int ch;  cin>>ch;
        if(ch==1){
            g.bfs();  cout<<endl;
        }
        else if(ch==2){
            g.dfs();
            g.init();
            cout<<endl;
        }
        else if(ch==3){
            cout<<"All Paths are : "<<endl;
            g.displayall();
            cout<<endl;
        }
        else    break;
    }
    cout<<endl;
}