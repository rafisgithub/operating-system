#include <iostream>
using namespace std;

int main() {
    int n = 6, m = 3;

    int alloc[6][3] = {
        {2,1,1},
        {1,1,0},
        {4,0,2},
        {0,2,1},
        {1,0,3},
        {2,1,1}
    };

    int maxm[6][3] = {
        {6,4,3},
        {3,2,2},
        {7,3,5},
        {2,3,3},
        {4,2,5},
        {5,3,3}
    };

    int avail[3]={5,2,2};

    int need[6][3];

    cout<<"Need Matrix\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=maxm[i][j]-alloc[i][j];
            cout<<need[i][j]<<" ";
        }
        cout<<endl;
    }

    bool finish[6]={false};
    int safeSeq[6];

    int count=0;

    while(count<n){

        bool found=false;

        for(int p=0;p<n;p++){

            if(!finish[p]){

                int j;

                for(j=0;j<m;j++){

                    if(need[p][j]>avail[j])
                        break;

                }

                if(j==m){

                    for(int k=0;k<m;k++)
                        avail[k]+=alloc[p][k];

                    safeSeq[count++]=p;
                    finish[p]=true;
                    found=true;
                }
            }
        }

        if(!found){
            cout<<"System is Unsafe";
            return 0;
        }
    }

    cout<<"\nSafe Sequence:\n";

    for(int i=0;i<n;i++)
        cout<<"P"<<safeSeq[i]+1<<" ";

    return 0;
}
