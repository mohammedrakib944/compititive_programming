#include<iostream>
#include<stack>
#include<queue>
using namespace std;

typedef struct node Node;

struct node{
	int data;
	Node* left;
	Node* right;
};
Node* root = NULL;

void insert(int n){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = n;
	newNode->left = NULL;
	newNode->right = NULL;

	if(root == NULL){
		root = newNode;
	}else{
		Node* temp;
		temp = root;
		while(true){
			if(temp->data > n){
				//insert in left
				if(temp->left == NULL){
					cout << "Root = " << temp->data << " -> ";
					cout <<n<<" Insert in left " << endl;
					temp->left =  newNode;
					return;
				}else{
					temp = temp->left;
				}
			}else{
				//insert in right
				if(temp->right == NULL){
					cout << "Root = " << temp->data <<" -> ";
					cout <<n<< " Insert in Right "<< endl;
					temp->right = newNode;
					return;
				}else{
					temp = temp->right;
				}
			}
		}
	}
}
//answer start over here
//left tree
void leftSebtree(Node* leftNode, vector<int> &ans){
	if(!leftNode) return;
	if(leftNode->left){
		ans.push_back(leftNode->data);
		leftSebtree(leftNode->left,ans);
	}else if(leftNode->right){
		ans.push_back(leftNode->data);
		leftSebtree(leftNode->right,ans);
	}
}
//leaf tree
void leafNodes(Node *root, vector<int> &ans){
	if(!root)return;
	leafNodes(root->left, ans);
	if(!root->left && !root->right)ans.push_back(root->data);
	leafNodes(root->right, ans);
}
//right tree
void right(Node* root, vector<int> &ans){
	if(!root) return;
	if(root->right){
		right(root->right, ans);
		ans.push_back(root->data);
	}else if(root->left){
		right(root->left, ans);
		ans.push_back(root->data);
	}
}

//Boundary Traversal of a binary tree
vector<int> BoundaryTRaversal(Node *root){
	vector<int> ans;
	ans.push_back(root->data);
	leftSebtree(root->left, ans);
	leafNodes(root, ans);
	right(root->right, ans);

	return ans;
}

// 20 8 22 4 12 25 10 14
int main(){
	int n = 8;
	for(int i=0; i < n; i++){
		int x;
		cin >> x;
		insert(x);
	}

//	Boundary traversal of binary tree
	cout << "\nRoot is : -->> " << root->data << endl;
	Node* head = root;
	vector<int> BT;
	BT = BoundaryTRaversal(head);
	cout << "\nBoundary Traversal of binary tree: ";
	for(int i=0; i < BT.size(); i++){
		cout << BT[i] << " ";
	}

	cout << "\n\n";

return 0;
}
