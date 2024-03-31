#include<bits/stdc++.h>
using namespace std;
string op1, op2;
vector<int> blocks[30]; // ��ά����洢������
map<int, pair<int,int> > pos; // �洢ÿ����Ŷ�Ӧλ��
int n, a, b;
void showResult() { // ��ӡ���
    for (int i = 0; i < n; i ++) {
        printf("%d:", i); // ������ӡ�ո�
        for (auto p : blocks[i]) printf(" %d", p);
        puts("");
    }
}
void clear(int a) { // ��a����Ķ���λ��������a��
    int ia = pos[a].first, j = pos[a].second + 1;
    for (; j < blocks[ia].size(); j ++) { // ���ǲ��뵱ǰ��
        int k = blocks[ia][j]; // Ҫɾ����ֵ
        blocks[k].push_back(k); // ��λ
        pos[k].first = k; pos[k].second = blocks[k].size()-1; // ����λ��
    }
    blocks[ia].erase(blocks[ia].begin()+pos[a].second+1, blocks[ia].end()); // ���һ��ɾ��
}
void move(int a, int b) { // ��a��������ķ���ȫ�Ƶ�����b��������
    int ia = pos[a].first, left = pos[a].second, ib = pos[b].first;
    for (int j = left; j < blocks[ia].size(); j ++) { // ��ʼ����
        blocks[ib].push_back(blocks[ia][j]); // ����b��������β��
        pos[blocks[ia][j]].first = ib; // λ�ø���
        pos[blocks[ia][j]].second = blocks[ib].size()-1;
    }
    blocks[ia].erase(blocks[ia].begin()+left, blocks[ia].end()); // һ��ɾ��
}
int main() {
    cin >>n;
    for (int i = 0; i < n; i ++) {
        blocks[i].push_back(i);
        pos[i] = {i,0}; // ����ֵλ��
    }
    while (cin >>op1 && op1 != "quit") {
        cin >>a >>op2 >>b;
        if (pos[a].first == pos[b].first) continue; // ͬһ��λ��
        if (op1 == "move") clear(a);
        if (op2 == "onto") clear(b);
        move(a,b);
    }
    showResult();
    return 0;
}
