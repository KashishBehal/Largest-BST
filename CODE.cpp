class Solution{
    public:
     bool checkBST(Node *root,int lmax,int rmin){
        if(!root) return 1;
        bool curr=(root->data>lmax && root->data<rmin);
        bool lst=checkBST(root->left,lmax,root->data);
        bool rst=checkBST(root->right,root->data,rmin);
        return (curr && lst && rst);
    }
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
    	 if(!root) return 0;
        if(checkBST(root,INT_MIN,INT_MAX)){
            return 1+largestBst(root->left)+largestBst(root->right);
        }
        else{
            return max(largestBst(root->left),largestBst(root->right));
        }
    }
};
