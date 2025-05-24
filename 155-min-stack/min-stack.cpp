class MinStack {
public:
    stack<pair<int, int>> st;

    MinStack() {
    }

    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            st.push({val, min(val, st.top().second)});
        }
    }

    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }

    int top() {
        if (!st.empty()) {
            return st.top().first;
        }
        throw runtime_error("Stack is empty");
    }

    int getMin() {
        if (!st.empty()) {
            return st.top().second;
        }
        throw runtime_error("Stack is empty");
    }
};
