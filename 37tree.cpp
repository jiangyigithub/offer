#include "head.hpp"
 
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int node) : val(node), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)return "[null]";
        string ret= "[";
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            if(node!=nullptr){
                ret+=to_string(node->val);
                ret+=",";
                que.push(node->left);
                que.push(node->right);
            }
            else ret+="null,";
        }
        //delte last comma
        ret.pop_back();
        ret+="]";
        return ret;
    }
    
        //       1
        //      / \
        //     2   3
        //        / \
        //       4   5
       

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        vector<string> res = this->spilit(data,',');
        TreeNode* root = new TreeNode(stoi(res[0]));
        queue<TreeNode*> que;
        que.push(root);
        int i=0;
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();

            if(res[2*i+1]=="null"){
                node->left = nullptr;
            }
            else{
                node->left = new TreeNode(stoi(res[2*i+1]));
                que.push(node->left);
            }
            if(res[2*i+2]=="null"){
                node->right = nullptr;
            }
            else{
                node->right = new TreeNode(stoi(res[2*i+2]));
                que.push(node->right);
            }
            ++i;
        }
        return root;
    }
private:
    vector<string> spilit(string str,char sym){
        string str2=str.substr(1,str.size()-2);
        if(str.empty()) return{};
        vector<string> res;
        string::size_type beg=0;
        for(auto end=0;(end=str2.find(sym,end))!=string::npos;++end){
            res.push_back(str2.substr(beg,end-beg));
            beg=end+1;
        }
        return res;
    }


};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main() {
    string line = "[1,2,3,null,null,4,5]";
    TreeNode* root = stringToTreeNode(line);

    Codec codec;
    string ret = codec.serialize(root);
    cout << "serialize: "<<ret << endl;

    TreeNode* root2 = codec.deserialize(codec.serialize(root));
    string out = (ret);
    
    return 0;
}