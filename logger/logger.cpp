#include "logger.h"
std::map<logger_level, std::vector<logger*>> logger::loggers;

logger::logger(ostream_wrapper& os) : os(os){}


void logger::init_loggers(enum logger_level level,const std::vector<std::reference_wrapper<ostream_wrapper>>& streams)
{
    for(auto i = streams.begin(); i != streams.end(); ++i){
        ostream_wrapper& os = (*i).get();
        loggers[level].push_back(new logger(os));
    }
}


void logger::message(enum logger_level level, const char* msg)
{
    for(auto i = loggers[level].begin(); i != loggers[level].end(); ++i)
        (*i)->os.print(msg);
}
void logger::message(enum logger_level level, const std::string& msg)
{
    for(auto i = loggers[level].begin(); i != loggers[level].end(); ++i)
        (*i)->os.print(msg);
}