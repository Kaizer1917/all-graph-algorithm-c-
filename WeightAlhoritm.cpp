#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>

using namespace std;
bool bfs(int **graph, int n, int m, int to, int* visited, list<int> &buffer, int* parents);
void print_path(int from, int to, int* parents, ofstream& ofst);

int main() {
    setlocale(LC_ALL, "rus");
    char filenamein[] = "in.txt";
    char filenameout[] = "out.txt";

    ifstream fin(filenamein);
    ofstream fout(filenameout);
    if (!fin || !fout) {
        cout << "ошибка при открытие файла\n";
        system("pause");
        return 1;
    }

    int n, m;
    fin >> n >> m;
    int from, to;
    fin >> from >> to;
    from--; to--;

    int** graph = new int* [n];
    int* visited = new int[n];
    int* parents = new int[n];

    for (int i = 0; i < n; i++) {
        graph[i] = new int[m];
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            graph[i][j] = 0;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        fin >> a >> b;
        graph[a - 1][i] = graph[b - 1][i] = 1;
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    list<int> buffer;
    buffer.push_back(from);

    if (false == bfs(graph, n, m, to, visited, buffer, parents)) {
        fout << "path does not exist" << endl;
    }
    else {
        print_path(from, to, parents, fout);
    }


    for (int i = 0; i < n; i++)
        delete[] graph[i];

    delete[] graph;
    delete[] visited;
    delete[] parents;

    fin.close();
    fout.close();
}

bool bfs(int **graph, int n, int m, int to, int* visited, list<int>& buffer, int* parents) {
    if (buffer.empty())
        return false;

    int from = buffer.front();
    buffer.pop_front();

    visited[from] = true;

    if (from == to) {
        return true;
    }

    for (int i = 0; i < m; ++i) {
        if (graph[from][i] == 0)
            continue;
        // i-тая дуга инцидентна вершине,
        // надо найти вторую вершину инцидентную I-той дуге
        int node;
        for (node = 0; node < n; ++node) {
            if (node != from && graph[node][i] != 0)
                break;
        }
        if (visited[node] == true)
            continue;
        if (find(buffer.begin(), buffer.end(), node) != buffer.end())
            continue;
        parents[node] = from;
        buffer.push_back(node);
    }

    return bfs(graph, n, m, to, visited, buffer, parents);
}

void print_path(int from, int to, int* parents, ofstream& ofst) {
    if (to == from) {
        ofst << to+1;
        return;
    }
    int prefrom = parents[to];
    print_path(from, prefrom, parents, ofst);

    ofst << " -> " << to+1;
}