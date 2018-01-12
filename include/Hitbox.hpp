//
// Created by nano on 1/10/18.
//

#ifndef CPP_RTYPE_HITBOX_HPP
#define CPP_RTYPE_HITBOX_HPP


#include "Position.hpp"

class Hitbox {
public:
    Hitbox(Position pos, int width, int lenght, float scale);
    ~Hitbox();
    const Position &getPosition() const;
    float getScale() const;
    int getLength() const;
    int getWidth() const;
    void setPosition(const Position &_position);
    void setWidth(int _width);
    void setLength(int _length);
    void setScale(float _scale);

private:
    Position _position;
    int _width;
    int _length;
    float _scale;
};


#endif //CPP_RTYPE_HITBOX_HPP
