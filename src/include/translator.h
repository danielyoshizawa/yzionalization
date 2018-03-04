#pragma once
#ifndef YZIONALIZATION_TRANSLATOR_H
#define YZIONALIZATION_TRANSLATOR_H

#include <string>

namespace yz
{
    class Translator
    {
    public:
        Translator();
        virtual ~Translator();

        std::string translate(const std::string &);
    };
}

#endif //YZIONALIZATION_TRANSLATOR_H
