#include <bits/stdc++.h>
#include <semaphore.h>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;

sem_t semaphore;

// Thread function
void process(int process_id) {
    sem_wait(&semaphore); // Acquire semaphore

    cout << "Process " << process_id << " has acquired the resource." << endl;

    // Simulate some work with the resource
    this_thread::sleep_for(chrono::seconds(1));

    cout << "Process " << process_id << " is releasing the resource." << endl;
    sem_post(&semaphore); // Release semaphore
    
}

int main() {

    // Initialize semaphore with 3 permits
    sem_init(&semaphore, 0, 3);

    vector<thread> t;

    // Create 10 threads
    for (int i = 0; i < 10; i++) {
        t.emplace_back(process, i);
    }

    // Wait for all threads to finish
    for (auto &a : t) {
        a.join();
    }

    // Destroy semaphore
    sem_destroy(&semaphore);

    return 0;
}