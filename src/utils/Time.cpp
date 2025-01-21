#include "time.h"

#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>
#include <chrono>

namespace Time {
int64_t currentTimeMillis()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count();
}

void sleep(int64_t ms)
{
    sf::sleep(sf::milliseconds(ms));
}
}