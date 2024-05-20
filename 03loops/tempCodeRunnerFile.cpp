int CalculatefiboSum(int n){
     if(n<=0){
        return 0;
    }
   //0 1 1 2 3 5 8
    //ARRAY DECLARATION
    int fibo[n+1];
    //INTIALIZATION
    fibo[0]=0, fibo[1]=1;
    //SUM DECLARATION
    int sum=fibo[0]+fibo[1];
    for(int i=2;i<=n;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
        sum+=fibo[i];
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    int sum=CalculatefiboSum(n);
    cout<<sum;
}