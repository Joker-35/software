#ifndef WEATHERDATABASE_H
#define WEATHERDATABASE_H

#include "Weather.h"
#include <map>
#include <vector>
#include <string>

class WeatherDatabase {
private:
    std::map<std::string, std::vector<Weather> > database;

public:
    WeatherDatabase();
    Weather getWeather(const std::string& city);
    std::vector<Weather> getHourlyForecast(const std::string& city);
    std::vector<Weather> getDailyForecast(const std::string& city);
    void addCity(const std::string& city);
    void removeCity(const std::string& city);
    std::vector<std::string> listCities() const;  
};

#endif

