#include<iostream>
using namespace std;

struct node{
    string name;
    int level;
    node * next;
    node(){
        cout<<"Enter name of patient : ";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter level : ";  cin>>level ;
        next = NULL;
    }
};

class priority{
    public:
    int size;
    node * root;
    int count;
    priority(int x){
        size = x;
        root = NULL;
        count = 0 ;
    }
    bool empty();
    bool full();
    void push(node *);
    void display();
    node * search(node *,node *);
    node * remove();
};

bool priority :: empty(){
    if ( count == 0)   return true;
    return false;
}
bool priority :: full(){
    if( count == size)   return true;
    return false;
}
void priority :: push(node * temp){
    if(full()){  cout<<"Hospital is at full capacity."<<endl;    return;  }
    if(empty()){   root = temp; count++; return;   }
    if(root->level < temp->level ){
        temp->next = root;
        root = temp;
        count++;
        return;
    }
    node * t = root;
    while( t->next!=NULL  &&  t->next->level >= temp->level ){
        t = t->next;
    }
    temp->next = t->next;
    t->next = temp;
    count++;
}
void priority :: display(){
    node * curr = root;
    cout<<endl;
    while(curr!=NULL){
        cout<<"Name : "<<curr->name<<" -> Level : "<<curr->level<<endl;
        curr = curr->next;
    }
    cout<<endl;
}
node * priority :: search(node * root,node * temp){
    if(root== NULL)  return NULL;
    if(root->level < temp->level)    return NULL;
    if(root->name == temp->name)   return root;   
    return search(root->next,temp);
}
node * priority::remove(){
    if(root==NULL)  return NULL;
    else{
        node * temp = root;
        root= root->next;
        delete temp;
    }
}

int main(){
    int s = 0;
    cout<<"Enter the capacity of hospital : ";
    cin>>s;
    priority p(s);
    while(true){
        cout<<endl<<"1.add  2.display  3.search   4.delete    5.exit\nEnter the choice : ";
        int ch;  cin>>ch;
        if(ch==1){
            node * temp = new node();
            p.push(temp);
        }
        else if(ch==2){
            p.display();
        }
        else if(ch==3){
            node * temp = new node();
            temp = p.search(p.root,temp);
            if(temp!=NULL)  cout<<"Found"<<endl;
            else  cout<<"Not found"<<endl;
        }
        else if(ch==4){
            p.remove();
        }
        else   break;
    }
}