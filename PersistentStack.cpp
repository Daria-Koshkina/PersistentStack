#include <iostream>
#include <vector>

struct GameVersion {
    int value;
    int sum;
    int prev;
    /*GameVersion(int num, int sum, int prev) {
        this->num = num;
        this->sum = sum;
        this->prev = prev;
    }*/
};

GameVersion copy(int value, int sum, int prev) {
    return GameVersion{ value, sum, prev };
}

class PersistentStack {
public:
    std::vector<GameVersion> stack;
    PersistentStack() {
        stack = std::vector<GameVersion>(0);
    }

    void push(int num, int value) {
        if (stack.size() == 0) {
            stack.push_back(GameVersion{ num, value, 0 });
        }
        /*int sum = stack[stack.size() - 1].sum + value;
        int prev = stack[stack.size() - 1].num;
        GameVersion version = GameVersion{ num, sum, num };*/
        //GameVersion version = copy(stack[num].num, stack[num].sum + value, stack.size() - 1);
        int sum = stack[ver].sum + value;
        versions.push_back(Version(value, ver, sum));
        stack.push_back(version);
    }

    void pop(int num) {
        GameVersion curr = stack[num];
        GameVersion prev = stack[curr.prev];
        GameVersion copyV = copy(prev.num, prev.sum, prev.prev);
        stack.push_back(copyV);
    }

    int count() {
        return stack.size();
    }
};


int main()
{
    int n;
    std::cin >> n;
    PersistentStack stack = PersistentStack();
    stack.push(0, 0);
    for (int i = 0; i < n; ++i) {
        int num, value;
        std::cin >> num >> value;
        if (value == 0) {
            stack.pop(num);
        }
        else {
            stack.push(num, value);
        }
    }

    int sum = 0;
    for (int i = 0; i < stack.count(); ++i) {
        sum += stack.stack[i].sum;
    }
    std::cout << sum;

    return 0;
}
