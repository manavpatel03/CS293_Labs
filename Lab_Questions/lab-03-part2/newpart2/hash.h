// PART 2
//
// Let us take a moment to appreciate what hashing does for us.
// Hash functions virtually appear in almost all information security
// applications. A cryptographic hash function (CHF) is a hash algorithm that
// has special properties desirable for a cryptographic application. At this
// point, a natural question arises - what special properties do we desire from
// a good CHF? While we can spend a good amount of time answering this question,
// it would be prudent (and hopefully, more fun) to try and see some of the basics
// on our own. In this part of the lab, we will analyse what makes a good hash
// function and attack some custom-made hash functions to exploit weaknesses that
// arise if the hash function does not satisfy the required properties. This brings
// us to the problem statement.
//
// Problem Statement
//
// There are six secret messages, each of which has been password protected.
// However, the passwords have been encrypted using different hash functions.
// Each hash function suffers from some weakness. Your goal is to attack each
// hash function by discovering and exploiting this weakness and gaining access
// to the secret message. You do not need to guess the password since any word
// which has the same hash value as the password will work.
//
// To get the message, you need to give the following commmand
//     $./eval [1-6] [password]
//
// Run the executable ’eval’ with two command line arguments. The first one is
// between 1 and 6, indicating which message you would like to attempt to access.
// The second one is the password. You will gain access to the respective secret
// message if the hash value matches. Your goal is to access all six secret messages.
// The correct hash values of passwwords can be found in the following.
//
// Details
//
//
// So, what’s our plan of attack? The first thing to note is that each of the
// provided hash functions has a weakness. Hence, while brute-forcing the answer
// may work, it is highly not recommended as it will be highly inefficient in
// practice. Also, this is not a cryptography course. Hence, we are more concerned
// with attacking the hash function algorithmically. This is a good time to think
// about the design principles we desire when designing a hash function.
//
// The next thing to note is that you have been provided with the implementation of three of the six hash functions.
// In such a case, you can tear apart the hash function and analyse the algorithm for a weakness. The other three
// are more subtle as we do not have their implementation. However, we can test for some properties by passing
// a very small set of passwords to eval. These two are the weakest hash functions and should fail many design properties
// you would expect a good hash function to possess.
// The above are mere hints to help you approach the problem, and in no way, is the only way to approach it.
// This is an open-ended problem; you can craft creative attacks to break the hash functions. Enjoy!
//
// Running Instructions

#include <iostream>
#include <string>

using namespace std;

#ifndef HASH_H
#define HASH_H

size_t insecureHashOne  (const std::string& input);
size_t insecureHashTwo  (const std::string& input);
size_t insecureHashThree(const std::string& input);
size_t insecureHashFour (const std::string& input);
size_t insecureHashFive (const std::string& input);
size_t insecureHashSix  (const std::string& input);

# define PASSWORD_HASH_ONE   7286957716698854768
# define PASSWORD_HASH_TWO   1522
# define PASSWORD_HASH_THREE 4203767532912581189
# define PASSWORD_HASH_FOUR  2956
# define PASSWORD_HASH_FIVE  714300129759786736
# define PASSWORD_HASH_SIX   84114101

// We know implmentations of three of them
//
// size_t insecureHashOne( const std::string& input ) {
//     size_t hash = 0;
//     for (char c : input) {
//         hash = (hash * 256) + c;
//     }
//     return hash;
// }
//
// size_t insecureHashThree(const std::string& input) {
//     unsigned long hash = 5381; // Initial value
//     for (char c : input) {
//         hash = ((hash << 5) + hash) + c; // DJB2 algorithm
//     }
//     return hash;
// }
//
// size_t insecureHashFive(const std::string& input) {
//     unsigned long hash = 5381; // Initial value
//     for (char c : input) {
//         hash = (hash * c) + c;
//     }
//     return hash;
// }

#endif



