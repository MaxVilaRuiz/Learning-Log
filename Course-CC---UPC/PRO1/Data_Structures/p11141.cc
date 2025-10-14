#include <iostream>
#include <vector>
using namespace std;

struct Student {
    int idn;
    string name;
    double mark;       
    bool repeater;
};

void information(const vector<Student>& stu, double& min,
                 double& max, double& avg) {
    int i = 0;
    int sz = stu.size();
    while(i < sz and (stu[i].repeater or stu[i].mark < 0)) i++;
    if (i == sz)
        min = max = avg = -1.0;
    else {
        min = max = avg = stu[i].mark;
        int num = 1;
        for (i = i+1; i < sz; i++) {
            if (not stu[i].repeater) {
                double m = stu[i].mark;
                if (-1.0 < m) {
                    num++;
                    avg += m;
                    if (m < min) min = m;
                    else if (max < m) max = m;
                }
            }
        }
        avg = avg / num;
    }

    // Alternative:
    // int count = 0;
    // for (int i = 0; i < stu.size(); i++) {
    //     if (not stu[i].repeater and stu[i].mark != -1) {
    //         count++;
    //         avg += stu[i].mark;
    //         if (stu[i].mark > max)
    //             max = stu[i].mark;
    //         else if (stu[i].mark < min)
    //             min = stu[i].mark;
    //     }
    // }
    // if (count == 0) {
    //     min = -1;
    //     max = -1;
    //     avg = -1;
    // }
    // else avg /= count;
}

int main() {
    vector<Student> stu;
    for (int i = 0; i < 5; i++) {
        cin >> stu[i].idn;
        cin >> stu[i].name;
        cin >> stu[i].mark;
        cin >> stu[i].repeater;
    }

    double min = 10, max = 0, avg = 0;
    information(stu, min, max, avg);
    cout << min << ' ' << max << ' ' << avg << endl;
}