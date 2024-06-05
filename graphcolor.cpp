#include<iostream>
using  namespace std;


int m = 3 , n = 4 ,x[4],G[4][4];

bool isSafe(int k , int c){
for(int i = 0; i < n;  i++){
    if(G[k][i]==1 && c == x[i])
        return false;
}
return true;
}

void graphColor(int k){
    for(int c =1; c<=m;c++){
        if(isSafe(k,c)){
            x[k] =c ;
            if(k+1 < n)
                graphColor(k+1);
            else{
                    for(int i = 0 ; i< n ; i++){
                        cout<< x[i] <<endl;
                    }
                    return;

            }
        }
    }
}




int main(){

for(int i = 0; i < n; i++){
    for(int j = 0; j < n ; j++){
        cout<< "Enter value for" << i+1 << " - "<<j+1<<endl;
        cin>>G[i][j];
    }
}



graphColor(0);
return 0;
}