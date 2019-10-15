
#include <iostream>


using namespace std;

int DeleteFive(int a[]){
    int i;
    int m = -1;
    for (i = 0; i < 10;i++){
        if(a[i] > 5){
            for (int j = i; j < 10 - m - 1;j++){
                if (a[j]>5){
                    m++;
                    a[j - m] = a[j + 1];
                }
                else {
                    a[j - m] = a[j + 1];
                }
            } //for(j)
            break;
        }
        
    }//for(i)
    return 1;
}

int main(){
    int a[] = {8,6,5,2,3,7,1,3,8,6};
    DeleteFive(a);
    for (int i = 0; i<5; i++){
        cout << a[i] << " ";
    }
    return 0;
}
