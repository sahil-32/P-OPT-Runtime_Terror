#include<bits/stdc++.h>
using namespace std;

int main(){
    srand(time(0));
    int n=2;
    vector<int> adj[n];
    int offset[n];
    vector<int> neighbour;
    int sum=0;
    for(int i=0;i<n;i++){
        offset[i]=sum;
        int num_neighbour=rand()%20+1;
        sum+=num_neighbour;
        bool done[n];
        memset(done,false,sizeof(done));
        for(int j=0;j<num_neighbour;j++){
            int dest;
            while(true){
                dest=rand()%n;
                if(done[dest]==false){
                    done[dest]=true;
                    break;
                }
            } 
            adj[i].push_back(dest);
        }
        sort(adj[i].begin(),adj[i].end());
        for(int j=0;j<(int)adj[i].size();j++){
            neighbour.push_back(adj[i][j]);
        }
    }
    int src[n];
    for(int i=0;i<n;i++) src[i]=2*i;
    asm("mov %eax, %eax");
    src[0]=src[0];
    src[1]=src[1];
    asm("mov %eax, %eax");
    int des[n];
    memset(des,0,sizeof(des));
    for(int i=0;i<n;i++){
        asm("mov %eax, %eax");
        for(auto j: adj[i]){
            des[i]+=src[j];
        }
    }
    cout<<"int offset[]={";
    for(int i=0;i<n;i++){
        cout<<offset[i];
        if(i!=n-1) cout<<",";
    }
    cout<<"};"<<"\n";
    cout<<"int na[]={";
    for(int i=0;i<(int)neighbour.size();i++){
        cout<<neighbour[i];
        if(i!=(int)neighbour.size()-1) cout<<",";
    }
    cout<<"};"<<"\n";
    return 0;
}