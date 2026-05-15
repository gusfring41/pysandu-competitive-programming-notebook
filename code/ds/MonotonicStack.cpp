// Monotonic Stack, next greater number in a circular array
// Time Complexity: O(N)
// Space Complexity: O(N)
// Use cases: ring problems, finding next larger obstacle in a loop

for (int i = 0; i < 2 * n; i++) {
    int num = a[i % n];
    while (!st.empty() and a[st.top()] < num) { // remove os menores
        res[st.top()] = num; st.pop();
    }
    
    if (i < n) st.push(i);    
}

// Monotonic Stack, next smaller element in a linear array 
// Use cases: largest rectangle in histogram, subarray contribution

for (int i = 0; i < n; i++) {
    while (!st.empty() and a[st.top()] > a[i]) { // remove os maiores
        res[st.top()] = a[i];
        st.pop();
    }
    st.push(i);
}
