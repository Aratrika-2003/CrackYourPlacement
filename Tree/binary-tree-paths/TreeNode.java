import java.util.*;


//Definition for a binary tree node.
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;    
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) 
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution 
{
    private void dfs(TreeNode root,String path,List<String> pathToleaf)
    {
        // if(root == null)
        //     return;
        
        if(root.left == null && root.right == null)
            pathToleaf.add(path + root.val);
        
        if(root.left != null)
            dfs(root.left,path + root.val + "->",pathToleaf);
        
        if(root.right != null)
            dfs(root.right,path + root.val + "->",pathToleaf);
    }

    public List<String> binaryTreePaths(TreeNode root) 
    {
        List<String> pathToleaf = new ArrayList<>();

        if(root != null)
            dfs(root,"",pathToleaf);
        
        return pathToleaf;
    }
}