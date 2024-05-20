/* #include<bits/stdc++.h>
using namespace std;
int nfact=1,rfact=1,n_rfact=1;
float combination(int n,int r){
    for(int i=1;i<=n;i++){
      nfact*=i;
    }
     for(int j=1;j<=r;j++){
      rfact*=j;
    }
     for(int z=1;z<=(n-r);z++){
      n_rfact*=z;
    }
}
int main(){
   int n,r;
   cout<<"enter the n :";
   cin>>n;
   cout<<"enter the r :";
   cin>>r;
   combination(n,r);
   cout<<"value of the combination:"<<(nfact/(rfact*n_rfact))<<endl;
    cout<<"value of the permutation:"<<(nfact/n_rfact);
cout<<"------another mathod-------";
}*/
#include<bits/stdc++.h>
using namespace std;
float fact(int n){
  int f=1;
    for(int i=1;i<=n;i++){
      f*=i;
    }
    return f;  
}
int main(){
   int n,r,nfact,rfact,n_rfact;
   cout<<"enter the n :";
   cin>>n;
   cout<<"enter the r :";
   cin>>r;
  nfact=fact(n);
  rfact=fact(r);
  n_rfact=fact(n-r);
   cout<<"value of the combination:"<<(nfact/(rfact*n_rfact))<<endl;
    cout<<"value of the permutation:"<<(nfact/n_rfact);
}