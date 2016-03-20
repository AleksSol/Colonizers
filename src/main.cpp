#include "Coord.h"
#include "RoadSide.h"
#include "Resource.h"
#include "ResourcesHolder.h"
#include "Hex.h"
#include "Infrastructure.h"
#include "Locality.h"
#include "Road.h"
#include "Town.h"
#include "City.h"
#include "Player.h"
#include <iostream>
using namespace std;


int main() {
	Player A("AleksSol");
	Player C("AleksisSol");
	cout << A.name()<<endl;
	Road &X =A.add_road("MY_ROAD");
	C.add_road("HIS_ROAD");
	if(X.is_town()) cout << "TOWN ADD" << endl;
	if(X.is_road()) cout << "ROAD ADD" << endl;
	return 0;
}
