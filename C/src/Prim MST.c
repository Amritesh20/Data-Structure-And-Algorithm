#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define V 5 //no of vertex

//print mst
void printmst(int parent[],int graph[V][V])
{
	int i;
	printf("Edge\tWeight\n");
	for(i=1;i<V;i++)
	printf("%d -> %d\t%d\n",parent[i],i,graph[i][parent[i]]);
}

//find minimum
int minkey(int key[],bool mstset[])
{
	int min=INT_MAX,min_index,v;
	for(v=0;v<V;v++)
		if(mstset[v]==false && key[v]<min)
			{
				min=key[v];
				min_index=v;
			}
	return min_index;
}

//primmst
void primmst(int graph[V][V])
{
	int parent[V],key[V],i,u,v,count;
	bool mstset[V];
	for(i=0;i<V;i++)
	{
		key[i]=INT_MAX;
		mstset[i]=false;
	}
	key[0]=0;
	parent[0]=-1;
	
	for(count=0;count<V;count++)
	{
		
		u=minkey(key,mstset);
		mstset[u]=true;
		
		for(v=0;v<V;v++)
		{
			if(graph[u][v] && mstset[v]==false && graph[u][v]<key[v])
			{
				parent[v]=u;
				key[v]=graph[u][v];
			}
		}
	}		
	printmst(parent,graph);
}


//DRIVER CODE
int main()
{
	 int graph[V][V] =  {
	 					{0, 2, 0, 6, 0},
{2, 0, 3, 8, 5},
{0, 3, 0, 0, 7},
{6, 8, 0, 0, 9},
{0, 5, 7, 9, 0},    
}; 
    primmst(graph);
    return 0;
}

