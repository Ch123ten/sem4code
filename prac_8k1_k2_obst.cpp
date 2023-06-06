#include<iostream>
using namespace std;
#define N 50

struct node{
    int freq, key;
    node * right;  node * left;
    node (int k,int f){
        freq = f;   key  = k;   left = right = NULL;
    }
};

class obst{
    int dist[N][N];
    int keys[N][N];
    int vertex[2][N];
    int m;
    public:
    obst(int n){
         m = n+1;    
    }
    void addvertex();           /////////////
    void prims();            //////////////////
    node * create(node *,int ,int );
    node * insert(node *,int ,int);
    int costis(node *,int);

    void display(){              /////////////////
        for(int i=0;i<m;i++)cout<<vertex[0][i]<<" "<<vertex[1][i]<<endl;
        for(int i=0;i<m;i++){   for(int j=0;j<m;j++)  cout<<dist[i][j]<<" ";  cout<<endl;  }
        for(int i=0;i<m;i++){   for(int j=0;j<m;j++)  cout<<keys[i][j]<<" ";  cout<<endl;  }
    }
};
void obst :: addvertex(){
    vertex[0][0] =0; vertex[1][0]= 0;
    for(int i=1;i<m;i++){
        cout<<"Enter key "<<i<<": ";cin>>vertex[0][i];
       cout<<"Enter freq : ";cin>>vertex[1][i];
    }
}
void obst :: prims(){
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(j>i)    dist[i][j] = 9999;
            else   dist[i][j] = 0;
            keys[i][j] = -1;
        }
    }
    for(int i=1;i<m;i++){
        for(int j=i;j<m;j++){
            if(i==1){
                keys[j-1][j] = j;
                dist[j-1][j] = vertex[1][j];
            }
            else{
                int wt = 0;
                for(int k=j-i+1;k<=j;k++)    wt+=vertex[1][k];
                for(int k=j-i;k<j;k++){
                    if(  dist[j-i][j] > dist[j-i][k] + dist[k+1][j] + wt  ){
                        dist[j-i][j] = dist[j-i][k] + dist[k+1][j] + wt;
                        keys[j-i][j] = k+1;
                    }
                }
            }
        }
    }
}
node * obst :: create(node * root,int i,int j){
    if(i==j);
    else{
        //cout<<i<<" "<<j<<endl;
    root = insert(root,vertex[0][keys[i][j]] , vertex[1][keys[i][j]] );
    int k = keys[i][j] - 1;
    root = create(root,i,k);
    root = create(root,k+1,j);
    }
    return root;
}
node * obst :: insert(node* root,int key,int freq){
    if(root ==NULL)  return new node(key,freq);
    else if(key< root->key)   root->left = insert(root->left,key,freq);
    else                     root->right = insert(root->right,key,freq);
    return root;
}
int obst :: costis(node * root,int n=1){
    if(root == NULL)  return 0;
    return  ( root->freq * n + (  costis(root->left,n+1)  +  costis(root->right,n+1) )  );
}

int main(){
    cout<<"Enter total no. of keys : ";int m;
    cin>>m;
    node * root = NULL;
    obst o(m);
    o.addvertex();
    o.prims();
    root = o.create(root,0,m);
    //o.display();
   cout<<"Cost : "<<o.costis(root);
}
