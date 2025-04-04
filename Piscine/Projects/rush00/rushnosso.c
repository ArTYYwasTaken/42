/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemontei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:10:43 by kemontei          #+#    #+#             */
/*   Updated: 2025/03/02 20:31:34 by kemontei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char value)
{
	write(1, &value, 1);
}

void	rush_border(int x)// funcao das bordas (largura)
{
	int	widthCount = x - 2;// calcula o numero de Bs nas bordas (largura)
	int	widthIndex;
	widthIndex = 0;// index das bordas (largura)
	
	ft_putchar('A'); // comeca smp com A							Ex:rush(1, 1) - A

	while (widthIndex < widthCount)// loop quantidade de Bs para as bordas (largura)
	{
		ft_putchar('B');// escreve os Bs das bordas
		widthIndex++;
	}
    
	if (x > 1) // se ... vai escrever o C							Ex:rush(2, 2) - AC
	{//																				AC
	ft_putchar('C');
	}
}

void	rush_length(int x, int y, int spaceWidth)// funcao das paredes (altura)
{
	int	currentRow;
	int	spaceIndex;
	int	rowCount;
	rowCount = y - 2;// calcula o numero de paredes (altura)
	currentRow = 0;// index das paredes (altura)

	while (currentRow < rowCount) // loop numero de paredes (altura)
	{
		ft_putchar('B'); // escreve o B da primeira parede

		if (x > 1) // Ensures there is space in between when width is greater than 1
		{
			spaceIndex = 0;
			while (spaceIndex < spaceWidth) // escreve os espacos dentro das paredes
			{
				ft_putchar(' ');
				spaceIndex++;
			}
			ft_putchar('B'); // escreve o B da segunda parede
		}
		ft_putchar('\n');// prox linha
		currentRow++;
	}
}

void	rush(int x, int y)// funcao do retangulo
{
	int	spaceWidth;
	int	widthIndex;

	widthIndex = 0;// index das bordas
	spaceWidth = x - 2;// calcula os espacos dentro das paredes

	if(x <= 0 || y <= 0)// se x/y forem 0 ou negativos, programa n vai rodar
	{
		return;
	}
	ft_putchar('A'); // smp comeca com A							Ex:rush (1, 1) - A

	while (widthIndex < spaceWidth)// loop quantidade de Bs para as bordas (largura)
	{
		ft_putchar('B');// escreve B das bordas
		widthIndex++;
	}
	if(x > 1) // vai escrever o C								Ex:rush(2,2) -  AC
	{//																			AC
		ft_putchar('C');
	}

	ft_putchar('\n');

	if (y > 2) // vai meter as paredes B							Ex:rush(6, 3)-  ABBBBC
	{//																				B    B
		rush_length(x, y, spaceWidth);//											ABBBBC
	}

	if (y > 1)// se ... vai escrever a segunda borda					Ex:rush(4, 2) - ABBC
	{//																					ABBC
		rush_border(x);
	}
}
int main()
{
    rush(2, 4);
    return 0;
}

