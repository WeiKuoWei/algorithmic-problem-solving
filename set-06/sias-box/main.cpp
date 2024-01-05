#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    // priority_queue<long> maxHeap;
    // priority_queue<long, vector<long>, greater<long> > minHeap;
    stack<int> sample_stack;
    queue<int> sample_queue;
    priority_queue<int> sample_pq;

    bool is_stack = true, is_queue = true, is_pq = true;

    int n;
    cin >> n;
    while(n--)
    {
        int operation, value;
        cin >> operation >> value;
        if(operation == 1)
        {
            sample_stack.push(value);
            sample_queue.push(value);
            sample_pq.push(value);
        }
        else if(operation == 2)
        {
            int stack_top = sample_stack.top();
            int queue_front = sample_queue.front();
            int pq_top = sample_pq.top();
            if(stack_top != value)
            {
                is_stack = false;
            }
            if(queue_front != value)
            {
                is_queue = false;
            }
            if(pq_top != value)
            {
                is_pq = false;
            }
            sample_stack.pop();
            sample_queue.pop();
            sample_pq.pop();
        }
    }

    if(!is_stack && !is_queue && !is_pq)
    {
        cout << "impossible" << endl;
    }
    else if(is_stack && !is_queue && !is_pq)
    {
        cout << "stack" << endl;
    }
    else if(!is_stack && is_queue && !is_pq)
    {
        cout << "queue" << endl;
    }
    else if(!is_stack && !is_queue && is_pq)
    {
        cout << "priority queue" << endl;
    }
    else
    {
        cout << "not sure" << endl;
    }

    return 0;
}