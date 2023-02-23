
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "stack.h"



int main(void)
{//-------------INPUT---------------------------------------
	// Edges Declaration
	Edge my_edge[] =
	{
		{1, 2}, {1, 3}, {2, 3}, {2, 4}, {4, 3}, {4, 5}, 
		{5, 6}, {6, 7}, {6, 8}, {7, 5}, {7, 8}
	};
	int Node_num = 8; //dilosi plithous komvon
//-----------------------------------------------------------	
	
	
	// Number of edges
	int Number_edges = sizeof(my_edge)/sizeof(my_edge[0]);

	//Graph construction using graph declaration from graph.h
	GraphPtr graph = createGraph(my_edge, Number_edges);

	// Graph print
	printf("\n \t  INITIAL graph \n\n");
	printGraph(graph, Number_edges);
	
//------------prospelasi DFS----------------------
	
	Stack node_stack; //Stack initialization
	init_stack(&node_stack);
	int dfnr[Node_Max] = {0};
	int theta[Node_Max]= {0}; // 0: means that node is not visited yet
	int visit_num=1;
	
	Edge dfs_edge[Number_edges];
	int dfs_edge_num = 0;

	int i = 1;//insert first node in stack (source node, is node number 1)
	NodePtr ptr = graph->head[i];
	dfnr[i]=visit_num;
	visit_num++;
	push(&node_stack, i);//----------------------
	
	while (!isempty(node_stack)) {//as long as the stack is not empty
		if (ptr != NULL) {  //if the node has neightbour 
			int next = ptr->label; //next neightbour
			if (dfnr[next] == 0) {  //if next neightbour has NOT been visited
				dfnr[next] = visit_num; //visit
				dfs_edge[dfs_edge_num].src =  i; //---------
				dfs_edge[dfs_edge_num].dest =  next; //--add edge to DFS sub-Graph
				dfs_edge_num++;
				visit_num++;
				theta[next] = i; // note the node from which the visit was made
				i = next; //the visited node is now the active node
				push(&node_stack, i); //push active node in stack
				ptr = graph->head[i]; //pointer, points to the connected list of the neightbours of the active node
			}
			else { // if next neightbour has BEEN VISITED BEFORE
				ptr = ptr->next; //look next neightbour
			}
		}
		else {   //if there is no next neightbour(that is un-visited)
			pop(&node_stack, &i); //delete active node from stack
			if (isempty(node_stack)) {break;} //if stack is empty exit loop
			i = node_stack.stack_array[node_stack.top]; // active node is the one that is on the top of th stack
			ptr = graph->head[i]; //pointer, points to the connected list of the neightbours of the active node
		}
	}
		printf("\n----RESULTS OF DFS ALGORITHM------\n");
	printf(" Visiting Sequence  \t   From node theta \n");
	for (int i=1; i<Node_num+1; i++){
		printf(" dfnr[ %d ] =  %d \t \t theta[ %d ] =  %d \n", i, dfnr[i], i, theta[i]);
	}
	
	
	printf("\n \t \t DFS sub-Graph \n\n");

	GraphPtr dfs_graph = createGraph(dfs_edge, dfs_edge_num);
	printGraph(dfs_graph, dfs_edge_num);
	
	return 0;
}
