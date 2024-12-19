#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

double calculateAverage(int count, ...)
{
    double sum = 0;
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++)
    {
        sum += va_arg(args, double);
    }

    va_end(args);

    double average = sum / count;
    return average;
}

int main()
{
    double avg = calculateAverage(4, 2.5, 3.7, 1.2, 4.8);
    printf("Average: %.2f\n", avg);

    return 0;
}