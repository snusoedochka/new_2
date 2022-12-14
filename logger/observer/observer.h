#ifndef OBSERVER_H
#define OBSERVER_H

#include <functional>
#include <iostream>
#include <vector>

#include "../ostream_wrapper.h"

class observer
{

public:

    observer(ostream_wrapper& os);
    observer(const std::vector<std::reference_wrapper<ostream_wrapper>>& streams);
    virtual ~observer();
    virtual void notify() = 0;

protected:

    std::vector<std::reference_wrapper<ostream_wrapper>> oslist;

};

#endif