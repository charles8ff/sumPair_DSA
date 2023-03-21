#include <iostream>
#include <vector>
#include <sstream>

#include <chrono>
#include <locale>

using namespace std;
using namespace std::chrono;

// static double suma_under_test( const unsigned long n ) {
//     auto t_start = std::chrono::high_resolution_clock::now();
//     suma(n);
//     auto t_end = std::chrono::high_resolution_clock::now();
//     return std::chrono::duration<double, std::milli>(t_end-t_start).count();
// }
int main() {
    // static long MAX = 1000000000;
    // static long REPS = 25;
    // double elapsed_time_ms;

    // struct custom_locale : std::numpunct<char> {
    //     char_type do_decimal_point() const override { return ','; } // Separador decimal
    // };

    // custom_locale my_locale;
    // std::cout.imbue(std::locale(std::cout.getloc(), &my_locale));

    // for( int i=100; i<MAX; i=i*10){
    //     std::vector<double> vec;
    //     for( int j=0; j< REPS; j++ ){
    //         vec.push_back( suma_under_test( i ) );
    //     }
    //     elapsed_time_ms = std::accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
    //     cout << i << ' ' << elapsed_time_ms << endl;
    // }

    cout << "Enter the vector elements separated by spaces: ";
    string line;
    getline(cin, line);
    istringstream iss(line);

    vector<int> vec;
    int element;
    while (iss >> element) {
        vec.push_back(element);
    }

    int count = 0;

    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = i + 1; j < vec.size(); ++j) {
            if (vec[i] + vec[j] == 0) {
                cout << "Pair: (" << vec[i] << ", " << vec[j] << ")" << endl;
                count++;
            }
        }
    }

    cout << "Number of pairs with sum 0: " << count << endl;


    return 0;
}
