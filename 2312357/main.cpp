#include "PathNode.h"
#include "Algo.h"

void printPath(PathNode* head) {
    cout << "Solution Path:\n";
    while (head != nullptr) {
        cout << "Node: " << head->name
            << " | f: " << head->f
            << " | g: " << head->g
            << " | h: " << head->h << "\n";
            head = head->next;
    }
};
void reset_double(double mat[100][100]) {
    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j)
            mat[i][j] = 0.0;
};
 
void reset_int(int mat[100][100]) {
    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j)
            mat[i][j] = 0;
};
 
void reset(double adjMatrix[100][100]){
    for(int i = 0; i < 100; ++i) {
        for(int j = 0; j < 100; ++j) {
            adjMatrix[i][j] = 0;
        }
    }
};

void Test_Task1(){
    double adjMatrix[100][100];
    PathNode* path = nullptr;

    cout << "========== TASK 1 TEST CASES ==========\n";

    cout << "\n[TC1]\n";
    reset(adjMatrix);
    path = findSocialPath(adjMatrix, 0, 0);
    cout << "\nexpected = node 0\n";
    printPath(path);

    cout << "\n[TC2]\n";
    reset(adjMatrix);
    adjMatrix[0][1] = 1.0; adjMatrix[1][0] = 1.0;
    path = findSocialPath(adjMatrix, 0, 1);
    cout << "\nexpected = 0->1\n";
    printPath(path);

    cout << "\n[TC3]\n";
    reset(adjMatrix);
    adjMatrix[0][1] = 1.0; adjMatrix[1][0] = 1.0;
    adjMatrix[1][2] = 1.0; adjMatrix[2][1] = 1.0;
    adjMatrix[2][3] = 1.0; adjMatrix[3][2] = 1.0;
    path = findSocialPath(adjMatrix, 0, 3);
    cout << "\nexpected = 0->1->2->3\n";
    printPath(path);

    cout << "\n[TC4]\n";
    reset(adjMatrix);
    
    adjMatrix[0][1] = 1.0; adjMatrix[1][0] = 1.0;
    adjMatrix[1][2] = 1.0; adjMatrix[2][1] = 1.0;
    adjMatrix[2][3] = 1.0; adjMatrix[3][2] = 1.0;
    
    adjMatrix[0][4] = 1.0; adjMatrix[4][0] = 1.0;
    adjMatrix[4][3] = 1.0; adjMatrix[3][4] = 1.0;
    path = findSocialPath(adjMatrix, 0, 3);
    cout << "\nexpected = 0->4->3\n";
    printPath(path);

    cout << "\n[TC5]\n";
    reset(adjMatrix);
    adjMatrix[0][1] = 1.0; adjMatrix[1][0] = 1.0; // Vung 1
    adjMatrix[2][3] = 1.0; adjMatrix[3][2] = 1.0; // Vung 2
    path = findSocialPath(adjMatrix, 0, 3);
    cout << "\nexpected = nullptr\n";
    printPath(path);

    cout << "\n[TC6]\n";
    reset(adjMatrix);

    adjMatrix[0][1] = 1.0; adjMatrix[1][0] = 1.0;
    adjMatrix[1][2] = 1.0; adjMatrix[2][1] = 1.0;

    adjMatrix[0][3] = 1.0; adjMatrix[3][0] = 1.0;
    adjMatrix[3][4] = 1.0; adjMatrix[4][3] = 1.0;
    adjMatrix[4][6] = 1.0; adjMatrix[6][4] = 1.0;
    path = findSocialPath(adjMatrix, 0, 6);
    cout << "\nexpected = 0->3->4->6\n";
    printPath(path);

    cout << "\n===============================================\n";
};
// ============================================================
//  TASK 2 — Drone Delivery
//  Graph: weighted directed (adjMatrix[i][j] = weight, 0 = no edge)
//  coords[i] = {x, y}
//  g(n) = tong trong so canh
//  h(n) mode 1 = Manhattan, mode 2 = Euclidean, mode 3 = Chebyshev
//  name cua moi node = to_string(index)
// ============================================================
void Test_Task2() {
    double adjMatrix[100][100];
    int coords[100][2];
    PathNode* path = nullptr;
 
    cout << "========== TASK 2 TEST CASES ==========\n";
 
    // ----------------------------------------------------------
    // TC1: start == goal
    // Graph: 1 node duy nhat tai (0,0)
    // Expected: 1 node "0", g=0, h=0, f=0
    // ----------------------------------------------------------
    cout << "\n[TC1]\n";
    reset_double(adjMatrix);
    coords[0][0] = 0; coords[0][1] = 0;
    path = findDronePath(adjMatrix, coords, 0, 0, 1);
    cout << "expected: Node (0,0) | f=0 | g=0 | h=0\n";
    printPath(path);
 
    // ----------------------------------------------------------
    // TC2: duong di thang 1 buoc, ca 3 mode
    // Graph: 0->(w=5)->1
    // coords: 0=(0,0), 1=(3,4)
    // Mode 1 Manhattan h(0->1) = |3-0|+|4-0| = 7, h(1) = 0
    // Mode 2 Euclidean h(0->1) = sqrt(9+16) = 5.0, h(1) = 0
    // Mode 3 Chebyshev h(0->1) = max(3,4) = 4, h(1) = 0
    // g(1) = 5 (trong so canh)
    // ----------------------------------------------------------
    cout << "\n[TC2a] 1 buoc - mode 1 (Manhattan)\n";
    reset_double(adjMatrix);
    coords[0][0] = 0; coords[0][1] = 0;
    coords[1][0] = 3; coords[1][1] = 4;
    adjMatrix[0][1] = 5.0;
    path = findDronePath(adjMatrix, coords, 0, 1, 1);
    cout << "expected: (0,0)(g=0,h=7,f=7) -> (3,4)(g=5,h=0,f=5)\n";
    printPath(path);
 
    cout << "\n[TC2b] 1 buoc - mode 2 (Euclidean)\n";
    reset_double(adjMatrix);
    coords[0][0] = 0; coords[0][1] = 0;
    coords[1][0] = 3; coords[1][1] = 4;
    adjMatrix[0][1] = 5.0;
    path = findDronePath(adjMatrix, coords, 0, 1, 2);
    cout << "expected: (0,0)(g=0,h=5.0,f=5.0) -> (3,4)(g=5,h=0,f=5)\n";
    printPath(path);
 
    cout << "\n[TC2c] 1 buoc - mode 3 (Chebyshev)\n";
    reset_double(adjMatrix);
    coords[0][0] = 0; coords[0][1] = 0;
    coords[1][0] = 3; coords[1][1] = 4;
    adjMatrix[0][1] = 5.0;
    path = findDronePath(adjMatrix, coords, 0, 1, 3);
    cout << "expected: (0,0)(g=0,h=4,f=4) -> (3,4)(g=5,h=0,f=5)\n";
    printPath(path);
 
    // ----------------------------------------------------------
    // TC3: duong di qua nhieu node, khong co nhanh nhieu
    // Graph: 0->(w=2)->1->(w=3)->2->(w=1)->3
    // coords: 0=(0,0), 1=(1,0), 2=(2,0), 3=(3,0)
    // Mode 1 Manhattan (di theo truc x):
    //   h(0)=3, h(1)=2, h(2)=1, h(3)=0
    //   g: 0,2,5,6
    //   f: 3,4,6,6
    // Expected path: 0->1->2->3
    // ----------------------------------------------------------
    cout << "\n[TC3] duong thang qua nhieu node - mode 1\n";
    reset_double(adjMatrix);
    coords[0][0] = 0; coords[0][1] = 0;
    coords[1][0] = 1; coords[1][1] = 0;
    coords[2][0] = 2; coords[2][1] = 0;
    coords[3][0] = 3; coords[3][1] = 0;
    adjMatrix[0][1] = 2.0;
    adjMatrix[1][2] = 3.0;
    adjMatrix[2][3] = 1.0;
    path = findDronePath(adjMatrix, coords, 0, 3, 1);
    cout << "expected: (0,0)(g=0,h=3,f=3)->(1,0)(g=2,h=2,f=4)->(2,0)(g=5,h=1,f=6)->(3,0)(g=6,h=0,f=6)\n";
    printPath(path);
 
    // ----------------------------------------------------------
    // TC4: nhieu duong, chon duong co tong trong so nho nhat
    // Graph:
    //   0->(w=1)->1->(w=1)->2->(w=1)->3   (3 buoc, tong = 3)
    //   0->(w=10)->3                        (1 buoc, tong = 10)
    // coords: 0=(0,0), 1=(1,0), 2=(2,0), 3=(3,0)
    // Mode 2 Euclidean:
    //   Duong ngan hon ve chi phi la 0->1->2->3 (g=3)
    //   du A* bi nham huong boi h, g thuc su quyet dinh
    // Expected: 0->1->2->3
    // ----------------------------------------------------------
    cout << "\n[TC4] nhieu duong - chon duong chi phi thap nhat - mode 2\n";
    reset_double(adjMatrix);
    coords[0][0] = 0; coords[0][1] = 0;
    coords[1][0] = 1; coords[1][1] = 0;
    coords[2][0] = 2; coords[2][1] = 0;
    coords[3][0] = 3; coords[3][1] = 0;
    adjMatrix[0][1] = 1.0;
    adjMatrix[1][2] = 1.0;
    adjMatrix[2][3] = 1.0;
    adjMatrix[0][3] = 10.0;
    path = findDronePath(adjMatrix, coords, 0, 3, 2);
    cout << "expected: (0,0)->(1,0)->(2,0)->(3,0) (g total = 3, not 10)\n";
    printPath(path);
 
    // ----------------------------------------------------------
    // TC5: khong co duong di
    // Graph: 0 va 1 khong co canh nao den 2
    // Expected: nullptr
    // ----------------------------------------------------------
    cout << "\n[TC5] khong co duong di\n";
    reset_double(adjMatrix);
    coords[0][0] = 0; coords[0][1] = 0;
    coords[1][0] = 1; coords[1][1] = 0;
    coords[2][0] = 5; coords[2][1] = 5;
    adjMatrix[0][1] = 1.0;
    path = findDronePath(adjMatrix, coords, 0, 2, 1);
    cout << "expected: nullptr \n";
    printPath(path);
 
    // ----------------------------------------------------------
    // TC6: so sanh 3 mode tren cung 1 graph
    // Graph:
    //   0=(0,0), 1=(0,3), 2=(4,3)
    //   0->(w=3)->1->(w=4)->2
    //   0->(w=6)->2
    // Tong chi phi: 0->1->2 = 7, 0->2 = 6
    // A* nen chon 0->2 vi g nho hon
    // Mode 1: h(0->2) = |4|+|3| = 7, f=13; h(0->1) = 0+3=3, f=6 -> expand 1 truoc
    //   sau expand 1: g(2) qua 1->2 = 7, f=7
    //   g(2) qua direct = 6, f=6 -> chon 0->2
    // Mode 2: h(0->2) = 5, f=11; h(0->1) = 3, f=6 -> tuong tu, ket qua 0->2
    // Mode 3: h(0->2) = max(4,3)=4, f=10; h(0->1)=3, f=6 -> tuong tu, ket qua 0->2
    // Expected tat ca 3 mode: 0->2
    // ----------------------------------------------------------
    cout << "\n[TC6] so sanh 3 mode - cung chon duong chi phi thap nhat\n";
    reset_double(adjMatrix);
    coords[0][0] = 0; coords[0][1] = 0;
    coords[1][0] = 0; coords[1][1] = 3;
    coords[2][0] = 4; coords[2][1] = 3;
    adjMatrix[0][1] = 3.0;
    adjMatrix[1][2] = 4.0;
    adjMatrix[0][2] = 6.0;
 
    cout << "--- mode 1 ---\n";
    path = findDronePath(adjMatrix, coords, 0, 2, 1);
    cout << "expected: (0,0)->(4,3) (g=6)\n";
    printPath(path);
 
    cout << "--- mode 2 ---\n";
    path = findDronePath(adjMatrix, coords, 0, 2, 2);
    cout << "expected: (0,0)->(4,3) (g=6)\n";
    printPath(path);
 
    cout << "--- mode 3 ---\n";
    path = findDronePath(adjMatrix, coords, 0, 2, 3);
    cout << "expected: (0,0)->(4,3) (g=6)\n";
    printPath(path);
 
    cout << "\n===============================================\n";
};
 
// ============================================================
//  TASK 3 — Warehouse Robot Navigation
//  Grid m x n, 0=di duoc, 1=blocked
//  8 huong: Up/Down/Left/Right (cost 1), diagonal (cost 1.5)
//  Toa do: (row, col), (0,0) = goc tren trai
//  name cua node = ten huong di den o do (e.g. "Down", "Up-Right")
//  h mode 1 = Manhattan, mode 2 = Chebyshev
// ============================================================
void Test_Task3() {
    int warehouse[100][100];
    PathNode* path = nullptr;
 
    cout << "========== TASK 3 TEST CASES ==========\n";
 
    // ----------------------------------------------------------
    // TC1: start == goal
    // Grid 3x3 co tuong o (0,1) va (1,0), start=(0,0), goal=(0,0)
    // 0 1 0
    // 1 0 0
    // 0 0 0
    // Expected: 1 node (start node, khong co buoc di nao)
    // ----------------------------------------------------------
    cout << "\n[TC1] start == goal\n";
    reset_int(warehouse);
    warehouse[0][1] = 1;
    warehouse[1][0] = 1;
    path = findWarehousePath(warehouse, 3, 3, 0, 0, 0, 0, 1);
    cout << "expected: 1 node (start node)\n";
    printPath(path);
 
    // ----------------------------------------------------------
    // TC2: di thang 1 buoc xuong (Down), co tuong ben canh
    // Grid 3x3:
    //   0 1 0
    //   0 1 0
    //   0 0 0
    // start=(0,0), goal=(1,0)
    // Hang xom phai (0,1) va (1,1) bi chan -> buoc Down la con duong duy nhat
    // g=1, h(mode1) tại goal = 0
    // Expected: Down(g=1,h=0,f=1)
    // ----------------------------------------------------------
    cout << "\n[TC2] 1 buoc Down - mode 1 (co tuong trai)\n";
    reset_int(warehouse);
    warehouse[0][1] = 1;
    warehouse[1][1] = 1;
    path = findWarehousePath(warehouse, 3, 3, 0, 0, 1, 0, 1);
    cout << "expected: Down(g=1,h=0,f=1)\n";
    printPath(path);
 
    // ----------------------------------------------------------
    // TC3: di cheo 1 buoc (Down-Right), co tuong chan huong thang
    // Grid 3x3:
    //   0 1 0
    //   1 0 0
    //   0 0 0
    // start=(0,0), goal=(1,1)
    // (0,1) va (1,0) bi chan -> khong the di Right roi Down, phai di cheo Down-Right
    // g=1.5, h(mode2 Chebyshev) tai start: max(1,1)=1 -> f=2.5
    // Expected: Down-Right(g=1.5,h=0,f=1.5)
    // ----------------------------------------------------------
    cout << "\n[TC3] 1 buoc cheo Down-Right - mode 2 (huong thang bi chan)\n";
    reset_int(warehouse);
    warehouse[0][1] = 1;
    warehouse[1][0] = 1;
    path = findWarehousePath(warehouse, 3, 3, 0, 0, 1, 1, 2);
    cout << "expected: Down-Right(g=1.5,h=0,f=1.5)\n";
    printPath(path);
 
    // ----------------------------------------------------------
    // TC4: co tuong, buoc di thang bi chan, phai di vong
    // Grid 4x4:
    //   0 0 0 0
    //   1 1 1 0
    //   0 0 0 0
    //   0 0 0 0
    // start=(0,0), goal=(2,0)
    // (1,0),(1,1),(1,2) bi chan, (1,3) mo
    // Duong toi uu: (0,0)->Down-Right(1,3)? Khong, (1,0)=1 nen chi co the di
    //   Right(0,1)->Right(0,2)->Down-Right(1,3)->Down-Left(2,2)->Left(2,1)->Left(2,0)
    //   g = 1+1+1.5+1.5+1+1 = 7.0
    // Hoac: Right(0,1)->Right(0,2)->Right(0,3)->Down(1,3)->Down(2,3)->Left(2,2)->Left(2,1)->Left(2,0)
    //   g = 1+1+1+1+1+1+1+1 = 8.0
    // Duong toi uu: Right,Right,Down-Right,Down-Left,Left,Left (g=7.0)
    // mode 1 Manhattan
    // ----------------------------------------------------------
    cout << "\n[TC4] co tuong - di vong qua canh phai - mode 1\n";
    reset_int(warehouse);
    warehouse[1][0] = 1;
    warehouse[1][1] = 1;
    warehouse[1][2] = 1;
    // warehouse[1][3] = 0 (mo)
    path = findWarehousePath(warehouse, 4, 4, 0, 0, 2, 0, 1);
    cout << "expected: Right,Right,Down-Right,Down-Left,Left,Left (g=7.0)\n";
    printPath(path);
 
    // ----------------------------------------------------------
    // TC5: khong co duong di (goal bi bao vay hoan toan ca 8 huong)
    // Grid 5x5:
    //   0 0 0 0 0
    //   0 1 1 1 0
    //   0 1 G 1 0
    //   0 1 1 1 0
    //   0 0 0 0 0
    // G = goal tai (2,2), start=(0,0)
    // Tat ca 8 hang xom cua (2,2) deu = 1 -> goal khong the tiep can
    // Expected: nullptr
    // ----------------------------------------------------------
    cout << "\n[TC5] goal bi bao vay 8 huong - khong co duong\n";
    reset_int(warehouse);
    // Bao vay (2,2) bang vong tuong 8 o xung quanh
    warehouse[1][1] = 1; warehouse[1][2] = 1; warehouse[1][3] = 1;
    warehouse[2][1] = 1;                       warehouse[2][3] = 1;
    warehouse[3][1] = 1; warehouse[3][2] = 1; warehouse[3][3] = 1;
    path = findWarehousePath(warehouse, 5, 5, 0, 0, 2, 2, 1);
    cout << "expected: nullptr\n";
    printPath(path);
 
    // ----------------------------------------------------------
    // TC6: so sanh mode 1 vs mode 2 tren grid co tuong buoc huong
    // Grid 5x5:
    //   0 0 0 0 0
    //   0 1 0 0 0
    //   0 1 0 0 0
    //   0 1 0 0 0
    //   0 0 0 0 0
    // start=(0,0), goal=(4,4)
    // Cot 1 hang 1-3 bi chan -> khong the di thang cheo qua (1,1),(2,1),(3,1)
    // Mode 1 (Manhattan): buoc xung quanh tuong, co the di Down(0,0)->(1,0)->(2,0)->(3,0)->(4,0)->Right..
    // Mode 2 (Chebyshev): uu tien cheo -> (0,0)->Down-Right(1,1)? bi chan ->
    //   phai xuong (1,0),(2,0),(3,0) roi cheo sang goal
    // Ca 2 mode phai di vong qua cot 0, Chebyshev se cheo nhieu buoc hon
    // ----------------------------------------------------------
    cout << "\n[TC6] mode 1 vs mode 2 - grid co tuong doc\n";
    reset_int(warehouse);
    warehouse[1][1] = 1;
    warehouse[2][1] = 1;
    warehouse[3][1] = 1;
    cout << "--- mode 1 (Manhattan) ---\n";
    path = findWarehousePath(warehouse, 5, 5, 0, 0, 4, 4, 1);
    cout << "expected: di vong qua cot 0, Manhattan\n";
    printPath(path);
 
    cout << "--- mode 2 (Chebyshev) ---\n";
    path = findWarehousePath(warehouse, 5, 5, 0, 0, 4, 4, 2);
    cout << "expected: di vong qua cot 0, Chebyshev (nhieu buoc cheo hon)\n";
    printPath(path);
 
    cout << "\n===============================================\n";
};
 
// // ============================================================
// //  TASK 4 — Evacuation Route Planning
// //  Giong Task 3 nhung:
// //  - floorPlan thay vi warehouse (cung 0/1)
// //  - Them weightMatrix[100][100] output: weightMatrix[x][y] = g(x,y)
// //    cho cac o trong path, cac o khac giu nguyen = 0
// //  - name: ten huong di (giong task 3)
// //  - h mode 1 = Manhattan, mode 2 = Chebyshev
// // ============================================================
// void Test_Task4() {
//     int floorPlan[100][100];
//     double weightMatrix[100][100];
//     PathNode* path = nullptr;
 
//     cout << "========== TASK 4 TEST CASES ==========\n";
 
//     // ----------------------------------------------------------
//     // TC1: start == goal
//     // Grid 3x3 trong
//     // Expected: 1 node, weightMatrix[0][0] = 0
//     // ----------------------------------------------------------
//     cout << "\n[TC1] start == goal\n";
//     reset_int(floorPlan);
//     reset_double(weightMatrix);
//     path = findEvacuationPath(floorPlan, 3, 3, 0, 0, 0, 0, weightMatrix, 1);
//     cout << "expected: 1 node, weightMatrix[0][0]=0\n";
//     printPath(path);
//     cout << "weightMatrix[0][0] = " << weightMatrix[0][0] << " (expected 0)\n";
 
//     // ----------------------------------------------------------
//     // TC2: 1 buoc Down
//     // Grid 3x3 trong, start=(0,0), exit=(1,0)
//     // Expected path: Down(g=1)
//     // weightMatrix[0][0]=0, weightMatrix[1][0]=1
//     // ----------------------------------------------------------
//     cout << "\n[TC2] 1 buoc Down - kiem tra weightMatrix\n";
//     reset_int(floorPlan);
//     reset_double(weightMatrix);
//     path = findEvacuationPath(floorPlan, 3, 3, 0, 0, 1, 0, weightMatrix, 1);
//     cout << "expected: Down(g=1,h=0,f=1)\n";
//     printPath(path);
//     cout << "weightMatrix[0][0]=" << weightMatrix[0][0] << " (expected 0)\n";
//     cout << "weightMatrix[1][0]=" << weightMatrix[1][0] << " (expected 1)\n";
 
//     // ----------------------------------------------------------
//     // TC3: duong di cheo
//     // Grid 3x3 trong, start=(0,0), exit=(2,2)
//     // Mode 2 Chebyshev -> 2 buoc Down-Right, g=3.0
//     // weightMatrix[0][0]=0, [1][1]=1.5, [2][2]=3.0
//     // ----------------------------------------------------------
//     cout << "\n[TC3] duong cheo - kiem tra weightMatrix - mode 2\n";
//     reset_int(floorPlan);
//     reset_double(weightMatrix);
//     path = findEvacuationPath(floorPlan, 3, 3, 0, 0, 2, 2, weightMatrix, 2);
//     cout << "expected: Down-Right(g=1.5), Down-Right(g=3.0)\n";
//     printPath(path);
//     cout << "weightMatrix[0][0]=" << weightMatrix[0][0] << " (expected 0)\n";
//     cout << "weightMatrix[1][1]=" << weightMatrix[1][1] << " (expected 1.5)\n";
//     cout << "weightMatrix[2][2]=" << weightMatrix[2][2] << " (expected 3.0)\n";
 
//     // ----------------------------------------------------------
//     // TC4: co tuong, kiem tra weightMatrix chi ghi path thuc su
//     // Grid 4x4:
//     //   0 0 0 0
//     //   0 1 0 0
//     //   0 0 0 0
//     //   0 0 0 0
//     // start=(0,0), exit=(2,2)
//     // Tuong tai (1,1) -> khong the di cheo thang
//     // Mot duong: (0,0)->Down(1,0)->Down-Right(2,1) bi chan boi(1,1)? Khong, (1,1)=tuong nhung (2,1) ok
//     //   (0,0)->Down(1,0)->Down-Right(2,1)->Right(2,2): g=1+1.5+1=3.5
//     // Duong khac: (0,0)->Right(0,1)->Down-Right(1,2)->Down-Left(2,1)->Right(2,2): g=1+1.5+1.5+1=5
//     // Duong khac: (0,0)->Right(0,1)->Right(0,2)->Down(1,2)->Down(2,2): g=1+1+1+1=4
//     // Duong toi uu: Down,Down-Right,Right (g=3.5)
//     // weightMatrix: [0][0]=0,[1][0]=1,[2][1]=2.5,[2][2]=3.5, cac o khac=0
//     // ----------------------------------------------------------
//     cout << "\n[TC4] co tuong - kiem tra weightMatrix chi ghi path - mode 1\n";
//     reset_int(floorPlan);
//     reset_double(weightMatrix);
//     floorPlan[1][1] = 1;
//     path = findEvacuationPath(floorPlan, 4, 4, 0, 0, 2, 2, weightMatrix, 1);
//     cout << "expected path: Down(g=1), Down-Right(g=2.5), Right(g=3.5)\n";
//     printPath(path);
//     cout << "weightMatrix[0][0]=" << weightMatrix[0][0] << " (expected 0)\n";
//     cout << "weightMatrix[1][0]=" << weightMatrix[1][0] << " (expected 1)\n";
//     cout << "weightMatrix[2][1]=" << weightMatrix[2][1] << " (expected 2.5)\n";
//     cout << "weightMatrix[2][2]=" << weightMatrix[2][2] << " (expected 3.5)\n";
//     cout << "weightMatrix[0][1]=" << weightMatrix[0][1] << " (expected 0, khong trong path)\n";
 
//     // ----------------------------------------------------------
//     // TC5: khong co duong thoat (exit bi chan)
//     // Grid 3x3, exit=(1,1) bi bao vay 4 huong chinh
//     // Expected: nullptr, weightMatrix giu nguyen = 0
//     // ----------------------------------------------------------
//     cout << "\n[TC5] khong co duong thoat - weightMatrix giu nguyen\n";
//     reset_int(floorPlan);
//     reset_double(weightMatrix);
//     floorPlan[0][1] = 1;
//     floorPlan[1][0] = 1;
//     floorPlan[1][2] = 1;
//     floorPlan[2][1] = 1;
//     path = findEvacuationPath(floorPlan, 3, 3, 0, 0, 1, 1, weightMatrix, 1);
//     cout << "expected: nullptr\n";
//     printPath(path);
//     cout << "weightMatrix[0][0]=" << weightMatrix[0][0] << " (expected 0)\n";
 
//     // ----------------------------------------------------------
//     // TC6: so sanh mode 1 vs mode 2, kiem tra ca path lan weightMatrix
//     // Grid 5x5 trong, start=(0,0), exit=(0,4)
//     // Mode 1 Manhattan: h(0,0)=4, huong ngang -> 4 buoc Right, g=4
//     // Mode 2 Chebyshev: h(0,0)=4, cung 4 buoc Right, g=4
//     // (Truong hop nay 2 mode cho ket qua giong nhau)
//     // weightMatrix: [0][0]=0,[0][1]=1,[0][2]=2,[0][3]=3,[0][4]=4
//     // ----------------------------------------------------------
//     cout << "\n[TC6] di thang ngang - ca 2 mode, kiem tra weightMatrix day du\n";
//     reset_int(floorPlan);
 
//     cout << "--- mode 1 ---\n";
//     reset_double(weightMatrix);
//     path = findEvacuationPath(floorPlan, 5, 5, 0, 0, 0, 4, weightMatrix, 1);
//     cout << "expected: 4x Right (g=1,2,3,4)\n";
//     printPath(path);
//     for (int c = 0; c <= 4; ++c)
//         cout << "weightMatrix[0][" << c << "]=" << weightMatrix[0][c]
//              << " (expected " << c << ")\n";
 
//     cout << "--- mode 2 ---\n";
//     reset_double(weightMatrix);
//     path = findEvacuationPath(floorPlan, 5, 5, 0, 0, 0, 4, weightMatrix, 2);
//     cout << "expected: 4x Right (g=1,2,3,4)\n";
//     printPath(path);
//     for (int c = 0; c <= 4; ++c)
//         cout << "weightMatrix[0][" << c << "]=" << weightMatrix[0][c]
//              << " (expected " << c << ")\n";
 
//     cout << "\n===============================================\n";
// };
int main() {
    //Test_Task1();
    //Test_Task2();
    Test_Task3();
    // Test_Task4();
    return 0;
};

