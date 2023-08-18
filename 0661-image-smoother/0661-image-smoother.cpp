class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

        int r=img.size();
        int c=img[0].size();
        vector<vector<int>> sol(r,vector<int> (c,0));


        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){

                if(i-1<0 and j-1<0 and i+1>=r and j+1>=c){

                    sol[i][j]=img[i][j];
                }  //for matrix of type [[0]]

                else if(i-1<0 and i+1>=r and j-1<0){
                    sol[i][j]=(img[i][j]+img[i][j+1])/2;
                } //for matrix of type [[0,1]]

                
                else if(i-1<0 and i+1>=r and j+1>=c){
                    sol[i][j]=(img[i][j]+img[i][j-1])/2;
                } //for matrix of type [[1,0]]

                else if(j-1<0 and j+1>=c and i-1<0){
                    sol[i][j]=(img[i][j]+img[i+1][j])/2;
                } //for matrix of type [[0],[1]]
      
                else if(j-1<0 and j+1>=c and i+1>=r){
                    sol[i][j]=(img[i][j]+img[i-1][j])/2;
                } //for matrix of type [[1],[0]]
                
                else if(i-1<0 and i+1>=r){
                    sol[i][j]=(img[i][j]+img[i][j-1]+img[i][j+1])/3;
                } //for matrix of type [[1,0,1]]

                else if(j-1<0 and j+1>=c){
                    sol[i][j]=(img[i][j]+img[i-1][j]+img[i+1][j])/3;
                } //for matrix of type [[1],[0],[1]]

                else if(i-1<0 and j-1<0){
                    
                    sol[i][j]=(img[i][j]+img[i][j+1]+img[i+1][j]+img[i+1][j+1])/4;
                } //for matrix of type [[0,1],[1,1]]

                else if(i+1>=r and j+1>=c){

                    sol[i][j]=(img[i][j]+img[i][j-1]+img[i-1][j]+img[i-1][j-1])/4;

                } //for matrix of type [[1,1],[1,0]]
                else if(i+1>=r and j-1<0 ){

                    sol[i][j]=(img[i][j]+img[i-1][j]+img[i][j+1]+img[i-1][j+1])/4;

                } //for matrix of type [[1,1],[0,1]]
                else if(i-1<0 and j+1>=c ){

                    sol[i][j]=(img[i][j]+img[i][j-1]+img[i+1][j-1]+img[i+1][j])/4;
                    
                } //for matrix of type [[1,0],[1,1]]
                else if(i-1<0){

                    sol[i][j]=(img[i][j]+img[i][j-1]+img[i][j+1]+img[i+1][j-1]+img[i+1][j]+img[i+1][j+1])/6;

                } //for matrix of type [[1,0,1],[1,1,1]]
                else if(i+1>=r){

                    sol[i][j]=(img[i][j]+img[i][j+1]+img[i][j-1]+img[i-1][j+1]+img[i-1][j]+img[i-1][j-1])/6;
                    
                } //for matrix of type [[1,1,1],[1,0,1]]

                else if(j+1>=c){
                    sol[i][j]=(img[i][j]+img[i-1][j]+img[i+1][j]+img[i-1][j-1]+img[i][j-1]+img[i+1][j-1])/6;
                    
                } //for matrix of type [[1,1],[1,0],[1,1]]
                else if(j-1<0){
                    sol[i][j]=(img[i][j]+img[i-1][j]+img[i+1][j]+img[i-1][j+1]+img[i][j+1]+img[i+1][j+1])/6;

                } //for matrix of type [[1,1],[0,1],[1,1]]
                else{
                    sol[i][j]=(img[i][j]+img[i-1][j]+img[i+1][j]+img[i][j+1]+img[i][j-1]+img[i+1][j+1]+img[i+1][j-1]+img[i-1][j+1]+img[i-1][j-1])/9;
                } //for matrix of type [[1,1,1],[1,0,1],[1,1,1]]


            }
        }

        return sol;
    }
};
