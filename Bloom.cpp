#include "Bloom.h"
#include <iostream>
#include <string>
#include <bitset>
using namespace std;
    
    

    void Bloom::insert(string key) {
        int num1, num2, num3;
        
        num1 = hasher.getHash(hasher.FNV1a(&*key.begin(), key.length()),TABLE_SIZE);
        num2 = hasher.getHash(hasher.rotating(&*key.begin(),key.length(), 5),TABLE_SIZE);
        num3 = hasher.getHash(hasher.MurmurHash2(&*key.begin(),key.length(),7),TABLE_SIZE);
        
        if(table[num1] == 0) { table[num1] = 1; }
        if(table[num2] == 0) { table[num2] = 1; }
        if(table[num3] == 0) { table[num3] = 1; }
        
        cout << key << " was set to " << num1 <<" "<< num2 <<" "<< num3 << endl;
    }
    
    bool Bloom::is_in(string key){
        
        int num1 = hasher.getHash(hasher.FNV1a(&*key.begin(), key.length()),TABLE_SIZE);
        int num2 = hasher.getHash(hasher.rotating(&*key.begin(),key.length(), 5),TABLE_SIZE);
        int num3 = hasher.getHash(hasher.MurmurHash2(&*key.begin(),key.length(),7),TABLE_SIZE);
        
        if (table[num1] == 1 && table[num2] == 1 && table[num3] == 1) {
            cout << key << " is in the dictionary!"<< endl;
            return true;
        }
        else {
            cout << key << " is not in the dictionary :( "<< endl;
            return false;
        }
    }
    
    void Bloom::read_in(string file) {
        string line;
        ifstream words(file.c_str());
        
        if (words.is_open()){
            while (getline (words,line)){
                insert(line);
            }
            
            words.close();
        }
        
        else {
            cout << "unable to open file" << endl;
        }
    
        words.close();
    }