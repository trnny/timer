#include <iostream>
#include <unistd.h>
#include "timer.h"

using std::cout;
using std::endl;

int main() {

    int count = 0;
    int it = setInterval([&]{
        cout << "每3000ms执行一次，第" << ++count << "次执行" << endl;
        if (count >= 8) {
            clearInterval(it);
            cout << "再过5000ms程序停止运行" << endl;
            setTimeout([&]{
                cout << "时间到了，停止运行" << endl;
                exit(0);
            }, 5000);
        }
    }, 3000);
    setTimeout([&]{
        cout << "我是0ms定时器" << endl;
    }, 0);
    cout << "我是直接输出" << endl;
    setTimeout([&]{
        cout << "我也是0ms定时器" << endl;
    }, 0);

    // 使用timeout模拟interval
    int timeoutId;
    FT timeoutCallback = [&]{
        cout << "我是timeout,我也能像interval一样反复执行" << endl;
        timeoutId = setTimeout(timeoutCallback, 2000);
    };
    timeoutCallback();
    setTimeout([&]{
        cout << "歇一会" << endl;
        clearTimeout(timeoutId);
        setTimeout([&]{
            cout << "继续" << endl;
            timeoutCallback();
        }, 5000);
    }, 7000);

    while (true)
        sleep(0);

}