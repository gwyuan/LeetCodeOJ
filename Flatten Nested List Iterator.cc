// Runtime: 33 ms

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
struct Node {
    Node *next;
    int val;

    Node(int _val) {
        next = NULL;
        val = _val;
    }
}; 
 
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        head = NULL;
        tail = head;
        flattenList(nestedList);
    }

    int next() {
        Node* tmp = head->next;
        int ret = head->val;
        delete head;
        head = tmp;
        return ret;
    }

    bool hasNext() {
        return (head != NULL);
    }
private:
    Node* head;
    Node* tail;
    void flattenList(vector<NestedInteger> &nestedList) {
        for(vector<NestedInteger>::iterator it = nestedList.begin(); it != nestedList.end(); it++) {
            if (it->isInteger()) {
                if (head == NULL) {
                    head = new Node(it->getInteger());
                    tail = head;
                }
                else {
                    Node* tmp = new Node(it->getInteger());
                    tail->next = tmp;
                    tail = tmp;
                }
            }
            else
                flattenList(it->getList());
        }
    }
    
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */