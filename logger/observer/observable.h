#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "observer.h"

class observable
{

public:

    void setObserver(observer& ob);
    void notifyObserver();

private:

    observer* ob = nullptr;

};

#endif