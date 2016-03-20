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
#include "Field.h"
#include <iostream>
using namespace std;


int main() {
	/*Player A("AleksSol");
	Player C("AleksisSol");
	cout << A.name()<<endl;
	A.add_road("MY_ROAD");
	A.add_road("HIS_ROAD");
	cout << A.num_roads()<<endl;
	A.remove_road(A.road(0));
	cout << A.num_roads()<<endl;
	cout<<A.road(0).name() << endl;*/
	
	/*Player C("AleksSol");
	Field A;
	City B("My_city", C);
	A.link_locality(B, Coord(1,1), CrossCorner::BOTTOM);
	
	if(A.has_locality(Coord(1,1), CrossCorner::BOTTOM)) cout << "lol" << endl;
	if(!A.has_locality(Coord(1,1), CrossCorner::BOTTOM)) cout << "unlol" << endl;
	cout << A.locality(Coord(1,1), CrossCorner::BOTTOM).name() << endl;
	A.unlink_locality(Coord(1,1), CrossCorner::BOTTOM);
	if(A.has_locality(Coord(1,1), CrossCorner::BOTTOM)) cout << "lol" << endl;
	if(!A.has_locality(Coord(1,1), CrossCorner::BOTTOM)) cout << "unlol" << endl;
	* */
	return 0;
}
