#include <iostream>
#include <string>
#include <bitset>

using namespace std;

#define FNV_32_prime 16777619
#define FNV_32_offset 2166136261

class Hashes {
    
    public :
    
        int getHash(unsigned int num, int t_size);
        
        unsigned int FNV1a(const void *bytes, int len);
        
        unsigned int rotating(const void *key, int len, int prime);
        
        unsigned int MurmurHash2(const void *key, int len, unsigned int seed);
        
        
        
};