///* 1330~1440
//
//	Ǯ��:
//	Ʈ���� ����
//	���� depth�� ���� ��尪�� ���°��� ã���� �� ���ϴ�.
//	���� Ʈ���� ������ ��, depth������ �߰����ְ�,
//	���� �ٸ� depth��� ���� depth�� ��尡 ������������ �̵��� �� ��,
//	���ÿ� �θ���� ������ �ϸ� �� ���ϴ�.
//	������ �ִ� 10000�� �ε�, �־��� �� ������ �θ��ڽ� ���踦 ���� �ʴ´ٰ� ������
//	�����Ѱ� ��Ʈ �Ѱ� ������ 10000-2�� �� ��찡 �ִ��ε�,
//	�׷����� 10000�� �����̴�.
//	����� �� �ϴ�. (���� Ʈ���� ����� ������ ������, �������� �ð����⵵�� ����� �� �ϴ�.)
//
//	�߿�ܼ�, ��ü Ʈ������ ��Ʈ�� �Ǵ� ������ �׻� 1������ ǥ��ȴ�.
//
//	�׷���, ������ �θ� - �ڽļ����� �شٴ� �ܼ��� ������,
//	����� ������� �شٴ� ���� ����.
//	����, �ϴ� ���� ���谪�� ������
//	���̸� ������ Ʈ���� ��������� �Ѵ�.
//*/
//#include <iostream>
//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//struct node {
//	int left;
//	int right;
//	int depth;
//	int parent;
//	node(int l = -1, int r = -1, int d = -1, int p = -1) :left(l), right(r), depth(d), parent(p) {}
//};
//
//int N, E, V1, V2;
//vector<int> connect[10001];
//node tree[10001];
//void input(); // �Է� �� �׷��� ����, (�� �׷����� ������踦 ��� �ִ�.)
//void make_tree(int num, int depth);
//int findSameParent(int n1, int n2);
//int bfsSubTreeSize(int rn);
//void reset();
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 1; t <= T; t++)
//	{
//		input();
//
//		make_tree(1, 1); // ��Ʈ���� 1�̴ϱ�, ���� 1���� ����
//
//		int rootNode = findSameParent(V1, V2);
//		int subTreeSize = bfsSubTreeSize(rootNode);
//
//		cout << "#" << t << " " << rootNode << " " << subTreeSize << endl;
//
//		reset();
//	}
//
//}
//
//void input()
//{
//	cin >> N >> E >> V1 >> V2;
//
//	int parent;
//	int child;
//	for (int i = 0; i < E; i++)
//	{
//		cin >> parent >> child;
//		connect[parent].push_back(child);
//	}
//
//}
//
//void make_tree(int num, int depth)
//{
//	tree[num].depth = depth;
//
//	for (int j = 0; j < connect[num].size(); j++) // i�� ������ �ֵ�,
//	{
//		if (tree[num].left == -1)
//		{
//			tree[num].left = connect[num][j];
//			tree[tree[num].left].parent = num;
//			make_tree(tree[num].left, depth + 1);
//		}
//		else if (tree[num].right == -1)
//		{
//			tree[num].right = connect[num][j];
//			tree[tree[num].right].parent = num;
//			make_tree(tree[num].right, depth + 1);
//		}
//	}
//}
//
//int findSameParent(int n1, int n2)
//{
//	if (tree[n1].depth == tree[n2].depth)
//	{	
//		if (n1 == n2)
//			return n1;
//		else
//		{
//			return findSameParent(tree[n1].parent, tree[n2].parent);
//		}	
//	}
//	else if (tree[n1].depth > tree[n2].depth)
//	{
//		return findSameParent(tree[n1].parent, n2);
//	}
//	else
//	{
//		return findSameParent(n1, tree[n2].parent);
//	}
//
//	return 0;
//}
//
//int bfsSubTreeSize(int rn)
//{
//	int answer = 0;
//	queue<int> que;
//	que.push(rn);
//
//	while (!que.empty())
//	{
//		int cur = que.front();
//		que.pop();
//		answer++;
//
//		if (tree[cur].left != -1)
//			que.push(tree[cur].left);
//
//		if (tree[cur].right != -1)
//			que.push(tree[cur].right);
//	}
//
//	return answer;
//}
//
//void reset()
//{
//	for (int i = 0; i <= N; i++)
//	{
//		connect[i].clear();
//		tree[i].left = -1;
//		tree[i].right = -1;
//		tree[i].parent = -1;
//		tree[i].depth = -1;
//	}
//}
