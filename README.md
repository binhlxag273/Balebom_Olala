# Balebom_Olala
Construct Suffix Array of a Long String
// Week4Problem2.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
using std::cin;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::string;
using std::vector;
using std::map;
// Build suffix array of the string text and
// return a vector result of the same length as the text
// such that the value result[i] is the index (0-based)
// in text where the i-th lexicographically smallest
// suffix of text starts.
void countingSortDoubled(string text, vector<int> &order, vector<int> &classes)
{
	int numA = 0, numC = 0, numG = 0, numT = 0, numD = 0;
	for (int i = 0; i < text.size() - 1; i++) {
		if (text[i] == 'A')	numA++;
		else if (text[i] == 'C') numC++;
		else if (text[i] == 'G') numG++;
		else if (text[i] == 'T') numT++;
		else if (text[i] == '$') numD++;
	}
	map<char, int> hashmap;
	hashmap['$'] = 0;
	hashmap['A'] = numD;
	hashmap['C'] = hashmap['A'] + numA;
	hashmap['G'] = hashmap['C'] + numC;
	hashmap['T'] = hashmap['G'] + numG;
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == 'A') {
			order[hashmap['A']] = i;
			hashmap['A']++;
		}
		else if (text[i] == 'C') {
			order[hashmap['C']] = i;
			hashmap['C']++;
		}
		else if (text[i] == 'G') {
			order[hashmap['G']] = i;
			hashmap['G']++;
		}
		else if (text[i] == 'T') {
			order[hashmap['T']] = i;
			hashmap['T']++;
		}
		else if (text[i] == '$') {
			order[hashmap['$']] = i;
			hashmap['$']++;
		}
	}
	for (int i = 0; i < text.size(); i++) {
		if(text[])
	}
	
}

vector<int> BuildSuffixArray(const string& text) {
	vector<int> result;
	// Implement this function yourself
	vector<int> order(text.size());
	vector<int> classes(text.size());

	return result;
}

int main() {
	string text;
	cin >> text;
	vector<int> suffix_array = BuildSuffixArray(text);
	for (int i = 0; i < suffix_array.size(); ++i) {
		cout << suffix_array[i] << ' ';
	}
	cout << endl;
	return 0;
}



