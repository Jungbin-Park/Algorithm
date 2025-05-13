#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 노드 정의
struct Node
{
    int id, x, y;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int _id, int _x, int _y)
        : id(_id)
        , x(_x)
        , y(_y)
    {}
};

// 이진 트리 정의
class BinaryTree
{
private:
    Node* root = nullptr;

private:
    // y가 큰 노드가 앞에, y가 같으면 x가 작은 노드가 앞에 오도록
    static bool CompareNodes(Node* a, Node* b)
    {
        if (a->y != b->y) return a->y > b->y;

        return a->x < b->x;
    }

    Node* AddNode(Node* current, Node* newNode)
    {
        // 노드가 비어있으면 바로 넣기
        if (current == nullptr) return newNode;

        if (newNode->x < current->x)
            current->left = AddNode(current->left, newNode);
        else
            current->right = AddNode(current->right, newNode);

        return current;
    }

private:
    // 전위 순회
    void PreOrder(Node* node, vector<int>& path)
    {
        if (node == nullptr) return;

        // 부모 -> 왼쪽 -> 오른쪽
        path.push_back(node->id);
        PreOrder(node->left, path);
        PreOrder(node->right, path);
    }

    // 후위 순회
    void PostOrder(Node* node, vector<int>& path)
    {
        if (node == nullptr) return;

        // 왼쪽 -> 오른쪽 -> 부모
        PostOrder(node->left, path);
        PostOrder(node->right, path);
        path.push_back(node->id);
    }


public:
    void BuildTree(const vector<vector<int>>& nodeinfo)
    {
        vector<Node*> nodes;

        for (int i = 0; i < nodeinfo.size(); ++i)
        {
            // 노드의 고유 숫자 = i + 1
            nodes.push_back(new Node(i + 1, nodeinfo[i][0], nodeinfo[i][1]));
        }

        // 노드 정렬
        sort(nodes.begin(), nodes.end(), CompareNodes);

        // 이진 트리 구축
        for (Node* node : nodes)
        {
            root = AddNode(root, node);
        }
    }

public:
    vector<int> GetPreOrderPath()
    {
        vector<int> path;
        PreOrder(root, path);
        return path;
    }

    vector<int> GetPostOrderPath()
    {
        vector<int> path;
        PostOrder(root, path);
        return path;
    }


public:
    BinaryTree()
        : root(nullptr)
    {}
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer;

    BinaryTree tree;

    tree.BuildTree(nodeinfo);
    vector<int> pre = tree.GetPreOrderPath();
    vector<int> post = tree.GetPostOrderPath();
    
    return { pre, post };
}