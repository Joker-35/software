#include "WeatherQueryFunction.h"

Weather WeatherQueryFunction::getCurrentWeather(const std::string& city) {
    return db.getWeather(city);
}

std::vector<Weather> WeatherQueryFunction::getHourlyForecast(const std::string& city) {
    return db.getHourlyForecast(city);
}

std::vector<Weather> WeatherQueryFunction::getDailyForecast(const std::string& city) {
    return db.getDailyForecast(city);
}

void WeatherQueryFunction::addCity(const std::string& city) {
    db.addCity(city);
}

void WeatherQueryFunction::removeCity(const std::string& city) {
    db.removeCity(city);
}

std::vector<std::string> WeatherQueryFunction::listCities() const {
    return db.listCities();
}
