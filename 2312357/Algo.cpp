#include "Algo.h"
inline PathNode* build_linked_list(
    const vector<int>& path, // tham chiếu đỡ phải copy toàn bộ dữ liệu
    const double g[],
    const double h[],
    const string names[]
){
    PathNode* head=nullptr;
    PathNode* tail=nullptr;
    
    for (int idx: path){
        PathNode* node = new PathNode(names[idx],g[idx]+h[idx],g[idx],h[idx]);
        if (!head){// node đầu tiên
            head=tail=node;
        }
        else{
            tail->next=node; // nối node vào cuối
            tail=node; //gán tail vào node
        };

    };
    return head;
};
void heuristic_task_1(int goal, double matrix[100][100],double h[100]){
    // mô phỏng queue bằng head + q.size() FIFO 
    //head giữ index từng hàng, hết hàng thì out
    vector<int> q;
    q.push_back(goal);
    h[goal]=0.0;
    int head=0;
    while (head<q.size()){
        int u=q[head];
        for (int i=0;i<100;i++){
            if(matrix[i][u]==1.0){ //đồ thị có hướng
                if (h[u]+1<h[i]){
                    h[i]=h[u]+1;
                    q.push_back(i);
                };
            };
        };
        head=head+1;
    };

    
};
const double MAX= 999999;

PathNode* findSocialPath(double adjMatrix[100][100], int startPerson, int goalPerson){
    double g[100],h[100];
    int parent[100];
    string names[100];
    bool visited[100];
    vector<int> path;
    MinHeap ncn;
    if(startPerson==goalPerson){
        PathNode* head=nullptr;
        string name=to_string(startPerson);
        head = new PathNode(name,0,0,0);
        return head;
    };
    
    for (int i=0;i<100;++i){
        g[i]=MAX;
        h[i]=MAX;
        names[i]=to_string(i);
        visited[i]=false;
        parent[i]=-1;
    };
    heuristic_task_1(goalPerson,adjMatrix,h);
    
    g[startPerson]=0;
    ncn.push(g[startPerson]+h[startPerson],h[startPerson],startPerson);
    while(!ncn.empty()){
        HeapNode temp=ncn.pop();
        if (visited[temp.id]==true) continue;
        if (temp.id==goalPerson) {
            break;
        };
        
        visited[temp.id]=true;
        
        for(int i=0;i<100;++i){
            if (adjMatrix[temp.id][i]==1.0){
                if (g[temp.id]+1<g[i]){
                    g[i]=g[temp.id]+1;
                    parent[i]=temp.id;
                    ncn.push(g[i]+h[i],h[i],i);
                };
            };
        };
    };
    
    if(parent[goalPerson]==-1) return nullptr;
    int i =goalPerson;
    while (parent[i]!=-1){
        path.push_back(parent[i]);
        i=parent[i];
    };
    reverse(path.begin(),path.end());
    path.push_back(goalPerson);
    return build_linked_list(path,g,h,names);
};

double heuristic_task_2(int x1,int x2,int y1,int y2, int mode){
    if (mode == 1){
        return abs(x1-x2)+abs(y1-y2);
    };
    if (mode == 2){
        return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
    };
    if (mode == 3){
        return max(abs(x1-x2),abs(y1-y2));
    };
    return 0.0;
};

PathNode* findDronePath(double adjMatrix[100][100], int coords[100][2],
    int startPoint, int goalPoint, int mode){
        double g[100],h[100];
        bool visited[100];
        MinHeap ncn;
        string names[100];
        int parents[100];
        vector<int> path;
        if (startPoint==goalPoint){
            PathNode* head=nullptr;
            string name='('+to_string(coords[startPoint][0])+','+to_string(coords[startPoint][1])+')';
            head = new PathNode(name,0,0,0);
            return head;
        }
        for (int i=0;i<100;i++){
            g[i]=MAX;
            h[i]=MAX;
            visited[i]=false;
            parents[i]=-1;      
            names[i]='('+to_string(coords[i][0])+','+to_string(coords[i][1])+')';
        };
        g[startPoint]=0;
        h[startPoint]=heuristic_task_2(coords[startPoint][0],coords[goalPoint][0],
            coords[startPoint][1],coords[goalPoint][1],mode);
        
        ncn.push(g[startPoint]+h[startPoint],h[startPoint],startPoint); // tutu tính
        while (!ncn.empty()){
            HeapNode temp=ncn.pop();
            if (temp.id==goalPoint) break;
            if (visited[temp.id]==true) continue;
            visited[temp.id]=true;
            for(int i=0;i<100;++i){
                if (adjMatrix[temp.id][i]!=0.0){
                    if (g[temp.id]+adjMatrix[temp.id][i]<g[i]){
                        g[i]=g[temp.id]+adjMatrix[temp.id][i];
                        parents[i]=temp.id;
                        h[i]=heuristic_task_2(coords[i][0],coords[goalPoint][0],
                                coords[i][1],coords[goalPoint][1],mode);
                        ncn.push(g[i]+h[i],h[i],i);
                    };
                };
            };
        };
        if(parents[goalPoint]==-1) return nullptr;
        int i =goalPoint;
        
        while (parents[i]!=-1){
            path.push_back(parents[i]);
            i=parents[i];
        };
        reverse(path.begin(),path.end());
        path.push_back(goalPoint);
        return build_linked_list(path,g,h,names);
    };

double heuristic_task_3(int x1,int x2,int y1,int y2, int mode){
    if (mode==1){
        return abs(x1-x2)+abs(y1-y2);
    }
    if (mode==2){
        return max(abs(x1-x2),abs(y1-y2));
    }
    return 0.0;
};

PathNode* findWarehousePath(int warehouse[100][100], int m, int n, int startX,
    int startY, int goalX, int goalY, int mode){
        double g[100],h[100];
        bool visited[100];
        MinHeap ncn;
        string names[100];
        int parents[100];
        vector<int> path;


        return build_linked_list(path,g,h,names);
    };