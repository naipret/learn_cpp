#include <iostream>

double distanceFallen(int const &time) {
    double const gravity{9.8};
    return gravity * (time * time) / 2.0;
}

void printProcess(int const &time, double const &current_meters) {
    if (current_meters > 0) {
        std::cout << "At " << time << " seconds, the ball is at height: " << current_meters << " meters\n";
    } else {
        std::cout << "At " << time << " seconds, the ball is on the ground.";
    }
}

int main() {
    std::cout << "Enter the height of the tower in meters: ";
    double meters_max{};
    std::cin >> meters_max;
    double current_meters{meters_max};
    int time{0};
    while (current_meters > 0) {
        current_meters = meters_max - distanceFallen(time);
        printProcess(time, current_meters);
        time++;
    }
    return 0;
}
