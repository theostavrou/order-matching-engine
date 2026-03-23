#ifndef matchingengine_h
#define matchingengine_h

#include "orderbook.h"

class MatchingEngine {
public:
    void processOrder(const Order& order);

private:
    OrderBook orderBook;

    void matchOrders();
};

#endif