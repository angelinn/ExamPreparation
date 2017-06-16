#include <cstdio>
#include <cstring>

class Trip
{
public:
	Trip() : destination(nullptr), description(nullptr), distance(0), price(0)
	{  }

	Trip(const Trip& other) : destination(nullptr), description(nullptr), distance(0), price(0)
	{
		copyFrom(other);
	}

public:
	virtual Trip* clone() const = 0;
	virtual const char* getDescription() = 0;
	virtual ~Trip()
	{
		delete[] description;
		delete[] destination;
	}

public:
	const char* getDescription() const { return description; }
	const char* getDestination() const { return destination; }
	float getPrice() const { return price; }
	int getDistance() const { return distance; }

	void setPrice(float newPrice) { price = newPrice; }
	void setDistance(int newDistance) { distance = newDistance; }
	void setDescription(const char* newDescription) { setString(description, newDescription); }
	void setDestination(const char* newDestination) { setString(destination, newDestination); }

protected:
	void setString(char*& dest, const char* source)
	{
		if (source)
		{
			delete[] dest;
			dest = new char[strlen(source) + 1];
			strcpy(dest, source);
		}
	}

	void copyFrom(const Trip& other)
	{
		setDescription(other.description);
		setDestination(other.destination);

		distance = other.distance;
		price = other.price;
	}

protected:
	char* description;
	char* destination;
	int distance;
	float price;
};

class BusTrip : public Trip
{
public:
	BusTrip() : deliverer(nullptr)
	{  }

	BusTrip(const BusTrip& other) : Trip(other), deliverer(nullptr)
	{
		copyFrom(other);
	}

	BusTrip& operator=(const BusTrip& other)
	{
		if (this != &other)
		{
			Trip::copyFrom(other);
			copyFrom(other);
		}

		return *this;
	}

	~BusTrip()
	{
		delete[] deliverer;
	}

public:
	const char* getDeliverer() const { return deliverer; }
	void setDeliverer(const char* newDeliverer) { setString(deliverer, newDeliverer); }

public:
	virtual BusTrip* clone() const
	{
		return new BusTrip(*this);
	}

	virtual const char* getDescription()
	{
		description = new char[512];
		sprintf(description, "Пътуване %d км до %s на цена %f лв. с автобус на фирма %s", distance, destination, price, deliverer);
		return description;
	}

private:
	void copyFrom(const BusTrip& other)
	{
		setString(deliverer, other.deliverer);
	}

private:
	char* deliverer;
};

class PlaneFlight : public Trip
{
public:
	PlaneFlight()
	{


	}

	PlaneFlight(const PlaneFlight& other) : Trip(other)
	{
		strcpy(flight, other.flight);
	}

public:
	const char* getFlight() const { return flight; }
	void setFlight(const char* newFlight)
	{
		if (strlen(newFlight) > 7)
			return;

		strcpy(flight, newFlight);
	}

public:
	virtual PlaneFlight* clone() const
	{
		return new PlaneFlight(*this);
	}

	virtual const char* getDescription()
	{
		description = new char[512];
		sprintf(description, "Пътуване %d км до %s на цена %f лв. с полет %s", distance, destination, price, flight);
		return description;
	}

private:
	char flight[8];
};

class Tour : public Trip
{
public:
	Tour() : trips(nullptr)
	{   }

	Tour(const Tour& other) : Trip(other), trips(nullptr)
	{
		copyFrom(other);
	}

	Tour& operator=(const Tour& other)
	{
		if (this != &other)
		{
			Trip::copyFrom(other);
			copyFrom(other);
		}

		return *this;
	}

	~Tour()
	{
		free();
	}

public:
	Trip** getTrips() { return trips; }
	void setTrips(Trip** newTrips, size_t size)
	{
		tripCount = size;
		trips = new Trip*[size];

		for (size_t i = 0; i < size; ++i)
			trips[i] = newTrips[i]->clone();
	}

public:
	Tour sliceTour(char const* start, char const* end)
	{
		int startIndex = -1;
		for (int i = 0; i < tripCount; ++i)
		{
			if (strcmp(trips[i]->getDestination(), start) == 0)
			{
				startIndex = i + 1;
				break;
			}
		}

		Tour newTour;

		if (startIndex == -1)
			return newTour;

		int endIndex = -1;
		for (int j = startIndex; j < tripCount; ++j)
		{
			if (strcmp(trips[j]->getDestination(), end) == 0)
			{
				endIndex = j;
				break;
			}
		}

		if (endIndex == -1)
			return newTour;

		newTour.setTrips(trips + startIndex, endIndex - startIndex + 1);
		return newTour;
	}

	void priceReport()
	{
		for (int i = 0; i < tripCount - 1; ++i)
		{
			int maxIndex = i;
			for (int j = i + 1; j < tripCount; ++j)
			{
				if (trips[maxIndex]->getPrice() / trips[maxIndex]->getDistance() < trips[j]->getPrice() / trips[j]->getDistance())
					maxIndex = j;
			}

			Trip* temporary = trips[i];
			trips[i] = trips[maxIndex];
			trips[maxIndex] = temporary;
		}


		for (int i = 0; i < tripCount; ++i)
			printf("[%d] - %s\n", i, trips[i]->getDescription());
	}

public:
	virtual Tour* clone() const
	{
		return new Tour(*this);
	}

	virtual const char* getDescription()
	{
		for (int i = 0; i < tripCount; ++i)
		{
			price += trips[i]->getPrice();
			distance += trips[i]->getDistance();
		}

		description = new char[512];
		sprintf(description, "Обща дължина %d км на цена %f лв.", distance, price);

		return description;
	}

private:
	void copyFrom(const Tour& other)
	{
		free();
		trips = new Trip*[other.tripCount];
		tripCount = other.tripCount;

		for (size_t i = 0; i < other.tripCount; ++i)
			trips[i] = other.trips[i]->clone();
	}

	void free()
	{
		if (trips)
		{
			for (size_t i = 0; i < tripCount; ++i)
				delete trips[i];

			delete[] trips;
		}
	}

private:
	Trip** trips;
	size_t tripCount;
};