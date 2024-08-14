import java.util.*;

class Solution {
    // Function to return Breadth First Traversal of given graph.
    public ArrayList<Integer> bfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) 
    {
        // Code here
        ArrayList<Integer> bfs = new ArrayList<>();
        
        boolean[] visited = new boolean[V];
        
        Queue<Integer> queue = new LinkedList<>();

        queue.add(0);
        visited[0] = true;

        while (!queue.isEmpty()) 
        {
            int node = queue.poll();
            bfs.add(node);

            // Traverse all the adjacent vertices of the dequeued node
            for (int neighbor : adj.get(node)) 
            {
                if (!visited[neighbor]) 
                {
                    queue.add(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        return bfs;
    }
}