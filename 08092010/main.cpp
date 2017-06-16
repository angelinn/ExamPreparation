#include "1.cpp"

int main()
{
    Trip** trips = new Trip*[5];
    BusTrip busTrip;
    busTrip.setDistance(100);
    busTrip.setDestination("Пловдив");
    busTrip.setPrice(4.50);
    busTrip.setDeliverer("Юнион Ивкони");

    PlaneFlight flight;
    
    flight.setDistance(3000);
    flight.setDestination("USA");
    flight.setPrice(400.50);
    flight.setFlight("LH3434");

    PlaneFlight otherFlight;

	otherFlight.setDistance(30000);
	otherFlight.setDestination("USA");
	otherFlight.setPrice(4000.1);
	otherFlight.setFlight("LH3164");

    trips[0] = &busTrip;
    trips[1] = &flight;
    trips[2] = &otherFlight;

    Tour tour;
    tour.setTrips(trips, 3);

    tour.priceReport();
    Tour t = tour.sliceTour("Пловдив", "USA");

}