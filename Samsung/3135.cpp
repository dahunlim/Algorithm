// 3135. 홍준이의 사전놀이
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
typedef struct node { node* child[26]; int cnt; int word;} node;
node* root;
extern void init(void) {
    root = (node *) malloc(sizeof(node));
    for(int i=0; i<26; i++) {
        if (root -> child[i]) root -> child[i] = 0;
    }
    root -> word = 0, root -> cnt = 0;
};

extern void insert(int buffer_size, char *buf){
    node* now = root;
    for(int i=0; i<buffer_size; i++) {
        if(!(now -> child[buf[i]-'a'])) { // 아직 존재하지 않을 때
            now -> child[buf[i]-'a'] = (node *)malloc (sizeof(node));

            now = now -> child[buf[i]-'a'];
            now->word = 0, now->cnt = 0;
            for(int j=0; j<26; j++) now -> child[j] = 0; //초기화
        }
        else now = now -> child[buf[i]-'a']; // 존재할때 root 를 child 로 바꿔줌

        now -> cnt++; // 자식의 갯수 count
    }
    now -> word = 1; // 글자의 끝 표시
};

extern int query(int buffer_size, char *buf) {
    node* now = root;
    for(int i=0; i<buffer_size; i++) {
        if(now -> child[buf[i]-'a']) {
            now = now -> child[buf[i] - 'a'];
        }
        else return 0;
    }
    //탐색이 끝나고의 now 는 검색하는 단어
    int ret = now -> cnt;
    return ret;
};

int main(void) {
	//freopen("input.txt", "r", stdin);
	int TestCase; 
	for (scanf("%d", &TestCase); TestCase--;) {
		int Query_N;
		scanf("%d", &Query_N);
		
		init();
		
		static int tc = 0;
		printf("#%d", ++tc);
		
		for (int i = 1; i <= Query_N; i++) {
			int type; scanf("%d", &type);

			if (type == 1) {
				char buf[15] = { 0, };
				scanf("%s", buf);
				
				int buffer_size = 0;
				while (buf[buffer_size]) buffer_size++;
				
				insert(buffer_size, buf);
			}
			else {
				char buf[15] = { 0, };
				scanf("%s", buf);
				
				int buffer_size = 0;
				while (buf[buffer_size]) buffer_size++;

				printf(" %d", query(buffer_size, buf));
			}
		}
		printf("\n");
		fflush(stdout);
	}
}