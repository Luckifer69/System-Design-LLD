#pragma once

#if defined(__MINGW32__) && !defined(_GLIBCXX_HAS_GTHREADS)
#include <windows.h>
#include <functional>
#include <utility>

class Mutex {
private:
    CRITICAL_SECTION cs;
public:
    Mutex() { InitializeCriticalSection(&cs); }
    ~Mutex() { DeleteCriticalSection(&cs); }
    void lock() { EnterCriticalSection(&cs); }
    void unlock() { LeaveCriticalSection(&cs); }
    Mutex(const Mutex&) = delete;
    Mutex& operator=(const Mutex&) = delete;
};

template<typename T>
class LockGuard {
private:
    T& mtx;
public:
    explicit LockGuard(T& m) : mtx(m) { mtx.lock(); }
    ~LockGuard() { mtx.unlock(); }
    LockGuard(const LockGuard&) = delete;
    LockGuard& operator=(const LockGuard&) = delete;
};

class Thread {
private:
    HANDLE handle;
    struct TaskWrapper {
        std::function<void()> task;
    };
    static DWORD WINAPI threadProc(LPVOID lpParam) {
        TaskWrapper* tw = static_cast<TaskWrapper*>(lpParam);
        if (tw && tw->task) {
            tw->task();
        }
        delete tw;
        return 0;
    }
public:
    Thread() : handle(NULL) {}

    template<typename Callable, typename... Args>
    explicit Thread(Callable&& func, Args&&... args) {
        auto boundFunc = std::bind(std::forward<Callable>(func), std::forward<Args>(args)...);
        TaskWrapper* tw = new TaskWrapper{boundFunc};
        handle = CreateThread(NULL, 0, threadProc, tw, 0, NULL);
    }

    ~Thread() {
        if (handle) {
            CloseHandle(handle);
        }
    }

    void join() {
        if (handle) {
            WaitForSingleObject(handle, INFINITE);
            CloseHandle(handle);
            handle = NULL;
        }
    }
};

#else
#include <mutex>
#include <thread>
using Mutex = std::mutex;
template<typename T>
using LockGuard = std::lock_guard<T>;
using Thread = std::thread;
#endif
