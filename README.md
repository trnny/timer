# timer

仿 **JavaScript** 的定时器 精度 **1ms**

> #include "timer" // 引入头文件
> int timerId;	// 计时器标识号 用于清除计时器
> timerId = setInterval([&]{ do sth. }, interval);	// 每隔interval毫秒do sth.
> timerId = setTimeout([&]{ do sth. }, timeout);  // timeout毫秒后do sth.
> clearInterval(timerId); clearTimeout(timerId);  // 清除计时器 其实这两个通用

**timeout、interval都是可以嵌套的哦**

改进方向

> “轮询”式相对“唤醒”式略浪费性能
>
> 自定义精度
>
> > 一是指定时器时间最小区分数值 目前是1ms
> >
> > 二是指定时器时间本身的精度 如用户态时间、内核态时间、真实时间等  目前是真实时间
>
> 定时器是异步的，但得注意的是任务并非在单独的线程中完成，即本质上还是同步的

**注意 定时器本身并不会阻塞程序 定时器任务队列也会不因为非空而阻止程序退出 即你需要你个"阻塞"**

> while(true)sleep(0);  // 这是一个很简单的阻塞