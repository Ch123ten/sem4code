#include<iostream>
#include<vector>
using namespace std;

struct node{
    string name;
    vector<node *>child;
    node(int n){
        if (n!=1)   cin.ignore();
        getline(cin,name);
    }
}; 

class book{
    node * root;
    public:
    book(){   root = NULL;   }
    void create();
    void display();
};

void book :: create(){
    cout<<"Enter the book Title : ";
    root = new node(1);

    int ch = 0;
    while(true){
        cout<<endl<<"    Chapter "<<++ch<<": ";
        node * chapter = new node(ch);
        root->child.push_back(chapter);

        int sec = 0;
        cout<<endl;
        while(true){
            cout<<"         Section "<<++sec<<": ";
            node * section = new node(sec);
            chapter->child.push_back(section);

            int subsec = 0;
            while(true){
                cout<<"            sub Section "<<++subsec<<": ";
                node * subsection = new node(subsec);
                section->child.push_back(subsection);

                cout<<"            Add more Subsection ? ";int choice;   cin>>choice;
                if(choice !=1)   break;
            }

            cout<<endl<<"        Add more Sections ? ";int choice;   cin>>choice;
            if(choice !=1)   break;
        }

        cout<<endl<<"    Add more chapters ? ";int choice;   cin>>choice;
        if(choice !=1)   break;
    }
}

void book :: display(){
    cout<<endl<<endl;
    cout<<"--------------------------INDEX--------------------------"<<endl;
    cout<<"              BOOK TITLE : "<<root->name<<endl;
    cout<<endl;
    vector<node *> :: iterator it = root->child.begin();
    int ch=0;
    for(it;it!=root->child.end();it++){
        cout<<"    Chapter "<<++ch<<": "<<(*it)->name<<endl;

        int sec=0;
        vector<node *> :: iterator it1 = (*it)->child.begin();
        for(it1;it1!=(*it)->child.end();it1++){
            cout<<"        Section "<<++sec<<": "<<(*it1)->name<<endl;

            int sub=0;
            vector<node *> :: iterator it2 = (*it1)->child.begin();
            for(it2;it2!=(*it1)->child.end();it2++){
                cout<<"            Subsection "<<++sub<<": "<<(*it2)->name<<endl;
            }
        }
    }
}

int main(){
    book b;
    b.create();
    b.display();
}