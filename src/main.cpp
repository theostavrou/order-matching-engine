#include <iostream>
#include <order.h>

int main() {
    Order order1(1, 10.5, 100, OrderSide::BUY);

    std::cout << "Order ID: " << order1.getID() << std::endl;
    std::cout << "Price: " << order1.getPrice() << std::endl;
    std::cout << "Quantity: " << order1.getQuantity() << std::endl;

    return 0;
}