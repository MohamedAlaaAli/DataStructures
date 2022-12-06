#ifndef __P2_H__
#define __P2_H__

#include <string>
#include <vector>
#include <set>
using namespace std;

// give a string vector dictionary and a scrambled word return a set containing all the words that can be formed from the scrambled word
set<string> word_amalgamation(vector<string> dictionary, string scrambled);

#endif