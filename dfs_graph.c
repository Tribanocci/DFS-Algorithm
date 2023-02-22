//--------Onomata-------------ΑΜ----------------
//--------Eleni_Frantzi-------2020010133--------
//--------Elisavet_Manali-----2020010087--------
//--------Rafaillia_Platinaki-2020010126--------
//--------Rodopi_Viltanioti---2020010117--------
//----------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "stack.h"



int main(void)
{//-------------INPUT---------------------------------------
	// dilosi akmon
	Edge akmes[] =
	{
		{1, 2}, {1, 3}, {2, 3}, {2, 4}, {4, 3}, {4, 5}, 
		{5, 6}, {6, 7}, {6, 8}, {7, 5}, {7, 8}
	};
	int Node_num = 8; //dilosi plithous komvon
//-----------------------------------------------------------	
	
	
	// ypologismos plithous akmon
	int Plith_akmon = sizeof(akmes)/sizeof(akmes[0]);

	//dhmiourgia graphou apo thn domi sto graph.h
	GraphPtr graph = createGraph(akmes, Plith_akmon);

	// ektiposi graphou
	printf("\n \t  ARXIKO graphima \n\n");
	printGraph(graph, Plith_akmon);
	
//------------prospelasi DFS----------------------
	
	Stack node_stack; //Dimiourgia stoivas (apo mathima domes dedomenon)
	init_stack(&node_stack);
	int dfnr[Node_Max] = {0};
	int theta[Node_Max]= {0}; // To 0 simainei oti o komvos den exei eksereunithei akoma
	int visit_num=1;
	
	Edge dfs_akmes[Plith_akmon];
	int dfs_akmes_num = 0;

	int i = 1;//eisagogi protou komvoy stin stoiva
	NodePtr ptr = graph->head[i];
	dfnr[i]=visit_num;
	visit_num++;
	push(&node_stack, i);//----------------------
	
	while (!isempty(node_stack)) {//oso iparxoun nodes tin stoiva
		if (ptr != NULL) {  //an o komvos exi epomeno geitona
			int next = ptr->label; //epomenos geitons
			if (dfnr[next] == 0) {  //ean o epomenos geitones DEN exei episkepi apo prin
				dfnr[next] = visit_num; //episkepsi
				dfs_akmes[dfs_akmes_num].src =  i; //---------
				dfs_akmes[dfs_akmes_num].dest =  next; //--prosthesi akmis sto DFS ypographima
				dfs_akmes_num++;
				visit_num++;
				theta[next] = i; // simiosi komvou proelesis tis episkepsis
				i = next; //o komvos pou episkeftikame ginetai o energos komvos
				push(&node_stack, i); //eisagosi energou komvou sthn stoiva
				ptr = graph->head[i]; //deixnoume stin lista me tous geitones tou energou komvou
			}
			else { // ean o epomenos geitones EXEI episkepi apo prin
				ptr = ptr->next; //koitame ton epomeno geitona
			}
		}
		else {   //ean o komvos DEN exei epomeno geitona (pou na min exi episkeftei apo prin)
			pop(&node_stack, &i); //afairesi tou komvo apo tin stoiva
			if (isempty(node_stack)) {break;} //an den iparxoun pleon alloi komvoi sthn stoiva TERMATISMOS
			i = node_stack.stack_array[node_stack.top]; // o active komvos einai tora o teleutaios komvos tis stoivas
			ptr = graph->head[i]; //deixnoume stous geitones tou active komvou
		}
	}
		printf("\n----APOTELESMATA ALGORITHMOU DFS------\n");
	printf(" Seira episkepis  \t   Apo ton komvo theta \n");
	for (int i=1; i<Node_num+1; i++){
		printf(" dfnr[ %d ] =  %d \t \t theta[ %d ] =  %d \n", i, dfnr[i], i, theta[i]);
	}
	
	
	printf("\n \t \t DFS ypo graphima \n\n");

	GraphPtr dfs_graph = createGraph(dfs_akmes, dfs_akmes_num);
	printGraph(dfs_graph, dfs_akmes_num);
	
	return 0;
}
