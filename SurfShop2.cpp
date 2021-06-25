// SurfShop.cpp : This program tracks purchases and totals of surfboards from sizes small medium and large.
// This program also runs a loop till the user selects Q and also has a menu to show the user how to use the program.
// Tim Cutts  Programing assignment Week 5  ITCS 2530  Modified to include xsmall boards for github submission

#include <iostream> //to use input and outputs
#include <iomanip> //to use formatting tools


using namespace std; //to not have to type std:: 



void ShowUsage() //function to display the menu to the user
{
    cout << "To show program usage press 'S'" << endl;
    cout << "To purchase a surfboard press 'P'" << endl;
    cout << "To display current purchases press 'C'" << endl;
    cout << "To display total amount due press 'T'" << endl;
    cout << "To quit the program press 'Q'" << endl;
}
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int&iTotalLarge, int&iTotalXSmall) //function to make a purchase from the surfshop while referencing the iTotalSmall, Medium, Large variables
{
    int quanity; //variables for the quanity and size selection of what boards to purchase
    char size;


    cout << "Please enter the quanity and type (X=extra small, S=small, M=medium, L=large) of surfboard you"; //output and input for the user to select what size and quanity they want
    cout << " would like to purchase: ";
    cin >> quanity;
    cin >> size;
    cout << endl;

    switch (size) //switch selection for the size
     {
        case 'x':
        case 'X':
            
            iTotalXSmall = iTotalXSmall + quanity;  //if the user types x or X then it increases the total extra small boards by the quanity the user selected
            break; //breaks out of switch
        case 's':
        case 'S':
            
            iTotalSmall = iTotalSmall + quanity;  //if the user types s or S then it increases the total small boards by the quanity the user selected
            break; //breaks out of switch
        case 'm':
        case 'M':
            
            iTotalMedium = iTotalMedium + quanity; //if the user types m or M then it increases the total medium boards by the quanity the user selected
            break; //breaks out of switch
        case 'l':
        case 'L':
            
            iTotalLarge = iTotalLarge + quanity; //if the user types l or L then it increases the total large boards by the quanity the user selected
            break; //breaks out of switch

        default:
            
            cout << "Wrong size selection" << endl; //if the user types in anything outside of s, S, m, M, l, or L the switch defaults here and outputs wrong size selection.
     }
    
}
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXSmall) //function to display purchases made and using the iTotalSmall, Medium, Large variables
{
    if (iTotalSmall > 0) //if structure to check if the number of small boards are greater than 0
        cout << "The number of small surfboards is " << iTotalSmall << endl; //output the total number of small boards

    if (iTotalMedium > 0) //if structure to check if the number of medium boards are greater than 0
        cout << "The number of medium surfboards is " << iTotalMedium << endl; //output the total number of medium boards

    if (iTotalLarge > 0) //if structure to check if the number of large boards are greater than 0
        cout << "The number of large surfboards is " << iTotalLarge << endl; //output the total number of large boards

    if (iTotalXSmall > 0) //if structure to check if the number of small boards are greater than 0
        cout << "The number of small surfboards is " << iTotalXSmall << endl; //output the total number of small boards

    if (iTotalLarge == 0 && iTotalMedium == 0 && iTotalSmall == 0 && iTotalXSmall == 0) //if structure if all totals are 0 to output no purchases made yet.
        cout << "No purchases made yet.";

}

void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXSmall) //function to display the total for the # of boards sold and total cost while using the iTotalSmall, Medium, Large variables
{
    const double SmallPrice = 175; //constant variables for the surfboard prices depending on the size
    const double MedPrice = 190;
    const double LargePrice = 200;
    const double XSmallPrice = 75;

    double smalltotal = 0; //variables to keep track of the total price of each size of surfboard
    double medtotal = 0; //set to zero for if structure
    double largetotal = 0;
    double xsmalltotal = 0;

    smalltotal = iTotalSmall * SmallPrice + smalltotal;  // these following lines calculate the total price for the surfboards purchased by using the iTotalSmall, Medium, Large variables
    medtotal = iTotalMedium * MedPrice + medtotal; //adding the total variables (exp; medtotal) to these lines to help track price for further purchases
    largetotal = iTotalLarge * LargePrice + largetotal;
    xsmalltotal = iTotalXSmall * XSmallPrice + xsmalltotal;

    cout << fixed << showpoint << setprecision(2);  //sets the decimal point to show at 2 spaces

    if (smalltotal > 0) //if structure to check if the total costs are greater than zero
        cout << "The total number of small surfboards is " << iTotalSmall << " at a total of $" << smalltotal << endl; //displays the count total and cost total to the user

    if (medtotal > 0) //if structure to check if the total costs are greater than zero
        cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of $" << medtotal << endl; //displays the count total and cost total to the user

    if (largetotal > 0) //if structure to check if the total costs are greater than zero
        cout << "The total number of large surfboards is " << iTotalLarge << " at a total of $" << largetotal << endl; //displays the count total and cost total to the user

    if (xsmalltotal > 0) //if structure to check if the total costs are greater than zero
        cout << "The total number of small surfboards is " << iTotalXSmall << " at a total of $" << xsmalltotal << endl; //displays the count total and cost total to the user

    if (iTotalLarge == 0 && iTotalMedium == 0 && iTotalSmall == 0 && iTotalXSmall == 0) //if structure to check board counts and if all are at 0 displays no purchase yet to user
        cout << "No purchases made yet.";


}


int main() // main function
{
    char user_choice; //variables for the menu choices and 
    int iSmall = 0; //to call the functions with the correct number of parameters
    int iMedium = 0;
    int iLarge = 0;
    int iXSmall = 0;

    cout << setw(61) << setfill('*') << "" << endl; //this line outputs 61 *'s to the screen
    cout << setw(56) << setfill('*') << " Welcome to my Johnny Utah's PointBreak Surf Shop " << setw(5) << setfill('*') << "" << endl; //welcome message to the screen
    cout << setw(61) << setfill('*') << "" << endl; //this line outputs 61 *'s to the screen
    cout << "\n" << "\n" << endl; //creates two blank line spaces

    ShowUsage(); //calls function to show the menu

        do //do loop for endless menu choices until the user selects q or Q
        {
            cout << "\n" << endl; //new line space
            cout << "Please enter a selection: "; //gets the users menu selection
            cin >> user_choice;
            cout << endl;


            switch (user_choice) //switch to call the proper function based on the users choice
            {
            case 's':
            case 'S':
                ShowUsage(); //calls menu function if the user selects s or S
                break; //breaks out of the switch

            case 'p':
            case 'P':
                MakePurchase(iSmall, iMedium, iLarge, iXSmall); //calls the purchase function using the variables for the boards declared in main if the user selects p or P
                break; //breaks out of the switch

            case 'c':
            case 'C':
                DisplayPurchase(iSmall, iMedium, iLarge, iXSmall); //calls the current purchase function using the variables for the boards declared in main if the user selects c or C
                break; //breaks out of the switch

            case 't':
            case 'T':
                DisplayTotal(iSmall, iMedium, iLarge, iXSmall);  //calls the total function using the variables for the boards declared in main if the user selects t or T
                break; //breaks out of the switch

            case 'q':
            case 'Q':
                cout << "Thank you" << endl; //ends the do loop when the user selects q or Q
                return 0; //ends the loop
                
                
            default: //in case the user selects a wrong choice the switch defaults to this
                cout << "Wrong input." << endl;
            }

        }
        while (user_choice != 'Q' || user_choice != 'q'); //checks to keep in the do loop or drops out if the user choice is q or Q

        return 0;
}

