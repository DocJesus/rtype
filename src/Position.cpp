//
// Created by nano on 1/10/18.
//

#include <iostream>
#include "../include/Position.hpp"

Position::Position(int x, int y) : _x(x), _y(y) {
    std::cerr << "New class position created." << std::endl;
}

Position::~Position() {
    std::cerr << "Class position deleted." << std::endl;
}

int Position::getX() const {
    return _x;
}

int Position::getY() const {
    return _y;
}

void Position::setY(int _y) {
    Position::_y = _y;
}

void Position::setX(int _x) {
    Position::_x = _x;
}
