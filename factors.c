#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct facts
{
	int p;
	int q;
} factor_t;

factor_t *factorize(int num, int *count)
{
	factor_t *factors;
	int n;

	*count = 0;
	factors = malloc(sizeof(factor_t) * sqrt(num));
	if (factors == NULL)
	{
		return (NULL);
	}
	for (n = 2; n <= sqrt(num); n++)
	{
		if (num % n == 0)
		{
			factors[*count].p = n;
			factors[*count].q = num / n;
			(*count)++;
		}
	}
	return (factors);
}
int main(int argc, char *argv[])
{
	char *filename;
	FILE *file;
	char line[200];
	int value, count, m;
	factor_t *factor_pair;

	if (argc != 2)
	{
		printf("Usage: factors <files>\n");
		return (1);
	}
	filename = argv[1];
	file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("File '%s' not found\n", filename);
		return (1);
	}
	while (fgets(line, sizeof(line), file))
	{
		value = atoi(line);
		factor_pair = factorize(value, &count);
		for (m = 0; m < count; m++)
		{
			printf("%d=%d*%d\n", value, factor_pair[m].p, factor_pair[m].q);
		}
		free(factor_pair);
	}
	fclose(file);
	return (0);
}
