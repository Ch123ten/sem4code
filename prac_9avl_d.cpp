#include<iostream>
using namespace std;

struct node{
    char key;  string mean;
    node * left;  node * right;
    node(char x){
        key = x;
        cout<<"Enter meaning of key "<<x<<" : ";   
        cin.ignore();
        getline(cin,mean);
        right = left = NULL ;
    }
};

class avl{
    node * root;
    public:
    avl(){root= NULL;}
    int height(node *);
    int diff(node *);
    node * balance(node *);
    node * insert(node *,char);
    node * ll(node *);
    node * rr(node *);
    node * lr(node *);
    node * rl(node *);

    void asdisp(node *);
    void dsdisp(node *);
    node * search(node * ,char);
    node * update(node * ,char);
    node * succ(node *);
    node * deletes(node * ,char);
    void traverse(node * root){
        if(root==NULL)    return;
        traverse(root->left);
        traverse(root->right);
        root = balance(root);
    }
};
int avl :: height(node * root){
    if(root==NULL)  return -1;
    return max( height(root->left),height(root->right) ) + 1;
}
int avl :: diff(node * root){
    return ( height(root->left) - height(root->right)  );
}
node * avl :: balance(node * root){
    if(diff(root)>1){
        if(diff(root->left)<0)    root = lr(root);
        else  root = ll(root);
    }
    else if(diff(root)<-1){
        if(diff(root->right)<0)   root = rr(root);
        else    root = rl(root);
    }
    return root;
}
node * avl :: ll(node * root){
    node * temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}
node * avl :: rr(node * root){
    node * temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}
node * avl :: lr(node * root){
    root->left = rr(root->left);
    return ll(root);
}
node * avl :: rl(node * root){
    root->right = ll(root->right);
    return rr(root);
}

node * avl :: insert(node * root,char x){
    if(root==NULL)  return new node(x);
    else if(x<root->key) {  root->left = insert(root->left,x);    root = balance(root); }
    else   {    root->right = insert(root->right,x);    root = balance(root);  }
    //cout<<height(root)<<endl;
    return root;
}
void avl :: asdisp(node * root){
    if(root == NULL)  return;
    asdisp(root->left);
    cout<<"key : "<<root->key<<"   Meaning : "<<root->mean<<endl;
    asdisp(root->right);
}
void avl :: dsdisp(node * root){
    if(root == NULL)  return;
    dsdisp(root->right);
    cout<<"key : "<<root->key<<"   Meaning : "<<root->mean<<endl;
    dsdisp(root->left);
}
node * avl :: search(node * root,char x){
    if(root == NULL) {  cout<<x<<" key not found"<<endl; return NULL;  }
    else if(root->key == x){  cout<<x<<" key found"<<endl;   return root;  }
    else if(x<root->key)   return search(root->left,x);
    else       return search(root->right,x);
}
node * avl :: update(node * root,char x){
    node * temp = search(root,x);
    if(temp!=NULL){
        cout<<"Enter new meaning of key "<<root->key<<" : ";
        cin.ignore();
        getline(cin,root->mean);
        cout<<x<<" is updated"<<endl;
    }
    return root;
}
node * avl :: succ(node * root){
    if(root->left==NULL)  return root;
    succ(root->left);
}

node * avl :: deletes(node * root,char x){
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
    avl b;
	node * root = NULL;
	int ch=0;
	while(true){
        cout<<"1.insert     2.ascending     3.descending     4.search     5.update     6.delete     7.exit "<<endl;
		cout<<"Enter the choice : ";  cin>>ch;
		if(ch==1){
			cout<<"Enter key to insert : ";    char c;   cin>>c;
			root = b.insert(root,c);
            cout<<root->key<<endl;
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
            b.traverse(root);
		}
		else    break;
	}

}










