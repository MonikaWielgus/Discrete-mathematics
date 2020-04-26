//Monika Wielgus
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NO_OF_VERTICES=7;
int A[NO_OF_VERTICES+1][NO_OF_VERTICES+1];

void tree(){
    srand(time(NULL));
    int code[NO_OF_VERTICES-1];
    int vertices[NO_OF_VERTICES+1];
    int countInCode[NO_OF_VERTICES+1];

    for(int i=0; i<NO_OF_VERTICES+1; i++)
        countInCode[i]=0;

    for(int i=1; i<NO_OF_VERTICES-1; i++){
        code[i]=rand()%(NO_OF_VERTICES-1)+1;
        countInCode[code[i]]++;
    }

    for(int i=1; i<NO_OF_VERTICES+1; i++)
        vertices[i]=i;

    cout << "CODE: ";
    for(int i=1; i<NO_OF_VERTICES-1; i++)
        cout << code[i];
    cout << endl << endl;

    for(int i=1; i<NO_OF_VERTICES-1; i++){
        for(int j=1; j<NO_OF_VERTICES+1; j++){
            if(vertices[j]!=-1)
                if(vertices[j]!=code[i]&&countInCode[vertices[j]]==0){
                    A[code[i]][vertices[j]]=A[vertices[j]][code[i]]=1;
                    vertices[j]=-1;
                    countInCode[code[i]]--;
                    break;
                }
        }
    }
    int last1=0;
    int last2=0;

    for(int i=1; i<NO_OF_VERTICES+1; i++){
        if(vertices[i]!=-1&&last1==0)
            last1=vertices[i];
        else if(vertices[i]!=-1&&last1!=0)
            last2=vertices[i];
    }
    A[last1][last2]=A[last2][last1]=1;

    cout << "MATRIX:" << endl;
    for(int i=1; i<NO_OF_VERTICES+1; i++){
        for(int j=1; j<NO_OF_VERTICES+1; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    for(int i=1; i<NO_OF_VERTICES+1; i++){
        cout << "Neighbours of vertice " << i << ": ";
        for(int j=1; j<NO_OF_VERTICES+1; j++)
            if(A[i][j]==1)
                cout << j << " ";
        cout << endl;
    }
}

int main(){
    tree();
}
