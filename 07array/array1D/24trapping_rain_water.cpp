
#include<bits/stdc++.h>
using namespace std;
    int trappingWater(int height[], int n){
       
        int prev[n];//prev gratest element array
         prev[0]=-1;
        int max= height[0];
        for(int i=1;i<n;i++){
            prev[i]=max;
            if(max<height[i]) max=height[i];
        }
        int next[n];// next gratest element array
        next[n-1]=-1;
         max=height[n-1];
        for(int i=n-2;i>=0;i--){
            next[i]=max;
            if(max<height[i]) max=height[i];
        }
            //minimum array 
            int mini[n];
            for(int i=0;i<n;i++){
                mini[i]=min(prev[i],next[i]);
            }
      long long int water=0;//calculate the water
        for(int i=0;i<n-1;i++){
            if(height[i]<mini[i]){
                water+=(mini[i]-height[i]);
            }
        }
        return water;
    }
/*

        int prev[n];//prev gratest element array
         prev[0]=-1;
        int max= height[0];
        for(int i=1;i<n;i++){
            prev[i]=max;
            if(max<height[i]) max=height[i];
        }
        int next[n];// next gratest element array
        next[n-1]=-1;
         max=height[n-1];
        for(int i=n-2;i>=0;i--){
            next[i]=max;
            if(max<height[i]) max=height[i];
        }
            //minimum array 
           
            for(int i=0;i<n;i++){
                prev[i]=min(prev[i],next[i]);
            }
     long long  int water=0;//calculate the water
        for(int i=0;i<n-1;i++){
            if(height[i]<prev[i]){
                water+=(prev[i]-height[i]);
            }
        }
        return water;
    }
};*/
       /* int prev[n];//prev gratest element array
         prev[0]=-1;
        int max= height[0];
        for(int i=1;i<n;i++){
            prev[i]=max;
            if(max<height[i]) max=height[i];
        }
        // next gratest element array
        prev[n-1]=-1;
         max=height[n-1];
        for(int i=n-2;i>=0;i--){
            if(max<prev[i]) prev[i]=max;
            if(max<height[i]) max=height[i];
        }
      long long int water=0;//calculate the water
        for(int i=0;i<n-1;i++){
            if(height[i]<prev[i]){
                water+=(prev[i]-height[i]);
            }
        }
        return water;
    }
};*/
int main(){
        int n;
        //size of array
        cin >> n;
        int a[n];
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        //calling trappingWater() function
        cout << trappingWater(a, n) << endl;
}
