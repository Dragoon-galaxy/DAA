#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int profit;
    int weight;
    double ratio; // Profit-to-Weight Ratio
};

bool compareItems(const Item& a, const Item& b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compareItems);

    double totalProfit = 0;
    double currentWeight = 0;

    for (const Item& item : items) {
        if (currentWeight + item.weight <= capacity) {
            // Take the whole item if it fits in the knapsack.
            currentWeight += item.weight;
            totalProfit += item.profit;
        } else {
            // Otherwise, take a fraction of the item to fill the remaining capacity.
            double fraction = static_cast<double>(capacity - currentWeight) / item.weight;
            totalProfit += item.profit * fraction;
            break;
        }
    }

    return totalProfit;
}

int main() {
    vector<Item> items = {
        {16, 10, 0.0},
        {12, 8, 0.0},
        {6, 5, 0.0},
        {18, 15, 0.0},
        {8, 6, 0.0}
    };

    int capacity = 30;

    for (Item& item : items) {
        item.ratio = static_cast<double>(item.profit) / item.weight;
    }

    double maxProfit = fractionalKnapsack(items, capacity);

    cout << "Maximum achievable profit (Fractional Knapsack): " << maxProfit << endl;

    return 0;
}
