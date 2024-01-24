#include <algorithm>
#include <fstream>
#include <iostream>

// using namespace std;

struct customer {
    int amount{};
    int time{};
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n{};

    std::ifstream input{};
    input.open("INPUT.INP");
    input >> n;
    customer arr[n];
    for (int i{0}; i < n; ++i) {
        input >> arr[i].amount >> arr[i].time;
    }
    input.close();

    std::sort(arr, arr + n, [](customer a, customer b) { return a.time < b.time; });
    {
        customer *itr{arr};
        while (itr != (arr + n)) {
            customer *next{std::find_if(itr, arr + n, [itr](customer a) { return itr->time != a.time; })};
            std::sort(itr, next, [](customer a, customer b) { return a.amount > b.amount; });
            itr = next;
        }
    }

    int totalAmount{0};
    int totalTime{0};

    {
        int junpTime{arr[0].time};
        for (int i{totalTime}; i <= junpTime; ++i) {
            totalAmount += arr[i].amount;
            totalTime++;
        }
    }

    int firstTime{arr[0].time};
    customer *itr{std::find_if(&arr[0], arr + n, [firstTime](customer a) { return firstTime != a.time; })};
    while (itr != (arr + n)) {
        customer *next{std::find_if(itr, arr + n, [itr](customer a) { return itr->time != a.time; })};
        if (next > (arr + n)) {
            break;
        }
        int junpTime{};
        if (next == (arr + n)) {
            junpTime = ((next - 1)->time) + 1;
        } else {
            junpTime = next->time;
        }
        while (totalTime != junpTime && itr != next) {
            totalAmount += itr->amount;
            itr++;
            totalTime++;
        }
        itr = next;
    }

    std::ofstream output{};
    output.open("OUTPUT.OUT");
    output << totalAmount;
    output.close();

    return 0;
}
