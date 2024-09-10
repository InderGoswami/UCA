class Solution {
    public int largestRectangleArea(int[] heights) {
        // find nearest smallest on left side
        int nSl[] = new int[heights.length];
        Stack<Integer> st = new Stack();
        for (int i = 0; i < heights.length; i++) {
            while (!st.isEmpty() && heights[i] <= heights[st.peek()]) {
                st.pop();
            }
            if (st.isEmpty()) {
                nSl[i] = 0;
            } else {
                nSl[i] = st.peek() + 1;
            }
            st.push(i);

        }
        st.clear();
        // next smallest element in right side
        int nSr[] = new int[heights.length];
        for (int i = heights.length - 1; i >= 0; i--) {
            while (!st.isEmpty() && heights[i] <= heights[st.peek()]) {
                st.pop();
            }
            if (st.isEmpty()) {
                nSr[i] = heights.length - 1;
            } else {
                nSr[i] = st.peek() - 1;
            }
            st.push(i);

        }

        int ans = 0;
        for (int i = 0; i < heights.length; i++) {
            ans = Math.max(ans, heights[i] * (nSr[i] - nSl[i] + 1));
        }

        return ans;

    }
}

