#include <iostream>
#include <cstddef> // for std::size_t

// this is the optimal way to order the members of the struct to minimize padding
struct DataPoint {
    double x; // 8 bytes
    int y;    // 4 bytes
    int z;    // 4 bytes
};

// this struct will be 24 bytes due to padding, while DataPoint is 16 bytes
struct BadDataPoint {
    int y;    // 4 bytes
    double x; // 8 bytes
    int z;    // 4 bytes
};



int main() {
    DataPoint point{1.57, 2, 3};
    BadDataPoint badPoint{2, 1.9, 3};

   std::cout << "sizeof(DataPoint) = " << sizeof(DataPoint) << " bytes\n";
   std::cout << "sizeof(BadDataPoint) = " << sizeof(BadDataPoint) << " bytes\n";
   std::cout << "DataPoint: x = " << point.x << ", y = " << point.y << ", z = " << point.z << '\n';
   std::cout << "BadDataPoint: y = " << badPoint.y << ", x = " << badPoint.x << ", z = " << badPoint.z << '\n';
}