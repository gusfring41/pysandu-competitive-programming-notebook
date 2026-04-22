// Monotonic Stack, next greater number in a circular array
// Time Complexity: O(N)
// Space Complexity: O(N)
// Use cases: ring problems, finding next larger obstacle in a loop

    int n; vector<int> arr(n);
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = 0; i < 2 * n; i++) {
        int num = arr[i % n];
        while (!st.empty() and arr[st.top()] < num) { // remove os menores
            res[st.top()] = num;
            st.pop();
        }
        if (i < n) {
            st.push(i);
        }
    }

// Monotonic Stack, next smaller element in a linear array 
// Use cases: largest rectangle in histogram, subarray contribution

    for (int i = 0; i < n; i++) {
        while (!st.empty() and arr[st.top()] > arr[i]) { // remove os maiores
            res[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
