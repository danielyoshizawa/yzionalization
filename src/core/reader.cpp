#include "reader.h"
#include <iostream>
#include <fstream>

namespace yz
{
    reader::~reader()
    {

    }

    reader::reader()
    {

    }

    bool reader::load(const std::string & file_path, const std::string & delimiter)
    {
        try
        {
            std::string buffer = read(file_path);
            std::vector<std::string> translation_tuples = split_line(buffer);
            translation_map = create_translation_map(translation_tuples, delimiter);
        } catch (std::exception & ex)
        {
            return false;
        }

        return true;
    }

    std::vector<std::string> reader::split_line(const std::string & buffer)
    {
        std::vector<std::string> strings;

        std::string::size_type pos = 0;
        std::string::size_type prev = 0;
        while ((pos = buffer.find("\n", prev)) != std::string::npos)
        {
            strings.push_back(buffer.substr(prev, pos - prev));
            prev = pos + 1;
        }

        strings.push_back(buffer.substr(prev));

        return strings;
    }

    std::pair<std::string, std::string> reader::split_translations(const std::string & translation, const std::string & delimiter)
    {
        std::pair<std::string, std::string> translation_pair;

        translation_pair.first = translation.substr(0,translation.find(delimiter));
        translation_pair.second = translation.substr(translation.find(delimiter) + 1, translation.size() - 1);

        return translation_pair;
    };

    std::string reader::translate( const std::string & identifier )
    {
        try
        {
            return translation_map.at(identifier);
        } catch (std::exception & ex)
        {
            throw;
        }
    }

    std::string reader::read(const std::string & file_path)
    {
        std::ifstream is (file_path, std::ifstream::in);
        if (is) {
            // get length of file:
            is.seekg (0, is.end);
            int length = is.tellg();
            is.seekg (0, is.beg);

            char * buffer = new char [length];

            try
            {
                is.read (buffer,length);
            }
            catch (std::exception & ex)
            {
                throw("Unable to read file!");
            }

            is.close();

            return std::string(buffer);
        }

        return "";
    }

    std::map<std::string, std::string> reader::create_translation_map(const std::vector<std::string> & tuples, const std::string & delimiter)
    {
        std::map<std::string, std::string> tmap;
        for (std::string tuple : tuples)
        {
            try
            {
                tmap.insert(split_translations(tuple, delimiter));
            } catch (std::exception & ex)
            {

            }
        }

        return tmap;
    };
}
