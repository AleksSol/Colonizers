#include "Coord.h"
#include "RoadSide.h"
#include "Resource.h"
#include "ResourcesHolder.h"
#include "Hex.h"
#include <iostream>
using namespace std;


int main() {
	ResourcesHolder A;
	A.add(Resource::ORE, 5);
	A.remove(Resource::ORE, 2);
	A.add(Resource::WOOD, 5);
	A.add(Resource::WOOL, 5);
	cout << A.resources() << endl;
}
