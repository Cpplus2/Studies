#include <iostream>
#include "SortedList.h"

using namespace std;

int main()
{
    cout << "This program computes following basic set operations. " << endl;

    cout << "What operation would you like to perform? (U) Union (I) Intersection (D) Set difference (C) Complement" << endl;
    cout << "Enter your choice: ";
    char choice;
    cin >> choice;

    cout << endl;

    cout << "You're calculating for A";
    switch(choice)
    {
        case 'U':
            cout << " union B" << endl;
            break;

        case 'I':
            cout << " intersection B" << endl;
            break;

        case 'D':
            cout << " - B" << endl;
            break;

        case 'C':
            cout << "'" << endl;
            break;
    }

    int num, count;    //temporary element holder
    int ** sets = new int *[2];    //Resultant set

    cout << endl << "Set A: " << endl;
    cout << "Enter the number of values in the first set: ";
    int cardinality;
    cin >> cardinality;

    for(count = 0; count < cardinality; count++)
    {
        cout << "Enter element#" << count+1 << ": ";
        cin >> num;

        sets[0][count] = num;
    }

    int cardinalityToo;
    if(choice != 'C')
    {
        cout << endl << "Set B: " << endl;
        cout << "Enter the number of values in the second set: ";
        cin >> cardinalityToo;

        for (count = 0; count < cardinalityToo; count++)
        {
            cout << "Enter element#" << count+1 << ": ";
            cin >> num;
            sets[1][count];
        }
    }

    int counter, counting, ct = 0;
    SortedList resultant;
    cout << "error here? " << endl;

    switch(choice)
    {
        case 'U':
            cout << "A union B = ";

            for(counting = 0; counting < cardinality; counting++)
            {
                bool inexistence = true;
                for(int countingToo = 0; countingToo < cardinalityToo; countingToo++)
                {
                    if(sets[0][counting] == sets[1][countingToo])
                    {
                        inexistence = false;
                        break;
                    }
                }
                if(inexistence)
                    resultant.InsertItem(sets[0][counting]);
            }

            counting = 0;
            cout << "{" << resultant.GetNextItem();
            while(!resultant.IsEmpty())
                cout << "," << resultant.GetNextItem();

            cout << "}" << endl;

            break;

        case 'I':
            cout << "A intersection B = ";
            ct = 0;

            for(count = 0; count < cardinality; count++)
                for(counting = 0; counting < cardinalityToo; counting++)
                    if(sets[0][count] == sets[1][counting])
                       resultant.InsertItem(sets[0][counting]);

            cout << "{" << resultant.GetNextItem();

            while(resultant.IsEmpty())
                cout << "," << resultant.GetNextItem();

            cout << "}" << endl;

            break;

        case 'D':

            break;

        case 'C':
            resultant = SortedList();

            cout << "A' = {" << resultant.GetNextItem();

            cout << endl << cardinality << endl;

            for(count = 0; count < 10; count++)
                if(count == resultant.GetNextItem())
                    cout << "," << count;

            cout << "}" << endl;

            cout << "\b}" << endl;

            break;

        default:
            cout << "Sorry! There is an error in your choice of input. " << endl;
    }

    cout << endl << "Thank you for your using this program. " << endl;

    return 0;
}
