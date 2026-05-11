#pragma once
#include "PathNode.h"

// min heap nhân tạo :)))
struct HeapNode {
    double f; //f=g+h
    int id; //tên
    double h; //
};
//priority queue O(log n)
struct MinHeap {
    
    vector<HeapNode> data;
    bool empty() const{
        return data.empty();
    };
    HeapNode top() const {
        return data[0];
    };  
    void debug(){
        if (data.size()==1){
            cout<<"queue: "<<data[0].id<<" "<<endl;
            return ;
        };
        for (int i=0;i<data.size();i++){
            cout<<"queue: "<<data[i].id<<" ";
        };
        cout<<endl;
        
    };
    void push(double f,double h,int id){
        data.push_back({f,id,h});
        
        int i=(int)data.size()-1;
        
        //heapify up
        while (i>0){
            int father=(i-1)/2;
            if ((data[father].f <data[i].f)||(data[father].f==data[i].f&&data[father].h <= data[i].h)){
                break; //thỏa mãn heap cha < con
            };
            swap(data[father],data[i]);
            i=father;
        };
    };
    
    HeapNode pop(){
        HeapNode ncn=data[0]; // ncn = phần tử nhỏ nhất(phần tử đầu của minheap)
        data[0]=data[(int)data.size()-1];//gán phần tử đầu thành phần tử cuối rồi heapify down
        
        
        data.pop_back(); //bỏ phần tử cuối
        int i=0;
        //heapify down
        while(true){
            int l=2*i+1;
            int r=2*i+2;
            int temp=i;
            int size=(int)data.size();
            if (l<size){
                if ((data[l].f<data[temp].f)||(data[l].f==data[temp].f&&data[l].h<=data[temp].h)){
                    temp=l;
                };
            };
            if (r<size){
                if ((data[r].f<data[temp].f)||(data[r].f==data[temp].f&&data[r].h<=data[temp].h)){
                    temp=r;
                };
            };
            if (temp==i) {
                break;
            };
            swap(data[temp],data[i]); // swap rồi gán index tiếp để so sánh xuống
            i=temp;
        }; 
        return ncn;
    };
};
//helper func to build linked list
inline PathNode* build_linked_list(
    const vector<int>& path, // tham chiếu đỡ phải copy toàn bộ dữ liệu
    const double g[],
    const double h[],
    const string names[]
);

double heuristic_task_1(int x,int goal, double matrix[100][100]);

double convert_2d_2_1d(); // xem xét

// task 1
PathNode* findSocialPath(double adjMatrix[100][100], int startPerson, int goalPerson);
// task 2
PathNode* findDronePath(double adjMatrix[100][100], int coords[100][2],
    int startPoint, int goalPoint, int mode);
// task 3
PathNode* findWarehousePath(int warehouse[100][100], int m, int n, int startX,
    int startY, int goalX, int goalY, int mode);
// task 4
PathNode* findEvacuationPath(int floorPlan[100][100], int m, int n, int startX,
    int startY, int exitX, int exitY, double weightMatrix[100][100], int mode);