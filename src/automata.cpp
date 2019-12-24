//
// Created by Egor on 25.12.2019.
//
#include "automata.h"
#include <iostream>

void Automata::on()
{
    if (this->state != READY)
    {
        std::cout << "The machine is ready to work!" << std::endl;
        this->state = READY;
    }
    else
        std::cout << "The machine is already working!" << std::endl;

    wait();
}

void Automata::of()
{
    if (this->state != UNREADY)
    {
        std::cout << "Shutting down..." << std::endl;
        this->state = UNREADY;
        this->cash = 0;
    }
}

void Automata::coin()
{
    std::cout << "Please, enter your Deposit amount: ";

    int amount = 0;

    while(true)
    {
        try
        {
            std::cout << "Input(0 for exit): ";
            std::cin >> amount;
            break;
        }
        catch(...)
        {
            std::cout << "Wrong input, try again!" << std::endl;
        }
    }

    if (amount == 0)
        wait();
    else
    {
        this->cash += amount;
        std::cout << "Balance: " << this->cash << std::endl;
        choice();
    }
}

void Automata::printMenu()
{
    std::cout << "Available drinks:" << std::endl;
    for(int i = 0; i < this->menu.size() && i < this->prices.size(); i++)
        std::cout << i + 1 << ") " <<  this->menu[i] << " (" << this->prices[i] << "$)" << std::endl;
}

void Automata::printState()
{
    std::string state = (this->state == READY) ? "ready" : "not ready";
    std::cout << "The machine is " <<  state << "\n";
}

std::string Automata::choice()
{
    std::cout << "Please, choose your drink:" << std::endl;
    this->printMenu();

    int choice = 0;

    while(true)
    {
        try
        {
            std::cout << "Input a number from 1 to " << this->menu.size() << ": ";
            std::cin >> choice;
            break;
        }
        catch(...)
        {
            std::cout << "Wrong input, try again!" << std::endl;
        }
    }

    if (check(choice))
        cook(choice);
    else
        wait();
}

bool Automata::check(int num)
{
    if (this->cash >= this->prices[num - 1])
    {
        this->cash -= this->prices[num - 1];
        return true;
    }
    std::cout << "You have not enough money to buy this drink!" << std::endl;
    return false;
}

void Automata::cook(int num)
{
    std::cout << this->menu[num - 1] << " is being prepared..." << std::endl;
    finish(num);
}

void Automata::finish(int num)
{
    this->cash -= this->prices[num - 1];
    std::cout << this->menu[num - 1] << " is ready, thank you for your purchase!" << std::endl;
    wait();
}

void Automata::wait()
{
    std::cout << "Please, choose action:" << std::endl;
    std::cout << "1) Turn off the machine\n2) Deposit money" << std::endl;

    int choice = 0;

    while(true)
    {
        try
        {
            std::cout << "Input a number from 1 to 2: ";
            std::cin >> choice;
            break;
        }
        catch(...)
        {
            std::cout << "Wrong input, try again!" << std::endl;
        }
    }

    if (choice == 1)
        this->of();
    else
        this->coin();
}

