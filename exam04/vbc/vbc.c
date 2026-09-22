/* vbc - evaluates a math expression with +, * and parentheses.
 *
 * Strategy for the exam: recursive descent parser that computes the
 * result on the fly (no AST needed, which is the easiest correct way).
 *
 * Grammar (lowest precedence first):
 *   expr    := product ( '+' product )*
 *   product := atom ( '*' atom )*
 *   atom    := DIGIT | '(' expr ')'
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char	*input;	/* global cursor into argv[1] */

void	unexpected(char c)
{
	if (c)
		printf("Unexpected token '%c'\n", c);
	else
		printf("Unexpected end of input\n");
	exit(1);
}

int	parse_expr(void);

/* atom := DIGIT | '(' expr ')' */
int	parse_atom(void)
{
	int	value;

	if (*input == '(')
	{
		input++;
		value = parse_expr();
		if (*input != ')')
			unexpected(*input);
		input++;
	}
	else if (isdigit(*input))
	{
		value = *input - '0';
		input++;
	}
	else
		unexpected(*input);
	return (value);
}

/* product := atom ( '*' atom )*   -- * binds tighter than + */
int	parse_product(void)
{
	int	value;

	value = parse_atom();
	while (*input == '*')
	{
		input++;
		value = value * parse_atom();
	}
	return (value);
}

/* expr := product ( '+' product )* */
int	parse_expr(void)
{
	int	value;

	value = parse_product();
	while (*input == '+')
	{
		input++;
		value = value + parse_product();
	}
	return (value);
}

int	main(int argc, char **argv)
{
	int	result;

	if (argc != 2)
		return (1);
	input = argv[1];
	result = parse_expr();
	if (*input != '\0')
		unexpected(*input);
	if (printf("%d\n", result) < 0)
		return (1);
	return (0);
}
