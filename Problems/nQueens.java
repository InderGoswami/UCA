class Solution {
    public static boolean isSafe(char chessBoard[][],int row,int col){
        //upwards
        for(int i=0;i<row;i++){
            if(chessBoard[i][col]=='Q'){
                return false;
            }
        }
        //left diag
        int i=row-1;
        int j=col-1;
        while(i>=0 && j>=0){
            
            if(chessBoard[i][j]=='Q'){
                return false;
            }
            --i;
            --j;
        }
         //right diag
        i=row-1;
         j=col+1;
        while(i>=0 && j<chessBoard.length){
           
            if(chessBoard[i][j]=='Q'){
                return false;
            }
             --i;
            ++j;
        }
        return true;
    }
    public static void Nqueens(List<List<String>> ans,char chessBoard[][],int row){
        if(row==chessBoard.length){
            List<String>temp=new ArrayList<>();
            for(int i=0;i<chessBoard.length;i++){
                 StringBuilder sb=new StringBuilder("");
                for(int j=0;j<chessBoard.length;j++){
                    sb.append(chessBoard[i][j]);

                }
                temp.add(sb.toString());

            }
            ans.add(temp);
            return;
        }
        for(int i=0;i<chessBoard.length;i++){
            if(isSafe(chessBoard,row,i)){
                chessBoard[row][i]='Q';
                Nqueens(ans,chessBoard,row+1);
                chessBoard[row][i]='.';
            }
        }
    }
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans=new ArrayList<>();
        char chessBoard[][]=new char[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                chessBoard[i][j]='.';
            }
        }
        
        Nqueens(ans,chessBoard,0);
        return ans;
        
    }
}
