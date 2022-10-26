#ifndef OSTREAM_WRAPPER_H
#define OSTREAM_WRAPPER_H

#include <fstream>

class ostream_wrapper
{

public:

    ostream_wrapper(std::ostream& os);
    virtual ~ostream_wrapper();

    void link();
    void unlink();

    virtual void print(const char* message);
    virtual void print(const std::string& message);


protected:

    std::ostream& os;

    virtual void os_open();
    virtual void os_close();


private:

    bool os_closed;
    unsigned link_cnt;

};

#endif//OSTREAM_WRAPPER_H