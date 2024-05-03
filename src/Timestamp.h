#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>
#include <sstream>

class Timestamp {
private:
    std::chrono::system_clock::time_point time_point;

public:
    // Constructor
    Timestamp() {
        time_point = std::chrono::system_clock::now();
    }

    Timestamp(const std::string& date_str) {
        std::tm tm = {};
        std::istringstream ss(date_str);
        ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
        std::time_t time = std::mktime(&tm);
        time_point = std::chrono::system_clock::from_time_t(time);
    }

    // Overloaded operator <
    bool operator<(const Timestamp& other) const {
        return time_point < other.time_point;
    }

    // Overloaded operator >
    bool operator>(const Timestamp& other) const {
        return time_point > other.time_point;
    }

    // Overloaded operator ==
    bool operator==(const Timestamp& other) const {
        return time_point == other.time_point;
    }

    // Overloaded operator <<
    friend std::ostream& operator<<(std::ostream& os, const Timestamp& ts) {
        std::time_t ttp = std::chrono::system_clock::to_time_t(ts.time_point);
        std::tm tm_out = *std::localtime(&ttp);
        os << std::put_time(&tm_out, "%Y-%m-%d %H:%M:%S");
        return os;
    }
};