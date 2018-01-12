//
// Created by nano on 1/10/18.
//

#ifndef CPP_RTYPE_AENTITY_HPP
#define CPP_RTYPE_AENTITY_HPP

#include <iostream>
#include "Position.hpp"
#include "Hitbox.hpp"
#include "EntiType.hpp"
#include "Data.hpp"

class AEntity {
public:
    AEntity(const Position &pos, int id, const Hitbox &hitbox, EntiType type, bool isTOuchable, float rotation) : _pos(pos), _id(id)
            , _hitbox(hitbox), _type(type), _isAlive(true), _isTouchable(isTOuchable), _rotation(rotation)
            {
                std::cerr << "New class AEntity created." << std::endl;
            }

    virtual ~AEntity() {}

    virtual void Update(Data data) = 0;

    const Position &get_pos() const {
        return _pos;
    }
    void set_pos(const Position &_pos) {
        AEntity::_pos = _pos;
    }
    int get_id() const {
        return _id;
    }
    void set_id(int _id) {
        AEntity::_id = _id;
    }
    const Hitbox &get_hibox() const {
        return _hitbox;
    }
    EntiType get_type() const {
        return _type;
    }
    bool is_isAlive() const {
        return _isAlive;
    }
    bool is_isTouchable() const {
        return _isTouchable;
    }
    float get_rotation() const {
        return _rotation;
    }
    void set_rotation(float _rotation) {
        AEntity::_rotation = _rotation;
    }
    void set_isTouchable(bool _isTouchable) {
        AEntity::_isTouchable = _isTouchable;
    }
    void set_isAlive(bool _isAlive) {
        AEntity::_isAlive = _isAlive;
    }
    void set_type(EntiType _type) {
        AEntity::_type = _type;
    }
    void set_hibox(const Hitbox &_hibox) {
        AEntity::_hitbox = _hibox;
    }

protected:
    Position _pos;
    int _id;
    Hitbox _hitbox;
    EntiType _type;
    bool _isAlive;
    bool _isTouchable;
    float _rotation;

};

#endif //CPP_RTYPE_AENTITY_HPP
