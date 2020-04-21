//Monika Wielgus
#include <iostream>
using namespace std;
const int NO_OF_VERTICES=10;
const int A[NO_OF_VERTICES+1][NO_OF_VERTICES+1]={{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                                 {0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
                                                 {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0},
                                                 {0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0},
                                                 {0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0},
                                                 {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
                                                 {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                                                 {0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
                                                 {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
                                                 {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
                                                 {0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0}};
bool POSSIBLE[NO_OF_VERTICES+1];
int X[NO_OF_VERTICES+1]; //partial equation

void Hamilton(int k){
    for(int i=1; i<NO_OF_VERTICES+1; i++){
        if(A[X[k-1]][i]==1){ //neighbours
            if(k==NO_OF_VERTICES+1){
                for(int j=1; j<NO_OF_VERTICES+1; j++)
                    cout << X[j] << " ";
                cout << endl;
                return;
            }
            else{
                if(POSSIBLE[i]==true){
                    X[k]=i;
                    POSSIBLE[i]=false;
                    Hamilton(k+1);
                    POSSIBLE[i]=true;
                }
            }
        }
    }
}

int main(){
    for(int i=0; i<NO_OF_VERTICES+1; i++)
        POSSIBLE[i]=true;

    POSSIBLE[1]=false;
    X[1]=1;
    Hamilton(2);
}
