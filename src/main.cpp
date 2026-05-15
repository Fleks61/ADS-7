// Copyright 2025
#include <iostream>
#include <random>

#include "train.h"

void experimentAllOff(int n) {
    Train train;

    for (int i = 0; i < n; i++) {
        train.addCar(false);
    }

    train.getLength();

    std::cout << n << " " << train.getOpCount() << std::endl;
}

void experimentAllOn(int n) {
    Train train;

    for (int i = 0; i < n; i++) {
        train.addCar(true);
    }

    train.getLength();

    std::cout << n << " " << train.getOpCount() << std::endl;
}

void experimentRandom(int n) {
    Train train;

    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(0, 1);

    for (int i = 0; i < n; i++) {
        train.addCar(dist(gen));
    }

    train.getLength();

    std::cout << n << " " << train.getOpCount() << std::endl;
}

int main() {
    for (int n = 2; n <= 100; n += 10) {
        experimentAllOff(n);

        experimentAllOn(n);

        experimentRandom(n);
    }

    return 0;
}
