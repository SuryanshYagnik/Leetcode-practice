class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;  // Stack to store asteroids
        
        for (int asteroid : asteroids) {
            // Handle collisions only when current asteroid is moving left and top of stack is moving right
            bool destroyed = false;
            
            while (!s.empty() && asteroid < 0 && s.top() > 0) {
                if (abs(asteroid) > abs(s.top())) {
                    // Current asteroid is larger, pop the stack and continue checking
                    s.pop();
                } else if (abs(asteroid) == abs(s.top())) {
                    // Both are the same size, both should be destroyed
                    s.pop();
                    destroyed = true;
                    break;
                } else {
                    // Current asteroid is smaller, it gets destroyed
                    destroyed = true;
                    break;
                }
            }
            
            if (!destroyed) {
                // No collision occurred, push current asteroid to the stack
                s.push(asteroid);
            }
        }
        
        // Prepare result from stack
        vector<int> result(s.size());
        for (int i = s.size() - 1; i >= 0; i--) {
            result[i] = s.top();
            s.pop();
        }
        
        return result;
    }
};
