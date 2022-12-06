#include "p2.h"
using namespace std;
#include "map"
#include "set"
set<string> word_amalgamation(vector<string> dictionary, string scrambled_word) {
    set<string> result;

    // create a map for the scrambled word mapping each letter to its count
    map<char, int> s_map;
    for(char letter : scrambled_word)   s_map[letter]++;

    for(string word : dictionary){
        //if the sizes are not equal then the word will fail
        if(word.size() != scrambled_word.size()) continue;

        // create a map for each word in the dictionary mapping each letter to its count
        map<char, int> word_map;
        for(char element : word)    word_map[element]++;

        for(int j=0; j<word.size(); j++){
            if(s_map[word[j]] == word_map[word[j]]){
                if(j == word.size() - 1)  result.insert(word);
            } else break;
        }

    }



    return result;
}