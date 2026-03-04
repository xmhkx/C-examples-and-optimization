#include <iostream>
#include <vector>
#include <utility> // for std::move

std::vector<int> SensorReadings;

void FilterReadings(std::vector<int> readings) {
    if (readings.size() < 10) {
        std::cout << "Too few readings\n";
        return;
    }

    std::cout << "Readings are sufficient\n";
    SensorReadings = std::move(readings); // move buffer into global (cheap)
}

int main() {
    std::vector<int> incoming;
    incoming.reserve(100);

    for (int i = 0; i < 100; ++i) {
        incoming.push_back(i);
    }

    // IMPORTANT: if you want to avoid copying incoming into the function:
    FilterReadings(std::move(incoming));

    std::cout << "Stored readings: " << SensorReadings.size() << "\n";
    std::cout << "Incoming after move: " << incoming.size() << "\n"; // likely 0

    return 0;
}