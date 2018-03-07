#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "Pair.h"

using namespace std;

class ArrayListZ {

public:

	Pair *arrayListZ;
	int size;

	ArrayListZ() {
		arrayListZ = (Pair *) malloc (1000 * sizeof(Pair));
		size = 0;
	};

	void add(Pair elem) {
		arrayListZ[size] = elem;
		size = size + 1;
	}

	Pair get(int poz) {
		if (poz < size)
			return arrayListZ[poz];
		else return Pair(-1, -1, -1, -1, -1, -1, 'N');
	}

	Pair remove(int poz) {
		if (poz < size) {
			Pair elem = arrayListZ[poz];
			for (int i = poz; i < size; i++)
				arrayListZ[i] = arrayListZ[i + 1];
			size--;

			
			return elem;
		}
		else {
			//printf("EMPTY ARRAYLISTZ");
			return Pair(-1, -1, -1, -1, -1, -1, 'N');

		}
	}

	int empty() {
		if (size == 0)
			return 1;
		else return 0;
	}

	int getSize() {
		return size;
	}
};