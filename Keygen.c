#include <stdio.h>
#include <stdbool.h> 
#include <string.h> 
#include <time.h>
#include <stdlib.h>
#include <errno.h>

#define         PRIME_RANGE_MIN 500 
#define         PRIME_RANGE_MAX 1000
#define         err_exit(s) do { perror(s); exit(EXIT_FAILURE); \
                                } while (0)

bool
sieve_of_eratosthenes(size_t min, size_t max, size_t* p, size_t* q);
size_t
product_of_primes(size_t min, size_t max);

int
main(int argc, char** argv)
{
        size_t n;

        n = product_of_primes(PRIME_RANGE_MIN, PRIME_RANGE_MAX);
        if (n == 0)
                err_exit("* product of primes was 0");

        // pick random number e such that
        // 1 < e < totient(n)
        // e is coprime with totient(n)
        ;

        // compute d the modular multiplicitive inverse of e(mod totient(n))
        ;

        // public key = (n, e)
        // private key = (n, d)
        ;
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
        srand(time(0));

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
        *q = prime_list[q_index];

        return true;
}
