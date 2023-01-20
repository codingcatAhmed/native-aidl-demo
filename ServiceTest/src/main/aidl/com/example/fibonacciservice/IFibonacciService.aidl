// This interface is a part of the fibonacci service which provides two functions for
// calculating the fibonacci number of a given integer 'n': fibR and fibL.
package com.example.fibonacciservice;

interface IFibonacciService {
    // Calculates the fibonacci number of 'n' using a recursive approach
    int fibR(int n);
    // Calculates the fibonacci number of 'n' using an iterative approach
    int fibL(int n);
}