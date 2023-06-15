#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

struct CityRecord
{
public:
    std::string name;
    uint16_t population;

    CityRecord() : name(""), population(0)
    {
    }

    CityRecord(std::string iname, uint16_t ipop) : name(iname), population(ipop)
    {
    }

    CityRecord(std::string iname, uint16_t ipop, double ilat, double ilon) : name(iname), population(ipop)
    {
    }

    void print() const
    {
        std::cout << "Name: " << name << "\n";
        std::cout << "Pop: " << population << std::endl;
    }

};

int main()
{

    CityRecord City1("London", 150), City2("Paris", 120), City3("New York", 145), City4("Istanbul", 165);

    // using a vector (slow):

    std::vector<CityRecord> my_cities{City1, City2, City3, City4};

    for (const auto& city : my_cities)
    {
        if (city.name == "New York")
        {
            std::cout << city.population << std::endl;
        }
    }

    // using an unordered_map (fast):

    std::unordered_map<std::string, CityRecord> city_map;

    city_map["London"] = City1;
    city_map["Paris"] = City2;
    city_map["New York"] = City3;
    city_map["Istanbul"] = City4;

    // now, if we want to look up population for Berlin
    // instead of having to iterate through a vector (slow)
    // we can simply do the following:

    CityRecord& LondonData = city_map["London"];
    std::cout << LondonData.population << std::endl;

}