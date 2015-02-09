/* 
 * File:   main.cpp
 * Author: Marietta E. Cameron 
 *
 * Created on February 9, 2015, 5:46 AM
 */

#include <cstdlib>
#include <string>    //need for string
#include <stdio.h>   //need for printf
#include <iostream>  //need for cout

using namespace std;


const string ALPHABET = "abc";
const int DIM = ALPHABET.size();

void initUsed(bool used[]){
    for (int i=0; i<DIM; i++)
        used[i] = false;
}//initUsed


void permute(char pArray[], int pos, int &count, bool used[]){
   
    if (pos >= DIM){
        printf("%4d: ", count);
        for (int i=0; i<DIM; i++)
            printf("%c", pArray[i]);
        cout << endl;
        count++;
    }//base case    
    else {
        for (int i=0; i<DIM; i++){
            if (!used[i]){
                pArray[pos] = ALPHABET[i];     
                used[i] = true;
                permute(pArray, pos+1, count, used);
                used[i] = false;
            }
        }//for each letter in the alphabet
    }//recursive recurrance
}//permute with Repeats

void permuteWithRepeats(char pArray[], int pos, int &count){
    if (pos >= DIM){
        printf("%4d: ", count);
        for (int i=0; i<DIM; i++)
            printf("%c", pArray[i]);
        cout << endl;
        count++;
    }//base case
    else {
        for (int i=0; i<DIM; i++){           
            pArray[pos] = ALPHABET[i];     
            permuteWithRepeats(pArray, pos+1, count);
        }//for each letter in the alphabet
    }//recursive recurrance
}//permute with Repeats

int main(int argc, char** argv) {
   
    char permuteArray[DIM];
    bool used[DIM];
    initUsed(used);
    
    int permuteRepeatsCount = 0;
    int permuteCount = 0;    

    cout << "Permuations with Repeats\n==========================\n";
    permuteWithRepeats(permuteArray, 0, permuteRepeatsCount);
    
    cout << "\nPermuations\n==========================\n";
    permute(permuteArray, 0, permuteCount, used);
    
    
    return 0;
}//main

