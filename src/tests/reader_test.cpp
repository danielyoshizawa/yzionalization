#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <path.h>

#include "core/reader.h"

SCENARIO("I want to read a file", "[Reader]")
{
    yz::reader reader;
    reader.load(EN_EN_INPUT_FILE_PATH, ":");

    GIVEN("A file with phrases separated by semi-colon")
    {
        WHEN("I read a valid identifier")
        {
            THEN("the value should be right")
            {
                REQUIRE(reader.translate("test_string").compare("Test string for Yzionalization Reader") == 0);
            }
        }
        WHEN("I read an invalid identifier")
        {
            THEN("Should throw an excepcion")
            {
                REQUIRE_THROWS(reader.translate("wrong_identifier"));
            }
        }
    }
}

