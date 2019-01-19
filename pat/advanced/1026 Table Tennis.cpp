// 5/9, but I want give up it.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct player {
    int time;
    int cost;
    int vip;
};
vector<player> players(10000);

bool cmp(player &a, player &b) { return a.time < b.time; }

void time2hms(int time) {
    printf("%02d:%02d:%02d", time / 3600, (time / 60) % 60, (time % 60));
}

int main(int argc, char const *argv[]) {
    int n, h, m, s, cost, vip;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d:%d:%d %d %d", &h, &m, &s, &cost, &vip);
        players[i] =
            player{h * 3600 + m * 60 + s, cost > 120 ? 120 : cost, vip};
    }
    sort(players.begin(), players.begin() + n, cmp);

    int K, M;
    int viptable[K] = {0};
    cin >> K >> M;
    while (M--) {
        int tmp;
        cin >> tmp;
        viptable[tmp - 1] = 1;
    }

    int time[K];
    fill(time, time + K, 28800);
    int counts[K] = {0};

    for (int i = 0; i < n; i++) {
        int arrive = players[i].time, cost = players[i].cost;
        int pos = 0, now = 1 << 31 - 1;
        for (int j = 0; j < K; j++)
            now = time[j] < now ? time[j] : now;
        while (time[pos] != now)
            pos++;
        if (now >= 75600)
            break;

        // printf("arrive:%d now:%d cost:%d\n", arrive, now, cost);

        if (viptable[pos])
            for (int j = i + 1; j < n && players[j].time <= now; j++)
                if (players[j].vip) {
                    arrive = players[j].time;
                    cost = players[j].cost;
                    players.erase(players.begin() + j);
                    n--;
                    i--;
                    break;
                }
        cost *= 60;

        if (now <= arrive) {
            time2hms(arrive);
            printf(" ");
            time2hms(arrive);
            printf(" 0\n");
            time[pos] = arrive + cost;
        } else {
            time2hms(arrive);
            printf(" ");
            time2hms(now);
            printf(" %d\n",
                   (now - arrive) / 60 + ((now - arrive) % 60 >= 30 ? 1 : 0));
            time[pos] = now + cost;
        }
        counts[pos]++;
    }
    bool flag = false;
    for (int i = 0; i < K; i++) {
        printf("%s%d", flag ? " " : "", counts[i]);
        flag = true;
    }
    return 0;
}
