class Solution 
{
public:
    string simplifyPath(string path) 
    {
        vector<string> stack;   // Stores valid directory names
        string current = "";    // Current directory being built

        // Add an extra '/' so the last directory gets processed
        path += '/';

        for(char c : path)
        {
            if(c == '/')
            {
                // Ignore empty directory names (caused by //)
                if(current == "")
                {
                    continue;
                }

                // "." means stay in current directory
                if(current == ".")
                {
                    // Do nothing
                }

                // ".." means go up one directory
                else if(current == "..")
                {
                    if(!stack.empty())
                    {
                        stack.pop_back();
                    }
                }

                // Normal directory name
                else
                {
                    stack.push_back(current);
                }

                // Reset for next directory
                current = "";
            }
            else
            {
                // Keep building the directory name
                current += c;
            }
        }

        // If nothing is in the stack, we're at root
        if(stack.empty())
        {
            return "/";
        }

        // Build the simplified path
        string answer = "";

        for(string dir : stack)
        {
            answer += "/" + dir;
        }

        return answer;
    }
};