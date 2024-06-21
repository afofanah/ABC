/*
Author: Abdul Joseph Fofanah
https://github.com/afofanah
*/
#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
#include <cstdlib>

using namespace std;

size_t ex1(size_t A[], size_t n);

size_t ex2(size_t A[], size_t n);

size_t ex3(size_t A[], size_t n);

size_t ex4(size_t A[], size_t n);

size_t ex5(size_t A[], size_t B[], size_t n);

int main(int argc, char *argv[])
{
    argc = argc;

    // fill the array
    size_t size = atoi(argv[1]);
    cout << "Size: " << size << endl;
    size_t *A = new size_t[size];
    size_t *B = new size_t[size];
    for (size_t i = 0; i < size; i++)
    {
        A[i] = i;
        B[i] = i;
    }

    // start the time
    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    // Insert Algorithm Here!
    auto end = chrono::high_resolution_clock::now();

    double time_taken =
        static_cast<double>(
            chrono::duration_cast<chrono::nanoseconds>(end - start)
                .count());

    time_taken *= 1e-9;

    cout << fixed << time_taken << setprecision(9) << endl;

    return 0;
}

size_t ex1(size_t A[], size_t n)
{
    size_t s = A[0];
    for (size_t i = 0; i < n; i++)
        s = s + A[i];
    return s;
}

size_t ex2(size_t A[], size_t n)
{
    size_t s = A[0];
    for (size_t i = 2; i < n; i += 2)
        s = s + A[i];
    return s;
}

size_t ex3(size_t A[], size_t n)
{
    size_t s = 0;
    for (size_t i = 0; i < n; i++)
    {
        s = s + A[0];
        for (size_t j = 1; j < i; j++)
            s = s + A[j];
    }
    return s;
}

size_t ex4(size_t A[], size_t n)
{
    size_t s = A[0];
    size_t t = s;
    for (size_t i = 1; i < n; i++)
    {
        s = s + A[i];
        t = t + s;
    }
    return t;
}

size_t ex5(size_t A[], size_t B[], size_t n)
{
    size_t c = 0;
    for (size_t i = 0; i < n; i++)
    {
        size_t s = 0;
        for (size_t j = 0; j < n; j++)
        {
            s = s + A[0];
            for (size_t k = 1; k < j; k++)
                s = s + A[k];
        }
        if (B[i] == s)
            c = c + 1;
    }
    return c;
}
