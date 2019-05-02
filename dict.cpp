#include<iostream>
#include<cstring>

using namespace std;

class Node{
public:
  char key[20],mean[20];
  Node *left = NULL;
  Node *right = NULL;
};

class bst{
public:
  Node *root=NULL , *newNode;
  int i=0,n;
  char delch[20] ,a[15][20],b[15][20];

  void create(char key[20], char mean[20]){
    newNode = new Node;
    strcpy(newNode->key,key);
    strcpy(newNode->mean,mean);
    if(root == NULL)
      root = newNode;
    else{
      insert(root , newNode);
    }

  }

  void insert(Node *r , Node *t){
    if(strcmp(r->key,t->key) > 0){
      if(r->left == NULL){
        r->left = t;
      }
      else
        insert(r->left , t);
    }
    else if(strcmp(r->key,t->key) < 0){
      if(r->right == NULL){
        r->right = t;
      }
      else
        insert(r->right , t);
    }
  }

  void display(Node *bt){
    if(bt!=NULL){
      display(bt->left);
      cout<<bt->key<<"\t"<<bt->mean<<endl;
      display(bt->right);
    }
  }

  void del(){
    i=0;
    chk(root , root);
    for (n = 1; n < i; n++) {
      create(a[n],b[n]);
    }
  }

  void chk(Node *r , Node *t){
    if(r != NULL){
      if(strcmp(r->key ,delch)==0){
        if(t->left == r)
          t->left = NULL;
        else if(t->right == r)
          t->right = NULL;
        else
          root = NULL;
        disp(r);
        return;
      }
      chk(r->left ,r);
      chk(r->right, r);
    }
  }

  void update(Node *bt){
    if(bt!=NULL){
      if(strcmp(bt->key,delch)==0){
        cout<<"Enter the new meaning for word => "<<bt->key<<endl;
        cin>>bt->mean;
        return;
      }
      update(bt->left);
      update(bt->right);
    }
  }

  void disp(Node *bt){
    if(bt!=NULL){
      strcpy(a[i],bt->key);
      strcpy(b[i],bt->mean);i++;
      disp(bt->left);
      disp(bt->right);
    }
  }
};

int main(){
  bst obj;
  char ch,key[20],mean[20];
  Again:
  cout<<"\nEnter:\n\t1.Insert\n\t2.Display\n\t3.Update\n\t4.Delete\n\t0.Exit\n";
  cin>>ch;
  switch (ch) {
    case '1':
      cout<<"Enter word to add to dict and meaning\n";
      cin>>key>>mean;
      obj.create(key,mean);
      goto Again;
    case '2':
      obj.display(obj.root);
      goto Again;
    case '3':
      cout<<"Enter word to update\n";
      cin>>obj.delch;
      obj.update(obj.root);
      goto Again;
    case '4':
      cout<<"Enter word to delete\n";
      cin>>obj.delch;
      obj.del();
      goto Again;
    case '0':
      exit(0);
    default:
      cout<<"Wrong Choice\n";
      goto Again;
  }
  return 0;
}
