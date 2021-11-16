/* 
 * A small library for public-key cryptography.
 * 
 * Resources:
 * https://en.wikipedia.org/wiki/Padding_(cryptography)
 * https://www.rfc-editor.org/rfc/rfc3447
 * https://www.rfc-editor.org/rfc/rfc8017
 * https://en.wikipedia.org/wiki/Euler%27s_totient_function
 * https://en.wikipedia.org/wiki/Euclidean_division#Proof
 * https://en.wikipedia.org/wiki/Modular_multiplicative_inverse
 * https://en.wikipedia.org/wiki/Prime_number_theorem
 * https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 * https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity
 * https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
 * https://en.wikipedia.org/wiki/Diophantine_equation
 * 
 * the-scientist@rootstorm.com
 * https://www.rootstorm.com
 */

#include <stdio.h>
#include <stdbool.h> 
#include <string.h> 
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#define         TIME_DELTA 1
#define         PRIME_RANGE_MIN 200 
#define         PRIME_RANGE_MAX 1000
#define         err_exit(s) do { perror(s); exit(EXIT_FAILURE); \
                                } while (0)
int
phi(int n);
bool
sieve_of_eratosthenes(size_t min, size_t max, size_t* p, size_t* q);
size_t
product_of_primes(size_t min, size_t max);
int
mod_inverse(int e, int m);


int
main(int argc, char** argv)
{
        size_t n, e, d, phi_n;

        n = product_of_primes(PRIME_RANGE_MIN, PRIME_RANGE_MAX);
        if (n == 0)
                err_exit("* product of primes was 0");

        phi_n = phi(n);
        sieve_of_eratosthenes(2, phi_n, &e, NULL);

        d = mod_inverse(e, phi_n);

        // public key = (n, e)
        // private key = (n, d)
}


int
mod_inverse(int e, int m)
{
        int m0, y, x, q, t;

        if (m == 1)
                return 0;

        m0 = m;
        y = 0;
        x = 1;
        while (e > 1) {
                q = e / m;
                t = m;

                m = e % m, e = t;
                t = y;

                y = x - q * y;
                x = t;
        }

        if (x < 0)
                x += m0;

        return x;
}


int
phi(int n)
{
        float result;

        result = n;
        for (int p = 2; p * p <= n; ++p) {
                if (n % p == 0) {
                        while (n % p == 0) {
                                n /= p;
                        }
                        result *= (1.0 - (1.0 / (float)p));
                }
        }

        if (n > 1)
                result *= (1.0 - (1.0 / (float)n));

        return (int)result;
}


size_t
product_of_primes(size_t min, size_t max)
{
        size_t p, q;

        if (sieve_of_eratosthenes(min, max, &p, &q) == false)
                return 0;
        return p * q;
}


bool
sieve_of_eratosthenes(size_t min, size_t max, size_t* p, size_t* q)
{
        bool prime[max + 1];
        size_t prime_list[max + 1];
        int p_index, q_index;

        if (min < 2 || max <= min)
                return false;

        memset(prime, true, sizeof(prime));

        sleep(TIME_DELTA);
        srand(time(NULL));

        for (int p = 2; p * p <= max; p++) {
                if (prime[p] == true) {
                        for (int i = p * p; i <= max; i += p)
                                prime[i] = false;
                }
        }

        int sz = 0;
        for (int p = min; p <= max; p++) {
                if (prime[p]) {
                        prime_list[sz] = p;
                        sz++;
                }
        }

        if (sz == 0)
                return false;

        p_index = rand() % sz;
        q_index = rand() % sz;
        while (q_index == p_index)
                q_index = rand() % sz;
        *p = prime_list[p_index];
        if (q != NULL)
                *q = prime_list[q_index];

        return true;
}
