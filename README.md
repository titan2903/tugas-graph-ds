# Tugas Graph

## Dokumentasi Implementasi Graf dalam C++

Dokumen ini menjelaskan dua cara umum untuk merepresentasikan graf: **Adjacency Matrix** (Matriks Ketetanggaan) dan **Adjacency List** (Daftar Ketetanggaan), beserta kelebihan dan kekurangannya masing-masing.

---

### 1. Representasi Adjacency Matrix (`GraphMatrix`)

Representasi ini menggunakan matriks 2D berukuran *V × V*. Elemen `adjMatrix[i][j]` bernilai 1 jika ada sisi dari simpul *i* ke *j*, dan 0 jika tidak.

- **Kelebihan:**  
  - Pengecekan sisi sangat cepat (kompleksitas O(1)).
- **Kekurangan:**  
  - Boros memori (O(V²)), tidak efisien untuk graf jarang.
  - Tidak fleksibel untuk menambah simpul baru.

**Fungsi pada Class GraphMatrix:**
- `GraphMatrix(int vertices)`: Konstruktor yang menginisialisasi matriks ketetanggaan berukuran *V × V* dengan semua nilai 0.
- `addEdge(int u, int v)`: Menambahkan sisi untuk graf tidak berarah dengan mengatur `adjMatrix[u][v]` dan `adjMatrix[v][u]` menjadi 1.
- `BFS(int startNode)`: Menelusuri graf level-demi-level dari `startNode` menggunakan antrian (queue).
- `DFS(int startNode)`: Menelusuri graf secara mendalam dari `startNode` menggunakan rekursi.

---

### 2. Representasi Adjacency List (`GraphList`)

Representasi ini menggunakan array dari `std::vector`, di mana setiap indeks `adjList[i]` menyimpan daftar simpul yang bertetangga dengan *i*.

- **Kelebihan:**  
  - Hemat memori (O(V+E)), cocok untuk graf jarang.
  - Mudah untuk menambah simpul.
- **Kekurangan:**  
  - Pengecekan sisi lebih lambat (O(derajat(u))).

**Fungsi pada Class GraphList:**
- `GraphList(int vertices)`: Konstruktor yang menginisialisasi array vector kosong sebanyak *V*.
- `addEdge(int u, int v)`: Menambahkan sisi dengan memasukkan *v* ke `adjList[u]` dan *u* ke `adjList[v]`.
- `BFS(int startNode)`: Proses sama seperti versi matriks, namun mencari tetangga dengan mengiterasi elemen di dalam `adjList[u]`.
- `DFS(int startNode)`: Proses sama seperti versi matriks, menggunakan iterasi pada `adjList[u]` untuk memanggil fungsi rekursif pada tetangga yang belum dikunjungi.

---

### Contoh Input dan Output

**Input (Struktur Graf):**
- Jumlah Simpul: 6 (0 hingga 5)
- Sisi: 0-1, 0-2, 1-3, 1-4, 2-4, 4-5

**Output yang Diharapkan (mulai dari simpul 0):**
- **BFS:** 0 1 2 3 4 5
- **DFS:** 0 1 3 4 2 5
## Cara Menggunakan

1. **Instalasi C++:**  
   Pastikan Anda sudah menginstal compiler C++ (misal: `g++`).  
   - **Ubuntu/Debian:**  
     Buka terminal dan jalankan:
     ```
     sudo apt update
     sudo apt install g++
     ```
   - **Fedora:**  
     ```
     sudo dnf install gcc-c++
     ```
   - **Windows:**  
     Unduh dan instal [MinGW](https://www.mingw-w64.org/) atau gunakan [WSL](https://docs.microsoft.com/id-id/windows/wsl/).
     
   - **MacOS:**  
     Instal Xcode Command Line Tools:
     ```
     xcode-select --install
     ```
   

2. **Kompilasi:**  
   Buka terminal, lalu jalankan perintah berikut:
   ```
   g++ main.cpp -o result
   ```

3. **Jalankan Program:**  
   Setelah kompilasi berhasil, jalankan:
   ```
   ./result
   ```

---

## Contoh Output

Setelah program dijalankan, output akan terlihat seperti berikut:

```
*** Implementasi Adjacency Matrix ***
Hasil BFS (mulai dari 0): 0 1 2 3 4 5 
Hasil DFS (mulai dari 0): 0 1 3 4 2 5 

----------------------------------------

*** Implementasi Adjacency List ***
Hasil BFS (mulai dari 0): 0 1 2 3 4 5 
Hasil DFS (mulai dari 0): 0 1 3 4 2 5

```