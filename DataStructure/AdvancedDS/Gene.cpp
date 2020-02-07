/*
 * Gene.cpp
 *
 *  Created on: Dec 13, 2019
 *      Author: 212331148
 *      https://www.hackerrank.com/challenges/bear-and-steady-gene/problem
 */

#include "iostream"
#include <unordered_map>
using namespace std;

int steadyGene(string gene) {

	unordered_map<char, int>occurance{ {'G', 0}, {'A', 0}, {'T', 0}, {'C', 0} };
	unordered_map<char, int>found{ {'G', 0}, {'A', 0}, {'T', 0}, {'C', 0} };
	for (auto ch : gene)
		occurance[ch]++;

	int expected = gene.size() / 4;
	for (auto &ch : occurance)
		ch.second = max(0, ch.second - expected);
		//occurance[ch.first] = max(0, occurance[ch.first] - expected);

	if (occurance['G'] == 0 && occurance['A'] == 0 && occurance['T'] == 0 && occurance['C'] == 0)
		return 0;

	int tail = 0;
	int head = 0;
	int min_length = gene.size();
	while (head < gene.size())
	{
		found[gene[head]]++;
		if (found['A'] >= occurance['A'] &&
			found['C'] >= occurance['C'] &&
            found['G'] >= occurance['G'] &&
			found['T'] >= occurance['T'])
		{
			min_length = min(min_length, head - tail + 1);

			while (found[gene[tail]] > occurance[gene[tail]])
			{
				found[gene[tail]]--;
				tail += 1;
				min_length = min(min_length, head - tail + 1);
			}
		}
		head++;
	}

	return min_length;
}

int GeneMain()
{
	string gene = "GAAATAAA";
	cout<<steadyGene(gene)<<endl;
	string res;
	cout<<*(gene.begin()+0);
	cout<<*(gene.begin()+1);
	cout<<*(gene.begin()+4);
	//cout<<();

	return 0;
}
