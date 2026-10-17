#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;

struct Coordinates {
    double latitude;
    double longitude;
};

class GoogleMaps {
public:
    double calculateDistance(Coordinates loc1, Coordinates loc2) {
        // Simplified Euclidean distance converted to kilometers estimation
        return sqrt(pow(loc1.latitude - loc2.latitude, 2) + pow(loc1.longitude - loc2.longitude, 2)) * 111.0;
    }
};

int main() {
    GoogleMaps routePlanner;
    map<string, Coordinates> locations;
    
    locations["Google HQ (California)"] = {37.4220, -122.0841};
    locations["Google New York"] = {40.7418, -74.0048};

    double distance = routePlanner.calculateDistance(locations["Google HQ (California)"], locations["Google New York"]);
    
    cout << "--- Google Maps Navigation ---" << endl;
    cout << "Estimated distance between Google HQ and Google NY: " << distance << " km" << endl;
    return 0;
}
