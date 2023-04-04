#include "monty.h"

/**
 * push - Adds values to the tippy top of the stack
 * @stack: Head of the stack
 * fix on github
 * @line_number: Line number of monty file
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *tippy_top = NULL;

	(void)line_number;
	tippy_top = (*stack);
	tippy_top = malloc(sizeof(stack_t));
	if (tippy_top == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_list(global_variable.stack);
		fclose(global_variable.file);
		exit(EXIT_FAILURE);
	}

	tippy_top->n = atoi(global_variable.number);
	tippy_top->next = *stack;
	tippy_top->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = tippy_top;
	*stack = tippy_top;

}


/**
 * pall - print all function
 * @stack: pointer to linked list stack
 * @line_number: number a line opcode occurs on
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *printall;

	printall = (*stack);
	(void) line_number;
	while (printall != NULL)
	{
		printf("%d\n", printall->n);
		printall = printall->next;
	}
}


/**
 * pop - remvove element a list
 * @stack: pointer to first node
 * @line_number: integer
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *bye_felicia = NULL;

	(void) line_number;
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_list(global_variable.stack);
		fclose(global_variable.file);
		exit(EXIT_FAILURE);
	}
	while (bye_felicia->prev != NULL)
	{
		bye_felicia = bye_felicia->prev;
	if (bye_felicia->next != NULL)
	{
		bye_felicia->next->prev = NULL;
	}
	if (bye_felicia == *stack)
	{
		if ((*stack)->next != NULL)
		{
			(*stack) = (*stack)->next;
		}
		else
		{
			(*stack) = NULL;
		}
	}
	free(bye_felicia);
	}
}

/**
 * pint - Prints value at the top of the stack + newline
 * @stack: Struct stack_s as stack_t **ptr
 * @line_number: File line number
 * Return: Nothing (void)
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if (stack == NULL || (*stack) == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_list(global_variable.stack);
		fclose(global_variable.file);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}
