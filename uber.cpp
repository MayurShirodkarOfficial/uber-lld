#include "tripMgr.hpp"

int main() {

	//---------------Creating Riders and Drivers--------------------------------
	Rider* keertiRider = new Rider("Mayur", RATING::FIVE_STARS);
	Rider* gauravRider = new Rider("Sanjana", RATING::FIVE_STARS);
	RiderMgr* riderMgr = RiderMgr::getRiderMgr();
	riderMgr->addRider("mayur", keertiRider);
	riderMgr->addRider("sanjana", gauravRider);

	Driver* yogitaDriver = new Driver("Yogesh", RATING::THREE_STARS);
	Driver* riddhiDriver = new Driver("Riddhi", RATING::FOUR_STARS);
	DriverMgr* driverMgr = DriverMgr::getDriverMgr();
	driverMgr->addDriver("yogesh", yogitaDriver);
	driverMgr->addDriver("riddhi", riddhiDriver);

	//These details in turn will be stored in database
	//-------------------------------------------------------------------------

	TripMgr* tripMgr = TripMgr::getTripMgr();


	cout << endl << "Creating Trip for Keerti from location (10,10) to (30,30)" << endl;
	tripMgr->CreateTrip(keertiRider, new Location(10, 10), new Location(30, 30));

	cout << endl << "Creating Trip for Gaurav from location (200,200) to (500,500)" << endl;
	tripMgr->CreateTrip(gauravRider, new Location(200, 200), new Location(500, 500));


	//-------------------Display all the trips created--------------------------
	unordered_map<int, Trip*> tripsMap = tripMgr->getTripsMap();
	for (auto mapVal : tripsMap) {
		(mapVal.second)->displayTripDetails();
	}

	return 0;
}