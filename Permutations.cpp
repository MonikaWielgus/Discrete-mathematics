//Monika Wielgus
#include <iostream>
using namespace std;

const int N=4;
int array[N];
void initArray(){
  for(int i=0;i<N;i++)
    array[i]=i+1;
}

void printArray(){
  for(int i=0;i<N;i++)
    cout<<array[i]<<" ";
  cout<<endl;
}

void swap(int i,int j){
   int tmp=array[i];
   array[i]=array[j];
   array[j]=tmp;
}

void reverse(int start,int stop){
  int i=start;
  int j=stop;

  while(i<j){
   swap(i,j);
    ++i;
    --j;
  }
}

void nextPermutation(){
    int k;
    int l;

    for(int i=N-1;i>0;i--){
        if(array[i]>array[i-1]){
            k=i-1;
            break;
        }
    }
    int temp=array[k];
    for(int i=N-1;i>k;i--){
        if(array[i]>temp){
            l=i;
            break;
        }
    }

    swap(k,l);
    reverse(k+1,N-1);
}

bool help(){
    for(int i=0;i<N-1;i++)
        if(array[i]<array[i+1])
            return false;

    return true;
}

int generateAllPermutations(void (fun)()){
    while(help()==false){
        nextPermutation();
        fun();
    }
}
int main(){
  initArray();
  printArray();
  generateAllPermutations(printArray);

}






