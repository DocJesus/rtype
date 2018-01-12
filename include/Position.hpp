//
// Created by nano on 1/10/18.
//

#ifndef CPP_RTYPE_POSITION_HPP
#define CPP_RTYPE_POSITION_HPP


class Position {
public:
    Position(int x, int y);
    ~Position();
    int getX() const;
    void setX(int _x);
    int getY() const;
    void setY(int _y);

private:
    int _x;
    int _y;
};


#endif //CPP_RTYPE_POSITION_HPP
