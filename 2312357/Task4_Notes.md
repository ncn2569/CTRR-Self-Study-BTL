# Ghi chú Task 4 - Evacuation Route Planning

Tài liệu này ghi chú lại cách hiện thực chuẩn cho Task 4 và phân tích những điểm hiểu sai đề so với Test Case.

## 1. Những điểm hiểu sai đề ban đầu
Trong code cũ của bạn, có 2 điểm chính chưa khớp với yêu cầu của đề và Test Case:

1. **Hiểu sai về `weightMatrix`**:
   - **Code cũ**: Dùng `weightMatrix` như một mảng 2 chiều để lưu giá trị `g` (tổng chi phí) của các ô trên đường đi (giống như đánh dấu đường đi trên lưới).
   - **Đề bài & Testcase**: Đề yêu cầu *"rebuild it as a graph using a weight matrix"*. Ở đây `weightMatrix` thực chất là một **Ma trận kề (Adjacency Matrix)** của đồ thị. 
   - Với lưới kích thước $m \times n$, mỗi ô $(x, y)$ được xem là một đỉnh với định danh $id = x \cdot n + y$. Ma trận `weightMatrix[u][v]` lưu chi phí cạnh nối từ đỉnh $u$ sang đỉnh $v$ (chi phí 1.0 cho ngang/dọc, 1.5 cho chéo, và 0.0 nếu có vật cản).

2. **Định dạng Tên Node (Node Name)**:
   - **Code cũ**: Xuất ra tên hướng đi (như "Down", "Right"...) giống như Task 3 và bỏ đi điểm Start. Không có khoảng trắng sau dấu phẩy `(x,y)`.
   - **Testcase**: Yêu cầu tên Node phải là toạ độ dạng `(x, y)` (có dấu cách sau dấu phẩy). Bắt buộc **phải giữ lại điểm Start** trong kết quả trả về.

3. **Thứ tự duyệt láng giềng (Tie-breaking)**:
   - Khi có nhiều đường đi có cùng tổng chi phí tối ưu (cùng $f$ và cùng $g$), A* sẽ quyết định chọn đường đi nào dựa vào thứ tự thêm láng giềng vào MinHeap.
   - Để trùng khớp 100% với Testcase, phải duyệt các đỉnh kề theo đúng thứ tự mảng hướng `dx`, `dy` đã cho thay vì duyệt mảng từ `0` đến `m*n - 1`.

## 2. Cách hiện thực chuẩn (Từng bước)

Để code lại đúng yêu cầu của Task 4, bạn có thể tham khảo quy trình sau:

### Bước 1: Khởi tạo Ma trận kề `weightMatrix`
- Đặt tất cả phần tử trong mảng `weightMatrix[100][100]` về `0.0`.
- Duyệt qua từng ô `(x, y)` trong lưới `floorPlan` (kích thước $m \times n$).
- Nếu ô đó không bị chặn (`floorPlan[x][y] == 0`), tính $id$ của ô đó: $u = x \cdot n + y$.
- Duyệt 8 hướng xung quanh bằng mảng `dx`, `dy`. Nếu ô kề hợp lệ, tính $id$ của ô kề là $v$, sau đó gán `weightMatrix[u][v]` bằng chi phí di chuyển tương ứng (`m_cost[i]`).

### Bước 2: Setup dữ liệu ban đầu cho A*
- Đặt chuỗi `names` cho từng đỉnh theo format: `"(" + to_string(x) + ", " + to_string(y) + ")"`.
- Khởi tạo mảng `g`, `h` bằng giá trị `MAX`, mảng `visited` là `false`, `parents` là `-1`.
- Chèn điểm xuất phát vào MinHeap `ncn`. Chú ý: Trả về thẳng điểm bắt đầu nếu `start == goal`.

### Bước 3: Vòng lặp A* với Tie-breaking chuẩn
- Bốc đỉnh $u$ có $f$ nhỏ nhất từ MinHeap.
- Phải duyệt láng giềng của $u$ **theo đúng mảng hướng `dx`, `dy`** (để mô phỏng lại thứ tự chèn vào Heap giống hệt như Task 3).
- Dùng `weightMatrix[u][v]` để lấy chi phí đường đi. Nếu `weightMatrix[u][v] != 0` và có thể cập nhật chi phí `g` tốt hơn, thực hiện cập nhật `g[v]`, `parents[v]`, và đưa `v` vào MinHeap.

### Bước 4: Truy vết và Xây dựng Linked List
- Sau khi tìm được đường đến `goalPoint`, dùng mảng `parents` để truy vết ngược lại đường đi (từ đích về nguồn), đẩy vào `vector<int> path`.
- Lật ngược mảng `path` bằng `reverse()` rồi thêm `goalPoint` vào cuối.
- Dùng hàm `build_linked_list` để chuyển `path` thành danh sách liên kết.
- Trả về thẳng danh sách này (không xóa phần tử đầu tiên).
