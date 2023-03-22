# sumPair_DSA

T(n): n^2 + 7


    void sumPair(const vector<int> myInput){

        int count = 0;

        for (size_t i = 0; i < myInput.size(); ++i) {
            for (size_t j = i + 1; j < myInput.size(); ++j)     {
                if (myInput[i] + myInput[j] == 0) {
                    cout << "Pair: (" << myInput[i]  << ", " << myInput[j] << ")" << endl;
                   count++;
               }
            }
        }
        cout << "Number of pairs with sum 0: " << count <<  endl;
    }


Ambos bucles _for_ anidados proporcionan una complejidad de n^2 y el resto es computacionalmente despreciable, por lo que nuestro orden es de O = n^2