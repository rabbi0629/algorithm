#include<bits/stdc++.h>

/*
 * 给出总长度不超过1E+5的不重复字符串集，给每个字符串选一个前缀使得可以区分它。
 * 构造trie, 从下向上处理，平衡树启发式合并
 *
 */

struct Node {
	Node *ch[26];
	bool end;
	Node() {
		for(int i = 0; i < 26; i++) {
			ch[i] = NULL;
		}
		end = false;
	}
};

Node *root;

void add(char *str) {
	Node *cur = root;
	int len = strlen(str);
	for(int i = 0; i < len; i++) {
		if (cur->ch[str[i] - 'a'] == NULL) {
			cur->ch[str[i] - 'a'] = new Node();
		}
		cur = cur->ch[str[i] - 'a'];
	}
	cur->end = true;
}

char str[100100];

using ps = std::multiset<int>*;

ps merge(ps a, ps b) {
	if(a->size() > b->size()) std::swap(a, b);
	for(auto it : *a) {
		b->insert(it);
	}
	delete a;
	return b;
}

ps calc(Node *cur, int depth) {
	ps ans = new std::multiset<int>;
	for(int i = 0; i < 26; i++) if(cur->ch[i]) {
		auto t = calc(cur->ch[i], depth+1);
		ans = merge(ans, t);
	}
	if(cur->end) {
		ans->insert(depth);
	} else if(depth != 0) {
		ans->erase(prev(ans->end()));
		ans->insert(depth);
	}
	return ans;
}

int main()
{
	root = new Node();
	int n;
	while(std::cin >> n) {
		for(int i = 0; i < n; i++) {
			std::cin >> str;
			add(str);
		}

		auto ans = calc(root, 0);
		int cnt = 0;
		for(auto s : *ans) {
			cnt += s;
		}
		std::cout << cnt << std::endl;
	}
	return 0;
}
