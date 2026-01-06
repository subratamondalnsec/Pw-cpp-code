#include <bits/stdc++.h>
using namespace std;

int main(){//Approch 2
    int n;//Number of box
    cin>>n;
    vector<int>f(n+1,0);
    int m;//Number of days
    cin>>m;
    for(int i=0;i<m;i++){//f update to quires
        int L,R;
        cin>>L>>R;
        f[L]+=1;
        f[R+1]+=(-1);
    }
    for(int i=1;i<=f.size();i++){//prefix sum
        f[i]+=f[i-1];
    }
    int mx=INT_MIN;
    for(int i=0;i<=n;i++) mx=max(mx,f[i]);
    vector<int> c(mx+5,0);
    for(int i=0;i<=n;i++){// frequency element array
        int coins=f[i];
        c[coins]++;
    }
    for(int i=c.size()-2;i>=0;i--){// suffix sum
        c[i]=c[i]+c[i+1];
    }
    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        cout<<c[num]<<"\n";
    }
}

/*
int main(){//Approch 1
    int n;//Number of box
    cin>>n;
    vector<int>f(n+1,0);
    int m;//Number of days
    cin>>m;
    vector<int>l(n+1,0);
    vector<int>r(n+1,0);
    for(int i=0;i<m;i++){
        int L,R;
        cin>>L>>R;
        l[L]++;
        r[R]++;
    }
    f[1]=l[1];
    for(int i=2;i<=n;i++){
        f[i]=l[i]-r[i-1]+f[i-1];
    }
    vector<int> c(10000005,0);
    for(int i=0;i<=n;i++){
        int coins=f[i];
        c[coins]++;
    }
    for(int i=c.size()-2;i>=0;i--){
        c[i]=c[i]+c[i+1];
    }
    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        cout<<c[num]<<"\n";
    }
}
*/

/*
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2
 */