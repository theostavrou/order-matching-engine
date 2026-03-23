#include <iostream>
#include <order.h>
#include "orderbook.h"
#include "matchingengine.h"

int main() {
    MatchingEngine engine;

    engine.processOrder(Order(1, 10.0, 100, OrderSide::BUY));
    engine.processOrder(Order(2, 9.5, 50, OrderSide::SELL));
    engine.processOrder(Order(3, 10.5, 100, OrderSide::SELL));
    engine.processOrder(Order(4, 11.0, 100, OrderSide::BUY));

    return 0;

}