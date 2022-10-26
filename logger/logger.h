#ifndef LOGGER_H
#define LOGGER_H

#include <functional>
#include <iostream>
#include <vector>
#include <map>

#include "ostream_wrapper.h"

enum logger_level
{
    LEVEL_EVENT,
    LEVEL_GAME,
    LEVEL_MISTAKE
};

class logger
{
private:

    ostream_wrapper& os;

    logger(ostream_wrapper& os);

    static std::map<logger_level, std::vector<logger*>> loggers;


public:

    static void init_loggers(enum logger_level level, const std::vector<std::reference_wrapper<ostream_wrapper>>& streams);

    static void message(enum logger_level level, const char* msg);
    static void message(enum logger_level level, const std::string& msg);
};

#endif//LOGGER_H