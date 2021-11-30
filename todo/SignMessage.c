#include <stdio.h> 

int
main(int argc, char ** argv)
{
        // hash the message to broadcast
        // broadcast = "some message"
        // hash(broadcast)
        ;

        // compute the signature with private_key (n,d)
        // signatute = hash(broadcast)^d mod n
        ;

        // confirm a received broadcast message, and signature with public_key (n,e)
        // confirmation = hash(broadcast)^e mod n
        // confirmation should match signature. 

        return 0; 
}