import java.util.*;

class Solution {
    // Function to detect cycle in an undirected graph.
    private boolean dfs(int v,boolean[] vis,int p,ArrayList<ArrayList<Integer>> adj)
    {
        vis[v] = true;
        
        for(int neighbor:adj.get(v))
        {
            if (!vis[neighbor]) 
            {
                // Recur to visit the neighbor
                if (dfs(neighbor, vis, v, adj))
                    return true;
            } 
            else if (neighbor != p) 
            {
                // If an adjacent vertex is visited and it's not the parent of the current vertex, then there is a cycle
                return true;
            }
        }
        return false;
    }
    
    public boolean isCycle(int V, ArrayList<ArrayList<Integer>> adj) 
    {
        // Code here
        boolean[] visited = new boolean[V];
        
        // Check for cycle in different DFS trees
        for (int i = 0; i < V; i++) 
        {
            if (!visited[i]) 
            { // If not visited, start a DFS from that node
                if (dfs(i, visited, -1, adj)) 
                    return true;
            }
        }
        
        return false;
    }
}