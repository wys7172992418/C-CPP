#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

const int MAX = 10;

struct BiTree {
	char data;
	struct BiTree* left, * right;
};

//创建二叉树，以#结束
void CreatBiTree(BiTree*& T) {
	char ch;
	ch = getchar();
	if (ch == '#')T = nullptr;
	else {
		T = new BiTree;
		T->data = ch;
		CreatBiTree(T->left);
		CreatBiTree(T->right);
	}
}

//先序遍历二叉树,先序遍历就是:根->左子树->右子树
void PreOrderTraverse(BiTree*& T) {
	if (T) {
		cout << T->data << " ";
		PreOrderTraverse(T->left);
		PreOrderTraverse(T->right);
	}
	else {
		cout << "";
	}
}

//中序遍历二叉树,中序遍历就是:左子树->根->右子树
void InoderTraverse(BiTree*& T) {
	if (T) {
		InoderTraverse(T->left);
		cout << T->data<<" ";
		InoderTraverse(T->right);
	}
	else {
		cout << "";
	}
}

//后序遍历二叉树,后续遍历就是:左子树->右子树->根
void PosoderTraverse(BiTree*& T) {
	if (T) {
		PosoderTraverse(T->left);
		PosoderTraverse(T->right);
		cout << T->data << " ";
	}
	else {
		cout << "";
	}
}

void LevleOrder(BiTree* T) {
	BiTree* Queue[MAX], *b;
	int front, rear;
	front = rear = 0;
	if (T) {
		Queue[rear++] = T;
		while (front != rear) {
			b = Queue[front++];
			cout << b->data << " ";
			if (b->left != nullptr)Queue[rear++] = b->left;
			if (b->right != nullptr)Queue[rear++] = b->right;
		}
	}
}

//求二叉树的深度:递归解决,先遍历左子树,再遍历右子树,大的+1
int BiTreeDepth(BiTree* T) {
	if (T == nullptr)
		return 0;
	int left, right;
	left = BiTreeDepth(T->left);
	right = BiTreeDepth(T->right);
	return left > right ? left + 1 : right + 1;
}

/*判断二叉树是否为平衡二叉树,平衡二叉树应满足以下三个条件:
1.左子树是平衡二叉树
2.右子树是平衡二叉树
3.左右子树之间的深度不超过1
*/
/*int countFloor(BiTree* T) {
	if (!T)
		return 0;
	int left, right;
	left = countFloor(T->left);
	right = countFloor(T->right);
	return left > right ? left + 1 : right + 1;
}//注意到这个函数跟求二叉树深度的函数一样,即可省略.*/

bool IsBalanced(BiTree* T) {
	if (!T)
		return true;
	if (abs(BiTreeDepth(T->left) - BiTreeDepth(T->right)) > 1) {
		return false;
	}//判断左子树与右子树的高度差
	else {
		if (IsBalanced(T->left) && IsBalanced(T->right)) {
			return true;
		}
		else {
			return false;
		}
	}//判断左子树与右子树是不是平衡二叉树
}

/*判断二叉树是不是对称二叉树
列如:[1,2,2,3,4,4,3](层次遍历)就是对称二叉树,
从根节点开始递归,判断左子树是不是等于右子树.
*/
bool IsMirror(BiTree* q,BiTree*	p) {
	if (q==nullptr&&p==nullptr)
		return true;//左右子树为空
	if (q == nullptr || p == nullptr)
		return false;//左右子树高度不等
	if (q->data == p->data) {
		return IsMirror(q->left, p->right) && IsMirror(q->right, p->left);
	}//递归判断节点值是否相等
	return false;
}

bool IsSymmetric(BiTree* T) {
	return IsMirror(T, T);
}

//二叉树的最小深度
int MinDepth(BiTree* T) {
	if (T == nullptr)
		return 0;
	int left, right;
	left = MinDepth(T->left);
	right = MinDepth(T->right);
	if (left > 0 && right > 0)
		return left > right ? right + 1 : left + 1;//如果左右子树都不为空,这样子做是可以的.
	return left = 0 ? right + 1 : left + 1;//如果左右子树有"空树",比如[1,2],[1,null,2,null,null,3,4](层次遍历)
}

//翻转二叉树
struct BiTree* invertTree(BiTree* T) {
	if (T == nullptr)
		return T;
	struct BiTree* p;
	p = T->left;
	T->left = invertTree(T->right);
	T->right = invertTree(p);
	return T;
}

void BiTreeCopy(BiTree* T, BiTree*& NewT) {
	if (T == nullptr) {
		NewT = nullptr;
		return;
	}
	else {
		NewT = new BiTree;
		NewT->data = T->data;
		BiTreeCopy(T->left, NewT->left);
		BiTreeCopy(T->right, NewT->right);
	}
}

/*合并二叉树
大概意思是，给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。
你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，
否则不为 NULL 的节点将直接作为新二叉树的节点。
比如:二叉树[1,3,2,5,null,null,null],[2,1,3,null,4,null,7](层次遍历)
合并后为[3,4,5,5,4,null,7]
*/
struct BiTree* mergeTrees(BiTree* t1,BiTree* t2) {
	if (t1 == nullptr)
		return t2;
	if (t2 == nullptr)
		return t1;
	t1->data = t1->data + t2->data;
	t1->left = mergeTrees(t1->left, t2->left);
	t1->right = mergeTrees(t1->right, t2->right);
	return t1;
}

int NodeCount(BiTree* T) {
	if (T == nullptr) {
		return 0;
	}
	return NodeCount(T->left) + NodeCount(T->right) + 1;
}

int main() {
	struct BiTree* T,*NewT=nullptr;//*t1,*t2;
	CreatBiTree(T);
	/*CreatBiTree(t1);
	CreatBiTree(t2);
	mergeTrees(t1, t2);
	cout << "\n合并的二叉树为(层次遍历）：" << endl;
	LevleOrder(t1);*/
	cout << "\n创建二叉树成功！" << endl;
	cout << "先序遍历为：" << endl;
	PreOrderTraverse(T);
	cout << "\n中序遍历为：" << endl;
	InoderTraverse(T);
	cout << "\n后序遍历为：" << endl;
	PosoderTraverse(T);
	cout << "\n层次遍历为：" << endl;
	LevleOrder(T);
	cout << "\n二叉树深度为：" << BiTreeDepth(T) << endl;
	if (IsBalanced(T)) {
		cout << "BiTree is Banlanced Tree !" << endl;
	}
	else {
		cout << "BiTree is't Banlanced Tree !" << endl;
	}
	if (IsSymmetric(T)) {
		cout << "BiTree is Symmetric Tree !" << endl;
	}
	else {
		cout << "BiTree is't Symmetric Tree !" << endl;
	}
	cout << "二叉树最小深度为："<< MinDepth(T) << endl;
	invertTree(T);
	cout << "翻转的二叉树为(层次遍历）：" << endl;
	LevleOrder(T);
	BiTreeCopy(T, NewT);
	cout << "\n复制的二叉树为(层次遍历）：" << endl;
	LevleOrder(NewT);
	cout << "二叉树的根节点个数为：" << NodeCount(T) << endl;
	cout << endl;
	cin.get();
	return 0;
}