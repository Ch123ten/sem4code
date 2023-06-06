#include<iostream>
using namespace std;

struct node{
    string mean;   char key;
    node * left;   node * right;
    node(char x){
        key = x;
        cout<<"Enter mean of key "<<x<<": ";
        cin.ignore();
        getline(cin,mean);
        left = right = NULL;
    }
};

class bst{
    node * root;
    public:
    bst(){   root = NULL;  }
    node * insert(node *,char);
    void asdisp(node *);
    void dsdisp(node *);
    node * search(node *,char);
    node * update(node *,char);

    node * deletes(node * ,char);
    node * succ(node *);
};

node * bst :: insert(node * root,char x){
    if(root==NULL)  return new node(x);
    else if(x<root->key)  root->left = insert(root->left,x);
    else      root->right = insert(root->right,x);
    return root;
}

void bst :: asdisp(node * root){
    if(root==NULL)  return;
    asdisp(root->left);
    cout<<"Key : "<<root->key<<"  Meaning : "<<root->mean<<endl;
    asdisp(root->right);
}

void bst :: dsdisp(node * root){
    if(root==NULL)  return;
    dsdisp(root->right);
    cout<<"Key : "<<root->key<<"  Meaning : "<<root->mean<<endl;
    dsdisp(root->left);
}

node * bst :: search(node * root,char x){
    if(root == NULL) {  cout<<x<<" key not found"<<endl; return NULL;  }
    else if(root->key == x){  cout<<x<<" key found"<<endl;   return root;  }
    else if(x<root->key)   return search(root->left,x);
    else       return search(root->right,x);
}

node * bst :: update(node * root,char x){
    node * temp = search(root,x);
    if(temp!=NULL){
        cout<<"Enter new meaning of key "<<root->key<<" : ";
        cin.ignore();
        getline(cin,root->mean);
        cout<<x<<" is updated"<<endl;
    }
    return root;
}

node * bst :: succ(node * root){
    if(root->left==NULL)  return root;
    succ(root->left);
}

node * bst :: deletes(node * root,char x){
    if(root== NULL) return NULL;
    else if(root->key == x){
        //0 child
        if(root->left == NULL  &&  root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 child
        else if(root->left != NULL  &&  root->right == NULL){
            node * temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left == NULL  &&  root->right != NULL){
            node * temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        else{
            node * temp = succ(root->right);
            root->key = temp->key;
            root->mean = temp->mean;
            root->right = deletes(root->right,temp->key);
            return root;
        }
    }
    else if(x<root->key)       root->left = deletes(root->left,x);
    else          root->right = deletes(root->right,x);
}

int main(){
    bst b;
	node * root = NULL;
	int ch=0;
	while(true){
        cout<<"1.insert     2.ascending     3.descending     4.search     5.update     6.delete     7.exit "<<endl;
		cout<<"Enter the choice : ";  cin>>ch;
		if(ch==1){
			cout<<"Enter key to insert : ";    char c;   cin>>c;
			root = b.insert(root,c);
		}
		else if(ch==2){
			b.asdisp(root);
		}
		else if(ch==3){
			b.dsdisp(root);
		}
		else if(ch==4){
			cout<<"Enter key to search : ";   char c;   cin>>c;
			(b.search(root,c));
		}
		else if(ch==5){
			cout<<"Enter key to update : ";char c;  cin>>c;
			b.update(root,c);
		}
		else if(ch==6){
			cout<<"Enter key to delete : ";char c;  cin>>c;
			b.deletes(root,c);
		}
		else    break;
	}
}