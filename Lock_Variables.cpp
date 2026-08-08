#include <iostream>
#include <thread>
using namespace std;

bool lockVar = false;

void criticalSection(int id)
{
    while(lockVar);

    lockVar = true;

    cout << "Process " << id << " entered Critical Section\n";

    for(int i=0;i<100000000;i++);

    cout << "Process " << id << " exited Critical Section\n";

    lockVar = false;
}

int main()
{
    thread t1(criticalSection,1);
    thread t2(criticalSection,2);

    t1.join();
    t2.join();

    return 0;
}
