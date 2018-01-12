//
// Created by vautri_b on 10/01/18.
//

#ifndef CPP_RTYPE_DEBUG_HPP
#define CPP_RTYPE_DEBUG_HPP

#include <iostream>

class   Debug
{
    static bool const debug = true;
public:
    static void write(std::string const &string) //ecrit sans \n
    {
        if (debug)
            std::cout << string;
    }
    static void writeln(std::string const & string) //ecrit avec un \n
    {
        if (debug)
            std::cout << string << std::endl;
    }
};

#endif //CPP_RTYPE_DEBUG_HPP
