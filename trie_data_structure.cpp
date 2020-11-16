#include<bits/stdc++.h>
using namespace std;

struct trie{
    struct trie *children[26];
    bool isEnd;

};

trie *getNode(){
      struct trie *newNode = new struct trie;

      for(int i=0;i<26;i++){
        newNode->children[i] = NULL;
      }

      newNode->isEnd = false;
      return newNode;
}

void insert_in_trie(trie *root,string key){
    int temp;
    struct trie *temp1 = root;
    for(int i=0;i<key.size();i++){
        temp = key[i]-'a';
        if(temp1->children[temp] == NULL){
            temp1->children[temp] = getNode();
        }
        temp1 = temp1->children[temp];
    }
    temp1->isEnd = true;
}

bool search_in_trie(trie *root,string key){
    int temp;
    struct trie *temp1 = root;
    for(int i=0;i<key.size();i++){
        temp = key[i]-'a';
        if(temp1->children[temp] == NULL){
            return false;
        }
        temp1 = temp1->children[temp];
    }

    return (temp1 != NULL && temp1->isEnd);
}

int main(){
    struct trie *root = getNode();
    insert_in_trie(root,"pqrs");
    insert_in_trie(root,"pprt");
    insert_in_trie(root,"psst");

    cout<<search_in_trie(root,"pprts");
    return 0;
}
