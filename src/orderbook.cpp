#include "orderbook.h"

void OrderBook::addOrder(const Order& order) {
    if (order.getSide() == OrderSide::BUY) {
        buyOrders[order.getPrice()].push(order);
    } else {
        sellOrders[order.getPrice()].push(order);
    }
}

const Order* OrderBook::getBestBuy() const {
    if (buyOrders.empty()) return nullptr;

    auto it = buyOrders.rbegin();
    if (it->second.empty()) return nullptr;

    return &it->second.front();
}

const Order* OrderBook::getBestSell() const {
    if (sellOrders.empty()) return nullptr;

    auto it = sellOrders.begin();
    if (it->second.empty()) return nullptr;

    return &it->second.front();
}

void OrderBook::removeBestBuy() {
    if (buyOrders.empty()) return;

    auto it = buyOrders.rbegin();
    it->second.pop();

    if (it->second.empty()) {
        buyOrders.erase(it->first);
    }
}

void OrderBook::removeBestSell() {
    if (sellOrders.empty()) return;

    auto it = sellOrders.begin();
    it->second.pop();

    if (it->second.empty()) {
        sellOrders.erase(it->first);
    }
}