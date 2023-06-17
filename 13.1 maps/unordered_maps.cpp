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

    for (const auto &city : my_cities)
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

    CityRecord &LondonData = city_map["London"];
    std::cout << LondonData.population << std::endl;

    // note:
    // if you look up city_map["Cairo"] when an element with index "Cairo" does not exist
    // then an empty element with index "Cairo" will be ADDED to the map

    // if you do not want this behaviour
    // use .at() method
    // ie city_map.at(Cairo)

    // however, if we use .at() with an element which does not exist in the map
    // we will get an exception or a crash
    // therefore we need to use .find()

    if (city_map.find("Berlin") != city_map.end())
    {
        const CityRecord &berlinData = city_map.at("Berlin");
        std::cout << "Berlin pop: " << berlinData.population << std::endl;
    }
    else
    {
        std::cout << "Berlin does not exist in map \n";
    }

    if (city_map.find("Istanbul") != city_map.end())
    {
        const CityRecord &istanbulData = city_map.at("Istanbul");
        std::cout << "Istanbul pop: " << istanbulData.population << std::endl;
    }
    else
    {
        std::cout << "Istanbul does not exist in map \n";
    }

    // additional notes: when to use std::vector and when to use std::map
    // general rule is to use vector when we have to iterate through elements
    // vector is contiguous memory, hence very fast to iterate through
    // however, if we want to be able to look up data
    // like in this example
    // maps are an order of magnitude faster
    
    // regardless, if we did still want to iterate through a map for debugging for example
    // we would do so like this:

    for (const auto& [name, city] : city_map)
    {
        std::cout << name << ", pop: " << city.population << std::endl;
    }

    // using structured bindings introduced in C++ 17
}