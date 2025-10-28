#include "MaxArea.h"
#include <stack>

int MaxArea::largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    heights.push_back(0);
    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[i] < heights[st.top()]) {
            int h = heights[st.top()];
            st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        st.push(i);
    }
    heights.pop_back();
    return maxArea;
}
