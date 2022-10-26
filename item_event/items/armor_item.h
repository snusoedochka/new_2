#ifndef ARMOR_ITEM_H
#define ARMOR_ITEM_H

#include "../item_event.h"
#include "../../actions/action.h"



class armor_item : public item_event
{
	public:


	armor_item(size_t dt, double dr);

    virtual const char* getName() const;

    //virtual void onUsed(actor& on_who);
    bool isWorn() const;
    void setWorn(bool _worn);

protected:

	bool worn;
    size_t dt; double dr;
};

class armor_item_wear : public action
{
public:

    armor_item_wear(armor_item& item, size_t dt, double dr);

    virtual const std::string getName();
    virtual size_t getAPCost(actor* active, actor* passive, cell* c);
    virtual bool canExecute(size_t ap, actor* active, actor* passive, cell* c);

    virtual void execute(size_t& ap, actor* active, actor* passive, cell* c);


private:

    armor_item& item;
    size_t dt; double dr;
};


#endif
