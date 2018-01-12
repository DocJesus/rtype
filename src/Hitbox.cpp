//
// Created by nano on 1/10/18.
//

#include <iostream>
#include "../include/Hitbox.hpp"

Hitbox::Hitbox(Position pos, int width, int lenght, float scale) : _position(pos), _width(width), _length(lenght),
                                                                   _scale(scale){
    std::cerr << "New class Hitbox created." << std::endl;
}

Hitbox::~Hitbox() {
    std::cerr << "Class Hitbox deleted." << std::endl;
}

const Position &Hitbox::getPosition() const {
    return _position;
}

int Hitbox::getWidth() const {
    return _width;
}

int Hitbox::getLength() const {
    return _length;
}

float Hitbox::getScale() const {
    return _scale;
}

void Hitbox::setPosition(const Position &_position) {
    Hitbox::_position = _position;
}

void Hitbox::setWidth(int _width) {
    Hitbox::_width = _width;
}

void Hitbox::setLength(int _length) {
    Hitbox::_length = _length;
}

void Hitbox::setScale(float _scale) {
    Hitbox::_scale = _scale;
}
