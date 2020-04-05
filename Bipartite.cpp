//Monika Wielgus
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

const int numberOfVertices=8;

int A[numberOfVertices+1][numberOfVertices+1]={{0, 0, 0, 0, 0, 0, 0, 0, 0},
                                               {0, 0, 1, 0, 1, 1, 0, 0, 0},
                                               {0, 1, 0, 1, 0, 0, 1, 0, 0},
                                               {0, 0, 1, 0, 1, 0, 0, 1, 0},
                                               {0, 1, 0, 1, 0, 0, 0, 0, 1},
                                               {0, 1, 0, 0, 0, 0, 1, 0, 1},
                                               {0, 0, 1, 0, 0, 1, 0, 1, 0},
                                               {0, 0, 0, 1, 0, 0, 1, 0, 1},
                                               {0, 0, 0, 0, 1, 1, 0, 1, 0}};

int labels[numberOfVertices+1];
int neighbour(int v){
	for(int i=1; i<numberOfVertices+1; i++){
		if(A[v][i]==1&&i!=v)
			return i;
	}
	return -1;
}
bool isBipartite(){
   std::queue <int> qu;
   int v=1;
   int u;
   labels[v]=1;
   qu.push(v);
   while(!qu.empty()){
		u=qu.front();
		qu.pop();
		for(int i=1; i<numberOfVertices+1; i++){
			if(A[u][i]==1 && labels[i]==labels[u])
				return false;
			if(labels[i]==0 && A[u][i]==1 ){
				if(labels[u]==1)
					labels[i]=2;
				if(labels[u]==2)
					labels[i]=1;

				qu.push(i);
			}
		}
	}
   return true;
}

void display(){
    for (int i=1;i<=numberOfVertices;i++)
        if (labels[i]==1)
    cout<<i<<" ";
    cout<<endl;

    for (int i=1;i<=numberOfVertices;i++)
        if (labels[i]==2)
	cout<<i<<" ";
}
int main()
{
    if(isBipartite())
      display();
    else
      cout<<"Graph is not bipartite!"<<endl;
}
