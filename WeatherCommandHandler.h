#ifndef WEATHERCOMMANDHANDLER_H
#define WEATHERCOMMANDHANDLER_H

#include "WeatherQueryFunction.h"
#include <iostream>
#include <string>

class WeatherCommandHandler {
private:
    WeatherQueryFunction weatherQuery;

public:
    WeatherCommandHandler() = default;
    void handleWeatherCommand(const std::string& city);
    void handleHourlyForecast(const std::string& city);
    void handleDailyForecast(const std::string& city);
    void handleTravelAdvice(const std::string& city);
    void listCities(); 
    void addCity(const std::string& city);
    void removeCity(const std::string& city);
    void displayRadarImage(const std::string& city);
    void shareWeatherInfo(const std::string& city);
};

#endif

