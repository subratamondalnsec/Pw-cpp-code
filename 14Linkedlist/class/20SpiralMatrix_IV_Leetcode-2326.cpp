#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
   vector<vector<int>>matrix(m,vector<int>(n,-1));
    int minr=0,minc=0,maxr=m-1,maxc=n-1;
    int tne =n*m,count=0; 
    ListNode* temp= head;  
while(minr<=maxr && minc<=maxc){
    
//rigit
for(int j=minc;j<=maxc && count<tne;j++){
    if(temp==NULL) return matrix;
    matrix[minr][j]=temp->val;
    temp=temp->next;
}
minr++;
//down
for(int i=minr;i<=maxr && count<tne;i++){
     if(temp==NULL) return matrix;
     matrix[i][maxc]=temp->val;
    temp=temp->next;
}
maxc--;
//left
for(int j=maxc;j>=minc && count<tne;j--){
     if(temp==NULL) return matrix;
    matrix[maxr][j]=temp->val;
    temp=temp->next;
}
maxr--;
//up
for(int i=maxr;i>=minr&&count<tne; i--){
     if(temp==NULL) return matrix;
     matrix[i][minc]=temp->val;
    temp=temp->next;
}
minc++;
}

    return matrix;
    }
};
// Function to create a linked list from a vector
ListNode* createLinkedList(const std::vector<int>& values) {
    if (values.empty()) return NULL;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Function to print the 2D matrix
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

// Main function to test the spiralMatrix function
int main() {
    int m = 3, n = 4;
    std::vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    ListNode* head = createLinkedList(values);
    
    Solution sol;
    std::vector<std::vector<int>> matrix = sol.spiralMatrix(m, n, head);
    
    // Print the resulting matrix
    printMatrix(matrix);
    
    return 0;
}