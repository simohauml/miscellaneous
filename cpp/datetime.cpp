
#include <ctime>

using namespace std;

string myTime() {
    // current date/time based on current system
    time_t now = time(0);

    tm *ltm = localtime(&now);

    // get various components of tm structure.
    string year = std::to_string(1900 + ltm->tm_year);
    string month = std::to_string(1 + ltm->tm_mon);
    string day = std::to_string(ltm->tm_mday);
    string hour = std::to_string(1 + ltm->tm_hour);
    string min = std::to_string(1 + ltm->tm_min);
    string sec = std::to_string(1 + ltm->tm_sec);
    
    return year + month + day + "-" + hour + "-" + min + "-" + sec;
}