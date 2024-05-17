/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;
    int index;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

void fractionalKnapsack(int N, vector<int>& weights, vector<int>& values, int maxCapacity) {
    vector<Item> items(N);

    for (int i = 0; i < N; ++i) {
        items[i].weight = weights[i];
        items[i].value = values[i];
        items[i].ratio = (double)values[i] / weights[i];
        items[i].index = i;
    }

    sort(items.begin(), items.end(), compare);

    int remainingCapacity = maxCapacity;
    double totalValue = 0.0;

    cout << "Maximum value that can be achieved: ";
    for (int i = 0; i < N; ++i) {
        if (remainingCapacity >= items[i].weight) {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
            cout << items[i].value << " ";
        } else {
            double fraction = (double)remainingCapacity / items[i].weight;
            totalValue += fraction * items[i].value;
            cout << items[i].value * fraction << " ";
            break;
        }
    }
    cout << endl;

    cout << "List of selected items along with their fraction: ";
    for (int i = 0; i < N; ++i) {
        if (remainingCapacity >= weights[items[i].index]) {
            cout << "Item" << items[i].index + 1 << ": 1.0, ";
            remainingCapacity -= weights[items[i].index];
        } else {
            double fraction = (double)remainingCapacity / weights[items[i].index];
            cout << "Item" << items[i].index + 1 << ": " << fraction << ", ";
            break;
        }
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    vector<int> weights(N);
    vector<int> values(N);

    for (int i = 0; i < N; ++i) {
        cin >> weights[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> values[i];
    }

    int maxCapacity;
    cin >> maxCapacity;

    fractionalKnapsack(N, weights, values, maxCapacity);

    return 0;
}

*/
