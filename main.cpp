#include <iostream>
#include<vector>
#include<numeric>
#include<iterator>
#include<algorithm>
#include<string>
#include<fstream>

using namespace std;


int main()
{
    // EXERCISE 2
    // creating vector
    vector<char> alphabet(26);
    vector<string> carBrands;

    // put letters from a to z inside
    iota(alphabet.begin(),alphabet.end(),'a');

    cout << "Exercices 2.1" << endl;
    // print forward
    std::ostream_iterator<char> out_it (std::cout,", ");
    std::copy ( alphabet.begin(), alphabet.end(), out_it );
    std::cout<< endl;
    // print backward
    std::reverse_copy(alphabet.begin(),alphabet.end(),out_it);



    // Read the file

    ifstream carsFile;
    string inputString;
    carsFile.open("cars.txt");

    while(carsFile>>inputString) //reads one string at a time
        carBrands.push_back(inputString); //add it to data vector
    carsFile.close();

    // sort and then print
    cout<<"\nExercise 2.2" << endl;
    std::sort(carBrands.begin(),carBrands.end());
    ostream_iterator<string> out_it2 (cout,"\n");
    std::copy(carBrands.begin(),carBrands.end(),out_it2);

    // print only car brands which begins with a certain letter

    char TheLetter = 'B'; // Please, choose the first letter

    // First way
    cout << "\n Exercise 2.3 a)" << endl;
    for (auto it = carBrands.cbegin(); it != carBrands.cend(); ++it)
    {
        string condition = *it;
        if(condition[0] == TheLetter){cout << condition << endl;}

    }

    // Second way
    cout << "\n Exercise 2.3 b)" << endl;
    for (const auto& car : carBrands)
    {
        string condition = car;

        if(condition[0] == TheLetter){cout<<car<<endl;}

    }

    // Two predicate using copy_if
    cout << "\n Exercices 2.4" << endl;

    std::ostream_iterator<string> out_it3 (cout,"\n");
    std::copy_if(carBrands.begin(),carBrands.end(),out_it3,[](string x)
    {
        string condition = "ABC";
        bool resultTest = false;
        if(condition[0] == x[0] | condition[1] == x[0] | condition[2] == x[0])
        {

            resultTest = true;
        }

        return resultTest;

    });

    // EXERCISE 3

    std::vector<string> words;
    std::string inputs;

    cout<< "please enter some text" << endl;
    while(cin >> inputs)
    {
        words.push_back(inputs);

    }

    // Create the unique words list

    std::unique(words.begin(),words.end());

    // verify if the text is saved into vector words
    std::ostream_iterator<string> out_it4 (cout,"\n");
    std::copy(words.begin(),words.end(),out_it4);

    return 0;
}
