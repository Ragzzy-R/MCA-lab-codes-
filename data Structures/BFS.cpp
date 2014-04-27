#include<iostream>
#define TRUE	1
#define FALSE	0
#define QUEUE_EMPTY	-1

using namespace std;

class RQueue {
public:
	int queue[100];
	int front;
	int rear;
	int count;
RQueue() {
	front = 0;
	rear = 0;
	count = 0;
}
int isEmpty() {
	
	if(front==rear) 
		return TRUE;
	else
		return FALSE;
}
		

void enqueue(int data) {
	queue[rear]=data;
	rear++;
	count++;
}

int dequeue() {
	int temp;
	if(isEmpty()) {
		return QUEUE_EMPTY;
	}
	else {
		temp=queue[front];
		for(int i=0;i<count;i++) {
			queue[i]=queue[i+1];
		}
		count--;
		rear--;
	}
	return temp;
}

void display() {
	for(int i=0;i<count;i++) {
		cout<<"|"<<queue[i]<<"|";
	}
}

};


class Graph {

public:
	int verticesCount;
	int adjMatrix[100][100];
	int visited[100];
	Graph(int n) {
		verticesCount=n;
		for(int i=1;i<100;i++) {
				visited[i]=0;
			for(int j=1;j<100;j++) {
				adjMatrix[i][j]=FALSE;
			}
		}
	}
	int addEdges(int v,int w) {
		adjMatrix[v][w]=TRUE;
	}
	void displayAdjacencyMatrix() {
		cout<<"  ";
		for(int g=1;g<=verticesCount;g++) {
			cout<<"  "<<g;
		}
		cout<<endl;
		cout<<"  ";
		for(int l=1;l<=verticesCount;l++) {
                        cout<<"---";
                }
		cout<<endl;
		for(int i=1;i<=verticesCount;i++) {
			cout<<i<<"|";
			for(int j=1;j<=verticesCount;j++) {
				
				cout<<"  "<<adjMatrix[i][j];
			}
			cout<<endl;
		}
	}
	
	void BFS(int s) {
		RQueue q;
		int v;	
		q.enqueue(s);
		visited[s]=TRUE;
		while(!(q.isEmpty())) {
			v= q.dequeue();
			cout<<v;
			for(int i=1;i<=verticesCount;i++) {
				if(adjMatrix[v][i]) {
					if(!(visited[i])) {
						q.enqueue(i);
						visited[i]=TRUE;
					}
				}
				
			}	
		}
		cout<<endl;
	}
};



int main() {
	int n,v,w;
	cout<<"Enter no of vertices";
	cin>>n;
	Graph g(n);
	for(int i=1;i<=n;i++) {
		w=0;
		cout<<"Enter the adjacencies  of node"<<i<<endl;
		cout<<"Enter -1 to move to next node"<<endl;
		while(w!=-1) {
			cin>>w;
			g.addEdges(i,w);
		}
	}
	/* g.addEdges(1,2);
	 g.addEdges(1,3);
 	 g.addEdges(2,3);
 	 g.addEdges(2,1);
	 g.addEdges(3,1);
	 g.addEdges(3,2);*/


	g.displayAdjacencyMatrix();
	g.BFS(1);
	
	return 0;
	
}

