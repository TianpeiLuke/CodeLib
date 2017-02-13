#include <iostream>
#include <thread>

using namespace std;
static const int num_threads = 10;

//This function will be called from a thread

void call_from_thread(int tid) {
    cout << "Launched by thread " << tid << endl;
}

int main() {
    thread t[num_threads];

    //Launch a group of threads
    for (int i = 0; i < num_threads; ++i) {
        t[i] = thread(call_from_thread, i);
    }

    cout << "Launched from the main\n";

    //Join the threads with the main thread
    for (int i = 0; i < num_threads; ++i) {
        t[i].join();
    }

    return 0;
}
