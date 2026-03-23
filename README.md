# Order Matching Engine (C++)

## Overview
This project implements a simplified limit order book and matching engine, similar to those used in financial exchange. It processes buy and sell orders and executes trades based on price-time priority.

The system is designed to demonstrate core software engineering concepts including: data structures, system design and real-time state management.

---

## Features
- Price-time priority order matching
- Order book implemented using 'std::map' and FIFO queues
- Real-time trade execution
- Partial fill support (order are reduced, not removed)
- Modular architecture

---

## System Architecture

Orders are processed through a layered system:

Orders -> Matching Engine -> Order Book -> Trade Execution

### Components

- **Order**
    - Represents a buy or sell request
    - Stores price, quantity and order side

- **Order Book**
    - Maintains active buy and sell orders
    - Uses ordered maps for efficient price lookup
    - Uses queues to enforce FIFO at each price level

- **Matching Engine**
    - Processes incoming orders
    - Executes trades when best bid >= best ask
    - Supports partial fills by updating order quantities

---

## Order Matching Logic

Trades occur when:

Highest Buy Price >= Lowest Sell Price

Trade quantity is determined by:

min(buy_quantity, sell_quantity)

The system then:
- Executes the trade
- Updates order quantities
- Removes fully filled orders

---

## Example

### Input
BUY 100 10.00  
SELL 50 9.50  
SELL 100 10.50  
BUY 100 11.00 

### Output
TRADE 50 @ 9.50  
TRADE 100 @ 10.50

---

## How to Run

```bash
mkdir build
cd build
cmake ..
make
./main