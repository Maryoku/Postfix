#include "header.h"

bool IsEmptyNode(Node *head)
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

bool PushNode(Node **head, char elem)
{
	Node *tmp = new Node;
	tmp->next = *head;
	tmp->elem = elem;
	*head = tmp;
	return 1;
}

int TopNode(Node *head)
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

int PopNode(Node **head)
{
	// проверка на Empty
	if (IsEmptyNode(*head)) {

		return 0;
	}
	else
	{
		Node *out;
		char elem;

		out = *head;
		*head = (*head)->next;
		elem = out->elem;
		delete out;
		return elem;
	}
}