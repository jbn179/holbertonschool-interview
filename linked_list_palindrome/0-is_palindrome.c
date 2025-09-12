#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse - inverse une liste chaînée simple
 * @head: pointeur vers pointeur du premier nœud de la liste listint_t
 * Return: pointeur vers le premier nœud de la liste inversée
 */
listint_t *reverse(listint_t **head)
{
	listint_t *prev = NULL;   /* Nœud précédent (commence à NULL) */
	listint_t *current;       /* Nœud actuel en cours de traitement */
	listint_t *next;          /* Nœud suivant (pour éviter de le perdre) */

	current = *head;

	/* Parcourir la liste et inverser les liens */
	while (current != NULL)
	{
		next = current->next;    /* Sauvegarder le nœud suivant */
		current->next = prev;    /* Inverser le lien */
		prev = current;          /* Faire avancer prev */
		current = next;          /* Faire avancer current */
	}

	*head = prev;  /* Mettre à jour head vers le nouveau premier nœud */
	return (*head);
}

/**
 * is_palindrome - vérifie si une liste chaînée simple est un palindrome
 * @head: pointeur vers pointeur du premier nœud de la liste listint_t
 * Return: 0 si ce n'est pas un palindrome, 1 si c'est un palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow, *fast, *prev_slow;
	listint_t *second_half, *first_half, *second_half_head;
	int is_palindrome = 1;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	slow = *head;
	fast = *head;

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		prev_slow = slow;
		slow = slow->next;
	}

	prev_slow->next = NULL;
	second_half = reverse(&slow);

	first_half = *head;
	second_half_head = second_half;

	while (first_half != NULL && second_half != NULL)
	{
		if (first_half->n != second_half->n)
		{
			is_palindrome = 0;
			break;
		}
		first_half = first_half->next;
		second_half = second_half->next;
	}

	prev_slow->next = reverse(&second_half_head);
	return (is_palindrome);
}
