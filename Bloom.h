#include <iostream>
#include <string>
#include <bitset>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "Hashes.h"

using namespace std;
#define TABLE_SIZE 800000

class Bloom {
    public:
        bitset<TABLE_SIZE> table;
        
        Hashes hasher;
        
    //-----------------------------Functions------------------------------------    
        void insert(string key);
        
        bool is_in(string key);
        
        void read_in(string file);
    //--------------------------------------------------------------------------    
};