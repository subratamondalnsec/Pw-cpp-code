/* problem link : https://leetcode.com/problems/permutations/
By subrata mondal */

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    char data;
    bool terminal;
    unordered_map<char,Node*>child;
    Node(char data){
        this->data=data;
        this->terminal=false;
    }
    void makeTerminal(){
        this->terminal=true;
    }
    bool isTerminal(){
        return this->terminal==true;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root=new Node('\0');
    }
    
    void insert(string word) {
        Node* curr =root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(curr->child.count(ch)){
                curr=curr->child[ch];
            }
            else{
                Node* children=new Node(ch);
                curr->child[ch]=children;
                curr=children;
            }
        }
        curr->makeTerminal();
    }
    
    bool search(string word) {
        Node* curr =root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(curr->child.count(ch)){
                curr=curr->child[ch];
            }
            else{
                return false;
            }
        }
        return curr->isTerminal();
    }
    
    bool startsWith(string prefix) {
        Node* curr =root;
        for(int i=0;i<prefix.size();i++){
            char ch=prefix[i];
            if(curr->child.count(ch)){
                curr=curr->child[ch];
            }
            else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


int main() {
    Trie trie;

    // Insert words into the Trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apricot");

    // Test search functionality
    cout << "Search for 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Search for 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "Search for 'appl': " << (trie.search("appl") ? "Found" : "Not Found") << endl;

    // Test startsWith functionality
    cout << "Starts with 'ap': " << (trie.startsWith("ap") ? "Yes" : "No") << endl;
    cout << "Starts with 'appl': " << (trie.startsWith("appl") ? "Yes" : "No") << endl;
    cout << "Starts with 'aqua': " << (trie.startsWith("aqua") ? "Yes" : "No") << endl;

    return 0;
}