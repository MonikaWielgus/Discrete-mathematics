//Monika Wielgus
#include <iostream>

using namespace std;

const int N=4; // size of array to permute
int array[N];

void initArray(int n){
    for(int i=0;i<n;i++){
        if(i<(n/2))
            array[i]=1;
        else
            array[i]=2;
    }
    int l=(N-n)/2;
    for(int i=n; i<n+l; i++)
        array[i]=3;
    for(int i=n+l; i<N; i++)
        array[i]=4;
}
void printArray(){
    for(int i=0;i<N;i++){
        if(array[i]==1)
            cout << "U" << " ";
        if(array[i]==2)
            cout << "D" << " ";
        if(array[i]==3)
            cout << "L" << " ";
        if(array[i]==4)
            cout << "R" << " ";
    }
    cout << endl;
}
void swap(int i,int j){
    int tmp=array[i];
    array[i]=array[j];
    array[j]=tmp;
}
void reverse(int start,int stop){
    int i=start;
    int j=stop;

    while (i<j){
        swap(i,j);
        ++i;
        --j;
    }
}
void nextPermutation(){
    int k;
    int l;

    for(int i=N-1; i>0; i--){
        if(array[i]>array[i-1]){
            k=i-1;
            break;
        }
    }
    for(int i=N-1; i>k; i--){
        if(array[i]>array[k]){
            l=i;
            break;
        }
    }
    swap(k,l);
    reverse(k+1,N-1);
}
bool fun_help(){
    for(int i=0; i<N-1; i++)
        if(array[i]<array[i+1])
            return false;
    return true;
}
int generateAllPermutations(void (fun)()){
    printArray();
    while(fun_help()==false){
        nextPermutation();
        fun();
    }
}
void walks(){
    if(N%2==1)
        cout << "There is no such walks!" << endl;
    else{
        cout << "U-UP  D-DOWN  L-LEFT  R-RIGHT" << endl;
        int i=N;
        while(i>=0){
            initArray(i);
            generateAllPermutations(printArray);
            i-=2;
        }
    }
}
int main(){
  walks();
}
