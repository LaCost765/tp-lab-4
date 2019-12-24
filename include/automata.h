//
// Created by Egor on 25.12.2019.
//

#ifndef TASK1_AUTOMATA_H
#define TASK1_AUTOMATA_H

#include <string>
#include <vector>

enum STATES {READY, UNREADY};

class Automata
{
public:
    void on();
    void of();
    void coin();
    void printMenu();
    STATES printState();
    std::string choice();
    bool check(int num);
    void cook(int num);
    void finish(int num);
    void wait();
private:
    long cash = 0;
    std::vector<std::string> menu = {"Black tea", "Green tea", "Cappuccino", "Latte"};
    std::vector<int> prices = {30, 40, 35, 50};
    STATES state = UNREADY;
};

#endif //TASK1_AUTOMATA_H
