#include "stack_header.h"

bool IsEmptyNode_num(Node_double* &head)
{
	if (head == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int PushNode_num(Node_double* &head, double elem)
{
	Node_double *tmp = new Node_double;
	if (tmp == NULL) return 0;
	tmp->next = head;
	tmp->elem = elem;
	head = tmp;
	return 1;
}

double TopNode_num(Node_double* &head)
{
	if (IsEmptyNode_num(head))
	{
		return 0;
	}
	else
	{
		return head->elem;
	}
}

double PopNode_num(Node_double* &head)
{
	// проверка на Empty
	if (IsEmptyNode_num(head)) {

		return 0;
	}
	else
	{
		Node_double *out;
		double elem;

		out = head;
		head = head->next;
		elem = out->elem;
		delete out;
		return elem;
	}
}