#include <iostream>

using namespace std;

const int N=6;
int chessboard[N][N];

class position{
    public:
        int x;
        int y;
};

position isMovePossible(int A[N][N],int attempt, int x, int y){
    position result;
    result.x=-1;
    result.y=-1;
    switch(attempt){
        case 1:
            if(x-2>=0&&y-1>=0)
                if(A[y-1][x-2]==0){
                        result.x=x-2;
                        result.y=y-1;
                    }
            break;
        case 2:
            if(x-1>=0&&y-2>=0)
                if(A[y-2][x-1]==0){
                    result.x=x-1;
                    result.y=y-2;
                }
            break;
        case 3:
            if(x+1<N&&y-2>=0)
                if(A[y-2][x+1]==0){
                    result.x=x+1;
                    result.y=y-2;
                }
            break;
        case 4:
            if(x+2<N&&y-1>=0)
                if(A[y-1][x+2]==0){
                    result.x=x+2;
                    result.y=y-1;
                }
            break;
        case 5:
            if(x+2<N&&y+1<N)
                if(A[y+1][x+2]==0){
                    result.x=x+2;
                    result.y=y+1;
                }
            break;
        case 6:
            if(x+1<N&&y+2<N)
                if(A[y+2][x+1]==0){
                    result.x=x+1;
                    result.y=y+2;
                }
            break;
        case 7:
            if(x-1>=0&&y+2<N)
                if(A[y+2][x-1]==0){
                    result.x=x-1;
                    result.y=y+2;
                }
            break;
        case 8:
            if(x-2>=0&&y+1<N)
                if(A[y+1][x-2]==0){
                    result.x=x-2;
                    result.y=y+1;
                }
            break;
    }
    return result;

}

bool isReturnPossible(int A[N][N], int x, int y){
    if((x-1==0&&y+2==N-1)||(x-2==0&&y+1==N-1)||(x-1==N-1&&y+2==0)||(x-2==N-1&&y+1==0))
        return true;
    else
        return false;
}

bool way(int A[N][N], int x, int y, int checked){
    if(N%2!=0)
        return false;

    A[y][x]=checked;
    if(checked==N*N&&isReturnPossible(A,x,y)){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(A[i][j]<10)
                    cout << A[i][j] << "  ";
                else
                    cout << A[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    else{
        for(int i=1; i<=8; i++){
            position result=isMovePossible(A,i,x,y);
            if(result.x!=-1)
                if(way(A,result.x,result.y,checked+1))
                    return true;
        }
        A[y][x]=0;
    }
    return false;
}

int main(){
    if(!way(chessboard,0,N-1,1))
        cout << "It is not possible!" << endl;
}
