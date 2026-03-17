#include "order.h"

Order::Order(int id, double price, int quantity, OrderSide side)
    : id(id), price(price), quantity(quantity), side(side) {}

int Order::getID() const {
    return id;
}

double Order::getPrice() const {
    return price;
}

int Order::getQuantity() const {
    return quantity;
}

OrderSide Order::getSide() const {
    return side;
}