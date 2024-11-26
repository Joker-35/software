#ifndef WEATHER_H
#define WEATHER_H

#include <string>

class Weather {
public:
    std::string dateTime;
    double temperature;
    double humidity;
    int windSpeed;
    std::string description;
    std::string sunrise;
    std::string sunset;

    Weather(std::string dt = "", double temp = 0.0, double hum = 0.0, int wind = 0, std::string desc = "",
            std::string sr = "06:00:00", std::string ss = "18:00:00");  
};

#endif
