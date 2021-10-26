#include "rootFinder.h"

int number_of_roots = 0;

// Filter function to detect the roots over the (start - end) range
double *_findRoots(double start, double end, double dx, double (*func)(double))
{
   double *roots = (double *)malloc(sizeof(double) * 2);
   int capacity = 2;

   for (double i = start; i < end; i += dx)
   {
      if (func(i) * func(i + dx) < 0)
      {
         if (number_of_roots - 1 == capacity)
         {
            roots = realloc(roots, sizeof(double) * capacity * 2);
            capacity *= 2;
         }
         roots[number_of_roots] = i;
         number_of_roots++;
      }
   }
   return roots;
}

// Required precision is obtained with this function
double *binaryRootFinder(double (*func)(double), double start, double end, int precision, double search_step_size)
{
   double *roots = _findRoots(start, end, search_step_size, func);

   double mid;
   double midf;
   int iteration_count = ceil((precision + log10(search_step_size)) / log10(2));

   for (int j = 0; j < number_of_roots; j++)
   {
      double _start = roots[j], _end = roots[j] + search_step_size;
      mid = (_start + _end) / 2;

      for (int i = 0; i < iteration_count; i++)
      {
         midf = func(mid);
         if (midf * func(_start) < 0)
            _end = mid;
         else
            _start = mid;
         mid = (_start + _end) / 2;
      }
      roots[j] = mid;
   }

   // ERROR: |E| <= 1 / 2^(iteration_count)
   // precision might be disregarded if rounding happens when printing
   return roots;
}
