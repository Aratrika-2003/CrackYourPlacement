import java.util.*;

class Solution
{
    // Function to return a list containing the DFS traversal of the graph.
    public static void dfsTree(int node,boolean[] visited,ArrayList<ArrayList<Integer>> adj,ArrayList<Integer> dfs)
    {
        visited[node] = true;
        dfs.add(node);
        
        for(int neighbor:adj.get(node))
        {
            if(!visited[neighbor])
                dfsTree(neighbor,visited,adj,dfs);
        }
    }
    public ArrayList<Integer> dfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) 
    {
        // Code here
        boolean[] visited = new boolean[V];
        ArrayList<Integer> dfs = new ArrayList<>();
        
        dfsTree(0, visited, adj, dfs);

        return dfs;
    }
}