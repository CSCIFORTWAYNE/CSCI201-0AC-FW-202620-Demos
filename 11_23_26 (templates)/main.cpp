#include <iostream>

/* int max(int x, int y);
double max(double x, double y);
long max(long x, long y);
short max(short x, short y);
float max(float x, float y); */
template <class t>
t max(t x, t y);

int main()
{
    int one = max(3, 4);
    long two = max(3L, 4L);
    short three = max(3, 4);
    float four = max(3.0f, 4.0f);
    double five = max(3.0, 4.0);

    return 0;
}

/* int max(int x, int y)
{
    if (x >= y)
        return x;
    else
        return y;
}

double max(double x, double y)
{
    if (x >= y)
        return x;
    else
        return y;
}

long max(long x, long y)
{
    if (x >= y)
        return x;
    else
        return y;
}

float max(float x, float y)
{
    if (x >= y)
        return x;
    else
        return y;
}

short max(short x, short y)
{
    if (x >= y)
        return x;
    else
        return y;
} */

template <class t>
t max(t x, t y)
{
    if (x >= y)
        return x;
    else
        return y;
}