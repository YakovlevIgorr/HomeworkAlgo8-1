#include <iostream>
#include <fstream>


void open(int* array[], int size_array){

    std::ifstream input;
    input.open("input.txt");
    if(input) {
        input.seekg(2, std::ios_base::beg);
        for (int i = 0; i < size_array; i++) {
            for (int k = 0; k < size_array; k++) {
                input >> array[i][k];
            }
        }
    }else std::cout << "Error open file";

}

void deep(int* array[], int size_array){
    int count = 0;
    for(int i = 0; i < size_array; i++){
        for(int k = 0; k < size_array; k++){
            if(array[i][k] == 1){
                array[i][k] = 0;
                array[i][count] = k + 1;
                count++;
            }
        }
        count = 0;
    }


}


void print_array(int* array[], int size){
    std::cout << "Текстовый вид орграфа: \n";
    for(int i = 0; i < size; i++){
        std::cout << i + 1 << ": ";

        if(array[i][0] != 0) {
            for (int k = 0; k < size; k++) {
                if (array[i][k] > 0) {
                    std::cout << array[i][k] << " ";
                }
            }
        }else std::cout << "нет";
        std::cout << "\n";
    }
}

int main() {
    int size_array;
    std::ifstream input;
    input.open("input.txt");
    input >> size_array;


    int** array = new int*[size_array];


    for(int i = 0; i < size_array; i++) {
        array[i] = new int[size_array];
    }

    open(array, size_array);

    //fill(array_count, size_array);
    deep(array, size_array);
    print_array(array,size_array);
    //print(array, size_array);

    for(int i = 0; i < size_array; i++){
        delete[] array[i];
    }
    delete[] array;

    return 0;
}