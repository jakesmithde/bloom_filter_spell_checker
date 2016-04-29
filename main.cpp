#include <iostream>
#include <string>
#include <bitset>
#include "Bloom.h"

using namespace std;


int main () {
        //creates the bloom filter object
        Bloom filter;
        //reads in the text file
        filter.read_in("wrds.txt");
        
        //tests for words that are in the text file
        filter.is_in("Galahads");
        filter.is_in("Lance");
        filter.is_in("ampoule");
        filter.is_in("Wendi");
        filter.is_in("carpetbaggers");
        filter.is_in("lesser");
        filter.is_in("showrooms");
        filter.is_in("womanliness's");
        filter.is_in("zygote's");
        filter.is_in("Ångström");
        filter.is_in("watermelon");
    
        //tests for words that are not in the tex file
        cout << "----------------------------------------------------------------------------" <<endl;
        
        filter.is_in("showooms");
        filter.is_in("dancedancerevolution");
        filter.is_in("aurthurdane");
        filter.is_in("winston");
        filter.is_in("supercalifragilisticexpialidocious");
        filter.is_in("ard");
}

