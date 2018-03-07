#ifndef PAIR_H
#define PAIR_H

class Pair
{
public:
	Pair(int f, int s, int pf, int ps, int height, int c, char ch);

	int first, second, parentF, parentS, ht, costFromStart;

	char ch;
	
	bool isNull();

	char getCh();
};

#endif