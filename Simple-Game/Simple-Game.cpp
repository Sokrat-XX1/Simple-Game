#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <fstream>
#include <vector>
#include <locale>

#define watch(x) cout << (#x) << " is " << (x) << endl

using namespace std;


class Воин {
public:
    int strength;
    int health;
    int dmg = rand() % 60;
    int speedAttack;
    double dps;
    string weapon;
    void WinPhrase() {
        cout << "Радостный полный победы АРГХ" << endl;
    }
    void LosePhrase() {
        cout << "Грустный полный поражения Аргх" << endl;
    }
    int getDmg() {
        return dmg;
    }
    Воин(int dmg) {
        this->dmg = dmg;
    }
    Воин() {}
    int Удар(int);
};

int Воин::Удар(int health) // сюда отправляется robin.health
{
    int a;
    if (dmg == 0)
        cout << "Miss!";
    a = health - dmg;
    return a;
}

class Лучник {
public:
    int dextery;
    string weapon;
    int health;
    double dps;
    int dmg = rand() % 80;
    int speedAttack;
    void WinPhrase() {
        cout << "Король здесь один и это я" << endl;
    }
    void LosePhrase() {
        cout << "Проиграл тупому быдло у падика,это позор" << endl;
    }
    int Выстрел(int);
};

int Лучник::Выстрел(int health) {
    int a;
    if (dmg == 0)
        cout << "Miss!";
    a = health - dmg;
    return a;
}

class Маг {
public:
    int intellect;
    int health;
    int dmg = 0;
    int mana;
    string weapon;
    void WinPhrase() {
        cout << "Маг: Моя магия сильнейшая" << endl;
    }
    void LosePhrase() {
        cout << "Маг: Тебе просто повезло" << endl;
    }
    int magickArrow(int health) {
        int a;
        a = health - 100;
        return a;
    }
    int BigMagickArrow(int health) {
        int a;
        a = health - 250;
        return a;
    }
    int HitStaff(int health) {
        int a;
        a = health - rand() % 30;
        return a;
    }
};

class Берсерк : public Воин {
public:

    void WinPhrase(int n = 0) {
        cout << "Берсерк: ";
        Воин::WinPhrase();
    }
    void LosePhrase(int n = 0) {
        cout << "Берсерк: ";
        Воин::LosePhrase();
    }
    int Dmg();
    int Ярость();
};

int Берсерк::Dmg() {
    dmg = rand() % 100 + 10;
    return dmg;
}

int Берсерк::Ярость() {
    dmg += 50;
    return dmg;
}

class Арбалетчик : public Лучник {
public:
    void WinPhrase(int n = 0) {
        cout << "Арбалетчик: ";
        Лучник::WinPhrase();
    }
    void LosePhrase(int n = 0) {
        cout << "Арбалетчик: ";
        Лучник::LosePhrase();
    }
    int Dmg();
    int DoubleShot(int);
};

int Арбалетчик::Dmg() {
    dmg = rand() % 100 + 30;
    return dmg;
}

int Арбалетчик::DoubleShot(int health) {
    int a;
    a = health - (dmg + dmg);
    // cout << endl << "Vanshot: " << a << endl << endl;
    return a;

}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    Берсерк viking;
    Арбалетчик robin;
    Маг alduin;
    Арбалетчик herokiller;
    viking.dps = viking.dmg * viking.speedAttack;
    robin.dps = robin.dmg * robin.speedAttack;
    viking.health = rand() % 1200 + 300;
    robin.health = rand() % 800 + 200;
    alduin.health = rand() % 750 + 200;
    herokiller.health = rand() % 750 + 200;
    watch(viking.health);
    watch(robin.health);
    watch(alduin.health);
    watch(herokiller.health);
    viking.dmg = viking.Dmg();
    robin.dmg = robin.Dmg();
    herokiller.dmg = robin.Dmg();
    cout << endl;
    watch(viking.dmg);
    watch(robin.dmg);
    watch(alduin.dmg);
    watch(herokiller.dmg);
    cout << endl;
    int k = 0, pers, cowldown_rage = 0, cowldown_arrow = 0, cowldown_bigArrow = 0;
    int col = 0;
    cout << "Выберите персонажа\n1) Viking(Берсерк)\n2) Alduin(Маг)\n3) Robin(Арбалетчик)\n"; cin >> pers;
    switch (pers) {
    case 1:
    {
        cout << endl << "ЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫЫ ТЕБЕ КАНЕЦ!!!" << endl << endl << "Берсерк вышел на ринг";
        cout << endl << endl << endl << "  0  | \\" << endl << "- | -| |" << endl << "  |  | /" << endl << " / " << "\\ |" << endl << endl << endl;
        while (1)
        {
            int x;

        Again:
            cout << "Выберите Атаку\n1) Удар\n2)Ярость\n "; cin >> x;
            switch (x)
            {
            case 1:
            {
                robin.health = viking.Удар(robin.health);
                cout << endl << "Вы нанесли Удар" << endl << endl << "Health enemy: " << robin.health << endl << endl;
                break;
            }
            case 2:
            {

                if (cowldown_rage == 4 || cowldown_rage == 0)
                {
                    cout << endl << "ААААААААААААА" << endl << endl;
                    viking.dmg = viking.Ярость();
                    cout << "My dmg: " << viking.dmg << endl;
                    cowldown_rage = 0;
                }
                if (cowldown_rage < 4 && cowldown_rage > 0)
                {
                    cout << endl << "Способность в кулдауне попробуйте другую абилку" << endl << endl;
                    cout << "------------------------------" << endl;
                    goto Again;
                }
                break;
            }
            }
            int choice = rand() % 2 + 1;

            switch (choice)
            {

            case 1:
            {
                viking.health = robin.Выстрел(viking.health);
                cout << endl << "Арбалетчик выстрелил" << endl << endl << "My Health: " << viking.health << endl << endl;
                break;
            }
            case 2:
            {

                if (col > 0)
                {
                    cout << endl << "Арбалетчик забыл что может выстрелить 2 раза только 1 раз и пропускает ход как жаль" << endl;
                    break;
                }
                if (col > 2)
                {
                    cout << endl << "Арбалетчик абсолютный даун он пытается выстрелить 2 раза уже в 3 раз" << endl;
                    break;
                }
                viking.health = robin.DoubleShot(viking.health);
                cout << endl << "Арбалетчик выстрелил 2 раза" << endl << endl << "My health: " << viking.health << endl << endl;
                col++;
                break;
            }
            }
            cout << "-----------------------------" << endl << endl;
            k++;
            if (robin.health <= 0 || viking.health <= 0)
                break;
            cowldown_rage++;
            if (k == 1) {
                if (x == 1)
                    cowldown_rage--;
            }
            goto Again;
        }


        cout << k * 2 << " ходов шла великая битва!" << endl;
        if (viking.health > robin.health) {
            viking.WinPhrase(1);
            robin.LosePhrase(1);
            break;
        }
        else {
            viking.LosePhrase(1);
            robin.WinPhrase(1);
            break;
        }

    }
    case 2:
        cout << endl << "Моя магия сокрушит тебя!!!";
        cout << endl << endl << "  0  |" << endl << "- | -|" << endl << "  |  |" << endl << " / " << "\\ |" << endl << endl << endl;
        while (1)
        {
            int x;
        MagAgain:
            cout << "Выберите Атаку\n1) Удар посохом\n2) Магический выстрел\n3) Большой магический выстрел\n"; cin >> x;
            switch (x)
            {
            case 1:
            {
                robin.health = alduin.HitStaff(robin.health);
                cout << endl << "Вы ударили посохом" << endl << endl << "Health enemy: " << robin.health << endl << endl;
                break;
            }
            case 2:
            {

                if (cowldown_arrow > 1 || cowldown_arrow == 0)
                {
                    cout << endl << "Левиоса стрелой" << endl << endl;
                    robin.health = alduin.magickArrow(robin.health);
                    cout << endl << "Вы выстрелили стрелой" << endl << endl << "Health enemy: " << robin.health << endl << endl;
                    cowldown_arrow = 0;
                }
                if (cowldown_arrow < 2 && cowldown_arrow > 0)
                {
                    cout << endl << "Способность в кулдауне попробуйте другую абилку" << endl << endl;
                    cout << "------------------------------" << endl;
                    goto MagAgain;
                }
                break;
            }
            case 3:
            {
                if (cowldown_bigArrow > 3 || cowldown_bigArrow == 0)
                {
                    cout << endl << "Левиоса большой стрелой" << endl << endl;
                    robin.health = alduin.BigMagickArrow(robin.health);
                    cout << endl << "Вы выстрелили большой стрелой" << endl << endl << "Health enemy: " << robin.health << endl << endl;
                    cowldown_bigArrow = 0;
                }
                if (cowldown_bigArrow < 4 && cowldown_bigArrow > 0)
                {
                    cout << endl << "Способность в кулдауне попробуйте другую абилку" << endl << endl;
                    cout << "------------------------------" << endl;
                    goto MagAgain;
                }
                break;
            }
            }
            int choice = rand() % 2 + 1;

            switch (choice)
            {

            case 1:
            {
                alduin.health = robin.Выстрел(alduin.health);
                cout << endl << "Арбалетчик выстрелил" << endl << endl << "My Health: " << alduin.health << endl << endl;
                break;
            }
            case 2:
            {

                if (col > 0)
                {
                    cout << endl << "Арбалетчик забыл что может выстрелить 2 раза только 1 раз и пропускает ход как жаль" << endl;
                    break;
                }
                if (col > 2)
                {
                    cout << endl << "Арбалетчик абсолютный даун он пытается выстрелить 2 раза уже в 3 раз" << endl;
                    break;
                }
                alduin.health = robin.DoubleShot(alduin.health);
                cout << endl << "Арбалетчик выстрелил 2 раза" << endl << endl << "My health: " << alduin.health << endl << endl;
                col++;
                break;
            }
            }
            cout << "-----------------------------" << endl << endl;
            k++;
            if (robin.health <= 0 || alduin.health <= 0)
                break;
            cowldown_arrow++;
            cowldown_bigArrow++;
            if (k == 1) {
                if (x == 1 || x == 3)
                    cowldown_arrow--;
            }
            if (k == 1) {
                if (x == 1 || x == 2)
                    cowldown_bigArrow--;
            }
            goto MagAgain;
        }


        cout << k * 2 << " ходов шла великая битва!" << endl;
        if (alduin.health > robin.health) {
            alduin.WinPhrase();
            robin.LosePhrase(1);
            break;
        }
        else {
            alduin.LosePhrase();
            robin.WinPhrase(1);
            break;
        }

    case 3:
    {
        cout << endl << "Самый меткий здесь я!!!";
        cout << endl << endl << "  0   " << endl << "- | - >" << endl << "  |   " << endl << " / " << "\\  " << endl << endl << endl;
        while (1)
        {
            int x;
        luchAgain:
            cout << "Выберите Атаку\n1) Выстрел\n2) Двойной выстрел\n"; cin >> x;
            switch (x)
            {
            case 1:
            {
                robin.health = herokiller.Выстрел(robin.health);
                cout << endl << "Вы выстрелили" << endl << endl << "Health enemy: " << robin.health << endl << endl;
                break;
            }
            case 2:
            {

                if (cowldown_arrow == 2 || cowldown_arrow == 0)
                {
                    cout << endl << "Двойной выстрел" << endl << endl;
                    robin.health = herokiller.DoubleShot(robin.health);
                    cout << endl << "Вы выстрелили стрелой 2 раза" << endl << endl << "Health enemy: " << robin.health << endl << endl;
                    cowldown_arrow = 0;
                }
                if (cowldown_arrow < 2 && cowldown_arrow > 0)
                {
                    cout << endl << "Способность в кулдауне попробуйте другую абилку" << endl << endl;
                    cout << "------------------------------" << endl;
                    goto luchAgain;
                }
                break;
            }

            }
            int choice = rand() % 2 + 1;

            switch (choice)
            {

            case 1:
            {
                herokiller.health = robin.Выстрел(herokiller.health);
                cout << endl << "Арбалетчик выстрелил" << endl << endl << "My Health: " << herokiller.health << endl << endl;
                break;
            }
            case 2:
            {

                if (col > 0)
                {
                    cout << endl << "Арбалетчик забыл что может выстрелить 2 раза только 1 раз и пропускает ход как жаль" << endl;
                    break;
                }
                if (col > 2)
                {
                    cout << endl << "Арбалетчик абсолютный даун он пытается выстрелить 2 раза уже в 3 раз" << endl;
                    break;
                }
                herokiller.health = robin.DoubleShot(herokiller.health);
                cout << endl << "Арбалетчик выстрелил 2 раза" << endl << endl << "My health: " << herokiller.health << endl << endl;
                col++;
                break;
            }
            }
            cout << "-----------------------------" << endl << endl;
            k++;
            if (robin.health <= 0 || herokiller.health <= 0)
                break;
            cowldown_arrow++;
            if (k == 1) {
                if (x == 1)
                    cowldown_arrow--;
            }
            goto luchAgain;
        }


        cout << k * 2 << " ходов шла великая битва!" << endl;
        if (herokiller.health > robin.health) {
            herokiller.WinPhrase();
            robin.LosePhrase(1);
            break;
        }
        else {
            herokiller.LosePhrase();
            robin.WinPhrase(1);
            break;
        }
    }
    }
}
