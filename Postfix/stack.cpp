#include "stack_header.h"

bool IsEmptyNode(Node * &head)
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

int PushNode(Node * &head, string elem)
{
	Node *tmp = new Node;
	if (tmp == NULL) return 0;
	tmp->next = head;
	tmp->elem = elem;
	head = tmp;
	return 1;
}

string TopNode(Node * &head)
{
	if (IsEmptyNode(head))
	{
		return 0;
	}
	else
	{
		return head->elem;
	}
}

string PopNode(Node * &head)
{
	// проверка на Empty
	if (IsEmptyNode(head)) {

		return 0;
	}
	else
	{
		Node *out;
		string elem;

		out = head;
		head = head->next;
		elem = out->elem;
		delete out;
		return elem;
	}
}