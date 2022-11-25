#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include <bits/stdc++.h>

using namespace std;

void program();
string formNum(long long int rawNum);
string strRep(string charIn, int amount);
string formAtt(bool isFinal);
void cc();

const string ver = "v2.1.2";
string currentStr;
long long int attempt;

main()
{
    system(("title InfiniteMonkeySimulator " + ver).c_str());
    system("color 7");
    cout << "  ___ __  __ ___ \n"
            " |_ _|  \\/  / __| InfiniteMonkeySimulator\n"
            "  | || |\\/| \\__ \\ " + ver + "\n"
            " |___|_|  |_|___/ by o7q\n";

    program();
    return 0;
}

void program()
{
    while (true)
    {
        cout << "\n+" + strRep("=", 40) + "+\n";

        cout << "\n SPECIFY THE SEARCH PHRASE (no spaces):\n -> ";
        string input; cin >> input; cc();

        // alphabet configuration

        // alphabet input
        cout << "\n SPECIFY THE ALPHABET (no spaces):\n"
                "  lower    (lowercase letters only)\n"
                "  upper    (uppercase letters only)\n"
                "  both     (lowercase and uppercase letters only)\n"
                "  num      (numbers only)\n"
                "  numlower (numbers and lowercase letters only)\n"
                "  numupper (numbers and uppercase letters only)\n"
                "  numboth  (numbers, lowercase, and uppercase letters only)\n"
                "  custom   (import a custom alphabet)\n -> ";
        string alphabet_input; cin >> alphabet_input; cc();
        // declare alphabet information
        string alphabet;
        string alphabet_types[] =
            {
                "lower",
                "upper",
                "both",
                "num",
                "numlower",
                "numupper",
                "numboth"
            };
        string alphabet_dictionary[] =
            {
                "abcdefghijklmnopqrstuvwxyz",
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
                "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
                "0123456789",
                "0123456789abcdefghijklmnopqrstuvwxyz",
                "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ",
                "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
            };
        // process alphabet
        int alphabet_type_length = sizeof(alphabet_types) / sizeof(alphabet_types[0]);
        for (int i = 0; i <= alphabet_type_length; i++) if (alphabet_input == alphabet_types[i]) alphabet = alphabet_dictionary[i];
        // handle custom alphabet
        int alphabet_type_index = 0;
        for (int i = 0; i < alphabet_type_length; i++) if (alphabet_input != alphabet_types[i]) alphabet_type_index++;
        if (alphabet_type_index == alphabet_type_length) alphabet = alphabet_input;
        // split alphabet in chars
        string s(alphabet);
        vector<char> v(s.begin(), s.end());

        cout << "\n SPECIFY THE MAXIMUM ATTEMPTS (! for infinite):\n -> ";
        string attempts_str; cin >> attempts_str; cc();
        long long int attempts = attempts_str == "!" ? 9223372036854775807 : stoi(attempts_str);

        // compute attempts
        const int input_length = input.length();
        const int alphabet_length = alphabet.length();
        const long long int attemptsApprox = pow(alphabet_length, input_length);
        const string attemptsText = attempts == 1 ? "ATTEMPT" : "ATTEMPTS";

        // create vars
        attempt = 0;
        long long int dispCount = 0;
        bool isRunning = true;
        string finalStr;
        // mersenne twister
        srand(time(NULL));
        mt19937 gen(rand());
        uniform_int_distribution<> dist(0, alphabet_length - 1);

        cout << "\n IT WILL TAKE THE MONKEY AROUND " + formNum(attemptsApprox) + " ATTEMPTS TO TYPE \"" + input + "\"! (input 'r' to restart)\n SPECIFY THE ATTEMPT DISPLAY INTERVAL (a lower value displays more attempts but it is slower to calculate):\n -> ";
        string dispInterval_str;
        cin >> dispInterval_str; cc();
        if (dispInterval_str == "r") program();
        int dispInterval = stoi(dispInterval_str);
        cout << endl;

        cout << " THE MONKEY IS READY! PRESS ANY KEY TO START...\n -> ";
        system("pause");
        cout << endl;

        for (int i = 0; i < attempts; i++)
        {
            currentStr = "";
            for (int n = 0; n < input_length; n++) { currentStr += v[dist(gen)]; }
            attempt++;

            dispCount++;
            if (dispCount == dispInterval) { dispCount = 0; printf(formAtt(false).c_str()); }

            if (currentStr == input)
            {
                cout << endl << formAtt(true);
                isRunning = false;
                cout << "\n THE MONKEY TYPED \"" + input + "\" IN " + formNum(attempt) + " " + attemptsText + "! (max: " + formNum(attempts) + ")\n TRY ANOTHER? (y = yes | anything else = no)\n -> ";
                char r; cin >> r; cc();
                if (r == 'y') break; else _Exit(0);
            }
            finalStr = currentStr;
        }

        if (finalStr != input && isRunning)
        {
            cout << "\n THE MONKEY DID NOT TYPE \"" + input + "\" IN " + formNum(attempts) + " " + attemptsText +"!\n TRY ANOTHER? (y = yes | anything else = no)\n -> ";
            char r; cin >> r; cc();
            if (r != 'y') _Exit(0);
        }
    }
}

// format number function
string formNum(long long int rawNum)
{
    string numForm;
    string num = to_string(rawNum);
  
    int count = 0;
  
    for (int i = num.size() - 1; i >= 0; i--)
    {
        count++;
        numForm.push_back(num[i]);
  
        if (count == 3)
        {
            numForm.push_back(',');
            count = 0;
        }
    }
  
    reverse(numForm.begin(), numForm.end());
  
    if (numForm.size() % 4 == 0) numForm.erase(numForm.begin());
  
    return numForm;
}

// string repeater function
string strRep(string charIn, int amount)
{
    string output;
    for (int i = 0; i < amount; i++) output += charIn;
    return output;
}

// format attempt function
string formAtt(bool isFinal)
{
    string n = isFinal == true ? " <-\n" : "\n";
    return " " + currentStr + " | " + formNum(attempt) + n;
}

// cin clear function
void cc()
{
    cin.clear();
    cin.sync();
}