#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "WeatherCommandHandler.h"
#include <iostream>
#include <string>

class UserInterface {
private:
    WeatherCommandHandler weatherHandler;

public:
    void startApp();
    void checkSevereWeatherCondition();
    void adapt(int width, int height);
};

#endif
