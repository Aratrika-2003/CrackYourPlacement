import java.util.*;

class Solution 
{
    class SegmentTree 
    {
        private final int[] tree;
        private final int size;

        public SegmentTree(int size) 
        {
            this.size = size;
            tree = new int[size * 2];
        }

        public void update(int index, int value) 
        {
            index += size;

            while (index > 0) 
            {
                tree[index] += value;
                index /= 2;
            }
        }

        public int query(int left, int right) 
        {
            left += size;
            right += size + 1;

            int sum = 0;

            while (left < right) 
            {
                if ((left & 1) == 1) 
                    sum += tree[left++];

                if ((right & 1) == 1) 
                    sum += tree[--right];

                left /= 2;
                right /= 2;
            }
            return sum;
        }
    }
    public int countRangeSum(int[] nums, int lower, int upper) 
    {
        if (nums.length == 0) 
            return 0;

        long[] prefixSums = new long[nums.length + 1];

        for (int i = 0; i < nums.length; i++) 
            prefixSums[i + 1] = prefixSums[i] + nums[i];

        Set<Long> set = new HashSet<>();

        for (long sum : prefixSums) 
        {
            set.add(sum);
            set.add(sum - lower);
            set.add(sum - upper);
        }

        List<Long> sortedList = new ArrayList<>(set);
        Collections.sort(sortedList);

        Map<Long, Integer> map = new HashMap<>();

        for (int i = 0; i < sortedList.size(); i++) 
            map.put(sortedList.get(i), i);

        SegmentTree segmentTree = new SegmentTree(sortedList.size());
        int count = 0;

        for (long sum : prefixSums) 
        {
            int left = map.get(sum - upper);
            int right = map.get(sum - lower);

            count += segmentTree.query(left, right);
            
            segmentTree.update(map.get(sum), 1);
        }

        return count;
    }
}