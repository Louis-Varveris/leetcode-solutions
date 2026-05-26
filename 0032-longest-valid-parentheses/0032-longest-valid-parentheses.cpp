class Solution 
{
public:
    int longestValidParentheses(string s) 
    {
        // Stack stores indices, not characters
        stack<int> st;
        // Push -1 as a base index.
        // This helps calculate the length of valid substrings.
        st.push(-1);
        int maxLength = 0;
        // Loop through every character in the string
        for (int i = 0; i < s.length(); i++) 
        {
            // If we see an opening parenthesis,
            // store its index in the stack.
            if (s[i] == '(') 
            {
                st.push(i);
            } 
            else 
            {
                // If we see a closing parenthesis,
                // try to match it with a previous '('.
                st.pop();
                // If the stack becomes empty,
                // it means there is no matching '(' for this ')'.
                // So we push the current index as the new base.
                if (st.empty()) 
                {
                    st.push(i);
                } 
                else 
                {
                    // If the stack is not empty,
                    // the substring from st.top() + 1 to i is valid.
                    int currentLength = i - st.top();
                    // Update the longest valid substring length.
                    maxLength = max(maxLength, currentLength);
                }
            }
        }
        return maxLength;
    }
};