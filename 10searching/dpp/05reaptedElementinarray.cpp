// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     int arr[]={1,2,3,3,4,5};
//     int n =sizeof(arr)/sizeof(arr[0]);
//     int lo=0;
//     int hi=n-1;
//    bool flag=false;
//             while(lo <= hi) {
//             int mid = lo + (hi - lo) / 2;
//             if(arr[mid] == mid || arr[mid]==mid+1) {
//                 if(arr[mid - 1] == mid+1 ||arr[mid - 1] == mid ||arr[mid + 1] == mid+1 ||arr[mid + 1] == mid) {
//                    cout<<"reapeated elment is : " <<arr[mid];
//                    flag= true;
//                     break;
//                 }
//                 hi = mid - 1;
//             } else {
//                 lo = mid + 1;
//             }
//         }
//     if(flag==false) cout<<-1;
// }

#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,3,4,5};
    int n =sizeof(arr)/sizeof(arr[0]);
    int lo=0;
    int hi=n-1;
    bool flag=false;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(arr[mid]==mid+1) lo=mid+1;
        if(arr[mid]==mid){
            if(arr[mid]==arr[mid-1]){
                cout<<"reapeated elment is : " <<arr[mid];
                break;
            }
            else hi=mid-1;
        }
                
    }
        
}