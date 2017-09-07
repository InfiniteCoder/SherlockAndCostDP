#include <iostream>
#include <vector>

using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; ++i) {
        int count;
        cin >> count;
        vector<int> numbers;
        for (int j = 0; j < count; ++j) {
            int number;
            cin >> number;
            numbers.push_back(number);
        }

        //init values
        std::pair<int, int> high, low; //in high, we consider next number as highest
        high = make_pair(numbers.at(0), 0);
        low = make_pair(1, 0);

        //dp
        for (unsigned long k = 1; k < count; ++k) {
            //calculate for high
            //new high
            auto newHigh = make_pair(numbers.at(k), max(low.second + abs(1 - numbers.at(k)),
                                                        high.second + abs(high.first - numbers.at(k))));
            //new low
            auto newLow = make_pair(1, max(low.second + abs(low.first - 1), high.second + abs(high.first - 1)));

            high = newHigh;
            low = newLow;
        }

        //print result
        cout << max(high.second, low.second) << "\n";
    }
    return 0;
}