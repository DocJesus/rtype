cmake_minimum_required(VERSION 3.7)
project(cpp_rtype)

set(CMAKE_CXX_STANDARD 11)

add_executable(cpp_rtype main.cpp include/IMediator.hpp include/AMediated.hpp src/Client.cpp include/Client.hpp src/Room.cpp include/Room.hpp src/Serveur.cpp include/Serveur.hpp include/Debug.hpp include/IGame.hpp src/Data.cpp src/EntityManager.cpp src/Hitbox.cpp src/Position.cpp)

