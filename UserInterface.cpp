#include "UserInterface.h"
#include "WeatherQueryFunction.h"
#include "ConsoleUtils.h"
#include <iostream>
#include <ostream>

void UserInterface::startApp() {
    int width = ConsoleUtils::getTerminalWidth();
    int height = ConsoleUtils::getTerminalHeight();
    adapt(width, height);

    std::cout << "Weather App Starts!\n";

    checkSevereWeatherCondition();

    std::string command;
    while (true) {
        std::cout << std::endl;
        std::cout << "'weather', 'hourly', 'daily', 'travel', 'list', 'add', 'remove', or 'exit' to quit " << std::endl;
        std::cout << "Please enter your command: ";
        std::getline(std::cin, command);

        if (command == "exit") {
            std::cout << "Exiting app\n";
            break;
        } else if (command == "weather") {
            std::string city;
            std::cout << "Please enter the city name: ";
            std::getline(std::cin, city);
            weatherHandler.handleWeatherCommand(city);
        } else if (command == "hourly") {
            std::string city;
            std::cout << "Please enter the city name: ";
            std::getline(std::cin, city);
            weatherHandler.handleHourlyForecast(city);
        } else if (command == "daily") {
            std::string city;
            std::cout << "Please enter the city name: ";
            std::getline(std::cin, city);
            weatherHandler.handleDailyForecast(city);
        } else if (command == "travel") {
            std::string city;
            std::cout << "Enter city name for travel advice: ";
            std::getline(std::cin, city);
            weatherHandler.handleTravelAdvice(city);
        } else if (command == "list") {
            weatherHandler.listCities();
        } else if (command == "add") {
            std::string city;
            std::cout << "Enter city name to add: ";
            std::getline(std::cin, city);
            weatherHandler.addCity(city);
        } else if (command == "remove") {
            std::string city;
            std::cout << "Enter city name to remove: ";
            std::getline(std::cin, city);
            weatherHandler.removeCity(city);
        } else {
            std::cout << "Invalid command. Please try again.\n";
        }
    }
}

void UserInterface::adapt(int width, int height) {
    // TODO: adapt width and height to the screen
}

void UserInterface::checkSevereWeatherCondition() {
    std::vector<std::string> cities = WeatherQueryFunction().listCities();
    if (!cities.empty()) {
        std::string defaultCity = cities[0];  // Assuming the first city in the list is the default
        Weather weather = WeatherQueryFunction().getCurrentWeather(defaultCity);
        // TODO: Define true to a severe weather condition, here is just for demo
        if (true) {
            std::cout << "WARNING! Severe weather conditions currently in " << defaultCity << ":\n"
                      << "Temperature: " << weather.temperature << "°C, "
                      << "Wind Speed: " << weather.windSpeed << " km/h, "
                      << "Conditions: " << weather.description << "\n";
        }
    }
}

