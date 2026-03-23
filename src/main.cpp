#include <iostream>
#include <order.h>
#include "orderbook.h"

int main() {
    OrderBook book;

    book.addOrder(Order(1, 10.0, 100, OrderSide::BUY));
    book.addOrder(Order(2, 10.5, 50, OrderSide::BUY));
    book.addOrder(Order(3, 9.5, 100, OrderSide::SELL));

    const Order* bestBuy = book.getBestBuy();
    const Order* bestSell = book.getBestSell();

    if (bestBuy) {
        std::cout << "Best Buy: " << bestBuy->getPrice() << std::endl;
    }

    if (bestSell) {
        std::cout << "Best Sell: " << bestSell->getPrice() << std::endl;
    }

}