#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long double ldbl;

struct result {
	ldbl x_one;
	ldbl x_two;
};

struct result quad(ldbl a, ldbl b, ldbl c);

int main()
{
	long double a = 2.0L;
	long double b = 2.0L;
	long double c = -9.0L;

	struct result result = quad(a, b, c);

	printf("x1 = %.2Lf\n", result.x_one);
	printf("x2 = %.2Lf\n", result.x_two);

	puts("\n The End ...\n");
	return EXIT_SUCCESS;
}

struct result quad(ldbl a, ldbl b, ldbl c)
{
	ldbl delta = sqrtl((b * b) - (4 * a * c));
	struct result rsl = {
		.x_one = ((-1) * (b) + delta) / (2 * a),
		.x_two = ((-1) * (b)-delta) / (2 * a),
	};
	return rsl;
}
