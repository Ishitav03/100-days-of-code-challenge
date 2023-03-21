// 1472. Design Browser History
// You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

// Implement the BrowserHistory class:

// BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
// void visit(string url) Visits url from the current page. It clears up all the forward history.
// string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
// string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.
 
  
//   Constraints:

// 1 <= homepage.length <= 20
// 1 <= url.length <= 20
// 1 <= steps <= 100
// homepage and url consist of  '.' or lower case English letters.
// At most 5000 calls will be made to visit, back, and forward.


struct Node { 
    Node* prev = nullptr;
    Node* next = nullptr;
    const string url;
    Node(const string& url) : url(url) {}
};

class BrowserHistory {
    public:
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }

    void visit(string url) {
        curr->next = new Node(url);
        curr->next->prev = curr;
        curr = curr->next;
    }

    string back(int steps) {
        while (curr->prev && steps-- > 0) curr = curr->prev;
        return curr->url;
    }
    
    string forward(int steps) {
        while (curr->next && steps-- > 0) curr = curr->next;
        return curr->url;
    }

    private:
        Node* curr = nullptr;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
