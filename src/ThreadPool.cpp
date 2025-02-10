#include "ThreadPool.h"
#include <iostream>

// creates and starts the worker thread process
ThreadPool::ThreadPool(size_t numThreads) : stop(false)
{
    for (size_t i = 0; i < numThreads; i++)
    {
        workers.push_back(std::thread(&ThreadPool::worker, this));
    }
}

// exists to stop the threads
ThreadPool::~ThreadPool()
{
    {
        std::lock_guard<std::mutex> lock(queueMutex);
        stop = true;
    }
    // notify all the threads to stop
    condition.notify_all();
    // join all worker threads
    for (std::thread &worker : workers)
    {
        worker.join();
    }
}

void ThreadPool::submit(std::function<void()> task)
{
    {
        std::lock_guard<std::mutex> lock(queueMutex);
        tasks.push(task); // add task to queue
        taskCount++;
    }
    condition.notify_one(); // notify a thread to start working
}

void ThreadPool::worker()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(3)); // an added delay to simulate transactions coming in
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            // wait for a task to be able to process or the pool to stop
            condition.wait(lock, [this]
                           { return stop || !tasks.empty(); });

            if (stop && tasks.empty())
            {
                return; // exit once the pool is empty and no tasks exist
            }
            // take the task from the queue
            task = std::move(tasks.front());
            tasks.pop();
        }
        // execute the task
        task();
        taskCount--;
    }
}

// used to sync main with ThreadPool
void ThreadPool::waitForCompletion()
{
    while (taskCount > 0)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}