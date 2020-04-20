//Monika Wielgus
#include <iostream>
#include <stack>

using namespace std;

const int NO_OF_VERTICES=6;

int A[NO_OF_VERTICES+1][NO_OF_VERTICES+1]={{0,0,0,0,0,0,0},
                                           {0,0,1,1,1,1,0},
                                           {0,1,0,1,1,0,1},
                                           {0,1,1,0,0,1,1},
                                           {0,1,1,0,0,1,1},
                                           {0,1,0,1,1,0,1},
                                           {0,0,1,1,1,1,0}};

int neighbour(int v){
	for(int i=1; i<NO_OF_VERTICES+1; i++){
		if(A[v][i]==1&&i!=v)
			return i;
    }
	return -1;
}

void euler(int start_vertex){
	std::stack <int> st;
	std::stack <int> circuit;
	int v=start_vertex;
	int u;
	st.push(v);
	while(!st.empty()){
		v=st.top();
		if(neighbour(v)>0){
			u=neighbour(v);
			st.push(u);
			A[v][u]=A[u][v]=0;
		}
		else{
			st.pop();
			circuit.push(v);
		}
	}
	while(!circuit.empty()){
		cout << circuit.top() << endl;
		circuit.pop();
	}
}

void removeEdge(int v, int u){
	A[u][v]=0;
	A[v][u]=0;
}

int main()
{
/*	removeEdge(1,4);
	removeEdge(2,4);
	removeEdge(1,5);
	removeEdge(3,5);
	removeEdge(2,6);
	removeEdge(3,6);*/
    euler(2);
    return 0;
}


