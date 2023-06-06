#include<iostream>
using namespace std;

struct node{
    char data;
    node * left;   node * right;
    node(char x){
        data = x;
        left = right = NULL;
    }
};

class stack{
    node * list[50];
    int i=-1;
    public:
    bool empty(){   if(i==-1)  return true;   return false;   }
    void push(node *x) { list[++i] = x; }
    node * pop(){   return list[i--];   }
    node * top(){   return list[i];   }
};

class tree{
    node * root;
    public:
    int level(char c){
        if(c=='*'  ||  c=='/')  return 2;
        if(c=='-'  ||  c=='+')  return 1;
    }
    node * create(string);
    void display();
    void deletes(node *);
};

node * tree :: create(string str){
    stack s1,s2;
    char c;
    for(int i=0;i<str.length();i++){
        c = str[i];
        node * temp = new node(c);

        if(isalpha(c))      s1.push(temp);
        else{
            if(s2.empty())   s2.push(temp);
            else{
                if(level(c)>level(s2.top()->data))   s2.push(temp);
                else{
                    while(!s2.empty()  &&  level(c)<=level(s2.top()->data)){
                        node * op = s2.pop();
                        op->right = s1.pop();
                        op->left = s1.pop();
                        s1.push(op);
                    }
                    s2.push(temp);
                }
            }
        }
    }
    while(!s2.empty()){
        node * temp = s2.pop();
        temp->right = s1.pop();
        temp->left = s1.pop();
        s1.push(temp);
    }
    root = s1.top();
    return root;
}

void tree :: display(){
    stack s1,s2;
    s1.push(root);
    while(!s1.empty()){
        node * temp = s1.pop();
        s2.push(temp);
        if(temp->left)  s1.push(temp->left);
        if(temp->right)  s1.push(temp->right);
    }
    cout<<"Postorder expression is : ";
    while(!s2.empty()){
        cout<<s2.pop()->data<<" ";
    }
    cout<<endl;
}

void tree :: deletes(node * root){
    if(root == NULL)  return;
    deletes(root->left);
    deletes(root->right);
    delete root;
}

int main(){
    tree t;
    node * root = NULL;
    string s ;  cout<<"Enter the expression : ";   cin>>s;
    for(int i=0;i<s.length();i++){
        if(i%2==0){
            if(!isalpha(s[i])){    cout<<"Expression is wrong."<<endl;  exit(0);    }
        }
        else{
            if(s[i]=='+'  ||  s[i]=='-'  ||  s[i]=='*'  ||  s[i]=='/');
            else{
                cout<<"This expression is wrong."<<endl;  exit(0); 
            }
        }
    }
    root = t.create(s);
    t.display();
    t.deletes(root);
}
// a+b*c-d/e+f