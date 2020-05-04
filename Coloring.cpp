//Monika Wielgus
#include <iostream>
using namespace std;

const int NO_OF_VERTICES=20;
int B[NO_OF_VERTICES+1][NO_OF_VERTICES+1]=
{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0,0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0},
{0,0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1},
{0,1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1},
{0,1, 1, 1, 0, 1, 0,  0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
{0,0, 0, 0, 1, 0, 0, 1, 1,  0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1},
{0,0, 0, 1, 0, 0, 0, 0, 0, 1, 1,  0, 1, 1, 1, 0, 0, 0, 1, 1, 1},
{0,0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1},
{0,0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1},
{0,0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1},
{0,1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1},
{0,1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1},
{0,0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0},
{0,1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0},
{0,0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1},
{0,0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1},
{0,1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
{0,1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0},
{0,1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
{0,1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0},
{0,0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0}};

bool isPresent(int pos, int col, int colors[]){
    for(int i=1; i<=pos; i++){
        if((B[i][pos]==1)&&(col==colors[i]))
            return true;
    }
    return false;
}


bool colorGraph(int A[NO_OF_VERTICES+1][NO_OF_VERTICES+1], int pos, int k, int colors[]){
    if(pos==NO_OF_VERTICES+1)
        return true;
    else{
        for(int col=1; col<k+1; col++){
            if(isPresent(pos,col,colors)==false){
                colors[pos]=col;
                if(colorGraph(A,pos+1,k,colors))
                    return true;
            }
        }
        return false;
    }
}

bool isColorable(int A[NO_OF_VERTICES+1][NO_OF_VERTICES+1], int k){
    int colors[NO_OF_VERTICES + 1];
    for (int col = 1; col <= k; ++col){
        colors[1] = col;
        if (colorGraph(A, 2, k, colors))
        {
            for (int i=1;i<=NO_OF_VERTICES;++i)
                cout<<i<<": "<<colors[i]<<endl;
                return true;
        }
    }
    return false;
}

int main(){
    for (int col=1;col<=NO_OF_VERTICES;++col)
        if (isColorable(B,col))
            break;
        else
            cout<<"Cannot be coloured with "<<col<<" color(s)."<<endl;
    return 0;
}

