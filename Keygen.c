/* the - scientist@rootstorm.com
 * spl0its-r-us security
 *
 * 100 % of the proceeds that wind up in these accounts will be donated to animal shelters.
 * ================================================================================================================
 * BITCOIN: bc1qc0x6qdsk7auhsrym6vz0rtafnl2qgqjk7yy3tn
 * ETHEREUM : 0x482d85E39Ce865Dcf7c26bFDD6e52AB203d0f555
 * DOGECOIN : DPYxWnnyYzmPYWP92iqo4DizJht3rZnYnu
 * LITECOIN : ltc1qea6ehaanwr9q3jygmw75q35avk8t74h7sc5uc3
 * ETHCLASSIC : 0x6C63D4428Cb6BfDB7AC72b447A8B29D811395052
 * CARDANO : addr1qxn4przua2crcrgwt3pk5465ym3syytfn2v7gssu7ayuvpvefqwdvkgzn4y3j5d5ynsh03kae9k8d0z8yuh8excuv6xqdl4kyt
 * ================================================================================================================
 */

#include <stdio.h>
#include <stdbool.h> 
#include <string.h> 
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#define         TIME_DELTA 1
#define         PRIME_RANGE_MIN 500 
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
main(int argc, char** argv)
{
        size_t n, e, blank, phi_n;

        n = product_of_primes(PRIME_RANGE_MIN, PRIME_RANGE_MAX);
        if (n == 0)
                err_exit("* product of primes was 0");

        phi_n = phi(n);
        sieve_of_eratosthenes(2, phi_n, &e, NULL);

        // compute d the modular multiplicitive inverse of e(mod Φ(n))
        // if n and e are coprime (or relatively prime) positive integers, then
        // aΦ(n) ≡ 1 (mod n) 
        ;

        // public key = (n, e)
        // private key = (n, d)
        ;
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
