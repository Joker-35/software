#include "WeatherDatabase.h"
#include <ctime>
#include <cstdlib>

void generateWeatherData(std::vector<Weather>& weatherData) {
    // TODO: Applying a interface to real-time data
    // Here generates the weather situation randomly for demo
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int hoursPerYear = 8760;  // Approximate hours in a non-leap year

    for (int i = 0; i < hoursPerYear; ++i) {
        ltm->tm_hour--;  // Decrement the hour to go back in time
        mktime(ltm);  // Normalize the time structure

        // Generate random weather data
        double temperature = (rand() % 30) + 10;
        double humidity = (rand() % 100);
        int windSpeed = (rand() % 100);
        std::string description = (rand() % 2) ? "Sunny" : "Cloudy";
        std::string sunrise = "06:00:00";  // Static sunrise time (could be dynamic based on city and date)
        std::string sunset = "18:00:00";  // Static sunset time

        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
        std::string dateTime = buffer;

        weatherData.push_back(Weather(dateTime, temperature, humidity, windSpeed, description));
    }
}

WeatherDatabase::WeatherDatabase() {
    std::string cities[] = {"New York", "London", "Tokyo"};

    for (auto &city : cities) {
        std::vector<Weather> weatherData;
        generateWeatherData(weatherData);
        database[city] = weatherData;
    }
}

Weather WeatherDatabase::getWeather(const std::string& city) {
    auto it = database.find(city);
    if (it != database.end() && !it->second.empty()) {
        return it->second.back();
    }
    return Weather();
}

std::vector<Weather> WeatherDatabase::getHourlyForecast(const std::string& city) {
    std::vector<Weather> forecast;
    // TODO
    return forecast;
}

std::vector<Weather> WeatherDatabase::getDailyForecast(const std::string& city) {
    std::vector<Weather> forecast;
    // TODO
    return forecast;
}

void WeatherDatabase::addCity(const std::string& city) {
    if (database.find(city) == database.end()) {  
        std::vector<Weather> weatherData;
        generateWeatherData(weatherData);
        database[city] = weatherData;
    }
}

void WeatherDatabase::removeCity(const std::string& city) {
    database.erase(city);  
}

std::vector<std::string> WeatherDatabase::listCities() const {
    std::vector<std::string> cityNames;
    for (const auto& entry : database) {
        cityNames.push_back(entry.first);
    }
    return cityNames;
}

