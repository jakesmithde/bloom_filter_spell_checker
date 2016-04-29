#include "Hashes.h"
#include <iostream>
#include <string>
#include <bitset>
using namespace std;
    
    
    int Hashes:: getHash(unsigned int hash , int t_size) {
            return hash % t_size;
        }
    
    unsigned int Hashes::FNV1a(const void *bytes, int len){
        unsigned int h = FNV_32_offset;
        for (int i = 0; i < len; ++i) {
            unsigned char data = * ((unsigned char *) bytes + i);
            h ^= data;
            h *= FNV_32_prime;
        }
        return h;
    } 
    
    unsigned int Hashes::rotating(const void *key, int len, int prime) {
        unsigned int hash;
        int i;
        for (hash=len, i=0; i<len; ++i) {
            unsigned char data = * ((unsigned char *) key + i);
            hash = (hash<<4)^(hash>>28)^data;
        }
        return hash;
    }
    
    
    unsigned int Hashes::MurmurHash2 (const void *key, int len, unsigned int seed) {
        // 'm' and 'r' are mixing constants generated offline.
    	// They're not really 'magic', they just happen to work well.
    	const unsigned int m = 0x5bd1e995;
    	const int r = 24;
    
    	// Initialize the hash to a 'random' value
    	unsigned int h = seed ^ len;
    
    	// Mix 4 bytes at a time into the hash
    	const unsigned char * data = (const unsigned char *)key;
    
    	while(len >= 4)
    	{
    		unsigned int k = *(unsigned int *)data;
    		k *= m; 
    		k ^= k >> r; 
    		k *= m; 
    		
    		h *= m; 
    		h ^= k;
    
    		data += 4;
    		len -= 4;
    	}
    	// Handle the last few bytes of the input array
    	switch(len)
    	{
    	case 3: h ^= data[2] << 16;
    	case 2: h ^= data[1] << 8;
    	case 1: h ^= data[0];
    	        h *= m;
    	};
    
    	// Do a few final mixes of the hash to ensure the last few
    	// bytes are well-incorporated.
    	h ^= h >> 13;
    	h *= m;
    	h ^= h >> 15;
    	return h;    
    }
    
    