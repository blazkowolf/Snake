#include "Event.h"

/* Odd static member variable initialization... */
std::vector<std::pair<std::string, std::function<void()>>> Event::behaviors;