class Solution {
public:
    vector<int> bottomView(Node *root) {
        vector<int> bottomElement;  // Vector to store the bottom view elements
        map<int, int> mp;  // Map to store the horizontal distance and the corresponding node value

        // Queue of pairs where the first element is the Node pointer and the second element is the horizontal distance from the root
        queue<pair<Node*, int>> q;
        q.push({root, 0});  // Start with the root node at horizontal distance 0

        while (!q.empty()) {
            auto it = q.front();  // Get the front element of the queue
            q.pop();  // Remove the front element from the queue
            Node* temp = it.first;  // Current node
            int line = it.second;  // Horizontal distance of the current node
            mp[line] = temp->data;  // Overwrite the map value for this horizontal distance

            // If there is a left child, add it to the queue with horizontal distance - 1
            if (temp->left) {
                q.push({temp->left, line - 1});
            }
            // If there is a right child, add it to the queue with horizontal distance + 1
            if (temp->right) {
                q.push({temp->right, line + 1});
            }
        }

        // Traverse the map and add the node values to the bottomElement vector
        for (auto it : mp) {
            bottomElement.push_back(it.second);
        }

        return bottomElement;  // Return the bottom view elements
    }
};
