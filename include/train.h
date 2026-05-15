// Copyright 2022 NNTU-CS
#include <iostream>
#include <random>
#include "train.h"

using namespace std;

void experimentAllOff(int n)
{
    Train train;

    for (int i = 0; i < n; i++)
    {
        train.addCar(false);
    }

    train.getLength();

    cout << n << " " << train.getOpCount() << endl;
}

void experimentAllOn(int n)
{
    Train train;

    for (int i = 0; i < n; i++)
    {
        train.addCar(true);
    }

    train.getLength();

    cout << n << " " << train.getOpCount() << endl;
}

void experimentRandom(int n)
{
    Train train;

    random_device rd;

    mt19937 gen(rd());

    uniform_int_distribution<> dist(0, 1);

    for (int i = 0; i < n; i++)
    {
        train.addCar(dist(gen));
    }

    train.getLength();

    cout << n << " " << train.getOpCount() << endl;
}

int main()
{
    for (int n = 2; n <= 100; n += 10)
    {
        experimentAllOff(n);

        experimentAllOn(n);

        experimentRandom(n);
    }

    return 0;
}
