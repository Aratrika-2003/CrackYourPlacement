import java.util.*;

class Solution {
    private class BinaryIndexedTree
    {
        final private int[] tree;

        public BinaryIndexedTree(int n)
        {
            tree = new int[n + 1];
        }

        public void update(int index,int delta)
        {
            while(index < tree.length)
            {
                tree[index] += delta;
                index += index & -index;
            }
        }

        public int query(int index)
        {
            int sum = 0;

            while(index > 0)
            {
                sum += tree[index];
                index -= index & -index;
            }
            return sum;
        }
    }
    public List<Integer> countSmaller(int[] nums) 
    {
        List<Integer> temp = new ArrayList<>();
        List<Integer> counts = new ArrayList<>();
        //int count = 0;

        for(int num:nums)
            temp.add(num);
        
        Collections.sort(temp);

        BinaryIndexedTree BIT = new BinaryIndexedTree(temp.size());

        for(int i = nums.length - 1; i >= 0; i--)
        {
            int index = Collections.binarySearch(temp,nums[i]);
            counts.add(BIT.query(index));
            BIT.update(index + 1, 1);
        }
        Collections.reverse(counts);

        return counts;
    }
}