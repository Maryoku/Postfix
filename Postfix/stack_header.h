#ifndef HEADER_NODE
#define HEADER_NODE

#include <string>

using namespace std;

struct Node
{
	string elem;
	Node *next;
};

struct Node_double
{
	double elem;
	Node_double *next;
};

bool IsEmptyNode(Node * &head);
int PushNode(Node * &head, string elem);
string TopNode(Node * &head);
string PopNode(Node * &head);

bool IsEmptyNode_num(Node_double* &head);
int PushNode_num(Node_double* &head, double elem);
double TopNode_num(Node_double* &head);
double PopNode_num(Node_double* &head);

#endif
