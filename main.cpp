#include <iostream>
#include <vector>
#include <sstream>

#include <chrono>
#include <locale>
#include <numeric>

using namespace std;
using namespace std::chrono;


void sumPair(const vector<int> myInput){

    int count = 0;

    for (size_t i = 0; i < myInput.size(); ++i) {
        for (size_t j = i + 1; j < myInput.size(); ++j) {
            if (myInput[i] + myInput[j] == 0) {
                cout << "Pair: (" << myInput[i] << ", " << myInput[j] << ")" << endl;
                count++;
            }
        }
    }
    cout << "Number of pairs with sum 0: " << count << endl;
}

static double sumPair_under_test( const vector<int> myInput ) {
    auto t_start = high_resolution_clock::now();
    sumPair(myInput);
    auto t_end = high_resolution_clock::now();
    return duration<double, milli>(t_end-t_start).count();
}

int main() {

    static long MAX = 1000000000;
    static long REPS = 25;
    double elapsed_time_ms;

    struct custom_locale : numpunct<char> {
        char_type do_decimal_point() const override { return ','; } // Separador decimal
    };
    custom_locale my_locale;
    cout.imbue(locale(cout.getloc(), &my_locale));

    // USER PROMPTS:
    cout << "Enter the vector elements separated by spaces: ";
    string line;
    getline(cin, line);
    istringstream iss(line);

    // ISS TO VECTOR
    vector<int> myInput;
    int element;
    while (iss >> element) {
        myInput.push_back(element);
    }
    // END OF USER PROMPT
    for( int i=100; i<MAX; i=i*10){
        vector<double> vec;
        for( int j=0; j< REPS; j++ ){
            vec.push_back( sumPair_under_test(myInput) );
        }
        elapsed_time_ms = accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
        cout<<"Timestamps: "<< endl;
        cout << i << ' ' << elapsed_time_ms << endl;
    }

    return 0;
}
