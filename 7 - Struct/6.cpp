#include <iostream>
#include <algorithm>

using namespace std;

struct StockAnalysis {
    int prices[1000]; // Assuming a maximum of 1000 prices
    int size = 0;

    void inputPrices() {
        for (int i = 0; i < 1000; ++i) {
            prices[i] = -1;
        }
        int price;
        for (int i = 0; cin >> price && price != -1; ++i) {
            prices[i] = price;
            size = i + 1;
        }
    }

    void queryPrices() {
        for (int i = 0; i < size; ++i) {
            cout << prices[i] << " ";
        }
        cout << endl;
    }

    void sortAndOutputPrices() {
        int sortedPrices[1000];
        copy(prices, prices + size, sortedPrices);
        sort(sortedPrices, sortedPrices + size);
        for (int i = 0; i < size; ++i) {
            cout << sortedPrices[i] << " ";
        }
        cout << endl;
    }

    void outputMaxMinDates() {
        if (size == 0) return;
        int maxIndex = max_element(prices, prices + size) - prices;
        int minIndex = min_element(prices, prices + size) - prices;
        cout << minIndex << " " << maxIndex << endl;
    }

    int maxProfitOneTransaction() {
        if (size == 0) return 0;
        int minPrice = prices[0];
        int maxProfit = 0;
        for (int i = 0; i < size; ++i) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }

    int maxProfitMultipleTransactions() {
        int maxProfit = 0;
        for (int i = 1; i < size; ++i) {
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
        }
        return maxProfit;
    }
};

int main() {
    cout << "欢迎使用股票分析系统：" << endl;
    cout << "1--输入股票价格序列" << endl;
    cout << "2--查询股票价格" << endl;
    cout << "3--输出升序的股票价格序列" << endl;
    cout << "4--输出最大值和最小值的日期" << endl;
    cout << "5--一笔交易的最大利润" << endl;
    cout << "6--多笔交易的最大利润" << endl;
    cout << "7--退出" << endl;

    StockAnalysis stockAnalysis;

    int command;
    while (cin >> command && command != 7) {
        switch (command) {
            case 1:
                stockAnalysis.inputPrices();
                break;
            case 2:
                stockAnalysis.queryPrices();
                break;
            case 3:
                stockAnalysis.sortAndOutputPrices();
                break;
            case 4:
                stockAnalysis.outputMaxMinDates();
                break;
            case 5:
                cout << stockAnalysis.maxProfitOneTransaction() << endl;
                break;
            case 6:
                cout << stockAnalysis.maxProfitMultipleTransactions() << endl;
                break;
            default:
                cout << "无效命令" << endl;
        }
    }

    return 0;
}