#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    string str;
    int length;
    int main_ptr = 0;   // 문자열을 처리할 메인 카운터
    int sub_ptr = 0;    // 메인 카운터를 도와서 단어 출력을 해줄 보조 카운터
    
    getline(cin, str);
    length = str.length();

    while (main_ptr < length) {
        if (str[main_ptr] == '<') {   // tag open
            sub_ptr = main_ptr;
            while (str[sub_ptr] != '>') {     // close tag를 만나기 전까지 모두 출력
                cout << str[sub_ptr++];
            }
            cout << str[sub_ptr++];     // 남아있는 close tag를 출력
            // 이제 sub_ptr은 close tag의 바로 다음 element를 가리킴.
            main_ptr = sub_ptr;
        } else if (str[main_ptr] == ' ') {   // 공백일 때
            cout << ' ';    // 공백 출력
            main_ptr++;
        } else {    // 태그, 공백이 둘 다 아닐 때 : 단어의 시작 문자
            // 단어의 끝까지 일단 sub_ptr을 이동, 해당 index를 저장한 후 거꾸로 출력
            sub_ptr = main_ptr;
            while (sub_ptr < length && str[sub_ptr] != ' ' && str[sub_ptr] != '<') {
                sub_ptr++;  // 이제 sub_ptr은 단어의 끝 index + 1을 가리킴
            }
            int temp_end = sub_ptr - 1;     // 단어의 끝 index를 따로 저장
            for (int i = temp_end; i >= main_ptr; i--) {
                cout << str[i];
            }
            main_ptr = temp_end + 1;    // 메인 포인터를 단어의 끝 index + 1로 업데이트
            // cout << "main_ptr : " << main_ptr << "\n";
        }
    }


    return 0;
}