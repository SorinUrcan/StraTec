#include "stdafx.h"
#include "PAIR.h"

	Pair::Pair(int f, int s, int pf, int ps, int height, int c, char chr) {
		first = f;
		second = s;
		parentF = pf;
		parentS = ps;

		ht = height;
		costFromStart = c;
		ch = chr;
	}
	
	bool Pair::isNull() {
		if ((first == -1) && (second == -1) && (parentF == -1) && (parentS == -1) && (ht == -1))
			return true;
		else return false;
	}

	char Pair::getCh() {
		return ch;
	}
