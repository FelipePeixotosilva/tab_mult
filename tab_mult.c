#include <unistd.h>
#include <stdio.h>

void putnbr(int nbr)
{
	char c;
	if(nbr >= 0 && nbr <= 9)
	{
		c = nbr + '0';
		write(1,&c,1);
	}
	else
	{
		putnbr(nbr/10);
		putnbr(nbr%10);
	}
}

int ft_atoi(char *str)
{

	int i;
	i = 0;
	int m;
	m = 1;
	int s;
	s = 0;

	while(str[i] >= '\t' && str[i] <= '\r' || str[i]== ' ' || str[i]== '+')
	{
		i++;
		if(str[i] == '+')
		{
			i++;
		}
	}
	if(str[i] == '-')
	{
		m= -1;
		i++;
	}

	while(str[i] >= '0' && str[i] <= '9' && str[i])
	{
		s = s * 10 + (str[i] - '0');
		i++;
	}
	return s * m;
}
int main(int argc, char **argv)
{
	int i;
	i = 1;
	int m;
	int val;
	int cont;
	cont = 0;
	int key = 0;
	char **c;

	if(argc == 2)
	{
		while(argv[1][cont])
		{
			if(argv[1][cont] >= '0' && argv[1][cont] <= '9')
			{
				key = 0;
			}
			else
			{
				key = 1;
				break;
			}
			cont++;
		}
		cont = 0;
		c = &argv[1];
		val = ft_atoi(argv[1]);
		while(i < 10 && key ==0)
		{
			putnbr(i);
			write(1," ",1);
			write(1,"x",1);
			write(1," ",1);
			while(argv[1][cont])
			{
				write(1,&argv[1][cont],1);
				cont++;
			}
			write(1," ",1);
			write(1,"=",1);
			m = val * i;
			write(1," ",1);
			putnbr(m);
			write(1,"\n",1);
			cont = 0;
			i++;

		}

	}
	else
	{
	write(1,"\n",1);
	}
}
