// Copyright 2013 Daniel Parker
// Distributed under Boost license

#include <boost/test/unit_test.hpp>
#include "jsoncons/json.hpp"
#include "jsoncons/json_serializer.hpp"
#include <sstream>
#include <vector>
#include <utility>
#include <ctime>
#include <cwchar>

using jsoncons::json_serializer;
using jsoncons::output_format;
using jsoncons::json;
using jsoncons::wjson;
using jsoncons::basic_json_reader;
using std::string;

BOOST_AUTO_TEST_CASE(test_string_to_double)
{
    jsoncons::float_reader reader;
    const char* begin = "1.15507e-173";
    const char* endptr = begin + strlen(begin);
    const double value1 = 1.15507e-173;
    const double value2 = strtod((char*) begin, (char**)&endptr );
    const double value3 = reader.read(begin,endptr-begin);

    BOOST_CHECK(value1 == value2);
    BOOST_CHECK(value2 == value3);
}

