/*
Design and implement a data structure for Least Recently Used (LRU) cache. 
It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item. 
*/

class LRUCache{
public:
    LRUCache(int capacity) {
        max_size = capacity > 0 ? capacity : 0;
    }
    
    int get(int key) {
    	int ret = -1;

        if (map.count(key) != 0) {
        	// Get the value and set the node
        	Node* find = map[key];
        	ret = find->val;
        	MoveToTop(find);
        }
        

        return ret;
    }
    
    void set(int key, int value) {
        if (map.size() > 0) {
        	// Looking for the node which has that key in the map
        	if (map.count(key) != 0) {
        		// Set the value and move the node to the top
        		Node* find = map[key];
        		find->val = value;
        		MoveToTop(find);
        	}
        	else {
        		Node *node = new Node(key, value);
        		InsertToTop(node);

        		// Check the size
        		if (map.size() == max_size) {
        			int k = bottom->key;
        			Node *second = bottom->next;
        			second->prev = NULL;
        			delete bottom;
        			bottom = second;
        			map.erase(k);
        		}
        		map[key] = node;
        	}
        }
        else {
        	// Init the cache stack and insert value
        	Node *node = new Node(key, value);
        	node->prev = NULL;
        	node->next = NULL;
        	top = node;
        	bottom = node;
        	map[key] = node;
        }
    }
    
private:
    int max_size;
    struct Node {
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int k, int v) {
        	key = k;
        	val = v;
        }
    };
    Node *top;
    Node *bottom;

    unordered_map<int, Node*> map;

    void MoveToTop(Node* x) {
        if (top == x)
            return;
    	
    	if (bottom == x) {
    	    bottom = bottom->next;
    	    bottom->prev = NULL;
    	}
    	else {
    	    // not top, not bottom
    		x->prev->next = x->next;
    		x->next->prev = x->prev;
    	}
    	
    	top->next = x;
    	x->prev = top;
    	x->next = NULL;
    	top = x;
    }
    
    void InsertToTop(Node* x) {
        x->prev = top;
        top->next = x;
        top = x;
    }
};