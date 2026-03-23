#ifndef orderbook_h
#define orderbook_h

#include <map>
#include <queue>
#include <order.h>

class OrderBook {
public: 
    void addOrder(const Order& order);

    const Order* getBestBuy() const;
    const Order* getBestSell() const;

    void removeBestBuy();
    void removeBestSell();

private:
    std::map<double, std::queue<Order>> buyOrders;
    std::map<double, std::queue<Order>> sellOrders;
};

#endif