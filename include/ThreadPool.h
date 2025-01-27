#ifndef THREADPOOL_H
#define THREADPOOL_H
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <atomic>

class ThreadPool
{
public:
    explicit ThreadPool(size_t numThreads); // weird looking constructor
    ~ThreadPool();

    void submit(std::function<void()> task); // exists for submitting to the worker thread

    void waitForCompletion();

private:
    void worker();

    std::vector<std::thread> workers;        // the current pool of worker threads
    std::queue<std::function<void()>> tasks; // thet ask queue for the worker threads
    std::mutex queueMutex;                   // for syncing
    std::condition_variable condition;       // also for syncing
    bool stop;                               // flag for stopping the pool
    std::atomic<int> taskCount;              // used to sync main with thread pool
};

#endif