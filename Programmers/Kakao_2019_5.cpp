#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Node {
	int id;
	int x, y;
	Node* left;
	Node* right;
};

bool cmp(const Node& a, const Node& b) {
	if (a.y == b.y)
		return a.x < b.x;
	else
		return a.y > b.y;
}

void addNode(Node* parent, Node* child) {
	if (child->x < parent->x) {
		if (parent->left == NULL)
			parent->left = child;
		else
			addNode(parent->left, child);
	}
	else {
		if (parent->right == NULL)
			parent->right = child;
		else
			addNode(parent->right, child);
	}
}

void preorder(const Node* node, vector<int>& ans) {
	if (node == NULL) return;
	ans.push_back(node->id);
	preorder(node->left, ans);
	preorder(node->right, ans);
}

void postorder(const Node* node, vector<int>& ans) {
	if (node == NULL) return;
	postorder(node->left, ans);
	postorder(node->right, ans);
	ans.push_back(node->id);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> ans;

	vector<Node> nodes;
	for (int i = 0, len = nodeinfo.size(); i < len; ++i) {
		nodes.push_back({ i + 1, nodeinfo[i][0], nodeinfo[i][1] });
	}
	sort(nodes.begin(), nodes.end(), cmp);

	Node* root = &nodes[0];
	for (int i = 1, len = nodes.size(); i < len; ++i) {
		addNode(root, &nodes[i]);
	}

	ans = { {}, {} };
	preorder(root, ans[0]);
	postorder(root, ans[0]);
}

int main() {
	vector<vector<int>> nodeinfo = {};
	vector<vector<int>> ans = solution(nodeinfo);

	return 0;
}