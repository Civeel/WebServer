#pragma once

#include <functional>
#include <memory>

#include "noncopyable.h"
#include "Timestamp.h"

class EventLoop;

/* 
    理清楚EventLoop, Channel, Poller之间关系，Reactor模型上对应多路事件分发器
    Channel理解为通道，封装了sockfd和其感兴趣的event，如EPOLLIN, EPOLLOUT事件，还绑定了poller返回的具体事件
*/
class Channel : noncopyable {
public:
    using EventCallback = std::function<void()>;
    using ReadEventCallback = std::function<void(Timestamp)>;

    Channel(EventLoop *loop, int fd);
    ~Channel();

    //fd得到Poller通知以后，处理事件handleEvent在EventLoop::loop()中调用
    
};