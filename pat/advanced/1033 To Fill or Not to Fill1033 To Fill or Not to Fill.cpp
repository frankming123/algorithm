#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct station {
    double mps;
    int dis;
};

bool cmp(station &a, station &b) { return a.dis < b.dis; }

int main() {
    int cap, dis, dps, num;
    cin >> cap >> dis >> dps >> num;
    vector<station> stations(num);
    double tmp1;
    int tmp2;
    for (int i = 0; i < num; i++) {
        cin >> tmp1 >> tmp2;
        stations[i] = station{tmp1, tmp2};
    }
    sort(stations.begin(), stations.end(), cmp);

    if (stations[0].dis != 0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }

    int pos = 0;
    double price = 0, oil = 0;
    while (true) {
        double maxrun = stations[pos].dis + cap * dps;
        double smps = stations[pos].mps;
        int sdis = stations[pos].dis;
        double minprice = 99999999;
        for (int i = pos + 1; i < stations.size() && stations[i].dis <= maxrun;
             i++)
            minprice = stations[i].mps < minprice ? stations[i].mps : minprice;
        // printf("smps: %.2f sdis: %d maxrun: %d minprice: %.2f price: %.2f
        // oil: %.2f\n", smps, sdis, maxrun, minprice, price, oil);
        if (minprice == 99999999) {
            // printf("in minprice=100000\n");
            if (maxrun < dis) {
                printf("The maximum travel distance = %.2f\n", maxrun);
                return 0;
            } else {
                double needoil = double(dis - sdis) / dps;
                printf("%.2f",
                       price + (oil >= needoil ? 0 : (needoil - oil)) * smps);
                return 0;
            }
        } else if (minprice < smps) {
            // printf("in minprice < smps\n");
            int i = pos + 1;
            while (stations[i].mps > smps)
                i++;
            double needoil = double(stations[i].dis - sdis) / dps;
            if (oil >= needoil) {
                oil -= needoil;
            } else {
                price += (needoil - oil) * smps;
                oil = 0;
            }
            pos = i;
        } else {
            if (maxrun >= dis) {
                double needoil = (dis - sdis) / dps;
                printf("%.2f",
                       price + (oil >= needoil ? 0 : (needoil - oil)) * smps);
                return 0;
            } else {
                price += (cap - oil) * smps;
                pos++;
                while (stations[pos].mps != minprice)
                    pos++;
                oil = cap - double(stations[pos].dis - sdis) / dps;
            }
        }
    }

    return 0;
}