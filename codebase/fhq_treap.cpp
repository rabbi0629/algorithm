#include<bits/stdc++.h>

const int INF = 100000000;

unsigned ran() {
	static int x = 23333;
	return x<<2|1;
}

struct Node *nill;

struct Node {
	Node *ch[2];
	int val;
	int pri;
	int sz;
	Node(int _val = 0, int _sz = 0): val(_val), sz(_sz) {
		ch[0] = ch[1] = nill;
		pri = ran();
	}

	void up() {
		if(this == nill) {
			return;
		}
		sz = ch[0]->sz + ch[1]->sz + 1;
	}
};

void split(Node *a, Node *&b, Node *&c, int cnt) {   //split操作会破坏原来的结构。
	if(a == nill) {
		b = c = nill;
	} else {
		if(a->val <= cnt) {
			b = a;
			split(a->ch[1], b->ch[1], c, cnt);
			b->up();
		} else {
			c = a;
			split(a->ch[0], b, c->ch[0], cnt);
			c->up();
		}
	}
}

Node *merge(Node *b, Node *c) {
	if(b == nill) {
		return c;
	} else if (c == nill) {
		return b;
	} else if(b->pri > c->pri) {
		b->ch[1] = merge(b->ch[1], c);
		b->up();
		return b;
	} else {
		c->ch[0] = merge(b, c->ch[0]);
		c->up();
		return c;
	}
}

Node pool[500100], *alloc;

void print(Node *root) {
	if(root->ch[0] != nill) {
		print(root->ch[0]);
	}
	if(root != nill) {
		std::cout << root->val << " ";
	}
	if(root->ch[1] != nill){
		print(root->ch[1]);
	}
}

void printTree(std::string prefix, Node *root) {
	std::cout << prefix << " ";
	print(root);
	std::cout << std::endl;
}

int find_Kth(Node * root, int k) {  //第K小数。
	while(1) {
		if(k <= root->ch[0]->sz) {
			root = root->ch[0];
		} else if (k == root->ch[0]->sz + 1) {
			return root->val;
		} else {
			root = root->ch[1];
			k -= root->ch[0]->sz + 1;
		}
	}
}

int find_pre(Node *root, int x) {
	Node *a, *b;
	split(root, a, b, x-1);
	root = merge(a, b);

	if(a == nill) {
		return -INF;
	}
	for(b = a; b ->ch[1] != nill; b = b->ch[1]); // 最大值。
	return b->val;
}

int find_succ(Node *root, int x) {
	Node *a, *b;
	split(root, a, b, x+1);
	root = merge(a, b);

	if (b == nill) {
		return INF;
	}
	for(a = b; a ->ch[0] != nill; a = a->ch[0]);  // 最小值。
	return a->val;
}

int get_rank(Node *root, int num) {
	std::cout <<"get_rank size(root): " << root->sz << std::endl;
	Node *x, *y;
	split(root, x, y, num);
	root = merge(x, y);

	printTree("rank_x", x);
	printTree("ran_y", y);
	std::cout << "sz(x) " << x->sz << " sz(y): " << y->sz << " sz(root): " << root->sz << std::endl;
	return x->sz;
}
/*

10
19 17 15 13 11 9 7 5 3 1

*/

int main() {
	//freopen("test.ini", "r", stdin);
	alloc = pool;
	nill = new(alloc++)Node(0, 0);
	nill->ch[0] = nill->ch[1] = nill;
	int n;
	std::cin >> n;

	Node* root = nill;

	for(int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;
		Node *b, *c;
		split(root, b, c, x);
		root = merge(b, merge(new(alloc++)Node(x, 1), c));
		std::cout << "lalala " << root->sz << std::endl;
	}

	std::cout << "wahaha " << root->sz << std::endl;


	printTree("root", root);

	std::cout << "Kth: " << find_Kth(root, 3) << std::endl;   //求K小数。

	Node *b, *c;
	split(root, b, c, 10);
	root = merge(b, merge(new(alloc++)Node(10, 1), c));   //插入10元素。
	printTree("root1", root);
	std::cout << "size(root): " << root->sz << std::endl;


	split(root, b, c, 10);
	root = merge(b, merge(new(alloc++)Node(10, 1), c));   //再次插入10元素。
	printTree("root2", root);
	std::cout << "size(root): " << root->sz << std::endl;


	split(root, b, c, 10);
	root = merge(b, merge(new(alloc++)Node(10, 1), c));   //第三次插入10元素。
	printTree("root3", root);
	std::cout << "size(root): " << root->sz << std::endl;

	Node *d, *e;       //删除一个10元素。
	split(root, b, c, 10);
	printTree("root4", b);
	printTree("root5", c);

	split(b, d, e, 9);
	printTree("root6", d);
	printTree("root7", e);

	b = merge(d, merge(e->ch[0], e->ch[1]));
	root = merge(b, c);
	printTree("root8", root);    // 最后删除一个10，只剩下两个10.  
	std::cout << "size(root): " << root->sz << std::endl;
	std::cout << find_pre(root, 11) << std::endl;  // 找11的前驱结点。
	std::cout << "size(root): " << root->sz << std::endl;
	std::cout << find_succ(root, 11) << std::endl; //找11的后继节点。

	std::cout << "size(root): " << root->sz << std::endl;

	c = root;
	std::cout << get_rank(c, 13) << std::endl;  //获得13的排名。
	std::cout << "size(root): " << root->sz << std::endl;

	return 0;
}
