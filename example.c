#include "rootFinder.h"

double exampleFunc(double x);

int main(void)
{
   const int precision = 15;
   double *roots = binaryRootFinder(&exampleFunc, -100, 100, precision, 0.1);

   printf("Finded %d roots with precision to %d decimal places:\n", number_of_roots, precision);

   for (int i = 0; i < number_of_roots; i++)
      printf("\t\t%.16lf\n", roots[i]);

   free(roots);

   return 0;
}

double exampleFunc(double x)
{
   //return cos(pow(x, 3) + 5 * pow(x, 2) - 20 * x + 3.123 - 20); // cos(x^{3}+5x^{2}-20x+3.123-20)
   //return pow(x, 3) + 5 * pow(x, 2) - 20 * x + 3.123; // x^{3}+5x^{2}-20x+3.123
   return x * x - 5 * x * cos(x) + pow(2.71, x);
}