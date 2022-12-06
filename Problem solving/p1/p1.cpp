#include "p1.h"
#include "map"
using namespace std;

bool ransom_note(string ransomNote, string magazine){
    // implement the solution
    //a map for each character in magazine
    map<char, int> mZ;
    for(char element : magazine)
        mZ[element]++;
    //loop over each element in ransomNote
    for(char element : ransomNote){
        //the element is not in the magazine , return -1
        if(mZ[element]==0)
            return false;
        // the element is found so reduce its count
        mZ[element]--;
    }
    return true;

}