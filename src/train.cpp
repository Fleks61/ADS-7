// Copyright 2025
#include "train.h"

Train::Train() {
    first = nullptr;

    countOp = 0;
}

Train::~Train() {
    if (first == nullptr) {
        return;
    }

    Car* current = first->next;

    while (current != first) {
        Car* temp = current;

        current = current->next;

        delete temp;
    }

    delete first;
}

void Train::addCar(bool light) {
    Car* newCar = new Car(light);

    if (first == nullptr) {
        first = newCar;

        first->next = first;
        first->prev = first;
    }
    else {
        Car* last = first->prev;

        last->next = newCar;

        newCar->prev = last;

        newCar->next = first;

        first->prev = newCar;
    }
}

int Train::getOpCount() const {
    return countOp;
}

int Train::getLength() {
    if (first == nullptr) {
        return 0;
    }

    countOp = 0;

    int length = 1;

    const Car* current = first->next;

    countOp++;

    while (current != first) {
        current = current->next;

        length++;

        countOp++;
    }

    return length;
}
