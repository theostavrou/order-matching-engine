#ifndef ORDER_H
#define ORDER_H

#include <string>

enum class OrderSide {
    BUY,
    SELL
};

class Order {
    public:
    Order(int id, double price, int quantity, OrderSide side);

    int getID() const;
    double getPrice() const;
    int getQuantity() const;
    OrderSide getSide() const;

    private:
    int id;
    double price;
    int quantity;
    OrderSide side;
};

#endif