#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern int number_of_roots;

double *binaryRootFinder(double (*func)(double), double start, double end, int precision, double search_step_size);