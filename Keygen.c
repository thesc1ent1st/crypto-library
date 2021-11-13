#include <stdio.h>
#include <stdbool.h> 

int*
sieve_of_eratosthenes(size_t n);

int
main(int argc, char** argv)
{
        // TODO:
        // pick 2 primes : n = p * q
        // int* primes = sieve_of_eratosthenese(num to find primes up to);  
        // p = primes[rand(seed) % sizeof B]
        // q = primes[rand(seed) % sizeof B]
        ;

        // compute Euler totient of n
        ;

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

int*
sieve_of_eratosthenes(size_t n)
{
        //algorithm Sieve of Eratosthenes is
        //        input: an integer n > 1.
        //        output: all prime numbers from 2 through n.
        //
        //        let A be an array of Boolean values, indexed by integers 2 to n,
        //        initially all set to true.

        //        for i = 2, 3, 4, ..., not exceeding √n do
        //            if A[i] is true
        //                for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n do
        //                    A[j] := false
        //        return all i such that A[i] is true.
}
