#include <iostream>
#include <chrono>
#include <string>
#include <sstream>
#include <iomanip>
#include <thread>

void waitUntil(const std::string& time_point) {
    auto start = std::chrono::steady_clock::now();
    std::tm timeDate = {};
    std::istringstream ss(time_point);
    ss >> std::get_time(&timeDate, "%T");

    std::time_t now_c = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    auto tm = std::localtime(&now_c);

    auto diffHr = timeDate.tm_hour - tm->tm_hour;
    auto diffMin = timeDate.tm_min - tm->tm_min;
    auto diffSec = timeDate.tm_sec - tm->tm_sec;
    if (diffSec < 0 and diffMin <= 0 and diffHr <= 0) {
        std::cout << "given time point must be later than current time moment!\n";
        exit(0);
    }
    std::chrono::seconds durationToWait = std::chrono::hours(diffHr) + std::chrono::minutes(diffMin) + std::chrono::seconds(diffSec);
    auto stop = std::chrono::steady_clock::now();
    auto durationAmmend = std::chrono::duration(stop - start);
    std::this_thread::sleep_for(durationToWait - durationAmmend);
}

int main() {
    waitUntil("05:04:30");
    std::cout << "HELLO!\n";

    // std::string time_value2{"04:57:55"};
    // std::tm timeDate = {};
    // std::istringstream ss(time_value2);
    // ss >> std::get_time(&timeDate, "%T");
    // timeDate.tm_isdst = -1;
    // // auto time_point = std::chrono::system_clock::from_time_t(mktime(&timeDate));

    // std::stringstream stream{};
    // std::time_t now_c = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    // auto tm = std::localtime(&now_c);
    // std::string dash(50, '-');

    // std::cout << "the value given\n";
    // std::cout << "hours: " << timeDate.tm_hour << '\n';
    // std::cout << "minutes: " << timeDate.tm_min << '\n';
    // std::cout << "secs: " << timeDate.tm_sec << '\n';
    // std::cout << dash << '\n';

    // std::cout << "value when program started\n";
    // std::cout << "hours: " << tm->tm_hour << '\n';
    // std::cout << "minutes: " << tm->tm_min << '\n';
    // std::cout << "seconds: " << tm->tm_sec << '\n';
    // std::cout << dash << '\n';

    // // if ()
    // auto diffHr = timeDate.tm_hour - tm->tm_hour;
    // auto diffMin = timeDate.tm_min - tm->tm_min;
    // auto diffSec = timeDate.tm_sec - tm->tm_sec;
    // // if (diffHr < 0) {
    // //     std::cout << "given time point must be later than current time moment!\n";
    // //     exit(0);
    // // }
    // // if (diffMin < 0 and diffHr <= 0) {
    // //     std::cout << "given time point must be later than current time moment!\n";
    // //     exit(0);
    // // }

    // if (diffSec < 0 and diffMin <= 0 and diffHr <= 0) {
    //     std::cout << "given time point must be later than current time moment!\n";
    //     exit(0);
    // }
    // std::cout << "the difference\n";
    // std::cout << "hours: " << diffHr << '\n';
    // std::cout << "minutes: " << diffMin << '\n';
    // std::cout << "seconds: " << diffSec << '\n';
    // std::cout << dash << '\n';

    // std::chrono::milliseconds durationToWait = std::chrono::hours(diffHr) + std::chrono::minutes(diffMin) + std::chrono::seconds(diffSec);
    // std::cout << durationToWait.count() << '\n';
    // std::this_thread::sleep_for(durationToWait);
    // std::cout << "it should be: " << time_value2 << " now!\n";
}
