#include "Weather.h"

Weather::Weather(std::string dt, double temp, double hum, int wind, std::string desc,
                 std::string sr, std::string ss)
    : dateTime(dt), temperature(temp), humidity(hum), windSpeed(wind),
      description(desc), sunrise(sr), sunset(ss) {}
