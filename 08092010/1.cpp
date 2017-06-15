#include <cstdio>
#include <cstring>

class Trip
{
public:
    Trip() : destination(nullptr), distance(0), price(0)
    {  }

    Trip(const Trip& other) : destination(nullptr), distance(0), price(0)
    {
        copyFrom(other);
    }

public:
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
        delete[] dest;
        dest = new char[strlen(source) + 1];
        strcpy(dest, source);
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
            copyFrom(other);

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
    const char* getFlight() const { return flight; }
    void setFlight(const char* newFlight)
    {
        if (strlen(newFlight) > 7)
            return;

        strcpy(flight, newFlight);
    }
    
public:
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
    Trip** getTrips() { return trips ;}

public:
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

    Trip** trips;
    size_t tripCount;
};
