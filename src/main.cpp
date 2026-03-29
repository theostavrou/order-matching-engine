#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "matchingengine.h"

int main() {
    MatchingEngine engine;

    std::ifstream file ("../examples/orders.txt");

    if (!file.is_open()) {
        std::cout << "Failed to open file" <<std::endl;
    }
    std::string line;

    int orderId = 1;

    while (std::getline(file, line)) {
        std::istringstream iss(line);

        //std::cout << "Reading line: " << line << std::endl;

        std::string sideStr;
        int quantity;
        double price;

        iss >> sideStr >> quantity >> price;

        OrderSide side = (sideStr == "BUY") ? OrderSide::BUY : OrderSide::SELL;

        engine.processOrder(Order(orderId++, price, quantity, side));
    }

    return 0;

}