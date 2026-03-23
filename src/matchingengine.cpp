#include <iostream>
#include "matchingengine.h"

void MatchingEngine::processOrder(const Order& order) {
    orderBook.addOrder(order);
    matchOrders();
}

void MatchingEngine::matchOrders() {
    while (true) {
        const Order* bestBuy = orderBook.getBestBuy();
        const Order* bestSell = orderBook.getBestSell();

        if (!bestBuy || !bestSell) break;
        if (bestBuy->getPrice() < bestSell->getPrice()) break;

        int tradeQty = std::min(bestBuy->getQuantity(), bestSell->getQuantity());
        double tradePrice = bestSell->getPrice();

        std::cout << "TRADE " << tradeQty << " @ " <<tradePrice << std::endl;

        Order* buy = const_cast<Order*>(bestBuy);
        Order* sell = const_cast<Order*>(bestSell);

        buy->reduceQuantity(tradeQty);
        sell->reduceQuantity(tradeQty);

        if (buy->getQuantity() == 0) {
            orderBook.removeBestBuy();
        }

        if (sell->getQuantity() == 0) {
            orderBook.removeBestSell();
        }

    }
}