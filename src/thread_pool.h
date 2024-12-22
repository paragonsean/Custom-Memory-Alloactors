// #include <iostream>
// #include "RBFreeListAllocator.h"
// #include <mutex>
// #include <deque>
// #include <thread>
// #include <vector>
// #include <functional>
// #include <future>
// #include <stdexcept>

// class ThreadPool {
// public:
//     explicit ThreadPool(size_t numThreads) : taskAllocator_(1024) {
//         for (size_t i = 0; i < numThreads; ++i) {
//             workers_.emplace_back(std::thread([this]() {
//                 for (;;) {
//                     std::function<void()> task;

//                     {
//                         std::unique_lock<std::mutex> lock(queueMutex_);
//                         condition_.wait(lock, [this]() { return stop_ || !tasks_.empty(); });
//                         if (stop_ && tasks_.empty())
//                             return;
//                         task = std::move(tasks_.front());
//                         tasks_.pop_front();
//                     }

//                     task();
//                 }
//             }));
//         }
//     }

//     template <class F, class... Args>
//     auto enqueue(F&& f, Args&&... args) -> std::future<typename std::invoke_result<F, Args...>::type> {
//         using returnType = typename std::invoke_result<F, Args...>::type;

//         void* taskMemory = taskAllocator_.Allocate(sizeof(std::packaged_task<returnType()>));
//         auto task = new (taskMemory) std::packaged_task<returnType()>(
//             [f = std::forward<F>(f), ... args = std::forward<Args>(args)]() mutable { return f(args...); });

//         std::future<returnType> res = task->get_future();
//         {
//             std::unique_lock<std::mutex> lock(queueMutex_);
//             if (stop_)
//                 throw std::runtime_error("enqueue on stopped ThreadPool");

//             tasks_.emplace_back([task, this]() {
//                 (*task)();
//                 task->~packaged_task();
//                 taskAllocator_.Free(task, sizeof(std::packaged_task<returnType()>));
//             });
//         }
//         condition_.notify_one();
//         return res;
//     }

//     ~ThreadPool() {
//         {
//             std::unique_lock<std::mutex> lock(queueMutex_);
//             stop_ = true;
//         }
//         condition_.notify_all();
//         for (std::thread& worker : workers_) {
//             if (worker.joinable())
//                 worker.join();
//         }
//     }

// private:
//     std::vector<std::thread> workers_;
//     std::deque<std::function<void()>> tasks_;

//     std::mutex queueMutex_;
//     std::condition_variable condition_;
//     bool stop_ = false;

//     ASL::RBFreeListAllocator taskAllocator_;
// };

