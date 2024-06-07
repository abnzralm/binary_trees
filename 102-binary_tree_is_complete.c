#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_node - Creates a new levelorder_queue_t node.
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
 * push - Pushes a node to the back.
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *nw;

	nw = create_node(node);
	if (nw == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = nw;
	*tail = nw;
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
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *hd, *tl;
	unsigned char flg = 0;

	if (tree == NULL)
		return (0);

	hd = tl = create_node((binary_tree_t *)tree);
	if (hd == NULL)
		exit(1);

	while (hd != NULL)
	{
		if (hd->node->left != NULL)
		{
			if (flg == 1)
			{
				free_queue(hd);
				return (0);
			}
			push(hd->node->left, hd, &tl);
		}
		else
			flg = 1;
		if (hd->node->right != NULL)
		{
			if (flg == 1)
			{
				free_queue(hd);
				return (0);
			}
			push(hd->node->right, hd, &tl);
		}
		else
			flg = 1;
		pop(&hd);
	}
	return (1);
}
