#include <string>
#include <set>
#include <iostream>
#include <fstream>
#include "../../../../../../GitHub/FMI-DSA/data_structures/hash_table/template_hash_map/hash_map.hpp"

using std::set;
using std::string;
using dsa::hash_map;
using std::ifstream;
using std::pair;

struct Data {
	set<string> lefts;
	set<string> rights;
	unsigned int cnt = 0;
};

string getMostCommon(const set<string>& words, hash_map<string, Data>& table) {
	pair<string, unsigned int> bestKeyCount = std::make_pair("", 0);
	for (const string& str : words){
		if (bestKeyCount.second < table[str].cnt) {
			bestKeyCount = std::make_pair(str, table[str].cnt);
		}
	}
	return bestKeyCount.first;
}

void mostCommonWord(const string& filename) {
	ifstream in(filename);
	if (!in.is_open()) {
		std::cerr << "Invalid file";
		return;
	}
	string previous, current, next;
	hash_map<string, Data> table;
	pair<string, unsigned int> bestKeyCount = std::make_pair("", 0);
	in >> current;
	in >> next;
	// fill in the table
	while (in) {
		table[current].cnt++;
		table[current].lefts.insert(previous);
		table[current].rights.insert(next);
		if (table[current].cnt > bestKeyCount.second) {
			bestKeyCount = std::make_pair(current, table[current].cnt);
		}
		previous = current;
		current = next;
		in >> next;
	}
	in.close();

	string left = getMostCommon(table[bestKeyCount.first].lefts, table);
	string right = getMostCommon(table[bestKeyCount.first].rights, table);

	std::cout << left << ' ' << bestKeyCount.first << ' ' << right << '\n';
}

int main()
{
	mostCommonWord("test.txt");
	return 0;
}