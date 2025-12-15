#include <ctime>
#include <iostream>

int main(){
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);

    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "Current date and time: %Y-%m-%d %H:%M:%S", localTime);

    std::cout << buffer << std::endl;
    std::cout << (localTime->tm_min) << std::endl;
    return 0;
}