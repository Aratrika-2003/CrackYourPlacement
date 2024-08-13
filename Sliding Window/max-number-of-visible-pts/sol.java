import java.util.*;

class Solution 
{
    public int visiblePoints(List<List<Integer>> points,int angle,List<Integer> location) 
    {
        int locnCount = 0;
        List<Double> angles = new ArrayList<>();

        int posX = location.get(0),posY = location.get(1);

        for(List<Integer> pt:points)
        {
            int x = pt.get(0),y = pt.get(1);

            if(x == posX && y == posY)
                locnCount++;
            
            else
            {
                double angleTopt = Math.atan2(y - posY,x - posX) * (180 / Math.PI);
                angles.add(angleTopt);
            }
        }
        Collections.sort(angles);

        int size = angles.size();

        for (int i = 0; i < size; i++) 
            angles.add(angles.get(i) + 360);

        int maxCount = 0,left = 0;

        for (int right = 0; right < angles.size(); right++) 
        {
            while (angles.get(right) - angles.get(left) > angle) 
                left++;

            maxCount = Math.max(maxCount,right - left + 1);
        }

        return maxCount + locnCount;
    }
}