#include "knight.h"

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

class Enemy
{
protected:
    int level;
    int base_damage;

public:
    Enemy(int _level, int _base_damage) : level(_level), base_damage(_base_damage) {}
    virtual ~Enemy() {}
    virtual int getLevel()
    {
        return this->level;
    }
    virtual int getDamage()
    {
        return this->level * base_damage;
    }
};

class MadBear : public Enemy
{
public:
    MadBear(int _level) : Enemy(_level, 10) {}
};

class Bandit : public Enemy
{
public:
    Bandit(int _level) : Enemy(_level, 15) {}
};

class LordLupin : public Enemy
{
public:
    LordLupin(int _level) : Enemy(_level, 45) {}
};

class Elf : public Enemy
{
public:
    Elf(int _level) : Enemy(_level, 75) {}
};

class Troll : public Enemy
{
public:
    Troll(int _level) : Enemy(_level, 95) {}
};

class Shaman
{
private:
    int level;

public:
    // Constructor
    Shaman(int lvl)
    {
        this->level = lvl;
    }

    int getLevel() const
    {
        return this->level;
    }

    void setLevel(int lvl)
    {
        this->level = lvl;
    }
};

class Vajsh
{
private:
    int level;

public:
    // Constructor
    Vajsh(int lvl)
    {
        this->level = lvl;
    }

    int getLevel() const
    {
        return this->level;
    }

    void setLevel(int lvl)
    {
        this->level = lvl;
    }
};

class Knight
{
private:
    int HP;
    int MaxHP;
    int level;
    int remedy;
    int maidenkiss;
    int phoenixdown;
    bool isArthur = false;
    bool isLancelot = false;
    bool isDwarf = false;
    bool isFrog = false;
    bool isMeetMerlin = false;
    bool isMeetAsclepius = false;
    int lvlFrog = 0;
    int countAffect = 0;

public:
    // Constructor
    Knight(int hp, int lvl, int rmd, int mk, int pd)
    {
        this->HP = hp;
        this->MaxHP = hp;
        this->level = lvl;
        this->remedy = rmd;
        this->maidenkiss = mk;
        this->phoenixdown = pd;

        if (this->HP == 999)
        {
            this->isArthur = true;
        }

        if (isPrime(this->HP))
        {
            this->isLancelot = true;
        }
    }

    // Default constructor
    Knight() : Knight(1, 1, 0, 0, 0) {}

    // Getters
    int getHP() const
    {
        return this->HP;
    }

    int getMaxHP() const
    {
        return this->MaxHP;
    }

    int getLevel() const
    {
        return this->level;
    }

    int getRemedy() const
    {
        return this->remedy;
    }

    int getMaidenKiss() const
    {
        return this->maidenkiss;
    }

    int getPhoenixDown() const
    {
        return this->phoenixdown;
    }

    bool getisArthur() const
    {
        return this->isArthur;
    }

    bool getisLancelot() const
    {
        return this->isLancelot;
    }

    bool getisDwarf()
    {
        return this->isDwarf;
    }

    bool getisFrog()
    {
        return this->isFrog;
    }

    bool getisMeetMerlin()
    {
        return this->isMeetMerlin;
    }

    bool getisMeetAsclepius()
    {
        return this->isMeetAsclepius;
    }

    int getLevelFrog()
    {
        return this->lvlFrog;
    }

    int getCountAffect()
    {
        return this->countAffect;
    }
    // Setters
    void setHP(int hp)
    {
        if (hp < this->MaxHP)
        {
            this->HP = hp;
        }
        else
        {
            this->HP = this->MaxHP;
        }
    }

    void setMaxHP(int maxhp)
    {
        this->MaxHP = maxhp;
    }

    void setLevel(int lvl)
    {
        if (lvl < 1)
        {
            this->level = 1;
        }
        else if (lvl > 10)
        {
            this->level = 10;
        }
        else
        {
            this->level = lvl;
        }
    }

    void setRemedy(int rmd)
    {
        if (rmd < 0)
        {
            this->remedy = 0;
        }
        else if (rmd > 99)
        {
            this->remedy = 99;
        }
        else
        {
            this->remedy = rmd;
        }
    }

    void setMaidenKiss(int mk)
    {
        if (mk < 0)
        {
            this->maidenkiss = 0;
        }
        else if (mk > 99)
        {
            this->maidenkiss = 99;
        }
        else
        {
            this->maidenkiss = mk;
        }
    }

    void setPhoenixDown(int pd)
    {
        if (pd < 0)
        {
            this->phoenixdown = 0;
        }
        else if (pd > 99)
        {
            this->phoenixdown = 99;
        }
        else
        {
            this->phoenixdown = pd;
        }
    }

    void setisDwarf(bool isDwarf)
    {
        this->isDwarf = isDwarf;
    }

    void setisFrog(bool isFrog)
    {
        this->isFrog = isFrog;
    }

    void setisMeetMerlin(bool isMeetMerlin)
    {
        this->isMeetMerlin = isMeetMerlin;
    }

    void setisMeetAsclepius(bool isMeetAsclepius)
    {
        this->isMeetAsclepius = isMeetAsclepius;
    }

    void setLevelFrog(int lvlFrog)
    {
        this->lvlFrog = lvlFrog;
    }

    void setCountAffect(int count)
    {
        this->countAffect = count;
    }

    std::string toString()
    {
        std::stringstream ss;
        ss << "HP: " << this->HP << "\n";
        ss << "Level: " << this->level << "\n";
        ss << "Arthur: " << (this->isArthur ? "yes" : "no") << "\n";
        ss << "Lancelot: " << (this->isLancelot ? "yes" : "no") << "\n";
        ss << "Is Dwarf: " << (this->isDwarf ? "yes" : "no") << "\n";
        ss << "Is Frog: " << (this->isFrog ? "yes" : "no") << "\n";
        ss << "Remedy: " << this->remedy << "\n";
        ss << "Maidenkiss: " << this->maidenkiss << "\n";
        ss << "Phoenixdown: " << this->phoenixdown << "\n";
        return ss.str();
    }

    void fight(Enemy enemy)
    {

        if (this->level > enemy.getLevel() || this->isArthur || this->isLancelot)
        {
            // Knight wins
            if (this->level < 10)
            {
                setLevel(this->level + 1);
            }
        }
        else if (this->level == enemy.getLevel())
        {
            // Draw
        }
        else
        {
            // Knight loses
            int newHP = this->HP - enemy.getDamage();
            if (newHP < 1)
            {
                if (getPhoenixDown() > 0)
                {
                    setPhoenixDown(getPhoenixDown() - 1);
                    setisDwarf(false);
                    newHP = getMaxHP();
                }
            }
            setHP(newHP);
        }
    }

    void fight(Shaman shaman)
    {

        if (this->level > shaman.getLevel() || this->isArthur || this->isLancelot)
        {
            // Knight wins
            if (this->level < 10)
            {
                setLevel(this->level + 2);
            }
        }
        else if (this->level == shaman.getLevel())
        {
            // Draw
        }
        else
        {
            // Lose
            if (this->remedy > 0)
            {
                setRemedy(this->remedy - 1);
                int newHP = this->HP / 5;
                setHP(newHP * 5);
            }
            else
            {
                // turn the knight into a dwarf for the next 3 events
                setisDwarf(true);
                setCountAffect(0);
                int newHP = this->HP / 5;
                if (newHP < 5)
                {
                    setHP(1);
                }
                else
                {
                    setHP(newHP);
                }
            }
        }
    }

    void fight(Vajsh vajsh)
    {
        if (this->level > vajsh.getLevel() || this->isArthur || this->isLancelot)
        {
            // Knight wins
            if (this->level < 10)
            {
                setLevel(this->level + 1);
            }
        }
        else if (this->level == vajsh.getLevel())
        {
            // Draw
        }
        else
        {
            // Lose
            if (this->maidenkiss > 0)
            {
                setMaidenKiss(this->maidenkiss - 1);
            }
            else
            {
                // turn the knight into a frog for the next 3 events
                setisFrog(true);
                setCountAffect(0);
                setLevelFrog(getLevel());
                setLevel(1);
            }
        }
    }

    void handleMushMario()
    {
        int n1 = ((this->level + this->phoenixdown) % 5 + 1) * 3;

        int s1 = 0;
        int count = 0;
        for (int i = 99; i >= 1 && count < n1; i -= 2)
        {
            s1 += i;
            count++;
        }

        int newHP = this->HP + (s1 % 100);
        int prime = newHP;
        while (!isPrime(prime))
        {
            prime++;
        }
        setHP(prime);
    }

    void handleMushFibo()
    {
        if (this->HP > 1)
        {
            int prev = 1, curr = 1, fibo = 1;
            while (fibo <= this->HP)
            {
                prev = curr;
                curr = fibo;
                fibo = prev + curr;
            }
            setHP(fibo);
        }
    }

    void handleGhostMushRoom(char type, int a[], int n)
    {
        int *arr = new int[n]; // create a copy of the array
        for (int i = 0; i < n; i++)
        {
            arr[i] = a[i];
        }

        if (type == '1')
        {
            int max_val = arr[0], min_val = arr[0];
            int max_last_occurrence = 0, min_last_occurrence = 0;
            for (int i = 1; i < n; i++)
            {
                if (arr[i] > max_val)
                {
                    max_val = arr[i];
                    max_last_occurrence = i;
                }
                if (arr[i] < min_val)
                {
                    min_val = arr[i];
                    min_last_occurrence = i;
                }
            }

            setHP(this->HP - (max_last_occurrence + min_last_occurrence));
        }
        if (type == '2')
        {
            int mtx = -2, mti = -3;
            int max_idx = 0;
            for (int i = 1; i < n; i++)
            {
                if (arr[i] > arr[max_idx])
                {
                    max_idx = i;
                }
            }

            if (max_idx == 0 || max_idx == n - 1)
            {
                mtx = arr[max_idx];
                mti = max_idx;
            }
            else
            {
                bool isIncreasing = true;
                for (int i = 0; i < max_idx; i++)
                {
                    if (arr[i] >= arr[i + 1])
                    {
                        isIncreasing = false;
                        break;
                    }
                }

                bool isDecreasing = true;
                for (int i = max_idx; i < n - 1; i++)
                {
                    if (arr[i] <= arr[i + 1])
                    {
                        isDecreasing = false;
                        break;
                    }
                }

                if (isIncreasing && isDecreasing)
                {
                    mtx = arr[max_idx];
                    mti = max_idx;
                }
                else
                {
                    mtx = -2;
                    mti = -3;
                }
            }

            setHP(getHP() - (mtx + mti));
        }
        if (type == '3')
        {
            // Perform transformations on the array
            for (int i = 0; i < n; i++)
            {
                if (arr[i] < 0)
                {
                    arr[i] = -arr[i];
                }
                arr[i] = (17 * arr[i] + 9) % 257;
            }

            // Find the positions of the max and min values in the transformed array
            int maxi2 = 0, mini2 = 0;
            for (int i = 1; i < n; i++)
            {
                if (arr[i] > arr[maxi2])
                {
                    maxi2 = i;
                }
                if (arr[i] < arr[mini2])
                {
                    mini2 = i;
                }
            }

            // Calculate HP and print the result
            setHP(getHP() - (maxi2 + mini2));
        }
        if (type == '4')
        {
            // Transform the array
            for (int i = 0; i < n; i++)
            {
                if (arr[i] < 0)
                {
                    arr[i] = -arr[i];
                }
                arr[i] = (17 * arr[i] + 9) % 257;
            }

            // Find the second largest number and its position in the first three numbers of the array
            int max2_3x = -5, max2_3i = -7;
            int max = arr[0];
            int secondMax = arr[1];
            int position = 1;
            if (arr[2] > max)
            {
                secondMax = max;
                max = arr[2];
                position = 2;
            }
            else if (arr[2] > secondMax)
            {
                secondMax = arr[2];
                position = 2;
            }
            if (position == 1)
            {
                if (arr[1] > arr[2])
                {
                    max2_3x = arr[1];
                    max2_3i = 1;
                }
                else
                {
                    max2_3x = arr[2];
                    max2_3i = 2;
                }
            }
            else if (position == 2)
            {
                if (arr[0] > arr[1])
                {
                    max2_3x = arr[0];
                    max2_3i = 0;
                }
                else
                {
                    max2_3x = arr[1];
                    max2_3i = 1;
                }
            }
            else
            {
                max2_3x = -5;
                max2_3i = -7;
            }

            // Update HP
            setHP(getHP() - (max2_3x + max2_3i));
        }

        delete[] arr;
    }

    void handleMeetMerlin(string file_merlin_pack)
    {
        ifstream file;
        file.open(file_merlin_pack);
        if (!file)
        {
            cerr << "Hmu Hmu";
            return;
        }

        int n9;
        file >> n9;
        string items[n9];
        for (int i = 0; i < n9; i++)
        {
            file >> items[i];
        }

        for (int i = 0; i < n9; i++)
        {
            bool contains_all_chars = true;
            bool contains_merlin = false;
            for (char c : {'m', 'e', 'r', 'l', 'i', 'n'})
            {
                bool found = false;
                for (char ch : items[i])
                {
                    if (tolower(ch) == c)
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    contains_all_chars = false;
                    break;
                }
            }
            if (items[i].find("Merlin") != string::npos || items[i].find("merlin") != string::npos)
            {
                contains_merlin = true;
            }
            if (contains_all_chars)
            {
                if (contains_merlin)
                {
                    setHP(this->HP + 3);
                }
                else
                {
                    setHP(this->HP + 2);
                }
            }
        }
    }

    void handleMeetAsclepius(string file_asclepius_pack)
    {
        ifstream infile(file_asclepius_pack);
        if (!infile)
        {
            cout << "Hmu Hmu" << endl;
            return;
        }

        int r1, c1;
        infile >> r1 >> c1;

        int medicines[r1][c1];
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                infile >> medicines[i][j];
            }
        }

        infile.close();

        int count_medicines_pick = 0;

        for (int i = 0; i < r1; i++)
        {
            count_medicines_pick = 0;
            for (int j = 0; j < c1; j++)
            {
                if (medicines[i][j] == 16 || medicines[i][j] == 17 || medicines[i][j] == 18)
                {
                    if (medicines[i][j] == 16)
                    {
                        setRemedy(getRemedy() + 1);
                        if (getisDwarf())
                        {
                            setRemedy(getRemedy() - 1);
                            setisDwarf(false);
                            setHP(getHP() * 5);
                            setCountAffect(0);
                        }

                        count_medicines_pick++;
                    }
                    if (medicines[i][j] == 17)
                    {
                        setMaidenKiss(getMaidenKiss() + 1);
                        if (getisFrog())
                        {
                            setMaidenKiss(getMaidenKiss() - 1);
                            setisFrog(false);
                            setLevel(getLevelFrog());
                            setCountAffect(0);
                        }
                        count_medicines_pick++;
                    }
                    if (medicines[i][j] == 18)
                    {
                        setPhoenixDown(getPhoenixDown() + 1);
                        count_medicines_pick++;
                    }
                }
                if (count_medicines_pick == 3)
                {
                    count_medicines_pick = 0;
                    break;
                }
            }
        }
    }
};

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue)
{
    cout << "HP=" << HP
         << ", level=" << level
         << ", remedy=" << remedy
         << ", maidenkiss=" << maidenkiss
         << ", phoenixdown=" << phoenixdown
         << ", rescue=" << rescue << endl;
}

void adventureToKoopa(string file_input, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue)
{
    int events[10000];
    string file_mush_ghost;
    string file_asclepius_pack;
    string file_merlin_pack;
    int num_events = 0;
    rescue = -1;

    ifstream input_file(file_input);
    if (input_file.is_open())
    {
        input_file >> HP >> level >> remedy >> maidenkiss >> phoenixdown;

        string line;
        getline(input_file, line); // read the end of the first line
        getline(input_file, line); // read the second line
        istringstream iss(line);
        int event;
        while (iss >> event)
        {
            events[num_events++] = event;
        }

        getline(input_file, line); // read the third line
        istringstream iss2(line);
        getline(iss2, file_mush_ghost, ',');
        getline(iss2, file_asclepius_pack, ',');
        getline(iss2, file_merlin_pack);
        input_file.close();
    }

    Knight knight(HP, level, remedy, maidenkiss, phoenixdown);

    for (int i = 0; i < num_events; i++)
    {
        int b = (i + 1) % 10;
        int levelO = (i + 1) > 6 ? (b > 5 ? b : 5) : b;
        int event = events[i];
        if (knight.getisDwarf())
        {
            knight.setCountAffect(knight.getCountAffect() + 1);
        }
        switch (event)
        {
        case 0: // Bowser ?????u h??ng v?? tr??? l???i c??ng ch??a
            rescue = 1;
            display(knight.getHP(), knight.getLevel(), knight.getRemedy(), knight.getMaidenKiss(), knight.getPhoenixDown(), rescue);
            return;
        case 1: // G???p g???u MadBear
            knight.fight(MadBear(levelO));
            break;
        case 2: // G???p c?????p Bandit
            knight.fight(Bandit(levelO));
            break;
        case 3: // G???p t?????ng c?????p LordLupin
            knight.fight(LordLupin(levelO));
            break;
        case 4: // G???p y??u tinh Elf
            knight.fight(Elf(levelO));
            break;
        case 5: // G???p qu??? kh???ng l??? Troll
            knight.fight(Troll(levelO));
            break;
        case 6: // G???p ph?? thu??? Shaman
            knight.fight(Shaman(levelO));
            break;
        case 7: // G???p Siren Vajsh
            knight.fight(Vajsh(levelO));
            break;
        case 11: // Nh???t ???????c n???m t??ng l???c MushMario
            knight.handleMushMario();
            break;
        case 12: // Nh???t ???????c n???m Fibonacci MushFib
            knight.handleMushFibo();
            break;
        case 15: // Nh???t ???????c thu???c ph???c h???i Remedy
            knight.setRemedy(knight.getRemedy() + 1);
            break;
        case 16: // Nh???t ???????c thu???c gi???i MaidenKiss
            knight.setMaidenKiss(knight.getMaidenKiss() + 1);
            break;
        case 17: // Nh???t ???????c gi???t n?????c m???t ph?????ng ho??ng PhoenixDown
            knight.setPhoenixDown(knight.getPhoenixDown() + 1);
            break;
        case 18: // G???p ph?? thu??? Merlin
            if (!knight.getisMeetMerlin())
            {
                knight.setisMeetMerlin(true);
                knight.handleMeetMerlin(file_merlin_pack);
            }

            break;
        case 19: // G???p th???n Asclepius
        {
            if (!knight.getisMeetAsclepius())
            {
                knight.setisMeetAsclepius(true);
                knight.handleMeetAsclepius(file_asclepius_pack);
            }
        }
        break;
        case 99: // G???p Bowser
            if (knight.getLevel() >= 8)
            {
                if (knight.getisArthur() || knight.getisLancelot())
                {
                    knight.setLevel(10);
                    break;
                }
                else if (knight.getLevel() == 10)
                {
                    break;
                }
            }
            knight.setHP(0);
            rescue = 0;
            break;
        default: // Nh???t ???????c n???m ma MushGhost
            ifstream file_in(file_mush_ghost);

            if (!file_in.is_open())
            {
                cout << "Hmu hmu";
                return;
            }

            int n2;
            file_in >> n2;

            int a[n2];
            string line;
            getline(file_in, line);
            getline(file_in, line); // read the whole line as a string
            stringstream ss(line);  // create a stringstream from the string

            for (int i = 0; i < n2; i++)
            {
                string number_str;
                getline(ss, number_str, ','); // read the next number as a string, using comma as delimiter
                a[i] = stoi(number_str);      // convert the string to integer and store in the array
            }

            file_in.close();

            string ms = to_string(event).substr(2);
            for (char c : ms)
            {
                knight.handleGhostMushRoom(c, a, n2);
            }

            break;
        }

        if (knight.getCountAffect() == 3)
        {
            if (knight.getisDwarf())
            {
                knight.setisDwarf(false);
                knight.setCountAffect(0);
                knight.setHP(knight.getHP() * 5);
            }
            if (knight.getisFrog())
            {
                knight.setisFrog(false);
                knight.setCountAffect(0);
                knight.setLevel(knight.getLevelFrog());
            }
        }

        if (knight.getHP() < 1)
        {
            rescue = 0;
            display(knight.getHP(), knight.getLevel(), knight.getRemedy(), knight.getMaidenKiss(), knight.getPhoenixDown(), rescue);
            return;
        }
        if (i < num_events - 1)
        {
            display(knight.getHP(), knight.getLevel(), knight.getRemedy(), knight.getMaidenKiss(), knight.getPhoenixDown(), rescue);
        }
    }
    rescue = 1;
    display(knight.getHP(), knight.getLevel(), knight.getRemedy(), knight.getMaidenKiss(), knight.getPhoenixDown(), rescue);
}