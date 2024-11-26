#include "WeatherCommandHandler.h"

void WeatherCommandHandler::handleWeatherCommand(const std::string& city) {
    Weather weather = weatherQuery.getCurrentWeather(city);
    if (!weather.description.empty()) {
        std::cout << "Current Weather in " << city << ":\n"
                  << "Time: " << weather.dateTime << "\n"
                  << "Temperature: " << weather.temperature << "°C\n"
                  << "Humidity: " << weather.humidity << "%\n"
                  << "Wind Speed: " << weather.windSpeed << " km/h\n"
                  << "Description: " << weather.description << std::endl;
        displayRadarImage(city);
        bool response;
        // TODO: make bool decides whether to share
        if (response) {
            shareWeatherInfo(city);
        }
    } else {
        std::cout << "No weather data found for \"" << city << "\". Please check the city name and try again.\n";
    }
}

void WeatherCommandHandler::handleHourlyForecast(const std::string& city) {
    // TODO
    std::cout << "Hourly Forecast Need Implementation" << std::endl;
}

void WeatherCommandHandler::handleDailyForecast(const std::string& city) {
    // TODO
    std::cout << "Daily Forecast Need Implementation" << std::endl;
}

void WeatherCommandHandler::handleTravelAdvice(const std::string& city) {
    std::vector<Weather> forecast = weatherQuery.getHourlyForecast(city);
    if (forecast.empty()) {
        std::cout << "No forecast available in " << city << std::endl;
        return;
    }

    std::cout << "Travel Advice for the next several hours in " << city << ":\n";
    // TODO
    std::cout << "Daily Forecast Need Implementation" << std::endl;
}

void WeatherCommandHandler::listCities() {
    std::vector<std::string> cities = weatherQuery.listCities();
    std::cout << "Available Cities:\n";
    for (const auto& city : cities) {
        std::cout << city << "\n";
    }
}

void WeatherCommandHandler::addCity(const std::string& city) {
    weatherQuery.addCity(city);
    std::cout << "City added: " << city << "\n";
}

void WeatherCommandHandler::removeCity(const std::string& city) {
    weatherQuery.removeCity(city);
    std::cout << "City removed: " << city << "\n";
}

void WeatherCommandHandler::displayRadarImage(const std::string& city) {
    // Displaying a radar image
    std::cout << "[Displaying radar image for " << city << "]\n";
    // TODO: Implement it
}

void WeatherCommandHandler::shareWeatherInfo(const std::string& city) {
    // TODO: Share the weather information to a social media platform
}