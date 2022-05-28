struct Node{
    Node *links[26];    //an array containing pointers of similar node structures.
    bool flag=false;    //for now know that this only tells if string is completed or not
    //which then helps to tell if the trie is present or not, in the trie, yes.
    
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    
    //add new char to trie / create reference trie.
    void put(char ch, Node *node){
        links[ch-'a']=node; //put a new node corresp to new char's index.
    }
    //get next node while traversal.
    Node *get(char ch){
        return links[ch-'a'];   //actually gives the ptr array's element where next is supposed to be, thus ultimately giving next
    }
    //set end true when the word is completed.
    void setEnd(){
        flag=true;
    }
    //check if word is finished.
    bool isEnd(){
        return flag;
    }
    
};
class Trie {
private:
    Node* root;
public:
    
    Trie() {
        //create new object
        root = new Node();
    }
    
	void insert(string word) {
		//initializing dummy node pointing to root initially
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containsKey(word[i])) {
				node->put(word[i], new Node());
			}
			//moves to reference trie
			node = node->get(word[i]);
		}
		node->setEnd();
	}

	bool search(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containsKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->isEnd();
	}

	bool startsWith(string prefix) {
		Node* node = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containsKey(prefix[i])) {
				return false;
			}
			node = node->get(prefix[i]);
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
