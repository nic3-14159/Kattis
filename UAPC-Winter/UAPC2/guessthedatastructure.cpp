#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(){
    int cmds, op, x;
    queue<int> a;
    stack<int> b;
    priority_queue<int> c;
    //bit-field: isQueue, isStack, isPriQueue
    short identity = 0;
    while (cin >> cmds){
        identity = 0b111;
        while (cmds--){
            cin >> op >> x;
            if (op == 1){
                a.push(x);
                b.push(x);
                c.push(x);
            } else {
                if (a.empty()){
                    identity = 0;
                    while (cmds--){
                        cin >> op >> x;
                    }
                    break;
                }
                if (a.front() != x)
                    identity &= 0b011;
                if (b.top() != x)
                    identity &= 0b101;
                if (c.top() != x)
                    identity &= 0b110;
                a.pop();
                b.pop();
                c.pop();
            }
        }
        switch (identity){
        case 0:
            cout << "impossible" << endl;
            break;
        case 0b100:
            cout << "queue" << endl;
            break;
        case 0b010:
            cout << "stack" << endl;
            break;
        case 0b001:
            cout << "priority queue" << endl;
            break;
        default:
            cout << "not sure" << endl;
        }
        a = queue<int>();
        b = stack<int>();
        c = priority_queue<int>();
    }
    return 0;
}
