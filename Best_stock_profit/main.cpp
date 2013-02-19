/* 
 * File:   main.cpp
 * Author: Vidya
 *
 * Created on February 18, 2013, 7:50 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

/* You been offered the opportunity to invest in the Volatile Chemical Corporation.
 * Like the chemicals the company produces, the stock price of the Volatile 
 * Chemical Corporation is rather volatile. You are allowed to buy one unit of 
 * stock only one time and then sell it at a later date, buying and selling after 
 * the close of trading for the day. To compensate for this restriction, you are 
 * allowed to learn what the price of the stock will be in the future. Your goal 
 * is to maximize your profit. 
 * you would want to “buy low, sell high”—buy at the lowest possible price and 
 * later on sell at the highest possible price—to maximize your profit.
 */

int find_best_crossing_profit(vector<int> & stock_array, int low, int mid, int high, int &buy_day, int &sell_day) {
    
    int left_sum = -10000;
    int right_sum = -10000;
    int sum = 0;
    
    for (int i = mid; i >= low; i--) {
        sum = sum + stock_array[i];
        
        if (sum > left_sum){
            left_sum = sum;
            buy_day = i;
        }
    }
    
    sum = 0;
    for ( int j = mid+1; j <= high; j++) {
        sum = sum + stock_array[j];
        
        if(sum > right_sum) {
            right_sum = sum;
            sell_day = j;
        }
    }
    
    return (left_sum + right_sum);
    
    
}

int find_best_profit(vector<int> & diff_stock_prices, int low, int high, int &buy_day, int &sell_day) {
    
    if(low == high) {
        buy_day = low;
        sell_day = low;
        return diff_stock_prices[low];
    }
    else {
        int mid = (high + low) /2;
        int left_buy, left_sell, left_sum, right_buy, right_sell, right_sum, cross_buy, cross_sell, cross_sum;
        
        left_sum = find_best_profit(diff_stock_prices, low, mid, left_buy, left_sell);
        right_sum = find_best_profit(diff_stock_prices, mid+1, high, right_buy, right_sell);
        cross_sum = find_best_crossing_profit(diff_stock_prices, low, mid, high, cross_buy, cross_sell);
        
        if ((left_sum >= right_sum) && (left_sum >= cross_sum)) {
            buy_day = left_buy;
            sell_day = left_sell;
            return left_sum;
        }
        else if((right_sum >= left_sum) && (right_sum >= cross_sum)) {
            buy_day = right_buy;
            sell_day = right_sell;
            return right_sum;
        }
        else{
            buy_day = cross_buy;
            sell_day = cross_sell;
            return cross_sum;
        }
        
        
        
    }
}

int maximize_profit(vector<int> & stock_prices, int & buy_day, int &sell_day){
    
    vector<int> diff_stock_prices;
    int max_profit = 0, size = stock_prices.size();
    
    diff_stock_prices.push_back(0);
    
    for(int i=0; i<(size-1); i++) {
        diff_stock_prices.push_back(stock_prices[i+1] - stock_prices[i]);
    }
    
    max_profit = find_best_profit(diff_stock_prices, 1, diff_stock_prices.size(), buy_day, sell_day);
    
    return max_profit;
    
}


int main(int argc, char** argv) {
    
    vector<int> stocks;
    int profit, buy_day, sell_day, n, stock_price;
    
    cout << "enter the number of days: " << endl;
    cin >> n;
    
    while(n) {
        cout << "enter the stock price: "<<endl;
        cin >> stock_price;
        stocks.push_back(stock_price);
        n--;
    }

    profit = maximize_profit(stocks, buy_day, sell_day);
    
    cout << "Max profit is: " << profit << " if you buy before day: " << buy_day << " and sell after day: " << sell_day;
    
}

