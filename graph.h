#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#define Node_Max 10 // Megistos arithmos komvon

// Domi sindemenis listas gia komvous (apo mathima domes dedomenon)
typedef struct node *NodePtr;
typedef struct node {
    int label;
    NodePtr next;
} Node;

// Domi gia akmes (diatetagmeno zeugari dyo arithmon)
typedef struct Edge {
	int src, dest;
} Edge;

//---------------------- Domi graphou--------------------
typedef struct graph *GraphPtr; //deiktis se domi
typedef struct graph {
	// Deiktes se listes (listes geitonikon komvon)
	NodePtr head[Node_Max];
	NodePtr tail[Node_Max];
} Graph;


GraphPtr createGraph(Edge edges[], int n); //edges[] einai pinakas me kathe stoixeio na einai mia Domi Edge
void printGraph(GraphPtr gr, int n);




#endif /* GRAPH_LIST_H_INCLUDED */
