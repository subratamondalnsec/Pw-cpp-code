#include <bits/stdc++.h>
using namespace std;
int maze(int sr,int sc,int er,int ec){
    if(sr>er||sc>ec) return 0;
    if(sr==er && sc==ec) return 1;
    int rightways=maze(sr,sc+1,er,ec);
    int downways=maze(sr+1,sc,er,ec);
    int totalways=rightways+downways;
    return totalways;
}
int maze2(int row,int col){
    if(row<0||col<0) return 0;
    if(row==0 && col==0) return 1;
    int rightways=maze2(row,col-1);
    int downways=maze2(row-1,col);
    int totalways=rightways+downways;
    return totalways;
}
void mazeprintpath(int sr,int sc,int er,int ec,string s){
    if(sr>er||sc>ec) return ;
    if(sr==er && sc==ec){ 
        cout<<s<<endl;
        return ;
 }
    mazeprintpath(sr,sc+1,er,ec,s+'R');
    mazeprintpath(sr+1,sc,er,ec,s+'D');
}
void mazeprintpath2(int row,int col,string s){
    if(row<0||col<0) return ;
    if(row==0 && col==0){ 
        cout<<s<<endl;
        return ;
}
    mazeprintpath2(row,col-1,s+'R');
    mazeprintpath2(row-1,col,s+'D');
}
int main(){
    cout<<maze(0,0,2,2)<<endl;
    mazeprintpath(0,0,2,2,"");
    cout<<maze2(2,2)<<endl;//row->3 and col ->3 ,->0,1,2 its
    mazeprintpath2(2,2,"");
}