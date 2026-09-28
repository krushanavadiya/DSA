# 662 - Maximum Width of Binary Tree

**Difficulty:** Medium

## Approach / Notes
1. The Setup
Instead of just putting a node in the queue, we put the node and its seat number together as a pair.

C++
// A queue holding pairs of {Node, Seat Number}
queue<pair<TreeNode*, long long int>> q;

// The root node takes seat 0.
q.push({root, 0}); 

2. Processing Level by Level
Inside your while (!q.empty()) loop, we need to figure out exactly who is in the current row before we start popping things out.

C++
while (!q.empty()) {
    int n = q.size(); // Exactly how many nodes are in this row right now?
    
    // Look at the very first person in this row. 
    // We will subtract their seat number from everyone else in this row to keep numbers small.
    long long int min_seat = q.front().second; 
    
    long long int first_seat, last_seat; // We will fill these in below

3. Processing the Nodes in the Current Row
Now we loop exactly n times to process only the nodes in the current row.

C++
    for (int i = 0; i < n; i++) {
        // Grab the node and calculate its "safe" seat number by subtracting min_seat
        long long int curr_seat = q.front().second - min_seat;
        TreeNode* node = q.front().first;
        q.pop();
        
        // If this is the very first node in the loop, record its seat
        if (i == 0) first_seat = curr_seat;
        
        // If this is the very last node in the loop, record its seat
        if (i == n - 1) last_seat = curr_seat;
        
        // Push the children to the next row using the seat formulas!
        if (node->left != NULL) {
            q.push({node->left, 2 * curr_seat + 1});
        }
        if (node->right != NULL) {
            q.push({node->right, 2 * curr_seat + 2});
        }
    }

4. Updating the Answer
Once that for loop finishes, you have looked at every node in the row. You know the first_seat and the last_seat.

C++
    // Calculate the width of this row, and see if it's the biggest one yet.
    ans = max(ans, last_seat - first_seat + 1);
} // End of the while loop

return ans;
