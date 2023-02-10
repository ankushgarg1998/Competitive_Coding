stack<int> ss;
stack<int> mins;

MinStack::MinStack() {
    while(!ss.empty())
        ss.pop();
    while(!mins.empty())
        mins.pop();
}

void MinStack::push(int x) {
    ss.push(x);
    if(mins.empty()) {
        mins.push(x);
    } else {
        if(mins.top() >= x)
            mins.push(x);
    }
}

void MinStack::pop() {
    if(!ss.empty()) {
        if(mins.top() == ss.top())
            mins.pop();
        ss.pop();
    }
}

int MinStack::top() {
    return (ss.empty()? -1: ss.top());
}

int MinStack::getMin() {
    return (mins.empty()? -1: mins.top());
}

