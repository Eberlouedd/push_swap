/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:28:28 by kyacini           #+#    #+#             */
/*   Updated: 2022/12/26 17:50:06 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	norm(t_list **stack_a, t_list **stack_b, int *i)
{
	get_to_top_a(stack_a, get_element(*stack_a, *i));
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
	*i = 0;
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		med;
	int		max;
	char	**last;

	stack_b = NULL;
	if (!test_format(argc, argv, &med, &max) || argc == 1)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	last = final_parsing(argc, argv);
	stack_a = create_stack_a(last);
	free_double_char(last);
	if (!is_grinded(stack_a))
		the_grading_machine(&stack_a, &stack_b, med, max);
	clear(&stack_a);
	return (0);
}
