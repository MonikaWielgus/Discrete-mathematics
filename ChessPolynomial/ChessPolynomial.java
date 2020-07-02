package chesspolynomial;

/**
 *
 * @author Monika Wielgus
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ChessPolynomial{
    public static void main(String[] args) throws FileNotFoundException {
        ChessPolynomial.chessPolynomial("x.txt");
        
        char [][]array=new char[][]{{'O','X','O','X','O','O','O'},
                                      {'X','O','O','O','X','X','O'},
                                      {'O','O','O','O','O','O','O'},
                                      {'X','O','O','X','O','X','O'},
                                      {'O','O','X','X','X','O','O'},
                                      {'X','O','O','O','O','X','X'},
                                      {'O','O','O','O','X','X','X'}};
        System.out.println();
        for(int i=0; i<7; i++){
            for(int j=0; j<7; j++){
                System.out.print(array[i][j]);
            }
            System.out.println();
        }        
       
    }
    
    public static void chessPolynomial(String name) throws FileNotFoundException{
        Scanner in = new Scanner(new File(name));
        int rows=in.nextInt();
        int columns=in.nextInt();
        int [][]arr=new int[rows][columns];
        String temp;
        char ctemp;
        for(int i=0; i<rows; i++){
            temp=in.next();
            for(int j=0; j<columns; j++){
                ctemp=temp.charAt(j);
                if(ctemp=='O'||ctemp=='0')
                    arr[i][j]=0;
                else 
                    arr[i][j]=1;
            }
        }
        
        //we have our chessboard
        int n;
        if(rows>columns)
            n=columns+1;
        else
            n=rows+1;
        
        int t[]=new int[n];
        
        for(int i=0; i<n; i++)
            t[i]=0;

        t=chessPolynomial(arr,t);
        for(int i=0; i<t.length; i++)
            System.out.println("x^"+i+"="+t[i]);

    }
    public static int[] chessPolynomial(int[][]array, int[]coefficients){

        if(isFull(array)==true){
            coefficients[0]+=1;
            return coefficients;                       
        }
        if(isOneFree(array)==true){
            coefficients[1]+=1;
            coefficients[0]+=1;
            return coefficients;                   
        }
        int [][]copy=new int[array.length][array[0].length];
        for(int k=0; k<array.length; k++)
            for(int l=0; l<array[0].length; l++)
                copy[k][l]=array[k][l];
        
        int i=0;
        int j=0;
        outer:
        for(i=0; i<array.length; i++){//left side
            for(j=0; j<array[0].length; j++){
                if(array[i][j]==0){
                    array[i][j]=1;
                    break outer;
                }
            }
        }
        for(int w=0; w<copy.length; w++){//right side
            for(int z=0; z<copy[0].length; z++){
                if(w==i)
                    copy[w][z]=1;
                if(z==j)
                    copy[w][z]=1;                         
            }
        }
        
        int []coefficients1= chessPolynomial(array, new int[coefficients.length]);
        int []coefficients2=chessPolynomial(copy, new int[coefficients.length]);

        for(int h=1; h<coefficients.length; h++)
            coefficients[h]=coefficients1[h]+coefficients2[h-1];
        coefficients[0]=coefficients2[0];
        return coefficients;      
    }
    
    public static boolean isFull(int[][]array){
        for(int i=0; i<array.length; i++)
            for(int j=0; j<array[0].length; j++){
                if(array[i][j]==0)
                    return false;
            }
        return true;
    }
    
    public static boolean isOneFree(int[][]array){
        boolean yes=false;
        for(int i=0; i<array.length; i++){
            for(int j=0; j<array[0].length; j++){
                if(array[i][j]==0&&yes==true)
                    return false;
                else if(array[i][j]==0&&yes==false);
                    yes=true;
            }
        }
        return true;
    }   
}
