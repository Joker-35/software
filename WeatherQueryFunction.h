#ifndef WEATHERQUERYFUNCTION_H
#define WEATHERQUERYFUNCTION_H

#include "WeatherDatabase.h"
#include <string>
#include <vector>

class WeatherQueryFunction {
private:
    WeatherDatabase db;

public:
    Weather getCurrentWeather(const std::string& city);
    std::vector<Weather> getHourlyForecast(const std::string& city);
    std::vector<Weather> getDailyForecast(const std::string& city);
    void addCity(const std::string& city); 
    void removeCity(const std::string& city);  
    std::vector<std::string> listCities() const;  
};

#endif
