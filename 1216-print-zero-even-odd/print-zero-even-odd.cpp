class ZeroEvenOdd {
private:
    int n;
    std::mutex m;
    std::condition_variable cv;
    int x;
    int y;
    int turn = 0;
    int i;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        x = 1;
        y = 0;
        i = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        unique_lock<std::mutex> lock(m);
        for (int j = 0; j < n; j++) {
            while (turn != 0 && turn != 2 && i < 2 * n) {
                cv.wait(lock);
            }
            if(i>=2*n) return;
            printNumber(y);
            turn++;
            cv.notify_all();
            i++;
        }
    }

    void even(function<void(int)> printNumber) {
        unique_lock<std::mutex> lock(m);
        while (i < 2 * n) {
            while (turn != 3 && i < 2 * n) {
                cv.wait(lock);
            }
            if(i>=2*n) return;
            printNumber(x);
            x++;
            i++;
            turn = 0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        unique_lock<std::mutex> lock(m);
        while (i < 2 * n) {
            while (turn != 1 && i < 2 * n) {
                cv.wait(lock);
            }
            if(i>=2*n) return;
            printNumber(x);
            x++;
            i++;
            turn = 2;
            cv.notify_all();
        }
    }
};
// 2n length