#include "gtest/gtest.h"
#include "automata.h"

TEST(lab4, task1){
Automata shop = Automata();
shop.of();
EXPECT_EQ(UNREADY, shop.printState());