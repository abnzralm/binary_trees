#include "binary_trees.h"


levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_node - Creates a new levelorder_queue_t.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *nw;

	nw = malloc(sizeof(levelorder_queue_t));
	if (nw == NULL)
		return (NULL);

	nw->node = node;
	nw->next = NULL;

	return (nw);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tpp;

	while (head != NULL)
	{
		tpp = head->next;
		free(head);
		head = tpp;
	}
}

/**
 * pint_push - Runs a function on a given binary tree node
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 * @func: A pointer to the function to call on @node.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *nw;

	func(node->n);
	if (node->left != NULL)
	{
		nw = create_node(node->left);
		if (nw == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = nw;
		*tail = nw;
	}
	if (node->right != NULL)
	{
		nw = create_node(node->right);
		if (nw == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = nw;
		*tail = nw;
	}
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tpp;

	tpp = (*head)->next;
	free(*head);
	*head = tpp;
}

/**
 * binary_tree_levelorder - Traverses a binary tree
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *hd, *til;

	if (tree == NULL || func == NULL)
		return;

	hd = til = create_node((binary_tree_t *)tree);
	if (hd == NULL)
		return;

	while (hd != NULL)
	{
		pint_push(hd->node, hd, &til, func);
		pop(&hd);
	}
}
