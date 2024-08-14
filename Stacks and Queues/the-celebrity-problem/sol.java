// import java.util.*;

class Solu 
{
    public int celebrity(int mat[][]) 
    {
        // code here
        int a = 0, b = mat.length - 1;
        
        while(a < b)
        {
            if(mat[a][b] == 1)
                a++;
            else
                b--;
        }
        
        for(int i = 0; i < mat.length; i++)
        {
            if((i != a) && (mat[a][i] == 1 || mat[i][a] == 0))
                return -1;
                
        }
        return a;
    }
}