/*
回合制游戏
Description

回合制游戏是几千年前的经典游戏玩法。某一天，LeLe闲着无聊，便利用超能力模拟了一个5V55V5的回合制战场。在这个回合制战场中，规则如下：

每一回合中，速度越高，越先行动。
每个人造成的伤害都是单体，且伤害值即为其攻击力。
每个人的生命值都是有限，且当生命值小于等于00时即阵亡，无法再参与战斗。活到最后的队伍即为胜利者。
两个队伍AA、BB的攻击目标的顺序是固定不变的。例如：当AA的队伍攻击目标顺序为{5,2,3,1,4}5,2,3,1,4，则AA必须将BB的55号击杀后，才能开始攻击BB的22号，以此类推....现给出所有人的生命值，攻击力，速度，以及所有队伍的攻击目标顺序。你应该知道谁将会是获胜者吧？


Input

只有一组测试数据。接下来有1010行：

每一行为HP_iHP 
i
​	 ,ATK_iATK 
i
​	 ,SPE_iSPE 
i
​	 .分别用空格隔开。

(500<=HP_i<=1000,50<=ATK_i<=150,0<=SPEED<=500)(500<=HP 
i
​	 <=1000,50<=ATK 
i
​	 <=150,0<=SPEED<=500)第ii行分别为第ii个人物的生命，攻击力，速度。

其中，前55行表示AA队的11号人物，22号人物....55号人物，后55行表示BB队的11号人物，22号人物....55号人物，且保证所有人的速度不相同。

接下来22行。每一行共有55个数字，分别用空格隔开。

其中第一行为AA队的攻击目标顺序，第二行为BB队的攻击目标顺序。


Output

若AA队获胜，输出AA。若BB队获胜，输出BB。


Sample Input 1 

1000 150 500
1000 150 450
1000 150 400
1000 150 350
1000 150 300
500 50 1
500 50 2
500 50 3
500 50 4
500 50 5
5 1 3 4 2 
1 5 4 3 2 
Sample Output 1

A
Hint

行动顺序为{1,2,3,4,5,6,7,8,9,10}1,2,3,4,5,6,7,8,9,10。然后B队的5号玩家阵亡、1号玩家接着阵亡、3号玩家再接着阵亡、4号、2号前仆后继的阵亡。B队5人全都暴毙。A队获得胜利。
*/
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct game {
    int team;
    int hp;
    int attack;
    int speed;
};

game team[10];
queue<int> atkq[2];
game *speed[10];

bool isFaster(game *a, game *b) {
    if (a->speed > b->speed)
        return true;
    return false;
}

void oneRound() {
    for (int i = 0; i < 10; i++) {
        if (speed[i]->hp <= 0)
            continue;
        int atk = speed[i]->attack;
        int myteam = speed[i]->team;
        if (atkq[myteam].empty())
            break;
        int aite = (myteam ? 0 : 5) + atkq[myteam].front() - 1;
        team[aite].hp -= atk;
        if (team[aite].hp <= 0)
            atkq[myteam].pop();
    }
}

int isEnd() {
    bool isend = true;
    for (int i = 0; i < 5; i++)
        if (team[i].hp > 0)
            isend = false;
    if (isend)
        return 1;
    isend = true;
    for (int i = 5; i < 10; i++)
        if (team[i].hp > 0)
            isend = false;
    if (isend)
        return 0;
    return -1;
}

void print() {
    cout << "a:" << endl;
    for (int i = 0; i < 5; i++)
        cout << "hp: " << team[i].hp << " attack: " << team[i].attack
             << " speed: " << team[i].speed << endl;
    cout << "b:" << endl;
    for (int i = 5; i < 10; i++)
        cout << "hp: " << team[i].hp << " attack: " << team[i].attack
             << " speed: " << team[i].speed << endl;
}

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    int tmp;
    for (int i = 0; i < 10; i++) {
        cin >> team[i].hp >> team[i].attack >> team[i].speed;
        team[i].team = i < 5 ? 0 : 1;
    }
    for (int i = 0; i < 10; i++) {
        cin >> tmp;
        atkq[i / 5].push(tmp);
    }
    for (int i = 0; i < 10; i++)
        speed[i] = &team[i];
    sort(speed, speed + 10, isFaster);

    while (isEnd() == -1) {
        oneRound();
        //print();
    }
    cout << (isEnd() ? "B" : "A") << endl;

    return 0;
}
