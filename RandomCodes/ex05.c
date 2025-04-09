#include <unistd.h>
#include <stdbool.h>

void    ft_putchar(char value)
{
    write(1, &value, 1);
}
void    ft_result(char n1, char n2, char n3)
{
    bool last_char;

    ft_putchar(n1);
    ft_putchar(n2);
    ft_putchar(n3);

    last_char = !(n1 == '7' && n2 == '8' && n3 == '9');

    if(last_char)
    {
        ft_putchar(';');
        ft_putchar(' ');
    }
}

int main()
{
    char n1;
    char n2;
    char n3;

    n1 = '0';
    while (n1 <= '7')
    {
        n2 = n1 + 1;
        while (n2 <= '8')
        {
            n3 = n2 + 1;
            while (n3 <= '9')
            {
                ft_result(n1, n2, n3);
                n3++;
            }
            n2++;
        }
        n1++;
    }
    return 0;
}