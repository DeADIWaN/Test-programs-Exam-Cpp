#define SIZE 7

using namespace std;

class Hash {
	struct List {
		struct Node {
			int value;
			Node *next;
			Node(int val) {
				value = val;
				next = nullptr;
			}
			Node(const Node &node) {
				value = node.value;
				next = node.next ? new Node(*node.next) : nullptr;
			}
			~Node() {
				if (next)
					delete next;
			}
			Node& operator=(const Node &node) {
				value = node.value;
				if (next)
					delete next;
				next = node.next ? new Node(*node.next) : nullptr;
				return *this;
			}
		}; //struct Node

		Node *head;
		List() {
			head = nullptr;
		}
		List(int val) {
			head = new Node(val);
		}
		List(const List &list) {
			head = list.head ? new Node(*list.head) : nullptr;
		}
		~List() {
			if (head)
				delete head;
		}
		void add(int val) {
			Node *temp = new Node(val);
			temp->next = head;
			head = temp;
		}
		List& operator=(const List &list) {
			if (head && list.head)
				*head = *list.head;
			else if (!head && list.head)
				head = new Node(*list.head);
			else if (head && !list.head)
				delete head;
			return *this;
		}
		void clear() {
			if (head) {
				delete head;
				head = nullptr;
			}
		}
		bool search(int val) {
			Node *temp = head;
			if (!temp)
				return false;
			else {
				while (temp->next) {
					if (temp->value == val)
						return true;
					else
						temp = temp->next;
				} //while
				return false;
			}
		}
	}; //struct List

	List Table[SIZE];
public:
	Hash() {
		for (int i = 0; i < SIZE; i++) {
			Table[i].head = nullptr;
		}
	};
	Hash(const Hash &hash) {
		for (int i = 0; i < SIZE; i++) {
			Table[i] = hash.Table[i];
		}
	}
	~Hash() {
		for (int i = 0; i < SIZE; i++) {
			Table[i].clear();
		}
	}
	Hash& operator=(const Hash &hash) {
		for (int i = 0; i < SIZE; i++) {
			Table[i] = hash.Table[i];
		}
	}
	void add(int val) {
		int KEY = val % SIZE;
		Table[KEY].add(val);
	}
	void clear() {
		for (int i = 0; i < SIZE; i++) {
			Table[i].clear();
		}
	}
	bool search(int val) {
		int KEY = val % SIZE;
		return Table[KEY].search(val);
	}
};