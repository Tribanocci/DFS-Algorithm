//--------Onomata-------------ΑΜ----------------
//--------Eleni_Frantzi-------2020010133--------
//--------Elisavet_Manali-----2020010087--------
//--------Rafaillia_Platinaki-2020010126--------
//--------Rodopi_Viltanioti---2020010117--------
//----------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// Sinartisi gia thn dhmiourgia graphou
	// epistrefi deikti se grapho
GraphPtr createGraph(Edge edges[], int n)
{
	// desmeusi mnimis
	GraphPtr graph = (GraphPtr)malloc(sizeof(Graph));

	// arxikopoihsh liston gia geitones (arxika den deixnoun kapou)
	for (int i = 0; i < Node_Max; i++) {
		graph->head[i] = NULL;
		graph->tail[i] = NULL;
	}

	// nea akmi
	for (int i = 0; i < n; i++)
	{	
		// dilosi neas akmis apo komvo src se komvo dest
		int src = edges[i].src;
		int dest = edges[i].dest;

		// dimiourgia neou komvou apo tin dislosi tis akmis (apo to mathima Domes Dedomenon) 
		NodePtr newNode = (NodePtr)malloc(sizeof(Node));
		
		newNode->label = dest; //to deytero noumero tis akmis einai to onoma tou neou komvou
		if (graph->head[src] == NULL){
			
				// o neos komvos prepei na anoikei stin lista
			newNode->next = graph->head[src];
				
				// point head pointer to the new node
			graph->head[src] = newNode;
			graph->tail[src] = newNode;
		}
		
		
		else {
				// o neos komvos prepei na anoikei stin lista
			newNode->next = graph->tail[src]->next;
				
				// point head pointer to the new node
			graph->tail[src]->next = newNode;
			graph->tail[src] = newNode;
		}
			
		
	}
	return graph;
}

// ektiposi graphou
void printGraph(GraphPtr graph, int n)
{
	for (int i = 1; i < Node_Max; i++)
	{
		
		NodePtr ptr = graph->head[i];
		if (ptr == NULL) {;}
		else {
			while (ptr != NULL)
				{
					printf("(%d -> %d)\t", i, ptr->label);
					ptr = ptr->next;
				}
			printf("\n");
		}
	}
}




