// -*- C++ -*-
// **Arithmetic Functions**
// **Author:** Wahh R. S.
#ifndef ARITHMETIC_H  
#define ARITHMETIC_H
// **Include Necessary Libraries**
#include <cmath>

namespace wrs
{
// **WRS Namespace**

/*
* **Function Name:**  bsqrt
* **Description:**  Calculates the square root of a number using the Babylonian method.
* **Input:**  double n - The number to calculate the square root of.
* **Output:** double - The square root of the input number.
*/
double bsqrt(double n) {
  // Initialize variables
  double guess = n / 2;
  double r;

  // Refine the approximation using the Babylonian method
  for (int i = 0; i < 10; i++) {
    r = n / guess;
    guess = (guess + r) / 2;
  }

  return guess;
}

/*
* **Function Name:** gcd
* **Description:**  Calculates the greatest common divisor (GCD) of two integers using the Euclidean algorithm.
* **Input:**  int a, int b - The two integers to calculate the GCD of.
* **Output:** int - The GCD of the input integers.
*/
int gcd(int a, int b) {
  while (b != 0) {
    int t = b;
    b = a % b;
    a = t;
  }

  return a;
}

/*
* **Function Name:** convertToLowestTerms
* **Description:**  Converts a fraction to its lowest terms by dividing both the numerator and denominator by their greatest common divisor (GCD).
* **Input:**  int &numerator, int &denominator - The numerator and denominator of the fraction to convert.
* **Output:** bool - True if the conversion was successful, false if the denominator is zero.
*/
bool convertToLowestTerms(int &numerator, int &denominator) {
  int greatest = gcd(numerator, denominator);

  // Divide both numerator and denominator by the GCD
  numerator /= greatest;
  denominator /= greatest;

  return denominator == 0 ? false : true;
}

/*
* **Function Name:** goldenSequence
* **Description:**  Calculates the nth Fibonacci number using a recursive approach.
* **Input:**  int n - The index of the Fibonacci number to calculate.
* **Output:** int - The nth Fibonacci number.
*/
int goldenSequence(int n) {
  // Initialize variables
  int previous = 0, target = 1, number;

  // Calculate the Fibonacci sequence using recursion
  for (int i = 1; i <= n; ++i) {
    if (i == 1) {
      return previous;
    } else if (i == 2) {
      return target;
    }

    number = previous + target;
    previous = target;
    target = number;
  }

  return number;
}

/*
* **Function Name:** isPrime
* **Description:**  Checks whether an integer is prime or not.
* **Input:**  int num - The integer to check for primality.
* **Output:** bool - True if the input integer is prime, false otherwise.
*/
bool isPrime(int num) {
  // Check if the number is divisible by any number between 2 and itself (exclusive)
  for (int i = 2; i < num; i++) {
    if (num % i == 0) {
      return false;
    }
  }

  return true;
}

/*
* **Function Name:** PAn
* **Description:**  Calculates the nth term of an arithmetic progression (A.P.).
* **Input:**  double A1 - The first term of the A.P.
*         int n - The index of the term to calculate.
*         double r - The common difference of the A.P.
* **Output:** double - The nth term of the A.P.
*/
double PAn(double A1, int n, double r) {
  return A1 + ((n - 1) * r);
}
// **Function Name:** maPA
// **Description:** Calculates the median of an arithmetic progression (A.P.).
// **Input:**  double Ak - The kth term of the A.P.
//         double r - The common difference of the A.P.
// **Output:** double - The median of the A.P.
double maPA(double Ak, double r) {
  // Calculate the middle term of the A.P.
  return ((Ak - r) + (Ak + r)) / 2;
}

/*
* **Function Name:** sumPA
* **Description:**  Calculates the sum of an arithmetic progression (A.P.).
* **Input:**  double A1 - The first term of the A.P.
*         int n - The index of the last term of the A.P.
*         double r - The common difference of the A.P.
* **Output:** double - The sum of the A.P.
*/
double sumPA(double A1, int n, double r) {
  // Calculate the nth term of the A.P.
  double An = PAn(A1, n, r);

  // Use the formula for the sum of an A.P.
  return ((A1 + An) * n) / 2;
}

/*
* **Function Name:** PGn
* **Description:**  Calculates the nth term of a geometric progression (G.P.).
* **Input:**  double A1 - The first term of the G.P.
*         int n - The index of the term to calculate.
*         double q - The common ratio of the G.P.
* **Output:** double - The nth term of the G.P.
*/
double PGn(double A1, int n, double q) {
  // Use the formula for the nth term of a G.P.
  return A1 * pow(q, n - 1);
}

/*
* **Function Name:** modPG
* **Description:**  Calculates the mean of an infinite geometric progression (G.P.).
* **Input:**  double Ak - The kth term of the G.P.
*         double q - The common ratio of the G.P.
* **Output:** double - The mean of the infinite G.P.
*/
double modPG(double Ak, double q) {
  // Use the formula for the mean of an infinite G.P.
  return sqrt((Ak / q) * (Ak * q));
}
/*
// **Description:** Calculates the sum of an infinite geometric progression (G.P.).
// **Input:**  double A1 - The first term of the G.P.
//         int n - The index of the last term of the G.P.
//         double q - The common ratio of the G.P.
// **Output:** double - The sum of the infinite G.P.
double sumPGinf(double A1, int n, double q) {
  // Use the formula for the sum of an infinite G.P.
  return A1 / (1 - q);
}

/*
* **Function Name:** prodPG
* **Description:**  Calculates the product of a finite geometric progression (G.P.).
* **Input:**  double A1 - The first term of the G.P.
*         int n - The index of the last term of the G.P.
*         double q - The common ratio of the G.P.
* **Output:** double - The product of the G.P.
*/
double prodPG(double A1, int n, double q) {
  // Calculate the nth term of the G.P.
  double An = PGn(A1, n, q);

  // Use the formula for the product of a G.P.
  return sqrt(pow(A1 * An, n));
}
} // namespace wrs

#endif /*ARITHMETIC_H*/
