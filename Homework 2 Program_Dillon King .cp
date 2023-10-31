// Homework: Programming Challenge #12, p. 609
// Dillon King

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char password[20];
    int hasUpper, hasLower, hasDigit;

        cout << "The password must have: \n"
             << "     at least 6 characters,\n"
             << "     at least one uppercase character,\n"
             << "     at least one lowercase character,\n"
             << "     at least one numeric digit\n";
    
    do
    {
        hasUpper = 0;
        hasLower = 0;
        hasDigit = 0;
        
        cout << "Enter a password: ";
        cin.getline(password, 20);
        
        for (int i = 0; i < strlen(password); i++)
        {
            if (isupper(password[i]))
                hasUpper++;
            if (islower(password[i]))
                hasLower++;
            if (isdigit(password[i]))
                hasDigit++;
        }
        
        if (strlen(password) < 6)
            cout << "The password must be 6 or more characters long." << endl;
        if (hasUpper == 0)
            cout << "The password must have:\n"
            << "   at least one uppercase character" << endl;
        if (hasLower == 0)
            cout << "The password must have:\n"
            << "    at least one lowercase character" << endl;
        if (hasDigit == 0)
            cout << "The password must have:\n"
            << "    at lease one numeric digit" << endl;
        if (hasUpper == 0 || hasLower == 0 || hasDigit == 0 || strlen(password) < 6)
            cout << "The password is not valid." << endl;
        
    }
    while (hasUpper == 0 || hasLower == 0 || hasDigit == 0 || strlen(password) < 6);
    cout << "The password is valid" << endl;
    
    return 0;
             
 
  

}

