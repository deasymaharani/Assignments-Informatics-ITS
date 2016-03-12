#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

typedef pair<int, int> neighbor;
typedef vector<neighbor> neighborList; 

int main()
{
	vector<neighborList> adjList;
	int V, weight, child;
	
	cout<<"masukkan jumlah vertex";
	cin>> V;
	adjList.assign(V, neighborList()); 
	
	for(int i=0;i<V;i++)
	{
		for(int j=0;i<V;i++)
		{
			cin>>child;
			cin>>weight;	
			adjList[i].push_back(neighbor(child, weight));
		}
	}
	
	printf("Neighbors of vertex 0:\n");
  	for (neighborList::iterator j = adjList[0].begin(); j != adjList[0].end(); j++)
    	cout<<"edge: "<< j->first <<"weight: " << j->second;	
}
