/* problem link : 
By subrata mondal */

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    char data;
    bool terminal;
    unordered_map<char,Node*>child;
    int countWordsEndingHere;
    int countWordsStarting;
    Node(char data){
        this->data=data;
        this->terminal=false;
        this->countWordsEndingHere=this->countWordsStarting=0;
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
                curr->countWordsStarting++;
            }
            else{
                Node* children=new Node(ch);
                curr->child[ch]=children;
                curr=curr->child[ch];
                curr->countWordsStarting++;
            }
        }
        curr->terminal=true;
        curr->countWordsEndingHere++;
    }
    int countWordsEqualTo(string word){
        Node* curr =root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            if(curr->child.count(ch)){
                curr=curr->child[ch];
            }
            else{
                return 0;
            }
        }
        return curr->countWordsEndingHere;
    }
    int countWordsStartingWith(string prefix){
        Node* curr =root;
        for(int i=0;i<prefix.size();i++){
            char ch=prefix[i];
            if(curr->child.count(ch)){
                curr=curr->child[ch];
            }
            else{
                return 0;
            }
        }
        return curr->countWordsStarting;
    }

    void erase(string word){
        Node* curr =root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            curr=curr->child[ch];
            curr->countWordsStarting--;
        }
        curr->countWordsEndingHere--;
    }
};


int main() {
    Trie trie;

    // Insert words into the trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("application");
    trie.insert("banana");
    trie.insert("band");
    trie.insert("bat");
    
    // Count words equal to a specific word
    cout << "Words equal to 'apple': " << trie.countWordsEqualTo("apple") << endl; // Output: 1
    cout << "Words equal to 'app': " << trie.countWordsEqualTo("app") << endl;     // Output: 1
    cout << "Words equal to 'apples': " << trie.countWordsEqualTo("apples") << endl; // Output: 0

    // Count words starting with a specific prefix
    cout << "Words starting with 'app': " << trie.countWordsStartingWith("app") << endl; // Output: 3
    cout << "Words starting with 'ban': " << trie.countWordsStartingWith("ban") << endl; // Output: 2
    cout << "Words starting with 'bat': " << trie.countWordsStartingWith("bat") << endl; // Output: 1

    // Erase a word and check counts again
    trie.erase("app");
    cout << "After erasing 'app':" << endl;
    cout << "Words equal to 'app': " << trie.countWordsEqualTo("app") << endl;     // Output: 0
    cout << "Words starting with 'app': " << trie.countWordsStartingWith("app") << endl; // Output: 2

    return 0;
}
