#pragma once

#ifndef YZIONALIZATION_READER_H
#define YZIONALIZATION_READER_H

#include <string>
#include <vector>
#include <map>

namespace yz
{

    class reader
    {
    private:
        std::map<std::string, std::string> translation_map;

    public:
        virtual ~reader();
        reader();
        bool load(const std::string & file_path, const std::string & delimiter);
        std::string translate( const std::string & identifier );
    private:
        std::vector<std::string> split_line(const std::string & buffer);
        std::pair<std::string, std::string> split_translations(const std::string & translation, const std::string & delimiter);
        std::string read(const std::string & file_path);
        std::map<std::string, std::string> create_translation_map(const std::vector<std::string> & tuples, const std::string & delimiter);
    };

};

#endif //YZIONALIZATION_READER_H
