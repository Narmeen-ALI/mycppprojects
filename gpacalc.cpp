#include <iostream>
using namespace std;
int main() {
    cout << "---------WELCOME TO GPA CALCULATOR ;)---------" << endl;
    int courses;
    cout << "Enter number of courses: ";
    cin >> courses;

    char grade, sign;
    float hr;
    float grade_point;
    float sum_hr = 0.0;
    float sum_gradepoints = 0.0;

    for (int i = 1; i <= courses; i++) {
        cout << "Enter GRADE and Credit Hour of Course " << i << " (e.g., A- 3.0): ";
        cin >> grade >> sign >> hr;

        switch (grade) {
            case 'A': grade_point = 4.0; break;
            case 'B': grade_point = 3.0; break;
            case 'C': grade_point = 2.0; break;
            case 'D': grade_point = 1.0; break;
            case 'F': grade_point = 0.0; break;
            default:
                grade_point = 0.0; 
        }

        if (sign == '+') {
            if (grade != 'A' && grade != 'F') {
  grade_point += 0.3;
   }
        } else if (sign == '-') {
    if (grade != 'F') {
   grade_point -= 0.3;
            }
        }
        sum_hr += hr;
        sum_gradepoints += grade_point * hr;
    }

    float cgpa = sum_gradepoints / sum_hr;
  cout << "\n--------- GPA RESULT ---------\n";
    cout << "Total Credit Hours = " << sum_hr << endl;
   cout << "Total Grade Points = " << sum_gradepoints << endl;
    cout << "GPA = " << cgpa << endl;
    return 0;
}
