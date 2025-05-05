#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    int i,j,t;
    cout<<"enter the number of testcases : ";
    cin>>t;
    while(t--){
        int n;
        cout<<"enter the number of 3 letter strings : ";
        cin>>n;
        vector<vector<string>> words(3,vector<string>(n));
        map<string,int>wordcount;
        for (i=0;i<3;i++){
            for(j=0;j<n;j++){
                printf("enter word %d of player %d : ",j+1,i+1);
                cin>>words[i][j];
                wordcount[words[i][j]]++;
            }
        }
        vector<int> scores(3,0);
        for (int i=0;i<3;i++){
            for (int j=0;j<n;j++){
                string word=words[i][j];
                if (wordcount[word]==1){
                    scores[i]+=3;
                }
                else if (wordcount[word]==2){
                    scores[i]+=1;
                }
            }
        }printf("\n\nthe scores are   %d  %d  %d\n\n\n",scores[0],scores[1],scores[2]);
    }
    return 0;
}
