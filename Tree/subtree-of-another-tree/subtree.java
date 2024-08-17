
public class subtree 
{
    int val;
    subtree left;
    subtree right;
    subtree() {}
    subtree(int val) { this.val = val; }
    subtree(int val, subtree left, subtree right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution 
{
    private boolean isSame(subtree t1,subtree t2)
    {
        if(t1 == null && t2 == null)
            return true;
        
        if(t1 == null || t2 == null)
            return false;
        
        return (t1.val == t2.val) && isSame(t1.left,t2.left) && isSame(t1.right,t2.right);
    }
    public boolean isSubtree(subtree root, subtree subRoot) 
    {
        if(root == null)
            return false;
        
        if(isSame(root,subRoot))
            return true;
        
        return isSubtree(root.left,subRoot) || isSubtree(root.right,subRoot);
    }
}