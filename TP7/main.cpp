#include <iostream>
#include "Point.h"
#define boolToString(b) (b ? "true" : "false")
#include <string>
#include <cctype>
#include <map>
#include <algorithm>
#include <numeric>

using std::cout;
using namespace std;

void pointTests(){
    pointTest<int>();
    pointTest<float>();
}

template <class T> void printVector(vector<T> numbers){
    cout << "[";
    for (auto i = numbers.begin(); i != numbers.end(); i++){
        cout << *i;
        if (i != numbers.end()-1){
            cout << ",";
        }
    }
    cout << "]";
}

void printNumbers(){
    vector<int> numbers = {1,2,3};
    printVector(numbers);
}

void printLetters(){
    vector<char> letters = {'A', 'B', 'C'};
    printVector(letters);
}

bool isNumber(string s){
    for (auto i = 0; s[i] != '\0'; i++){
        if (!isdigit(s[i])){
            return false;
        }
    }
    return true;
}

void isNumberTests(){
    cout << boolToString( isNumber("1") )<< endl;
    cout << boolToString( isNumber("42") ) << endl;
    cout << boolToString( isNumber("6PO") ) << endl;
    cout << boolToString( isNumber("R2D2") ) << endl;
}

void keepNumbersOnly(vector<string>& v){
    for (auto i = v.begin(); i != v.end(); i++){
        for (auto j = 0; (*i)[j] != '\0'; j++) {
            if (!isdigit((*i)[j])) {
                v.erase(i);
                i--;
                break;
            }
        }
    }
}

void filterVectorTest(){
    vector<string> values = {"Z", "1", "A", "42", "E", "G", "0"};
    keepNumbersOnly(values);
    printVector(values);
}

vector<string> splitString(string a, string b) {
    vector<string> result;
    auto split = b[0];
    string temp;
    for (auto i = 0; a[i] != '\0'; i++) {
        if (a[i] == split) {
            result.push_back(temp);
            temp = "";
        }
        else {
            temp += a[i];
        }
    }
    return result;
}

void splitTests(){
    vector<string> operators = splitString("+ - / =");
    printVector(operators);

    vector<string> numbers = splitString("1,2,3,4,5", ",");
    printVector(numbers);

    vector<string> letters = splitString("A-B-C-D", "-");
    printVector(letters);
}

void printAges(){
    map</*name*/string, /*age*/unsigned short> ages = {
            { "Emma", 30 },
            { "Manon", 19 },
            { "Sacha", 45 }
    };

    printMap(ages);
}

template <class T1, class T2> void printMap(map<T1, T2> m) {
    for (const pair<T1, T2> p : m) {
        cout << p.first << " -> " << p.second << "\n";
    }
}

void printMapTests(){
    printAges();
    cout << "---" << endl;
    printRights();
}

void printRights(){
    map</*userId*/int, /*rights*/int> userRights = {
            { 254756, 666 },
            { 4587, 644 },
            { 58714, 777 }
    };
    printMap(userRights);
}

void filterMapTest(){
    map</*name*/string, /*male*/bool> genders = {
            { "Emma", false } ,
            { "Manon", false } ,
            { "Sacha", true } ,
            { "Ambre", false } ,
            { "Gabin", true } ,
            { "Paul", true }
    };
    keepMalesOnly(genders);
    printMap(genders);
}

void keepMalesOnly(map<string, bool> &m) {
    for (auto i = m.begin(); i != m.end(); i++){
        if (!i->second){
            m.erase(i);
        }
    }
}

void splitMapTest(){
    map</*name*/string, /*male*/bool> genders = {
            { "Emma", false } ,
            { "Manon", false } ,
            { "Sacha", true } ,
            { "Ambre", false } ,
            { "Gabin", true } ,
            { "Paul", true }
    };
    vector<string> males;
    vector<string> females;
    splitOnGender(genders, males, females);
    printMap(genders);
    cout << "---" << endl;
    printVector(males);
    printVector(females);
}

void splitOnGender(map<string, bool> genders, vector<string> &males, vector<string> &females){ // todo question ordre alphabétique et flèches
    for (auto i = genders.begin(); i != genders.end(); i++){
        if (i->second){
            males.push_back(i->first);
        }
        else {
            females.push_back(i->first);
        }
    }
}

void statsTest(){
    vector<int> values = {1, 42, -3, 6, 12, 404};
    map<string, float> statistics = computeStatistics(values);
    printMap(statistics);
}

map<string, float> computeStatistics(vector<int> v) {
    float avg = 0;
    float min = *(v.begin());
    float max = *(v.begin());
    int j = 0;
    for (auto i = v.begin(); i != v.end(); i++){
        avg += *i;
        j++;
        if (*i < min){
            min = *i;
        }
        if (*i > max){
            max = *i;
        }
    }
    avg /= j;
    return {
            {"average", avg},
            {"min", min},
            {"max", max},
    };
}

void statsTest2(){
    vector<int> values = {1, 42, -3, 6, 12, 404};
    map<string, float> statistics = computeStatistics2(values);
    printMap(statistics);
}

map<string, float> computeStatistics2(vector<int> v) {
    return {
            {"average", accumulate(v.begin(), v.end(), 0) / v.size()}, // todo prob
            {"min", *min_element(v.begin(), v.end())},
            {"max", *max_element(v.begin(), v.end())},
    };
}

int main() {
    cout << "---------------------------------\n";
    pointTests();
    cout << "---------------------------------\n";
    printNumbers();
    cout << "\n---------------------------------\n";
    printLetters();
    cout << "\n---------------------------------\n";
    isNumberTests();
    cout << "---------------------------------\n";
    filterVectorTest();
    cout << "\n---------------------------------\n";
    splitTests();
    cout << "\n---------------------------------\n";
    printAges();
    cout << "---------------------------------\n";
    printMapTests();
    cout << "---------------------------------\n";
    filterMapTest();
    cout << "---------------------------------\n";
    splitMapTest();
    cout << "\n---------------------------------\n";
    statsTest();
    cout << "---------------------------------\n";
    statsTest2();
    cout << "---------------------------------";
    return 0;
}