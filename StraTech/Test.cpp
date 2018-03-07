#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "ArrayListZ.cpp"
#include <iostream>


using namespace std;

int mainz() {

	ArrayListZ array;

	printf("size %d ", array.size);
	
	printf("empty %d ", array.empty());

	Pair minPair(-1, -1, -1, -1, -1, -1, 'N');
	if (minPair.isNull()) {
		printf("IS NULLLL");
	}


	int x;
	cin >> x;
	return 0;
}

