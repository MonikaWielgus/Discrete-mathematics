//Monika Wielgus
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;
bool isPresent(int **A, int position, int col, int colors[], int size){
    for(int i=1; i<=position; i++){
        if((A[i][position]==1)&&(col==colors[i])) //if it is a neighbour with such color
            return true;
    }
    return false;
}

bool colorGraph(int **A, int position, int noOfColors, int colors[], int size){
    if(position==size+1)
        return true;
    else{
        for(int col=1; col<=noOfColors; col++){
            if(!isPresent(A,position,col,colors,size)){
                colors[position]=col;
                if(colorGraph(A,position+1,noOfColors,colors,size))
                    return true;
            }
        }
        return false;
    }
}

bool isColorable(int **A, int noOfColors, int size){
    int colors[size+1]; //colors for vertices
    for(int col=1; col<=noOfColors; col++){
        colors[1]=col;
        if(colorGraph(A,2,noOfColors,colors,size)){
            for(int j=1; j<=noOfColors; j++){
                cout << "Day " << j << ": ";
                for (int i=1; i<=size; i++){
                    if(colors[i]==j)
                        cout << i << " ";
                }
                cout << endl;
            }
            return true;
        }
    }
    return false;
}

int neighboursColors(int **A, int position, int colors[], int size){
    int color=1;
    int neighboursColors[position+1]; //on index i we have 1 if any neigbour has such color and if not we have -1
    for(int i=1; i<=position; i++)
        neighboursColors[i]=-1;

    for(int i=1; i<=position; i++)
        if(A[i][position]==1) //it is a neighbour
           neighboursColors[colors[i]]=1;

    for(int i=1; i<=position; i++){
        if(neighboursColors[i]==-1){ //first free color
            color=i;
            break;
        }
    }
    return color;
}
void colorGraph2(int **A, int size){
    int maxColor=0;
    int colors[size+1];
    for(int i=1; i<=size; i++)
        colors[i]=0;

    for(int i=1; i<=size; i++){
        colors[i]=neighboursColors(A,i,colors,size);
        if(colors[i]>maxColor)
            maxColor=colors[i];
    }

    for(int j=1; j<=maxColor; j++){
        cout << "Day " << j << ": ";
        for (int i=1; i<=size; i++){
            if(colors[i]==j)
            cout << i << " ";
        }
        cout << endl;
    }
}
void foo(string name){
    int N=0;

    fstream file;
    string text;

    file.open(name, ios::in);
    getline(file,text);
    N=atoi(text.c_str()); //size of matrix

    int** A = new int*[N+1];
    for(int i = 0; i < N+1; i++)
        A[i] = new int[N+1];

    for(int i=1;i<N+1;i++)
        for(int j=1;j<N+1;j++)
            A[i][j]=1;

    int number1;
    int number2;

    while(!file.eof()){//creating matrix
        getline(file, text, ' ');
        number1=atoi(text.c_str());
        getline(file, text);
        number2=atoi(text.c_str());
        A[number1][number2]=A[number2][number1]=0;
    }

    cout << "Optimal coloring: " << endl;
    for(int noOfColors=1;noOfColors<=N;noOfColors++)
        if (isColorable(A,noOfColors,N))
            break;

    cout << "Non-optimal coloring: " << endl;
    colorGraph2(A,N);

    for (int i = 0; i<N+1; i++)
        delete [] A[i];

    delete [] A;

}
int main(){
    foo("data.txt");
}
