#include "gtest/gtest.h"
#include "automata.h"

TEST(lab4, task1){
Automata shop = Automata();
shop.off();
EXPECT_EQ(UNREADY, shop.printState());