#include "ft_printf.h"
#include "libft.h"
#include "stdio.h"

int	main()
{
	int		test;
	int 	nat_test;
	char	*str;
	int		it;

	it = 0;
	str = "%%c";
	test = ft_printf("dgs%dxx\n", 10);
	nat_test = printf("dgs%dxx\n", 10);
	printf("%d\n", nat_test);
	printf("%d\n", test);
	return (0);
}
