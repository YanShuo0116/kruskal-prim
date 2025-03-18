//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"

#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
#include <ctime>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
#define INF INT_MAX

namespace {
	const int MAX_SIZE = 5000; // 陣列大小

	int weights[MAX_SIZE][MAX_SIZE]; // G二維陣列
	int arraySize = 0; // 陣列大小
}

__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner)
{
}

using namespace std;

struct Edge {
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// 比較邊的權重
bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

struct PathInfo {
    int node;
    int distance;
    vector<int> path;

	PathInfo(int n, int dist, const vector<int>& p) : node(n), distance(dist), path(p) {}
};

// 填充G矩陣
void FillWeightMatrix(int n, int range, int valueIfGreater, int valueIfEqual)
{
	arraySize = n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				weights[i][j] = 0;
			} else {
				int weight = rand() % (range + 1);
				weights[i][j] = weight;
				if (weights[i][j] > valueIfGreater) {
					weights[j][i] = valueIfEqual;
				}
				if ( weights[j][i] != 0 ) {
					weights[i][j] = weights[j][i];
				}
			}
		}
	}
}

// 清除G
void ClearWeights() {
    for (int i = 0; i < MAX_SIZE; ++i) {
        for (int j = 0; j < MAX_SIZE; ++j) {
			weights[i][j] = 0;
		}
    }
}

// Loadfile
void LoadFromFile(const string& filename) {
	ifstream inputFile(filename);
	if (!inputFile.is_open()) {
        ShowMessage("無法打開文件。");
        return;
    }

    int n;
    inputFile >> n;
	arraySize = n;

	ClearWeights();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inputFile >> weights[i][j];
        }
    }

    inputFile.close();
}


class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
		}
	}

	bool connected(int x, int y) {
		return find(x) == find(y);
	}

private:
	vector<int> parent;
	vector<int> rank;
};
// 檢查是否形成循環
bool hasCycle(int v, int u, const std::vector<std::vector<int>> &adjList, std::vector<bool> &visited) {
	if (v == u) return true;
	visited[v] = true;
	for (int neighbor : adjList[v]) {
		if (!visited[neighbor]) {
			if (hasCycle(neighbor, u, adjList, visited)) return true;
		}
	}
	return false;
}

// Kruskal 演算法
vector<Edge> KruskalMST(int n, vector<Edge> &edges, bool useUnionFind) {
	vector<Edge> mst;
	if (useUnionFind) {
		UnionFind uf(n);
		sort(edges.begin(), edges.end(), compareEdges);
		for (const auto &edge : edges) {
			if (uf.find(edge.src) != uf.find(edge.dest)) {
				mst.push_back(edge);
				uf.unite(edge.src, edge.dest);
			}
		}
	} else {
		// 使用循環檢測
		sort(edges.begin(), edges.end(), compareEdges);
		vector<vector<int>> adjList(n);
		for (const auto &edge : edges) {
			vector<bool> visited(n, false);
			if (!hasCycle(edge.src, edge.dest, adjList, visited)) {
				mst.push_back(edge);
				adjList[edge.src].push_back(edge.dest);
				adjList[edge.dest].push_back(edge.src);
			}
		}
	}
	return mst;
}

// 檢查是否形成循環
bool hasCycle(int v, int u, vector<vector<int>> &adjList, vector<bool> &visited) {
	if (v == u) return true;
	visited[v] = true;
	for (int neighbor : adjList[v]) {
		if (!visited[neighbor]) {
			if (hasCycle(neighbor, u, adjList, visited)) return true;
		}
	}
	return false;
}

// Prim 演算法
vector<Edge> PrimMST(int n, int weights[MAX_SIZE][MAX_SIZE]) {
	vector<Edge> mst;
	vector<bool> inMST(n, false);
	vector<int> key(n, INF);
	vector<int> parent(n, -1);
	key[0] = 0;

	for (int count = 0; count < n - 1; ++count) {
		int u = -1;

        // 找到不在MST中的最小鍵值節點
		for (int i = 0; i < n; ++i) {
            if (!inMST[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        inMST[u] = true;
        for (int v = 0; v < n; ++v) {
            if (weights[u][v] && !inMST[v] && weights[u][v] < key[v]) {
				key[v] = weights[u][v];
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        mst.push_back(Edge(parent[i], i, weights[i][parent[i]]));
    }

    return mst;
}

void __fastcall TForm2::Button2Click(TObject *Sender)
{
	PageControl1->ActivePage = TabSheet2;
	int n = StrToInt(Edit1->Text);
	int range = StrToInt(Edit2->Text);
	int valueIfGreater = StrToInt(Edit3->Text); // 大於值
	int valueIfEqual = StrToInt(Edit4->Text); // 大於valueIfGreater替代值

	ClearWeights();
	// 填充陣列
	FillWeightMatrix(n, range, valueIfGreater, valueIfEqual);
	StringGrid1->RowCount = 0;
	StringGrid1->ColCount = 0;

	if (CheckBox2->Checked) {
		// 設置 StringGrid 的行列數
		StringGrid1->RowCount = n ;
		StringGrid1->ColCount = n ;
		// 將G的值填入 StringGrid
		for (int i = 0; i < arraySize; ++i) {
			for (int j = 0; j < arraySize; ++j) {
				if (weights[j][i] > valueIfGreater) {
					weights[j][i] = valueIfEqual;
				}
				StringGrid1->Cells[j][i] = IntToStr(weights[i][j]);
			}
		}
	}
}

void __fastcall TForm2::Button1Click(TObject *Sender)
{
	PageControl1->ActivePage = TabSheet2;
	string filename = "input.txt";
	LoadFromFile(filename);

	// 設置StringGrid1
	StringGrid1->RowCount = arraySize + 1;
	StringGrid1->ColCount = arraySize + 1;

	// 填充StringGrid1
	for (int i = 0; i < arraySize; ++i) {
		for (int j = 0; j < arraySize; ++j) {
			StringGrid1->Cells[j + 1][i + 1] = IntToStr(weights[i][j]);
		}
	}

	for (int i = 0; i < arraySize; ++i) {
		StringGrid1->Cells[0][i + 1] = IntToStr(i);
		StringGrid1->Cells[i + 1][0] = IntToStr(i);
	}
}

void __fastcall TForm2::Button3Click(TObject *Sender)
{
    PageControl1->ActivePage = TabSheet4;
    bool useUnionFind = RadioButton2->Checked; // RadioButton2 表示使用 Union-Find
    std::vector<Edge> edges;
    for (int i = 0; i < arraySize; ++i) {
        for (int j = i + 1; j < arraySize; ++j) {
            if (weights[i][j] != 0 && weights[i][j] != INF) {
                edges.push_back(Edge(i, j, weights[i][j]));
            }
        }
    }

    clock_t start = clock(); // 開始計時
	std::vector<Edge> mst = KruskalMST(arraySize, edges, useUnionFind);
    clock_t end = clock(); // 結束計時
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    StringGrid2->RowCount = mst.size() + 1;
    StringGrid2->ColCount = 3;
    StringGrid2->Cells[0][0] = "Src";
    StringGrid2->Cells[1][0] = "Dest";
    StringGrid2->Cells[2][0] = "Weight";

    Memo2->Lines->Add("Kruskal:");
    for (size_t i = 0; i < mst.size(); ++i) {
        StringGrid2->Cells[0][i + 1] = IntToStr((int)mst[i].src);
        StringGrid2->Cells[1][i + 1] = IntToStr((int)mst[i].dest);
        StringGrid2->Cells[2][i + 1] = IntToStr((int)mst[i].weight);
        Memo2->Lines->Add("edge " + IntToStr((int)i) + ": (" + IntToStr((int)mst[i].src) + ", " + IntToStr((int)mst[i].dest) + ") [" + IntToStr((int)mst[i].weight) + "]");
    }
    Memo2->Lines->Add("Kruskal: " + FloatToStr(cpu_time_used) + " (sec.)");
}

void __fastcall TForm2::Button4Click(TObject *Sender)
{
    PageControl1->ActivePage = TabSheet4;

    clock_t start = clock(); // 開始計時
    std::vector<Edge> mst = PrimMST(arraySize, weights);
    clock_t end = clock(); // 結束計時
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    StringGrid2->RowCount = mst.size() + 1;
    StringGrid2->ColCount = 3;
    StringGrid2->Cells[0][0] = "Src";
    StringGrid2->Cells[1][0] = "Dest";
    StringGrid2->Cells[2][0] = "Weight";

    Memo2->Lines->Add("Prim:");
    for (size_t i = 0; i < mst.size(); ++i) {
        StringGrid2->Cells[0][i + 1] = IntToStr((int)mst[i].src);
        StringGrid2->Cells[1][i + 1] = IntToStr((int)mst[i].dest);
        StringGrid2->Cells[2][i + 1] = IntToStr((int)mst[i].weight);
        Memo2->Lines->Add("edge " + IntToStr((int)i) + ": (" + IntToStr((int)mst[i].src) + ", " + IntToStr((int)mst[i].dest) + ") [" + IntToStr((int)mst[i].weight) + "]");
    }
    Memo2->Lines->Add("Prim: " + FloatToStr(cpu_time_used) + " (sec.)");
}
//---------------------------------------------------------------------------

